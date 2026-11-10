// func_00469700 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (a80: const-int pun reload of D_004E2668 in the final return (a63 pattern); merged self==0||p0==0).

struct UnkStruct_D_004E2668 { int field_0; };
struct UnkStruct_D_004E2FD0 { int field_0; };
struct UnkStruct_D_004E2FD8 { int field_0; };
struct UnkStruct_D_004E2FD4 { int field_0; };
extern UnkStruct_D_004E2668 D_004E2668;
extern UnkStruct_D_004E2FD0 D_004E2FD0;
extern UnkStruct_D_004E2FD8 D_004E2FD8;
extern UnkStruct_D_004E2FD4 D_004E2FD4;

// 0x00469700
extern "C" int func_00469700(unsigned char *self, int p0)
{
    if (self == 0 || p0 == 0) {
        return 2;
    }
    if (D_004E2668.field_0 != 4) {
        D_004E2FD0.field_0 = (int)self;
        D_004E2FD8.field_0 = (int)self;
        D_004E2FD4.field_0 = (int)(self + p0 - 1);
        D_004E2668.field_0 = 5;
        return 0;
    }
    return *(const int *)&D_004E2668.field_0;  // [G] pun: retail reloads the state word here
}
