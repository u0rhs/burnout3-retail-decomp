// func_0022FC10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0022FC10;
struct UnkStruct_0022FC10_e0;

struct UnkStruct_0022FC10_e0 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_0022FC10 {
    unsigned char pad_0[0x18];
    UnkStruct_0022FC10_e0 field_18[1];  // [G] element count unknown
    unsigned char pad_30[0x47C];
    int field_4AC;
};

// 0x0022FC10
extern "C" int func_0022FC10(UnkStruct_0022FC10 * self, int p0)
{
    int t0 = self->field_4AC;
    for (int i = 0; (i < t0); i++) {
        if (self->field_18[i].field_14 == p0) {
            return 1;
        }
    }
    return 0;
}
