// Hand-written; the lifter refused it (.lit4 extern D_004E0BFC written as the literal 3.402823466e+38f (FLT_MAX)).


// s314 (2026-10-27): tail in the proven sibling RenderItalicText's form (sp = obj.ObjectSpace(); WorldPos/WorldScale/WorldColour; obj.Render(sp)), a named CGtV2d q, and the Min stand-in with both operands by reference -> 64 -> 5.

// func_003C1990 -- [L] DNAT: CB3ResultsPage::RenderStylisedText(const CGtV2d&, const CGtV2d&, unsigned short*,
// const CGt2dFrame&, const void*) (research/proto/new_names.csv, high). A table cell render callback: truncate the
// text with an ellipsis to the cell width, prepare a stylised text object (func_003D0710) and render it through the
// frame (the CGt2dObjectTable::RenderBox tail). Data-block layout [G] from the loads.
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using namespace GtMathPs2;

struct UnkStruct_003C1990 {
    CGtV4d field_0;
    CGtV2d field_10;
    unsigned char pad_18[0x8];
    float field_20;
    const CGt2dFont *field_24;
    const unsigned short *field_28;
    int field_2C;
    int field_30;
};
struct UnkStruct_003C1990_frame {
    unsigned char pad_0[0x20];
    CGtV2d field_20;
    CGtV2d field_28;
    CGtV4d field_30;
};
extern "C" unsigned short *Copy__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" unsigned short *Append__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" int Length__10CGtUnicodeFPCUs(const unsigned short *);
extern unsigned short D_004CA330[];
extern "C" void func_003D0710(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, CGtV4d colour, int a, int b,
                              int c, const CGt2dFont *font, float size, float maxWidth, const unsigned short *text,
                              bool flag);

// [L] N185: as v241's stand-in for GtMathPs2::Min(CGtV4d, CGtV4d) (first operand by reference)
static inline CGtV4d func_003C1990_min(const CGtV4d &a, const CGtV4d &b)
{
    u_long128 r;
    asm("vmini.xyzw %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV4d(r);
}
static inline CGtV2d func_003C1990_inl1(const CGt2dObject &o) { return o.mObjectSpace.mTopLeftPos; }
static inline CGtV2d func_003C1990_inl2(const CGt2dObject &o) { return o.mObjectSpace.mSize; }

// 0x003C1990
extern "C" void func_003C1990(const CGtV2d &pos, const CGtV2d &size, unsigned short *text, const CGt2dFrame &frame,
                              const void *data)
{
    CGtV2d q;
    const UnkStruct_003C1990_frame *f = (const UnkStruct_003C1990_frame *)&frame;
    const UnkStruct_003C1990 *d = (const UnkStruct_003C1990 *)data;
    CGt2dObject obj;
    CGt2dObject::CGt2dObjectSpace sp;
    CGtV4d white = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
    if (*d->field_28 == 0) return;
    if (text != 0) {
        Copy__10CGtUnicodeFPUsPCUs(text, d->field_28);
        if (d->field_24->GetStringWidth(text) * d->field_20 > size.marValues[0]) {
            float ell = d->field_24->GetStringWidth(D_004CA330) * d->field_20;
            int n = Length__10CGtUnicodeFPCUs(text);
            float w = d->field_24->GetStringWidth(text) * d->field_20;
            while (n > 0 && !(w + ell <= size.marValues[0])) {
                n--;
                text[n] = 0;
                w = d->field_24->GetStringWidth(text) * d->field_20;
            }
            Append__10CGtUnicodeFPUsPCUs(text, D_004CA330);
        }
    } else {
        text = (unsigned short *)d->field_28;
    }
    q = pos + size * d->field_10;
    func_003D0710(&obj, q, d->field_10, d->field_0, d->field_30, d->field_2C, 0, d->field_24,
                  d->field_20, 3.402823466e+38f, text, false);
    sp = obj.ObjectSpace();
    sp.mTopLeftPos = frame.WorldPos() + frame.WorldScale() * sp.mTopLeftPos;
    sp.mSize = sp.mSize * frame.WorldScale();
    sp.mColour = func_003C1990_min(sp.mColour * frame.WorldColour(), white);
    obj.Render(sp);
}
