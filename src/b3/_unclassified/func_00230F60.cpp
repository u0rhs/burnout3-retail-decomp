// func_00230F60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00230F60;
struct UnkStruct_00230F60_2;
struct UnkStruct_00230F60_3;
struct UnkStruct_00230F60_4;
struct UnkStruct_00230F60_e0;

struct UnkStruct_00230F60_e0 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    float field_2C;
    int field_30;
    unsigned char field_34;
    unsigned char pad_35[0x1F];
    float field_54;
    unsigned char field_58;
    unsigned char field_59;
    unsigned char field_5A;
    unsigned char field_5B;
    unsigned char field_5C;
    unsigned char field_5D;
    unsigned char field_5E;
    unsigned char pad_5F[0x31];
};

struct UnkStruct_00230F60_2 {
    int field_0;
    unsigned char pad_4[0x8];
    int field_C;
};

struct UnkStruct_00230F60_3 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(int);
};

struct UnkStruct_00230F60_4 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(int);
};

struct UnkStruct_00230F60 {
    UnkStruct_00230F60_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_90[0x494];
    UnkStruct_00230F60_4 * field_524;
};

extern "C" UnkStruct_00230F60_2 * func_002348A0(UnkStruct_00230F60 *, int);
extern "C" void func_0022D9F0(void *);

// 0x00230F60
extern "C" void func_00230F60(UnkStruct_00230F60 * self, int p0)
{
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        if (p0 == self->field_0[i].field_14) {
            if (self->field_0[i].field_5E != 0) {
                UnkStruct_00230F60_2 * r0 = func_002348A0(self, -1);
                if (r0->field_0 != 1) {
                    self->field_524->vfunc_18(3658);
                    self->field_0[i].field_5E = 0;
                } else {
                    self->field_524->vfunc_18(r0->field_C);
                    self->field_0[i].field_5E = 0;
                }
            }
            self->field_0[i].field_0 = 4;
            self->field_0[i].field_4 = -1;
            self->field_0[i].field_8 = -1;
            self->field_0[i].field_C = -1;
            self->field_0[i].field_10 = -1;
            self->field_0[i].field_14 = -1;
            self->field_0[i].field_18 = -1;
            self->field_0[i].field_1C = 0;
            self->field_0[i].field_20 = 0;
            self->field_0[i].field_24 = -1;
            self->field_0[i].field_28 = -1;
            self->field_0[i].field_2C = -1.0f;
            self->field_0[i].field_30 = 0;
            self->field_0[i].field_34 = 0;
            self->field_0[i].field_54 = -1.0f;
            self->field_0[i].field_58 = 0;
            self->field_0[i].field_59 = 0;
            self->field_0[i].field_5A = 0;
            self->field_0[i].field_5B = 0;
            self->field_0[i].field_5C = 0;
            self->field_0[i].field_5D = 0;
            self->field_0[i].field_5E = 0;
            func_0022D9F0(((char *)&self->field_0[i] + 0x60));
            func_0022D9F0(((char *)&self->field_0[i] + 0x70));
            func_0022D9F0(((char *)&self->field_0[i] + 0x80));
            return;
        }
    }
    i++;
loop0_test:
    if (i < 8) goto loop0_body;
}
