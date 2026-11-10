// B3GameMode.cpp -- translation unit regrouped by tools/tu_merge.py from 6 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> B3GameMode.cpp, 2 by a medium-confidence name confirmed by a neighbour.
// Area: src/b3/gamesource/Game, [L] Revenge (SLUS_212.42) GameSource/Game/B4GameMode.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3GameMode.h"

struct UnkStruct_00134600;
struct UnkStruct_00134600_1;
struct UnkStruct_00134600_2;
struct UnkStruct_00134660;
struct UnkStruct_00134660_1;
struct UnkStruct_00134660_2;

struct UnkStruct_00134600_1 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
};

struct UnkStruct_00134600_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
};

struct UnkStruct_00134600 {
    unsigned char pad_0[0x1B4];
    UnkStruct_00134600_2 * field_1B4;
    UnkStruct_00134600_1 * field_1B8;
    unsigned char field_1BC;
};

struct UnkStruct_00134660_1 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
};

struct UnkStruct_00134660_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
};

struct UnkStruct_00134660 {
    unsigned char pad_0[0x1B4];
    UnkStruct_00134660_1 * field_1B4;
    UnkStruct_00134660_2 * field_1B8;
};

struct UnkStruct_00134910 {
    unsigned char pad_0[0x1B4];
    int field_1B4;
    int field_1B8;
    unsigned char field_1BC;
};

// CB3GameMode::GetNumLaps() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3GameMode.cpp.
// 0x001345D0
int CB3GameMode::GetNumLaps()
{
    return 3;
}

// CB3GameMode::StartReplay() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3GameMode.cpp.
// 0x001345E0
int CB3GameMode::StartReplay()
{
    return 0;
}

// func_001345F0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001345F0
extern "C" void func_001345F0()
{
}

// func_00134600 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134600
extern "C" void func_00134600(UnkStruct_00134600 * self)
{
    self->field_1BC = 1;
    UnkStruct_00134600_1 * t0 = self->field_1B8;
    if (t0 != 0) {
        t0->vfunc_10();
    }
    UnkStruct_00134600_2 * t1 = self->field_1B4;
    if (t1 == 0) return;
    t1->vfunc_18();
}

// func_00134660 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134660
extern "C" void func_00134660(UnkStruct_00134660 * self)
{
    UnkStruct_00134660_1 * t0 = self->field_1B4;
    if (t0 != 0) {
        t0->vfunc_10();
    }
    UnkStruct_00134660_2 * t1 = self->field_1B8;
    if (t1 == 0) return;
    t1->vfunc_18();
}

// func_00134910 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134910
extern "C" void func_00134910(UnkStruct_00134910 *self)
{
    self->field_1BC = 1;
    self->field_1B4 = 0;
    self->field_1B8 = 0;
}
