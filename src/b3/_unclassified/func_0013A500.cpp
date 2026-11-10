// func_0013A500 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (gCalculatedData+0x11C through a byte-offset cast to D_0051BFA0's struct type (a23's form), the siblings' loop shape).

struct UnkStruct_D_0051BFA0 {
    unsigned char field_0[67];  // [G] element count from the loop bound
};
struct UnkStruct_gCalculatedData;

extern UnkStruct_D_0051BFA0 D_0051BFA0;
extern UnkStruct_gCalculatedData gCalculatedData;

// 0x0013A500
extern "C" int func_0013A500(void *n0_, int p0)
{
    int n0 = (int)n0_;
    for (p0++; p0 < 67; p0++) {
        if (D_0051BFA0.field_0[p0] != 0 && ((UnkStruct_D_0051BFA0 *)((char *)&gCalculatedData + 0x11C))->field_0[p0] == 0) {
            return p0;
        }
    }
    return -1;
}
