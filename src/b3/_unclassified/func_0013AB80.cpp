// func_0013AB80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (outer switch on p1, inner if/else-if/else chain on p0 assigning one v (sibling of func_0013A8A0)).

// lifter variant 0
// func_0013AB80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_gCalculatedData;

struct UnkStruct_gCalculatedData {
    unsigned char pad_0[0x40];
    int field_40[1];  // [G] element count unknown
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    unsigned char pad_54[0x44];
    int field_98[1];  // [G] element count unknown
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC[1];  // [G] element count unknown
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
};

extern UnkStruct_gCalculatedData gCalculatedData;

// 0x0013AB80
extern "C" int func_0013AB80(void *n0_, int p0, int p1)
{
    int n0 = (int)n0_;
    int v;
    switch (p1) {
    case 1:
        if (p0 == 0) {
            v = gCalculatedData.field_A8 - gCalculatedData.field_A4 - gCalculatedData.field_A0 - gCalculatedData.field_9C;
        } else if (p0 == 4) {
            v = gCalculatedData.field_A8;
        } else {
            v = gCalculatedData.field_98[p0];
        }
        break;
    case 2:
        if (p0 == 0) {
            v = gCalculatedData.field_BC - gCalculatedData.field_B8 - gCalculatedData.field_B4 - gCalculatedData.field_B0;
        } else if (p0 == 4) {
            v = gCalculatedData.field_BC;
        } else {
            v = gCalculatedData.field_AC[p0];
        }
        break;
    default:
        if (p0 == 0) {
            v = gCalculatedData.field_50 - gCalculatedData.field_4C - gCalculatedData.field_48 - gCalculatedData.field_44;
        } else if (p0 == 4) {
            v = gCalculatedData.field_50;
        } else {
            v = gCalculatedData.field_40[p0];
        }
        break;
    }
    return v;
}
