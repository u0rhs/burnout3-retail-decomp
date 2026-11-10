// func_00442470 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bool return; nonnull bool before an inline index-check bool; slot test as a bool temp with early return; phantom 3rd vfunc_10 arg dropped).

// lifter variant 0
// func_00442470 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00442470;
struct UnkStruct_00442470_a1;

struct UnkStruct_00442470_a1 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(UnkStruct_00442470 *, int);  // [G] a3 at the call is only self left over
};

struct UnkStruct_00442470 {
    void * field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x3C];
    int field_40;
};

// [G] an inlined index check (real name unknown, placeholder): its merged true/false give retail's daddiu 1 + andi
static inline bool func_00442470_inl0(int i)
{
    return i >= 0 && i < 2;
}

// 0x00442470
extern "C" bool func_00442470(UnkStruct_00442470 * self, UnkStruct_00442470_a1 * p0, int p1)
{
    bool nonnull = p0 != 0;
    bool valid = func_00442470_inl0(p1);
    if (nonnull == false || valid == false) {
        return false;
    }
    bool fr = self->field_0[p1] == 0;
    if (fr == false) {
        return false;
    }
    self->field_0[p1] = (void *)p0;
    self->field_40++;
    p0->vfunc_10(self, p1);
    return true;
}
