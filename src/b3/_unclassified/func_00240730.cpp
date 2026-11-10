// Hand-written; the lifter refused it (a120: sum reassigned in two statements keeps f20; int cnt).

struct UnkStruct_00240730_q {
    unsigned char field_0;
    unsigned char pad_1[0xF];
    float field_10;
    float field_14;
};
struct UnkStruct_00240730 {
    unsigned char pad_0[0x50];
    float field_50[4];
    float field_60[4];
    int field_70;
    unsigned char field_74;
    unsigned char field_75;
    unsigned short field_76;
    unsigned char field_78;
    unsigned char field_79;
};
extern "C" UnkStruct_00240730_q * func_00240D10(UnkStruct_00240730 *);
extern "C" void func_00240D40(UnkStruct_00240730 *, int, float, float);

static inline unsigned short func_00240730_inl2(unsigned short a, unsigned short b)
{
    if (b < 0x5555) {
        if (a > 0xAAAA) {
            return b + (0xFFFF - a);
        }
    }
    return b - a;
}

// 0x00240730
extern "C" void func_00240730(UnkStruct_00240730 * self, int p0, float * p1)
{
    float sum = 0.0f;
    UnkStruct_00240730_q * q = func_00240D10(self);
    if (q != 0) {
        self->field_50[self->field_78] = *p1 - q->field_10;
        self->field_78 = (self->field_78 + 1) % 4;
        if (self->field_74 < 4) {
            self->field_74++;
        }
        self->field_70 = self->field_70 + 1;
        int cnt = self->field_74;
        unsigned char i = 0;
        while (i < cnt) {
            sum += self->field_50[i];
            i++;
        }
        sum = sum / (float)(unsigned int)cnt;
        sum = sum / 2.0f;
        self->field_60[self->field_79] = *p1 - (q->field_14 + sum);
        self->field_79 = (self->field_79 + 1) % 4;
        if (self->field_75 < 4) {
            self->field_75++;
        }
        *p1 = q->field_14 + sum;
        q->field_0 = q->field_0 & ~1;
    }
    unsigned short last = self->field_76;
    if (last == 0xFFFF || !(func_00240730_inl2(last, p0) < 6)) {
        self->field_76 = p0;
        func_00240D40(self, (unsigned short)p0, *p1, 0.0f);
    }
}
