// B3CrashCombo.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3CrashCombo.cpp, 3 by a medium-confidence name confirmed by a neighbour, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4CrashCombo.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3CrashCombo.h"
#include "b3/classes/CB3RaceCar.h"
#include "b3/classes/EB3ScoreFinishState.h"

struct UnkStruct_00364270;

struct UnkStruct_00364270 {
    unsigned char pad_0[0x118];
    unsigned char field_118;
    unsigned char pad_119[0x1];
    unsigned char field_11A;
    unsigned char pad_11B[0x219];
    int field_334;
};

extern "C" void UpdateCurrentCombo__13CB3CrashComboFv(void *);  // CB3CrashCombo::UpdateCurrentCombo()

// CB3CrashCombo::OnCrashStop() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3CrashCombo.cpp.
// 0x00363B00
void CB3CrashCombo::OnCrashStop()
{
    field_119 = 1;
}

// func_00364270 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00364270
extern "C" void func_00364270(UnkStruct_00364270 * self)
{
    if (self->field_11A == 0) return;
    self->field_118 = 0;
    UpdateCurrentCombo__13CB3CrashComboFv(self);
    self->field_334 = 0;
}

// CB3CrashCombo::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3CrashCombo.cpp.
// 0x003642B0
void CB3CrashCombo::Release()
{
}

// CB3CrashCombo::Prepare(CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// 0x003642C0
void CB3CrashCombo::Prepare(CB3RaceCar* p0)
{
    field_224 = (CB3RaceCar *)p0;
    field_228 = 0;
    ResetData();
    field_11A = 0;
}

// CB3CrashCombo::Construct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3CrashCombo.cpp.
// 0x003642F0
void CB3CrashCombo::Construct()
{
}
