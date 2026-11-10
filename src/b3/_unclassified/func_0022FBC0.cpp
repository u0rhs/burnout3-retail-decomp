// func_0022FBC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0022FBC0;
struct UnkStruct_0022FBC0_e0;
struct UnkStruct_0022FBC0_e1;

struct UnkStruct_0022FBC0_e0 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_0022FBC0_e1 {
    int field_0;
    unsigned char pad_4[0x14];
};

struct UnkStruct_0022FBC0 {
    unsigned char pad_0[0x18];
    UnkStruct_0022FBC0_e0 field_18[1];  // [G] element count unknown
    UnkStruct_0022FBC0_e1 field_30[1];  // [G] element count unknown
    unsigned char pad_48[0x464];
    int field_4AC;
};

// 0x0022FBC0
extern "C" void func_0022FBC0(UnkStruct_0022FBC0 * self, int p0, int p1)
{
    int t0 = self->field_4AC;
    for (int i = 0; (i < t0); i++) {
        if (self->field_18[i].field_14 != p0) {
            continue;
        }
        self->field_30[i].field_0 = p1;
        break;
    }
}
