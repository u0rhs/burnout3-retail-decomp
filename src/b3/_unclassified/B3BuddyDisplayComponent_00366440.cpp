// CB3BuddyDisplayComponent::SetFocus(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3BuddyDisplayComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (reused func_003665B0 highlight block; bool return).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CGt2dObjectTable {
public:
    CGtV2d GetRowPos(int);   // [G] return type: an 8-byte result through a0 (hidden pointer), as func_0033FF10
    CGtV2d GetRowSize(int);  // [G] as GetRowPos
};

class CB3Panel2dObject {
public:
    void Prepare(const CGtV2d &, const CGtV2d &, const CGtV2d &, unsigned int, float);
};


struct UnkStruct_krB3BuddyTableSize { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_krB3BuddyTableSize krB3BuddyTableSize;
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
class CB3BuddyDisplayComponent {
public:
    bool SetFocus(bool);
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[0xE62];
    CGt2dObjectTable *field_E6C;
    void *field_E70;
    void *field_E74;
    unsigned short field_E78;
    unsigned char pad_E7A[2];
    int field_E7C;
    int field_E80;
    unsigned char field_E84;
};
// 0x00366440
bool CB3BuddyDisplayComponent::SetFocus(bool focus)
{
    if (focus) {
        field_E84 = 1;
        if (field_E7C == 0) {
            field_E7C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, field_8 + 1, field_E74);
        }
        if (field_E7C != 0) {
            CGtV2d pos;
            pos = field_E6C->GetRowPos(field_E78 + 1);
            pos.SetX(7.0f);
            CGtV2d size;
            size = field_E6C->GetRowSize(field_E78 + 1);
            size.SetX(krB3BuddyTableSize.field_0 - 4.0f);
            ((CB3Panel2dObject *)field_E7C)->Prepare(pos, CGtV2d(0.0f, 0.0f), size, 32, 0.0f);
        }
    } else {
        field_E84 = 0;
        if (field_E7C != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(&D_01E903E0, field_8 + 1, (void *)field_E7C);
            field_E7C = 0;
        }
    }
    return true;
}
