// func_003C5B40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E8F090.h"
#include "b3/classes/UnkStruct_D_01ECD9F0.h"
#include "b3/classes/UnkStruct_D_01ECDACF.h"

extern UnkStruct_D_01ECDACF D_01ECDACF;
extern UnkStruct_D_01E8F090 D_01E8F090;
extern UnkStruct_D_01ECD9F0 D_01ECD9F0;
extern UnkStruct_D_01E89518 D_01E89518;
extern "C" void func_0044A430(void *);
extern "C" void func_0042F650(void *);
extern "C" void func_0031A9C0(void *, signed char);

// 0x003C5B40
extern "C" void func_003C5B40(void *a0, void *a1 /* passed by every caller, not read here */)
{
    func_0044A430(&D_01E8F090);
    func_0042F650(&D_01ECD9F0);
    func_0031A9C0(&D_01E89518, D_01ECDACF.field_0);
}
