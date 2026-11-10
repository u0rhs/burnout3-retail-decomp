// func_00287570 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtSoundVirtualVoice.h"

struct UnkStruct_00287570;
struct UnkStruct_00287570_1;

struct UnkStruct_00287570_1 {
    unsigned char pad_0[0x40];
    unsigned char field_40;
};

struct UnkStruct_00287570 {
    unsigned char pad_0[0x2C];
    UnkStruct_00287570_1 * field_2C;
    unsigned char pad_30[0x27];
    unsigned char field_57;
    unsigned char pad_58[0x8];
    CGtSoundVirtualVoice * field_60[1];  // [G] element count unknown
};

// 0x00287570
extern "C" void func_00287570(UnkStruct_00287570 * self)
{
    for (int i = 0; ((unsigned int)i < (unsigned int)self->field_2C->field_40); i++) {
        self->field_60[i]->Stop();
    }
    self->field_57 = 0;
}
