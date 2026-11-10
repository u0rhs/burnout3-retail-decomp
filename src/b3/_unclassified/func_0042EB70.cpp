// Hand-written; the lifter refused it (twin of func_0042E9F0).

// Hand-written (a108); twin of func_0042E9F0.
struct UnkStruct_0042EB70_self {
    unsigned char pad_0[0x1A0];
    int field_1A0[10];
    unsigned char pad_x[0x198];
    signed char field_360;
};

// 0x0042EB70
extern "C" int func_0042EB70(UnkStruct_0042EB70_self * self, int n1, int n2)
{
    if (n2 != 0) {
        int v = n1 + 1;
        if (v < 10) {
            return v;
        }
    } else {
        if (n1 == -1) {
            return self->field_1A0[0];
        }
        int n = self->field_360;
        for (int i = 0; i < n; i++) {
            if (self->field_1A0[i] == n1) {
                return self->field_1A0[i + 1];
            }
        }
    }
    return -1;
}
