// DRAFT -- NOT MATCHING, NOT WIRED IN (retail's asm is still linked: game/unit_0031B860.s). See docs/known.md N95.
#include "b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent.h"

using GtMathPs2::CGtV2d;

// [L] the debug-menu state and its 0..1 transition amount (same declarations as B3HeadingComponent_00319490.cpp).
// Padded for N51.
struct UnkStruct_D_01E90424 {
    int value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E90424 D_01E90424;
struct UnkStruct_D_01E90420 {
    float value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E90420 D_01E90420;

// Same declaration as B3HelpBarComponent_0031BD60.cpp.
struct UnkStruct_D_004F50A0 {
    float value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_004F50A0 D_004F50A0;

// [L] a byte flag gating the side prompts' pop-in (lbu, tested for zero). Padded for N51.
struct UnkStruct_D_00665EA0 {
    unsigned char value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665EA0 D_00665EA0;

// 0x0031B860 (CB3HelpBarComponent::Update(float): vtable slot 0).
void CB3HelpBarComponent::Update(float dt)
{
    if (field_14 == 0)
        return;
    switch (D_01E90424.value) {
    case 2:
    case 3:
    case 4: {
        // One position local for every object: retail keeps a single stack slot and &pos.y for all four.
        CGtV2d pos;
        float lift = 32.0f * D_01E90420.value;
        pos = field_14->mObjectSpace.mTopLeftPos;
        pos.SetY(432.0f - 0.5f * field_14->mObjectSpace.mSize.marValues[1] - lift);
        field_14->mObjectSpace.mTopLeftPos = pos;
        if (field_6E == 1 || field_6E == 2) {
            pos = field_18[0]->mObjectSpace.mTopLeftPos;
            pos.SetY(432.0f - 0.5f * field_18[0]->mObjectSpace.mSize.marValues[1] - lift);
            field_18[0]->mObjectSpace.mTopLeftPos = pos;
        }
        if (field_6E == 2) {
            pos = field_20->mObjectSpace.mTopLeftPos;
            pos.SetY(432.0f - 0.5f * field_20->mObjectSpace.mSize.marValues[1] - lift);
            field_20->mObjectSpace.mTopLeftPos = pos;
            pos = field_18[1]->mObjectSpace.mTopLeftPos;
            pos.SetY(432.0f - 0.5f * field_18[1]->mObjectSpace.mSize.marValues[1] - lift);
            field_18[1]->mObjectSpace.mTopLeftPos = pos;
        }
        if (field_6E != 0)
            return;
        if (field_6D != field_C->field_0) {
            field_6D = field_C->field_0;
            ((CB3ScrollingText2dObject *)field_14)->Prepare(field_10[field_6D].field_0, false, false, field_50);
        } else {
            *(float *)&field_14->mauDataBlock[1] += dt;  // the scrolling text's offset [L]
        }
        break;
    }
    case 5: {
        CGtV2d d;
        for (int i = 0; i < 2; i++) {
            if (field_6F[i] && D_00665EA0.value) {
                float elapsed = D_004F50A0.value - field_54[i];
                if (elapsed <= 0.8f) {
                    float s;
                    if (elapsed > 0.4f)  // the second half falls through, as retail lays it out
                        s = (0.4f - (elapsed - 0.4f)) * 0.5f;
                    else
                        s = 0.5f * elapsed;
                    d = field_28[i] * s;
                    field_18[i]->mObjectSpace.mSize = field_28[i] + d;
                    d *= -0.5f;
                    field_18[i]->mObjectSpace.mTopLeftPos = field_38[i] + d;
                } else {
                    field_6F[i] = 0;
                    field_18[i]->mObjectSpace.mSize = field_28[i];
                    field_18[i]->mObjectSpace.mTopLeftPos = field_38[i];
                }
            }
        }
        // Write-backs through CGtV2d::Set, not `= pos`: an aggregate copy keeps `pos` in memory and the compared
        // x gets reloaded (N99).
        if (field_6C) {
            CGtV2d pos = field_18[0]->mObjectSpace.mTopLeftPos;
            if (pos.marValues[0] < field_64) {
                pos.marValues[0] += (field_64 - field_5C) / (1.0f / dt);
                field_18[0]->mObjectSpace.mTopLeftPos.Set(pos.marValues[0], pos.marValues[1]);
            } else {
                field_6C = 0;  // cleared first: retail's clamp then keeps x in a register on the other arm
                pos.SetX(field_64);
                field_18[0]->mObjectSpace.mTopLeftPos.Set(pos.marValues[0], pos.marValues[1]);
            }
            CGtV2d pos1 = field_18[1]->mObjectSpace.mTopLeftPos;
            if (pos1.marValues[0] > field_68) {
                pos1.marValues[0] -= (field_60 - field_68) / (1.0f / dt);
                field_18[1]->mObjectSpace.mTopLeftPos.Set(pos1.marValues[0], pos1.marValues[1]);
            } else {
                field_6C = 0;
                pos1.SetX(field_68);
                field_18[1]->mObjectSpace.mTopLeftPos.Set(pos1.marValues[0], pos1.marValues[1]);
            }
        }
        if (field_6E != 0)
            return;
        CGtV2d pos = field_14->mObjectSpace.mTopLeftPos;
        pos.SetY(432.0f - 0.5f * field_14->mObjectSpace.mSize.marValues[1] - 32.0f);
        field_14->mObjectSpace.mTopLeftPos.Set(pos.marValues[0], pos.marValues[1]);
        if (field_6D != field_C->field_0) {
            field_6D = field_C->field_0;
            ((CB3ScrollingText2dObject *)field_14)->Prepare(field_10[field_6D].field_0, false, false, field_50);
        } else {
            *(float *)&field_14->mauDataBlock[1] += dt;  // the scrolling text's offset [L]
        }
        break;
    }
    }
}
