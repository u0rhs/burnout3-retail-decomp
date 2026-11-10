// NONMATCHING: func_0039B330 -- retail 479 / ours 496 instructions, 452 in changed runs
// audit1 (2026-11-01): layout: field_14 holds 7 items, not 11 -- every later field (field_30..field_59) was read 0x10 high [C] retail offsets 0x30..0x59 off s3 (behaviour_audit) | Before: son7 first archive: sibling of func_00449510. logic/calls/offsets believed right; retail 479 vs ours 496 instrs; s-register numbering (retail this=s3, &D_01E90240=s1) and frame 0x140 vs 0x130 differ; arrow-colour loop copies via stack differ
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// func_0039B330 -- hand-written (son7). Menu-list Update(dt) sibling of func_00449510 [L]: switch on D_01E90424 (2: eased
// slide-in, 5: selection change + hflash timer, 3/4: fade/vflash) then the selection-bar placement via func_00372400.
// Field names are placeholders and every type is [G].
#include "b3/GtMathPs2.h"
#include "b3/classes/UnkStruct_D_01E90424.h"
using namespace GtMathPs2;

extern UnkStruct_D_01E90424 D_01E90424;
extern float D_01E90420;
extern float D_004E06AC;
extern float D_004E07E8;
extern float D_004E07EC;
extern float D_004E08B0;
extern float D_004C9A28;
struct UnkStruct_D_01E90350 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E90350 D_01E90350;
struct UnkStruct_D_01E90240 { CGtV4d field_0; unsigned char pad_10[0x10]; CGtV4d field_20; };
extern UnkStruct_D_01E90240 D_01E90240;
extern unsigned char D_01E7A800[];

struct UnkStruct_0039B330_item {   // [G] CB3FlashText2dObject-like
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[4];
    CGtV4d field_10;
};
struct UnkStruct_0039B330_pg { unsigned short field_0; unsigned short field_2; };
struct UnkStruct_0039B330 {
    unsigned char pad_0[0xC];
    UnkStruct_0039B330_pg *field_C;
    unsigned char pad_10[4];
    UnkStruct_0039B330_item *field_14[7];   // audit1: was [11], which put field_30..field_59 0x10 high [C] retail lw 0x30/0x38(s3), lb 0x59(s3)
    UnkStruct_0039B330_item *field_30[2];
    int field_38;
    int field_3C;
    float field_40;
    float field_44;
    unsigned char pad_48[4];
    float field_4C;
    unsigned char pad_50[4];
    float field_54;
    signed char field_58;
    signed char field_59;
};

extern "C" void func_0039BAB0(UnkStruct_0039B330 *, int);
extern "C" void func_00372400(void *, CGtV2d *, CGtV2d *, void *, float, float, float);
extern "C" void SetHFlashTimeScale__20CB3FlashText2dObjectFf(void *, float);
extern "C" void SetVFlashTimeScale__20CB3FlashText2dObjectFf(void *, float);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);

// [G] the shared selection-bar placement (inlined four times in retail)
static inline void func_0039B330_inl1(UnkStruct_0039B330 *self, float t)
{
    CGtV2d anchor;
    anchor.Set(0.0f, 0.5f);
    CGtV2d pos;
    float w = self->field_14[self->field_59]->field_8;
    float g = w + D_004C9A28;
    float f14 = 640.0f + t * (g - 640.0f);
    float d = f14 - g;
    pos.Set(-0.5f * d, 32.0f * (float)self->field_59 + self->field_40 + 0.0f);
    func_00372400((void *)(self->field_38), &pos, &anchor, &D_01E90350, 640.0f + d, (self->field_44 + 0.0f) - self->field_4C * w, f14);
}

static inline void func_0039B330_arrows(UnkStruct_0039B330 *self)
{
    for (int i = 0; i < 2; i++) {
        CGtV4d c = self->field_30[i]->field_10;
        float w = D_01E90240.field_0.W();
        if ((i == 1 && self->field_C->field_0 == self->field_C->field_2 - 1) || (i == 0 && self->field_C->field_0 == 0)) {
            c = D_01E90240.field_20;
            w = D_01E90240.field_20.W();
        }
        c.SetW(w * D_01E90420);
        self->field_30[i]->field_10 = c;
    }
}

// 0x0039B330
extern "C" void func_0039B330(UnkStruct_0039B330 *self, float dt)
{
    switch (D_01E90424.field_0) {
    case 2: {
        float t = D_01E90420;
        float step = D_004E06AC / (float)self->field_58;
        for (int i = 0; i < self->field_58; i++) {
            float f4 = step * (float)i;
            float hi = D_004E07E8 + f4;
            float m = t > f4 ? t : f4;
            m = m < hi ? m : hi;
            UnkStruct_0039B330_item *it = self->field_14[i];
            float y = it->field_4;
            float x = (self->field_44 + 0.0f) - (1.0f - D_004E07EC * (m - f4)) * 320.0f - self->field_4C * it->field_8;
            it->field_0 = x;
            it->field_4 = y;
        }
        func_0039B330_arrows(self);
        func_0039B330_inl1(self, t);
        break;
    }
    case 5:
        if (self->field_3C != (int)self->field_C->field_0) {
            self->field_30[0]->field_10 = self->field_C->field_0 == 0 ? D_01E90240.field_20 : D_01E90240.field_0;
            self->field_30[1]->field_10 = self->field_C->field_0 == self->field_C->field_2 - 1 ? D_01E90240.field_20 : D_01E90240.field_0;
            for (int i = 0; i < self->field_58; i++) func_0039BAB0(self, i);
            self->field_54 = 0.0f;
            func_0039B330_inl1(self, 1.0f);
            if (self->field_3C != -1) FEVerticalMove__18CB3HUDSoundManagerFv(D_01E7A800, 1);
            self->field_3C = self->field_C->field_0;
        }
        if (!(self->field_54 < 0.0f)) {
            self->field_54 = self->field_54 + dt;
            float s;
            if (self->field_54 < D_004E08B0) s = 2.5f * self->field_54;
            else s = -1.0f;
            SetHFlashTimeScale__20CB3FlashText2dObjectFf(self->field_14[self->field_59], s);
        }
        break;
    case 3:
    case 4: {
        float t = D_01E90420;
        int sel = (D_01E90424.field_0 == 3) ? (int)self->field_59 : -1;
        if (self->field_3C >= 0) {
            self->field_3C = -1;
            for (int i = 0; i < self->field_58; i++) {
                if (i == sel) SetHFlashTimeScale__20CB3FlashText2dObjectFf(self->field_14[i], -1.0f);
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
        for (int i = 0; i < self->field_58; i++) {
            if (i != sel) {
                UnkStruct_0039B330_item *it = self->field_14[i];
                float y = it->field_4;
                float x = (self->field_44 + 0.0f) - (1.0f - t) * 320.0f - self->field_4C * it->field_8;
                it->field_0 = x;
                it->field_4 = y;
            }
        }
        func_0039B330_arrows(self);
        if (sel >= 0) {
            UnkStruct_0039B330_item *it = self->field_14[sel];
            CGtV4d c = it->field_10;
            c.SetW(a);
            it->field_10 = c;
            SetVFlashTimeScale__20CB3FlashText2dObjectFf(self->field_14[sel], b);
        }
        func_0039B330_inl1(self, t);
        break;
    }
    }
}
