// Hand-written; the lifter refused it (twin of func_0042E9F0).

// Hand-written (a108); twin of func_0042E9F0.
struct UnkStruct_0042EAF0_self {
    unsigned char pad_0[0x1CC];
    int field_1CC[10];
    unsigned char pad_x[0x16C];
    signed char field_360;
};

// 0x0042EAF0
extern "C" int func_0042EAF0(UnkStruct_0042EAF0_self * self, int n1, int n2)
{
    if (n2 != 0) {
        int v = n1 + 1;
        if (v < 10) {
            return v;
        }
    } else {
        if (n1 == -1) {
            return self->field_1CC[0];
        }
        int n = self->field_360;
        for (int i = 0; i < n; i++) {
            if (self->field_1CC[i] == n1) {
                return self->field_1CC[i + 1];
            }
        }
    }
    return -1;
}
