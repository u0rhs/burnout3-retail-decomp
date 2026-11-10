// func_003BC540 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (dropped phantom t0/t1 args: callee signature (self,int,int,unsigned char,float) as in matched sibling SetOptionText__26CB3VOptionsSelectComponentFiUi; v0=0 before the early return).

struct UnkStruct_003BC540;
struct UnkStruct_003BC540_e0;

struct UnkStruct_003BC540_e0 {
    unsigned char pad_0[0xD];
    unsigned char field_D;
    unsigned char pad_E[0x6];
};

struct UnkStruct_003BC540 {
    unsigned char pad_0[0x10];
    UnkStruct_003BC540_e0 * field_10;
};

extern float D_004CA2A0[];  // [G] element count unknown

extern "C" void func_003BD760(UnkStruct_003BC540 *, int, int, float);

// 0x003BC540
extern "C" void func_003BC540(UnkStruct_003BC540 * self, int p0, int p1)
{
    UnkStruct_003BC540_e0 * t0 = self->field_10;
    unsigned char t1 = t0[p0].field_D;
    int v0 = 0;
    if (t1 != 6) return;
    if (p1 == 0) {
        v0 = 1;
    }
    func_003BD760(self, p0, v0, D_004CA2A0[t1]);
}
