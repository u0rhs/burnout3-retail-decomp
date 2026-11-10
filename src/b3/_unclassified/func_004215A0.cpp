// func_004215A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (do-while loops with unsigned counters; m0 = 2; m0 += 2 kept as two statements).

// func_004215A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_004215A0;
struct UnkStruct_004215A0_e1;
struct UnkStruct_D_004CEB80;
struct UnkStruct_D_004D13B0;
struct UnkStruct_D_004F5080;
struct UnkStruct_D_01EB5D00;
struct UnkStruct_D_01EBE3B0;
struct UnkStruct_D_01EBE3C4;
struct UnkStruct_D_01EBE3C8;
struct UnkStruct_D_01ECD950;

struct UnkStruct_D_01EBE3B0 {
    int field_0;
    unsigned char pad_4[0xC];
    unsigned char field_10[1];  // [G] element count unknown
};

struct UnkStruct_D_01EBE3C4 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EBE3C8 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004215A0_e1 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x8];
};

struct UnkStruct_D_01EB5D00 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CEB80 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F5080 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECD950 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D13B0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004215A0 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    unsigned char pad_C[0x4];
    UnkStruct_004215A0_e1 field_10[1];  // [G] element count unknown
    unsigned char pad_20[0x3C];
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
};

extern UnkStruct_D_01EBE3B0 D_01EBE3B0;
extern UnkStruct_D_01EBE3C4 D_01EBE3C4;
extern UnkStruct_D_01EBE3C8 D_01EBE3C8;
extern UnkStruct_D_01EB5D00 D_01EB5D00;
extern UnkStruct_D_004CEB80 D_004CEB80;
extern UnkStruct_D_004F5080 D_004F5080;
extern UnkStruct_D_01ECD950 D_01ECD950;
extern UnkStruct_D_004D13B0 D_004D13B0;

extern "C" void func_003FE130(void *, UnkStruct_004215A0 *, void *, void *);
extern "C" void func_00421E50(void *, void *, void *, void *);

// 0x004215A0
// [L] both loops are bottom-tested (retail enters the body directly) with unsigned counters (sltiu).
// [G] `m0 = 2; m0 += 2;`: retail keeps `li 2; addiu +2` unfolded, so the two terms are separate statements
// in the original (their meaning is unknown).
extern "C" void func_004215A0(UnkStruct_004215A0 * self, int a1 /* passed by every caller, not read here */)
{
    func_003FE130(&D_01EB5D00, self, &D_004CEB80, &D_004F5080);
    func_00421E50(&D_01ECD950, &D_01EB5D00, &D_004D13B0, &D_004F5080);
    self->field_4 = 3;
    self->field_5C = 0;
    self->field_60 = 0;
    self->field_8 = 0;
    self->field_64 = -1;
    self->field_68 = 0;
    D_01EBE3B0.field_0 = 0;
    unsigned int i = 0;
    do {
        D_01EBE3B0.field_10[i] = 1;
        i++;
    } while (i < 3);
    D_01EBE3C4.field_0 = 0;
    D_01EBE3C8.field_0 = 0;
    unsigned int m0 = 2;
    m0 += 2;
    unsigned int i1 = 0;
    do {
        m0 += (unsigned int)(self->field_10[i1].field_4 + 1023) >> 10;
        i1++;
    } while (i1 < 4);
    self->field_8 = m0 << 10;
}
