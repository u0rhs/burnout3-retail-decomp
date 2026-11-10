// func_003D7100 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (sub-struct at +0x20 reached through a hoisted local pointer; .lit4 0.6f literal; -= then clamp).

// from build/vt\try_func_003D7100_best.cpp
// func_003D7100 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003D7100;
struct UnkStruct_003D7100_1;
struct UnkStruct_003D7100_2;
struct UnkStruct_003D7100_3;
struct UnkStruct_003D7100_4;
struct UnkStruct_D_004E06A8;

struct UnkStruct_003D7100_1 {
    unsigned char pad_0[0xC8];
    UnkStruct_003D7100_2 * field_C8;
};

struct UnkStruct_003D7100_2 {
    unsigned char pad_0[0x18EA];
    unsigned char field_18EA;
};

struct UnkStruct_003D7100_3_20 {  // [G] sub-struct at +0x20 (hoisted base pointer in retail)
    float field_0;
    UnkStruct_003D7100_4 * field_4;
    int field_8;
};

struct UnkStruct_003D7100_3 {
    unsigned char pad_0[0x20];
    UnkStruct_003D7100_3_20 field_20;
};

struct UnkStruct_003D7100_4 {
    unsigned char pad_0[0x100];
    int field_100;
};

struct UnkStruct_D_004E06A8 {
    float field_0;
};

struct UnkStruct_003D7100 {
    unsigned char pad_0[0x28];
    UnkStruct_003D7100_1 * field_28;
    UnkStruct_003D7100_3 * field_2C;
};

extern UnkStruct_D_004E06A8 D_004E06A8;

// 0x003D7100
extern "C" void func_003D7100(UnkStruct_003D7100 * self, float f0)
{
    if (self->field_28->field_C8->field_18EA != 0) {
        UnkStruct_003D7100_3_20 * s = &self->field_2C->field_20;
        if (s->field_8 == s->field_4->field_100) {
            s->field_0 -= f0;
            if (s->field_0 < 0.0f) {
                s->field_0 = 0.0f;
            }
        } else {
            s->field_0 = 0.6f;
            s->field_8 = s->field_4->field_100;
        }
    } else {
        self->field_2C->field_20.field_8 = -1;
    }
}
