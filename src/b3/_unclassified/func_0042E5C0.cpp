// func_0042E5C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01ECD520.h"

extern UnkStruct_D_01ECD520 D_01ECD520;
extern "C" void OnMemCardPageExit__24CB3MemCardControllerBaseFv(void *);

// 0x0042E5C0
extern "C" void func_0042E5C0()
{
    OnMemCardPageExit__24CB3MemCardControllerBaseFv(&D_01ECD520);
}
