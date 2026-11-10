// Hand-written; the lifter refused it (day-of-year calc; bool leap if-chain inline; table copy as struct {int[6] lo; int[6] hi} pun gives lw/sw pair loop).

struct UnkStruct_0045C890_d { int field_0; int field_4; int field_8; int field_C; };
struct UnkStruct_D_004B06C0 { int field_0[6]; };
struct UnkStruct_004B06C0_x { UnkStruct_D_004B06C0 lo; UnkStruct_D_004B06C0 hi; };
extern UnkStruct_D_004B06C0 D_004B06C0;

static inline bool func_0045C890_inl1(int y)
{
    bool leap;
    if (y % 400 == 0) {
        leap = true;
    } else if (y % 100 == 0) {
        leap = false;
    } else {
        if (y % 4 == 0) {
            leap = true;
        } else {
            leap = false;
        }
    }
    return leap;
}

// 0x0045C890
extern "C" void func_0045C890(UnkStruct_0045C890_d *self, int a1, int a2, int a3)
{
    self->field_4 = a2;
    self->field_8 = a1;
    self->field_C = a3;
    self->field_C = self->field_C - 1;
    self->field_0 = 0;
    self->field_0 = self->field_0 + self->field_C * 365;
    self->field_0 = self->field_0 + self->field_C / 4;
    self->field_0 = self->field_0 - self->field_C / 100;
    self->field_0 = self->field_0 + self->field_C / 400;
    int i = 1;
    for (; i < self->field_4; i++) {
        int y = self->field_C;
        UnkStruct_004B06C0_x tbl = *(UnkStruct_004B06C0_x *)&D_004B06C0;
        int add;
        if (i == 2 && func_0045C890_inl1(y)) {
            add = 29;
        } else {
            add = ((int *)&tbl)[i - 1];
        }
        self->field_0 = self->field_0 + add;
    }
    self->field_0 = self->field_0 + self->field_8;
}
