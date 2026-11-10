// NONMATCHING: func_003D56D0 -- retail 383 / ours 383 instructions, 95 in changed runs
// fix2 (2026-11-01): taskB: the icon object's fields are written through a reload of field_10 as retail 0x3D59F4 (audit store-base FP; same values) | Before: a81: 382 vs 383 instrs, ~100 changed. Logic/structure matches (ClearMessage inline, rec table, anchor/scale/dx/width, V2 temp chains, Prepare calls, callback switch) but the stack-slot layout of the V2 operator temporaries / CGtV4d arg copies differs (retail pairs temp+copy per call: B0/C0, D0/E0; named tmp at 0x178), and saved-reg naming (rec->s2, tex->s3 in retail; text/type regs reused). Not a quick fix.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// func_003D56D0 -- CB3HUDPrimaryMessageHandler::ShowMessage(const CGtV2d&, CGt2dFrame*, const unsigned short*, ...)
// [L] DNAT: CB3HUDPrimaryMessageHandler::ShowMessage(const GtMathPs2::CGtV2d&,CGt2dFrame*,const unsigned short*,CB3HUDPrimaryMessageHandler... (research/proto/new_names.csv, medium)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3HUDPrimaryMessageHandler;

struct UnkStruct_Obj {
    CGtV2d field_0;
    CGtV2d field_8;
    unsigned char pad_10[0x10];
    void * field_20;
    int field_24;
    int field_28;
    unsigned char field_2C;
};

struct UnkStruct_Rec {
    int field_0;
    int field_4;
    int field_8;
    unsigned char field_C;
    unsigned char pad_D[3];
};

class CB3HUDPrimaryMessageHandler {
public:
    void * field_0;
    int field_4;
    int field_8;
    UnkStruct_Obj * field_C;
    UnkStruct_Obj * field_10;
    UnkStruct_Obj * field_14;
    CGtV2d field_18;
    CGtV2d field_20;
    CGtV2d field_28;
    CGtV2d field_30;
    int field_38;
    unsigned char field_3C[0x110];
    int field_14C;
    float field_150;
    float field_154;
    int (* field_158)(CB3HUDPrimaryMessageHandler *);
    int (* field_15C)(CB3HUDPrimaryMessageHandler *);
    int (* field_160)(CB3HUDPrimaryMessageHandler *);
};

struct UnkStruct_D_00665ED0 { void * pFont; unsigned char pad[0x100]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_F { float field_0; };

extern UnkStruct_Rec D_004CA6F0[];
extern void * mapIconTextures__15CB3HUDComponent[];
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_I D_0066A540;
extern UnkStruct_B D_00665ECF;
extern UnkStruct_F D_004E096C;

extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void func_003D0960(void *, int, const unsigned short *, int);
extern "C" void func_003D0710(void * obj, const CGtV2d & pos, const CGtV2d & anchor, CGtV4d colour, int a, int b, int c, void * font, float size, float d, void * str, int e);
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void * obj, const CGtV2d & pos, const CGtV2d & size, CGtV4d colour, void * cb, unsigned int a, unsigned int b);
extern "C" void _RenderStars__23CB3PositiveIcon2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv(void *, const void *);
extern "C" void func_003D62A0(void *, const void *);
extern "C" int UpdateSpinAnimationIn__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler(CB3HUDPrimaryMessageHandler *);
extern "C" int func_003D4FC0(CB3HUDPrimaryMessageHandler *);
extern "C" int UpdateSpinAnimationOut2__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler(CB3HUDPrimaryMessageHandler *);
extern "C" int UpdateSpinAnimationOut__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler(CB3HUDPrimaryMessageHandler *);
extern "C" int UpdateWibbleAnimationIn__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler(CB3HUDPrimaryMessageHandler *);
extern "C" int func_003D47B0(CB3HUDPrimaryMessageHandler *);
extern "C" int UpdateWibbleAnimationOut__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler(CB3HUDPrimaryMessageHandler *);

// 0x003D56D0
extern "C" void func_003D56D0(CB3HUDPrimaryMessageHandler * self, const CGtV2d & pos, void * frame, const unsigned short * text, int type, int p5, int p6, int p7, bool b9, bool b10)
{
    CGtV4d colour = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
    CGtV2d anchor;
    CGtV2d scale;
    float dx;
    float width;
    if (self->field_C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(self->field_0, self->field_4, self->field_C);
        self->field_C = 0;
    }
    if (self->field_14 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(self->field_0, self->field_4, self->field_14);
        self->field_14 = 0;
    }
    if (self->field_10 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(self->field_0, self->field_8, self->field_10);
        self->field_10 = 0;
    }
    self->field_14C = 3;
    func_003D0960(&self->field_3C, 0x80, text, 1);
    void * tex;
    UnkStruct_Rec * rec = &D_004CA6F0[type];
    tex = 0;
    if (rec->field_8 != 0x11) {
        tex = mapIconTextures__15CB3HUDComponent[rec->field_8];
    }
    if (b10 != false) {
        anchor.Set(0.0f, 0.0f);
        width = 272.0f;
    } else if ((rec->field_C & 1) != 0 && p7 == 0) {
        anchor.Set(0.0f, 0.0f);
        width = 272.0f;
    } else {
        anchor.Set(0.5f, 0.0f);
        if (D_0066A540.field_0 == 2 && D_00665ECF.field_0 != 0) {
            width = 256.0f;
        } else {
            width = 512.0f;
        }
    }
    switch (rec->field_C & 6) {
    case 0:
        scale.Set(-0.5f, 0.0f);
        dx = -18.0f;
        break;
    case 2:
        scale.Set(0.5f, 0.0f);
        dx = 18.0f;
        break;
    case 4:
        scale.Set(D_004E096C.field_0, 0.25f);
        dx = 0.0f;
        break;
    case 6:
        scale.Set(-0.5f, 0.0f);
        dx = 18.0f;
        break;
    }
    self->field_C = (UnkStruct_Obj *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(self->field_0, self->field_4, frame);
    func_003D0710(self->field_C, pos, anchor, colour, rec->field_0, 2, rec->field_4, D_00665ED0.pFont, 44.0f, width, &self->field_3C, 0);
    self->field_20 = self->field_C->field_8;
    self->field_18 = self->field_C->field_0 + self->field_20 * 0.5f;
    if (tex != 0) {
        CGtV2d tmp = self->field_18 + self->field_20 * scale;
        CGtV2d isize;
        float px = dx + tmp.X();
        self->field_10 = (UnkStruct_Obj *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(self->field_0, self->field_8, frame);
        UnkStruct_Obj * o2 = self->field_10;   // taskB: retail re-reads the field (0x3D59F4 lw a0, 0x10(s1))
        isize.Set(72.0f, 72.0f);
        o2->field_20 = tex;
        o2->field_24 = 0;
        o2->field_28 = p6;
        o2->field_2C = b9;
        void * cb;
        if (p6 > 0) {
            cb = (void *)_RenderStars__23CB3PositiveIcon2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv;
        } else {
            cb = (void *)func_003D62A0;
        }
        Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(self->field_10, CGtV2d(px, tmp.Y()) - isize * 0.5f, isize, CGtV4d(1.0f, 1.0f, 1.0f, 1.0f), cb, 0x40, 0x10);
        self->field_30 = self->field_10->field_8;
        self->field_28 = self->field_10->field_0 + self->field_30 * 0.5f;
    }
    switch (rec->field_4) {
    case 1:
        self->field_158 = UpdateSpinAnimationIn__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler;
        self->field_15C = func_003D4FC0;
        if (rec->field_8 == 2) {
            self->field_160 = UpdateSpinAnimationOut2__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler;
        } else {
            self->field_160 = UpdateSpinAnimationOut__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler;
        }
        if ((rec->field_C & 8) != 0) {
            self->field_154 = 3.5f;
        } else {
            self->field_154 = 1.625f;
        }
        self->field_14C = 0;
        break;
    case 2:
        self->field_158 = UpdateWibbleAnimationIn__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler;
        self->field_15C = func_003D47B0;
        self->field_160 = UpdateWibbleAnimationOut__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler;
        if ((rec->field_C & 8) != 0) {
            self->field_154 = 3.0f;
        } else {
            self->field_154 = 1.75f;
        }
        self->field_14C = 0;
        break;
    case 0:
        self->field_158 = 0;
        self->field_15C = 0;
        self->field_160 = 0;
        self->field_14C = 3;
        break;
    }
    self->field_150 = 0;
    self->field_38 = p5;
}
