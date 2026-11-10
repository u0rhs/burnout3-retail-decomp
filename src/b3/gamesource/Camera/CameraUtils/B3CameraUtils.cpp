// B3CameraUtils.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 0 function(s) named in research/retail_names.csv -> B3CameraUtils.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Camera/CameraUtils, [L] Revenge (SLUS_212.42) GameSource/Camera/CameraUtils/B4CameraUtils.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

struct UnkStruct_002F72A0;
struct UnkStruct_002F72A0_1;
struct UnkStruct_002F72A0_a1;

struct UnkStruct_002F72A0_1 {
    unsigned char pad_0[0x4];
    unsigned short field_4;
};
struct UnkStruct_002F72A0_a1 {
    float field_0;
};
struct UnkStruct_002F72A0 {
    unsigned char pad_0[0x50];
    float field_50;
    unsigned char pad_54[0xC];
    UnkStruct_002F72A0_1 * field_60;
};

// func_002F72A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002F72A0
extern "C" int func_002F72A0(UnkStruct_002F72A0 * self, UnkStruct_002F72A0_a1 * p0)
{
    unsigned short t1 = self->field_60->field_4;
    switch (t1 & 255) {
    case 32:
    case 36:
    case 35:
    case 34:
        return 1;
    }
    float t2 = self->field_50;
    float t3 = p0->field_0;
    if (t2 < t3) {
        if (((t1 & 0x800) ? true : false) && t3 - t2 < 0.5f) { p0->field_0 = t2; return 1; }
        if (((t1 & 0x400) ? true : false) && t3 - t2 < 10.0f) { p0->field_0 = t2; return 1; }
        if (!(((t1 & 0x400) ? true : false)) && !(((t1 & 0x800) ? true : false))) p0->field_0 = t2;
    }
    return 1;
}
