// func_003FBB00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (if/else -> if { call; return; } call; (struct order e0 before a2)).

struct UnkStruct_003FBB00_e0 {
    unsigned char pad_0[0x18];
};
struct UnkStruct_003FBB00_a2 {
    unsigned char pad_0[0x4C];
    UnkStruct_003FBB00_e0 * field_4C;
    unsigned char pad_50[0x4];
    unsigned char field_54;
};

extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" void func_0042B520(int);

// 0x003FBB00
extern "C" void func_003FBB00(int n0, int p0, UnkStruct_003FBB00_a2 * p1, int p2)
{
    if (p1->field_54) {
        memcpy((void *)p2, &p1->field_4C[p0], 24);
        return;
    }
    func_0042B520((n0 + 8));
}
