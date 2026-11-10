// func_003D11D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (record/entry structs with inlined reset helpers; each entry address in a const local pointer (keeps it in an s-register)).

// func_003D11D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// [G] 100 records of 0x17C bytes at +0x4EC0: five 0x1C-byte entries, then five pairs of a 0x1C-byte and a
// 0x14-byte entry, each reset through an inlined helper (CopyN__10CGtUnicodeFPUsiPCUs of D_004A5240 into the 9-character name).

struct UnkStruct_003D11D0_a {
    unsigned short field_0[9];
    unsigned char field_12;
    unsigned char field_13;
    signed char field_14;
    unsigned char field_15;
    unsigned char pad_16[0x2];
    int field_18;
};

struct UnkStruct_003D11D0_b {
    unsigned short field_0[9];
    unsigned char field_12;
    unsigned char field_13;
};

struct UnkStruct_003D11D0_c {
    UnkStruct_003D11D0_a field_0;
    UnkStruct_003D11D0_b field_1C;
};

struct UnkStruct_003D11D0_r {
    UnkStruct_003D11D0_a field_0[5];
    UnkStruct_003D11D0_c field_8C[5];
};

struct UnkStruct_003D11D0 {
    unsigned char pad_0[0x4EC0];
    UnkStruct_003D11D0_r field_4EC0[100];
};

struct UnkStruct_D_004A5240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern unsigned long D_004E2EE8;
extern int D_004E2EE0;
extern unsigned long D_004E2EF0;
extern UnkStruct_D_004A5240 D_004A5240;

extern "C" void func_003D0D80(UnkStruct_003D11D0 *);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(void *, int, void *);

// [G] inlined helpers (no names known)
static inline void func_003D11D0_inl1(UnkStruct_003D11D0_a * e)
{
    CopyN__10CGtUnicodeFPUsiPCUs(e->field_0, 9, &D_004A5240);
    e->field_12 = 0;
    e->field_13 = 0;
    e->field_14 = -1;
    e->field_15 = 255;
    e->field_18 = 0;
}

static inline void func_003D11D0_inl2(UnkStruct_003D11D0_b * e)
{
    CopyN__10CGtUnicodeFPUsiPCUs(e->field_0, 9, &D_004A5240);
    e->field_12 = 0;
    e->field_13 = 0;
}

static inline void func_003D11D0_inl3(UnkStruct_003D11D0_c * e)
{
    func_003D11D0_inl1(&e->field_0);
    func_003D11D0_inl2(&e->field_1C);
}

// 0x003D11D0
extern "C" int func_003D11D0(UnkStruct_003D11D0 * self)
{
    func_003D0D80(self);
    for (int i = 0; i < 100; i++) {
        UnkStruct_003D11D0_a * const e0 = &self->field_4EC0[i].field_0[0];
        func_003D11D0_inl1(e0);
        UnkStruct_003D11D0_a * const e1 = &self->field_4EC0[i].field_0[1];
        func_003D11D0_inl1(e1);
        UnkStruct_003D11D0_a * const e2 = &self->field_4EC0[i].field_0[2];
        func_003D11D0_inl1(e2);
        UnkStruct_003D11D0_a * const e3 = &self->field_4EC0[i].field_0[3];
        func_003D11D0_inl1(e3);
        UnkStruct_003D11D0_a * const e4 = &self->field_4EC0[i].field_0[4];
        func_003D11D0_inl1(e4);
        UnkStruct_003D11D0_c * const c0 = &self->field_4EC0[i].field_8C[0];
        func_003D11D0_inl3(c0);
        UnkStruct_003D11D0_c * const c1 = &self->field_4EC0[i].field_8C[1];
        func_003D11D0_inl3(c1);
        UnkStruct_003D11D0_c * const c2 = &self->field_4EC0[i].field_8C[2];
        func_003D11D0_inl3(c2);
        UnkStruct_003D11D0_c * const c3 = &self->field_4EC0[i].field_8C[3];
        func_003D11D0_inl3(c3);
        UnkStruct_003D11D0_c * const c4 = &self->field_4EC0[i].field_8C[4];
        func_003D11D0_inl3(c4);
    }
    D_004E2EE8 = 0;
    D_004E2EE0 = 3;
    D_004E2EF0 = 0;
    return 1;
}
