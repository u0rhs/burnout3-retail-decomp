// func_00336C20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (early returns instead of result variable).

// lifter variant 0
// func_00336C20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00336C20;
struct UnkStruct_func_003366E0;

struct UnkStruct_func_003366E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00336C20 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual int vfunc_14();
    unsigned char pad_4[0x10C];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x8];
    unsigned char field_120;
    unsigned char pad_121[0x4FB];
    int field_61C;
};

extern UnkStruct_func_003366E0 func_003366E0;

extern "C" void func_0040CF08(int, int);
extern "C" int func_0040CDB8(int, int, int, int);
extern "C" int func_0040D020(int, int, int, int, int, int, void *, UnkStruct_00336C20 *);

// 0x00336C20
extern "C" int func_00336C20(UnkStruct_00336C20 * self, int p0, int p1, int p2, int p3)
{
    func_0040CF08(self->field_61C, 1);
    if (func_0040CDB8(self->field_61C, p0, p1, p2) != 0) {
        return 1;
    }
    self->field_110 = 1;
    self->field_111 = 0;
    self->field_112 = 0;
    self->field_120 = 0;
    self->field_114 = 0;
    if (func_0040D020(self->field_61C, 0, -93, p3, 0, 0, &func_003366E0, self) != 0) {
        return 1;
    }
    return self->vfunc_14();
}
