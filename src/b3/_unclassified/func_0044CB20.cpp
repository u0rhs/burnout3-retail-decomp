// Hand-written; the lifter refused it (a117: signed char i/int j=i search loop; [G] *(const signed char*)&field_1F8 pun for retail's reload).

struct UnkStruct_0044CB20 {
    unsigned char pad_0[0x1C0];
    signed char field_1C0[0x38];
    signed char field_1F8;
    signed char field_1F9;
};
struct UnkStruct_D_01E7A800 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E7A800 D_01E7A800;
extern float D_004E08B0;
extern "C" void func_00284400(void *, float, float);

// 0x0044CB20
extern "C" void func_0044CB20(UnkStruct_0044CB20 * self, int n)
{
    if (self->field_1F9 >= 0) return;
    while (self->field_1F8 < n) {
        signed char i = self->field_1F8;
        int j = i;
        while (j < n) {
            if (self->field_1C0[j] == i) {
                if (j != i) {
                    func_00284400(&D_01E7A800, D_004E08B0, 2.0f);
                    self->field_1F9 = j;
                    return;
                }
                break;
            }
            j++;
        }
        self->field_1F8 = *(const signed char *)&self->field_1F8 + 1;
    }
    self->field_1F9 = -1;
}
