// NONMATCHING: CanSlam__24CB3AIAggressionBehaviourFv -- retail 122 / ours 124 instructions, 128 in changed runs
// fix1 (2026-11-01): final return was inverted (retail returns field_38 <= 10: bc1f with v0 = 1 in the delay slot, then xori); found by a live shadow race, 113/4136 calls = every call reaching that return | Before: a191: first third matches (A/B quads via D_0055EFEC, W-lane k*Aw-k*Bw mula/msub, pabsw/pextlw on the v1 bool); remaining: bool temps get extra andi 0xFF/xori vs retail's slt/sltu forms, retail keeps separate 'return 0' blocks, dot product 1.0 (vaddw.x vf1; qmfc2.ni) + mtc1 asm done by hand (single hand asm), frame 0x90 vs 0x80 (one extra 16B slot), ~126 instrs differ; needs bool/flow reshaping
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [C] fix1 (2026-11-01): live shadow race (the port project harness): 4,136 calls, 0 mismatches (before the fix 113, every call reaching the last return); 24/24 port6 live captures pass the Burn3 checker at tolerance 0 -- on those inputs


#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
static inline int a191_pabsw(int x) { int r; asm("pabsw %0,%1" : "=r"(r) : "r"(x)); return r; }
static inline long a191_pextlw0(int x) { unsigned long r; asm("pextlw %0,$0,%1" : "=r"(r) : "r"(x)); return r; }
extern float D_004E0D6C;
extern float D_01E755B8;
extern float D_01E755E8;
extern float D_01E755E4;
extern float D_01E755F8;
struct UnkStruct_0032FD90_body { unsigned char pad_0[0xB0]; CGtV4d field_B0; };
struct UnkStruct_0032FD90_ent { UnkStruct_0032FD90_body * field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_D_0055EFEC_cs { UnkStruct_0032FD90_ent field_0[1]; };
extern UnkStruct_D_0055EFEC_cs D_0055EFEC;
struct UnkStruct_0032FD90_car {
    unsigned char pad_0[0x20];
    CGtV3d field_20;
    unsigned char pad_30[0x18A0];
    CGtV3d field_18D0;
    unsigned char pad_18E0[0xCC];
    signed char field_19AC;
    unsigned char pad_19AD[0xA8B];
    float field_2438;
};
class CB3AIAggressionBehaviour {
public:
    int CanSlam();
    unsigned char pad_0[0x38];
    float field_38;
    float field_3C;
    unsigned char pad_40[4];
    UnkStruct_0032FD90_car * field_44;
    UnkStruct_0032FD90_car * field_48;
};
// 0x0032FD90
int CB3AIAggressionBehaviour::CanSlam()
{
    if (field_48 == 0) return 0;
    CGtV4d a;
    a = D_0055EFEC.field_0[field_48->field_19AC].field_0->field_B0;
    float k = D_004E0D6C;
    if (k * (float)a.W() < D_01E755B8) return 0;
    CGtV4d c;
    c = a;
    CGtV4d b;
    b = D_0055EFEC.field_0[field_44->field_19AC].field_0->field_B0;
    bool v1 = !(k * (float)c.W() - k * (float)b.W() <= D_01E755E8);
    if (a191_pextlw0(a191_pabsw(v1)) != 0) return 0;
    float f = field_3C;
    bool neg = f < 0.0f;
    bool a1 = !neg;
    if (a1) a1 = f < D_01E755E4;
    if (!a1) {
        a1 = neg;
        if (a1) a1 = -f < 0.5f * field_44->field_2438;
    }
    if (!a1) return 0;
    u_long128 t, o;
    float d;
    UnkStruct_0032FD90_car *c44 = field_44;
    asm("vaddw.x $vf1, $vf0, $vf0w\n\tqmfc2.ni %1, $vf1\n\tlqc2 $vf2, 0x20(%2)\n\tlqc2 $vf1, 0x18D0(%2)\n\tvmul.xyz $vf2, $vf2, $vf1\n\tvadday.x $ACC, $vf2, $vf2y\n\tqmtc2.ni %1, $vf1\n\tvmaddz.x $vf1, $vf1, $vf2z\n\tqmfc2.ni %0, $vf1" : "=r"(t), "=&r"(o) : "r"(c44));
    asm("mtc1 %1, %0" : "=f"(d) : "r"(t));
    if (d < D_01E755F8) return 0;
    // fix1: retail returns (field_38 <= 10) [C] 0x32FF3C `c.le.s; bc1f` with v0 = 1 in the delay slot, then `xori v0, 1`
    return field_38 <= 10.0f;
}
