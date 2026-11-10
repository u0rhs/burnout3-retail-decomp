// func_002C12B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (a66: the lifter's u_long128 locals were wrong -- the sq/lq at 0xB0/0xA0 are plain int register-pressure spills (nine saved regs); loop limit and p0[m0] value as ints; int m0 declared before r0 gives s0=r0/s1=m0).

// from build/vt\try_func_002C12B0_best.cpp
// func_002C12B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_002C12B0;
struct UnkStruct_002C12B0_1;
struct UnkStruct_002C12B0_2;
struct UnkStruct_002C12B0_3;

struct UnkStruct_002C12B0_1 {
    unsigned char pad_0[0x28];
    int field_28;
};

struct UnkStruct_002C12B0_2 {
    u_long128 field_0;
    u_long128 field_10;
};

struct UnkStruct_002C12B0_3 {
    unsigned char pad_0[0x4B0];
    unsigned char field_4B0;
};

struct UnkStruct_002C12B0 {
    unsigned char pad_0[0x81D8];
    UnkStruct_002C12B0_1 * field_81D8;
};

extern "C" UnkStruct_002C12B0_3 * func_002366D0(UnkStruct_002C12B0_1 *, int);
extern "C" int func_0022FBB0(UnkStruct_002C12B0_3 *);
extern "C" int func_0022F910(UnkStruct_002C12B0_3 *, int);
extern "C" void func_002C1FC0(void *, int, int, int);

// 0x002C12B0
extern "C" void func_002C12B0(UnkStruct_002C12B0 * self, int * p0, int p1, int p2, int p3, int p4)
{
    // [G] the two spills (sq/lq 0xB0, 0xA0) are register-pressure spills: nine saved registers are in use
    int limit = self->field_81D8->field_28;
    for (int i = 0; i < limit; i++) {
        int m0;
        UnkStruct_002C12B0_3 * r0 = func_002366D0(self->field_81D8, i);
        if (r0 != 0) {
            if (r0->field_4B0 != 0) {
                m0 = 0;
                while (m0 < p1) {
                    int v = p0[m0];
                    int r1 = func_0022FBB0(r0);
                    if (v == r1) {
                        int r2 = func_0022F910(r0, 3);
                        func_002C1FC0((void *)(r2), p3, p2, p4);
                    }
                    m0 = m0 + 1;
                }
            }
        }
    }
}
