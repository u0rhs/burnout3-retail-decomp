// CB3AIArbitrator::CalculateSpeedMatch() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIArbitrator.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (stabs1: Revenge inline lane read (WAxisType copy) + index accessor + flat early return).

// from build/vt\try_CalculateSpeedMatch__15CB3AIArbitratorFv_best.cpp
// CB3AIArbitrator::CalculateSpeedMatch() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIArbitrator.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3AIArbitrator;
struct UnkStruct_0019D4D0_2;
struct UnkStruct_0019D4D0_3;
struct UnkStruct_0019D4D0_6;
struct UnkStruct_0019D4D0_7;
struct UnkStruct_0019D4D0_e0;
struct UnkStruct_D_004E0D6C;
struct UnkStruct_D_0055EFEC;
struct UnkStruct_D_0064D3A0;

struct UnkStruct_D_0064D3A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0019D4D0_2 {
    unsigned char pad_0[0x11DE];
    unsigned char field_11DE;
    unsigned char pad_11DF[0x461];
    int field_1640;
    unsigned char pad_1644[0x368];
    signed char field_19AC;
};

struct UnkStruct_0019D4D0_3 {
    unsigned char pad_0[0x1640];
    int field_1640;
    unsigned char pad_1644[0x368];
    signed char field_19AC;
    unsigned char pad_19AD[0xA93];
    int field_2440;
};

struct UnkStruct_0019D4D0_e0 {
    UnkStruct_0019D4D0_6 * field_0;
    unsigned char pad_4[0x2C];
};

struct UnkStruct_D_0055EFEC {
    UnkStruct_0019D4D0_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_0019D4D0_6 {
    unsigned char pad_0[0xB0];
    u_long128 field_B0;
};

struct UnkStruct_0019D4D0_7 {
    float field_0;
    unsigned char pad_4[0x8];
    float field_C;
    unsigned char pad_10[0x10];
};

struct UnkStruct_D_004E0D6C {
    float field_0;
};

class CB3AIArbitrator {
public:
    void CalculateSpeedMatch();

    unsigned char pad_0[0x191];
    unsigned char field_191;
    unsigned char field_192;
    unsigned char pad_193[0x5CD];
    UnkStruct_0019D4D0_3 * field_760;
    unsigned char pad_764[0x2C];
    int field_790;
    void * field_794;
};

extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_0055EFEC D_0055EFEC;
extern UnkStruct_D_004E0D6C D_004E0D6C;

extern "C" UnkStruct_0019D4D0_2 * GetAttackTarget__24CB3AIAggressionBehaviourCFv(void *);  // CB3AIAggressionBehaviour::GetAttackTarget() const

#include "b3/GtMathPs2.h"
// stabs1 (2026-10-30), after Revenge's CalculateSpeedMatch__15CB4AIArbitrator (research/stabs, [L]): two inlined
// CB4RaceCar accessors returning an ERaceCarIndex, an inlined CB4CollidingBody lane read (vcopy + a stack
// UGtVectorAsTypes lRet) giving lrSpeedMPH. Here [G] placeholders: the speed is the velocity's W lane through
// WAxisType (its copy ctor is retail's `addiu a0,sp,0x20; sq a1,0(a0)`), the index is the racer's field_19AC.
static inline float func_0019D4D0_inl1(const UnkStruct_0019D4D0_6 *p) { return GtMathPs2::WAxisType(p->field_B0); }
static inline signed char func_0019D4D0_inl2(const UnkStruct_0019D4D0_3 *p) { return p->field_19AC; }
// 0x0019D4D0
void CB3AIArbitrator::CalculateSpeedMatch()
{
    field_790 = 0;
    if (D_0064D3A0.field_0 == 0) {
        return;
    }
    if (field_191 == 0) {
        return;
    }
    UnkStruct_0019D4D0_2 * target = GetAttackTarget__24CB3AIAggressionBehaviourCFv((char *)this + 0x170);
    if (target == 0) {
        return;
    }
    signed char idx = target->field_19AC;
    UnkStruct_0019D4D0_6 * car = D_0055EFEC.field_0[idx].field_0;
    UnkStruct_0019D4D0_3 * me = field_760;
    int flag = me->field_2440;
    if (flag == 0 && target->field_11DE != 0) {
        return;
    }
    if (me->field_1640 != idx && target->field_1640 != func_0019D4D0_inl2(me) && flag == 0) {
        float lrSpeedMPH = func_0019D4D0_inl1(car) * 2.2369363f;
        if (lrSpeedMPH < 100.0f) {
            return;
        }
    }
    field_794 = target;
    if (field_192 != 0) {
        field_790 = 5;
    } else {
        field_790 = 4;
    }
}
