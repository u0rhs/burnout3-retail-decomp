// func_003FBB50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (p0 >= 1 test (out-of-line then-block layout); first arg a struct pointer, passing &a0->field_8).

struct UnkStruct_003FBB50_a2 {
    unsigned char pad_0[0x50];
    int field_50;
};
struct UnkStruct_003FBB50_a0 { unsigned char pad_0[8]; unsigned char field_8[8]; };
struct UnkStruct_D_004A5A20 {
    unsigned char pad_0[0x10];
};
extern UnkStruct_D_004A5A20 D_004A5A20;
extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" void func_0042B530(void *, int);
// 0x003FBB50
extern "C" void func_003FBB50(UnkStruct_003FBB50_a0 * n0, int p0, UnkStruct_003FBB50_a2 * p1)
{
    if (p0 >= 1) {
        func_0042B530(n0->field_8, p0 - 1);
        p1->field_50 = p0;
    } else {
        memcpy(p1, &D_004A5A20, 88);
    }
}
