// Hand-written; the lifter refused it (a135: T* const p = &D_0064EA70; first; byte-offset lb loop; switch 0,1,2,default).

struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064EA70 { short field_0; unsigned char pad_2[6]; int field_8; unsigned char pad_C[4]; };
struct UnkStruct_D_0051B930_t { unsigned char pad_0[0x38]; int field_38; };
struct UnkStruct_D_0051B930 { UnkStruct_D_0051B930_t *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051B938 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00430840 {
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
    unsigned char pad_28[0xA0];
    int field_C8;
    unsigned char pad_CC[6];
    unsigned char field_D2;
    unsigned char pad_D3[7];
    unsigned char field_DA;
    signed char field_DB;
    signed char field_DC;
    unsigned char pad_DD[2];
    unsigned char field_DF;
};
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_0064EA70 D_0064EA70;
extern UnkStruct_D_0051B930 D_0051B930;
extern UnkStruct_D_0051B938 D_0051B938;
extern "C" int func_00271A00(void *, int);

// 0x00430840
extern "C" void func_00430840(UnkStruct_00430840 * self)
{
    UnkStruct_D_0064EA70 * const p = &D_0064EA70;
    int s1;
    int a;
    int s0;
    self->field_DA = 1;
    self->field_DB = D_0051B938.field_0 + 1;
    self->field_DC = D_0051B930.field_0->field_38;
    self->field_D2 = self->field_DB < self->field_DC;
    self->field_1C = 13;
    if (p->field_0 == 6) {
        self->field_C = 4;
        s1 = 0x339;
    } else {
        self->field_C = 1;
        s1 = 0x35F;
    }
    s0 = p->field_0 + 0x363;
    if (p->field_8 == 2) {
        a = 0x26C;
    } else {
        a = p->field_0 + 0x321;
    }
    if (self->field_D2 == 0) {
        int i = 0;
        int n = D_0064D37C.field_0;
        self->field_14 = 0x9CD;
        self->field_10 = 0x386;
        self->field_24 = 1;
        self->field_20 = 9;
        while (i < n) {
            if (*((signed char *)&D_004EE040 + i + 0x2D92C) == 0) break;
            i++;
        }
        switch (i) {
        case 0: self->field_C8 = 0; break;
        case 1: self->field_C8 = 1; break;
        case 2: self->field_C8 = 2; break;
        default: self->field_C8 = 3; break;
        }
        self->field_18 = i + 0x322;
        self->field_DF = 3;
    } else {
        self->field_24 = 15;
        self->field_14 = 0x9D0;
    }
    if (a < 4005) self->field_0 = func_00271A00(&D_0051BA44, a);
    if (s1 < 4005) self->field_4 = func_00271A00(&D_0051BA44, s1);
    if (s0 < 4005) self->field_8 = func_00271A00(&D_0051BA44, s0);
}
