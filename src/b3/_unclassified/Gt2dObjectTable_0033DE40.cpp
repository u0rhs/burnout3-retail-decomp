// CGt2dObjectTable::GetTextSize(GtMathPs2::CGtV2d*,const CGt2dFrame&,const void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dObjectTable.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-written).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectText.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"

using namespace GtMathPs2;

struct UnkStruct_Table_loc { CGt2dObjectText o; unsigned char pad_40[8]; CGtV2d extra; };
struct UnkStruct_Table_txt {
    CGt2dObjectText::COutlineDropShadow field_0;
    CGtV4d field_20;
    unsigned char pad_30[8];
    CGtV2d field_38;
    float field_40;
    const CGt2dFont *field_44;
    const unsigned short *field_48;
    int field_4C;
};

extern "C" void func_001D6C40(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const CGt2dFont *, const unsigned short *);
extern "C" void func_001D6AD0(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const CGt2dFont *, const unsigned short *, const CGtV2d *, int);
extern "C" void func_001D6970(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const CGt2dFont *, const unsigned short *, const void *);

extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *out, const CGt2dFrame &frame, const void *data)
{
    const UnkStruct_Table_txt *d = (const UnkStruct_Table_txt *)data;
    CGtV2d pos(0.0f, 0.0f);
    CGtV2d anchor(0.0f, 0.0f);
    UnkStruct_Table_loc loc;
    if (d->field_48[0] == 0) {
        loc.extra.marValues[0] = out->marValues[0] = 0.0f;
        loc.extra.marValues[1] = out->marValues[1] = 0.0f;
        return;
    }
    switch (d->field_4C) {
    case 0:
        func_001D6C40(&loc.o, pos, anchor, d->field_40, d->field_20, d->field_44, d->field_48);
        break;
    case 1:
    case 2:
        func_001D6AD0(&loc.o, pos, anchor, d->field_40, d->field_20, d->field_44, d->field_48, &d->field_38, *(const int *)&d->field_4C);
        break;
    case 3:
        func_001D6970(&loc.o, pos, anchor, d->field_40, d->field_20, d->field_44, d->field_48, data);
        break;
    }
    *out = loc.o.mObjectSpace.mSize;
}
