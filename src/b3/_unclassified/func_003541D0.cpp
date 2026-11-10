// Hand-written; the lifter refused it (recursive float sum over intrusive list).

struct UnkStruct_3541D0_d { unsigned char pad_0[0x60]; float field_60; };
struct UnkStruct_3541D0_l { UnkStruct_3541D0_l *field_0; };
struct UnkStruct_3541D0 {
    unsigned char pad_0[0x24];
    void *field_24;
    UnkStruct_3541D0_l field_28;
    unsigned char pad_2C[8];
    UnkStruct_3541D0_d *field_34;
};
// 0x003541D0
extern "C" float func_003541D0(void *self, UnkStruct_3541D0 *n)
{
    if (n->field_24 != 0) {
        float sum = 0.0f;
        UnkStruct_3541D0_l *p = n->field_28.field_0;
        while (p != &n->field_28) {
            UnkStruct_3541D0 *c = (UnkStruct_3541D0 *)((char *)p - 0x14);
            p = p->field_0;
            sum += func_003541D0(self, c);
        }
        *(float *)n->field_34 = sum;
        return sum;
    }
    return n->field_34->field_60;
}
