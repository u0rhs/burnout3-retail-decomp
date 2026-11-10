// B3ScrapeSystem.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 0 function(s) named in research/retail_names.csv -> B3ScrapeSystem.cpp, 3 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Graphics/Scrapes, [L] Revenge (SLUS_212.42) GameSource/Graphics/Scrapes/B4ScrapeSystem.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

struct UnkStruct_00375D90;
struct UnkStruct_00375D90_e1;

struct UnkStruct_00375D90_e1 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x444];
};
struct UnkStruct_00375D90 {
    UnkStruct_00375D90_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_450[0x85B0];
    void * * field_8A00;
    int field_8A04;
    unsigned char pad_8A08[0x104];
    int field_8B0C;
    int field_8B10;
    int field_8B14;
};

extern "C" void * memset(void *, int, unsigned int);

// func_00375D80 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00375D80
extern "C" void func_00375D80(void *a0 /* passed by every caller, not read here */)
{
}

// Prepare__15CB3ScrapeSystemFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00375D90
extern "C" int Prepare__15CB3ScrapeSystemFv(UnkStruct_00375D90 * self)
{
    self->field_8A04 = 0;
    for (int i = 0; (i < 32); i++) {
        self->field_8A00[self->field_8A04++] = &self->field_0[i];
        self->field_0[i].field_8 = -1;
    }
    self->field_8B0C = 0;
    self->field_8B10 = 32;
    memset(((char *)self + 0x8A8C), 0, 128);
    if (self->field_8B14 == -1) {
        self->field_8B14 = 0;
    }
    return 1;
}

// func_00375E80 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00375E80
extern "C" void func_00375E80(void *a0 /* passed by every caller, not read here */)
{
}
