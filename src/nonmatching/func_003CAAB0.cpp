// NONMATCHING: func_003CAAB0 -- retail 371 / ours 365 instructions, 256 in changed runs
// draftAM C-first: [L] CB3HUDScoreList row layout (called from ActualPrepare__15CB3HUDScoreList with this): for each race position 1..n the car holding it (field_10C0), skipping cars out of the race (field_1160); y = 120 + 27 x row; a wrecked car (func_00150D00) gets the map icon (mapIconTextures[1], 24 x 24 at x 168) in place of its distance label, others a distance text (player-relative field_1894[list index] when the player car is out, else func_0015A7F0; km x 0.001 / miles x 0.000621371204 + " " + string 0x7DC/0x7DD) coloured by behind / player / other; then the name (car+0x1974, 16 chars) truncated with U+2026 to fit before the label; 365/371, calls identical, non-stack stores identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; the rank search (keeps the last car read when no car holds the position), both swap paths (destroy the other object, construct into the other slot), the colour picks (player: field_10/field_40 then field_10/field_60; behind (distance < 0): field_30/field_50; else Interpolate(field_60, field_30, 0.25)/field_30), the label flags 1/9 (| 0x40 for the width calls), func_003824D0's 10 arguments x2 and Prepare's 9, and the truncation loop (n >= 2, w + ellipsis <= avail) traced; behaviour_audit reports only pointer-shape differences (row slots held in registers vs re-derived)

// func_003CAAB0 -- draftAM (C-first draft). 0x3CAAB0, 0x5CC. Unnamed in every table: placeholder with C linkage. [L] a
// CB3HUDScoreList helper (its only caller is ActualPrepare__15CB3HUDScoreListFv at 0x3CB33C, a0 = this). Written from the retail
// asm; declarations as the proven/archived HUD units (func_003D8920, func_003A3250, ActualPrepare__15CB3HUDScoreList).
// Retail reads kept: when neither the distance label nor the icon exists (both null), the available width reads through a null
// pointer, as retail; row arrays are sized from the class's offsets [G] (5 rows of text).
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CGt2dFrame;
class CGtTexture;
struct UnkStruct_003CAAB0_car {
    unsigned char pad_0[0x10C0];
    short field_10C0;                       // [L] race position (1-based); also func_0015A7F0's object
    unsigned char pad_10C2[0x1160 - 0x10C2];
    unsigned char field_1160;               // [G] out of the race (finished / retired)
    unsigned char pad_1161[0x1894 - 0x1161];
    float field_1894[8];                    // [G] per-car distance as seen from this car (read on the player car, by list index)
    unsigned char pad_18B4[0x1974 - 0x18B4];
    unsigned short field_1974[16];          // [L] the driver/car name (copied with CopyN__10CGtUnicodeFPUsiPCUs 16)
};
class CGt2dScene {
public:
    void DestructObject(int, CGt2dObject *);
    CGt2dObject * ConstructObject(int, CGt2dFrame *);
};
struct UnkStruct_003CAAB0_sc { unsigned char pad_0[0x14]; CGt2dScene field_14; unsigned char pad_15[0x5B]; };   // 0x70 per entry
struct UnkStruct_003CAAB0 {                 // [L] CB3HUDScoreList (the caller ActualPrepare__15CB3HUDScoreList passes its this)
    unsigned char pad_0[0x4];
    UnkStruct_003CAAB0_sc * field_4;        // scenes
    CGt2dFrame * field_8;
    unsigned char pad_C[0x10];
    signed char field_1C;                   // scene index
    unsigned char pad_1D[0x3];
    CGt2dObject * field_20[12];             // per row: [2i] the name label, [2i+1] the distance label
    CGt2dObject * field_50[5];              // per row: the wreck icon
    unsigned char pad_64[0x1C];
    unsigned short field_80[5][32];         // per row: the distance text
    unsigned short field_1C0[5][16];        // per row: the name text
    unsigned char pad_260[0xC];
    int field_26C;                          // scene layer of the row labels
};
struct UnkStruct_003CAAB0_m {
    unsigned char pad_0[0x10];
    CGtV4d field_10;
    CGtV4d field_20;
    CGtV4d field_30;
    CGtV4d field_40;
    CGtV4d field_50;
    CGtV4d field_60;
};
struct UnkStruct_003CAAB0_D { unsigned char pad_0[0x10]; };
extern UnkStruct_003CAAB0_m D_0066A4C0;     // [G] HUD colour set
extern int D_0064D37C;                      // [L] number of race cars
extern UnkStruct_003CAAB0_car * D_0064D388[];   // [L] the race cars
extern UnkStruct_003CAAB0_car D_0064D3B0;   // [L] the player's car
extern unsigned int D_004E2918;             // [G] distance units (> 1: km)
extern UnkStruct_003CAAB0_D D_0051BA44;     // [L] the string table
extern const unsigned short D_004CA468[];   // L"\x2026" (an ellipsis)
extern float D_004E08A8;                    // FLT_MAX
extern void * mapIconTextures__15CB3HUDComponent[];
extern "C" int func_00150D00(UnkStruct_003CAAB0_car *);
extern "C" float func_0015A7F0(short *);
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" void PrintReal__10CGtUnicodeFPUsfi(unsigned short *, float, int, int);
extern "C" unsigned short * AppendN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, const unsigned short *);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, const unsigned short *);
extern "C" int Length__10CGtUnicodeFPCUs(const unsigned short *);
extern "C" void Append__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" float func_003827B0(const unsigned short *, unsigned char);
extern "C" void func_003824D0(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, CGtV4d, CGtV4d, const unsigned short *, int,
                              float, float);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, CGtTexture *, const CGtV2d &, const CGtV2d &, unsigned int);

// 0x003CAAB0
extern "C" void func_003CAAB0(UnkStruct_003CAAB0 * self)
{
    int row = 0;
    UnkStruct_003CAAB0_m * m = &D_0066A4C0;
    CGt2dScene * scene = &self->field_4[self->field_1C].field_14;
    float t = 0.25f;
    for (int rank = 0; rank < D_0064D37C; rank++) {
        UnkStruct_003CAAB0_car * car = 0;
        int i;
        for (i = 0; i < D_0064D37C; i++) {
            car = D_0064D388[i];
            if (car->field_10C0 == rank + 1)
                break;
        }
        if (car->field_1160 != 0)
            continue;
        unsigned char flags;
        CGtV4d c0, c1;
        if (car == &D_0064D3B0) {
            flags = 1;
            c0 = m->field_10;
            c1 = m->field_40;
        } else {
            flags = 9;
            c0 = m->field_40;
            c1 = m->field_40;
        }
        float y = 0.0f + 120.0f + 27.0f * (float)row;
        float size;
        float one;
        CGt2dObject ** value = &self->field_20[row * 2 + 1];
        CGt2dObject ** icon = &self->field_50[row];
        if (func_00150D00(car) != 0) {
            if (*value != 0) {
                scene->DestructObject(self->field_26C, *value);
                *value = 0;
                *icon = scene->ConstructObject(self->field_26C, self->field_8);
            }
            one = 1.0f;
            size = 24.0f;
            Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
                *icon, CGtV2d(168.0f, y), CGtV2d(one, 0.0f), CGtV2d(size, size), m->field_10,
                (CGtTexture *)mapIconTextures__15CB3HUDComponent[1], CGtV2d(0.0f, 0.0f), CGtV2d(one, one), 0);
        } else {
            if (*icon != 0) {
                scene->DestructObject(self->field_26C, *icon);
                *icon = 0;
                *value = scene->ConstructObject(self->field_26C, self->field_8);
            }
            unsigned short lSpace[2] = { 0x20, 0 };
            bool behind = false;
            float d;
            if (D_0064D3B0.field_1160 != 0) {
                d = D_0064D3B0.field_1894[i];
                if (d < 0.0f)
                    behind = true;
            } else {
                d = func_0015A7F0(&car->field_10C0);
            }
            float v;
            const unsigned short * units;
            if (D_004E2918 > 1) {
                v = 0.001f * d;
                units = func_00271A00(&D_0051BA44, 0x7DC);
            } else {
                v = 0.000621371204f * d;
                units = func_00271A00(&D_0051BA44, 0x7DD);
            }
            unsigned short * text = self->field_80[row];
            PrintReal__10CGtUnicodeFPUsfi(text, v, 1, 0);
            AppendN__10CGtUnicodeFPUsiPCUs(text, 0x20, lSpace);
            AppendN__10CGtUnicodeFPUsiPCUs(text, 0x20, units);
            if (behind) {
                c0 = m->field_30;
                c1 = m->field_50;
            } else if (car == &D_0064D3B0) {
                c0 = m->field_10;
                c1 = m->field_60;
            } else {
                c0 = Interpolate(m->field_60, m->field_30, t);
                c1 = m->field_30;
            }
            one = 1.0f;
            size = 24.0f;
            func_003824D0(*value, CGtV2d(168.0f, y), CGtV2d(one, 0.0f), size, c0, c1, text, 0x41, one, D_004E08A8);
        }
        CGt2dObject ** name = &self->field_20[row * 2];
        float avail;
        if (*value != 0)
            avail = (*value)->mObjectSpace.mTopLeftPos.marValues[0] - (*name)->mObjectSpace.mTopLeftPos.marValues[0] - 10.0f;
        else
            avail = (*icon)->mObjectSpace.mTopLeftPos.marValues[0] - (*name)->mObjectSpace.mTopLeftPos.marValues[0] - 10.0f;
        unsigned short * str = self->field_1C0[row];
        CopyN__10CGtUnicodeFPUsiPCUs(str, 0x10, car->field_1974);
        unsigned char f = flags | 0x40;
        float w = size * func_003827B0(str, f);
        if (!(w <= avail)) {
            float ell = func_003827B0(D_004CA468, f);
            int n = Length__10CGtUnicodeFPCUs(str);
            while (n >= 2 && !(w + ell <= avail)) {
                n--;
                str[n] = 0;
                w = size * func_003827B0(str, f);
            }
            Append__10CGtUnicodeFPUsPCUs(str, D_004CA468);
        }
        func_003824D0(*name, CGtV2d(0.0f, y), CGtV2d(0.0f, 0.0f), size, c0, c1, str, flags, one, D_004E08A8);
        row++;
    }
}
