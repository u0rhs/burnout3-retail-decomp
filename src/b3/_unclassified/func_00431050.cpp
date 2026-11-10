// func_00431050 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (one unsigned char flags variable (&= 0xF8, |= per case) and a shared tail; callee's 4th param unsigned char).

// func_00431050 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00431050;
struct UnkStruct_00431050_1;

struct UnkStruct_00431050_1 {
    unsigned char pad_0[0x60];
};

struct UnkStruct_00431050 {
    unsigned char pad_0[0x95C];
    unsigned char field_95C;
    unsigned char pad_95D[0x5B];
    int field_9B8;
};

extern "C" void func_003FBB50(void *, int, UnkStruct_00431050_1 *);
extern "C" void func_003FBAA0(void *, int, UnkStruct_00431050_1 *, unsigned char);

// 0x00431050
extern "C" int func_00431050(UnkStruct_00431050 * self, int p0, int p1)
{
    UnkStruct_00431050_1 local;
    unsigned char f = self->field_95C;
    func_003FBB50((void *)(self->field_9B8), 0, &local);
    f &= 0xF8;
    switch (p1) {
    case 0:
        f |= 7;
        break;
    case 1:
        f |= 1;
        break;
    case 2:
        f |= 4;
        break;
    case 3:
        if (f & 8) {
            return 0;
        }
        break;
    }
    func_003FBAA0((void *)(self->field_9B8), p0, &local, f);
    *(int *)&self->field_95C = f;
    return 1;
}
