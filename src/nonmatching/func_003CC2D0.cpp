// NONMATCHING: func_003CC2D0 -- retail 125 / ours 125 instructions, 2 in changed runs
// near22: dropped the asm-volatile sqrt + pinned-1.0 FAKEMATCH stand-ins; header GetSquaredLength + a local GetLength stand-in whose 1.0 and result share one GPR (retail a3; header's two outputs force two) -> 2 off. Left: epilogue restore order only (retail ld ra; lwc1 f20; lq s3, ours ld ra; lq s3; lwc1 f20). Declaration-order permutations didn't move it. If the header GetLength is reshaped to one GPR, drop the stand-in
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3VehiclePhysics;
class CB3RacePosition {
public:
    void DrawSingleVehicleValue(CB3VehiclePhysics* pVehicle, int a, int b, float f, bool c);
    unsigned char pad_0[0x10];                   // [G] size: absolute addressing needs > 8 bytes (N50)
};
namespace Gt2dRenderer {
    enum EGt2dRendererFilter { };
    void SetTextureFilterMode(EGt2dRendererFilter mode);
}

struct UnkStruct_003CC2D0_m { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_003CC2D0_v { unsigned char pad_0[0x204]; UnkStruct_003CC2D0_m* field_204; };
struct UnkStruct_003CC2D0 {
    unsigned char pad_0[0x18];
    UnkStruct_003CC2D0_v* field_18[0x42];        // [G] element count
    int field_120[0xD2];                          // [G] element count
    UnkStruct_003CC2D0_v* field_468[8];
    float field_488[8];
    unsigned char pad_4A8[0x7];
    unsigned char field_4AF;
};
struct UnkStruct_003CC2D0_e {                    // [G] one 0x14-byte sort record
    UnkStruct_003CC2D0_v* field_0;
    float field_4;
    int field_8;
    int field_C;
    float field_10;
};
struct UnkStruct_D_00666270_c { unsigned char pad_0[0x20]; CGtV3d field_20; };
struct UnkStruct_D_00666270 { unsigned char pad_0[0x68]; UnkStruct_D_00666270_c* field_68; };
struct UnkStruct_D_00666270_g { UnkStruct_D_00666270* field_0; unsigned char pad_4[0xC]; };   // [G] size: absolute addressing needs > 8 bytes (N50)
extern UnkStruct_D_00666270_g D_00666270;
struct UnkStruct_D_004F50A0 { float field_0; unsigned char pad_4[0xC]; };   // [G] size: absolute addressing needs > 8 bytes (N50)
extern UnkStruct_D_004F50A0 D_004F50A0;
extern unsigned char D_004EE040[];
extern CB3RacePosition D_00648730;
extern "C" int func_00131CA0(void *);
extern "C" void Begin__12Gt2dRendererFv();          // [L] DNAT: Gt2dRenderer::Begin() (research/proto/new_names.csv, high)
extern "C" void func_00217E70(int);       // [L] DNAT: Gt2dRenderer::SetBlendMode(EGt2dRendererBlend) (new_names.csv)
extern "C" int func_003CC4D0(const void*, const void*);
extern "C" void qsort(void *, int, int, void *);

// [G] a - b with b as a "j" operand (retail keeps b in a VU register across the loop): a in $vf1, the result over $vf1
static inline CGtV3d func_003CC2D0_sub(const CGtV3d& a, const CGtV3d& b)
{
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "vsub.xyz $vf1, $vf1, %2" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(a.mData), "j"(b.mData));
    return CGtV3d(t);
}

// [L] stand-in (near22) for CGtV3d::GetLength(): the header body with the 1.0 and the result sharing one GPR, as retail's
// inlined copy here (0x3CC3B0..C0: qmfc2.ni a3 / qmtc2.ni a3 / qmfc2.ni a3); the header's two outputs force two registers.
static inline XAxisType func_003CC2D0_inl1(const CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 r;
    asm(".set noreorder");
    asm("qmtc2.i %1, $vf1" "\n\t" "vsqrt $Q, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %0, $vf1" "\n\t"
        "vwaitq" "\n\t" "qmtc2.i %0, $vf1" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %0, $vf1"
        : "=&r"(r) : "r"(l.lVector));
    asm(".set reorder");
    return XAxisType(r);
}
// 0x003CC2D0
extern "C" bool func_003CC2D0(UnkStruct_003CC2D0* p)
{
    XAxisType dist;
    UnkStruct_003CC2D0_e entries[65];
    float base = D_004F50A0.field_0;
    int n = 0;
    func_00131CA0(D_004EE040);
    bool drawn = false;
    CGtV3d cam = D_00666270.field_0->field_68->field_20;
    for (int i = 0; i < 8; i++) {
        UnkStruct_003CC2D0_v* v = p->field_468[i];
        if (v != 0) {
            CGtV3d d = func_003CC2D0_sub(v->field_204->field_30, cam);
            int j;
            for (j = 0; j < p->field_4AF; j++) {
                if (p->field_18[j] == v) goto found;
            }
            j = -1;
        found:
            float f = base - p->field_488[i];
            dist = func_003CC2D0_inl1(d);
            UnkStruct_003CC2D0_e* e = &entries[n++];
            e->field_4 = dist;
            e->field_0 = p->field_468[i];
            e->field_8 = p->field_120[j];
            e->field_10 = f;
            e->field_C = i;
        }
    }
    qsort(entries, n, 0x14, (void*)&func_003CC4D0);
    for (n--; n >= 0; n--) {
        UnkStruct_003CC2D0_e* e = &entries[n];
        int& val = e->field_8;
        if (e->field_8 >= 100) {
            if (!drawn) {
                drawn = true;
                Begin__12Gt2dRendererFv();
                func_00217E70(0);
                Gt2dRenderer::SetTextureFilterMode((Gt2dRenderer::EGt2dRendererFilter)0);
            }
            D_00648730.DrawSingleVehicleValue((CB3VehiclePhysics*)e->field_0, e->field_C, val, e->field_10, false);
        }
    }
    return drawn;
}

