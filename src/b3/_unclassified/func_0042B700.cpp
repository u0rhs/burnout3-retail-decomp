// func_0042B700 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (merged && / || mode test, early returns).

// lifter variant 0
// func_0042B700 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3MenuCarClasses {};

class CB3VehicleList;
struct UnkStruct_0042B700;
struct UnkStruct_0042B700_e0;
struct UnkStruct_0042B700_e1;

class CB3VehicleList {
public:
    unsigned long GetCarID(EB3MenuCarClasses, int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0042B700_e0 {
    unsigned char pad_0[0x4];
    signed char field_4;
    signed char field_5;
    unsigned char pad_6[0x6];
};

struct UnkStruct_0042B700_e1 {
    unsigned char pad_0[0x4];
    signed char field_4;
    signed char field_5;
    unsigned char pad_6[0x6];
};

struct UnkStruct_0042B700 {
    unsigned char pad_0[0xC];
    UnkStruct_0042B700_e0 field_C[1];  // [G] element count unknown
    unsigned char pad_18[0xE4];
    UnkStruct_0042B700_e1 field_FC[1];  // [G] element count unknown
    unsigned char pad_108[0x12C];
    int field_234;
    int field_238;
    unsigned char pad_23C[0xC];
    int field_248;
    int field_24C;
};

extern CB3VehicleList D_005186A0;

// 0x0042B700
extern "C" unsigned long func_0042B700(UnkStruct_0042B700 * self, int p0)
{
    if (self->field_234 == 4 && (self->field_238 == 3 || self->field_238 == 4)) {
        if (p0 < self->field_24C) {
            return D_005186A0.GetCarID((EB3MenuCarClasses)self->field_FC[p0].field_5, self->field_FC[p0].field_4);
        }
        return 0;
    }
    if (p0 < self->field_248) {
        return D_005186A0.GetCarID((EB3MenuCarClasses)self->field_C[p0].field_5, self->field_C[p0].field_4);
    }
    return 0;
}
