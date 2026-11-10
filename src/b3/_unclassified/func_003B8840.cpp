// func_003B8840 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (ustr buffer param advanced in the switch, bool flag, early return (if (!v1) return;)).

// func_003B8840 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// [G] self is a 16-bit (ustr) text buffer: writes '$' (36) and ' ' (32) around ustrFromInt's number,
// prefix or suffix chosen by D_004E2918 (4/5 -> suffix).

struct UnkStruct_D_004E2918 { int field_0; };
extern UnkStruct_D_004E2918 D_004E2918;
extern "C" unsigned short * ustrFromInt(unsigned short *, int, int, int);
// 0x003B8840
extern "C" void func_003B8840(unsigned short * self, int p0)
{
    bool v1 = false;
    switch (D_004E2918.field_0) {
    case 6:
        *self++ = 36;
        *self++ = 32;
        break;
    case 4:
    case 5:
        v1 = true;
        break;
    default:
        *self++ = 36;
        break;
    }
    self = ustrFromInt(self, p0, 1, 0);
    if (!v1) return;
    self[0] = 32;
    self[1] = 36;
    self[2] = 0;
}
