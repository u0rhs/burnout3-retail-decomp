// func_003ED450 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01ECD520.h"

extern UnkStruct_D_01ECD520 D_01ECD520;
extern "C" void OnMemCardPageExit__24CB3MemCardControllerBaseFv(void *);

// 0x003ED450
extern "C" void func_003ED450()
{
    OnMemCardPageExit__24CB3MemCardControllerBaseFv(&D_01ECD520);
}
