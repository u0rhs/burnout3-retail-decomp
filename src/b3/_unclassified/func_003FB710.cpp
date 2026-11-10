// func_003FB710 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E1EDC.h"
#include "b3/classes/UnkStruct_D_004E1EE0.h"
#include "b3/classes/UnkStruct_D_004E1EE4.h"
#include "b3/classes/UnkStruct_D_004E1EE8.h"
#include "b3/classes/UnkStruct_D_004E1EEC.h"
#include "b3/classes/UnkStruct_D_004E1EF0.h"
#include "b3/classes/UnkStruct_D_004E1EF4.h"
#include "b3/classes/UnkStruct_D_004E1EF8.h"

struct UnkStruct_003FB710;

struct UnkStruct_003FB710 {
    unsigned char pad_0[0xEC];
    int field_EC;
    unsigned char pad_F0[0x40];
    unsigned char field_130[1];  // [G] element count unknown
    unsigned char pad_131[0x2F];
    int field_160;
    int field_164;
    int field_168;
    int field_16C;
    int field_170;
    unsigned char pad_174[0x4];
    int field_178;
    unsigned char pad_17C[0x4];
    int field_180;
    int field_184;
    unsigned char pad_188[0xC];
    unsigned char field_194;
    unsigned char pad_195[0x3];
    int field_198;
    unsigned char pad_19C[0x4];
    int field_1A0;
    unsigned char pad_1A4[0x4];
    int field_1A8;
    unsigned char field_1AC;
    unsigned char pad_1AD[0x1];
    unsigned char field_1AE;
    unsigned char pad_1AF[0x1];
    unsigned char field_1B0;
};

extern UnkStruct_D_004E1EEC D_004E1EEC;
extern UnkStruct_D_004E1EF0 D_004E1EF0;
extern UnkStruct_D_004E1EF4 D_004E1EF4;
extern UnkStruct_D_004E1EF8 D_004E1EF8;
extern UnkStruct_D_004E1EDC D_004E1EDC;
extern UnkStruct_D_004E1EE0 D_004E1EE0;
extern UnkStruct_D_004E1EE4 D_004E1EE4;
extern UnkStruct_D_004E1EE8 D_004E1EE8;
extern "C" void func_003FCD20(UnkStruct_003FB710 *);

// 0x003FB710
extern "C" void func_003FB710(UnkStruct_003FB710 * self)
{
    self->field_16C = 0;
    self->field_168 = 0;
    self->field_164 = 0;
    self->field_160 = 0;
    self->field_198 = 0;
    self->field_180 = 0;
    self->field_184 = -1;
    self->field_178 = 0;
    self->field_170 = 1;
    self->field_194 = 0;
    self->field_1AC = 0;
    self->field_1AE = 1;
    self->field_EC = 0;
    self->field_1B0 = 1;
    func_003FCD20(self);
    for (int i = 0; (i < 38); i++) {
        self->field_130[i] = i;
    }
    float t0 = D_004E1EF0.field_0;
    float t1 = D_004E1EF4.field_0;
    float t2 = D_004E1EF8.field_0;
    D_004E1EDC.field_0 = D_004E1EEC.field_0;
    D_004E1EE0.field_0 = t0;
    D_004E1EE4.field_0 = t1;
    D_004E1EE8.field_0 = t2;
    self->field_1A0 = 0;
    self->field_1A8 = 0;
}
