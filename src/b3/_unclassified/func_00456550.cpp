// func_00456550 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004D3448.h"

struct UnkStruct_00456550;

struct UnkStruct_00456550 {
    unsigned char pad_0[0x20];
    unsigned char field_20[1];  // [G] element count unknown
    unsigned char pad_21[0x27];
    float field_48[1];  // [G] element count unknown
    unsigned char pad_4C[0x10];
    float field_5C[1];  // [G] element count unknown
    unsigned char pad_60[0x10];
    int field_70;
    float field_74;
    int field_78;
    int field_7C;
};

extern const float D_004D3490[];  // [G] element count unknown
extern const float D_004D34D0[];  // [G] element count unknown
extern const float D_004D3450[];  // [G] element count unknown
extern const float D_004D3470[];  // [G] element count unknown
extern UnkStruct_D_004D3448 D_004D3448;
extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Prepare()
extern "C" void func_00455F60(UnkStruct_00456550 *);

// 0x00456550
extern "C" int func_00456550(UnkStruct_00456550 * self, int p0, int p1)
{
    Prepare__20CB3MenuComponentBaseFv(self);
    self->field_70 = 0;
    self->field_7C = p0;
    self->field_78 = p1;
    for (int i = 0; i < 5; i++) {
        self->field_20[i] = 0;
    }
    if (self->field_7C == 7) {
        for (int i = 0; i < 5; i++) {
            self->field_48[i] = D_004D3450[i];
            self->field_5C[i] = D_004D3470[i];
        }
        self->field_74 = D_004D3448.field_0;
    } else {
        for (int i = 0; i < 5; i++) {
            self->field_48[i] = D_004D3490[i];
            self->field_5C[i] = D_004D34D0[i];
        }
        self->field_74 = 1.0f;
        if (self->field_7C == 3 || (unsigned int)(self->field_7C - 9) < 3) {
            for (int i = 0; i <= 2; i++) {
                self->field_48[i] += 4.0f;
            }
        }
    }
    func_00455F60(self);
    return 1;
}
