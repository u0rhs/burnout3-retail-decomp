// NONMATCHING: func_00134DF0 -- retail 221 / ours 219 instructions, 109 in changed runs
// v292: logic + block layout right (3-arm text select, StylisedText Prepare on a stack object, render via mpfRender), 109 changed: frame 0x150 vs 0x180 (retail keeps scale in memory: temp 0x160 -> named 0x178; pos 0x170 above anchor 0x168), render space copy through a3 pointer for mSize.x, draw-block store scheduling
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00134DF0 -- hand-written (v292). [L] a CB3OnePlayerStage helper: Render__17CB3OnePlayerStageFv (0x134A20, the
// previous function) calls it with the car/stage block D_0064D3B0; draws a countdown / start text with a stack
// CB3StylisedText2dObject (func_003D0710 = DNAT CB3StylisedText2dObject::Prepare, research/proto/new_names.csv low).
// Unnamed in every table, so a placeholder with C linkage; Area unknown, so _unclassified/. Every type is [G].

#include "b3/classes/UnkStruct_D_0051BA88.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/_unclassified/B3Strings.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_00134DF0_ui {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual int vfunc_C0();
};
struct UnkStruct_00134DF0 { unsigned char pad_0[0x1340]; float field_1340; };
struct UnkStruct_D_00665ED0 { CGt2dFont *pFont; unsigned char pad[0x100]; };
extern UnkStruct_D_00665ED0 D_00665ED0;
struct UnkStruct_D_00665EC0 { int field_0; int field_4; unsigned char pad[0x100]; };
extern UnkStruct_D_00665EC0 D_00665EC0;
struct UnkStruct_D_00522680 { float v; unsigned char pad[12]; };
extern UnkStruct_D_00522680 D_00522680;
struct UnkStruct_D_0051BA44 { CB3Strings strings; unsigned char pad[0x100]; };
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern "C" float ceilf(float);
extern "C" void PrintInt__10CGtUnicodeFPUsii(void *, int, int, int);
extern "C" void func_003D0710(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, CGtV4d colour, int a, int b,
                              int c, const CGt2dFont *font, float size, float maxWidth, const unsigned short *text,
                              bool flag);

// [G] inlined render of a 2d object with its size scaled (placeholder name)
static inline void func_00134DF0_inl1(CGt2dObject &o, const CGtV2d &scale)
{
    CGt2dObject::CGt2dObjectSpace space = o.mObjectSpace;
    space.mSize.marValues[0] *= scale.marValues[0];
    space.mSize.marValues[1] *= scale.marValues[1];
    o.mpfRender(space, o.mauDataBlock);
}
// 0x00134DF0
extern "C" void func_00134DF0(UnkStruct_00134DF0 *self)
{
    unsigned short buf[12] = {0};
    float size = 60.0f;
    const unsigned short *text = 0;
    CGtV4d col;
    if (((UnkStruct_00134DF0_ui *)D_0051BA88.field_0->field_1B4)->vfunc_C0() == 0 && D_00522680.v <= self->field_1340) {
        PrintInt__10CGtUnicodeFPUsii(buf, (int)ceilf(self->field_1340 - D_00522680.v), 0, 0);
        col = CGtV4d(255.0f, 230.0f, 125.0f, 255.0f);
        text = buf;
    } else if (((UnkStruct_00134DF0_ui *)D_0051BA88.field_0->field_1B4)->vfunc_C0() != 0
               && self->field_1340 - D_00522680.v <= 1.2f && !(self->field_1340 - D_00522680.v < 0.0f)) {
        text = D_0051BA44.strings.GetString(0x4BA);
        size = 50.0f;
        float a = (1.2f - (self->field_1340 - D_00522680.v)) / 0.95f;
        if (!(a <= 1.0f)) a = 1.0f;
        col = CGtV4d(255.0f, 230.0f, 125.0f, 255.0f * a);
    } else {
        col = CGtV4d(255.0f, 230.0f, 125.0f, 255.0f);
        float t = D_00522680.v - self->field_1340;
        if (t < 1.0f && !(t < 0.0f)) text = D_0051BA44.strings.GetString(0x4B8);
    }
    if (text != 0 && text[0] != 0) {
        col = col * (CGtV4d(0.5f, 0.5f, 0.5f, 1.0f) * (1.0f / 255.0f));
        CGtV2d pos(320.0f, 180.0f);
        CGtV2d anchor(0.5f, 0.0f);
        CGt2dObject obj;
        func_003D0710(&obj, pos, anchor, col, 1, 2, 0, D_00665ED0.pFont, size, 3.402823466e+38f, text, false);
        func_00134DF0_inl1(obj, CGtV2d((float)D_00665EC0.field_0 / 640.0f, (float)D_00665EC0.field_4 / 480.0f));
    }

}

