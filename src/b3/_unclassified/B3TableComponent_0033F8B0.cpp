// CB3TableComponent::RenderImageAndText(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,unsigned short*,const CGt2dFrame&,const void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TableComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (static extern C; text pos = copy of pos with x += d60 + 3.0).

#include "b3/GtMathPs2.h"
#include "b3/classes/CGt2dFrame.h"

using namespace GtMathPs2;

struct UnkStruct_Gt2dObjectTable_it {
    unsigned char pad_0[0x50];
    unsigned char field_50[0x10];
    float field_60;
};

extern "C" void RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, const CGt2dFrame &, const void *);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, const CGt2dFrame &, const void *);

extern "C" void RenderImageAndText__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(
    const CGtV2d &pos, const CGtV2d &size, unsigned short *p, const CGt2dFrame &frame, const void *data)
{
    const UnkStruct_Gt2dObjectTable_it *d = (const UnkStruct_Gt2dObjectTable_it *)data;
    RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(pos, size, p, frame, d->field_50);
    CGtV2d tp(pos);
    tp.marValues[0] = tp.marValues[0] + d->field_60 + 3.0f;
    RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(tp, size, p, frame, data);
}
