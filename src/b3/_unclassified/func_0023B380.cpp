// func_0023B380 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtNetworkPlayerManager.h"
#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E32B08.h"

struct UnkStruct_0023B380;

struct UnkStruct_0023B380 {
    unsigned char pad_0[0xC];
    CGtNetworkPlayerManager * field_C;
    unsigned char pad_10[0x570];
    int field_580[1];  // [G] element count unknown
    unsigned char pad_584[0x1C];
    int field_5A0[1];  // [G] element count unknown
};

extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern "C" int func_002366D0(void *, int);
extern "C" int func_0022FBB0(void *);

// 0x0023B380
extern "C" bool func_0023B380(UnkStruct_0023B380 * self)
{
    int n = D_01E32B08.field_0;
    int p;
    int k;
    int i = 0;
    bool found = false;
    bool ok = true;
    for (; i < 8; i++) {
        if (self->field_580[i] == self->field_C->GetMyPlayerID() && self->field_5A0[i] == 2) {
            found = true;
            break;
        }
    }
    if (!found) { return 0; }
    for (k = 0; k < n; k++) {
        found = false;  // [G] the flag and index of loop 1 reused for loop 2 (fixes the s1/s6 colouring)
        p = func_002366D0(&D_01E32AE0, k);
        if (p == 0 || p == (int)self) { continue; }
        for (i = 0; i < 8; i++) {
            if (self->field_580[i] == func_0022FBB0((void *)(p)) && self->field_5A0[i] == 2) {
                found = true;
                break;
            }
        }
        if (!found) { ok = false; break; }
    }
    return ok;
}
