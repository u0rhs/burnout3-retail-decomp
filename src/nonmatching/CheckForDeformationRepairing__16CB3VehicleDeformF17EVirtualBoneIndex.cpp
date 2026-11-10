// NONMATCHING: CheckForDeformationRepairing__16CB3VehicleDeformF17EVirtualBoneIndex -- retail 58 / ours 58 instructions, 18 in changed runs
// psweep: scoped #pragma opt_dead_assignments off [G] improves 22 -> 18
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_dead_assignments off
using GtMathPs2::CGtV3d;
using GtMathPs2::XAxisType;
// [L] N185: stands in for a missing GtMathPs2 inline (XAxisType - XAxisType: lqc2 b first, vsubx.x)
inline XAxisType operator-(XAxisType a, XAxisType b) {
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "qmtc2 %2, $vf2" "\n\t" "vsubx.x $vf1, $vf2, $vf1x" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(b.lVector), "r"(a.lVector));
    return XAxisType(t);
}
static inline float fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }

struct UnkStruct_003DBF80_b { unsigned char pad_0[0x730]; CGtV3d field_730; };
struct UnkStruct_003DBF80_c { unsigned char pad_0[0xA0]; CGtV3d field_A0; };
extern int kaeVirtualToNormalBone[];
struct UnkStruct_D_004E0C6C { float field_0; };
extern UnkStruct_D_004E0C6C D_004E0C6C;
class CB3VehicleDeform;

class CB3VehicleDeform {
public:
    unsigned char pad_0[0x14];
    UnkStruct_003DBF80_b *field_14;
    UnkStruct_003DBF80_c *field_18;
    unsigned char pad_1C[0x134];
    CGtV3d field_150;
};

extern "C" bool CheckForDeformationRepairing__16CB3VehicleDeformF17EVirtualBoneIndex(CB3VehicleDeform *self, int bone)
{
    if (!((unsigned)bone <= 1 || (unsigned)(bone - 4) <= 1)) return false;
    int n = kaeVirtualToNormalBone[bone];
    float d = XAxisType(((UnkStruct_003DBF80_b *)((char *)self->field_14 + n * 0x40))->field_730.X()) - ((UnkStruct_003DBF80_c *)((char *)self->field_18 + n * 0x40))->field_A0.X();
    if (fabsf(d) < D_004E0C6C.field_0) return false;
    float dd = d;
    int bits = *(int *)&dd;
    int sg = (bits & 0x80000000) | 0x3F800000;
    float fx;
    *(int *)&fx = (int)self->field_150.mData;
    int x8 = *(int *)&fx;
    int sg2 = (x8 & 0x80000000) | 0x3F800000;
    if (*(float *)&sg == *(float *)&sg2) return false;
    self->field_150.Zero();
    return true;
}

#pragma pop
