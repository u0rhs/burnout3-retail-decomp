// CGt2dFont::GetStringStartAndEnd(const unsigned short*,float,const unsigned short**,const unsigned short**,bool) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dFont.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (GetStringStartAndEnd: goto entry-jump loop, foundBreak hoisted before compare).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using namespace GtMathPs2;
// [C] matched by hand (a101): entry-jump loop via goto (N24), foundBreak set before the compare, tails shared via `after`.
// 0x001D7E10
float CGt2dFont::GetStringStartAndEnd(const unsigned short* s, float maxWidth, const unsigned short** outStart,
                                       const unsigned short** outEnd, bool flag) const
{
    bool foundBreak = false;
    float breakWidth;
    float maxW = maxWidth / field_8.marValues[0];
    while (*s == ' ' || *s == '\n') {
        s++;
        if (*s == 0) {
            *outStart = s;
            *outEnd = s;
            return 0.0f;
        }
    }

    *outStart = s;
    UnkStruct_Gt2dFont_Glyph* g = UnkInline_FindGlyph(*s);
    float width = -g->field_10.marValues[0];
    const unsigned short* lastBreak = 0;


    goto next;
body:
    {
        unsigned int c = *(const unsigned short *)(const char *)s;
        if (c == '\n') {
            float t = width + g->field_10.marValues[0];
            float extent = t + g->field_8.marValues[0];
            if (!(extent < maxW) && foundBreak) {
                *outEnd = lastBreak;
                return breakWidth * field_8.marValues[0];
            }
            *outEnd = s;
            return extent * field_8.marValues[0];
        }
        if (c == ' ') {
            float t = width + g->field_10.marValues[0];
            float extent = t + g->field_8.marValues[0];
            foundBreak = true;
            if (extent < maxW) {
                breakWidth = extent;
                lastBreak = s;
            } else {
                if (lastBreak) {
                    *outEnd = lastBreak;
                    return breakWidth * field_8.marValues[0];
                }
                goto after;
            }
        }
        if (flag && !foundBreak) {
            float t = width + g->field_10.marValues[0];
            float extent = t + g->field_8.marValues[0];
            if (extent < maxW)
                breakWidth = extent;
        }
        width += g->field_18;
        g = UnkInline_FindGlyph(c);
        if (flag && !foundBreak && !(width < maxW)) {
            float hb = width - g->field_18;
            hb += g->field_10.marValues[0];
            hb += g->field_8.marValues[0];
            *outEnd = s - 1;
            return hb * field_8.marValues[0];
        }
    }
next:
    s++;
    if (*s)
        goto body;
after:
    if (lastBreak || flag) {
        float t = width + g->field_10.marValues[0];
            float extent = t + g->field_8.marValues[0];
        if (!(extent < maxW)) {
            if (lastBreak)
                *outEnd = lastBreak;
            else if (flag)
                *outEnd = s - 1;
            return breakWidth * field_8.marValues[0];
        }
    }
    *outEnd = s;
    float ce = width + (g->field_10.marValues[0] + g->field_8.marValues[0]);
    return ce * field_8.marValues[0];
}
