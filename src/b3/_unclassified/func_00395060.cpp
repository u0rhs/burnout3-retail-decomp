// Hand-written; the lifter refused it (a115: byte-offset 0xBB0 row cast for vfunc_14; D_00522660 is the CGtTimer).

struct UnkStruct_0395060_car {
    unsigned char pad_0[0x11DE];
    unsigned char field_11DE;
    unsigned char pad_11DF[0x131];
    int field_1310;
    unsigned char pad_1314[0x280];
    int field_1594;
    unsigned char pad_1598[0x414];
    signed char field_19AC;
};

struct UnkStruct_0395060_row {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int *);
};

struct UnkStruct_0395060_cam {
    UnkStruct_0395060_car * field_0;
    int field_4;
    int field_8;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char field_E;
    unsigned char field_F;
};

struct UnkStruct_0395060_hud { unsigned char pad_0[0x70]; };
struct UnkStruct_0395060_g1 { unsigned char pad_0[0x28E00]; UnkStruct_0395060_row field_28E00[1]; };
struct UnkStruct_0395060_g2 { unsigned char pad_0[0x12AD50]; unsigned char pad_x; };
struct UnkStruct_0395060_hudt { UnkStruct_0395060_hud field_0[1]; };

extern UnkStruct_0395060_g2 D_00522660;
extern UnkStruct_0395060_g1 D_004EE040;
extern UnkStruct_0395060_hudt D_0066A3D0;
extern "C" void SetSlowMo__8CGtTimerFi(void *, int);
extern "C" void SetHUDMode__6CB3HUDF8EHUDMode(void *, int);

// 0x00395060
extern "C" void func_00395060(UnkStruct_0395060_cam * self)
{
    UnkStruct_0395060_car * car = (UnkStruct_0395060_car *)((char *)&D_00522660 + self->field_8 * 0x27D0 + 0x12AD50);
    if (self->field_E == 0) {
        self->field_0 = (UnkStruct_0395060_car *)car->field_1594;
        self->field_4 = 0;
        self->field_E = 1;
        self->field_C = 1;
        self->field_D = 0;
        self->field_F = car->field_11DE;
        SetSlowMo__8CGtTimerFi(&D_00522660, 5);
        int t = self->field_0->field_19AC;
        if (car->field_1310 == -1) {
            ((UnkStruct_0395060_row *)((char *)&D_004EE040 + self->field_8 * 0xBB0 + 0x28E00))->vfunc_14(9, &t);
        } else {
            ((UnkStruct_0395060_row *)((char *)&D_004EE040 + self->field_8 * 0xBB0 + 0x28E00))->vfunc_14(0xB, &t);
        }
        SetHUDMode__6CB3HUDF8EHUDMode(&D_0066A3D0.field_0[self->field_8], 3);
    }
}
