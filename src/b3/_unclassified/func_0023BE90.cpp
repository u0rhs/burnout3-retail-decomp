// Hand-written; the lifter refused it (a120: bool lim, cnt hoist, RELOC only ofs_00122A10 constant (a107)).

class CGtNetworkPlayerManager {
public:
    int GetMyPlayerIndex() const;
    unsigned char pad_0[0x8];
    int field_8[1];
    unsigned char pad_C[0x4];
};
struct UnkStruct_D_01E32B08 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064517C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004E2A14 { unsigned short field_0; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
struct UnkStruct_0023BE90_car { unsigned char pad_0[0x242B]; signed char field_242B; };
struct UnkStruct_0023BE90 {
    unsigned char pad_0[0xC];
    CGtNetworkPlayerManager * field_C;
    unsigned char pad_10[0x6C4];
    unsigned short field_6D4;
    short field_6D6;
};
extern UnkStruct_D_01E32B08 D_01E32B08;
extern CGtNetworkPlayerManager D_01E32AE0;
extern UnkStruct_D_0064517C D_0064517C;
extern UnkStruct_D_004E2A14 D_004E2A14;
extern UnkStruct_D_00522660 D_00522660;
extern unsigned char D_004EE040[0x10];
extern "C" bool func_00131E40(void *);
extern "C" float ceilf(float);

static inline unsigned short func_0023BE90_inl2(unsigned short a, unsigned short b)
{
    if (b < 0x5555) {
        if (a > 0xAAAA) {
            return b + (0xFFFF - a);
        }
    }
    return b - a;
}

// 0x0023BE90
extern "C" int func_0023BE90(UnkStruct_0023BE90 * self)
{
    int n = 0;
    if (D_0064517C.field_0 == 0) return 1;
    bool bb = func_00131E40(&D_004EE040);
    int lim = bb ? 0x18 : 8;
    int i;
    int c = 0;
    for (i = 0; i < D_01E32B08.field_0; i++) {
        if (D_01E32AE0.field_8[i] != 0) c++;
    }
    float fc = (float)c;
    int cnt = D_0064517C.field_0;
    int s2;
    for (s2 = 0; s2 < cnt; s2++) {
        UnkStruct_0023BE90_car *car = *(UnkStruct_0023BE90_car **)((char *)&D_00522660 + s2 * 4 + 0x122A10);
        int pi = car->field_242B;
        if (pi == self->field_C->GetMyPlayerIndex()) {
            if (!(n < lim)) break;
            n++;
        }
    }
    if (n == 0) return 1;
    float t = 10240.0f / fc;
    float u = 60.0f / (float)self->field_6D6;
    float w = (0.0f + t) - 76.0f * u;
    w = w / (float)(unsigned int)(n * 22);
    int a2 = (int)ceilf(60.0f / w);
    unsigned short a3 = D_004E2A14.field_0;
    if (a3 == 0xFFFF) a3 = 0;
    unsigned short a1 = self->field_6D4;
    if (a1 != 0xFFFF) {
        unsigned short d = func_0023BE90_inl2(a1, a3);
        if (d < a2) return 0;
    }
    self->field_6D4 = a3;
    return 1;
}
