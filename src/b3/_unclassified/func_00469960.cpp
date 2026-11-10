// func_00469960 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (null-tested global typed void* (was int)).

struct UnkStruct_D_004B13C0 {
    void *field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
struct UnkStruct_D_004B13D0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
extern UnkStruct_D_004B13C0 D_004B13C0;
extern UnkStruct_D_004B13D0 D_004B13D0;
extern "C" void func_00360AC0(int, void *, int, int);
// 0x00469960
extern "C" int func_00469960()
{
    void *t0 = D_004B13C0.field_0;
    if (t0 != 0) {
        func_00360AC0(D_004B13D0.field_0, t0, 1024, 4);
        D_004B13C0.field_0 = 0;
        return 0;
    }
    return 6;
}
