// Hand-written; the lifter refused it (save checksum verify; s0[0x3C52] for first compare, byte-offset pun second; i declared first; k then sum init order).

struct UnkStruct_00421700 {
    int field_0;
    int field_4[3];
    signed char field_10[3];
    unsigned char pad_13[0x9];
    int field_1C;
};
struct UnkStruct_D_01EA7810_x { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01EA7810_x D_01EA7810;
extern "C" void func_003D0B70(void *, void *);
extern "C" float func_0013A560(float *, void *);
// 0x00421700
extern "C" int func_00421700(UnkStruct_00421700 *self)
{
    unsigned int i;
    int *s0 = &self->field_1C;
    if (self->field_1C != 0x10) {
        return 2;
    }
    unsigned int k;
    int sum = 0;
    k = 0;
    do {
        sum += s0[k];
        k++;
    } while (k < 0x3C52);
    if (sum != s0[0x3C52]) {
        return 2;
    }
    func_003D0B70((char *)self + 0x20, &D_01EA7810);
    if (self->field_0 != ((int *)((char *)s0 + 0x10000))[-942]) {
        return 1;
    }
    for (i = 0; i < 3; i++) {
        char *r = (char *)s0 + i * 0x49C;
        int a = self->field_10[i];
        int b = ((signed char *)r)[0xE80F] != 0;
        if (a != b) return 1;
        if (a == 0) {
            float t;
            func_0013A560(&t, r + 0xE374);
            union { float f; int i; } u;
            u.f = t;
            if (self->field_4[i] != u.i) return 1;
        }
    }
    return 0;
}
