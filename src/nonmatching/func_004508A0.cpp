// NONMATCHING: func_004508A0 -- retail 348 / ours 345 instructions, 129 in changed runs
// a158: logic+layout right (345/348 instrs, 129 changed): per-set-bit row builder (title text via func_0033D4E0 + two number texts via PrepareCommonData, inline func_004508A0_inl1 x3, double null test s2, movz a3 arm). Left: frame 0x100 vs retail 0x130 -- retail keeps a distinct stack slot per expansion for the CGtV2d pos/anchor, CGtV4d colour copy and 1/size temps (3 text expansions + 2 title blocks), ours shares slots between the exclusive/sequential expansions (named locals in the inline did not help); same problem as func_0044FE00 (frame 0xF0 vs 0xD0). All sp offsets then shift.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_004508A0 -- hand-written (a158): table component, add one row per set bit of D_01ECDA10 (title text + two number texts).
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
using namespace GtMathPs2;
struct UnkStruct_D_00665ED0 { CGt2dFont *pFont; unsigned char pad[0x100]; };
extern UnkStruct_D_00665ED0 D_00665ED0;
struct UnkStruct_D_16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_16 D_01E903E0;
extern UnkStruct_D_16 D_0051BA44;
extern UnkStruct_D_16 D_01E90250;
extern CGtV4d D_01E903C0;
struct UnkStruct_D_byte { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_word { unsigned int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_byte D_01ECDAC5;
extern UnkStruct_D_byte D_01ECDAC7;
extern UnkStruct_D_word D_01ECDA10;
struct UnkStruct_D_004D3130 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004D3134 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004D3130 D_004D3130;
extern UnkStruct_D_004D3134 D_004D3134;
struct UnkStruct_004508A0_data { unsigned char pad_0[0xC]; float field_C; CGtV2d field_10; };
struct UnkStruct_004508A0_frame { CGtV2d field_0; };
struct UnkStruct_004508A0_row {
    CGt2dObject *field_0;
    unsigned char pad_4[4];
    UnkStruct_004508A0_frame *field_8;
    unsigned char pad_C[4];
    CGt2dObject *field_10;
    CGt2dObject *field_14;
    CGt2dObject *field_18;
    unsigned char pad_1C[8];
};
struct UnkStruct_004508A0 {
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[2];
    UnkStruct_004508A0_row field_C[8];
    unsigned char pad_12C[8];
    int field_134;
    int field_138;
};
extern "C" void func_0044D180(void *, int, int);
extern "C" const unsigned short *func_00450EF0(void *, int, int, int);
extern "C" int func_00450E10(void *, int);
extern "C" void func_00453680(void *, int, int, int);
extern "C" const unsigned short *func_00271A00(void *, int);
extern "C" CGt2dObject *ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void func_0033D4E0(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, const void *, const CGt2dFont *, const unsigned short *, const void *, int);
extern "C" void func_00453980(const CGt2dObject::CGt2dObjectSpace &, const void *);
extern "C" void PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(
    void *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const CGt2dFont *, const unsigned short *, void (*)(const CGt2dObject::CGt2dObjectSpace &, const void *));

static inline void func_004508A0_inl1(UnkStruct_004508A0 *self, UnkStruct_004508A0_row *row, CGt2dObject *&slot, const unsigned short *text, float off)
{
    if (text != 0) {
        CGt2dObject *o = row->field_0;
        float right = o->mObjectSpace.mTopLeftPos.marValues[0] + o->mObjectSpace.mSize.marValues[0];
        slot = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, row->field_8);
        CGt2dObject *obj = slot;
        PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(
            obj, CGtV2d(right + off, 0.0f), CGtV2d(1.0f, 0.5f), 36.0f, D_01E903C0, D_00665ED0.pFont, text, func_00453980);
        UnkStruct_004508A0_data *d = (UnkStruct_004508A0_data *)obj->mauDataBlock;
        d->field_10 = CGtV2d(D_004D3130.field_0, D_004D3134.field_0) / obj->mObjectSpace.mSize;
        d->field_C = 0.0f;
    }
}

// 0x004508A0
extern "C" void func_004508A0(UnkStruct_004508A0 *self)
{
    unsigned int s3;
    const unsigned short *s2;
    const unsigned short *s1;
    int s0;
    if (D_01ECDAC5.field_0 != 0 || D_01ECDAC7.field_0 != 0) {
        func_0044D180(self, self->field_138, 4);
        self->field_138 = self->field_138 + 1;
    }
    for (s3 = 1; s3 < 0x400; s3 <<= 1) {
        if ((D_01ECDA10.field_0 & s3) == 0) continue;
        s1 = 0;
        s2 = func_00450EF0(self, self->field_138, s3, 0);
        if (s2 == 0) continue;
        s0 = func_00450E10(self, s3);
        if (D_01ECDAC5.field_0 != 0) s1 = func_00450EF0(self, self->field_138, s3, 1);
        if (s1 != 0) {
            int idx = self->field_138;
            func_00453680(self, idx, 1, 4);
            const unsigned short *t0 = func_00271A00(&D_0051BA44, s0);
            UnkStruct_004508A0_row *row = &self->field_C[idx];
            CGt2dObject *bg = row->field_0;
            float z = 0.0f;
            float px = 30.0f + (z + bg->mObjectSpace.mTopLeftPos.marValues[0] + z * bg->mObjectSpace.mSize.marValues[0]);
            row->field_10 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, row->field_8);
            func_0033D4E0(row->field_10, CGtV2d(px, 0.0f), CGtV2d(0.0f, 0.5f), 22.0f, &D_01E90250, D_00665ED0.pFont, t0, &D_004D3130, 2);
            func_004508A0_inl1(self, row, row->field_14, s1, -30.0f);
            if (s2 != 0) func_004508A0_inl1(self, row, row->field_18, s2, -190.0f);
        } else {
            int idx = self->field_138;
            func_00453680(self, idx, 1, (D_01ECDAC7.field_0 == 0) ? 1 : 4);
            const unsigned short *t0 = func_00271A00(&D_0051BA44, s0);
            UnkStruct_004508A0_row *row = &self->field_C[idx];
            CGt2dObject *bg = row->field_0;
            float z = 0.0f;
            float px = 30.0f + (z + bg->mObjectSpace.mTopLeftPos.marValues[0] + z * bg->mObjectSpace.mSize.marValues[0]);
            row->field_10 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, row->field_8);
            func_0033D4E0(row->field_10, CGtV2d(px, 0.0f), CGtV2d(0.0f, 0.5f), 22.0f, &D_01E90250, D_00665ED0.pFont, t0, &D_004D3130, 2);
            func_004508A0_inl1(self, row, row->field_14, s2, -30.0f);
        }
        self->field_138 = self->field_138 + 1;
    }
}
