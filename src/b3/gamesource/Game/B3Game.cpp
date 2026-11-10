// B3Game.cpp -- translation unit regrouped by tools/tu_merge.py from 31 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 6 function(s) named in research/retail_names.csv -> B3Game.cpp, 2 by a medium-confidence name confirmed by a neighbour, 23 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Game, [L] Revenge (SLUS_212.42) GameSource/Game/B4Game.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3Game.h"
#include "b3/classes/CB3StageLogic.h"
#include "b3/classes/CGtLinearMalloc.h"
#include "b3/classes/UnkStruct_D_004EB1E0.h"
#include "b3/classes/UnkStruct_D_0051AEC0.h"
#include "b3/classes/UnkStruct_D_0051B40C.h"
#include "b3/classes/UnkStruct_D_0051B4BC.h"
#include "b3/classes/UnkStruct_D_0051B714.h"

struct UnkStruct_00131CA0;
struct UnkStruct_00131CE0;
struct UnkStruct_00131CE0_1;
struct UnkStruct_00131D20;
struct UnkStruct_00131D20_1;
struct UnkStruct_00131E00;
struct UnkStruct_00131E00_1;
struct UnkStruct_00131F10;
struct UnkStruct_00131F60;

struct UnkStruct_00131CA0 {
    unsigned char pad_0[0x2DA48];
    int field_2DA48;
};

struct UnkStruct_00131CE0_1 {
    unsigned char pad_0[0x1B8];
    int field_1B8;
};

struct UnkStruct_00131CE0 {
    unsigned char pad_0[0x2DA48];
    UnkStruct_00131CE0_1 * field_2DA48;
};

struct UnkStruct_00131D20_1 {
    unsigned char pad_0[0x1B4];
    int field_1B4;
};

struct UnkStruct_00131D20 {
    unsigned char pad_0[0x2DA48];
    UnkStruct_00131D20_1 * field_2DA48;
};

struct UnkStruct_00131E00_1 {
    unsigned char pad_0[0x1B4];
    int field_1B4;
};

struct UnkStruct_00131E00 {
    unsigned char pad_0[0x2DA48];
    UnkStruct_00131E00_1 * field_2DA48;
};

struct UnkStruct_00131F10 {
    unsigned char pad_0[0x2DA4C];
    int field_2DA4C;
    unsigned char pad_2DA50[0x3C];
    int field_2DA8C;
    int field_2DA90;
};

struct UnkStruct_00131F60 {
    unsigned char pad_0[0x2DA94];
    unsigned char field_2DA94;
};

struct UnkStruct_001344D0_game {
    unsigned char pad_0[0x2C668];
    unsigned char field_2C668[0x1B0];
    const void * field_2C818;
    unsigned char pad_2C81C[0x164];
    unsigned char field_2C980[4];
};

extern UnkStruct_D_0051AEC0 D_0051AEC0;
extern UnkStruct_D_0051B40C D_0051B40C;
extern UnkStruct_D_0051B4BC D_0051B4BC;
extern UnkStruct_D_0051B714 D_0051B714;
extern UnkStruct_D_004EB1E0 D_004EB1E0;
extern char __vt__11CB3FrontEnd[];

// func_00131CA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00131CA0
extern "C" int func_00131CA0(UnkStruct_00131CA0 * self)
{
    if ((self->field_2DA48 == 0) || (self->field_2DA48 != (int)&D_0051AEC0)) {
        return 0;
    }
    return 1;
}

// func_00131CE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00131CE0
extern "C" int func_00131CE0(UnkStruct_00131CE0 * self)
{
    if ((self->field_2DA48 == 0) || (self->field_2DA48->field_1B8 != (int)((char *)self + 0x2D8E8))) {
        return 0;
    }
    return 1;
}

// func_00131D20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00131D20
extern "C" int func_00131D20(UnkStruct_00131D20 * self)
{
    if (self->field_2DA48 == 0) {
        return 0;
    }
    if (((self->field_2DA48->field_1B4 == (int)&D_0051B40C) || (self->field_2DA48->field_1B4 == (int)&D_0051B4BC)) || (self->field_2DA48->field_1B4 == (int)&D_0051B714)) {
        return 1;
    }
    return 0;
}

// func_00131DF0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00131DF0
extern "C" int func_00131DF0()
{
    return 0;
}

// func_00131E00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00131E00
extern "C" int func_00131E00(UnkStruct_00131E00 * self)
{
    if ((self->field_2DA48 == 0) || (self->field_2DA48->field_1B4 != (int)((char *)self + 0x2D2B0))) {
        return 0;
    }
    return 1;
}

// func_00131F10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00131F10
extern "C" void func_00131F10(UnkStruct_00131F10 * self, int p0)
{
    if (self->field_2DA90 == 5) {
        self->field_2DA4C = p0;
        self->field_2DA8C = 6;
    }
}

// func_00131F60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00131F60
extern "C" bool func_00131F60(UnkStruct_00131F60 * self)
{
    bool v0 = ((self->field_2DA94 != 0) && (D_004EB1E0.field_0 != 0));
    return (!v0);
}

// func_00133180 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00133180
extern "C" void func_00133180()
{
}

// func_00134260 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134260
extern "C" int func_00134260()
{
    return 15;
}

// func_00134290 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134290
extern "C" int func_00134290()
{
    return 1;
}

// func_001342A0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001342A0
extern "C" int func_001342A0()
{
    return 1;
}

// func_001342E0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001342E0
extern "C" int func_001342E0()
{
    return 0;
}

// func_00134370 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134370
extern "C" int func_00134370()
{
    return 0;
}

// func_00134380 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134380
extern "C" void func_00134380()
{
}

// func_00134390 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134390
extern "C" void func_00134390()
{
}

// func_001343A0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001343A0
extern "C" void func_001343A0()
{
}

// func_001343D0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001343D0
extern "C" int func_001343D0()
{
    return 0;
}

// func_001343F0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001343F0
extern "C" int func_001343F0()
{
    return 0;
}

// func_00134400 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134400
extern "C" int func_00134400()
{
    return 0;
}

// func_00134410 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134410
extern "C" int func_00134410()
{
    return 0;
}

// func_00134420 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134420
extern "C" void func_00134420()
{
}

// func_00134430 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134430
extern "C" void func_00134430()
{
}

// func_00134440 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134440
extern "C" void func_00134440()
{
}

// func_00134450 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134450
extern "C" int func_00134450()
{
    return 0;
}

// func_00134460 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134460
extern "C" int func_00134460()
{
    return 0;
}

// func_00134470 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134470
extern "C" void func_00134470()
{
}

// func_00134480 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134480
extern "C" void func_00134480()
{
}

// func_00134490 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00134490
extern "C" int func_00134490()
{
    return 0;
}

// CB3StageLogic::AllResultsAreIn() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3Game.cpp.
// 0x001344B0
int CB3StageLogic::AllResultsAreIn()
{
    return 0;
}

// CB3StageLogic::GetNumRoundsPlayed() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3Game.cpp.
// 0x001344C0
int CB3StageLogic::GetNumRoundsPlayed()
{
    return 0;
}

// CB3Game::~CB3Game() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Game.cpp.
extern "C" CGtLinearMalloc * __dt__15CGtLinearMallocFv(CGtLinearMalloc *, short);
extern "C" void func_001003A0(void *);
extern "C" CB3Game * __dt__7CB3GameFv ( CB3Game * self0 , short flag );

// 0x001344D0
CB3Game *__dt__7CB3GameFv(CB3Game *self0, short flag)
{
  UnkStruct_001344D0_game *self = (UnkStruct_001344D0_game *) self0;
  if (self != 0)
  {
    if (self->field_2C668)
    {
      self->field_2C818 = __vt__11CB3FrontEnd;
      __dt__15CGtLinearMallocFv((CGtLinearMalloc *) self->field_2C980, -1);
    }
    if (flag > 0)
    {
      func_001003A0(self);
    }
  }
  return self0;
}
