// CB3HUDComponent::Prepare(int,int,int,int,EHUDAlign,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (CGtV2d/CGtV4d temps (GetAlignPos by-value result, V2d(1,1), V4d by value); field_28 read into a local after the call; field_4 cast to CB3HUD*).

// CB3HUDComponent::Prepare(int,int,int,int,EHUDAlign,int) -- hand-finished from the lifted source.
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

enum EHUDAlign {};
class CB3HUDComponent;

class CB3HUD {
public:
    CGtV2d GetAlignPos(EHUDAlign);  // 8-byte result through a hidden pointer in a0 [L]

    unsigned char pad_0[0x28];
    int field_28;
    unsigned char pad_2C[0x44];
};

class CB3HUDManager {
public:
    void AddComponent(CB3HUDComponent*, int, int, int, int);

    CB3HUD field_0[1];  // [G] element count unknown; stride 0x70 (B3HUDManager.cpp)
};

class CB3HUDComponent {
public:
    int Prepare(int p0, int p1, int p2, int p3, EHUDAlign p4, int p5);

    unsigned char pad_0[0x4];
    CB3HUDManager * field_4;
    int field_8;
    unsigned char pad_C[0x6];
    short field_12;
    int field_14;
    EHUDAlign field_18;
    signed char field_1C;
};

extern "C" int func_001D5CE0(void *, const CGtV2d &, const CGtV2d &, CGtV4d);

// 0x0019F6A0
int CB3HUDComponent::Prepare(int p0, int p1, int p2, int p3, EHUDAlign p4, int p5)
{
    field_14 = p5;
    field_18 = p4;
    field_1C = p3;
    field_12 = p0;
    field_4->AddComponent(this, p3, p0, p1, p2 + 1);
    // [G] field_4 indexed as a CB3HUD array (stride 0x70) from its own base: retail adds base + idx*0x70
    CGtV2d pos = ((CB3HUD *)field_4)[field_1C].GetAlignPos(field_18);
    int t = ((CB3HUD *)field_4)[field_1C].field_28;
    field_8 = func_001D5CE0((void *)(t), pos, CGtV2d(1.0f, 1.0f), CGtV4d(1.0f, 1.0f, 1.0f, 1.0f));
    return 1;
}
