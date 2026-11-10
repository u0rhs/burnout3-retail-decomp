// func_004423E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bool b = p0 != 0 declared before the inlined index check (as sibling func_00442470); if (valid && b) b = field_0[p1] == p0; early return on b == false || valid == false; field_0 typed void*; vfunc_14 called with no args (a1-a3 at the call are leftovers)).

struct UnkStruct_004423E0;
struct UnkStruct_004423E0_a1;

struct UnkStruct_004423E0_a1 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
};

struct UnkStruct_004423E0 {
    void * field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x3C];
    int field_40;
};

// [G] an inlined index check (real name unknown, placeholder), as in sibling func_00442470
static inline bool func_004423E0_inl0(int i)
{
    return i >= 0 && i < 2;
}

// 0x004423E0
extern "C" void func_004423E0(UnkStruct_004423E0 * self, UnkStruct_004423E0_a1 * p0, int p1)
{
    bool b = p0 != 0;
    bool valid = func_004423E0_inl0(p1);
    if (valid && b) {
        b = self->field_0[p1] == p0;
    }
    if (b == false || valid == false) {
        return;
    }
    self->field_0[p1] = 0;
    self->field_40--;
    p0->vfunc_14();
}
