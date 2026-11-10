// Hand-written; the lifter refused it (twin; arr[i] > n1).

// Hand-written (a108); twin of func_0042E9F0, "first element greater than n1".
struct UnkStruct_0042EC70_self {
    unsigned char pad_0[0x138];
    int field_138[4];
    unsigned char pad_x[0x35D - 0x148];
    signed char field_35D;
};

// 0x0042EC70
extern "C" int func_0042EC70(UnkStruct_0042EC70_self * self, int n1, int n2)
{
    if (n2 != 0) {
        int v = n1 + 1;
        if (v < 4) {
            return v;
        }
    } else {
        if (n1 == -1) {
            return self->field_138[0];
        }
        int n = self->field_35D;
        for (int i = 0; i < n; i++) {
            if (self->field_138[i] > n1) {
                return self->field_138[i];
            }
        }
    }
    return -1;
}
