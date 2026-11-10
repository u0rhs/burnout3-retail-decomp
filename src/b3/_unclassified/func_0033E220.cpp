// Hand-written; the lifter refused it (near1: Min(sp.mColour * frame.WorldColour(), white) with both-by-ref Min stand-in fixes white ctor slot).

// v279/g2d2/near1: hand-written (lifter refused). Truncation loop + paragraph Prepare (v279); `CGtV2d p;` first +
// `p = pos + size*d->field_10;` and mSize = mSize * WorldScale() (g2d2); colour = Min(sp.mColour * frame.WorldColour(), white)
// with a both-by-reference Min stand-in (near1) puts white's ctor temp at retail's 0x90.

// func_0033E220 -- a CGt2dObjectTable cell render callback [L: its unit, between RenderImage and
// RenderItalicTextNoTruncation; DNAT's medium row names it RenderItalicText, but retail's tables put that name at
// another address, so the placeholder stays]: truncate the text with kaEllipses to the cell width, prepare a paragraph
// object (func_002F9690, [L] DNAT CGt2dObjectParagraph::Prepare) and render it through the frame (the RenderBox tail).
// Data-block layout [G] from the loads.
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using namespace GtMathPs2;

struct UnkStruct_0033E220_set {
    unsigned char pad_0[0x8];
    float field_8;
    unsigned char pad_C[0x4];
    const CGt2dFont *field_10;
};
struct UnkStruct_0033E220 {
    CGtV4d field_0;
    CGtV2d field_10;
    float field_18;
    float field_1C;
    const unsigned short *field_20;
    const UnkStruct_0033E220_set *field_24;
    unsigned int field_28;
    int field_2C;
};
struct UnkStruct_0033E220_frame {
    unsigned char pad_0[0x20];
    CGtV2d field_20;
    CGtV2d field_28;
    CGtV4d field_30;
};
extern "C" unsigned short *Copy__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" unsigned short *Append__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" int Length__10CGtUnicodeFPCUs(const unsigned short *);
extern unsigned short kaEllipses[];
extern "C" void func_002F9690(CGt2dObject *obj, const CGtV2d &pos, float width, const CGtV2d &anchor, CGtV4d colour,
                              const unsigned short *text, const UnkStruct_0033E220_set *settings, unsigned int a, int type);

// [L] N185: stand-in for GtMathPs2::Min(CGtV4d, CGtV4d), both operands by reference (near1: by-value forms add dead 16-byte
// slots; with frame.WorldColour()'s by-value return this gives retail's [white, dead, ctor t, dead] slots) [G shape]
static inline CGtV4d func_0033E220_min(const CGtV4d &a, const CGtV4d &b)
{
    u_long128 r;
    asm("vmini.xyzw %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV4d(r);
}
static inline CGtV2d func_0033E220_inl1(const CGt2dObject &o) { return o.mObjectSpace.mTopLeftPos; }
static inline CGtV2d func_0033E220_inl2(const CGt2dObject &o) { return o.mObjectSpace.mSize; }

// 0x003C1990
// 0x0033E220
extern "C" void func_0033E220(const CGtV2d &pos, const CGtV2d &size, unsigned short *text, const CGt2dFrame &frame,
                              const void *data)
{
    CGtV2d p;
    const UnkStruct_0033E220_frame *f = (const UnkStruct_0033E220_frame *)&frame;
    const UnkStruct_0033E220 *d = (const UnkStruct_0033E220 *)data;
    CGt2dObject obj;
    CGt2dObject::CGt2dObjectSpace sp;
    CGtV4d white = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
    if (*d->field_20 == 0) return;
    if (text != 0) {
        Copy__10CGtUnicodeFPUsPCUs(text, d->field_20);
        const UnkStruct_0033E220_set *st = d->field_24;
        if (st->field_10->GetStringWidth(text) * st->field_8 > size.marValues[0]) {
            float ell = st->field_10->GetStringWidth(kaEllipses) * d->field_24->field_8;
            int n = Length__10CGtUnicodeFPCUs(text);
            float w = d->field_24->field_10->GetStringWidth(text) * d->field_24->field_8;
            while (n > 0 && !(w + ell <= size.marValues[0])) {
                n--;
                text[n] = 0;
                w = d->field_24->field_10->GetStringWidth(text) * d->field_24->field_8;
            }
            Append__10CGtUnicodeFPUsPCUs(text, kaEllipses);
        }
    } else {
        text = (unsigned short *)d->field_20;
    }
    p = pos + size * d->field_10;
    float width = d->field_18 == -1.0f ? d->field_1C - pos.marValues[0] : d->field_18;
    func_002F9690(&obj, p, width, d->field_10, d->field_0, text, d->field_24, d->field_28, d->field_2C);
    sp = obj.ObjectSpace();
    sp.mTopLeftPos = frame.WorldPos() + frame.WorldScale() * sp.mTopLeftPos;
    sp.mSize = sp.mSize * frame.WorldScale();
    sp.mColour = func_0033E220_min(sp.mColour * frame.WorldColour(), white);
    obj.Render(sp);
}
