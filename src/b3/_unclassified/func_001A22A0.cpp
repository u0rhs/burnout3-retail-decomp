// Hand-written; the lifter refused it (v303: hand-written; early return on null object, CGtV4d lq copy, obj locals before case-24 calls, static-init order scale/font/guard).

// func_001A22A0 -- CB3HUDScore message setup + per-frame update [L: its unit B3HUDScore.cpp, between Update and
// UpdateSmallMessage, its only caller (0x1A3628)]; nahelam's unknown row reads UpdateMessageGeneric (not evidence, [G]).
// Hand-written (lifter refused). Parameters [C] by the caller's setup: a1 = message, a2 = type, a3 = text, t0 = a
// bool (lbu of a stack byte), f12 = the frame time. D_004E2700 / D_0049A100 / D_0049A110: a function-static paragraph
// settings object and its guard (statically initialised data with the scale and font set once at run time) [L].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CGt2dFont;
class CGt2dFrame;

struct UnkStruct_001A22A0_obj { float field_0; };
struct UnkStruct_001A22A0_msg {
    UnkStruct_001A22A0_obj *field_0;
    CGt2dFrame *field_4;
    unsigned short field_8[0x40];
    float field_88;
    float field_8C;
    float field_90;
    unsigned char pad_94[0x4];
    short field_98;
};
struct UnkStruct_001A22A0_layer { unsigned char pad_0[0x70]; };
struct UnkStruct_001A22A0_cc { unsigned char pad_0[0xC]; float field_C; };
struct UnkStruct_001A22A0 {
    unsigned char pad_0[0x4];
    UnkStruct_001A22A0_layer *field_4;
    unsigned char pad_8[0x14];
    signed char field_1C;
    unsigned char pad_1D[0xAF];
    UnkStruct_001A22A0_cc *field_CC;
};
struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x10];
    CGtV4d field_10;
    unsigned char pad_20[0x10];
    CGtV4d field_30;
    unsigned char pad_40[0x20];
    CGtV4d field_60;
};
struct UnkStruct_D_00665ED0 { CGt2dFont *pFont; unsigned char pad[0xC]; };
struct UnkStruct_D_0049A100 { CGtV2d field_0; float field_8; float field_C; };
struct UnkStruct_D_0049A110 { CGt2dFont *field_0; short field_4; short field_6; unsigned char pad_8[0x8]; };
struct UnkStruct_D_0066C4A0 { unsigned short field_0[0x50]; };
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_0049A100 D_0049A100;
extern UnkStruct_D_0049A110 D_0049A110;
extern UnkStruct_D_0066C4A0 D_0066C4A0;
extern signed char D_004E2700;

extern "C" unsigned short *CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, const unsigned short *);
extern "C" int Length__10CGtUnicodeFPCUs(const unsigned short *);
extern "C" void SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(CGt2dFrame *);
extern "C" UnkStruct_001A22A0_obj *ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, CGt2dFrame *);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, UnkStruct_001A22A0_obj *);
extern "C" void UpdateMessageAnimation__11CB3HUDScoreFPQ211CB3HUDScore13CScoreMessage(UnkStruct_001A22A0 *, UnkStruct_001A22A0_msg *);
extern "C" void func_003824D0(UnkStruct_001A22A0_obj *obj, const CGtV2d &a, const CGtV2d &b, float c, CGtV4d d, CGtV4d e,
                              const unsigned short *text, int f, float g, float h);
extern "C" void func_003D0960(unsigned short *dst, int max, const unsigned short *src, int flag);
extern "C" void func_003D0710(UnkStruct_001A22A0_obj *obj, const CGtV2d &pos, const CGtV2d &anchor, CGtV4d colour, int a, int b,
                              int c, const CGt2dFont *font, float size, float maxWidth, const unsigned short *text,
                              bool flag);
extern "C" void func_002F9690(UnkStruct_001A22A0_obj *obj, const CGtV2d &pos, float width, const CGtV2d &anchor, CGtV4d colour,
                              const unsigned short *text, const UnkStruct_D_0049A100 *settings, int a, int type);
// 0x001A22A0
extern "C" void func_001A22A0(UnkStruct_001A22A0 *self, UnkStruct_001A22A0_msg *msg, int type, const unsigned short *text,
                              bool flag, float dt)
{
    if (text != 0) {
        void *scene = (char *)&self->field_4[self->field_1C] + 0x14;
        msg->field_88 = 5.0f + self->field_CC->field_C;
        CopyN__10CGtUnicodeFPUsiPCUs(msg->field_8, 0x40, text);
        msg->field_8C = 5.0f;
        if (msg->field_0 == 0)
            msg->field_0 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, msg->field_98, msg->field_4);
        SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(msg->field_4);
        switch (type) {
        case 1: {
            CGtV4d c = Interpolate(D_0066A4C0.field_60, D_0066A4C0.field_30, 0.25f);
            CGtV4d e;
            e = D_0066A4C0.field_30;
            func_003824D0(msg->field_0, CGtV2d(0.0f, 0.0f), CGtV2d(0.5f, 0.0f), 28.0f, c,
                          e, msg->field_8, 0x11, 1.25f, 580.0f);
            break;
        }
        case 9:
            {
                UnkStruct_001A22A0_obj *o = msg->field_0;
                func_003D0960(D_0066C4A0.field_0, 0x50, msg->field_8, 0);
                func_003D0710(o, CGtV2d(0.0f, 0.0f), CGtV2d(0.5f, 0.0f), D_0066A4C0.field_10, 4, 2, 0, D_00665ED0.pFont, 32.0f, 580.0f,
                              D_0066C4A0.field_0, false);
            }
            break;
        case 10:
        case 11:
        case 12:
            {
                UnkStruct_001A22A0_obj *o = msg->field_0;
                func_003D0960(D_0066C4A0.field_0, 0x50, msg->field_8, 0);
                func_003D0710(o, CGtV2d(0.0f, 0.0f), CGtV2d(0.5f, 0.0f), D_0066A4C0.field_10, 1, 2, 0, D_00665ED0.pFont, 32.0f, 580.0f,
                              D_0066C4A0.field_0, false);
            }
            break;
        case 0x18:
            if (Length__10CGtUnicodeFPCUs(text) > Length__10CGtUnicodeFPCUs(msg->field_8)) {
                if (D_004E2700 == 0) {
                    D_0049A100.field_0 = CGtV2d(1.5f, 1.5f);
                    D_0049A110.field_0 = D_00665ED0.pFont;
                    D_004E2700 = 1;
                }
                UnkStruct_001A22A0_obj *o = msg->field_0;
                func_002F9690(o, CGtV2d(0.0f, 0.0f), 560.0f, CGtV2d(0.5f, 0.0f), D_0066A4C0.field_30, text, &D_0049A100, 3, 2);
            } else {
                UnkStruct_001A22A0_obj *o = msg->field_0;
                func_003824D0(o, CGtV2d(0.0f, 0.0f), CGtV2d(0.5f, 0.0f), 30.0f, D_0066A4C0.field_30, D_0066A4C0.field_30,
                              msg->field_8, 9, 1.25f, 580.0f);
            }
            break;
        }
        msg->field_90 = msg->field_0->field_0;
    }
    if (msg->field_0 == 0) return;
    if (flag) {
        msg->field_8C = 0.3f;
    } else {
        msg->field_8C = msg->field_8C - dt;
        if (msg->field_8C < 0.0f) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject((char *)&self->field_4[self->field_1C] + 0x14, msg->field_98, msg->field_0);
            msg->field_0 = 0;
            return;
        }
    }
    UpdateMessageAnimation__11CB3HUDScoreFPQ211CB3HUDScore13CScoreMessage(self, msg);
}
