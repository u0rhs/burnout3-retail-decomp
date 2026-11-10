// func_003388C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004C58E0.h"
#include "b3/classes/UnkStruct_D_004E2DAC.h"

struct UnkStruct_003388C0;
struct UnkStruct_func_00338540;

struct UnkStruct_func_00338540 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003388C0 {
    unsigned char pad_0[0x104];
    int field_104;
    unsigned char pad_108[0x8];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x8];
    unsigned char field_120;
    unsigned char pad_121[0x493];
    int field_5B4;
    int field_5B8;
};

extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_D_004C58E0 D_004C58E0;
extern UnkStruct_func_00338540 func_00338540;
extern "C" void TagFieldSetString(UnkStruct_003362B0_1 *, int, void *, int, int);
extern "C" void LobbyApiRequestCB(int, int, UnkStruct_003362B0_1 *, void *, UnkStruct_003388C0 *);

// 0x003388C0
extern "C" void func_003388C0(UnkStruct_003388C0 * self, int p0, int p1, int p2)
{
    if (self->field_104 == 0) return;
    self->field_5B4 = p1;
    self->field_5B8 = p2;
    D_004E2DAC.field_0->field_0 = 0;
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C58E0, p0, p0);
    LobbyApiRequestCB(self->field_104, 0x6F6E6C6E, D_004E2DAC.field_0, &func_00338540, self);
    self->field_110 = 1;
    self->field_111 = 0;
    self->field_112 = 0;
    self->field_120 = 0;
    self->field_114 = 0;
}
