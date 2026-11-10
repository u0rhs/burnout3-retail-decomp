// func_00420FD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01EBE3B0.h"

extern UnkStruct_D_01EBE3B0 D_01EBE3B0;
extern "C" void func_00421850(void *, int);

// 0x00420FD0
// pass1: forwards its own entry register(s) untouched to the callee, which reads them (retail live-in)
extern "C" void func_00420FD0(void *self, int p1)  // self (a0) unread
{
    func_00421850(&D_01EBE3B0, p1);
}
