// NONMATCHING: func_003D6660 -- retail 274 / ours 274 instructions, 126 in changed runs
// L263: hand-written from asm (lifter refused), [L] DNAT CB3HUDImpactTime::Update(float); control flow/calls/args believed right, 274/274; left: frame 0x110 vs 0x120 (one 16-byte slot missing; retail keeps 1.0 in f20 across calls), s0-s3 rotation (layer/scene/frame/near), 0.0f compare operand order; most of the 126 is the frame shift
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003D6660 -- [L] DNAT: CB3HUDImpactTime::Update(float) (research/proto/new_names.csv, exact/verified).
// Hand-written from the retail asm (lifter refused); shapes from B3HUDEscapeDistance_003D8BC0 / B3HUDImpactTime_003D6AB0.
// Field names are placeholders and every type is [G] (instruction widths).
#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

enum UnkEnum_003D6660 { UnkEnum_003D6660_0, UnkEnum_003D6660_1 };  // [G] 0/1 diamond (a66)
class CGt2dFrame;
class CGt2dObject;
class CGtTexture;
struct UnkStruct_003D6660_e1;
struct UnkStruct_003D6660_o;
struct UnkStruct_003D6660_p;

struct UnkStruct_003D6660_e1 {
    unsigned char pad_0[0x70];
};

struct UnkStruct_003D6660_o {
    float field_0;
};

struct UnkStruct_003D6660_p {
    unsigned char pad_0[0x1530];
    float field_1530;
    unsigned char pad_1534[0x2000];
    float field_3534;
};

struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x40];
    CGtV4d field_40;
};
struct UnkStruct_D_0064F810 { void ** field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_i16 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_f16 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_sb16 { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_o16 { unsigned char pad_0[0x10]; };

class CB3HUDImpactTime {
public:
    unsigned char pad_0[0x4];
    UnkStruct_003D6660_e1 * field_4;
    CGt2dFrame * field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    UnkStruct_003D6660_o * field_20[1];  // [G] element count unknown (3 in the destroy loop)
    UnkStruct_003D6660_o * field_24;
    UnkStruct_003D6660_o * field_28;
    CGtTexture * field_2C;
    unsigned char field_30;
};

extern UnkStruct_D_0064F810 D_0064F810;
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_D_o16 D_004EE040;
extern UnkStruct_D_i16 D_00645170;
extern UnkStruct_003D6660_p D_0057BAF0;
extern UnkStruct_D_f16 D_00522680;
extern float D_004E06AC;
extern UnkStruct_D_sb16 D_004F507C;
extern UnkStruct_D_i16 D_0064D384;
extern UnkStruct_D_o16 D_0051BA44;
struct UnkStruct_D_v2 { CGtV2d field_0; unsigned char pad_8[0x8]; };  // [G] size: absolute addressing needs > 8 bytes (N50)
extern UnkStruct_D_v2 D_004CA818, D_004CA820, D_004CA828, D_004CA840;

extern "C" int func_00131E40(void *);
extern "C" float func_0012F160(void *);
extern "C" UnkStruct_003D6660_o * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, CGt2dFrame *);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, UnkStruct_003D6660_o *);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003824D0(UnkStruct_003D6660_o *, const CGtV2d &, const CGtV2d &, float, CGtV4d, CGtV4d, void *, int, float, float);
extern "C" void Prepare__18CB3HUDDPad2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(UnkStruct_003D6660_o *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    UnkStruct_003D6660_o *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, CGtTexture *, const CGtV2d &, const CGtV2d &, unsigned int);

// 0x003D6660
extern "C" void func_003D6660(CB3HUDImpactTime * self, float)
{
    UnkStruct_D_0066A4C0 * const mgr = &D_0066A4C0;
    void * p6 = *D_0064F810.field_0;
    int layer = self->field_10;
    CGt2dFrame * frame = self->field_8;
    void * scene = (char *)&self->field_4[self->field_1C] + 0x14;
    bool near = false;
    if (func_00131E40(&D_004EE040)) {
        UnkStruct_003D6660_p * p = D_00645170.field_0 > 0 ? &D_0057BAF0 : 0;
        float d = D_00522680.field_0 - p->field_3534;
        UnkEnum_003D6660 v;
        if (d < 0.0f) v = (UnkEnum_003D6660)0; else v = (UnkEnum_003D6660)1;
        if (v) { if (d <= D_004E06AC) v = (UnkEnum_003D6660)1; else v = (UnkEnum_003D6660)0; }
        near = v;
        if (p->field_1530 > 2.0f && !near) {
            for (int i = 0; i < 3; i++) {
                if (self->field_20[i] != 0) {
                    DestructObject__10CGt2dSceneFiP11CGt2dObject((char *)&self->field_4[self->field_1C] + 0x14, layer, self->field_20[i]);
                    self->field_20[i] = 0;
                }
            }
            return;
        }
    }
    if (self->field_20[0] == 0) {
        self->field_20[0] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, frame);
        self->field_24 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, frame);
        int text = func_00271A00(&D_0051BA44, 0x8A4);
        func_003824D0(self->field_20[0], CGtV2d(0.0f, 20.0f), CGtV2d(1.0f, 0.5f), 27.0f, mgr->field_40, mgr->field_40, (void *)(text), 11, 1.0f, 124.0f);
    }
    if (func_0012F160(p6) != 0.0f || near || (D_004F507C.field_0 != 0 && func_00131E40(&D_004EE040))) {
        Prepare__18CB3HUDDPad2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(
            self->field_24, CGtV2d(self->field_20[0]->field_0 - 4.0f, 19.0f), CGtV2d(1.0f, 0.5f), D_004CA818.field_0, CGtV4d(1.0f, 1.0f, 1.0f, 1.0f));
    } else {
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
            self->field_24, CGtV2d(self->field_20[0]->field_0 - 4.0f - 22.0f, 21.0f), CGtV2d(0.5f, 0.5f), D_004CA840.field_0, CGtV4d(1.0f, 1.0f, 1.0f, 1.0f), self->field_2C, D_004CA820.field_0, D_004CA828.field_0, 0);
    }
    bool v2 = self->field_30 != 0;
    if (v2) v2 = !(D_0064D384.field_0 < 2);
    if (v2) {
        if (self->field_28 == 0) {
            self->field_28 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, frame);
            int text = func_00271A00(&D_0051BA44, 0xBF6);
            func_003824D0(self->field_28, CGtV2d(0.0f, 404.0f), CGtV2d(1.0f, 0.0f), 22.0f, mgr->field_40, mgr->field_40, (void *)(text), 11, 1.0f, 580.0f);
        }
    } else {
        if (self->field_28 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, layer, self->field_28);
            self->field_28 = 0;
        }
    }
}

