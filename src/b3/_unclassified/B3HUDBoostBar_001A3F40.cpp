// CB3HUDBoostBar::UpdateTransition(float,bool,EHUDMode,EHUDMode) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HUDBoostBar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (header CGtV2d position copied before the field_694 read (retail reloads it, as BarUpdate); SetY((150 + v.Y()) - 150*t) keeps y in a register (pass3a)).

#include "b3/GtMathPs2.h"

enum EHUDMode {};
extern "C" void TakeLinkFromList__11CGtFreeListFP15CGtFreeListLinkP11CGtFreeList(void *, void *, void *);

struct UnkStruct_001A3F40_e {
    unsigned char pad_0[0x4];
    unsigned char field_4[0xC];
};
struct UnkStruct_001A3F40_row {
    unsigned char pad_0[0x40];
    UnkStruct_001A3F40_e * field_40;
    unsigned char pad_44[0x2C];
};
struct UnkStruct_001A3F40_hud {
    UnkStruct_001A3F40_row field_0[1];
};
struct UnkStruct_001A3F40_s {
    unsigned char pad_0[0x10];
    short field_10;
};
struct UnkStruct_001A3F40_o {
    unsigned char pad_0[0x38];
    int field_38;
};
struct UnkStruct_001A3F40_l {
    unsigned char pad_0[0x38];
    int field_38;
    unsigned char pad_3C[0x4];
};

class CB3HUDComponent {
public:
    void UpdateTransition(float p0, bool p1, EHUDMode p2, EHUDMode p3);
    unsigned char pad_0[0x4];
    UnkStruct_001A3F40_hud * field_4;
    int field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
};

class CB3HUDBoostBar : public CB3HUDComponent {
public:
    void UpdateTransition(float p0, bool p1, EHUDMode p2, EHUDMode p3);
    unsigned char pad_20[0x540];
    UnkStruct_001A3F40_o * field_560;
    unsigned char pad_564[0x12C];
    UnkStruct_001A3F40_s * field_690;
    float field_694;
    int field_698;
    GtMathPs2::CGtV2d * field_69C;
    GtMathPs2::CGtV2d field_6A0;
    unsigned char field_6A8;
};

// 0x001A3F40
void CB3HUDBoostBar::UpdateTransition(float p0, bool p1, EHUDMode p2, EHUDMode p3)
{
    field_6A8 = p1 && (p0 == 1.0f);
    if (p2 == (EHUDMode)3) {
        if (p0 == 1.0f) {
            int n = field_690->field_10 + 1;
            TakeLinkFromList__11CGtFreeListFP15CGtFreeListLinkP11CGtFreeList(
                ((UnkStruct_001A3F40_row *)((char *)field_4 + field_1C * 0x70))->field_40[n].field_4,
                (char *)field_560 - 8,
                ((UnkStruct_001A3F40_row *)((char *)field_4 + field_1C * 0x70))->field_40[field_698].field_4);
            field_698 = n;
            field_560->field_38 = (int)field_69C;
            float z = 0.0f;
            field_694 = 0.0f;
            field_694 += z;
            GtMathPs2::CGtV2d v = field_6A0;
            float t = field_694;
            if (t < 1.0f) {
                v.SetY((150.0f + v.Y()) - 150.0f * t);
            }
            *field_69C = v;
        }
    } else if (field_6A8 != 0 || (p2 != (EHUDMode)3 && !p1)) {
        int n = field_10 + 1;
        TakeLinkFromList__11CGtFreeListFP15CGtFreeListLinkP11CGtFreeList(
            ((UnkStruct_001A3F40_row *)((char *)field_4 + field_1C * 0x70))->field_40[n].field_4,
            (char *)field_560 - 8,
            ((UnkStruct_001A3F40_row *)((char *)field_4 + field_1C * 0x70))->field_40[field_698].field_4);
        field_698 = n;
        field_560->field_38 = field_8;
        field_694 = -1.0f;
    }
    CB3HUDComponent::UpdateTransition(p0, p1, p2, p3);
}
