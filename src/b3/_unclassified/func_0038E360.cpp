// AllowRestartButton__23CB3OnlineCoOpCrashLogicFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3NetworkManager.h"
#include "b3/classes/UnkStruct_D_01E32AE0.h"

struct UnkStruct_0038E360;

struct UnkStruct_0038E360 {
    unsigned char pad_0[0x60];
    int field_60;
};

extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::AmIHost()

// 0x0038E360
extern "C" int AllowRestartButton__23CB3OnlineCoOpCrashLogicFv(UnkStruct_0038E360 * self)
{
    int r0 = AmIHost__17CB3NetworkManagerFv(&D_01E32AE0);
    if (r0 == 0) {
        return 0;
    }
    switch (self->field_60) {
    case 10:
    case 11:
    case 12:
        return 1;
    default:
        return 0;
    }
}
