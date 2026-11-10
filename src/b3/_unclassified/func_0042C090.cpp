// func_0042C090 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bool flag from if/else-if/else (true/false literals give daddiu/daddu), then if(!ok) return).

// lifter variant 0
// func_0042C090 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0042C090;

struct UnkStruct_0042C090 {
    unsigned char pad_0[0x238];
    int field_238;
    int field_23C;
    int field_240;
    int field_244;
    int field_248;
};

// 0x0042C090
extern "C" void func_0042C090(UnkStruct_0042C090 * self)
{
    bool ok;
    if (self->field_238 != 0) {
        ok = false;
    } else if (self->field_244 < self->field_248 - 1) {
        ok = true;
    } else {
        ok = false;
    }
    if (!ok) return;
        self->field_238 = 2;
        self->field_23C = 0;
        self->field_240 = self->field_244;
        self->field_244 = (self->field_244 + 1);
}
