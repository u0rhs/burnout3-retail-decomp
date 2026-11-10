// func_0022D3C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01D6EDD0.h"
#include "b3/classes/UnkStruct__gbEncryptionKeyValid.h"

extern UnkStruct__gbEncryptionKeyValid _gbEncryptionKeyValid;
extern UnkStruct_D_01D6EDD0 D_01D6EDD0;

// 0x0022D3C0
extern "C" void * func_0022D3C0()
{
    void * v0;
    if (_gbEncryptionKeyValid.field_0 != 0) {
        v0 = &D_01D6EDD0;
    } else {
        v0 = 0;
    }
    return v0;
}
