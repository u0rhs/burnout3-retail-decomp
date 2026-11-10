// func_0013AA10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (outer switch on p1, inner if/else-if/else chain on p0 assigning one v (sibling of func_0013A8A0)).

// lifter variant 0
// func_0013AA10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_gCalculatedData;

struct UnkStruct_gCalculatedData {
    unsigned char pad_0[0x54];
    int field_54[1];  // [G] element count unknown
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    unsigned char pad_68[0x58];
    int field_C0[1];  // [G] element count unknown
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4[1];  // [G] element count unknown
    int field_D8;
    int field_DC;
    int field_E0;
    int field_E4;
};

extern UnkStruct_gCalculatedData gCalculatedData;

// 0x0013AA10
extern "C" int func_0013AA10(void *n0_, int p0, int p1)
{
    int n0 = (int)n0_;
    int v;
    switch (p1) {
    case 1:
        if (p0 == 0) {
            v = gCalculatedData.field_D0 - gCalculatedData.field_CC - gCalculatedData.field_C8 - gCalculatedData.field_C4;
        } else if (p0 == 4) {
            v = gCalculatedData.field_D0;
        } else {
            v = gCalculatedData.field_C0[p0];
        }
        break;
    case 2:
        if (p0 == 0) {
            v = gCalculatedData.field_E4 - gCalculatedData.field_E0 - gCalculatedData.field_DC - gCalculatedData.field_D8;
        } else if (p0 == 4) {
            v = gCalculatedData.field_E4;
        } else {
            v = gCalculatedData.field_D4[p0];
        }
        break;
    default:
        if (p0 == 0) {
            v = gCalculatedData.field_64 - gCalculatedData.field_60 - gCalculatedData.field_5C - gCalculatedData.field_58;
        } else if (p0 == 4) {
            v = gCalculatedData.field_64;
        } else {
            v = gCalculatedData.field_54[p0];
        }
        break;
    }
    return v;
}
