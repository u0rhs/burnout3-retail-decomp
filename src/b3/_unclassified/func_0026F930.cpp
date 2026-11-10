// func_0026F930 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (a66: wraparound counter compare/diff via two static inlines (thirds 0x55555555/0xAAAAAAAB); bool-returning compare with nested ifs; the upper-third test spelled x > 0xAAAAAAAA gives the at-register sltu (>= 0xAAAAAAAB used v1)).

// func_0026F930 -- hand-matched (a66).
// [G] wraparound-aware 32-bit counter compare/difference (thirds 0x55555555 / 0xAAAAAAAB); inlines have no names.
struct UnkStruct_0026F930 {
    unsigned char pad_0[0x329B0];
    int field_329B0;
    int field_329B4;
    unsigned char field_329B8;
};

struct UnkStruct_D_00665EC0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern unsigned int D_004E2A14;
extern UnkStruct_D_00665EC0 D_00665EC0;

extern "C" unsigned int func_00222C90(void *);


static inline unsigned int func_0026F930_inl0(unsigned int a, unsigned int b)
{
    if (a < 0x55555555) {
        if (b > 0xAAAAAAAA) {
            return a + (0xFFFFFFFF - b);
        }
    }
    return a - b;
}

static inline bool func_0026F930_inl1(unsigned int r, unsigned int a)
{
    if (a < 0x55555555) {
        if (r > 0xAAAAAAAA) {
            return true;
        }
    }
    if (r < 0x55555555) {
        if (a > 0xAAAAAAAA) {
            return false;
        }
    }
    if (r < a) {
        return true;
    }
    return false;
}

// 0x0026F930
extern "C" void func_0026F930(UnkStruct_0026F930 * self)
{
    self->field_329B8 = 1;
    self->field_329B4 = 0;
    unsigned int t0 = D_004E2A14;
    unsigned int r0 = func_00222C90(&D_00665EC0);
    if (func_0026F930_inl1(r0, t0)) {
        self->field_329B0 = func_0026F930_inl0(t0, r0);
    } else {
        self->field_329B0 = -func_0026F930_inl0(r0, t0);
    }
}
