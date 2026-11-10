// func_0013A830 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (p0 as const pointer, field read in the loop condition (MWCC hoists it after i=0)).

// func_0013A830 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0013A830;
struct UnkStruct_0013A830_a1;

struct UnkStruct_0013A830_a1 {
    unsigned char pad_0[0xA8];
    int field_A8;
};

struct UnkStruct_0013A830 {
    unsigned char pad_0[0x433];
    unsigned char field_433[1];  // [G] element count unknown
};

// 0x0013A830
// [L] p0 is a const pointer read inside the loop: MWCC hoists the load into the preheader after i = 0
// (a non-const pointer keeps it in the loop; a cached local loads it ahead of i = 0).
extern "C" void func_0013A830(UnkStruct_0013A830 * self, const UnkStruct_0013A830_a1 * p0)
{
    for (int i = 0; i < 20; i++) {
        if ((p0->field_A8 & (1 << i)) != 0) {
            self->field_433[i] = 1;
        }
    }
}
