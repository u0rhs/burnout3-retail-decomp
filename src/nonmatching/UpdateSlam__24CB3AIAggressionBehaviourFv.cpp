// NONMATCHING: UpdateSlam__24CB3AIAggressionBehaviourFv -- retail 149 / ours 149 instructions, 29 in changed runs
// v257: logic and block layout exact (dead t<D compare kept via an unused bool; sign-ne / 1914 / FA blocks in retail order); 149/149, 29 changed: retail stores the dot result (sw v1) and reloads it for the GtMath::Sign pun (lw), b119p forwards it (dsll32/dsra32) in every Sign form tried (by value, union, const&, asm sw, pragmas); also body reg a3 vs a2, add.s operand order, frame 0x80 vs 0xC0 (W copy at 0x30 with one slot below)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
#include "b3/classes/UnkStruct_D_00522680.h"
using namespace GtMathPs2;
class CB3Score {
public:
    int WasSlammedWithinTime(float);
};
struct UnkStruct_0032FB30_seg { unsigned char pad_0[2]; unsigned char field_2; unsigned char pad_3[7]; };
struct UnkStruct_0032FB30_l2 { unsigned char pad_0[8]; UnkStruct_0032FB30_seg * field_8; };
struct UnkStruct_0032FB30_l1 { unsigned char pad_0[4]; UnkStruct_0032FB30_l2 * field_4; };
struct UnkStruct_0032FB30_car {
    CGtV3d field_0;
    unsigned char pad_10[0x10];
    CGtV3d field_20;
    CGtV3d field_30;
    unsigned char pad_40[0x1080];
    CB3Score field_10C0;
    unsigned char pad_10C1[0x7F3];
    UnkStruct_0032FB30_l1 * field_18B4;
    unsigned short field_18B8;
    unsigned char pad_18BA[0x5A];
    int field_1914;
    unsigned char pad_1918[0x94];
    signed char field_19AC;
    unsigned char pad_19AD[0x255];
    unsigned char field_1C02;
};
struct UnkStruct_0032FB30_body { unsigned char pad_0[0xB0]; CGtV4d field_B0; };
struct UnkStruct_0032FB30_ent { UnkStruct_0032FB30_body * field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_D_0055EFEC { UnkStruct_0032FB30_ent field_0[1]; };
extern UnkStruct_D_0055EFEC D_0055EFEC;
extern UnkStruct_D_00522680 D_00522680;
struct UnkStruct_D_01E755F4 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E755F4 D_01E755F4;
extern UnkStruct_D_01E755F4 D_01E755FC;
extern "C" int func_001419B0(void *);
class CB3AIAggressionBehaviour {
public:
    void UpdateSlam();
    void StopAttacking(bool, bool);
    int field_0;
    unsigned char pad_4[0xC];
    CGtV3d field_10;
    unsigned char field_20;
    unsigned char pad_21[3];
    unsigned char field_24;
    unsigned char pad_25[7];
    float field_2C;
    float field_30;
    float field_34;
    unsigned char pad_38[8];
    unsigned char field_40;
    unsigned char pad_41[3];
    UnkStruct_0032FB30_car * field_44;
    UnkStruct_0032FB30_car * field_48;
};
// [L] N185 stand-ins: DotProduct with the 1.0 parked in a GPR (compiler-chosen VU registers), a compiler-chosen vsub
static inline u_long128 func_0032FB30_inl1() { u_long128 o, one; asm("vaddw.x %0, $vf0, $vf0w" : "=j"(o)); asm("qmfc2.i %0, %1" : "=r"(one) : "j"(o)); return one; }
static inline XAxisType func_0032FB30_inl2(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 one = func_0032FB30_inl1();
    u_long128 m, d;
    asm("vmul.xyz %0, %1, %2" "\n\t" "vadday.x $ACC, %0, %0y" : "=j"(m) : "j"(a.mData), "j"(b.mData));
    u_long128 w;
    asm("qmtc2.i %2, %1" "\n\t" "vmaddz.x %1, %1, %3z" "\n\t" "qmfc2.i %0, %1" : "=r"(d), "=&j"(w) : "r"(one), "j"(m));
    return XAxisType(d);
}
static inline CGtV3d func_0032FB30_inl3(const CGtV3d &a, const CGtV3d &b) { u_long128 t; asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }
static inline CGtV3d func_0032FB30_inl4(const CGtV3d &a, const CGtV3d &b) { u_long128 t; asm("vadd.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }
// [L] GtMath::Sign(float) (B3O0PCH map, 48 bytes): +-1.0 with x's sign bit
static inline float func_0032FB30_inl0(float x) { int i = *(int *)&x; i &= 0x80000000; i |= 0x3F800000; *(int *)&x = i; return x; }
static inline bool func_0032FB30_inl5(CB3AIAggressionBehaviour * b)
{
    if (func_001419B0(b->field_44) == 0) return false;
    if (b->field_44->field_10C0.WasSlammedWithinTime(2.0f)) return false;
    UnkStruct_0032FB30_car * car = b->field_44;
    if (car->field_18B4->field_4->field_8[car->field_18B8].field_2 == 0xFF) return true;
    if (car->field_1C02 != 0) return false;
    return true;
}

// 0x0032FB30
void CB3AIAggressionBehaviour::UpdateSlam()
{
    UnkStruct_0032FB30_car * me = field_44;
    UnkStruct_0032FB30_body * body = D_0055EFEC.field_0[me->field_19AC].field_0;
    UnkStruct_0032FB30_car * tg = field_48;
    if (field_24 != 0) {
        StopAttacking(true, false);
        return;
    }
    float now = D_00522680.field_0;
    float t = (now - field_30) / D_01E755F4.field_0;
    bool late = t < D_01E755FC.field_0;
    if (late) {
    }
    float d = func_0032FB30_inl2(func_0032FB30_inl3(me->field_30, tg->field_30), me->field_0);
    if (func_0032FB30_inl0(field_34) != func_0032FB30_inl0(d)) {
        StopAttacking(false, false);
    } else {
        if (field_40 == 0) {
            if (field_48->field_1914 != 1) {
                field_0 = 2;
                float n2 = D_00522680.field_0;
                field_30 = n2;
                field_2C = n2 + 1.0f;
            } else {
                StopAttacking(false, true);
            }
        } else {
            CGtV4d a;
            a = body->field_B0;
            UnkStruct_0032FB30_car * c = field_48;
            float s = 0.1f * (float)a.W();  // [C] retail FPU form, not a VU lane op: 0x32FCB4 lwc1 / 0x32FCC0 mul.s (the cast keeps the port's PS2 float model)
            field_10 = func_0032FB30_inl4(c->field_30, c->field_20 * s);
            field_20 = func_0032FB30_inl5(this);
        }
    }
}
