// func_0013A220 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (gCalculatedData+0x11C through a byte-offset cast to D_0051BFA0's struct type (a23's form) on a19's best source).

struct UnkStruct_0013A220_s {
    unsigned char pad_0[0x132];
    unsigned char field_132[10];  // [G] element count: loop bound
};

struct UnkStruct_gCalculatedData {
    unsigned char pad_0[0x11C];
    UnkStruct_0013A220_s field_11C;
};

extern UnkStruct_0013A220_s D_0051BFA0;
extern UnkStruct_gCalculatedData gCalculatedData;

// 0x0013A220
extern "C" int func_0013A220(void *n0_, int p0)
{
    int n0 = (int)n0_;
    for (p0++; p0 < 10; p0++) {
        if (D_0051BFA0.field_132[p0] != 0 && ((UnkStruct_0013A220_s *)((char *)&gCalculatedData + 0x11C))->field_132[p0] == 0) {
            return p0;
        }
    }
    return -1;
}
