// NONMATCHING: GetWindscreenPos__16CB3VehicleDeformFbb -- retail 77 / ours 75 instructions, 28 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: a236: logic + VU body exact (local operator*/+ asm: qmtc2.ni vf2 + vmulx.xyz, vadd; YAxisType operator+(Y,float) asm); frame 0x120 via 4 dead YAxisType slots; left: h slot at sp+16 vs retail sp+80, GPR alloc (j in t3 vs t1, a3 scalar), vf3 vs vf2 on SetY tail
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_3E6FD0_e { CGtV3d field_0; CGtV3d field_10; unsigned char pad_20[0x20]; };
struct UnkStruct_3E6FD0_p { unsigned char pad_0[0x90]; UnkStruct_3E6FD0_e field_90[8]; unsigned char pad_290[0x7E0]; float field_A70[8]; };
struct UnkStruct_3E6FD0_q { unsigned char pad_0[0x720]; UnkStruct_3E6FD0_e field_720[8]; };
static inline CGtV3d func_003E6FD0_inl1(const CGtV3d& a, float s)
{ u_long128 t; asm("qmtc2.ni %1, $vf2" "\n\t" "vmulx.xyz %0, %2, $vf2x" : "=j"(t) : "r"(s), "j"(a.mData)); return CGtV3d(t); }
static inline CGtV3d func_003E6FD0_inl2(const CGtV3d& a, const CGtV3d& b)
{ u_long128 t; asm("vadd.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }
static inline YAxisType operator+(YAxisType a, float f)
{ u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return YAxisType(r); }
class CB3VehicleDeform {
public:
    CGtV3d GetWindscreenPos(bool, bool);
    unsigned char pad_0[0x14];
    UnkStruct_3E6FD0_q *field_14;
    UnkStruct_3E6FD0_p *field_18;
};
// 0x003E6FD0
CGtV3d CB3VehicleDeform::GetWindscreenPos(bool p0, bool p1)
{
    CGtV3d pos;
        YAxisType d0(field_18->field_90[0].field_0.mData); float f0 = d0;
    YAxisType d1(field_18->field_90[0].field_0.mData); float f1 = d1;
    YAxisType d2(field_18->field_90[0].field_0.mData); float f2 = d2;
    YAxisType d3(field_18->field_90[0].field_0.mData); float f3 = d3;
    int i, j;
    if (p0) {
        j = 7;
        i = 3;
    } else {
        j = 6;
        i = 0;
    }
    if (p1) {
        pos = func_003E6FD0_inl2(field_18->field_90[i].field_10, func_003E6FD0_inl1(field_18->field_90[i].field_0, field_18->field_A70[i]));
    } else {
        pos = func_003E6FD0_inl2(field_14->field_720[i].field_10, func_003E6FD0_inl1(field_14->field_720[i].field_0, field_18->field_A70[i]));
    }
    float h = field_18->field_90[j].field_10.Y() - field_18->field_90[i].field_10.Y();
    if (p0) {
        pos.SetY(pos.Y() + 0.4f * h);
    } else {
        pos.SetY(pos.Y() + 0.5f * h);
    }
    return pos;
}
