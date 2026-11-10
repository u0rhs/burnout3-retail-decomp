// NONMATCHING: func_002284B0 -- retail 1032 / ours 892 instructions, 924 in changed runs
// draftH: 5 view matrices (identity, +-90 deg about X/Y via inlined CreateRotationMatrix3x4) + per-view GIF packet of sphere-map ST/XYZ2 for func_002294D0's 10x10 strip; residue = op= byte-loop copies of the 4 rotation results (N263), uv low-word forwarding, $fp base
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: every call, branch, packet word and per-vertex VU/FPU op accounted for; differs only in copy/register shape

// draftH: func_002284B0 (0x2284B0, 0x1020) -- retail-only (no E-map entry; the E maps list PreBuildSpheremapWarpData,
// _PartialHemisphereCreate and CBlit::BuildPacket around it in B3GraphicsManagerPS2.cpp [C], but not this function or its
// helper func_002294D0). Caller func_00228400 (B3GraphicsManagerPS2.cpp) runs it instead of
// CB3GraphicsManager::PreBuildSpheremapWarpData when D_0051BA88 == &D_0051A6A8 [C asm].
// What it does [L, written from the asm]: five view matrices (identity, +-90 degrees about X, +-90 degrees about Y); per view
// a 10x10 grid (func_002294D0 builds it as a triangle strip at 0x70000000, 32-byte position/uv vertices) is transformed, each
// position normalised and projected to sphere-map coordinates (x, -y) / |n + (0,0,1)| * 0.565; one GIF packet per view
// (DMA ret tag, VIF DIRECT, GIF tag PRIM 0x54 + RGBAQ, then NLOOP=n ST/XYZ2 pairs) is appended to the buffer at field_1198.
// Residue [C asm, draftH]: (1) retail copies each CreateRotationMatrix3x4 result (lRotateMatrix -> result temporary) with
// the op= shape -- row 0 from its register, rows 1-3 by 8x2 lb/sb loops (12 loops) -- then lq/sq into mats[i]; ours
// forwards/lq-sqs every row (the N263 family; `r = Create..(); mats[i] = r;` gives loops only when ONE block is written so,
// inline_depth 2..7 negative). (2) uv's low word: retail takes it from the lq register (dsll32/dsrl32), ours reloads it
// with lwu (7 source forms tried). (3) 0x70000000 kept in $fp by retail, ours rematerialises it. Calls, branches, the
// packet words, VU/FPU op order in the vertex loop otherwise as retail.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

// [G] the CB3GraphicsManager fields used here (byte offsets from retail; layout of func_00228400's UnkStruct_00228400).
struct UnkStruct_002284B0 {
    unsigned char pad_0[0x1194];
    int field_1194;        // set to 6 at the end
    int field_1198;        // packet buffer (AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki block 26) [C func_00228400]
    int field_119C;        // used size in quadwords [C func_00228400: SyncDCache(buf, buf + size - 1)]
    int field_11A0[5];     // packet start per view
    int field_11B4[5];     // 7,7,7,6,6 per view [G meaning]
    int field_11C8[5];     // 7 per view [G meaning]
};

// [G] one grid vertex at the scratchpad: position then uv (func_002294D0's layout).
struct UnkStruct_002284B0_vtx {
    CGtV3d field_0;
    CGtV3d field_10;
};

extern "C" int func_002294D0(int n);   // [C asm] returns the strip's vertex count (v0); builds the strip at 0x70000000
extern "C" int GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(void *, int);
extern unsigned char theMemMgr[];
extern const CGtV3d D_004B9DC0;        // (1,0,0), set by the static initialiser at 0x4D5B28 [C]; [L] kRightAxis (map conflict note)
extern const CGtV3d D_004B9DD0;        // (0,1,0), same initialiser [C]

// [G] local stand-ins (header gaps, build/vt/header_queue.txt):
// TransformPoint with all four rows as compiler-chosen VU operands (retail 0x229358: rows hoisted in $vf6/$vf5/$vf4/$vf3, the
// point lqc2'd straight into a VU register, result `vmaddw.xyz $vf1,<pos>,$vf0w` + qmfc2) -- the header form moves rows 1-3
// through $vf1 by qmtc2.
static inline CGtV3d func_002284B0_inl1(const CGtMatrix3x4 &m, CGtV3d v)
{
    u_long128 t;
    asm(".set noreorder" "\n\t" "vmulax.xyz $ACC, %1, %5x" "\n\t" "vmadday.xyz $ACC, %2, %5y" "\n\t" "vmaddaz.xyz $ACC, %3, %5z" "\n\t"
        "vmaddw.xyz $vf1, %4, $vf0w" "\n\t" "qmfc2.ni %0, $vf1" "\n\t" ".set reorder"
        : "=r"(t) : "j"(m.mRight.mData), "j"(m.mUp.mData), "j"(m.mAt.mData), "j"(m.mPos.mData), "j"(v.mData));
    return CGtV3d(t);
}
// In-place Normalise (N238's H1Q0N2V1R- body: retail 0x229370 `vmulq.xyz $vf8,$vf8,$Q`).
static inline void func_002284B0_inl2(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm(".set noreorder" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" "\n\t" ".set reorder" : "+j"(v.mData));
}

// 0x002284B0
extern "C" void func_002284B0(UnkStruct_002284B0 *self)
{
    CGtMatrix3x4 mats[5];
    mats[0].SetIdentity();
    self->field_11B4[0] = 7;
    self->field_11C8[0] = 7;
    mats[1] = CreateRotationMatrix3x4(D_004B9DC0, 1.5707964f);
    self->field_11B4[1] = 7;
    self->field_11C8[1] = 7;
    mats[2] = CreateRotationMatrix3x4(D_004B9DC0, -1.5707964f);
    self->field_11B4[2] = 7;
    self->field_11C8[2] = 7;
    mats[3] = CreateRotationMatrix3x4(D_004B9DD0, 1.5707964f);
    self->field_11B4[3] = 6;
    self->field_11C8[3] = 7;
    mats[4] = CreateRotationMatrix3x4(D_004B9DD0, -1.5707964f);
    self->field_11B4[4] = 6;
    self->field_11C8[4] = 7;
    UnkStruct_002284B0_vtx * const verts = (UnkStruct_002284B0_vtx *)0x70000000;
    for (int i = 0; i < 5; i++) {
        self->field_11A0[i] = 0;
        int n = func_002294D0(10);
        int qwc = (n * sizeof(u_long128) + 15) / sizeof(u_long128);
        self->field_11A0[i] = self->field_1198 + self->field_119C * 16;
        self->field_119C += qwc + 4;
        GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(theMemMgr, 26);
        unsigned long *p = (unsigned long *)self->field_11A0[i];
        p[0] = (long)(qwc + 3) | 0x60000000;
        p[1] = (unsigned long)((qwc + 3) | 0x50000000U) << 32;
        p[2] = 0x2400000000000001UL;
        p[3] = 0x10;
        p[4] = 0x54;
        p[5] = 0x3F80000080808080UL;
        p[6] = (long)n | 0x2400000000008000UL;
        p[7] = 0x52;
        p += 8;
        const CGtMatrix3x4 &m = mats[i];
        for (int j = 0; j < n; j++) {
            UnkStruct_002284B0_vtx *vx = &verts[j];
            CGtV3d d = func_002284B0_inl1(m, vx->field_0);
            func_002284B0_inl2(d);
            CGtV3d uv = vx->field_10;
            float v = uv.Y();
            p[0] = (unsigned long)*(unsigned int *)&uv | ((unsigned long)*(unsigned int *)&v << 32);
            float x2 = d.X() * d.X();
            float y2 = d.Y() * d.Y();
            float z2 = (d.Z() + 1.0f) * (d.Z() + 1.0f);
            float len = sqrtf(x2 + y2 + z2);
            CGtV2d s;
            s.marValues[1] = (float)-d.Y() / len * 0.565f;
            s.marValues[0] = d.X() / len * 0.565f;
            int x = (int)(16.0f * (256.0f + 256.0f * s.marValues[0]));
            int y = (int)(16.0f * (256.0f + 256.0f * s.marValues[1]));
            p[1] = (long)x | ((long)y << 16);
            p += 2;
        }
    }
    self->field_1194 = 6;
}
