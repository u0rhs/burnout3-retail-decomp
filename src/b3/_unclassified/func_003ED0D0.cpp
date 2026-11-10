// Hand-written; the lifter refused it (a153: MyBurnout profile-load FSM; one-case switches for states 4/8; inline vcall block x3 as separate case bodies).

struct UnkStruct_D_01E8F360 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E89800 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E8F36A { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E8980A { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01ECD520 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_005185A0 { unsigned char pad_0[0x10]; };
struct UnkStruct_003ED0D0 { unsigned char pad_0[0x4]; int field_4; };
extern UnkStruct_D_01E8F360 D_01E8F360;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E8F36A D_01E8F36A;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern UnkStruct_D_005185A0 D_005185A0;
extern "C" int func_00449B70(void *, int, int, int, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_003ECCD0(void *, int);
extern "C" int func_0030A8C0(void *);
extern "C" void StartLoadProfileFlow__24CB3MemCardControllerBaseFv(void *);

static inline void func_003ED0D0_inl1()
{
    if (D_01E8F36A.field_0 != 0) {
        ((UnkStruct_D_01E8F360 *)&D_01E8F360)->vfunc_C();
    }
    func_00449B70(&D_01E8F360, 6, 0, 0, 1, 0);
    if (D_01E8980A.field_0 != 0) {
        ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
    }
    func_0031ECD0(&D_01E89800, 0x105, 3);
}

// 0x003ED0D0
extern "C" void func_003ED0D0(UnkStruct_003ED0D0 * self, int p0)
{
    switch (self->field_4) {
    case 1:
        switch (p0) {
        case 0x31:
            func_003ECCD0(self, 2);
            self->field_4 = 2;
            break;
        case 0x37:
        case 0x38:
        case 0x39:
            func_003ED0D0_inl1();
            self->field_4 = 4;
            break;
        case 0x2E:
        case 0x2F:
            func_003ED0D0_inl1();
            self->field_4 = 4;
            break;
        case 0x32:
            func_003ED0D0_inl1();
            self->field_4 = 4;
            break;
        case 0x3A:
            func_003ECCD0(self, 7);
            self->field_4 = 8;
            break;
        case 0x36:
            if (func_0030A8C0(&D_005185A0) == 1) {
                func_003ECCD0(self, 2);
                self->field_4 = 2;
            } else {
                func_003ECCD0(self, 6);
                self->field_4 = 8;
            }
            break;
        case 0x33:
            func_003ECCD0(self, 9);
            self->field_4 = 8;
            break;
        }
        break;
    case 2:
        switch (p0) {
        case 0x30:
            func_003ECCD0(self, 1);
            self->field_4 = 1;
            StartLoadProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            break;
        case 0x32:
            func_003ECCD0(self, 1);
            self->field_4 = 1;
            StartLoadProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            break;
        }
        break;
    case 4:
        switch (p0) {
        case 0x31:
            func_003ECCD0(self, 2);
            self->field_4 = 2;
            break;
        }
        break;
    case 8:
        switch (p0) {
        case 0x31:
            func_003ECCD0(self, 2);
            self->field_4 = 2;
            break;
        }
        break;
    case 5:
        break;
    }
}
