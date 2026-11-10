// B3PropManager.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3PropManager.cpp, 3 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4PropManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3PropManager.h"
#include "b3/classes/UnkStruct_theMemMgr.h"

struct UnkStruct_002B7230;
struct UnkStruct_002B7230_e0;
struct UnkStruct_002B7290;

struct UnkStruct_002B7230_e0 {
    unsigned short field_0;
    unsigned char field_2;
    unsigned char field_3;
};

struct UnkStruct_002B7230 {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0xC];
    UnkStruct_002B7230_e0 field_1C[1];  // [G] element count unknown
};

struct UnkStruct_002B7290 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    short field_10;
    unsigned char field_12;
    unsigned char pad_13[0x1];
    int field_14;
    int field_18;
};

extern UnkStruct_theMemMgr theMemMgr;
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);

// DynamiseProp__14CB3PropManagerFP7CB3Prop -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002B7230
extern "C" UnkStruct_002B7230_e0 * DynamiseProp__14CB3PropManagerFP7CB3Prop(UnkStruct_002B7230 * self, UnkStruct_002B7230_e0 * p0)
{
    self->field_1C[self->field_C] = *p0;
    UnkStruct_002B7230_e0 * e = &self->field_1C[self->field_C];
    self->field_C++;
    p0->field_3 = 2;
    e->field_3 = 1;
    return e;
}

// func_002B7280 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002B7280
extern "C" void func_002B7280(void *a0 /* passed by every caller, not read here */)
{
}

// Release__14CB3PropManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002B7290
extern "C" void Release__14CB3PropManagerFv(UnkStruct_002B7290 * self)
{
    ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 13, 0);
    self->field_0 = 0;
    self->field_4 = 0;
    self->field_8 = 0;
    self->field_10 = 0;
    self->field_12 = 0;
    self->field_C = 0;
    self->field_18 = 0;
    self->field_14 = 0;
}

// CB3PropManager::Update() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PropManager.cpp.
// 0x002B72F0
void CB3PropManager::Update()
{
}

// CB3PropManager::Construct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PropManager.cpp.
// 0x002B7870
void CB3PropManager::Construct()
{
    field_0 = 0;
    field_4 = 0;
    field_8 = 0;
    field_10 = 0;
    field_12 = 0;
    field_C = 0;
    field_18 = 0;
    field_14 = 0;
}
