// Hand-written; the lifter refused it (N182 pragma match (lead): archive source + scoped optimiser pragma).

// N182: retail compiled this function with `#pragma opt_dead_assignments off` ([G] scoped to this function).
#pragma push
#pragma opt_dead_assignments off

struct UnkStruct_B { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_B2 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_arr { signed char b[0x2C]; };
struct UnkStruct_D_004F5040 { UnkStruct_arr field_0; unsigned char pad_2C[0x14]; };
struct UnkStruct_big { unsigned char pad_0[0x10]; };
struct UnkStruct_00322EA0 {
    unsigned char pad_0[0x10];
    UnkStruct_arr field_10;
    unsigned char field_3C;
    unsigned char field_3D;
    unsigned char field_3E;
    unsigned char field_3F;
    signed char field_40;
    signed char field_41;
    signed char field_42;
    signed char field_43;
    signed char field_44;
    signed char field_45;
    signed char field_46;
    signed char field_47;
    signed char field_48;
    signed char field_49;
    signed char field_4A;
    signed char field_4B;
    signed char field_4C;
    unsigned char field_4D;
    unsigned char field_4E;
    signed char field_4F;
    int field_50;
};
extern UnkStruct_D_004F5040 D_004F5040;
extern UnkStruct_B D_004F506C;
extern UnkStruct_B D_004F506D;
extern UnkStruct_B D_004F506E;
extern UnkStruct_B D_004F506F;
extern UnkStruct_B D_004F5070;
extern UnkStruct_B D_004F5071;
extern UnkStruct_B D_004F5072;
extern UnkStruct_B D_004F5073;
extern UnkStruct_B D_004F5074;
extern UnkStruct_B D_004F5075;
extern UnkStruct_B D_004F5076;
extern UnkStruct_B D_004F5077;
extern UnkStruct_B D_004F5078;
extern UnkStruct_B D_004F5079;
extern UnkStruct_B D_004F507A;
extern UnkStruct_B D_004F507B;
extern UnkStruct_B D_004F507C;
extern UnkStruct_B D_004F507D;
extern UnkStruct_B D_004F507E;
extern UnkStruct_B D_004F507F;
extern UnkStruct_big D_01E94C94;
extern UnkStruct_big D_01E77540;
extern UnkStruct_B D_0064ED5D;
extern "C" int func_00342410(void *, int, int);
extern "C" void func_00288F50(void *);
extern "C" void func_0021B4F0(void *);

// 0x00322EA0
extern "C" void func_00322EA0(UnkStruct_00322EA0 * self, int p1, int p2, int p3)
{
    switch (p3) {
    case 1:
        self->field_50 = 0;
        func_00342410(&D_01E94C94, 1, 0);
        return;
    case 6:
        self->field_50 = 0;
        D_0064ED5D.field_0 = 1;
        func_00288F50(&D_01E77540);
        return;
    case 3:
        self->field_50 = 0;
        func_00342410(&D_01E94C94, 1, 0);
    case 0x4A:
        D_004F5040.field_0 = self->field_10;
        unsigned char b0 = self->field_3C;
        unsigned char b1 = self->field_3D;
        unsigned char b2 = self->field_3E;
        unsigned char b3 = self->field_3F;
        D_004F506C.field_0 = b0;
        D_004F506D.field_0 = b1;
        D_004F506E.field_0 = b2;
        D_004F506F.field_0 = b3;
        D_004F5070.field_0 = self->field_40;
        D_004F5071.field_0 = self->field_41;
        D_004F5072.field_0 = self->field_42;
        D_004F5073.field_0 = self->field_43;
        D_004F5074.field_0 = self->field_44;
        D_004F5075.field_0 = self->field_45;
        D_004F5076.field_0 = self->field_46;
        D_004F5077.field_0 = self->field_47;
        D_004F5078.field_0 = self->field_48;
        D_004F5079.field_0 = self->field_49;
        D_004F507A.field_0 = self->field_4A;
        D_004F507B.field_0 = self->field_4B;
        D_004F507C.field_0 = self->field_4C;
        unsigned char b4 = self->field_4D;
        unsigned char b5 = self->field_4E;
        D_004F507D.field_0 = b4;
        D_004F507E.field_0 = b5;
        D_004F507F.field_0 = self->field_4F;
    case 0x4B:
        func_0021B4F0(&D_004F5040);
        return;
    }
}

#pragma pop
