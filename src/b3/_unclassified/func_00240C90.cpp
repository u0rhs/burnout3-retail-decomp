// func_00240C90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (a77: declaration fix only (p0 is the element-array pointer)).

struct UnkStruct_00240C90_e0 {
    unsigned char pad_0[0x50];
};

struct UnkStruct_00240C90 {
    UnkStruct_00240C90_e0 * field_0;
    int field_4;
};

extern "C" void func_00240E90(void *, int);

// [L] DNAT: low row only, CGtInputManagerPS2Keyboard::Construct(int,int) (research/proto/new_names.csv, sim 0.70, low) - a hint, not applied; retail takes 3 args and loops func_00240E90 over 0x50-byte elements.
// 0x00240C90
extern "C" void func_00240C90(UnkStruct_00240C90 * self, UnkStruct_00240C90_e0 * p0, int p1, void *p2_)
{
    int p2 = (int)p2_;
    self->field_0 = p0;
    self->field_4 = p2;
    for (int i = 0; (i < p1); i++) {
        func_00240E90(&self->field_0[i], p2);
    }
}
