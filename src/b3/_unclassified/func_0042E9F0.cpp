// Hand-written; the lifter refused it (twin of func_0042E970).

struct UnkStruct_0042E9F0_self {
    unsigned char pad_0[0x308];
    int field_308[10];
    unsigned char pad_330[0x31];
    signed char field_361;
};

// 0x0042E9F0
extern "C" int func_0042E9F0(UnkStruct_0042E9F0_self * self, int n1, int n2)
{
    if (n2 != 0) {
        int v = n1 + 1;
        if (v < 10) {
            return v;
        }
    } else {
        if (n1 == -1) {
            return self->field_308[0];
        }
        int n = self->field_361;
        for (int i = 0; i < n; i++) {
            if (self->field_308[i] == n1) {
                return self->field_308[i + 1];
            }
        }
    }
    return -1;
}
