// CB3FlashText2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,float,GtMathPs2::CGtV4d,const CGt2dFont*,const unsigned short*,const GtMathPs2::CGtV2d&) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3FlashText2dObject.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (const CGtV4d by-value param passed on to ItalicText::PrepareCommonData; 1/size into data block +0x30).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
using namespace GtMathPs2;
struct UnkStruct_Flash_data {
    unsigned char pad_0[0xC];
    float field_C;
    CGtV2d field_10;
};
class CB3FlashText2dObject : public CGt2dObject {
public:
    void Prepare(const CGtV2d &p0, const CGtV2d &p1, float p2, const CGtV4d p3, const CGt2dFont *p4, const unsigned short *p5, const CGtV2d &p6);
};
extern "C" void _Render__20CB3FlashText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &, const void *);
extern "C" void PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(
    void *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const CGt2dFont *, const unsigned short *, void (*)(const CGt2dObject::CGt2dObjectSpace &, const void *));
// 0x00372010
void CB3FlashText2dObject::Prepare(const CGtV2d &p0, const CGtV2d &p1, float p2, const CGtV4d p3, const CGt2dFont *p4, const unsigned short *p5, const CGtV2d &p6)
{
    PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(
        this, p0, p1, p2, p3, p4, p5, (void (*)(const CGt2dObjectSpace &, const void *))_Render__20CB3FlashText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv);
    UnkStruct_Flash_data *d = (UnkStruct_Flash_data *)mauDataBlock;
    d->field_10 = CGtV2d(1.0f, 1.0f) / mObjectSpace.mSize;
    d->field_C = -1.0f;
}
