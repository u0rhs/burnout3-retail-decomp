// func_002348A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (switch -> if (m != 7 && m != 8 && m != 9) {default} else {nested ifs, nonzero-first}; field_578 set with == first).

// lifter variant 0
// func_002348A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_002348A0;

struct UnkStruct_002348A0 {
    unsigned char pad_0[0x480];
    int field_480;
    int field_484;
    int field_488;
    int field_48C;
    int field_490;
    unsigned char pad_494[0xC4];
    int field_558;
    unsigned char pad_55C[0x10];
    int field_56C;
    unsigned char pad_570[0x4];
    int field_574;
    int field_578;
    int field_57C;
    unsigned char pad_580[0x4];
    int field_584;
};

// 0x002348A0
extern "C" void * func_002348A0(UnkStruct_002348A0 * self, int p0)
{
    if (self->field_57C == self->field_56C) {
        self->field_578 = 0;
    } else {
        self->field_578 = 1;
    }
    self->field_488 = self->field_56C;
    int m = self->field_584;
    if (m != 7 && m != 8 && m != 9) {
        self->field_480 = 3;
        self->field_48C = self->field_558;
        self->field_484 = self->field_57C;
    } else {
        if (self->field_578 != 0) {
            if (self->field_574 != 0) {
                self->field_480 = 1;
                self->field_48C = self->field_558;
                self->field_484 = self->field_57C;
            } else {
                self->field_480 = 2;
                self->field_48C = 3658;
                self->field_484 = self->field_57C;
            }
        } else {
            self->field_480 = 0;
            self->field_484 = self->field_56C;
            self->field_48C = 3658;
        }
    }
    if (p0 != -1) {
        self->field_490 = p0;
    }
    return ((char *)self + 0x480);
}
