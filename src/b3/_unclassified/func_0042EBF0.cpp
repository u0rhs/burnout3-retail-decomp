// Hand-written; the lifter refused it (twin of func_0042E9F0).

// Hand-written (a108); twin of func_0042E9F0.
struct UnkStruct_0042EBF0_self {
    unsigned char pad_0[0x14C];
    int field_14C[20];
    unsigned char pad_x[0x1C2];
    signed char field_35E;
};

// 0x0042EBF0
extern "C" int func_0042EBF0(UnkStruct_0042EBF0_self * self, int n1, int n2)
{
    if (n2 != 0) {
        int v = n1 + 1;
        if (v < 20) {
            return v;
        }
    } else {
        if (n1 == -1) {
            return self->field_14C[0];
        }
        int n = self->field_35E;
        for (int i = 0; i < n; i++) {
            if (self->field_14C[i] == n1) {
                return self->field_14C[i + 1];
            }
        }
    }
    return -1;
}
