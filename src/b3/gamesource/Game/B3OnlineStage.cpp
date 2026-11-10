// B3OnlineStage.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3OnlineStage.cpp, 2 by a medium-confidence name confirmed by a neighbour.
// Area: src/b3/gamesource/Game, [L] Revenge (SLUS_212.42) GameSource/Game/B4OnlineStage.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/UnkStruct_D_00665E52.h"

struct UnkStruct_001353C0;
struct UnkStruct_001353C0_1;
struct UnkStruct_00135A60;

struct UnkStruct_001353B0 {
    unsigned char pad_0[0x1C4];
    int field_1C4;
};

struct UnkStruct_001353C0_1 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual int vfunc_2C();
};

struct UnkStruct_001353C0 {
    unsigned char pad_0[0x1B4];
    UnkStruct_001353C0_1 * field_1B4;
};

struct UnkStruct_00135410 {
    unsigned char pad_0[0x1C8];
    int field_1C8;
};

struct UnkStruct_00135A60 {
    unsigned char pad_0[0x1C8];
    int field_1C8;
};

extern UnkStruct_D_00665E52 D_00665E52;
extern "C" void func_00134910(UnkStruct_00135A60 *);

// func_001353B0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001353B0
extern "C" int func_001353B0(UnkStruct_001353B0 *self)
{
    return self->field_1C4;
}

// func_001353C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001353C0
extern "C" int func_001353C0(UnkStruct_001353C0 * self)
{
    int r0 = self->field_1B4->vfunc_2C();
    if (r0 == 0) {
        return 0;
    }
    D_00665E52.field_0 = 1;
    return 1;
}

// func_00135410 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00135410
extern "C" void func_00135410(UnkStruct_00135410 *self)
{
    self->field_1C8 = 25;
}

// func_00135A60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00135A60
extern "C" void func_00135A60(UnkStruct_00135A60 * self)
{
    func_00134910(self);
    self->field_1C8 = 1;
}
