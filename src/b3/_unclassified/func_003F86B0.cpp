// func_003F86B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (self is const (lw hoisted above sd ra); field_160 a pointer; && chain with early return 1).

struct UnkStruct_003F86B0 {
    unsigned char pad_0[0x160];
    void * field_160;
};
extern "C" int func_00386010(void *);
// 0x003F86B0
extern "C" int func_003F86B0(const UnkStruct_003F86B0 * self)
{
    if (self->field_160 != 0 && func_00386010(self->field_160) != 0) return 1;
    return 0;
}
