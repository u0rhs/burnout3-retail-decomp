// NONMATCHING: func_0044FE00 -- retail 293 / ours 277 instructions, 133 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: a158: logic complete (277/293 instrs, 133 changed). Family of func_0044D180/func_00453680/func_004506E0 (table rows self+n*0x24+0xC: bg obj +0, frame +8, texts +0x10/+0x14/+0x18). Left: retail frame 0xF0 vs ours 0xD0 (two extra 16-byte slots, probably CGtV4d colour/anchor temps); adda.s/madd.s pairs
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_0044FE00 -- hand-written (a158): table component, add a row (title text + two number texts), then re-centre the frames vertically.
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
using namespace GtMathPs2;
struct UnkStruct_D_00665ED0 { CGt2dFont *pFont; unsigned char pad[0x100]; };
extern UnkStruct_D_00665ED0 D_00665ED0;
struct UnkStruct_D_16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_16 D_01E903E0;
extern UnkStruct_D_16 D_01E90438;
extern UnkStruct_D_16 D_0051BA44;
extern UnkStruct_D_16 D_01E90350;
extern UnkStruct_D_16 D_0051AEC0;
extern CGtV4d D_01E903C0;
struct UnkStruct_D_004D3130 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004D3134 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004D3130 D_004D3130;
extern UnkStruct_D_004D3134 D_004D3134;
struct UnkStruct_0044FE00_data { unsigned char pad_0[0xC]; float field_C; CGtV2d field_10; };
struct UnkStruct_0044FE00_frame { CGtV2d field_0; };
struct UnkStruct_0044FE00_row {
    CGt2dObject *field_0;
    unsigned char pad_4[4];
    UnkStruct_0044FE00_frame *field_8;
    unsigned char pad_C[4];
    CGt2dObject *field_10;
    CGt2dObject *field_14;
    CGt2dObject *field_18;
    unsigned char pad_1C[8];
};
struct UnkStruct_0044FE00 {
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[2];
    UnkStruct_0044FE00_row field_C[8];
    unsigned char pad_12C[8];
    int field_134;
    int field_138;
};
extern "C" void func_00453560(void *);
extern "C" void func_0044D180(void *, int, int);
extern "C" void func_00453680(void *, int, int, int);
extern "C" void *AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" const unsigned short *func_00271A00(void *, int);
extern "C" void func_003D0960(void *, int, const unsigned short *, int);
extern "C" CGt2dObject *ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void func_003D0710(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, const void *colour,
                              int a, int b, int c, const CGt2dFont *font, float d, float e, void *str, int f);
extern "C" const unsigned short *func_0013C930(void *, int);
extern "C" void PrintInt__10CGtUnicodeFPUsii(void *, const unsigned short *, int, int);
extern "C" void func_00453980(const CGt2dObject::CGt2dObjectSpace &, const void *);
extern "C" void PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(
    void *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const CGt2dFont *, const unsigned short *, void (*)(const CGt2dObject::CGt2dObjectSpace &, const void *));

// 0x0044FE00
extern "C" int func_0044FE00(UnkStruct_0044FE00 *self)
{
    func_00453560(self);
    self->field_134 = 4;
    int n = self->field_138;
    func_0044D180(self, self->field_138, 4);
    UnkStruct_0044FE00_row *r0 = &self->field_C[n];
    CGt2dObject *t0 = r0->field_14;
    CGt2dObject *bg = r0->field_0;
    CGt2dObject *t1 = r0->field_10;
    self->field_138 = self->field_138 + 1;
    n = self->field_138;
    float cx = (0.0f + t0->mObjectSpace.mTopLeftPos.marValues[0] + 0.5f * t0->mObjectSpace.mSize.marValues[0])
             - (0.0f + bg->mObjectSpace.mTopLeftPos.marValues[0] + 1.0f * bg->mObjectSpace.mSize.marValues[0]);
    float cy = (0.0f + t1->mObjectSpace.mTopLeftPos.marValues[0] + 0.5f * t1->mObjectSpace.mSize.marValues[0])
             - (0.0f + bg->mObjectSpace.mTopLeftPos.marValues[0] + 1.0f * bg->mObjectSpace.mSize.marValues[0]);
    func_00453680(self, n, 4, 4);
    UnkStruct_0044FE00_row *r = &self->field_C[n];
    int layer = self->field_8 + 2;
    void *str = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x40);
    func_003D0960(str, 0x40, func_00271A00(&D_0051BA44, 0x9E2), 0);
    CGt2dObject *ro = r->field_0;
    float px = 0.0f + (30.0f + ro->mObjectSpace.mTopLeftPos.marValues[0]) + 0.0f * (ro->mObjectSpace.mSize.marValues[0] - 60.0f);
    r->field_10 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, layer, r->field_8);
    func_003D0710(r->field_10, CGtV2d(px, 0.0f), CGtV2d(0.0f, 0.5f), &D_01E90350, 1, 1, 0, D_00665ED0.pFont, 36.0f, 3.4028235e+38f, str, 0);
    void *s = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x10);
    PrintInt__10CGtUnicodeFPUsii(s, func_0013C930(&D_0051AEC0, 1), 1, 0);
    if (s != 0) {
        CGt2dObject *o = r->field_0;
        float right = o->mObjectSpace.mTopLeftPos.marValues[0] + o->mObjectSpace.mSize.marValues[0];
        r->field_14 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, r->field_8);
        CGt2dObject *obj = r->field_14;
        PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(
            obj, CGtV2d(right + cx, 0.0f), CGtV2d(0.5f, 0.5f), 36.0f, D_01E903C0, D_00665ED0.pFont, (const unsigned short *)s, func_00453980);
        UnkStruct_0044FE00_data *d = (UnkStruct_0044FE00_data *)obj->mauDataBlock;
        d->field_10 = CGtV2d(D_004D3130.field_0, D_004D3134.field_0) / obj->mObjectSpace.mSize;
        d->field_C = 0.0f;
    }
    void *s2 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x10);
    PrintInt__10CGtUnicodeFPUsii(s2, func_0013C930(&D_0051AEC0, 0), 1, 0);
    if (s2 != 0) {
        CGt2dObject *o = r->field_0;
        float right = o->mObjectSpace.mTopLeftPos.marValues[0] + o->mObjectSpace.mSize.marValues[0];
        r->field_18 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, r->field_8);
        CGt2dObject *obj = r->field_18;
        PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(
            obj, CGtV2d(right + cy, 0.0f), CGtV2d(0.5f, 0.5f), 36.0f, D_01E903C0, D_00665ED0.pFont, (const unsigned short *)s2, func_00453980);
        UnkStruct_0044FE00_data *d = (UnkStruct_0044FE00_data *)obj->mauDataBlock;
        d->field_10 = CGtV2d(D_004D3130.field_0, D_004D3134.field_0) / obj->mObjectSpace.mSize;
        d->field_C = 0.0f;
    }
    self->field_138 = self->field_138 + 1;
    int cnt = self->field_138;
    if (cnt != 0) {
        float y = 0.0f + 180.0f - 0.5f * (34.0f * (float)(cnt - 1));
        int i;
        for (i = 0; i < cnt; i++) {
            self->field_C[i].field_8->field_0 = CGtV2d(640.0f, y);
            y += 34.0f;
        }
    }
    return 1;
}
