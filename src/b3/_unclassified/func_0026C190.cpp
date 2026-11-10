// Hand-written; the lifter refused it (switch only sets field_329E3 (0,1,5 break), body after the switch; D4/D8 fields are char*; round-up via signed %% 0x800).

struct UnkStruct_D_004F60C0_o {
    virtual void vfunc_8();
    virtual int vfunc_C();
};
struct UnkStruct_D_004F60C0 { UnkStruct_D_004F60C0_o *field_0; unsigned char pad[0xC]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_26C190_ent { unsigned long field_0; int field_8; int field_C; };
struct UnkStruct_26C190_hdr { int field_0; int field_4; UnkStruct_26C190_ent field_8[1]; };
struct UnkStruct_26C190 {
    unsigned char pad_0[0x329D0];
    UnkStruct_26C190_hdr *field_329D0;
    char *field_329D4;
    char *field_329D8;
    unsigned short *field_329DC;
    unsigned char field_329E0;
    unsigned char pad_329E1[2];
    unsigned char field_329E3;
    unsigned char pad_329E4[8];
    int field_329EC;
    int field_329F0;
    int field_329F4;
};
extern UnkStruct_D_004F60C0 D_004F60C0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern char D_004BCA50[];
extern char D_004BCA58[];
extern "C" unsigned short *func_00271A00(void *, int);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, unsigned short *);
extern "C" int Length__10CGtUnicodeFPCUs(unsigned short *);
extern "C" void func_0021ADF0(unsigned long, char *);
extern "C" int strncmp(const char *, const char *, unsigned int);
// 0x0026C190
extern "C" int func_0026C190(UnkStruct_26C190 *self)
{
    switch (D_004F60C0.field_0->vfunc_C()) {
    case 0:
    case 1:
    case 5:
        break;
    case 2:
    case 3:
    case 4:
    default:
        self->field_329E3 = 1;
        break;
    }
    self->field_329EC = 10;
    CopyN__10CGtUnicodeFPUsiPCUs(self->field_329DC, 0x544, func_00271A00(&D_0051BA44, 0xD50));
    int n = Length__10CGtUnicodeFPCUs(self->field_329DC);
    self->field_329DC[n] = 0xA;
    CopyN__10CGtUnicodeFPUsiPCUs(self->field_329DC + (n + 1), 0x544 - (n + 1), func_00271A00(&D_0051BA44, 0xD51));
    n = Length__10CGtUnicodeFPCUs(self->field_329DC);
    self->field_329DC[n] = 0xA;
    CopyN__10CGtUnicodeFPUsiPCUs(self->field_329DC + (n + 1), 0x544 - (n + 1), func_00271A00(&D_0051BA44, 0xD52));
    if (self->field_329E0 == 0) return 0;
    self->field_329F0 = 0;
    self->field_329F4 = -1;
    int count = self->field_329D0->field_0;
    UnkStruct_26C190_ent *entries = self->field_329D0->field_8;
    int off = count * 16 + 8;
    int rem = off % 0x800;
    if (rem != 0) off = off + (0x800 - rem);
    char name[0x10];
    for (int i = 0; i < count; i++) {
        UnkStruct_26C190_ent *e = &entries[i];
        func_0021ADF0(e->field_0, name);
        if (strncmp(name, D_004BCA50, 7) == 0) {
            int t = e->field_C + off;
            self->field_329D8 = (char *)self->field_329D0 + t;
        } else if (strncmp(name, D_004BCA58, 9) == 0) {
            int t = e->field_C + off;
            self->field_329D4 = (char *)self->field_329D0 + t;
            self->field_329F4 = e->field_8;
        }
    }
    return 1;
}
