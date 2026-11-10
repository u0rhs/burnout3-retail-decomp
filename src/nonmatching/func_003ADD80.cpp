// NONMATCHING: func_003ADD80 -- retail 229 / ours 231 instructions, 109 in changed runs
// v292: control flow right (switch 4/1/2+3, colour SetA arms), 109 changed: tail CGtV2d temp/copy layout (retail A0 ctor temp ld/sd to B8+C8, GetTrackIconPos into B0, pos copy C0, half 98->A8), madd operand order (write f*0.5f), entry-jump loop (N24 goto form untested with rest), colour lq hoisted into GPR before the 8E8 test
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003ADD80 -- hand-written (v292). [L] a CB3SatNavComponent method (file neighbours B3SatNavComponent.cpp; calls
// func_003A8A90 = DNAT CB3SatNavComponent::ReleasePopups, research/proto/new_names.csv low). Unnamed in every table, so a
// placeholder with C linkage; Area unknown, so _unclassified/. Field names are placeholders, every type [G].

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
class CGt2dObject;

struct UnkStruct_003ADD80_blk {
    int field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    signed char field_14;
};
struct UnkStruct_003ADD80_obj {
    CGtV2d field_0;
    CGtV2d field_8;
    u_long128 field_10;
    UnkStruct_003ADD80_blk field_20;
};
struct UnkStruct_003ADD80_hl {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};
struct UnkStruct_003ADD80_e {
    unsigned char pad_0[0x3C];
    int field_3C[12];
    unsigned char pad_6C[0x4];
};
struct UnkStruct_003ADD80 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x6];
    float field_10;
    float field_14;
    unsigned char pad_18[0x174];
    UnkStruct_003ADD80_obj * field_18C[12];
    UnkStruct_003ADD80_obj * field_1BC;
    UnkStruct_003ADD80_hl * field_1C0[12];
    unsigned char pad_1F0[0x64];
    int field_254;
    unsigned char pad_258[0x20];
    int field_278;
    int field_27C;
    unsigned char pad_280[0x24];
    int field_2A4[12];
    unsigned char pad_2D4[0x26C];
    UnkStruct_003ADD80_e field_540[1];  // [G] element count unknown
    unsigned char pad_5B0[0x338];
    unsigned char field_8E8;
    unsigned char pad_8E9[0xC7];
    float field_9B0;
};
struct UnkStruct_D_004C9FA8 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };

extern CGtV4d D_01E90350;   // [L] CB3MenuPageManager member (field_110), BRIEF big2
extern UnkStruct_D_004C9FA8 D_004C9FA8;
extern UnkStruct_D_004C9FA8 D_004C9FAC;
extern UnkStruct_P D_01E903E0;

extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void func_003A8A90(UnkStruct_003ADD80 *);   // [L] DNAT CB3SatNavComponent::ReleasePopups() (low)
extern "C" int func_003F5D10(int);                      // [L] DNAT CB3HardCodedTrackRegionList::GetNumTrackIconPos (low)
extern "C" int func_003EA530(int);                      // [L] DNAT CB3HardCodedRaceStageList::GetNumRaceCircuitsInThisRegion (low)
extern "C" CGtV2d func_003F5C70(int, int, bool);        // [L] DNAT CB3HardCodedTrackRegionList::GetTrackIconPos (medium)

// 0x003ADD80
extern "C" void func_003ADD80(UnkStruct_003ADD80 *self, float f)
{
    void * const scene = &D_01E903E0;
    CGtV4d col;
    self->field_9B0 = 0.0f;
    col = D_01E90350;
    if (self->field_8E8 != 0) {
        col.SetA(f);
    } else if (f <= 0.0f) {
        col.SetA(0.0f);
    } else {
        col.SetA(1.0f);
    }
    if (self->field_1BC != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 13, self->field_1BC);
        self->field_1BC = 0;
        self->field_18C[self->field_278]->field_20.field_C = 1.0f;
        func_003A8A90(self);
    }
    int n = func_003F5D10(self->field_254);
    int m = func_003EA530(self->field_254);
    for (int i = 0; i < n; i++) {
        UnkStruct_003ADD80_obj *o = self->field_18C[i];
        bool b = self->field_540[self->field_254].field_3C[i] >= m;
        if (o != 0) {
            float v;
            switch (self->field_2A4[i]) {
            case 4:
                if (i == self->field_27C) {
                    if (b) o->field_20.field_14 = 50; else o->field_20.field_14 = 47;
                    v = 0.5f + 0.5f * f;
                } else if (i == self->field_278) {
                    if (b) o->field_20.field_14 = 52; else o->field_20.field_14 = 49;
                    v = 1.0f + -0.5f * f;
                } else {
                    if (b) o->field_20.field_14 = 52; else o->field_20.field_14 = 49;
                    v = 0.5f;
                }
                break;
            case 1:
                if (i == self->field_27C) {
                    v = 0.5f + 0.5f * f;
                } else if (i == self->field_278) {
                    v = 1.0f + -0.5f * f;
                } else {
                    v = 0.5f;
                }
                break;
            case 2:
            case 3:
                v = 1.0f;
                break;
            }
            CGtV2d size(D_004C9FA8.field_0 / self->field_10, D_004C9FAC.field_0 / self->field_14);
            CGtV2d pos = func_003F5C70(self->field_254, i, true);
            pos -= size * 0.5f;
            self->field_18C[i]->field_0 = pos;
            self->field_18C[i]->field_8 = size;
            self->field_18C[i]->field_20.field_4 = 0.0f;
            self->field_18C[i]->field_20.field_8 = 0.0f;
            self->field_18C[i]->field_20.field_C = v;
            self->field_18C[i]->field_10 = col.mData;
            if (self->field_1C0[i] != 0) self->field_1C0[i]->field_10 = col.mData;
        }
    }
}

