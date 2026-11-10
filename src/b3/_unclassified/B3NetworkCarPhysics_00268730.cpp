// CB3NetworkCarPhysics::HideUnderRoad() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkCarPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CB3NetworkCarPhysics;
struct UnkStruct_00268730_1;

struct UnkStruct_00268730_1 {
    unsigned char pad_0[0x30];
    GtMathPs2::CGtV3d field_30;
};

class CB3NetworkCarPhysics {
public:
    void HideUnderRoad();

    unsigned char pad_0[0x204];
    UnkStruct_00268730_1 * field_204;
    unsigned char pad_208[0x134C];
    unsigned char field_1554;
};

extern "C" void func_001AB610(CB3NetworkCarPhysics *, UnkStruct_00268730_1 *);

// 0x00268730
void CB3NetworkCarPhysics::HideUnderRoad()
{
    field_204->field_30.SetY(((float)-100000));
    func_001AB610(this, field_204);
    field_1554 = 1;
}
