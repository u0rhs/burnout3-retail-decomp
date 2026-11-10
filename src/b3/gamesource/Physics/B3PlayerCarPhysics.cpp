// B3PlayerCarPhysics.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 0 function(s) named in research/retail_names.csv -> B3PlayerCarPhysics.cpp, 1 by a medium-confidence name confirmed by a neighbour, 2 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Physics, same unit as the hand-placed file there (its docs/layout.md row).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3ScoreBonus.h"
#include "b3/classes/CB3StageLogic.h"
#include "b3/classes/EB3ScoreMedalType.h"
#include "b3/classes/EScoreBonusEvent.h"
#include "b3/classes/UnkStruct_D_01E7A800.h"

struct UnkStruct_001BAD00;
struct UnkStruct_001BAD00_1;
struct UnkStruct_001BB6B0;
struct UnkStruct_001BB6B0_1;

struct UnkStruct_001BAD00_1 {
    unsigned char pad_0[0x11E4];
    CB3ScoreBonus field_11E4;
};

struct UnkStruct_001BAD00 {
    unsigned char pad_0[0x13F4];
    UnkStruct_001BAD00_1 * field_13F4;
    unsigned char pad_13F8[0x318E];
    unsigned char field_4586;
};

struct UnkStruct_001BB6B0_1 {
    unsigned char pad_0[0x1161];
    unsigned char field_1161;
};

struct UnkStruct_001BB6B0 {
    unsigned char pad_0[0x1353];
    unsigned char field_1353;
    unsigned char pad_1354[0xA0];
    UnkStruct_001BB6B0_1 * field_13F4;
};

extern UnkStruct_D_01E7A800 D_01E7A800;
extern "C" void func_00284B20(void *);

// func_001BAD00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001BAD00
extern "C" void func_001BAD00(UnkStruct_001BAD00 * self)
{
    self->field_4586 = 1;
    self->field_13F4->field_11E4.OnEvent((EScoreBonusEvent)207, 0, -1, 1);
    func_00284B20(&D_01E7A800);
}

// func_001BB6B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001BB6B0
extern "C" void func_001BB6B0(UnkStruct_001BB6B0 * self)
{
    if (self->field_13F4->field_1161 != 0) {
        self->field_1353 = (self->field_1353 | 2);
    }
}

// CB3StageLogic::IsCrashType() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3PlayerCarPhysics.cpp.
// 0x001BD630
int CB3StageLogic::IsCrashType()
{
    return 0;
}
