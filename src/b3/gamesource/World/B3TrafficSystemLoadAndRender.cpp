// B3TrafficSystemLoadAndRender.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 0 function(s) named in research/retail_names.csv -> B3TrafficSystemLoadAndRender.cpp, 4 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4TrafficSystemLoadAndRender.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

struct UnkStruct_00308FE0;
struct UnkStruct_00308FE0_a1;
struct UnkStruct_00309010;
struct UnkStruct_00309010_a1;
struct UnkStruct_00309040;
struct UnkStruct_00309040_a1;
struct UnkStruct_00309070;
struct UnkStruct_00309070_a1;

struct UnkStruct_00308FE0_a1 {
    unsigned char pad_0[0xC];
    int field_C;
};
struct UnkStruct_00308FE0 {
    unsigned char pad_0[0xC];
    int field_C;
};
struct UnkStruct_00309010_a1 {
    unsigned char pad_0[0x9];
    signed char field_9;
};
struct UnkStruct_00309010 {
    unsigned char pad_0[0x9];
    signed char field_9;
};
struct UnkStruct_00309040_a1 {
    unsigned char pad_0[0x4];
    float field_4;
};
struct UnkStruct_00309040 {
    unsigned char pad_0[0x4];
    float field_4;
};
struct UnkStruct_00309070_a1 {
    unsigned char pad_0[0x4];
    float field_4;
};
struct UnkStruct_00309070 {
    unsigned char pad_0[0x4];
    float field_4;
};

// func_00308FE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00308FE0
extern "C" int func_00308FE0(UnkStruct_00308FE0 * self, UnkStruct_00308FE0_a1 * p0)
{
    int v0;
    if ((unsigned int)self->field_C < (unsigned int)p0->field_C) {
        v0 = -1;
    } else {
        v0 = 1;
    }
    return v0;
}

// func_00309010 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00309010
extern "C" int func_00309010(UnkStruct_00309010 * self, UnkStruct_00309010_a1 * p0)
{
    int v0;
    if (self->field_9 < p0->field_9) {
        v0 = -1;
    } else {
        v0 = 1;
    }
    return v0;
}

// func_00309040 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00309040
extern "C" int func_00309040(UnkStruct_00309040 * self, UnkStruct_00309040_a1 * p0)
{
    int v0;
    if (self->field_4 < p0->field_4) {
        v0 = -1;
    } else {
        v0 = 1;
    }
    return v0;
}

// func_00309070 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00309070
extern "C" int func_00309070(UnkStruct_00309070 * self, UnkStruct_00309070_a1 * p0)
{
    int v0;
    if (self->field_4 < p0->field_4) {
        v0 = -1;
    } else {
        v0 = 1;
    }
    return v0;
}
