// Hand-written; the lifter refused it (snprintf/ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi string setup; int b hoisted before first snprintf).

struct UnkStruct_Prof { unsigned char pad_0[0x40]; int field_40; int field_44; };
struct UnkStruct_D_0051BF9C { UnkStruct_Prof * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BF9C D_0051BF9C;
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
extern UnkStruct_Pad16 D_0051BA44;
extern int D_004E2A20;
extern char D_004D1480[];
extern char D_004D1490[];
extern char D_004D1498[];
extern char D_004D14A0[];
extern char D_004D14A8[];
extern char D_004D14B0[];
struct UnkStruct_Row { unsigned short * field_0; unsigned char field_4; unsigned char field_5; unsigned char pad_6[2]; };
struct UnkStruct_00424A60 {
    unsigned char pad_0[8];
    int field_8;
    int field_C;
    unsigned char pad_10[8];
    UnkStruct_Row field_18[9];
    unsigned short * field_60[9];
};
extern "C" int snprintf(char *, int, const char *, ...);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, unsigned short *, int);
extern "C" int AppendN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, unsigned short *);
extern "C" int func_0013A630(void *, int);
extern "C" int func_0013A820(void *, int);
extern "C" int func_003F5FB0(int);
extern "C" int func_003F5EF0(int);
extern "C" unsigned short * func_00271A00(void *, int);
// 0x00424A60
extern "C" void func_00424A60(UnkStruct_00424A60 * self)
{
    char buf[0x40];
    UnkStruct_Prof * p = D_0051BF9C.field_0;
    int b = p->field_44;
    snprintf(buf, 0x40, D_004D1480, p->field_40);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, self->field_60[4], 0x40);
    snprintf(buf, 0x40, D_004D1490, b);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, self->field_60[5], 0x40);
    snprintf(buf, 0x36, D_004D14A8, func_0013A630(p, self->field_8) ? D_004D1498 : D_004D14A0);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, self->field_60[6], 0xA);
    AppendN__10CGtUnicodeFPUsiPCUs(self->field_60[6], 0x36, func_00271A00(&D_0051BA44, func_003F5FB0(self->field_8)));
    snprintf(buf, 0x36, D_004D14A8, func_0013A820(p, self->field_C) ? D_004D1498 : D_004D14A0);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, self->field_60[7], 0xA);
    AppendN__10CGtUnicodeFPUsiPCUs(self->field_60[7], 0x36, func_00271A00(&D_0051BA44, func_003F5EF0(self->field_C)));
    snprintf(buf, 0x40, D_004D14B0, D_004E2A20);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, self->field_60[8], 0x40);
    for (int i = 0; i < 9; i++) {
        self->field_18[i].field_0 = self->field_60[i];
        self->field_18[i].field_4 = 0;
        self->field_18[i].field_5 = 0;
    }
}
