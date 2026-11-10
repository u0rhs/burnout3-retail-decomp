// func_00421000 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004F5040.h"
#include "b3/classes/UnkStruct_D_01EBE3B0.h"

struct UnkStruct_00421000;

struct UnkStruct_00421000 {
    int field_0;
};

extern UnkStruct_D_01EBE3B0 D_01EBE3B0;
extern UnkStruct_D_004F5040 D_004F5040;
extern "C" void func_00421850(void *, int);
extern "C" void func_0021B5E0(void *);
extern "C" void func_0021B4E0(void *);

// 0x00421000
extern "C" void func_00421000(UnkStruct_00421000 * self, int p0)
{
    func_00421850(&D_01EBE3B0, p0);
    func_0021B5E0(&D_004F5040);
    func_0021B4E0(&D_004F5040);
    self->field_0 = p0;
}
