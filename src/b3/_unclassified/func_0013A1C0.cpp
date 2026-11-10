// func_0013A1C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (gCalculatedData+0x11C through a byte-offset cast to D_0051BFA0's struct type (a23's form) on a24's best source).

// lifter variant 0
// func_0013A1C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_D_0051BFA0;
struct UnkStruct_gCalculatedData;

struct UnkStruct_D_0051BFA0 {
    unsigned char pad_0[0x13C];
    unsigned char field_13C[1];  // [G] element count unknown
};

struct UnkStruct_gCalculatedData {
    unsigned char pad_0[0x11C];
    UnkStruct_D_0051BFA0 field_11C;  // [G] same layout as D_0051BFA0 (both index +0x13C)
};

extern UnkStruct_D_0051BFA0 D_0051BFA0;
extern UnkStruct_gCalculatedData gCalculatedData;

extern "C" int func_0013A1C0(void *n0_, int p0)
{
    int n0 = (int)n0_;
    for (p0++; p0 < 20; p0++) {
        if (D_0051BFA0.field_13C[p0] != 0 && ((UnkStruct_D_0051BFA0 *)((char *)&gCalculatedData + 0x11C))->field_13C[p0] == 0) {
            return p0;
        }
    }
    return -1;
}
