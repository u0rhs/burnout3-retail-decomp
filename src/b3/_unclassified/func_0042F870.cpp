// func_0042F870 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3Profile.h"
#include "b3/classes/UnkStruct_D_0051BF9C.h"

struct UnkStruct_0042F870;

struct UnkStruct_0042F870 {
    unsigned char pad_0[0x39C];
    unsigned char field_39C;
};

extern UnkStruct_D_0051BF9C D_0051BF9C;
extern "C" void func_0013B580(CB3Profile *, unsigned int, unsigned long);
extern "C" void func_0042EE20(UnkStruct_0042F870 *);

// 0x0042F870
// pass1: a1, a2 (callers func_0026E800 / func_003910B0 pass a points value and the 64-bit track id) go to
// func_0013B580(profile, unsigned int, unsigned long) untouched
extern "C" void func_0042F870(UnkStruct_0042F870 * self, unsigned int p0, unsigned long p1)
{
    if (self->field_39C == 0) return;
    self->field_39C = 0;
    CB3Profile * t0 = D_0051BF9C.field_0;
    func_0013B580(t0, p0, p1);
    t0->Evaluate();
    func_0042EE20(self);
}
