// _CalculateUV__15CB3MenuImageUVsFffffffUi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (16-byte struct returned by value (hidden a0); flag swaps with temps; division order brute-forced).

// lifter variant 0
// _CalculateUV__15CB3MenuImageUVsFffffffUi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003713A0;
struct UnkStruct_003713A0_1;

struct UnkStruct_003713A0_1 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};

struct UnkStruct_003713A0 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};

// 0x003713A0
extern "C" UnkStruct_003713A0 _CalculateUV__15CB3MenuImageUVsFffffffUi(int p0, float f0, float f1, float f2, float f3, float f4, float f5)
{
    float y0 = f1 / f5;
    float y1 = (f1 + f3) / f5;
    float x0 = f0 / f4;
    float x1 = (f0 + f2) / f4;
    if ((p0 & 1) != 0) {
        float t = x0;
        x0 = x1;
        x1 = t;
    }
    if ((p0 & 2) != 0) {
        float t = y0;
        y0 = y1;
        y1 = t;
    }
    UnkStruct_003713A0 r;
    r.field_0 = x0;
    r.field_4 = y0;
    r.field_8 = x1;
    r.field_C = y1;
    return r;
}
