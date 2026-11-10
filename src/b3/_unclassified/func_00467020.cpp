// func_00467020 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_D_004E2FCC;

struct UnkStruct_D_004E2FCC {
    int field_0;
};

extern UnkStruct_D_004E2FCC D_004E2FCC;

extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" void func_00462190(void *, void *, void *);
extern "C" int func_00462130(int);

// 0x00467020
extern "C" int func_00467020(int n0)
{
    if (n0 == 0) {
        return 12;
    }
    int t0 = D_004E2FCC.field_0;
    if ((t0 != 0) != false) {
        memcpy((void *)(t0 + 84), (const void *)n0, 976);
        func_00462190((void *)(n0), (void *)((D_004E2FCC.field_0 + 1060)), (void *)((D_004E2FCC.field_0 + 1064)));
        int r2 = func_00462130(n0);
        return r2;
    }
    return 2;
}
