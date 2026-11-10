// NONMATCHING: func_003BC7F0 -- retail 814 / ours 831 instructions, 1043 in changed runs
// draftAJ C-first: [L] CB3VOptionsSelectComponent::Update(float): slide-in (staggered rows), slide-out (re-prepare, kept-row fade), idle (re-colour old/new row from the manager's colour table, re-prepare, highlight flash timer, arrow bob), selection bar ease; 831/814, calls identical; left: the row-placement inline's address/temp shape (retail keeps the row CGtV2d on the stack, reloads per object), frame 0x180 vs 0x110
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra draft as a reading aid); switch shape per the 4,3,5,2 test order rule; every row offset (D_004CA2A0 by type), colour pick (normal/selected/disabled, bar field_110), timer threshold (ELF .lit4, folded 0.100000024 / 9.999998 / 13.052631) and call argument traced (FEVerticalMove's unread a1 = 1 kept)

// func_003BC7F0 -- draftAJ (C-first draft; the lifter refused it). 0x3BC7F0, 0xCB8. Unnamed in every table, so the asm label
// with C linkage. [L] CB3VOptionsSelectComponent::Update(float) (DNAT pairs this unit with it; siblings func_003BD4B0 =
// the selected row's arrows, func_003BE040 [L] PrepareItem(int,float,bool), func_003BD760). Written from the retail asm
// (Ghidra's draft as a reading aid).
// What it does [L]: per-frame layout of a vertical options list, driven by the menu manager's transition state
// (D_01E90424) and progress (D_01E90420):
//  - 2 (sliding in): rows slide in from the right one after another (staggered by 0.9 / count), panels follow;
//  - 3 / 4 (sliding out, 3 keeps the selected row): the rows' items are re-prepared once, the panels slide out, the kept
//    row fades (alpha, then its vertical flash);
//  - 5 (idle): when the selection changed, re-colour the old and new rows, re-prepare them and the arrows, and restart
//    the highlight timer field_E0 (horizontal flash for 0.4 s); the selected row's arrows bob (field_E8/field_EC);
//  - the selection bar (field_D0, func_00372400) follows the selected row, its width eased from 776 to the row's.
// Types and field meanings [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
using namespace GtMathPs2;

extern CB3MenuPageManager D_01E90240;
struct UnkStruct_D_01E90420 { float field_0; int field_4; unsigned char pad_8[0x8]; };
extern float D_01E90420;                    // the menu manager's transition progress (manager + 0x1E0)
extern int D_01E90424;                      // its transition state (manager + 0x1E4)
class CB3HUDSoundManager;
extern CB3HUDSoundManager D_01E7A800;
// CB3HUDSoundManager::FEVerticalMove(): retail passes a1 = 1 (the callee never reads it; kept as retail's call)
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(CB3HUDSoundManager *, int);
extern float D_004CA2A0[];                  // panel x per row type
extern float D_004CA298;                    // selection bar margin
struct UnkStruct_D_004CA2E8 { CGtV2d field_0; unsigned char pad_8[0x8]; };
extern UnkStruct_D_004CA2E8 D_004CA2E8;     // type-6 box size

class CB3FlashText2dObject : public CGt2dObject {
public:
    void SetHFlashTimeScale(float);
    void SetVFlashTimeScale(float);
};
struct UnkStruct_003BC7F0_list { unsigned short field_0; unsigned short field_2; };   // selected row, row count
struct UnkStruct_003BC7F0_e {               // 20-byte rows
    unsigned char pad_0[0xC];
    unsigned char field_C;                  // value (type 8: bar steps)
    unsigned char field_D;                  // type
    unsigned char field_E;                  // disabled
    unsigned char pad_F[0x5];
};
struct UnkStruct_003BC7F0 {
    unsigned char pad_0[0xC];
    UnkStruct_003BC7F0_list *field_C;
    UnkStruct_003BC7F0_e *field_10;
    CB3FlashText2dObject *field_14[9];      // row titles
    CGt2dObject *field_38[9];               // row panels
    CGt2dObject *field_5C[9];               // row values
    CGt2dObject *field_80[9];               // row value bars
    CGt2dObject *field_A4;                  // left arrow
    CGt2dObject *field_A8;                  // right arrow
    unsigned char pad_AC[0x24];
    CGt2dObject *field_D0;                  // selection bar
    CGt2dObject *field_D4;                  // header
    unsigned char pad_D8[0x4];
    int field_DC;                           // highlighted row (< 0: none)
    float field_E0;                         // highlight timer
    float field_E4;                         // list top
    float field_E8;                         // arrow bob offset
    float field_EC;                         // arrow bob speed
};
extern "C" void func_003BD4B0(UnkStruct_003BC7F0 *, int, float);
extern "C" void func_003BE040(UnkStruct_003BC7F0 *, int, float, bool);
extern "C" void func_00372400(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, float, float, CGtV4d);

// [G] place row i's panel, value and value bar at x0 + the row type's offset (the selected row also re-places its arrows)
static inline void func_003BC7F0_inl1(UnkStruct_003BC7F0 *self, int i, float x, bool sel)
{
    CGt2dObject *o = self->field_38[i];
    if (o == 0) return;
    CGtV2d p;
    p.marValues[1] = o->mObjectSpace.mTopLeftPos.marValues[1];
    p.marValues[0] = x + D_004CA2A0[self->field_10[i].field_D];
    o->mObjectSpace.mTopLeftPos = p;
    if (sel && i == self->field_C->field_0) func_003BD4B0(self, i, p.marValues[0]);
    CGt2dObject *v = self->field_5C[i];
    if (v != 0) {
        if (self->field_10[i].field_D == 6) {
            p.marValues[0] = p.marValues[0] + 0.5f * D_004CA2E8.field_0.marValues[0] - 0.5f * v->mObjectSpace.mSize.marValues[0];
        } else {
            p.marValues[0] = 5.0f + p.marValues[0];
        }
        p.marValues[1] = self->field_5C[i]->mObjectSpace.mTopLeftPos.marValues[1];
        self->field_5C[i]->mObjectSpace.mTopLeftPos = p;
        CGt2dObject *b = self->field_80[i];
        if (b != 0) {
            UnkStruct_003BC7F0_e *e = &self->field_10[i];
            if (e->field_D == 8) {
                int n = e->field_C;
                p.marValues[0] = p.marValues[0] + 13.052631f * (float)n;
            }
            b->mObjectSpace.mTopLeftPos = p;
        }
    }
}

// [G] keep y, set x
static inline void func_003BC7F0_inl2(CGt2dObject *o, float x)
{
    CGtV2d p;
    p.marValues[0] = x;
    p.marValues[1] = o->mObjectSpace.mTopLeftPos.marValues[1];
    o->mObjectSpace.mTopLeftPos = p;
}

// [G] the selection bar on the selected row, its width eased from 776 by t
static inline void func_003BC7F0_inl3(UnkStruct_003BC7F0 *self, float t)
{
    int sel = self->field_C->field_0;
    float w = D_004CA298 + self->field_14[sel]->mObjectSpace.mSize.marValues[0];
    float ew = 776.0f + t * (w - 776.0f);
    float d = ew - w;
    CGtV2d anchor;
    anchor.marValues[1] = 0.5f;
    anchor.marValues[0] = 0.0f;
    CGtV2d pos;
    pos.marValues[0] = -0.5f * d;
    pos.marValues[1] = self->field_E4 + 32.0f * (float)sel;
    func_00372400(self->field_D0, pos, anchor, 640.0f + d, 68.0f, ew, D_01E90240.field_110);
}

// [G] a row's value colours: field_0[0] normal / [1] highlighted / [2] disabled (bars: field_110 when highlighted)
static inline void func_003BC7F0_inl4(UnkStruct_003BC7F0 *self, bool hi)
{
    CGt2dObject *v = self->field_5C[self->field_DC];
    if (v != 0) {
        UnkStruct_003BC7F0_e *e = &self->field_10[self->field_DC];
        if (e->field_D != 7 && e->field_D != 8) {
            if (e->field_E) {
                v->mObjectSpace.mColour = D_01E90240.field_0[2];
            } else {
                v->mObjectSpace.mColour = D_01E90240.field_0[hi ? 1 : 0];
            }
        }
    }
    CGt2dObject *b = self->field_80[self->field_DC];
    if (b != 0) {
        if (self->field_10[self->field_DC].field_E) {
            b->mObjectSpace.mColour = D_01E90240.field_0[2];
        } else if (hi) {
            b->mObjectSpace.mColour = D_01E90240.field_110;
        } else {
            b->mObjectSpace.mColour = D_01E90240.field_0[0];
        }
    }
}

// 0x003BC7F0
extern "C" void func_003BC7F0(UnkStruct_003BC7F0 *self, float dt)
{
    switch (D_01E90424) {
    case 2: {
            float t = D_01E90420;
            float slide = 320.0f * (1.0f - t);
            float hx = D_004CA2A0[0] + slide;
            float step = 0.9f / (float)(int)self->field_C->field_2;
            for (int i = 0; i < self->field_C->field_2; i++) {
                float a = step * (float)i;
                float c = GtMath::Min(GtMath::Max(t, a), 0.100000024f + a);
                float k = 1.0f - 9.999998f * (c - a);
                func_003BC7F0_inl2(self->field_14[i], 68.0f - 320.0f * k);
                CGtV2d hp;
                hp.marValues[0] = hx;
                hp.marValues[1] = self->field_E4 - 48.0f;
                self->field_D4->mObjectSpace.mTopLeftPos = hp;
                func_003BC7F0_inl1(self, i, slide, true);
            }
            func_003BC7F0_inl3(self, t);
        break;
    }
    case 5: {
            float h;
            if (self->field_DC != self->field_C->field_0) {
                FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
                if (self->field_DC < 0) {
                    for (int i = 0; i < self->field_C->field_2; i++) {
                        func_003BC7F0_inl2(self->field_14[i], 68.0f);
                        func_003BC7F0_inl1(self, i, 0.0f, false);
                    }
                } else {
                    func_003BE040(self, self->field_DC, 68.0f, false);
                }
                func_003BC7F0_inl4(self, false);
                self->field_DC = self->field_C->field_0;
                func_003BC7F0_inl4(self, true);
                func_003BE040(self, self->field_DC, 68.0f, true);
                func_003BD4B0(self, self->field_DC, D_004CA2A0[self->field_10[self->field_DC].field_D]);
                func_003BC7F0_inl3(self, 1.0f);
            }
            h = self->field_E0;
            if (!(h < 0.0f)) {
                h = h + dt;
                self->field_E0 = h;
                float s;
                if (h < 0.4f) {
                    s = 2.5f * h;
                } else {
                    s = -1.0f;
                }
                self->field_14[self->field_DC]->SetHFlashTimeScale(s);
                if (self->field_A4 != 0) {
                    float e = self->field_E8 + dt * self->field_EC;
                    self->field_E8 = e;
                    if (!(e <= 0.4f)) {
                        self->field_E8 = 0.4f;
                        self->field_EC = self->field_EC * -1.0f;
                    } else if (e < 0.0f) {
                        self->field_E8 = 0.0f;
                        self->field_EC = self->field_EC * -1.0f;
                    }
                    float d = self->field_EC * (3.0f * (dt / 0.4f));
                    func_003BC7F0_inl2(self->field_A4, self->field_A4->mObjectSpace.mTopLeftPos.marValues[0] - d);
                    func_003BC7F0_inl2(self->field_A8, d + self->field_A8->mObjectSpace.mTopLeftPos.marValues[0]);
                }
            }
        break;
    }
    case 3:
    case 4: {
        int state = D_01E90424;
            float t = D_01E90420;
            int sel;
            if (state == 3) {
                sel = self->field_C->field_0;
            } else {
                sel = -1;
            }
            if (self->field_DC >= 0) {
                self->field_DC = -1;
                for (int i = 0; i < self->field_C->field_2; i++) {
                    if (i == sel) {
                        func_003BE040(self, i, 68.0f, true);
                        self->field_14[i]->SetHFlashTimeScale(-1.0f);
                    } else {
                        func_003BE040(self, i, 68.0f, false);
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
            float slide = 320.0f * (1.0f - t);
            float tx = 68.0f - slide;
            CGtV2d hp;
            hp.marValues[0] = D_004CA2A0[0] + slide;
            hp.marValues[1] = self->field_E4 - 48.0f;
            self->field_D4->mObjectSpace.mTopLeftPos = hp;
            for (int i = 0; i < self->field_C->field_2; i++) {
                func_003BC7F0_inl1(self, i, slide, true);
                if (i != sel) func_003BC7F0_inl2(self->field_14[i], tx);
            }
            if (sel >= 0) {
                self->field_14[sel]->mObjectSpace.mColour.SetA(a);
                self->field_14[sel]->SetVFlashTimeScale(b);
            }
            func_003BC7F0_inl3(self, t);
        break;
    }
    }
}
