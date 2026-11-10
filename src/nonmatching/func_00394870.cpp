// NONMATCHING: func_00394870 -- retail 239 / ours 239 instructions, 23 in changed runs
// hdr12 reroute: N224 Interpolate(CGtV4d) + call-site float t
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_00394870 -- retail 239 / ours 239 instructions, 43 in changed runs
// v294: [L] DNAT CB3HUDLapTimer::Prepare; logic + frame exact (N140 pad under the text buffer, named CGtV4d c declared before buf); 43 left = scheduling around the Interpolate(CGtV4d) stand-in (retail: 0.25 lui + pos floats before the asm, result sq right after; same N94 family as func_003356A0) and f0-f5 numbering of the pos constants
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_00394870 -- [L] DNAT: CB3HUDLapTimer::Prepare(int,EHUDAlign,int,bool,bool) (research/proto/new_names.csv, exact/verified),
// B3HUDLapTimer.cpp. Placeholder with C linkage (the asm label); written on CB3HUDTakedowns::Prepare's model
// (B3HUDTakedowns_003A25F0.cpp). Every type [G] unless noted.

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

enum EHUDAlign {};
class CGt2dFrame;
class CGtTexture;

struct UnkStruct_00394870_e0 {
    unsigned char pad_0[0x27D0];
};
struct UnkStruct_D_00522660 {
    UnkStruct_00394870_e0 field_0[1];  // [G] element count unknown
};
struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x10];
    CGtV4d field_10;
    unsigned char pad_20[0x10];
    CGtV4d field_30;
    unsigned char pad_40[0x20];
    CGtV4d field_60;
};
// [G] the race-car record field_34 points into (D_00522660 row + 0x12BE10)
struct UnkStruct_00394870_rec {
    unsigned char pad_0[0x2C8];
    float field_2C8;
};
struct UnkStruct_00394870_obj {
    CGtV2d field_0;   // [L] CGt2dObject mTopLeftPos
    CGtV2d field_8;   // [L] CGt2dObject mSize
};

class CB3HUDLapTimer {
public:
    unsigned char pad_0[0x4];
    unsigned char *field_4;
    void *field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    UnkStruct_00394870_obj *field_20;
    UnkStruct_00394870_obj *field_24;
    UnkStruct_00394870_obj *field_28;
    UnkStruct_00394870_obj *field_2C;
    UnkStruct_00394870_obj *field_30;
    UnkStruct_00394870_rec *field_34;
    float field_38;
    unsigned char pad_3C[0x4];
    unsigned short field_40[0x40];   // [L] the time text (ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi target, passed to func_003824D0)
    CGtTexture *field_C0[3];
    bool field_CC;
    bool field_CD;
    unsigned char pad_CE[2];
    float field_D0;
};

extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern "C" CGtTexture *mapIconTextures__15CB3HUDComponent[16];   // CB3HUDComponent::mapIconTextures (symbol_addrs_b3names.txt)
extern "C" const int D_004C98B0[3];
extern "C" const char D_004C98C0[];

extern "C" void Prepare__15CB3HUDComponentFiiii9EHUDAligni(void *, int, int, int, int, EHUDAlign, int);
extern "C" UnkStruct_00394870_obj *ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, unsigned int);
extern "C" float func_00155280(float f0);
extern "C" int snprintf(char *, int, const char *, ...);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(const char *, unsigned short *, int);
extern "C" void func_003824D0(void *, const CGtV2d &, const CGtV2d &, float, CGtV4d, CGtV4d, const unsigned short *, int, float, float);
extern "C" void func_00394280(CB3HUDLapTimer *self);   // [L] DNAT: CB3HUDLapTimer::PrepareMedalObjects() (low)

// [L] N185: stands in for GtMathPs2::Interpolate(CGtV4d, CGtV4d, float) (header N94 body: `"+j"` a on a compiler-chosen
// register, moves folded); retail has a and the result on $vf1, t on $vf2, b's and the result's moves kept.


// [G] N140 frame pad (retail's frame has one more 16-byte slot below the text buffer)
struct UnkStruct_00394870_pad { int x[4]; UnkStruct_00394870_pad() {} ~UnkStruct_00394870_pad() {} };

// 0x00394870
extern "C" int func_00394870(CB3HUDLapTimer *self, int p0, EHUDAlign p1, int p2, bool p3, bool p4)
{
    Prepare__15CB3HUDComponentFiiii9EHUDAligni(self, 2, 5, 0, p0, p1, p2);
    UnkStruct_D_0066A4C0 * const mgr = &D_0066A4C0;
    void *scene = self->field_4 + self->field_1C * 0x70 + 0x14;
    int layer = self->field_10;
    int layer1 = layer + 1;
    self->field_34 = (UnkStruct_00394870_rec *)((char *)&D_00522660.field_0[p0] + 0x12BE10);
    self->field_CC = p3;
    self->field_CD = p4;
    self->field_D0 = 14.0f;
    self->field_20 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, self->field_8);
    self->field_24 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, self->field_8);
    if (self->field_CC) {
        self->field_28 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer1, self->field_8);
        self->field_2C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer1, self->field_8);
        self->field_30 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer1, self->field_8);
        Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(self->field_30, CGtV2d(-30.0f, self->field_D0), CGtV2d(0.0f, 0.5f), CGtV2d(200.0f, 27.0f), mgr->field_10, 2);
        self->field_D0 += 31.0f;
    } else {
        self->field_28 = 0;
        self->field_2C = 0;
        self->field_30 = 0;
    }
    for (int i = 0; i < 3; i++) {
        self->field_C0[i] = mapIconTextures__15CB3HUDComponent[D_004C98B0[i]];
    }
    Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(self->field_24, CGtV2d(-30.0f, self->field_D0), CGtV2d(0.0f, 0.5f), CGtV2d(200.0f, 27.0f), mgr->field_10, 2);
    float t = func_00155280(self->field_34->field_2C8);
    self->field_38 = t;
    UnkStruct_D_0066A4C0 * const col = &D_0066A4C0;
    int m, s, h;
    if (t == 3.402823466e+38f) {
        m = 0;
        s = 0;
        h = 0;
    } else {
        m = (int)(0.016666668f * t);
        float sec = t - 60.0f * (float)(int)(t / 60.0f);
        s = (int)sec;
        h = (int)(100.0f * (sec - (float)s)) % 100;
    }
    CGtV4d c;
    char buf[0x20];
    snprintf(buf, 31, D_004C98C0, m, s, h);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, self->field_40, 0x20);
    UnkStruct_00394870_obj *o = self->field_24;
    float x = (o->field_0.marValues[0] + o->field_8.marValues[0]) - 112.0f;
    float y = (36.0f + o->field_0.marValues[1]) - 22.0f;
    float k_t0 = 0.25f;
    c = GtMathPs2::Interpolate(col->field_60, col->field_30, k_t0);
    func_003824D0(self->field_20, CGtV2d(x, y),
                  CGtV2d(0.0f, 0.5f), 30.0f, c, col->field_30, self->field_40, 0x61, 1.25f, 3.402823466e+38f);
    if (self->field_CC) {
        func_00394280(self);
    }
    return 1;
}
