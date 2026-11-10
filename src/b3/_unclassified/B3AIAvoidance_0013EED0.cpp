// CB3AIAvoidanceMap::CheckRaceCar() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAvoidance.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (for loop over &D_00522660 direct (per-pass base), real member CheckVehicle call with by-value vector, bool field_18EA, 3-operand vsuby.y stand-in).

// near37: every race car except the owner (top-tested for loop), skipped when it is the owner's attack target or idle while
// the owner is fast (field_10CC > 10), or when it is crashing into the owner; then the height test and CheckVehicle with the
// car's matrix, its model's extents vector by value, crashing flag, risk 5 (crashing) / 6 and the model's box at +0xE80.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_0013EED0_car;
struct UnkStruct_0013EED0_ent { struct UnkStruct_0013EED0_obj * field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_0013EED0_obj { unsigned char pad_0[0xB0]; CGtV3d field_B0; };
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x3C98C];
    UnkStruct_0013EED0_ent field_3C98C[1];
    unsigned char pad_3C9BC[0x12AD1C - 0x3C9BC];
    int field_12AD1C;
    unsigned char pad_12AD20[0x8];
    UnkStruct_0013EED0_car * field_12AD28[1];
};
struct UnkStruct_D_01E75534 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0013EED0_beh { unsigned char pad_0[0x10]; };
struct UnkStruct_0013EED0_car {
    unsigned char pad_0[0x30];
    CGtV3d field_30;
    void * field_40;
    unsigned char pad_44[0x1588];
    void * field_15CC;
    unsigned char pad_15D0[0x31A];
    bool field_18EA;
    unsigned char pad_18EB[0x29];
    int field_1914;
    unsigned char pad_1918[0x94];
    signed char field_19AC;
    unsigned char pad_19AD[0xE1B];
    unsigned char field_27C8;
};
struct UnkStruct_0013EED0_own {
    unsigned char pad_0[0x30];
    CGtV3d field_30;
    unsigned char pad_40[0x108C];
    float field_10CC;
    unsigned char pad_10D0[0x26C];
    int field_133C;
    unsigned char pad_1340[0x820];
    UnkStruct_0013EED0_beh field_1B60;
};
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_01E75534 D_01E75534;
extern "C" UnkStruct_0013EED0_car * GetAttackTarget__24CB3AIAggressionBehaviourCFv(const UnkStruct_0013EED0_beh *);
static inline float fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }

class CGtAxisAlignedBox;
enum EAIAvoidanceRisk {};
class CB3AIAvoidanceMap {
public:
    void CheckRaceCar();
    void CheckVehicle(const CGtMatrix3x4 &, CGtV3d, bool, bool, EAIAvoidanceRisk, const CGtAxisAlignedBox &);
    unsigned char pad_0[0x454];
    UnkStruct_0013EED0_own * field_454;
};
// [L] N185 stand-in for operator-(YAxisType, YAxisType): the three-operand compiler-chosen form gives retail's registers
// (car in $vf1, owner in $vf2, result over the car's); the header's "+j"(b) form numbers them the other way round
static inline YAxisType func_0013EED0_inl1(YAxisType a, YAxisType b) { u_long128 r; asm("vsuby.y %0, %1, %2y" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return YAxisType(r); }
// 0x0013EED0
void CB3AIAvoidanceMap::CheckRaceCar()
{
    UnkStruct_0013EED0_car * car;
    if (field_454->field_133C == 0)
        return;
    for (int i = 0; i < D_00522660.field_12AD1C; i++) {
        car = D_00522660.field_12AD28[i];
        if (car == (UnkStruct_0013EED0_car *)field_454)
            goto next;
        if (field_454->field_10CC > 10.0f) {
            if (car == GetAttackTarget__24CB3AIAggressionBehaviourCFv(&field_454->field_1B60))
                goto next;
            if (car->field_18EA == 0 && car->field_1914 == 0 && car->field_27C8 == 0)
                goto next;
        }
        if (car->field_18EA != 0 && car->field_15CC == (void *)field_454)
            goto next;
        if (fabsf(func_0013EED0_inl1(((UnkStruct_0013EED0_car *)field_454)->field_30.Y(), car->field_30.Y())) <= D_01E75534.field_0) {
            CheckVehicle(*(const CGtMatrix3x4 *)car, D_00522660.field_3C98C[car->field_19AC].field_0->field_B0, car->field_18EA, true, (EAIAvoidanceRisk)(car->field_18EA ? 5 : 6), *(const CGtAxisAlignedBox *)((char *)car->field_40 + 0xE80));
        }
    next:;
    }
}
