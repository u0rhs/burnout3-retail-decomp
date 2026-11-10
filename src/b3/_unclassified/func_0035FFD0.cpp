// func_0035FFD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (separate early returns: p0!=3&&p0!=4 (no range fold) then field_F8==0).

// lifter variant 0
// func_0035FFD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0035FFD0_a3;

struct UnkStruct_0035FFD0_a3 {
    unsigned char pad_0[0xF8];
    int field_F8;
};

// 0x0035FFD0
extern "C" void func_0035FFD0(int n0, int p0, int p1, UnkStruct_0035FFD0_a3 * p2)
{
    if (p0 != 3 && p0 != 4) return;
    if (p2->field_F8 == 0) return;
    ((void (*)(bool, int))p2->field_F8)(p1 == 0, p2->field_F8);
    p2->field_F8 = 0;
}
