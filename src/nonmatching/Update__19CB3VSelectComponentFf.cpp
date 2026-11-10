// NONMATCHING: Update__19CB3VSelectComponentFf -- retail 934 / ours 942 instructions, 443 in changed runs
// draft4: call sequence and frame (0x120) identical; scheduling and stack-slot order differ; header gap: field_C8 is a float timer, pad_CC holds float CC + bools D0/D1
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm and Ghidra draft, every branch, store and call accounted for; call sequence identical (calls.sh)

#include "b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/UnkStruct_D_01E90424.h"
#include "b3/GtMath.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

extern CB3MenuPageManager D_01E90240;
// [C] D_01E90240 + 0x1E0 / + 0x1E4 (inside the manager's unmapped tail): the menu transition's progress (float) and
// state (int; 2 = lead-in, 3/4 = lead-out [L], 5 = idle). Unsized/padded so the reference stays lui/%lo (N50/N51).
extern float D_01E90420[];
extern UnkStruct_D_01E90424 D_01E90424;
extern CB3HUDSoundManager D_01E7A800;
extern const float D_004C5390;  // [L] krVSelectRightBarGapX (B3VSelectComponent_004D81A0.cpp)

extern "C" void func_00372400(CGt2dObject *bar, const CGtV2d *pos, const CGtV2d *anchor, float w, float x, float f,
                              const CGtV4d *colour);  // CB3SelectionBar2dObject::Prepare [L, retail_names low]
extern "C" void SetHFlashTimeScale__20CB3FlashText2dObjectFf(CGt2dObject *, float);
extern "C" void SetVFlashTimeScale__20CB3FlashText2dObjectFf(CGt2dObject *, float);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(CB3HUDSoundManager *, int);

// Header gap [C]: field_C8 is a float timer (retail lwc1/add.s/c.lt.s at 0xC8), pad_CC holds float field_CC and
// bools field_D0/field_D1 (lbu 0xD0, 0xD1).
#define F_C8 (*(float *)&field_C8)
#define F_CC (*(float *)&pad_CC[0])
#define B_D0 (*(bool *)&pad_CC[4])
#define B_D1 (*(bool *)&pad_CC[5])

// 0x0031FF80
void CB3VSelectComponent::Update(float dt)
{
    if (field_C4 >= 0.0f)
        field_C4 += dt;
    if (field_D2) {
        if (!(field_C4 < 0.4f))
            field_C4 = 0.4f;
    } else {
        if (!(field_C4 < 0.4f))
            field_C4 = -1.0f;
    }

    float t = field_C4;
    if (!(t < 0.0f)) {
        if (!field_D2) {
            // lead-in: items slide in one after another
            t = t / 0.4f;
            int n = field_C->field_2;
            float step = 0.9f / (float)n;
            for (int i = 0; i < field_C->field_2; i++) {
                float start = step * (float)i;
                float f = GtMath::Min(GtMath::Max(t, start), 0.100000024f + start);
                CGt2dObject *o = field_14[i];
                float k = 0.0f + 1.0f - 9.999998f * (f - start);
                CGtV2d p = o->Pos();
                if (B_D1)
                    p.marValues[0] = 0.0f + field_BC + 320.0f * k;
                else
                    p.marValues[0] = 0.0f + field_BC - 320.0f * k;
                o->mObjectSpace.mTopLeftPos = p;
                CGt2dObject *l = field_38[i];
                if (l) {
                    CGtV2d q(0.0f + field_14[i]->Pos().marValues[0] - 0.5f * l->Size().marValues[0],
                             l->Pos().marValues[1]);
                    l->mObjectSpace.mTopLeftPos = q;
                }
            }
            int sel = field_C->field_0;
            float r = field_BC * 2.0f + 640.0f;
            float w = field_14[sel]->Size().marValues[0];
            float e = D_004C5390 + w;
            float lp = 0.0f + r + t * (e - r);
            float x = lp - e;
            float half = 0.0f;
            if (field_D4)
                half = w / 2.0f;
            CGtV2d anchor(0.0f, 0.5f);
            CGtV2d pos(-0.5f * x - half, 0.0f + field_B8 + (float)sel * (field_B0 + 2.0f));
            func_00372400(field_5C, &pos, &anchor, 640.0f + x, field_BC, lp, &D_01E90240.field_110);
        } else {
            // lead-out
            float u = (0.4f - t) / 0.4f;
            int sel;
            if (field_D3)
                sel = field_C->field_0;
            else
                sel = -1;
            if (field_A4 >= 0) {
                field_A4 = -1;
                for (int i = 0; i < field_C->field_2;) {
                    if (i == sel) {
                        func_00320EB0(this, i, field_BC, true);
                        SetHFlashTimeScale__20CB3FlashText2dObjectFf(field_14[i], -1.0f);
                        i++;
                    } else {
                        func_00320EB0(this, i, field_BC, false);
                        i++;
                    }
                }
            }
            float a, b;
            if (u < 0.5f) {
                a = u / 0.5f;
                b = 1.0f - a;
            } else {
                a = 1.0f;
                b = -1.0f;
            }
            float x;
            if (B_D1)
                x = 0.0f + field_BC + (1.0f - u) * 320.0f;
            else
                x = 0.0f + field_BC - (1.0f - u) * 320.0f;
            for (int i = 0; i < field_C->field_2; i++) {
                if (i != sel) {
                    CGt2dObject *o = field_14[i];
                    CGtV2d p = o->Pos();
                    p.marValues[0] = x;
                    o->mObjectSpace.mTopLeftPos = p;
                    CGt2dObject *l = field_38[i];
                    if (l) {
                        CGtV2d q(0.0f + field_14[i]->Pos().marValues[0] - 0.5f * l->Size().marValues[0],
                                 l->Pos().marValues[1]);
                        l->mObjectSpace.mTopLeftPos = q;
                    }
                }
            }
            if (sel >= 0) {
                CGt2dObject *o = field_14[sel];
                CGtV4d c(o->mObjectSpace.mColour);
                c.SetA(a);
                o->mObjectSpace.mColour = c;
                SetVFlashTimeScale__20CB3FlashText2dObjectFf(field_14[sel], b);
                CGt2dObject *l = field_38[sel];
                if (l)
                    l->mObjectSpace.mColour = c;
            }
            int cur = field_C->field_0;
            float r = field_BC * 2.0f + 640.0f;
            float w = field_14[cur]->Size().marValues[0];
            float e = D_004C5390 + w;
            float lp = 0.0f + r + u * (e - r);
            float x2 = lp - e;
            float half = 0.0f;
            if (field_D4)
                half = w / 2.0f;
            CGtV2d anchor(0.0f, 0.5f);
            CGtV2d pos(-0.5f * x2 - half, 0.0f + field_B8 + (float)cur * (field_B0 + 2.0f));
            func_00372400(field_5C, &pos, &anchor, 640.0f + x2, field_BC, lp, &D_01E90240.field_110);
        }
        return;
    }
    int state = D_01E90424.field_0;
    switch (state) {
    case 2: {
        float tt = D_01E90420[0];
        int n = field_C->field_2;
        float step = 0.9f / (float)n;
        float half = 0.0f;
        for (int i = 0; i < field_C->field_2; i++) {
            float start = step * (float)i;
            float f = GtMath::Min(GtMath::Max(tt, start), 0.100000024f + start);
            CGt2dObject *o = field_14[i];
            float k = 0.0f + 1.0f - 9.999998f * (f - start);
            if (field_D4)
                half = o->Size().marValues[0] / 2.0f;
            CGtV2d p = o->Pos();
            if (B_D1)
                p.marValues[0] = 0.0f + field_BC + 320.0f * k;
            else
                p.marValues[0] = 0.0f + field_BC - 320.0f * k;
            p.marValues[0] = p.marValues[0] - half;
            o->mObjectSpace.mTopLeftPos = p;
            CGt2dObject *l = field_38[i];
            if (l) {
                CGtV2d q(0.0f + field_14[i]->Pos().marValues[0] - 0.5f * l->Size().marValues[0],
                         l->Pos().marValues[1]);
                l->mObjectSpace.mTopLeftPos = q;
            }
        }
        int sel = field_C->field_0;
        float r = field_BC * 2.0f + 640.0f;
        float w = field_14[sel]->Size().marValues[0];
        float e = D_004C5390 + w;
        float lp = 0.0f + r + tt * (e - r);
            float x = lp - e;
        float h2 = 0.0f;
        if (field_D4)
            h2 = w / 2.0f;
        CGtV2d anchor(0.0f, 0.5f);
        CGtV2d pos(-0.5f * x - h2, 0.0f + field_B8 + (float)sel * (field_B0 + 2.0f));
        func_00372400(field_5C, &pos, &anchor, 640.0f + x, field_BC, lp, &D_01E90240.field_110);
    } break;
    case 5: {
        // idle: the frame fades in/out (field_D0), the bar follows the current item
        CGtV4d c(D_01E90240.field_110);
        float f;
        if (!B_D0) {
            F_CC += dt;
            if (F_CC < 0.4f) {
                f = 2.5f * F_CC;
            } else {
                f = 1.0f;
                F_CC = 0.4f;
            }
        } else {
            F_CC -= dt;
            if (F_CC > 0.0f) {
                f = 2.5f * F_CC;
            } else {
                F_CC = 0.0f;
                f = 0.0f;
            }
        }
        c.SetA(0.0f + 0.0f + f * 1.0f);
        field_A8->field_0.field_10 = c;
        if (field_A4 != field_C->field_0) {
            if (field_A4 < 0) {
                for (int i = 0; i < field_C->field_2; i++) {
                    CGt2dObject *o = field_14[i];
                    CGtV2d p = o->Pos();
                    if (field_D4)
                        p.marValues[0] = field_BC - o->Size().marValues[0] / 2.0f;
                    else
                        p.marValues[0] = field_BC;
                    o->mObjectSpace.mTopLeftPos = p;
                    CGt2dObject *l = field_38[i];
                    if (l) {
                        CGtV2d q(0.0f + field_14[i]->Pos().marValues[0] - 0.5f * l->Size().marValues[0],
                                 l->Pos().marValues[1]);
                        l->mObjectSpace.mTopLeftPos = q;
                    }
                }
                FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            } else {
                func_00320EB0(this, field_A4, field_BC, false);
                FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            }
            field_A4 = field_C->field_0;
            func_00320EB0(this, field_A4, field_BC, true);
            int cur = field_C->field_0;
            float r = field_BC * 2.0f + 640.0f;
            float w = field_14[cur]->Size().marValues[0];
            float e = D_004C5390 + w;
            float lp = 0.0f + r + 1.0f * (e - r);
            float x2 = lp - e;
            float half = 0.0f;
            if (field_D4)
                half = w / 2.0f;
            CGtV2d anchor(0.0f, 0.5f);
            CGtV2d pos(-0.5f * x2 - half, 0.0f + field_B8 + (float)cur * (field_B0 + 2.0f));
            func_00372400(field_5C, &pos, &anchor, 640.0f + x2, field_BC, lp, &D_01E90240.field_110);
        }
        if (F_C8 >= 0.0f) {
            F_C8 += dt;
            float h;
            if (F_C8 < 0.4f)
                h = 2.5f * F_C8;
            else
                h = -1.0f;
            SetHFlashTimeScale__20CB3FlashText2dObjectFf(field_14[field_A4], h);
        }
    } break;
    case 3:
    case 4: {
        float tt = D_01E90420[0];
        int sel;
        if (state == 3)
            sel = field_C->field_0;
        else
            sel = -1;
        if (field_A4 >= 0) {
            field_A4 = -1;
            for (int i = 0; i < field_C->field_2;) {
                if (i == sel) {
                    func_00320EB0(this, i, field_BC, true);
                    SetHFlashTimeScale__20CB3FlashText2dObjectFf(field_14[i], -1.0f);
                    i++;
                } else {
                    func_00320EB0(this, i, field_BC, false);
                    i++;
                }
            }
        }
        float a, b;
        if (tt < 0.5f) {
            a = tt / 0.5f;
            b = 1.0f - a;
        } else {
            a = 1.0f;
            b = -1.0f;
        }
        float x;
        if (B_D1)
            x = 0.0f + field_BC + (1.0f - tt) * 320.0f;
        else
            x = 0.0f + field_BC - (1.0f - tt) * 320.0f;
        for (int i = 0; i < field_C->field_2; i++) {
            if (i != sel) {
                CGt2dObject *o = field_14[i];
                CGtV2d p = o->Pos();
                p.marValues[0] = x;
                if (field_D4)
                    p.marValues[0] = x - o->Size().marValues[0] / 2.0f;
                o->mObjectSpace.mTopLeftPos = p;
                CGt2dObject *l = field_38[i];
                if (l) {
                    CGtV2d q(0.0f + field_14[i]->Pos().marValues[0] - 0.5f * l->Size().marValues[0],
                             l->Pos().marValues[1]);
                    l->mObjectSpace.mTopLeftPos = q;
                }
            }
        }
        if (sel >= 0) {
            CGt2dObject *o = field_14[sel];
            o->mObjectSpace.mColour.SetA(a);
            SetVFlashTimeScale__20CB3FlashText2dObjectFf(field_14[sel], b);
        }
        int cur = field_C->field_0;
        float r = field_BC * 2.0f + 640.0f;
        float w = field_14[cur]->Size().marValues[0];
        float e = D_004C5390 + w;
        float lp = 0.0f + r + tt * (e - r);
            float x2 = lp - e;
        float half = 0.0f;
        if (field_D4)
            half = w / 2.0f;
        CGtV2d anchor(0.0f, 0.5f);
        CGtV2d pos(-0.5f * x2 - half, 0.0f + field_B8 + (float)cur * (field_B0 + 2.0f));
        func_00372400(field_5C, &pos, &anchor, 640.0f + x2, field_BC, lp, &D_01E90240.field_110);
    } break;
    }
}
