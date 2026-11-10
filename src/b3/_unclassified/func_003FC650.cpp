// func_003FC650 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E774E0.h"

struct UnkStruct_003FC650;

struct UnkStruct_003FC650 {
    unsigned char pad_0[0xBC];
    unsigned char field_BC;
    unsigned char pad_BD[0x3];
    void *field_C0;
    unsigned char pad_C4[0x4];
    int field_C8;
    unsigned char pad_CC[0x4];
    int field_D0;
    unsigned char pad_D4[0x14];
    unsigned char field_E8;
};

extern UnkStruct_D_01E774E0 D_01E774E0;
extern "C" void func_0042B580(void *);
extern "C" void Stop__14CGtSoundStreamFv(void *);
extern "C" int Release__14CGtSoundStreamFv(void *);
extern "C" void FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(void *, void *);
extern "C" void func_003FC700(UnkStruct_003FC650 *);

// 0x003FC650
extern "C" void func_003FC650(UnkStruct_003FC650 * self)
{
    self->field_E8 &= 254;
    if (self->field_BC != 0) {
        if (self->field_C0 != 0) {
            Stop__14CGtSoundStreamFv(self->field_C0);
            Release__14CGtSoundStreamFv(self->field_C0);
            FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, self->field_C0);
            self->field_C0 = 0;
        }
        if (self->field_D0 == 4) {
            self->field_D0 = 5;
            func_003FC700(self);
        }
        self->field_C8 = 6;
    } else {
        func_0042B580(((char *)self + 0x8));
    }
}
