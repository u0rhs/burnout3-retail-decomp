// CGt2dObjectTable::RenderText(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,unsigned short*,const CGt2dFrame&,const void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dObjectTable.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near2: RenderItalicText's shape on CGt2dObjectText (Prepare overloads func_001D6C40/6AD0/6970), truncation loop n > 1).

// CGt2dObjectTable::RenderText(const CGtV2d &, const CGtV2d &, unsigned short *, const CGt2dFrame &, const void *) --
// hand-written (near2, 2026-10-27; the lifter refused it): RenderItalicText's twin on CGt2dObjectText. Copy the cell text
// into the buffer and truncate it with kaEllipses to the cell width (else use the cell's own text), prepare a text object
// through one of the three CGt2dObjectText::Prepare overloads by the cell's text type ([C] names, config/symbol_addrs_b3names.txt
// 0x1D6970/0x1D6AD0/0x1D6C40 "no symbol form", so called by their func_ labels), and render it through the frame.
// Unlike RenderItalicText the truncation loop stops at one character (`n > 1`: retail's slti 2) [C asm].
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectText.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"

using namespace GtMathPs2;

// [G] the table cell's text data block (offsets from retail's loads)
struct UnkStruct_0033EA10_text {
    CGtV2d field_0;
    unsigned char pad_8[0x18];
    CGtV4d field_20;
    CGtV2d field_30;
    CGtV2d field_38;
    float field_40;
    const CGt2dFont *field_44;
    const unsigned short *field_48;
    int field_4C;
};
extern "C" void func_001D6970(CGt2dObjectText *self, const CGtV2d &pos, const CGtV2d &anchor, float size,
                              const CGtV4d colour, const CGt2dFont *font, const unsigned short *text, const CGtV2d &arg);
extern "C" void func_001D6AD0(CGt2dObjectText *self, const CGtV2d &pos, const CGtV2d &anchor, float size,
                              const CGtV4d colour, const CGt2dFont *font, const unsigned short *text,
                              const CGtV2d &scale, int type);
extern "C" void func_001D6C40(CGt2dObjectText *self, const CGtV2d &pos, const CGtV2d &anchor, float size,
                              const CGtV4d colour, const CGt2dFont *font, const unsigned short *text);

// [L] N185: GtMathPs2::Min(CGtV4d, CGtV4d) stand-in, both operands by reference (as the proven sibling func_0033E220)
static inline CGtV4d func_0033EA10_min(const CGtV4d &a, const CGtV4d &b)
{
    u_long128 r;
    asm("vmini.xyzw %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV4d(r);
}
// [G] the cell's text set-up as an inline helper (placeholder name): the position by reference (the caller's named q),
// the case 1/2 type argument re-read through a pun (retail reloads field_4C)
static inline void func_0033EA10_inl1(CGt2dObjectText *obj, const CGtV2d &p, const UnkStruct_0033EA10_text *d, const unsigned short *t)
{
    switch (d->field_4C) {
    case 0:
        func_001D6C40(obj, p, d->field_30, d->field_40, d->field_20, d->field_44, t);
        break;
    case 1:
    case 2:
        func_001D6AD0(obj, p, d->field_30, d->field_40, d->field_20, d->field_44, t, d->field_38, *(const int *)&d->field_4C);
        break;
    case 3:
        func_001D6970(obj, p, d->field_30, d->field_40, d->field_20, d->field_44, t, d->field_0);
        break;
    }
}
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
extern "C" unsigned short *Copy__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" unsigned short *Append__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" int Length__10CGtUnicodeFPCUs(const unsigned short *);
extern const unsigned short kaEllipses[];

extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(
    const CGtV2d &pos, const CGtV2d &size, unsigned short *text, const CGt2dFrame &frame, const void *data)
{
    CGtV2d q;
    const UnkStruct_0033EA10_text *d = (const UnkStruct_0033EA10_text *)data;
    CGt2dObjectText obj;
    CGt2dObject::CGt2dObjectSpace sp;
    CGtV4d white(1.0f, 1.0f, 1.0f, 1.0f);
    const unsigned short *t = d->field_48;
    if (*t == 0) return;
    if (text != 0) {
        Copy__10CGtUnicodeFPUsPCUs(text, t);
        if (d->field_40 * d->field_44->GetStringWidth(text) > size.marValues[0]) {
            float ew = d->field_40 * d->field_44->GetStringWidth(kaEllipses);
            int n = Length__10CGtUnicodeFPCUs(text);
            float tw = d->field_40 * d->field_44->GetStringWidth(text);
            while (n > 1 && tw + ew > size.marValues[0]) {
                n--;
                text[n] = 0;
                tw = d->field_40 * d->field_44->GetStringWidth(text);
            }
            Append__10CGtUnicodeFPUsPCUs(text, kaEllipses);
        }
    } else {
        text = (unsigned short *)t;
    }
    q = pos + size * d->field_30;
    func_0033EA10_inl1(&obj, q, d, text);
    sp = obj.ObjectSpace();
    sp.mTopLeftPos = frame.WorldPos() + frame.WorldScale() * sp.mTopLeftPos;
    sp.mSize = sp.mSize * frame.WorldScale();
    sp.mColour = func_0033EA10_min(sp.mColour * frame.WorldColour(), white);
    obj.Render(sp);
}
