// NONMATCHING: func_003A3250 -- retail 399 / ours 400 instructions, 273 in changed runs
// draftAL C-first: [G] HUD pop-up counter Update(dt) (a virtual, vtable 0x4DF548): value from func_003CC910; crash-time teardown (4 DestructObject), new value: number label (PrintInt__10CGtUnicodeFPUsii + func_003824D0) or string 0x8BA + image (CGt2dObjectImage::Prepare), then pop-in scale 1 + 6.67 t or the 0.35 s pulse on the clock D_004F50A0; 400/399, calls identical; x *= -0.5 for retail's unfused mul/add
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; the crash/teardown condition (n == 0, +0x210 set, +0x4586 clear), both label calls' 10 arguments (positions (5 + right edge, -10), anchor (0, 0.6), heights 45/27, Interpolate 0.25/0.75 colours, flags 0x21/1, 1.25, FLT_MAX), the image's 9, and the timer logic (0.35/0.175/0.4, 6.6666665) traced

// func_003A3250 -- draftAL (C-first draft). 0x3A3250, 0x63C. Unnamed in every table: placeholder with C linkage. [C] a virtual
// (its address sits in the vtable data at 0x4DF548); [G] a HUD component's Update(float dt).
// Written from the retail asm; func_003824D0 / CGt2dObjectImage::Prepare declarations as the proven B3HeadingComponent and
// B3OnlineLobbyPage units.
// What it does [L]: a pop-up counter next to a HUD element. Its value comes from func_003CC910(&D_0064CE40, player):
//  - value 0 while the player car is crashing (+0x210, not +0x4586): the pop-up's four objects are destroyed;
//  - a new value: timer 0.15; a positive value is printed (PrintInt__10CGtUnicodeFPUsii) as the label (func_003824D0, 45 high) right
//    of object +0x20, a non-positive one shows string 0x8BA (27 high) right of object +0x28 and an image (45 x 25,
//    texture +0x34) after it; the label's size and centre are kept (+0x50 / +0x58);
//  - then each frame: a positive value pops in (scale 1 + 6.67 t while the timer runs down by dt), a zero value pulses
//    the +0x8 object for 0.35 s against the clock D_004F50A0 (rise to 0.175 then fall, x0.4) and restarts the clock.
// Types and field meanings [G].
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_003A3250_car { unsigned char pad_0[0x19AC]; signed char field_19AC; };
struct UnkStruct_003A3250_rc { unsigned char pad_0[0xC8]; UnkStruct_003A3250_car * field_C8; };
struct UnkStruct_003A3250_phys { unsigned char pad_0[0x210]; unsigned char field_210; unsigned char pad_211[0x4375]; unsigned char field_4586; };
struct UnkStruct_003A3250_pc { UnkStruct_003A3250_phys * field_0; unsigned char pad_4[0x2C]; };   // per player, 0x30
extern UnkStruct_003A3250_pc D_0055EFEC[];
class CGt2dScene { public: void DestructObject(int, CGt2dObject *); unsigned char pad_0[0x70]; };
struct UnkStruct_003A3250_sc { unsigned char pad_0[0x14]; CGt2dScene field_14; };   // 0x70 per entry [G]
struct UnkStruct_003A3250 {
    unsigned char pad_0[0x4];
    UnkStruct_003A3250_sc * field_4;        // scenes
    CGt2dObject * field_8;                  // the element the counter belongs to
    unsigned char pad_C[0x4];
    short field_10;                         // scene layer
    unsigned char pad_12[0xA];
    signed char field_1C;                   // scene index
    unsigned char pad_1D[0x3];
    CGt2dObject * field_20;
    CGt2dObject * field_24;                 // the label
    CGt2dObject * field_28;
    CGt2dObject * field_2C;
    UnkStruct_003A3250_rc * field_30;
    CGtTexture * field_34;
    unsigned char pad_38[0x4];
    unsigned short field_3C[4];             // the label text
    int field_44;                           // the shown value
    unsigned char pad_48[0x4];
    float field_4C;                         // timer
    CGtV2d field_50;                        // label size
    CGtV2d field_58;                        // label centre
};
struct UnkStruct_003A3250_m { unsigned char pad_0[0x30]; CGtV4d field_30; unsigned char pad_40[0x20]; CGtV4d field_60; };
extern UnkStruct_003A3250_m D_0066A4C0;
struct UnkStruct_003A3250_D { unsigned char pad_0[0x10]; };
extern UnkStruct_003A3250_D D_0064CE40;
extern UnkStruct_003A3250_D D_0051BA44;
extern const CGtV4d D_004C9DB0;
extern float D_004F50A0[];                  // [G] a clock (lui/%lo)
extern "C" int func_003CC910(void *, int);
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" unsigned short * PrintInt__10CGtUnicodeFPUsii(unsigned short *, int, int, int);
extern "C" void func_003824D0(CGt2dObject * obj, const CGtV2d & a, const CGtV2d & b, float c, CGtV4d d, CGtV4d e,
                              const unsigned short * text, int f, float g, float h);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject * self, const CGtV2d & pos, const CGtV2d & anchor, const CGtV2d & size, CGtV4d colour,
    CGtTexture * texture, const CGtV2d & uv0, const CGtV2d & uv1, unsigned int n);

// 0x003A3250
extern "C" void func_003A3250(UnkStruct_003A3250 * self, float dt)
{
    int lnPlayer = self->field_30->field_C8->field_19AC;
    UnkStruct_003A3250_phys * lpPhysics = D_0055EFEC[lnPlayer].field_0;
    int n = func_003CC910(&D_0064CE40, lnPlayer);
    if (n == 0 && lpPhysics->field_4586 == 0 && lpPhysics->field_210 != 0) {
        if (self->field_20 != 0) {
            CGt2dScene * s = &self->field_4[self->field_1C].field_14;
            s->DestructObject(self->field_10, self->field_20);
            s->DestructObject(self->field_10, self->field_2C);
            s->DestructObject(self->field_10 + 1, self->field_24);
            s->DestructObject(self->field_10 + 1, self->field_28);
            self->field_20 = 0;
            self->field_2C = 0;
            self->field_24 = 0;
            self->field_28 = 0;
        }
        return;
    }
    if (self->field_44 != n) {
        self->field_4C = 0.15f;
        UnkStruct_003A3250_m * m = &D_0066A4C0;
        if (n > 0) {
            float x = self->field_20->mObjectSpace.mTopLeftPos.X() + self->field_20->mObjectSpace.mSize.X();
            PrintInt__10CGtUnicodeFPUsii(self->field_3C, func_003CC910(&D_0064CE40, self->field_30->field_C8->field_19AC), 1, 0);
            func_003824D0(self->field_24, CGtV2d(5.0f + x, -10.0f), CGtV2d(0.0f, 0.6f), 45.0f, Interpolate(m->field_60, m->field_30, 0.25f),
                          m->field_30, self->field_3C, 0x21, 1.25f, 3.4028235e+38f);
            self->field_50 = self->field_24->mObjectSpace.mSize;
            self->field_58 = self->field_24->mObjectSpace.mTopLeftPos + self->field_50 * 0.5f;
        } else {
            float x = self->field_28->mObjectSpace.mTopLeftPos.X() + self->field_28->mObjectSpace.mSize.X();
            CGtV4d c0(m->field_60.mData);
            CGtV4d c1 = Interpolate(m->field_60, m->field_30, 0.75f);
            const unsigned short * text = func_00271A00(&D_0051BA44, 0x8BA);
            func_003824D0(self->field_20, CGtV2d(5.0f + x, -10.0f), CGtV2d(0.0f, 0.6f), 27.0f, c0, c1, text, 1, 1.25f, 3.4028235e+38f);
            Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
                self->field_24, CGtV2d(5.0f + (self->field_20->mObjectSpace.mTopLeftPos.X() + self->field_20->mObjectSpace.mSize.X()), -10.0f),
                CGtV2d(0.0f, 0.6f), CGtV2d(45.0f, 25.0f), D_004C9DB0, self->field_34, CGtV2d(0.0f, 0.0f), CGtV2d(1.0f, 1.0f), 0);
            self->field_50 = self->field_24->mObjectSpace.mSize;
            self->field_58 = self->field_24->mObjectSpace.mTopLeftPos + self->field_50 * 0.5f;
            self->field_50 = self->field_8->mObjectSpace.mSize;
            self->field_58 = self->field_8->mObjectSpace.mTopLeftPos;
            self->field_4C = D_004F50A0[0];
        }
        self->field_44 = n;
    }
    float s = 1.0f;
    if (self->field_44 == 0) {
        float e = D_004F50A0[0] - self->field_4C;
        if (!(e <= 0.35f)) {
            self->field_4C = D_004F50A0[0];
            return;
        }
        if (e <= 0.175f)
            s = 0.4f * e;
        else
            s = (0.175f - (e - 0.175f)) * 0.4f;
        CGtV2d d = self->field_50 * s;
        self->field_8->mObjectSpace.mSize = self->field_50 + d;
        CGtV2d o(330.0f * d.X(), d.Y());
        o *= -0.5f;
        self->field_8->mObjectSpace.mTopLeftPos = self->field_58 + o;
        return;
    }
    if (!(self->field_4C <= 0.0f)) {
        float t = self->field_4C;
        self->field_4C = t - dt;
        s = 1.0f + 6.6666665f * t;
    }
    CGtV2d sz = self->field_50 * s;
    self->field_24->mObjectSpace.mSize = sz;
    self->field_24->mObjectSpace.mTopLeftPos = self->field_58 - sz * 0.5f;
}
