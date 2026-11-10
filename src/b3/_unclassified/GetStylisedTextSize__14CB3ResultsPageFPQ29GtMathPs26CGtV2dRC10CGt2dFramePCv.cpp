// Hand-written; the lifter refused it (lit4fix: .lit4 externs as literals).


#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
class CGt2dFont;
struct UnkStruct_003C18F0_obj { unsigned char pad_0[8]; CGtV2d field_8; unsigned char pad_10[0x38]; };
class CGt2dFrame {
public:
    CGtV4d field_0;
    unsigned char pad_10[0x10];
    float field_20;
    CGt2dFont *field_24;
    unsigned short *field_28;
    int field_2C;
    int field_30;
};
extern "C" void func_003D0710(UnkStruct_003C18F0_obj *obj, const CGtV2d &pos, const CGtV2d &anchor, CGtV4d colour,
                              int a, int b, int c, CGt2dFont *font, float size, float d, unsigned short *text, int e);

class CB3ResultsPage {
public:
    static CGtV2d GetStylisedTextSize(CGtV2d *, const CGt2dFrame &, const void *);
};

// 0x003C18F0
CGtV2d CB3ResultsPage::GetStylisedTextSize(CGtV2d *, const CGt2dFrame &fr, const void *)
{
    UnkStruct_003C18F0_obj obj;
    CGtV2d pos(0.0f, 0.0f);
    CGtV2d anc(0.0f, 0.0f);
    if (*fr.field_28 == 0) {
        CGtV2d r(0.0f, 0.0f);
        return r;
    }
    func_003D0710(&obj, pos, anc, fr.field_0, fr.field_30, fr.field_2C, 0, fr.field_24, fr.field_20, 3.4028235e+38f, fr.field_28, 0);
    return obj.field_8;
}
