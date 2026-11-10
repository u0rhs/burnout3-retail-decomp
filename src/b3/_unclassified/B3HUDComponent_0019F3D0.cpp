// CB3HUDComponent::AdjustScalingForSplitScreen() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (single-case switch; field_8->field_8 is a CGtV2d assigned CGtV2d(0.75f, 0.75f) (the temporary keeps the dead stack stores)).

// CB3HUDComponent::AdjustScalingForSplitScreen() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3HUDComponent;
struct UnkStruct_0019F3D0_1;
struct UnkStruct_0019F3D0_2;
struct UnkStruct_0019F3D0_3;

struct UnkStruct_0019F3D0_1 {
    unsigned char pad_0[0x170];
    int field_170;
};

struct UnkStruct_0019F3D0_2 {
    unsigned char pad_0[0x8];
    CGtV2d field_8;
};

struct UnkStruct_0019F3D0_3 {
    float field_0;
    float field_4;
};

class CB3HUDComponent {
public:
    void AdjustScalingForSplitScreen();

    unsigned char pad_0[0x4];
    UnkStruct_0019F3D0_1 * field_4;
    UnkStruct_0019F3D0_2 * field_8;
};

// 0x0019F3D0
void CB3HUDComponent::AdjustScalingForSplitScreen()
{
    switch (field_4->field_170) {
    case 2:
        field_8->field_8 = CGtV2d(0.75f, 0.75f);
        break;
    }
}
