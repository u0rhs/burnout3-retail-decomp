// func_0033DC80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (s321: rewritten as a clone of CGt2dObjectTable::GetTextSize (0x33DE40): CGtV2d pos/anchor locals, loc struct with extra CGtV2d, *out = loc.o.mObjectSpace.mSize).

// func_0033DC80 -- hand-written (s321) after the proven sibling CGt2dObjectTable::GetTextSize (0x33DE40): the same
// (CGtV2d *out, const CGt2dFrame &, const void *data) text-size callback for a paragraph cell [L] (shape, frame and
// zero path identical). Types placeholders [G].

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectText.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"

using namespace GtMathPs2;

struct UnkStruct_0033DC80_loc { CGt2dObjectText o; unsigned char pad_40[8]; CGtV2d extra; };
struct UnkStruct_0033DC80_txt {
    unsigned char pad_0[0x18];
    float field_18;
    float field_1C;
    const unsigned short *field_20;
    void *field_24;
    int field_28;
    int field_2C;
};

extern "C" void func_002F9690(CGt2dObject *, const CGtV2d &, const CGtV2d &, const void *, const unsigned short *, void *, int, int, float);

// 0x0033DC80
extern "C" void func_0033DC80(CGtV2d *out, const CGt2dFrame &frame, const void *data)
{
    const UnkStruct_0033DC80_txt *d = (const UnkStruct_0033DC80_txt *)data;
    CGtV2d pos(0.0f, 0.0f);
    CGtV2d anchor(0.0f, 0.0f);
    UnkStruct_0033DC80_loc loc;
    if (d->field_20[0] == 0) {
        loc.extra.marValues[0] = out->marValues[0] = 0.0f;
        loc.extra.marValues[1] = out->marValues[1] = 0.0f;
        return;
    }
    func_002F9690(&loc.o, pos, anchor, data, d->field_20, d->field_24, d->field_28, d->field_2C, (-1.0f == d->field_18) ? d->field_1C : d->field_18);
    *out = loc.o.mObjectSpace.mSize;
}
