// Hand-written; the lifter refused it (a209: n++ after the 6A==0 block (branch target of bnez)).


struct UnkStruct_D_0051BAC8 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BAC8 D_0051BAC8;
struct UnkStruct_D_0064CE40 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064CE40 D_0064CE40;
extern "C" void func_003CC510(void *, int);
struct UnkStruct_00353640_e {
    unsigned char pad_0[0x40];
    int field_40;
    unsigned char pad_44[0x14];
    float field_58;
    float field_5C;
    unsigned char pad_60[0xA];
    unsigned char field_6A;
    unsigned char pad_6B[5];
};
struct UnkStruct_00353640 {
    unsigned char pad_0[0x2E0];
    UnkStruct_00353640_e field_2E0[1];
    unsigned char pad_350[0xCE0];
    int field_1030;
    unsigned char pad_1034[0xC];
    float field_1040;
};
// 0x00353640
extern "C" int func_00353640(UnkStruct_00353640 *self, float x, float w)
{
    UnkStruct_00353640_e *best = 0;
    float v0 = w;
    int n = 0;
    float bestval = 0.0f;
    self->field_1040 = self->field_1040 + D_0051BAC8.field_0;
    for (int i = 0; i < self->field_1030; i++) {
        UnkStruct_00353640_e *e = &self->field_2E0[i];
        if (*((unsigned char *)e + 0x69) != 0) continue;
        if (e->field_58 <= x) continue;
        if (!(e->field_58 < (x + v0))) continue;
        if (e->field_6A == 0) {
            if (e->field_58 < (0.0f + x + 0.5f * v0)) {
                best = e;
            } else if (e->field_5C > bestval) {
                bestval = e->field_5C;
                best = e;
            }
        }
        n++;
    }
    if (self->field_1040 > 0.25f && best != 0) {
        func_003CC510(&D_0064CE40, best->field_40);
        best->field_6A = 1;
        self->field_1040 = 0;
    }
    return n;
}
