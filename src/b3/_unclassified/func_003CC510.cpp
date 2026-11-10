// Hand-written; the lifter refused it (N182 pragma pair match (lead): opt_propagation off + opt_rebuildconditionals off, scoped [G]).

// N182: retail compiled this function with `#pragma opt_propagation off` ([G] scoped to this function; with opt_rebuildconditionals off (pair sweep)).
#pragma push
#pragma opt_propagation off
#pragma opt_rebuildconditionals off

struct UnkStruct_C510 {
    unsigned char pad_0[0x18];
    int field_18[0x42];
    int field_120[0x42];
    float field_228[2][0x42];
    unsigned char pad_438[0x30];
    int field_468[8];
    float field_488[8];
    unsigned char field_4A8;
    unsigned char pad_4A9[6];
    unsigned char field_4AF;
};
struct UnkStruct_D_00665EA0 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_004F50A0 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_Gen { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00665EA0 D_00665EA0;
extern UnkStruct_D_004F50A0 D_004F50A0;
extern UnkStruct_Gen D_004EE040, D_01E959D0;
extern float D_004E0E24;
extern "C" int func_00131CA0(void *);
extern "C" void func_00423DC0(void *, int, int);

static inline float func_003CC510_inl1(UnkStruct_C510 *self, int i, int j)
{
    float x = self->field_228[j][i];
    float r;
    int k = 1 - j;
    if (x < D_004E0E24) r = 0.0f;
    else r = x / (x + self->field_228[k][i]);
    return r;
}

// 0x003CC510
extern "C" void func_003CC510(UnkStruct_C510 *self, int id)
{
    int i, n;
    int v;
    if (D_00665EA0.field_0 == 0) return;
    self->field_468[self->field_4A8] = id;
    self->field_488[self->field_4A8] = D_004F50A0.field_0;
    self->field_4A8 = self->field_4A8 + 1;
    if (self->field_4A8 >= 8) self->field_4A8 = 0;
    n = self->field_4AF;
    for (i = 0; i < n; i++) {
        if (self->field_18[i] == id) goto found;
    }
    i = -1;
found:
    v = self->field_120[i];
    if (func_00131CA0(&D_004EE040) != 0) {
        func_00423DC0(&D_01E959D0, 0, (int)((float)v * func_003CC510_inl1(self, i, 0)));
        func_00423DC0(&D_01E959D0, 1, (int)((float)v * func_003CC510_inl1(self, i, 1)));
    } else {
        func_00423DC0(&D_01E959D0, 0, v);
    }
}

#pragma pop
