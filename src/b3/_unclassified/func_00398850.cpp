// Hand-written; the lifter refused it (a83: UpdateScroll [L] DNAT; block form if(*p!=old){...} instead of early return; lo/hi decl order; *p as 3rd arg).

// func_00398850 -- CB3OnlineGameCreateOptionsPage::UpdateScroll() [L] DNAT (research/proto/new_names.csv, medium)
class CB3InputManager {
public:
    int GetMenuLeft(signed char);
    int GetMenuRight(signed char);
    unsigned char pad_0[0x10];
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_S3 { short field_0; short field_2; short field_4; };
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E8D4B0 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_00398850 {
    unsigned char pad_0[0x40];
    unsigned short field_40;
    unsigned char pad_42[0x52];
    unsigned short field_94;
    unsigned short field_96;
    unsigned char pad_98[0x10];
    unsigned short * field_A8;
    unsigned char pad_AC[0x38];
    int field_E4;
    int field_E8;
};
extern CB3InputManager D_004F50C0;
extern UnkStruct_P D_01E7A800, D_01E8961C, D_0051BA44;
extern UnkStruct_D_01E8D4B0 D_01E8D4B0;
extern UnkStruct_B D_01E8D4BA;
extern UnkStruct_S3 D_004E1E78;
extern UnkStruct_P D_004C99B0, D_004C99B8, D_004C99C0, D_004C99C8;
extern UnkStruct_F D_004C99D0;
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);
extern "C" unsigned short * func_00271A00(void *, int);
extern "C" int AppendN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, unsigned short *);
extern "C" bool func_00351E40(void *, void *, void *, void *, void *, void *, void *, int, int, int, int, float, float);

// [L] DNAT: CB3OnlineGameCreateOptionsPage::UpdateScroll() (research/proto/new_names.csv, medium)
// 0x00398850
extern "C" void func_00398850(UnkStruct_00398850 * self)
{
    int *p;
    int hi;
    int lo;
    switch (self->field_40) {
    case 2:
        p = &self->field_E4;
        lo = 0;
        hi = 4;
        break;
    case 3:
        hi = self->field_96 + 1;
        p = &self->field_E8;
        lo = self->field_94;
        break;
    default:
        return;
    }
    int old = *p;
    if (D_004F50C0.GetMenuLeft(0)) {
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
        *p = *p - 1;
        if (*p < lo) {
            *p = hi - 1;
        }
    } else if (D_004F50C0.GetMenuRight(0)) {
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
        *p = *p + 1;
        if (*p >= hi) {
            *p = lo;
        }
    }
    if (*p != old) {
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, self->field_40, *p);
    UnkStruct_S3 buf = D_004E1E78;
    *self->field_A8 = 0;
    AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, func_00271A00(&D_0051BA44, 987));
    if (self->field_E8 < 7) {
        AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, func_00271A00(&D_0051BA44, 730));
        AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, (unsigned short *)&buf);
        AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, func_00271A00(&D_0051BA44, 733));
        AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, (unsigned short *)&buf);
        if (self->field_E8 == 2) {
            AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, func_00271A00(&D_0051BA44, 735));
            AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, (unsigned short *)&buf);
            AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, func_00271A00(&D_0051BA44, 731));
            AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, (unsigned short *)&buf);
        }
    }
    AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, func_00271A00(&D_0051BA44, 734));
    if (D_01E8D4BA.field_0 != 0) {
        ((UnkStruct_D_01E8D4B0 *)&D_01E8D4B0)->vfunc_C();
    }
    func_00351E40(&D_01E8D4B0, &D_004C99B0, &D_004C99B8, &D_004C99C0, &D_004C99C8, &D_004C99D0, (void *)self->field_A8, 3, 1, 3, 0, 26.0f, D_004C99D0.field_0 - 16.0f);
    }
}
