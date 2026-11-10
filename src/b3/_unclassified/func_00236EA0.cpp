// Hand-written; the lifter refused it (a119: init: c = field_98 + field_84*k computed before the slot pointer).

struct UnkStruct_00236EA0_slot {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    unsigned char field_10;
    unsigned char pad_11[3];
};
struct UnkStruct_00236EA0_blk { unsigned char pad_0[0x10]; };
struct UnkStruct_00236EA0_t { int field_0; int field_4; int field_8; };
struct UnkStruct_00236EA0 {
    int field_0;
    unsigned char pad_4[4];
    int field_8[8];
    int field_28;
    int field_2C[8];
    int field_4C;
    int field_50[8];
    int field_70;
    int field_74;
    unsigned char pad_78[4];
    int field_7C;
    unsigned char pad_80[4];
    int field_84;
    unsigned char pad_88[0xC];
    int field_94;
    int field_98;
    int field_9C;
    UnkStruct_00236EA0_slot field_A0[32];
    int field_320;
    UnkStruct_00236EA0_t field_324[10];
    int field_39C;
};
extern "C" void func_0022DA20(void *);
extern "C" void func_00234C40(void *);

// 0x00236EA0
extern "C" void func_00236EA0(UnkStruct_00236EA0 *self, int *src, int n, void *a3_, int t0, int t1)
{
    int a3 = (int)a3_;
    int i = 0;
    for (; i < n; i++) {
        self->field_2C[i] = src[i];
        self->field_8[i] = 0;
        self->field_50[i] = 0;
    }
    for (; i < 8; i++) {
        self->field_2C[i] = 0;
        self->field_8[i] = 0;
        self->field_50[i] = 0;
    }
    self->field_74 = n;
    self->field_28 = 0;
    self->field_4C = n;
    self->field_70 = 0;
    self->field_7C = 0;
    self->field_84 = t1;
    self->field_94 = 0;
    self->field_98 = a3;
    self->field_9C = t0;
    self->field_320 = 0;
    for (int k = 0; k < 32; k++) {
        int c = self->field_98 + self->field_84 * k;
        UnkStruct_00236EA0_slot *s = &self->field_A0[k];
        s->field_0 = -1;
        s->field_4 = 0;
        s->field_8 = -1;
        s->field_C = c;
        s->field_10 = 1;
    }
    for (int j = 0; j < 10; j++) func_0022DA20((char *)self + 0x3A0 + j * 16);
    for (int j = 0; j < 10; j++) func_0022DA20((char *)self + 0x440 + j * 16);
    for (int j = 0; j < 10; j++) {
        self->field_324[j].field_0 = -1;
        self->field_324[j].field_4 = -1;
        self->field_324[j].field_8 = -1;
    }
    self->field_39C = 0;
    func_00234C40((char *)self + 0x4E0);
    self->field_0 = 1;
}
