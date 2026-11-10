// func_0042C020 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bool temp (daddiu consts) and return inside the then-block (no trailing b)).

// lifter variant 0
// func_0042C020 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0042C020;

struct UnkStruct_0042C020 {
    unsigned char pad_0[0x238];
    int field_238;
    int field_23C;
    int field_240;
    int field_244;
};

// 0x0042C020
extern "C" void func_0042C020(UnkStruct_0042C020 * self)
{
    bool v1;
    if (self->field_238 != 0) {
        v1 = false;
    } else if (self->field_244 <= 0) {
        v1 = false;
    } else {
        v1 = true;
    }
    if (v1) {
        self->field_238 = 1;
        self->field_23C = 0;
        self->field_240 = self->field_244;
        self->field_244 = (self->field_244 + -1);
        return;
    }
}
