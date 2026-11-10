// func_0013C170 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0064D3B0.h"

struct UnkStruct_0013C170;
struct UnkStruct_0013C170_2;
struct UnkStruct_0013C170_a1;

struct UnkStruct_0013C170_a1 {
    unsigned char pad_0[0x13C8];
    unsigned char field_13C8;
    unsigned char field_13C9;
    unsigned char pad_13CA[0x6];
    UnkStruct_0013C170_2 * field_13D0;
    unsigned char pad_13D4[0x1F8];
    int field_15CC;
};

struct UnkStruct_0013C170_2 {
    unsigned char pad_0[0x173];
    signed char field_173;
};

struct UnkStruct_0013C170 {
    unsigned char pad_0[0x14];
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
};

extern UnkStruct_D_0064D3B0 D_0064D3B0;
extern "C" int func_00369240(void *);
extern "C" int func_00369210(void *);
extern "C" int func_00369200(void *);

// 0x0013C170
extern "C" void func_0013C170(UnkStruct_0013C170 * self, UnkStruct_0013C170_a1 * p0, int p1)
{
    // &D_0064D3B0 held in s0 across the calls; field_11E4 an array member so its address is recomputed per call.
    UnkStruct_D_0064D3B0 * const g = &D_0064D3B0;
    if (p0->field_15CC != (int)g) {
        return;
    }
    if (p1 != 0) {
        self->field_3C++;
    } else {
        self->field_38++;
    }
    if (p0->field_13C9 != 0 && p0->field_13D0 != 0) {
        self->field_34++;
        switch (p0->field_13D0->field_173) {
        case 1:
            self->field_14++;
            break;
        case 5:
            if (p1 == 0) self->field_18++;
            break;
        case 8:
            if (p1 == 0) self->field_1C++;
            break;
        case 4:
            self->field_20++;
        case 11:
            if (p1 == 0) self->field_24++;
            break;
        }
    }
    if (p0->field_13C8 != 0 && p1 == 0) {
        self->field_28++;
    }
    if (g->field_11EB != 0) {
        self->field_30++;
    }
    if (g->field_11EC != 0 && p1 == 0) {
        self->field_2C++;
    }
    if (func_00369240(g->field_11E4) != 0) {
        self->field_40++;
    }
    if (func_00369210(g->field_11E4) != 0) {
        self->field_44++;
    }
    if (func_00369200(g->field_11E4) != 0) {
        self->field_48++;
    }
    if (g->field_11EA != 0) {
        self->field_4C++;
    }
}
