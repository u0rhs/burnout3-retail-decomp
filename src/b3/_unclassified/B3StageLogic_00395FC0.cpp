// CB3StageLogic::DamageRaceCar(CB3RaceCar*,CB3RaceCar*,EB3DamageType) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StageLogic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (parkfix: tool-bug park fixed (N213)).

// CB3StageLogic::DamageRaceCar(CB3RaceCar*,CB3RaceCar*,EB3DamageType) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StageLogic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a105i form: 50/50, JTBL+RELOC OK; earlier wire-in parked at 6 bytes (link) - re-test).
// parkfix: the table load is a statement of its own (dmg = table; dmg *= k): the one-expression form loaded the two operands into
// swapped registers ($f1/$f0), which diff_vs_retail hid (it dropped load base registers; 6 bytes in the link).

struct UnkStruct_00395FC0_car {
    unsigned char pad_0[0x10C0];
    unsigned char field_10C0[0x5F4];
    float field_16B4;
};
extern float D_004E1038;
extern float D_004E103C;
#include "b3/classes/UnkStruct_D_0052267C.h"
extern UnkStruct_D_0052267C D_0052267C;
extern float _karRoadRageDamageTable[];
extern "C" void DecrementHealth__8CB3ScoreFf(void *, float);
extern "C" void DamageRaceCar__13CB3StageLogicFP10CB3RaceCarP10CB3RaceCar13EB3DamageType(void *self, UnkStruct_00395FC0_car *p1, void *p2, unsigned int type)
{
    float hp = p1->field_16B4;
    bool low = hp < D_004E1038;
    float dmg;
    switch (type) {
    case 0: case 1: case 2: case 3:
        dmg = _karRoadRageDamageTable[type];
        break;
    case 4: case 5: case 6:
        dmg = _karRoadRageDamageTable[type]; dmg *= D_0052267C.field_0;
        break;
    case 7: case 8:
        dmg = _karRoadRageDamageTable[type];
        break;
    default:
        dmg = 0.0f;
        break;
    }
    if ((unsigned int)(type - 7) < 2) {
        if (low) {
            dmg = hp;
        } else if (!(dmg < hp)) {
            dmg = hp - D_004E103C;
        }
    }
    DecrementHealth__8CB3ScoreFf(p1->field_10C0, dmg);
}
