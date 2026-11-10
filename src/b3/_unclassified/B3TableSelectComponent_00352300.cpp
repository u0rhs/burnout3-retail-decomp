// CB3TableSelectComponent::Update(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3TableSelectComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (a245: scoped opt_repositioncode off [G] (N182) keeps ConstructObject inline; early-return stub label reused via goto ret after Prepare).

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;

class CGt2dFrame;
class CGt2dObject;
class CB3MenuComponentSelectionData;

struct UnkStruct_00352300_2 {
    unsigned short field_0;
};

class CGt2dObjectTable {
public:
    CGtV2d GetRowPos(int);   // [G] return type: an 8-byte result through a0 (hidden pointer)
    CGtV2d GetRowSize(int);  // [G] as GetRowPos
};

class CB3Panel2dObject {
public:
    void Prepare(const CGtV2d &, const CGtV2d &, const CGtV2d &, unsigned int, float);
};

class CGt2dScene {
public:
    CGt2dObject * ConstructObject(int, CGt2dFrame *);

    unsigned char pad_0[0x14];
    CGt2dFrame * field_14;
};

struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3TableSelectComponent {
public:
    void Update(float p0);

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    UnkStruct_00352300_2 * field_C;
    CGt2dObjectTable * field_10;
    CB3Panel2dObject * field_14;
    int field_18;
    int field_1C;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern CGt2dScene D_01E903E0;

// FAKE-free: N182 [G] scoped pragma
#pragma push
#pragma opt_repositioncode off
// 0x00352300
void CB3TableSelectComponent::Update(float p0)
{
    if (D_01E90424.field_0 != 5) return;
    unsigned short sel = field_C->field_0;
    if (field_18 == sel) {
ret:
        return;
    }
    CGt2dScene * const scene = &D_01E903E0;
    CGt2dFrame * root = scene->field_14;
    field_18 = sel;
    CGtV2d pos;
    pos = field_10->GetRowPos(field_18 + field_1C);
    pos.SetX(pos.X() - 2.0f);
    CGtV2d size;
    size = field_10->GetRowSize(field_18 + field_1C);
    size.SetX(4.0f + size.X());
    if (field_14 == 0) {
        field_14 = (CB3Panel2dObject *)scene->ConstructObject(field_8, root);
    }
    field_14->Prepare(pos, CGtV2d(0.0f, 0.0f), size, 32, 0.0f);
    goto ret;
}
#pragma pop
