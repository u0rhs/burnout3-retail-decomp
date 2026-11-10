// Hand-written; the lifter refused it (a120: inl1/inl2 u16 helpers, us local declared first + 0x25 buf pad).

struct UnkStruct_0023E3E0_buf { int field_0; int field_4; int field_8; int field_C; int field_10; unsigned char field_14; unsigned char field_15; unsigned char field_16; unsigned char pad_17[37]; };
struct UnkStruct_0023E3E0_p {
    unsigned char pad_0[0x1161];
    unsigned char field_1161;
    unsigned char field_1162;
    unsigned char pad_1163[0x7B];
    unsigned char field_11DE;
    unsigned char pad_11DF[0x4D5];
    float field_16B4;
    unsigned char pad_16B8[0x2F8];
    unsigned char field_19B0[0x40];
    unsigned char field_19F0[0x10];
    unsigned char field_1A00[0x10];
    unsigned char field_1A10[2];
    unsigned char field_1A12;
    unsigned char field_1A13;
    unsigned char field_1A14;
    unsigned char field_1A15;
    unsigned char field_1A16;
    unsigned char pad_1A17;
    int field_1A18;
    unsigned char pad_1A1C[0x68];
    unsigned char field_1A84;
    unsigned char field_1A85;
    unsigned short field_1A86;
};
struct UnkStruct_0023E3E0_vt {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual int vfunc_9C();
};
struct UnkStruct_0023E3E0_o { unsigned char pad_0[0x1B4]; UnkStruct_0023E3E0_vt * field_1B4; };
struct UnkStruct_D_0051BA88 { UnkStruct_0023E3E0_o * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BA80 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0023E3E0 {
    unsigned char pad_0[0x6DC];
    UnkStruct_0023E3E0_p * field_6DC;
    int field_6E0;
    unsigned char pad_6E4[0x47FC];
    int field_4EE0;
    int field_4EE4;
};
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0051BA80 D_0051BA80;
extern "C" bool func_001A9200(void *, void *, void *, void *, void *, void *, void *);
extern "C" void func_0023B000(UnkStruct_0023E3E0 *, void *);

static inline bool func_0023E3E0_inl1(unsigned short a, unsigned short b)
{
    if (a < 0x5555) {
        if (b > 0xAAAA) {
            return true;
        }
    }
    if (b < 0x5555) {
        if (a > 0xAAAA) {
            return false;
        }
    }
    if (b < a) {
        return true;
    }
    return false;
}

static inline unsigned short func_0023E3E0_inl2(unsigned short a, unsigned short b)
{
    if (b < 0x5555) {
        if (a > 0xAAAA) {
            return b + (0xFFFF - a);
        }
    }
    return b - a;
}

// 0x0023E3E0
extern "C" void func_0023E3E0(UnkStruct_0023E3E0 * self, int p0, void *p1_)
{
    int p1 = (int)p1_;
    unsigned short us;
    UnkStruct_0023E3E0_buf buf;
    self->field_6DC->field_1A84 = 1;
    self->field_6DC->field_1A13 = 0;
    self->field_6DC->field_1A85 = 1;
    func_001A9200((void *)(p1), self->field_6DC->field_19B0, self->field_6DC->field_19F0, self->field_6DC->field_1A00, self->field_6DC->field_1A10, &buf, &us);
    self->field_6DC->field_1A14 = buf.field_14;
    self->field_6DC->field_1A15 = buf.field_15;
    self->field_6DC->field_1A16 = buf.field_16;
    self->field_6DC->field_1A18 = buf.field_10;
    if (func_0023E3E0_inl1(p0, us)) {
        self->field_6DC->field_1A86 = func_0023E3E0_inl2(us, p0);
    } else {
        unsigned short d = func_0023E3E0_inl2(p0, us);
        if (d >= 5) {
            D_0051BA80.field_0 = 1;
        }
        self->field_6DC->field_1A86 = 0;
    }
    self->field_6DC->field_11DE = 0;
    if ((self->field_6DC->field_1A12 & 8) == 8) {
        self->field_6DC->field_11DE = 1;
    }
    if (self->field_6E0 != 0) {
        func_0023B000(self, &buf);
    }
    switch (D_0051BA88.field_0->field_1B4->vfunc_9C()) {
    case 0: case 3: case 4: case 5:
        self->field_6DC->field_16B4 = (float)buf.field_4 / 255.0f;
        break;
    case 2:
        self->field_6DC->field_16B4 = (float)buf.field_4 / 255.0f;
        self->field_6DC->field_1162 = 0;
        if ((buf.field_8 & 1) == 1) {
            self->field_6DC->field_1162 = 1;
        }
        self->field_6DC->field_1161 = 0;
        if ((buf.field_8 & 2) == 2) {
            self->field_6DC->field_1161 = 1;
        }
        break;
    case 1:
        break;
    }
    self->field_4EE0 = 0;
    self->field_4EE4 = 0;
}
