// Hand-written; the lifter refused it (next-in-list lookup; single shared return -1).

struct UnkStruct_0042E970_self {
    unsigned char pad_0[0x334];
    int field_334[5];
    unsigned char pad_348[0x1A];
    signed char field_362;
};

// 0x0042E970
extern "C" int func_0042E970(UnkStruct_0042E970_self * self, int n1, int n2)
{
    if (n2 != 0) {
        int v = n1 + 1;
        if (v < 5) {
            return v;
        }
    } else {
        if (n1 == -1) {
            return self->field_334[0];
        }
        int n = self->field_362;
        for (int i = 0; i < n; i++) {
            if (self->field_334[i] == n1) {
                return self->field_334[i + 1];
            }
        }
    }
    return -1;
}
