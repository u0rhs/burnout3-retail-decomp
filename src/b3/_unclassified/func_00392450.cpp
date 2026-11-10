// func_00392450 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3NetworkManager.h"
#include "b3/classes/UnkStruct_D_01E32AE0.h"

struct UnkStruct_00392450;

struct UnkStruct_00392450 {
    unsigned char pad_0[0x68];
    int field_68;
};

extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::AmIHost()
extern "C" void func_00391DD0(UnkStruct_00392450 *, int, int);

// 0x00392450
extern "C" void func_00392450(UnkStruct_00392450 * self, int p0, int p1)
{
    switch (self->field_68) {
    case 3:
        self->field_68 = 4;
        break;
    case 4:
        int r0 = AmIHost__17CB3NetworkManagerFv(&D_01E32AE0);
        if (r0 != 0) {
            self->field_68 = 3;
        }
        break;
    default:
        break;
    }
    func_00391DD0(self, p0, p1);
}
