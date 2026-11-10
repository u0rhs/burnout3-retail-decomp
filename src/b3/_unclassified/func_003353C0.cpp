// func_003353C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (sig1: func_003350F0 takes only self (its prologue never reads a1); drop phantom 2nd arg).


// lifter variant 0
// func_003353C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003353C0;
struct UnkStruct_003353C0_1;

struct UnkStruct_003353C0_1 {
    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0x2AC];
    int field_2C4;
};

struct UnkStruct_003353C0 {
    unsigned char pad_0[0x30];
    UnkStruct_003353C0_1 * field_30;
    int field_34;
    int field_38;
    float field_3C;
};

extern "C" void func_003350F0(void *);

// 0x003353C0
extern "C" void func_003353C0(UnkStruct_003353C0 * self, float f0)
{
    if (self->field_34 < self->field_30->field_14 || (self->field_38 != self->field_30->field_2C4)) {
        self->field_3C = 0.1f;
        self->field_34 = self->field_30->field_14;
        self->field_38 = self->field_30->field_2C4;
    } else {
        float t1 = self->field_3C;
        if (!(t1 <= 0.0f)) {
            self->field_3C = t1 - f0;
        }
    }
    func_003350F0(self);
}
