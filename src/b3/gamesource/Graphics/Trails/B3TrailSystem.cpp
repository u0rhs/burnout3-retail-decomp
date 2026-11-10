// B3TrailSystem.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3TrailSystem.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Graphics/Trails, [L] Revenge (SLUS_212.42) GameSource/Graphics/Trails/B4TrailSystem.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3TrailSystem.h"
#include "b3/classes/UnkStruct_D_004E2D00.h"
#include "b3/classes/UnkStruct_D_004E2D04.h"

struct UnkStruct_002BD7F0_pool {
    unsigned char pad_0[0x130];
};
struct UnkStruct_002BD7F0_el {
    unsigned char pad_0[8];
    unsigned int field_8;
    unsigned int field_C;
    unsigned char pad_10[1];
    signed char field_11;
    unsigned char pad_12[2];
};
struct UnkStruct_002BD7F0_tr {
    void * field_0[128];
    int field_200;
    int field_204;
};
struct UnkStruct_002BD7F0 {
    UnkStruct_002BD7F0_pool field_0[256];
    UnkStruct_002BD7F0_el field_13000[128];
    void * * field_13A00;
    int field_13A04;
    unsigned char pad_13A08[0x13C0C - 0x13A08];
    UnkStruct_002BD7F0_tr field_13C0C[5];
    int field_14634;
    int field_14638;
};

extern UnkStruct_D_004E2D04 D_004E2D04;
extern UnkStruct_D_004E2D00 D_004E2D00;

extern "C" void Construct__16CB3TrailRendererFv(void *);  // CB3TrailRenderer::Construct()
extern "C" void * memset(void *, int, unsigned int);

// CB3TrailSystem::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrailSystem.cpp.
// 0x002BD7E0
void CB3TrailSystem::Release()
{
}

// func_002BD7F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002BD7F0
extern "C" int func_002BD7F0(UnkStruct_002BD7F0 * self)
{
    self->field_13A04 = 0;
    for (int i = 0; i < 128; i++) {
        self->field_13A00[self->field_13A04++] = &self->field_13000[i];
        self->field_13000[i].field_11 = -1;
        self->field_13000[i].field_8 = (unsigned int)&self->field_0[i] | 0x30000000;
        self->field_13000[i].field_C = (unsigned int)&self->field_0[i + 128] | 0x30000000;
    }
    for (int i1 = 0; i1 < 5; i1++) {
        self->field_13C0C[i1].field_200 = 0;
        self->field_13C0C[i1].field_204 = 128;
        memset(self->field_13C0C[i1].field_0, 0, 512);
    }
    self->field_14634 = 0;
    if (self->field_14638 == -1) {
        self->field_14638 = 0;
    }
    return 1;
}

// CB3TrailSystem::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrailSystem.cpp.
// 0x002BD990
void CB3TrailSystem::Destruct()
{
}

// CB3TrailSystem::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrailSystem.cpp.
// 0x002BD9A0
void CB3TrailSystem::Construct()
{
    field_13A08 = 128;
    field_13A00 = ((char *)this + 0x13A0C);
    D_004E2D04.field_0 = 0x2B9D6F8;
    D_004E2D00.field_0 = 0xFD462907;
    field_14638 = -1;
    field_14634 = 0;
    Construct__16CB3TrailRendererFv(this);
}
