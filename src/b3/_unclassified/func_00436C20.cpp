// func_00436C20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2F5C.h"
#include "b3/classes/UnkStruct_D_01E90438.h"
#include "b3/classes/UnkStruct_D_01ECD520.h"

struct UnkStruct_00436C20;

struct UnkStruct_00436C20 {
    unsigned char pad_0[0x4];
    int field_4;
};

extern UnkStruct_D_004E2F5C D_004E2F5C;
extern UnkStruct_D_01E90438 D_01E90438;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_004365B0(UnkStruct_00436C20 *, int);
extern "C" void StartLoadProfileFlow__24CB3MemCardControllerBaseFv(void *);

// 0x00436C20
extern "C" int func_00436C20(UnkStruct_00436C20 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    int r1 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 256);
    D_004E2F5C.field_0 = r1;
    self->field_4 = 0;
    func_004365B0(self, 0);
    StartLoadProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
    return 1;
}
