// func_00442510 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (p0 is a byte (sb without andi) and is passed on to vfunc_C (missing call argument)).

// lifter variant 0
// func_00442510 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00442510;
struct UnkStruct_00442510_2;

struct UnkStruct_00442510_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C(unsigned char);
};

struct UnkStruct_00442510 {
    UnkStruct_00442510_2 * field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x40];
    unsigned char field_44;
};

// 0x00442510
extern "C" void func_00442510(UnkStruct_00442510 * self, unsigned char p0)
{
    self->field_44 = p0;
    for (int i = 0; (i < 2); i++) {
        UnkStruct_00442510_2 * t0 = self->field_0[i];
        if (t0 != 0) {
            t0->vfunc_C(p0);
        }
    }
}
