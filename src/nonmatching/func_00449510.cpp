// NONMATCHING: func_00449510 -- retail 408 / ours 445 instructions, 378 in changed runs
// son5: menu-list Update(dt) sibling of func_00449050/00449B70: switch on D_01E90424 (2: eased slide-in, 5: selection change + hflash timer, 3/4: fade/vflash) then selection-bar placement via func_00372400. remaining: ours 445 vs 408 instrs (retail shares/hoists constants and the placement block differently), s-register numbering (retail this in s0), float-register allocation
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
#include "b3/classes/UnkStruct_D_01E90424.h"
using namespace GtMathPs2;

extern UnkStruct_D_01E90424 D_01E90424;
extern float D_01E90420;
extern float D_004D30D8;
extern float D_004E06A8;
extern float D_004E0B28;
extern float D_004E0B2C;
extern float D_004E08B0;
struct UnkStruct_D_01E90350 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E90350 D_01E90350;
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x20]; CGtV4d field_20; };
extern UnkStruct_D_01E90240 D_01E90240;
extern unsigned char D_01E7A800[];

struct UnkStruct_00449510_item {   // [G] CB3FlashText2dObject-like
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[4];
    CGtV4d field_10;
};
struct UnkStruct_00449510_b { unsigned char pad_0[4]; float field_4; };
struct UnkStruct_00449510_ent { unsigned char pad_0[4]; unsigned char field_4; unsigned char pad_5[3]; };   // [G] stride 8
struct UnkStruct_00449510 {
    unsigned char pad_0[0xC];
    unsigned short field_C;
    unsigned short field_E;
    UnkStruct_00449510_ent field_10[5];   // [G] stride 8

    UnkStruct_00449510_item *field_38[5];
    int field_4C;
    int field_50;
    unsigned char pad_54[0x10];
    float field_64;
    unsigned char pad_68[4];
    unsigned char field_6C;
    unsigned char pad_6D[0x88 - 0x6D];
    UnkStruct_00449510_b *field_88;
    unsigned char pad_8C[4];
    signed char field_90;
    unsigned char pad_91[0x63];
    float field_F4;
};

extern "C" void func_00449050(UnkStruct_00449510 *, int, int, float);
extern "C" void func_00372400(void *, CGtV2d *, CGtV2d *, void *, float, float, float);
extern "C" void SetHFlashTimeScale__20CB3FlashText2dObjectFf(void *, float);
extern "C" void SetVFlashTimeScale__20CB3FlashText2dObjectFf(void *, float);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);

// [G] the shared selection-bar placement (inlined five times in retail)
static inline void func_00449510_inl1(UnkStruct_00449510 *self, float t)
{
    CGtV2d anchor;
    anchor.Set(0.0f, 0.5f);
    CGtV2d pos;
    float y = 0.0f + (self->field_F4 + self->field_88->field_4 + 15.0f) + 32.0f * (float)self->field_C;
    pos.Set(0.0f, y);
    float w = self->field_38[self->field_C]->field_8;
    float f14 = 640.0f + t * ((D_004D30D8 + w) - 640.0f);
    float x = (D_004D30D8 / 2.0f + (640.0f - f14)) / 2.0f;
    func_00372400((void *)(self->field_4C), &pos, &anchor, &D_01E90350, 640.0f, x, f14);
}

// 0x00449510
extern "C" void func_00449510(UnkStruct_00449510 *self, float dt)
{
    int count = (self->field_90 != 0) ? self->field_E : 0;
    if (count == 0) return;
    switch (D_01E90424.field_0) {
    case 2: {
        float t = D_01E90420;
        float step = D_004E06A8 / (float)count;
        for (int i = 0; i < count; i++) {
            float f4 = step * (float)i;
            float hi = D_004E0B28 + f4;
            float m = t > f4 ? t : f4;
            m = m < hi ? m : hi;
            UnkStruct_00449510_item *it = self->field_38[i];
            float x = (320.0f - 400.0f * (1.0f - D_004E0B2C * (m - f4))) - 0.5f * it->field_8;
            CGtV2d p;
            p.Set(x, it->field_4);
            it->field_0 = p.X();
            it->field_4 = p.Y();
        }
        func_00449510_inl1(self, t);
        break;
    }
    case 5:
        if (self->field_50 != (int)self->field_C) {
            if (self->field_50 < 0) {
                for (int i = 0; i < count; i++) {
                    UnkStruct_00449510_item *it = self->field_38[i];
                    CGtV2d p;
                    p.Set(320.0f - 0.5f * it->field_8, it->field_4);
                    it->field_0 = p.X();
                    it->field_4 = p.Y();
                }
                FEVerticalMove__18CB3HUDSoundManagerFv(D_01E7A800, 1);
            } else {
                func_00449050(self, self->field_50, 0, 320.0f);
                FEVerticalMove__18CB3HUDSoundManagerFv(D_01E7A800, 1);
            }
            self->field_50 = self->field_C;
            func_00449050(self, self->field_50, 1, 320.0f);
            func_00449510_inl1(self, 1.0f);
        }
        if (!(self->field_64 < 0.0f)) {
            self->field_64 = self->field_64 + dt;
            float s;
            if (self->field_64 < D_004E08B0) s = 2.5f * self->field_64;
            else s = -1.0f;
            SetHFlashTimeScale__20CB3FlashText2dObjectFf(self->field_38[self->field_50], s);
        }
        break;
    case 3:
    case 4: {
        float t = D_01E90420;
        int sel = (D_01E90424.field_0 == 3) ? (int)self->field_C : -1;
        if (self->field_50 >= 0) {
            self->field_50 = -1;
            for (int i = 0; i < count; i++) {
                if (i == sel) {
                    func_00449050(self, i, 1, 320.0f);
                    SetHFlashTimeScale__20CB3FlashText2dObjectFf(self->field_38[i], -1.0f);
                } else {
                    func_00449050(self, i, 0, 320.0f);
                }
            }
        }
        float a, b;
        if (t < 0.5f) {
            a = t / 0.5f;
            b = 1.0f - a;
        } else {
            a = 1.0f;
            b = -1.0f;
        }
        for (int i = 0; i < count; i++) {
            if (i == sel) {
                SetVFlashTimeScale__20CB3FlashText2dObjectFf(self->field_38[i], b);
            } else {
                UnkStruct_00449510_item *it = self->field_38[i];
                CGtV4d c = it->field_10;
                if (self->field_6C != 0 && self->field_10[i].field_4 != 0) {
                    c = D_01E90240.field_20;
                }
                c.SetW(a);
                it->field_10 = c;
            }
        }
        func_00449510_inl1(self, t);
        break;
    }
    }
}
