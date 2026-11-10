// Release__26CB3OnlineRoadRageRaceLogicFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051BAA8.h"

struct UnkStruct_0038F720;

struct UnkStruct_0038F720 {
    unsigned char pad_0[0x60];
    int field_60;
};

extern UnkStruct_D_0051BAA8 D_0051BAA8;
extern "C" void func_00392250(UnkStruct_0038F720 *);

// 0x0038F720
extern "C" void Release__26CB3OnlineRoadRageRaceLogicFv(UnkStruct_0038F720 * self)
{
    self->field_60 = 0;
    D_0051BAA8.field_0 = 1;
    func_00392250(self);
}
