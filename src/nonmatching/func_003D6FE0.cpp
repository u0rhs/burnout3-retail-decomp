// NONMATCHING: func_003D6FE0 -- retail 72 / ours 72 instructions, 25 in changed runs
// near27: 33 -> 25; rewritten as CB3HUDCrashCombo::UpdateTransition [L DNAT] cloned from the proven CB3HUDComponent sibling: bool p1, control flow + SetAllLayerVisible block exact; left: the pos/offset CGtV2d temporaries -- retail stores (0,60)*p0 into a temp at 0x78 (y first through addiu a2,sp,0x7C, x stored late, no copy), adds (0,388) into a temp at 0x68, ld/sd to pos 0x70, then lwc1/swc1 into *field_20; frame 0x80 vs 0x70. Tried operator* / ctor / *= / named-local / stand-in inline forms
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3HUDCrashCombo::UpdateTransition(float,bool,EHUDMode,EHUDMode) -- [L] DNAT: research/proto/new_names.csv (medium,
// vtable slot 3 of CB3HUDCrashCombo); the retail label is still func_003D6FE0, so an extern "C" definition.
// Fields are placeholders; every type is [G] (instruction widths). Shape cloned from the proven sibling
// CB3HUDComponent::UpdateTransition (B3HUDComponent_0019F4B0.cpp).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_003D6FE0_3 {
    unsigned char pad_0[0x10];
    CGtV4d field_10;
};

struct UnkStruct_003D6FE0 {
    unsigned char pad_0[0x8];
    UnkStruct_003D6FE0_3 * field_8;
    unsigned char pad_C[0x14];
    CGtV2d * field_20;
};

extern "C" void SetAllLayerVisible__15CB3HUDComponentFb(void *, bool);  // CB3HUDComponent::SetAllLayerVisible(bool)

// 0x003D6FE0
extern "C" void func_003D6FE0(UnkStruct_003D6FE0 * self, bool p1, float p0)
{
    if ((p0 == 1.0f && !p1) || (p0 == 0.0f && p1)) {
        SetAllLayerVisible__15CB3HUDComponentFb(self, p1);
    }
    if (p1) {
        p0 = 1.0f - p0;
    }
    CGtV2d pos(0.0f, 388.0f);
    pos += CGtV2d(0.0f, 60.0f) * p0;
    *self->field_20 = pos;
    self->field_8->field_10 = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f - p0);
}

