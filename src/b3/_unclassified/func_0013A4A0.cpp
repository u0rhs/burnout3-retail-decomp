// func_0013A4A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (advance p0 in place; gCalculatedData+0x11C as same struct type as D_0051BFA0 via byte-offset cast (sibling of func_0013A160)).

// lifter variant 0
// func_0013A4A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_D_0051BFA0;
struct UnkStruct_gCalculatedData;

struct UnkStruct_D_0051BFA0 {
    unsigned char pad_0[0x15A];
    unsigned char field_15A[1];  // [G] element count unknown
};

struct UnkStruct_gCalculatedData {
    unsigned char pad_0[0x276];
    unsigned char field_276[1];  // [G] element count unknown
};

extern UnkStruct_D_0051BFA0 D_0051BFA0;
extern UnkStruct_gCalculatedData gCalculatedData;

// 0x0013A4A0
extern "C" int func_0013A4A0(void *n0_, int p0)
{
    int n0 = (int)n0_;
    for (p0++; p0 < 5; p0++) {
        if (D_0051BFA0.field_15A[p0] == 0) {
            continue;
        }
        if (((UnkStruct_D_0051BFA0 *)((char *)&gCalculatedData + 0x11C))->field_15A[p0] != 0) {
            continue;
        }
        return p0;
    }
    return -1;
}
