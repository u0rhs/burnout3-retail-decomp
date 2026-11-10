// func_002409B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtNetworkPlayerManager.h"
#include "b3/classes/UnkStruct_D_004E0C14.h"

struct UnkStruct_002409B0;

struct UnkStruct_002409B0 {
    unsigned char pad_0[0x40];
    CGtNetworkPlayerManager * field_40;
    unsigned char pad_44[0xC];
    int field_50[1];  // [G] element count unknown
    unsigned char pad_54[0xC];
    float field_60[1];  // [G] element count unknown
    unsigned char pad_64[0xC];
    int field_70;
    unsigned char field_74;
    unsigned char field_75;
    unsigned short field_76;
    unsigned char field_78;
    unsigned char field_79;
};

extern UnkStruct_D_004E0C14 D_004E0C14;
extern "C" void func_00240E20(UnkStruct_002409B0 *, void *);

// 0x002409B0
extern "C" void func_002409B0(UnkStruct_002409B0 * self)
{
    CGtNetworkPlayerManager * t0 = self->field_40;
    int r0 = t0->GetHostPlayerID();
    int r1 = t0->GetPlayerByID(r0);
    func_00240E20(self, (void *)(r1));
    self->field_76 = 65535;
    self->field_78 = 0;
    self->field_70 = 0;
    self->field_74 = 0;
    self->field_79 = 0;
    self->field_75 = 0;
    for (int i = 0; (i < 4); i++) {
        self->field_50[i] = 0;
    }
    float t1 = D_004E0C14.field_0;
    for (int i1 = 0; (i1 < 4); i1++) {
        self->field_60[i1] = t1;
    }
}
