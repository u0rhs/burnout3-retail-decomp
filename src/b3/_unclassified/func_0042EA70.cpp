// Hand-written; the lifter refused it (twin of func_0042E9F0).

// Hand-written (a108); twin of func_0042E9F0.
struct UnkStruct_0042EA70_self {
    unsigned char pad_0[0x34C];
    int field_34C[3];
    unsigned char pad_x[0xC];
    signed char field_364;
};

// 0x0042EA70
extern "C" int func_0042EA70(UnkStruct_0042EA70_self * self, int n1, int n2)
{
    if (n2 != 0) {
        int v = n1 + 1;
        if (v < 3) {
            return v;
        }
    } else {
        if (n1 == -1) {
            return self->field_34C[0];
        }
        int n = self->field_364;
        for (int i = 0; i < n; i++) {
            if (self->field_34C[i] == n1) {
                return self->field_34C[i + 1];
            }
        }
    }
    return -1;
}
