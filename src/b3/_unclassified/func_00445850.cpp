// func_00445850 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (case 5 tests p2 with a one-case inner switch (case 2), outer default: return; (beq to body + b to exit)).

// func_00445850 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00445850_1;
struct UnkStruct_00445850_2;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_01E95854;

struct UnkStruct_D_0051BA88 {
    UnkStruct_00445850_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00445850_1 {
    unsigned char pad_0[0x1B4];
    UnkStruct_00445850_2 * field_1B4;
};

struct UnkStruct_00445850_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
};

struct UnkStruct_D_01E95854 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01E95854 D_01E95854;

extern "C" int func_004457C0(void *);

extern "C" void func_00445850(int n0, int p0, int p1, int p2)
{
    switch (p0) {
    case 0:
        break;
    case 3:
        func_004457C0(&D_01E95854);
        break;
    case 5:
        switch (p2) {
        case 2:
            D_0051BA88.field_0->field_1B4->vfunc_20();
            break;
        }
        break;
    default:
        return;
    }
}
