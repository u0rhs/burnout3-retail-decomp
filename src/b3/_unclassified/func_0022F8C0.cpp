// func_0022F8C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0022F8C0;
struct UnkStruct_0022F8C0_e0;
struct UnkStruct_0022F8C0_e1;

struct UnkStruct_0022F8C0_e0 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_0022F8C0_e1 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x10];
};

struct UnkStruct_0022F8C0 {
    unsigned char pad_0[0x258];
    UnkStruct_0022F8C0_e0 field_258[1];  // [G] element count unknown
    UnkStruct_0022F8C0_e1 field_270[1];  // [G] element count unknown
    unsigned char pad_288[0x224];
    int field_4AC;
};

// 0x0022F8C0
extern "C" int func_0022F8C0(UnkStruct_0022F8C0 * self, int p0)
{
    int t0 = self->field_4AC;
    for (int i = 0; (i < t0); i++) {
        if (self->field_258[i].field_14 == p0) {
            return self->field_270[i].field_4;
        }
    }
    return 0;
}
