// func_0033BAE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0033BAE0;
struct UnkStruct_0033BAE0_1;

struct UnkStruct_0033BAE0_1 {
    unsigned char pad_0[0x130];
    int field_130;
};

struct UnkStruct_0033BAE0 {
    unsigned char pad_0[0x104];
    int field_104;
    unsigned char pad_108[0x14];
    unsigned char field_11C;
    unsigned char field_11D;
    unsigned char pad_11E[0x3];
    unsigned char field_121;
    unsigned char pad_122[0x2];
    int field_124;
    unsigned char pad_128[0x4];
    int field_12C;
    int field_130;
    int field_134;
    unsigned char pad_138[0x30C];
    unsigned char field_444;
    unsigned char pad_445[0x113];
    int field_558;
    int field_55C;
};

extern "C" UnkStruct_0033BAE0_1 * LobbyApiInfoPtr(int, int);

// 0x0033BAE0
extern "C" int func_0033BAE0(UnkStruct_0033BAE0 * self)
{
    UnkStruct_0033BAE0_1 * r0 = LobbyApiInfoPtr(self->field_104, 0x73656C66);
    if (r0->field_130 != 0) {
        self->field_124 = 0;
        return 1;
    }
    self->field_124 = (self->field_124 + 1);
    if (self->field_124 >= 200) {
        self->field_124 = 0;
        self->field_11C = 0;
        self->field_11D = 0;
        self->field_12C = -1;
        self->field_134 = 0;
        self->field_121 = 0;
        self->field_124 = 0;
        self->field_130 = 0;
        self->field_444 = 0;
        ((void (*)(int, int))self->field_558)(1, self->field_55C);
        return 0;
    }
    return 1;
}
