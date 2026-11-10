// func_0013A8A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (outer switch on p1, inner if/else-if/else chain on p0 assigning one v (not a nested switch)).

// lifter variant 0
// func_0013A8A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_gCalculatedData;

struct UnkStruct_gCalculatedData {
    unsigned char pad_0[0x68];
    int field_68[1];  // [G] element count unknown
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    unsigned char pad_7C[0x6C];
    int field_E8[1];  // [G] element count unknown
    int field_EC;
    int field_F0;
    int field_F4;
    int field_F8;
    int field_FC[1];  // [G] element count unknown
    int field_100;
    int field_104;
    int field_108;
    int field_10C;
};

extern UnkStruct_gCalculatedData gCalculatedData;

// 0x0013A8A0
extern "C" int func_0013A8A0(void *n0_, int p0, int p1)
{
    int n0 = (int)n0_;
    int v;
    switch (p1) {
    case 1:
        if (p0 == 0) {
            v = gCalculatedData.field_F8 - gCalculatedData.field_F4 - gCalculatedData.field_F0 - gCalculatedData.field_EC;
        } else if (p0 == 4) {
            v = gCalculatedData.field_F8;
        } else {
            v = gCalculatedData.field_E8[p0];
        }
        break;
    case 2:
        if (p0 == 0) {
            v = gCalculatedData.field_10C - gCalculatedData.field_108 - gCalculatedData.field_104 - gCalculatedData.field_100;
        } else if (p0 == 4) {
            v = gCalculatedData.field_10C;
        } else {
            v = gCalculatedData.field_FC[p0];
        }
        break;
    default:
        if (p0 == 0) {
            v = gCalculatedData.field_78 - gCalculatedData.field_74 - gCalculatedData.field_70 - gCalculatedData.field_6C;
        } else if (p0 == 4) {
            v = gCalculatedData.field_78;
        } else {
            v = gCalculatedData.field_68[p0];
        }
        break;
    }
    return v;
}
