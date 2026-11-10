// func_003A02F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E90424.h"

struct UnkStruct_003A02F0;

struct UnkStruct_003A02F0 {
    unsigned char pad_0[0xF4];
    signed char field_F4;
    unsigned char pad_F5[0x5EF];
    int field_6E4;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern "C" void func_003A0050(UnkStruct_003A02F0 *);
extern "C" void func_0039FD90(UnkStruct_003A02F0 *);
extern "C" void func_0039FA70(UnkStruct_003A02F0 *);
extern "C" void func_0039F490(UnkStruct_003A02F0 *);
extern "C" void func_0039F090(UnkStruct_003A02F0 *);

// 0x003A02F0
extern "C" void func_003A02F0(UnkStruct_003A02F0 * self)
{
    if (D_01E90424.field_0 == 5) {
        signed char t0 = self->field_F4;
        switch (t0) {
        case 0:
            int t1 = self->field_6E4;
            if (t1 != 1) {
                if (t1 == 0) {
                    func_003A0050(self);
                } else {
                    func_0039FD90(self);
                }
            } else {
                func_0039FA70(self);
            }
            break;
        case 1:
            if ((unsigned int)self->field_6E4 < (unsigned int)2) {
                func_0039F490(self);
            } else {
                func_0039F090(self);
            }
            break;
        }
        return;
    }
}
