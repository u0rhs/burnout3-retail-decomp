// func_0013A280 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (gCalculatedData+0x11C reached through a byte-offset cast to D_0051BFA0's struct type, p0 advanced in place (a20)).

// lifter variant 0
// func_0013A280 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_D_0051BFA0;
struct UnkStruct_gCalculatedData;

struct UnkStruct_D_0051BFA0 {
    unsigned char pad_0[0x128];
    unsigned char field_128[1];  // [G] element count unknown
};

struct UnkStruct_gCalculatedData {
    unsigned char pad_0[0x11C];
    UnkStruct_D_0051BFA0 field_11C;  // [G] same layout as D_0051BFA0 (base +0x11C, then +0x128)
};

extern UnkStruct_D_0051BFA0 D_0051BFA0;
extern UnkStruct_gCalculatedData gCalculatedData;

// 0x0013A280
extern "C" int func_0013A280(void *n0_, int p0)
{
    int n0 = (int)n0_;
    for (p0++; p0 < 10; p0++) {
        if (D_0051BFA0.field_128[p0] == 0) {
            continue;
        }
        if (((UnkStruct_D_0051BFA0 *)((char *)&gCalculatedData + 0x11C))->field_128[p0] != 0) {
            continue;
        }
        return p0;
    }
    return -1;
}
