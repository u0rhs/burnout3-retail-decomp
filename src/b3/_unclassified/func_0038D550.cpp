// func_0038D550 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3NetworkManager.h"
#include "b3/classes/UnkStruct_D_01E32AE0.h"

struct UnkStruct_0038D550;

struct UnkStruct_0038D550 {
    unsigned char pad_0[0x60];
    int field_60;
};

extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::AmIHost()
extern "C" void func_00391DD0(UnkStruct_0038D550 *, int, int);

// 0x0038D550
extern "C" void func_0038D550(UnkStruct_0038D550 * self, int p0, int p1)
{
    switch (self->field_60) {
    case 3:
        self->field_60 = 4;
        break;
    case 4:
        int r0 = AmIHost__17CB3NetworkManagerFv(&D_01E32AE0);
        if (r0 != 0) {
            self->field_60 = 3;
        }
        break;
    case 12:
        self->field_60 = 14;
        break;
    case 14:
        int r1 = AmIHost__17CB3NetworkManagerFv(&D_01E32AE0);
        if (r1 != 0) {
            self->field_60 = 12;
        }
        break;
    case 13:
        break;
    default:
        break;
    }
    func_00391DD0(self, p0, p1);
}
