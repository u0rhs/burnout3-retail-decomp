// func_003C5B80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (callee func_003C5A80 declared with only self (it overwrites a1 at entry); the lifter's extra args included an int that truncated p0 (dsll32/dsra32)).

// func_003C5B80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003C5B80;

struct UnkStruct_003C5B80 {
    unsigned char pad_0[0x30];
    unsigned long field_30;
    unsigned char pad_38[0x11];
    unsigned char field_49;
    unsigned char field_4A;
};

extern "C" void func_003C5A80(UnkStruct_003C5B80 *);

// 0x003C5B80
extern "C" void func_003C5B80(UnkStruct_003C5B80 * self, unsigned long p0)
{
    self->field_49 = ((p0 & 0x419E9003) != 0);
    self->field_4A = ((p0 & 0x1C00020681C) != 0);
    if (p0 != self->field_30) {
        self->field_30 = p0;
        func_003C5A80(self);
    }
}
