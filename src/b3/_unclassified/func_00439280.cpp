// func_00439280 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01ECDDA0.h"

struct UnkStruct_00439280;

struct UnkStruct_00439280 {
    unsigned char pad_0[0x40];
    int field_40;
    int field_44;
    int field_48;
};

extern UnkStruct_D_01ECDDA0 D_01ECDDA0;
extern "C" void Construct__10CGt2dSceneFiiiPvUi(void *, int, int, int, void *, unsigned int);  // CGt2dScene::Construct(int,int,int,void*,unsigned int)

// 0x00439280
extern "C" void func_00439280(UnkStruct_00439280 * self)
{
    Construct__10CGt2dSceneFiiiPvUi(self, 1, 1, 0, (void*)&D_01ECDDA0, 240);
    self->field_40 = 0;
    self->field_44 = 0;
    self->field_48 = 0;
}
