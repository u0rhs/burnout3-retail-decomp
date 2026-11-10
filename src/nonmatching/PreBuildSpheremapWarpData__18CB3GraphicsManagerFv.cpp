// NONMATCHING: PreBuildSpheremapWarpData__18CB3GraphicsManagerFv -- retail 1561 / ours 1572 instructions, 2181 in changed runs
// draftR: calls, CFG, packet words and per-vertex FPU/VU ops as retail; residue = scheduling/VU numbering in the face-matrix inline and CreateRotationMatrix3x4 bodies, matrix copy levels (sq 21 vs 29 per face), rotate-step operand order (retail x*cos first), frame 0x22B0 vs 0x3A30
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: every call, branch, store and VU/FPU op of the 3 face matrices and the warp loop accounted for; differs in copy/register/schedule shape

// CB3GraphicsManager::PreBuildSpheremapWarpData() -- draftR (2026-10-31), hand-written from retail asm + Ghidra draft.
// [C] name: retail tables (B3GraphicsManagerPS2.cpp, E-map file order next to _PartialHemisphereCreate). No Revenge
// counterpart. Twin of draftH's func_002284B0 (the 5-face path's warp data; same packet head and vertex loop shape).
// What it does [L, from the asm]: the 3-face env-map frame chain of BuildCustomCameraData (rotation about D_004B9DC0 by
// krEnvmapRotateAngle, 45 degrees about its at axis, then 120 degrees about kAtAxis per face) turned into one texture
// matrix per face (func_002298B0_inl1); per face a hemisphere strip (func_0022B120 = [L] _PartialHemisphereCreate) is
// rotated about Y by the face's angle, flattened, sphere-map coordinates (u, w) are turned back into a direction,
// projected through the face matrix into uv, and written as ST/XYZ2 pairs into a GIF packet appended at field_1198.
// Fields are placeholders, every type [G] (instruction widths) unless noted.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

extern "C" float sinf(float);
extern "C" float cosf(float);
extern "C" float sqrtf(float);
extern "C" int func_0022B120(int n, float radius, float angle);   // [L] DNAT _PartialHemisphereCreate (its archive)
extern "C" int GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(void *, int);
extern unsigned char theMemMgr[];
extern const CGtV3d D_004B9DC0;        // (1,0,0) [C] (func_002284B0's archive)
extern CGtV3d kAtAxis;
// [G] 16-byte wrappers: retail reads these .data floats with lui/%lo (a plain extern float goes gp-relative).
struct UnkStruct_002298B0_f { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_002298B0_f krEnvmapRotateAngle;
extern UnkStruct_002298B0_f krEnvmapShift;
extern UnkStruct_002298B0_f krEnvmapViewWindow;

struct UnkStruct_002298B0_vtx {        // [G] func_0022B120's 32-byte strip vertex: position, uv
    CGtV3d field_0;
    CGtV3d field_10;
};

class CB3GraphicsManager {
public:
    void PreBuildSpheremapWarpData();
    unsigned char pad_0[0x1194];
    int field_1194;        // set to 4 at the end (func_002284B0: 6)
    int field_1198;        // packet buffer
    int field_119C;        // used size in quadwords
    int field_11A0[5];     // packet start per face
    int field_11B4[5];
    int field_11C8[5];
};

// [G] placeholder inline: the face texture matrix -- columns built from the frame rows scaled by the view window
// (s = 1/W, o = -/+(W - 1), h = (-0.5, 0.5)), transposed, position from the shifted frame position.
static inline CGtMatrix3x4 func_002298B0_inl1(CGtMatrix3x4 m, float shift, const CGtV3d &h, const float *sc, const float *of)
{
    CGtMatrix3x4 r;
    m.mPos += m.mAt * shift;
    CGtV3d s;
    s.SetX(sc[0]);
    s.SetY(sc[1]);
    CGtV3d o;
    o.SetX(of[0]);
    o.SetY(of[1]);
    CGtV3d t;
    t.SetX(s.X() * h.X());
    t.SetY(h.Y() - t.X() * o.X());
    CGtV3d c0 = m.mRight * t.X() + m.mAt * t.Y();
    r.mRight.SetX(c0.X());
    r.mAt.SetX(c0.Z());
    r.mUp.SetX(c0.Y());
    r.mPos.SetX(h.Y() - (t.Y() + DotProduct(m.mPos, c0)));
    t.SetX(s.Y() * h.X());
    t.SetY(h.Y() + t.X() * o.Y());
    CGtV3d c1 = m.mUp * t.X() + m.mAt * t.Y();
    r.mRight.SetY(c1.X());
    r.mUp.SetY(c1.Y());
    r.mAt.SetY(c1.Z());
    r.mPos.SetY(h.Y() - (t.Y() + DotProduct(m.mPos, c1)));
    r.mAt.SetZ(m.mAt.Z());
    r.mRight.SetZ(m.mAt.X());
    r.mUp.SetZ(m.mAt.Y());
    r.mPos.SetZ(-DotProduct(m.mPos, m.mAt));
    return r;
}

// [G] stand-in from func_002284B0's archive: TransformPoint with the four rows as compiler-chosen VU operands.
static inline CGtV3d func_002298B0_inl2(const CGtMatrix3x4 &m, CGtV3d v)
{
    u_long128 t;
    asm(".set noreorder" "\n\t" "vmulax.xyz $ACC, %1, %5x" "\n\t" "vmadday.xyz $ACC, %2, %5y" "\n\t" "vmaddaz.xyz $ACC, %3, %5z" "\n\t"
        "vmaddw.xyz $vf13, %4, $vf0w" "\n\t" "qmfc2.ni %0, $vf13" "\n\t" ".set reorder"
        : "=r"(t) : "j"(m.mRight.mData), "j"(m.mUp.mData), "j"(m.mAt.mData), "j"(m.mPos.mData), "j"(v.mData));
    return CGtV3d(t);
}

// 0x002298B0
void CB3GraphicsManager::PreBuildSpheremapWarpData()
{
    CGtMatrix3x4 lFace[3];
    float lAngles[3] = { 1.0471976f, 3.1415927f, 5.2359878f };
    float lScale[2];
    float lOffset[2];
    lScale[0] = lScale[1] = 1.0f / krEnvmapViewWindow.field_0;
    lOffset[1] = krEnvmapViewWindow.field_0 - 1.0f;
    lOffset[0] = -lOffset[1];
    CGtMatrix3x4 lRotationMatrix;
    CGtMatrix3x4 lTempMatrix;
    CGtMatrix3x4 lTemp;
    lRotationMatrix = CreateRotationMatrix3x4(D_004B9DC0, 0.017453292f * krEnvmapRotateAngle.field_0);
    lTempMatrix = CreateRotationMatrix3x4(lRotationMatrix.mAt, 0.7853982f);
    lTemp = lRotationMatrix * lTempMatrix;
    CGtV3d lHalf(-0.5f, 0.5f, 0.0f);
    float lrShift = krEnvmapShift.field_0;
    lFace[0] = func_002298B0_inl1(lTemp, lrShift, lHalf, lScale, lOffset);
    lRotationMatrix = CreateRotationMatrix3x4(kAtAxis, 2.0943952f);
    lTemp = lTemp * lRotationMatrix;
    lFace[1] = func_002298B0_inl1(lTemp, lrShift, lHalf, lScale, lOffset);
    lRotationMatrix = CreateRotationMatrix3x4(kAtAxis, 2.0943952f);
    lTemp = lTemp * lRotationMatrix;
    lFace[2] = func_002298B0_inl1(lTemp, lrShift, lHalf, lScale, lOffset);

    UnkStruct_002298B0_vtx * const verts = (UnkStruct_002298B0_vtx *)0x70000000;
    for (int i = 0; i < 3; i++) {
        field_11B4[i] = 7;
        field_11C8[i] = 7;
        int n = func_0022B120(200, 1.0f, 120.0f);
        int qwc = (n * sizeof(u_long128) + 15) / sizeof(u_long128);
        field_11A0[i] = field_1198 + field_119C * 16;
        field_119C += qwc + 4;
        GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(theMemMgr, 26);
        float a = lAngles[i];
        unsigned long *p = (unsigned long *)field_11A0[i];
        p[0] = (long)(qwc + 3) | 0x60000000;
        p[1] = (unsigned long)((qwc + 3) | 0x50000000U) << 32;
        p[2] = 0x2400000000000001UL;
        p[3] = 0x10;
        p[4] = 0x54;
        p[5] = 0x3F80000080808080UL;
        p[6] = (long)n | 0x2400000000008000UL;
        p[7] = 0x52;
        p += 8;
        float sn = sinf(a);
        float cs = cosf(a);
        const CGtMatrix3x4 &m = lFace[i];
        float lrW2 = 2.0f * krEnvmapViewWindow.field_0;
        float lrWn = -lrW2;
        CGtV3d r;
        CGtV3d d;
        for (int j = 0; j < n; j++) {
            UnkStruct_002298B0_vtx *vx = &verts[j];
            CGtV3d v = vx->field_0;
            r.SetX(v.X() * cs - v.Z() * sn);
            r.SetY(0.0f);
            r.SetZ(v.Z() * cs + v.X() * sn);
            vx->field_0.SetX(r.X() * 0.5f);
            vx->field_0.SetY(0.0f);
            vx->field_0.SetZ(r.Z() * 0.5f);
            float u = vx->field_0.X() + 0.5f;
            float w = vx->field_0.Z() + 0.5f;
            float u2 = u * u;
            float w2 = w * w;
            float q = 4.0f * u + -4.0f * u2 - 1.0f + -4.0f * w2 + 4.0f * w;
            if (q < 0.0f) {
                q = 0.0f;
            }
            float k = 2.0f * sqrtf(q);
            d.SetX(k * (2.0f * u - 1.0f));
            d.SetY(k * (2.0f * w - 1.0f));
            d.SetZ(-8.0f * u2 + 8.0f * u - 8.0f * w2 + 8.0f * w - 3.0f);
            d.SetX(d.X() * lrW2);
            d.SetY(d.Y() * lrW2);
            d.SetZ(d.Z() * lrWn);
            CGtV3d pt = func_002298B0_inl2(m, d);
            vx->field_10.SetX(pt.X() / pt.Z());
            vx->field_10.SetY(pt.Y() / pt.Z());
            r = vx->field_0;
            vx->field_0.SetX(r.X() * 1.15f);
            vx->field_0.SetY(0.0f);
            vx->field_0.SetZ(r.Z() * 1.15f);
            CGtV3d uv = vx->field_10;
            int x = (int)((vx->field_0.X() * 256.0f + 256.0f) * 16.0f);
            int y = (int)((vx->field_0.Z() * 256.0f + 256.0f) * 16.0f);
            float vv = uv.Y();
            p[0] = (unsigned long)(unsigned int)uv.GetRawData() | ((unsigned long)*(unsigned int *)&vv << 32);
            p[1] = (long)x | ((long)y << 16);
            p += 2;
        }
    }
    field_1194 = 4;
}
