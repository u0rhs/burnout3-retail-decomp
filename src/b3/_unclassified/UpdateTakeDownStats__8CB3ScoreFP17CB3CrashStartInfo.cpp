// Hand-written; the lifter refused it (cmp1: field_19AC bound to an int-sized enum local keeps the beq lower-register-first order (N240)).

// near24 (27->1): FAKEMATCH pinned-vf2 helpers removed -- header GetSquaredLength() (b119p hoists the 1.0) + an N185 compiler-chosen vsub stand-in for the loop's difference (header operator- hard-codes vf2) + header operator- for the victim; me re-read before the 133C/18EA test (delay-slot lw). Left: bne t0,t1 operand order of the field_1674 test (every operand/declaration/inline form either keeps bne t1,t0 or swaps the registers too)

// 27 in changed runs, 166 vs 165: hand-written (lifter refused); blocks, pinned vf2 1.0 hoist and both squared-distance bodies match; left: register allocation in the victim part (victim in a3 vs t0, field_5F0/crash time in f2/f1 swapped, one extra nop), bne operand order of the field_1674 test, and the 25600.0f rematerialisation scheduled earlier

enum UnkEnum_00157410 { UnkEnum_00157410_0 };

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

// [L] DNAT: CB3Score::UpdateTakeDownStats(CB3CrashStartInfo*) (research/proto/new_names.csv, high)
struct UnkStruct_00157410_c;
struct UnkStruct_00157410_c {                    // [G] a race car (one type for all four uses: same field offsets)
    unsigned char pad_0[0x30];
    CGtV3d field_30;
    unsigned char pad_40[0x108C];
    float field_10CC;
    unsigned char pad_10D0[0xB8];
    UnkStruct_00157410_c* field_1188;
    unsigned char pad_118C[0x1B0];
    int field_133C;
    unsigned char pad_1340[0x258];
    float field_1598[6];
    unsigned char field_15B0[6];
    unsigned char field_15B6[6];
    unsigned char pad_15BC[0xC];
    UnkStruct_00157410_c* field_15C8;
    unsigned char pad_15CC[0xA8];
    int field_1674;
    unsigned char pad_1678[0x272];
    unsigned char field_18EA;
    unsigned char pad_18EB[0x29];
    int field_1914;
    unsigned char pad_1918[0x94];
    signed char field_19AC;
    unsigned char pad_19AD[0xE13];
    int field_27C0;
};
struct UnkStruct_00157410_i { unsigned char pad_0[0xC]; UnkStruct_00157410_c* field_C; };
struct UnkStruct_00157410_p { unsigned char pad_0[0x4585]; unsigned char field_4585; unsigned char pad_4586[0xA]; };   // [G] 0x4590-byte records
struct UnkStruct_D_0055EF70 { unsigned char pad_0[0x1CB80]; UnkStruct_00157410_p field_1CB80[1]; };   // [G] count unknown
extern UnkStruct_D_0055EF70 D_0055EF70;
struct UnkStruct_D_00645170 { int field_0; unsigned char pad_4[0xC]; };   // [G] size: absolute addressing needs > 8 bytes (N50)
extern UnkStruct_D_00645170 D_00645170;
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };   // [G] size: absolute addressing needs > 8 bytes (N50)
extern UnkStruct_D_0064D37C D_0064D37C;
struct UnkStruct_D_00522660 { unsigned char pad_0[0x12AD28]; UnkStruct_00157410_c* field_12AD28[1]; };   // [G] count unknown
extern UnkStruct_D_00522660 D_00522660;

class CB3Score {
public:
    static float gmrTakedownCrashTime;
    static float gmrTakedownCollideTimeNoSlam;

    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0xB8];
    UnkStruct_00157410_c* field_C8;
    unsigned char pad_CC[0x43A];
    unsigned char field_506;
    unsigned char field_507;
    unsigned char pad_508[0x4];
    int field_50C;
    unsigned char pad_510[0x18];
    float field_528[6];
    unsigned char pad_540[0x78];
    unsigned char field_5B8;
    unsigned char pad_5B9[0x33];
    UnkStruct_00157410_c* field_5EC;
    float field_5F0;
};

// [L] N185 stand-in: the race-car difference with compiler-chosen VU registers (retail 0x157478: `vsub.xyz $vf1, $vf3, $vf1`
// with the hoisted 1.0 in $vf2 -- the header operator- hard-codes $vf2 for this operand)
static inline GtMathPs2::CGtV3d func_00157410_inl1(const GtMathPs2::CGtV3d& a, const GtMathPs2::CGtV3d& b)
{
    u_long128 t;
    asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData));
    return GtMathPs2::CGtV3d(t);
}
// 0x00157410
extern "C" void UpdateTakeDownStats__8CB3ScoreFP17CB3CrashStartInfo(CB3Score* self, UnkStruct_00157410_i* pInfo)
{
    self->field_50C = 0;
    self->field_506 = 0;
    self->field_507 = 0;
    for (int i = 0; i < D_0064D37C.field_0; i++) {
        UnkStruct_00157410_c* car = D_00522660.field_12AD28[i];
        if (self->field_528[i] <= CB3Score::gmrTakedownCollideTimeNoSlam) {
            if (self->field_5B8 == 0) continue;
            UnkEnum_00157410 idx = (UnkEnum_00157410)self->field_C8->field_19AC;
            if (car->field_1674 != idx) continue;
        }
        UnkStruct_00157410_c* me = self->field_C8;
        if (func_00157410_inl1(car->field_30, me->field_30).GetSquaredLength() < 25600.0f) {
            unsigned char v = self->field_5B8;
            if (car->field_133C != 3 && car->field_1188->field_18EA == 0) {
                int k = me->field_19AC;
                car->field_1598[k] = car->field_10CC;
                car->field_15B0[k] = 0;
                car->field_15B6[k] = v;
            }
        }
    }
    UnkStruct_00157410_c* victim;
    float crash = CB3Score::gmrTakedownCrashTime;
    float t = self->field_5F0;
    if (-1.0f == t) {
        victim = 0;
    } else if (t + crash < self->field_C) {
        victim = 0;
    } else {
        victim = self->field_5EC;
    }
    if (victim != 0) {
        UnkStruct_00157410_c* me = self->field_C8;
        if ((victim->field_30 - me->field_30).GetSquaredLength() < 25600.0f) {
            victim->field_15C8 = me;
            me = self->field_C8;
            if (victim->field_133C != 3 && victim->field_1188->field_18EA == 0) {
                int k = me->field_19AC;
                victim->field_1598[k] = victim->field_10CC;
                victim->field_15B0[k] = 0;
                victim->field_15B6[k] = 0;
            }
        }
    }
    if (pInfo != 0) {
        UnkStruct_00157410_c* c = pInfo->field_C;
        if (c != 0 && c->field_18EA != 0 && c->field_1914 == 0) {
            int idx = c->field_27C0;
            UnkStruct_00157410_p* p = idx < D_00645170.field_0 ? &D_0055EF70.field_1CB80[idx] : 0;
            if (p->field_4585 != 0) {
                UnkStruct_00157410_c* me = self->field_C8;
                if (c->field_133C != 3) {
                    int k = me->field_19AC;
                    c->field_1598[k] = c->field_10CC;
                    c->field_15B0[k] = 1;
                    c->field_15B6[k] = 0;
                }
            }
        }
    }
}
