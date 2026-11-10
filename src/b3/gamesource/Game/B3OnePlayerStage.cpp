// B3OnePlayerStage.cpp -- translation unit regrouped by tools/tu_merge.py from 7 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3OnePlayerStage.cpp, 4 by a medium-confidence name confirmed by a neighbour, 2 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Game, [L] Revenge (SLUS_212.42) GameSource/Game/B4OnePlayerStage.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/UnkStruct_D_00516DF0.h"
#include "b3/classes/UnkStruct_D_00516E10.h"
#include "b3/classes/UnkStruct_D_00516E14.h"
#include "b3/classes/UnkStruct_D_00516E34.h"
#include "b3/classes/UnkStruct_D_0051BAA5.h"
#include "b3/classes/UnkStruct_D_0051BAA8.h"
#include "b3/classes/UnkStruct_D_00665E52.h"
#include "b3/classes/UnkStruct_theMemMgr.h"

struct UnkStruct_00134940;
struct UnkStruct_00134940_1;

struct UnkStruct_00134940_1 {
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

struct UnkStruct_00134940 {
    unsigned char pad_0[0x1B4];
    UnkStruct_00134940_1 * field_1B4;
};

extern UnkStruct_D_00665E52 D_00665E52;
extern UnkStruct_D_00516E10 D_00516E10;
extern UnkStruct_D_00516E34 D_00516E34;
extern UnkStruct_D_0051BAA8 D_0051BAA8;
extern UnkStruct_D_0051BAA5 D_0051BAA5;
extern UnkStruct_D_00516DF0 D_00516DF0;
extern UnkStruct_D_00516E14 D_00516E14;
extern UnkStruct_theMemMgr theMemMgr;
extern "C" void func_001345F0();
extern "C" void func_00134600(int);
extern "C" void func_00135A90(void *);
extern "C" void func_003E8750(void *);
extern "C" void func_00134910();

// func_00134940 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134940
extern "C" int func_00134940(UnkStruct_00134940 * self)
{
    int r0 = self->field_1B4->vfunc_2C();
    if (r0 == 0) {
        return 0;
    }
    D_00665E52.field_0 = 1;
    return 1;
}

// func_00134990 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134990
extern "C" void func_00134990()
{
    func_001345F0();
}

// func_001349A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001349A0
extern "C" void func_001349A0(int n0)
{
    func_00134600(n0);
    D_00665E52.field_0 = 0;
    D_00516E10.field_0 = 1;
    func_00135A90(&D_00516DF0);
    D_00516E34.field_0 = 1;
    func_00135A90(&D_00516E14);
    D_0051BAA8.field_0 = 1;
    D_0051BAA5.field_0 = 0;
    func_003E8750(&theMemMgr);
}

// func_00134DD0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134DD0
extern "C" int func_00134DD0()
{
    return 0;
}

// func_00134DE0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134DE0
extern "C" void func_00134DE0()
{
}

// func_00135170 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00135170
extern "C" int func_00135170()
{
    return 1;
}

// func_001353A0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001353A0
extern "C" void func_001353A0()
{
    func_00134910();
}
