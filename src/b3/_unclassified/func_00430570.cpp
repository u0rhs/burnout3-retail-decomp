// Hand-written; the lifter refused it (CB3MenuFinishedEvent-style string-id setup; sibling func_00430720 shape).

struct UnkStruct_D_0064EA70 {
    short field_0;
    unsigned char pad_2[6];
    int field_8;
    unsigned char pad_C[4];
};
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0064EA70 D_0064EA70;
extern UnkStruct_D_0051BA44 D_0051BA44;
struct UnkStruct_00430570 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    unsigned char pad_10[4];
    int field_14;
    unsigned char pad_18[4];
    int field_1C;
    int field_20;
    unsigned char pad_24[0xA0];
    int field_C4;
    unsigned char pad_C8[8];
    unsigned char field_D0;
};
extern "C" int func_00271A00(void *, int);
// 0x00430570
extern "C" void func_00430570(UnkStruct_00430570 * self)
{
    UnkStruct_D_0064EA70 * const g = &D_0064EA70;
    int a;
    int b;
    int c;
    self->field_1C = 13;
    self->field_20 = 9;
    self->field_14 = 2501;
    if (g->field_8 == 2) {
        b = 0x26C;
        self->field_C4 = 3;
        c = 0x32D;
        self->field_C = 4;
        a = b;
    } else if (g->field_8 == 3) {
        self->field_C4 = 3;
        b = 0x35A;
        self->field_C = 4;
        c = 0x32D;
        a = b;
    } else {
        switch (g->field_0) {
        case 1:
            self->field_C = 1;
            b = 0x336;
            self->field_C4 = 0;
            c = 0x32A;
            break;
        case 2:
            self->field_C = 2;
            b = 0x337;
            c = 0x32B;
            self->field_C4 = 1;
            break;
        case 3:
            self->field_C = 3;
            b = 0x338;
            self->field_C4 = 2;
            c = 0x32C;
            break;
        default:
            b = 0x339;
            c = 0x32D;
            self->field_C = 4;
            break;
        }
        if (self->field_D0 == 0) {
            self->field_C4 = 3;
            c = g->field_0 + 0x32D;
        }
        a = g->field_0 + 0x321;
    }
    if (a < 4005) {
        self->field_0 = func_00271A00(&D_0051BA44, a);
    }
    if (b < 4005) {
        self->field_4 = func_00271A00(&D_0051BA44, b);
    }
    if (c < 4005) {
        self->field_8 = func_00271A00(&D_0051BA44, c);
    }
}
