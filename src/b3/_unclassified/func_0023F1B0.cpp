// Hand-written; the lifter refused it (u16 wraparound compare/diff as two static inlines; '> 0xAAAA' gives slt at).

struct UnkStruct_0023F1B0 {
    unsigned char pad_0[0x5CC];
    int field_5CC;
    int field_5D0;
    int field_5D4[1];
};
struct UnkStruct_D_004E1970 {
    int field_0;
};
extern UnkStruct_D_004E1970 D_004E1970;

static inline bool func_0023F1B0_inl1(unsigned short a, unsigned short b)
{
    if (a < 0x5555) {
        if (b > 0xAAAA) {
            return true;
        }
    }
    if (b < 0x5555) {
        if (a > 0xAAAA) {
            return false;
        }
    }
    if (b < a) {
        return true;
    }
    return false;
}

static inline unsigned short func_0023F1B0_inl2(unsigned short a, unsigned short b)
{
    if (b < 0x5555) {
        if (a > 0xAAAA) {
            return b + (0xFFFF - a);
        }
    }
    return b - a;
}

// 0x0023F1B0
extern "C" void func_0023F1B0(UnkStruct_0023F1B0 *self, int p0, int p1)
{
    unsigned short d;
    if (func_0023F1B0_inl1(p0, p1)) {
        d = 0;
    } else {
        d = func_0023F1B0_inl2(p0, p1);
    }
    self->field_5D4[self->field_5D0] = d;
    self->field_5D0 = self->field_5D0 + 1;
    if (self->field_5D0 >= D_004E1970.field_0) {
        self->field_5D0 = 0;
    }
    self->field_5CC = 0;
    for (int i = 0; i < D_004E1970.field_0; i++) {
        self->field_5CC = self->field_5CC + self->field_5D4[i];
    }
    self->field_5CC = self->field_5CC / D_004E1970.field_0;
}
