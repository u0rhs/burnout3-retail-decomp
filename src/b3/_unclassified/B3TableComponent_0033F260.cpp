// CB3TableComponent::RecalculateSize() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TableComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-written; sibling func_0033FCF0).

// Hand-written (a113); shapes from func_0033FCF0 (PrepareRowBackgrounds sibling: row Y() accessors, N24 goto loop).
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class CGt2dObjectTableData {
public:
    unsigned char pad_0[0x8];
    int field_8;
};

// [G] stands for CGtV2d with its Y() accessor, as in func_0033FCF0.
struct UnkStruct_0033FF10_v2 : public CGtV2d {
    float Y() const { return marValues[1]; }
};

class CGt2dObjectTable : public CGt2dObject {
public:
    UnkStruct_0033FF10_v2 GetRowPos(int);   // [G] 8-byte result through a0 (hidden pointer)
    UnkStruct_0033FF10_v2 GetRowSize(int);  // [G] as GetRowPos
};

class CB3HUDBackground2dObject : public CGt2dObject {
public:
    void Prepare(const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, unsigned int);
};

extern "C" bool Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, unsigned int, int);
extern "C" void RecalculateSize__16CGt2dObjectTableFv(void *);

class CB3TableComponent {
public:
    void RecalculateSize();
    unsigned char pad_0[0xC];
    CGt2dObjectTable * field_C;
    CGt2dObject * field_10;
    unsigned char pad_14[4];
    CGt2dObject ** field_18;
    unsigned char pad_1C[4];
    const CGt2dObjectTableData * field_20;
    unsigned char pad_24[0xC];
    int field_30;
};

// 0x0033F260
void CB3TableComponent::RecalculateSize()
{
    RecalculateSize__16CGt2dObjectTableFv(field_C);
    int flags = field_30;
    if ((flags & 1) != 0) {
        if ((flags & 2) != 0) {
            const CGtV2d &psz = field_C->mObjectSpace.mSize;
            Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(field_10, field_C->mObjectSpace.mTopLeftPos, CGtV2d(0.0f, 0.0f), psz, 31, 0);
        } else if ((flags & 8) != 0) {
            int i;
            if ((flags & 0x10) != 0) i = 0; else i = 1;
            goto test;
        body:
            {
                CGtV2d size;
                CGtV2d at;
                at.marValues[0] = field_18[i]->mObjectSpace.mTopLeftPos.marValues[0];
                at.marValues[1] = field_C->GetRowPos(i).Y();
                size = field_18[i]->mObjectSpace.mSize;
                size.marValues[1] = field_C->GetRowSize(i).Y();
                ((CB3HUDBackground2dObject *)field_18[i])->Prepare(at, CGtV2d(0.0f, 0.0f), size, CGtV4d(1.0f, 1.0f, 1.0f, 1.0f), 3);
            }
            i++;
        test:
            if (i < field_20->field_8) goto body;
        }
    }
}
