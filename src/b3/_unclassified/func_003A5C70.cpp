// func_003A5C70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/UnkStruct_D_01E7A800.h"

struct UnkStruct_003A5C70;

struct UnkStruct_003A5C70 {
    unsigned char pad_0[0x60];
    int field_60;
    int field_64;
};

extern UnkStruct_D_01E7A800 D_01E7A800;
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);  // CB3HUDSoundManager::FEVerticalMove(), passed 1 more argument(s) [G]
extern "C" void func_003A5A00(UnkStruct_003A5C70 *, int);

// 0x003A5C70
extern "C" void func_003A5C70(UnkStruct_003A5C70 * self)
{
    int t0 = self->field_64;
    if (t0 < (self->field_60 + -1)) {
        func_003A5A00(self, (t0 + 1));
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
    }
}
