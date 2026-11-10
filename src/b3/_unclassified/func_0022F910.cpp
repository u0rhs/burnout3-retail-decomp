// func_0022F910 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0022F910;
struct UnkStruct_0022F910_e0;
struct UnkStruct_0022F910_e1;

struct UnkStruct_0022F910_e0 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_0022F910_e1 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x10];
};

struct UnkStruct_0022F910 {
    unsigned char pad_0[0x18];
    UnkStruct_0022F910_e0 field_18[1];  // [G] element count unknown
    UnkStruct_0022F910_e1 field_30[1];  // [G] element count unknown
    unsigned char pad_48[0x464];
    int field_4AC;
};

// 0x0022F910
extern "C" int func_0022F910(UnkStruct_0022F910 * self, int p0)
{
    int t0 = self->field_4AC;
    for (int i = 0; (i < t0); i++) {
        if (self->field_18[i].field_14 == p0) {
            return self->field_30[i].field_4;
        }
    }
    return 0;
}
