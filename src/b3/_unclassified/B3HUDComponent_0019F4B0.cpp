// CB3HUDComponent::UpdateTransition(float,bool,EHUDMode,EHUDMode) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (inlined SetAllLayerVisible as static helper: flag read once before the branch, store via const-pointer pun of field_2C; N140 pad at function scope replaces the volatile pad).

// CB3HUDComponent::UpdateTransition(float,bool,EHUDMode,EHUDMode) -- [C] name: the mangled symbol in retail's tables.
// Area not evidenced, so _unclassified/. Fields are placeholders; every type is [G] (instruction widths).
// Hand-finished (near19): the inlined SetAllLayerVisible loop as a static helper (read once, store via a field_2C
// pun), plus an N140 frame pad at function scope for retail's unused 16-byte slot.

#include "b3/GtMathPs2.h"
#include "b3/classes/EHUDMode.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

enum EHUDAlign {};

struct UnkStruct_0019F4B0_e1 {
    int field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_0019F4B0_e2 {
    unsigned char pad_0[0x2C];
    UnkStruct_0019F4B0_e1 * field_2C;
    unsigned char pad_30[0x2C];
};
class CB3HUD {
public:
    CGtV2d GetAlignPos(EHUDAlign);
    unsigned char pad_0[0x14];
    UnkStruct_0019F4B0_e2 field_14;
};
struct UnkStruct_0019F4B0_obj {
    CGtV2d field_0;
    unsigned char pad_8[0x8];
    CGtV4d field_10;
};
extern CGtV2d kaMovementDirections[];

struct UnkStruct_0019F4B0_pad { UnkStruct_0019F4B0_pad() {} ~UnkStruct_0019F4B0_pad() {} int x[4]; };

class CB3HUDComponent {
public:
    void UpdateTransition(float p0, bool p1, EHUDMode p2, EHUDMode p3);

    unsigned char pad_0[0x4];
    CB3HUD * field_4;
    UnkStruct_0019F4B0_obj * field_8;
    unsigned char pad_C[0x4];
    short field_10;
    short field_12;
    int field_14;
    EHUDAlign field_18;
    signed char field_1C;
};

// [L] the inlined body of CB3HUDComponent::SetAllLayerVisible(bool) (0x19F420, B3HUDComponent_0019F420.cpp: the same loop,
// but this inlined copy re-reads field_2C for each store). A static placeholder helper, not the member, so the merged TU keeps one definition ([G] form).
// Retail reads the flag word once ahead of the branch and re-reads field_2C for each store: the store goes through a
// const-pointer pun of field_2C ([G], a63 pun rule).
static inline void func_0019F4B0_inl1(CB3HUDComponent * self, bool p0)
{
    signed char t0 = self->field_1C;
    UnkStruct_0019F4B0_e2 * t1 = &self->field_4[t0].field_14;
    for (int i = self->field_10; (i < (self->field_10 + self->field_12)); i++) {
        int v = t1->field_2C[i].field_0;
        if (p0) {
            (*(UnkStruct_0019F4B0_e1 * const *)&t1->field_2C)[i].field_0 = v & -2;
        } else {
            (*(UnkStruct_0019F4B0_e1 * const *)&t1->field_2C)[i].field_0 = v | 1;
        }
    }
}

// 0x0019F4B0
void CB3HUDComponent::UpdateTransition(float p0, bool p1, EHUDMode p2, EHUDMode p3)
{
    UnkStruct_0019F4B0_pad pad;  // N140 frame pad: retail's unused 16-byte slot
    if ((p0 == 1.0f && !p1) || (p0 == 0.0f && p1)) {
        func_0019F4B0_inl1(this, p1);
    }
    if (p1) {
        float u = 1.0f - p0;
        p0 = 1.0f - (1.0f - u * u);
    } else {
        p0 = p0 * p0;
    }
    if ((field_14 & 0x10) == 0) {
        CGtV2d pos = field_4[field_1C].GetAlignPos(field_18);
        pos += kaMovementDirections[field_18] * (80.0f * p0);
        field_8->field_0 = pos;
    }
    field_8->field_10 = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f - p0);
}
