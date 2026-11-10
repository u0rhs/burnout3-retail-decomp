// func_00221420 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (result local initialised to -1 at its declaration instead of assigned in the else arm).

// func_00221420 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00221420;
struct UnkStruct_00221420_a2;

struct UnkStruct_00221420_a2 {
    int field_0;
};

struct UnkStruct_00221420 {
    unsigned char pad_0[0x1C5];
    unsigned char field_1C5;
    unsigned char pad_1C6[0x2];
    int field_1C8;
    unsigned char pad_1CC[0x1C];
    int field_1E8;
    int field_1EC;
    unsigned char pad_1F0[0x34];
    unsigned char field_224;
};

extern "C" void FlushCache__15CGtTextureCacheFv(void *);  // CGtTextureCache::FlushCache()

extern "C" int func_00221420(UnkStruct_00221420 * self, int p0, UnkStruct_00221420_a2 * p1)
{
    int v1 = -1;
    if (p0 != 0) {
        FlushCache__15CGtTextureCacheFv(self);
        if (p1 != 0) {
            p1->field_0 = self->field_1E8;
        }
        v1 = self->field_1EC;
    } else {
        self->field_1C5 = 0;
        self->field_1C8 = 0;
    }
    self->field_224 = p0;
    return v1;
}
