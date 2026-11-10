// func_0045FF40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0045FF40;

struct UnkStruct_0045FF40 {
    unsigned char pad_0[0x14];
    int field_14;
    int field_18;
};

extern "C" unsigned long func_0045FC80(UnkStruct_0045FF40 *);

// 0x0045FF40
// w64 (2026-11-02): returns func_0045FC80's 64-bit result [C retail: v0 from func_0045FC80 reaches the return; func_003EFEC0 uses it].
extern "C" unsigned long func_0045FF40(UnkStruct_0045FF40 * self)
{
    self->field_18 = (self->field_18 + -1);
    if (self->field_18 < 0) {
        self->field_18 = (self->field_14 + -1);
    }
    return func_0045FC80(self);
}
