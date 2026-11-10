// NONMATCHING: func_003A3EA0 -- retail 509 / ours 504 instructions, 124 in changed runs
// a170 CB3TabbedDisplayComponent gradient-panel build [L]: block layout/logic exact (teardown loop, field_104 dispatch placed after the bodies via goto, 5 Prepare shapes F1a/F1b/F2/F3a/F3b as GtMathPs2 temporaries, by-pointer CGtV4d args = &D_01E90240+0x150), 504/509 instrs, 124 in changed runs: float-load order / register naming (retail loads Q before P into a0/v1, reloads Q->y; sdata D_004E0B3C/D_004E0978 loads) and 5 missing reloads; locals/pp-pointer forms made it worse.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (a170): CB3TabbedDisplayComponent gradient-panel layout/prepare (GtMathPs2 temporaries, goto-laid-out blocks) [L]
#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_3A3EA0_rect {
    CGtV2d pos;
    CGtV2d size;
};
struct UnkStruct_3A3EA0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x30 - 0xA];
    UnkStruct_3A3EA0_rect * field_30;
    UnkStruct_3A3EA0_rect * field_34[4];
    unsigned char pad_44[0x4C - 0x44];
    void * field_4C[2];
    void * field_54;
    int field_58;
    unsigned char pad_5C[0xD0 - 0x5C];
    void * field_D0;
    void * field_D4;
    unsigned char pad_D8[0x104 - 0xD8];
    int field_104;
    int field_108;
};
struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x150];
    CGtV4d field_150;
};
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_Pad16 D_01E903E0;
extern UnkStruct_D_01E90240 D_01E90240;
extern float D_004E0B3C;
extern float D_004E0978;
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
extern "C" void Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, const void *, const void *, float);

// 0x003A3EA0
extern "C" void func_003A3EA0(UnkStruct_3A3EA0 * self, int mode)
{
    void * const scene = &D_01E903E0;
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    void * parent = self->field_D4;
    int i;
    if (parent == 0) parent = self->field_D0;
    for (i = 0; i < self->field_58; i++) {
        void ** p = &self->field_4C[i];
        if (*p) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8, *p);
            *p = 0;
        }
    }
    if (self->field_54) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8, self->field_54);
        self->field_54 = 0;
    }
    switch (self->field_104) {
    default:
        break;
    case 3:
    case 0:
    case 4:
        if (mode == 0) {
            self->field_58 = 1;
            for (i = 0; i < self->field_58; i++) {
                self->field_4C[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, parent);
            }
            Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(self->field_4C[0], CGtV2d(self->field_30->pos.marValues[0], (self->field_34[mode]->pos.marValues[1] + self->field_34[mode]->size.marValues[1]) - D_004E0B3C), CGtV2d(0.5f, 0.0f), CGtV2d(D_004E0B3C, D_004E0978 + ((self->field_30->pos.marValues[1] + self->field_30->size.marValues[1]) - (self->field_34[mode]->pos.marValues[1] + self->field_34[mode]->size.marValues[1]))), &mgr->field_150, &mgr->field_150, 0.0f);
            self->field_54 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, parent);
            Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(self->field_54, CGtV2d(38.0f + self->field_34[mode]->pos.marValues[0], self->field_34[mode]->pos.marValues[1]), CGtV2d(0.0f, 0.0f), CGtV2d((D_004E0978 + (self->field_30->pos.marValues[0] + self->field_30->size.marValues[0])) - (38.0f + self->field_34[mode]->pos.marValues[0]), D_004E0B3C), &mgr->field_150, &mgr->field_150, 0.0f);
        } else if ((unsigned int)(mode - 1) <= 1) {
            self->field_58 = 2;
            for (i = 0; i < self->field_58; i++) {
                self->field_4C[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, parent);
            }
            Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(self->field_4C[0], CGtV2d(self->field_30->pos.marValues[0], self->field_34[0]->pos.marValues[1]), CGtV2d(0.5f, 0.0f), CGtV2d(D_004E0B3C, (D_004E0B3C + self->field_34[mode]->pos.marValues[1]) - self->field_34[0]->pos.marValues[1]), &mgr->field_150, &mgr->field_150, 0.0f);
            Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(self->field_4C[1], CGtV2d(self->field_30->pos.marValues[0], (self->field_34[mode]->pos.marValues[1] + self->field_34[mode]->size.marValues[1]) - D_004E0B3C), CGtV2d(0.5f, 0.0f), CGtV2d(D_004E0B3C, D_004E0978 + ((self->field_30->pos.marValues[1] + self->field_30->size.marValues[1]) - (self->field_34[mode]->pos.marValues[1] + self->field_34[mode]->size.marValues[1]))), &mgr->field_150, &mgr->field_150, 0.0f);
        } else if (mode == 3) {
            if (self->field_108 == 0) {
                self->field_58 = 2;
                for (i = 0; i < self->field_58; i++) {
                    self->field_4C[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, parent);
                }
                Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(self->field_4C[0], CGtV2d(self->field_30->pos.marValues[0], self->field_34[0]->pos.marValues[1]), CGtV2d(0.5f, 0.0f), CGtV2d(D_004E0B3C, D_004E0B3C + (self->field_34[mode]->pos.marValues[1] - self->field_34[0]->pos.marValues[1])), &mgr->field_150, &mgr->field_150, 0.0f);
                Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(self->field_4C[1], CGtV2d(self->field_30->pos.marValues[0], (self->field_34[mode]->pos.marValues[1] + self->field_34[mode]->size.marValues[1]) - D_004E0B3C), CGtV2d(0.5f, 0.0f), CGtV2d(D_004E0B3C, D_004E0978 + ((self->field_30->pos.marValues[1] + self->field_30->size.marValues[1]) - (self->field_34[mode]->pos.marValues[1] + self->field_34[mode]->size.marValues[1]))), &mgr->field_150, &mgr->field_150, 0.0f);
            
            } else {
                self->field_58 = 1;
                for (i = 0; i < self->field_58; i++) {
                    self->field_4C[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, parent);
                }
                Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(self->field_4C[0], CGtV2d(self->field_30->pos.marValues[0], self->field_34[0]->pos.marValues[1]), CGtV2d(0.5f, 0.0f), CGtV2d(D_004E0B3C, D_004E0B3C + (self->field_34[mode]->pos.marValues[1] - self->field_34[0]->pos.marValues[1])), &mgr->field_150, &mgr->field_150, 0.0f);
                self->field_54 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, parent);
                Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(self->field_54, CGtV2d(38.0f + self->field_34[mode]->pos.marValues[0], self->field_34[mode]->pos.marValues[1] + self->field_34[mode]->size.marValues[1]), CGtV2d(0.0f, 1.0f), CGtV2d(((self->field_30->pos.marValues[0] + self->field_30->size.marValues[0]) - 16.0f) - (38.0f + self->field_34[mode]->pos.marValues[0]), D_004E0B3C), &mgr->field_150, &mgr->field_150, 0.0f);
            }
        }
        break;
    case 1:
    case 2:
        self->field_58 = 1;
        self->field_4C[0] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, parent);
        Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(self->field_4C[0], CGtV2d(self->field_30->pos.marValues[0], (self->field_34[mode]->pos.marValues[1] + self->field_34[mode]->size.marValues[1]) - D_004E0B3C), CGtV2d(0.5f, 0.0f), CGtV2d(D_004E0B3C, D_004E0978 + ((self->field_30->pos.marValues[1] + self->field_30->size.marValues[1]) - (self->field_34[mode]->pos.marValues[1] + self->field_34[mode]->size.marValues[1]))), &mgr->field_150, &mgr->field_150, 0.0f);
        self->field_54 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, parent);
        Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(self->field_54, CGtV2d(38.0f + self->field_34[mode]->pos.marValues[0], self->field_34[mode]->pos.marValues[1]), CGtV2d(0.0f, 0.0f), CGtV2d((D_004E0978 + (self->field_30->pos.marValues[0] + self->field_30->size.marValues[0])) - (38.0f + self->field_34[mode]->pos.marValues[0]), D_004E0B3C), &mgr->field_150, &mgr->field_150, 0.0f);
        break;
    }
}
