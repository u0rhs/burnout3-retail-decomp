// Hand-written; the lifter refused it (mwperm: 'e = arr[i];' -> 'UnkStruct_00375BF0_e * t7; UnkStruct_00375BF0_e *const  t5 = ((UnkStruct_00375BF').

// Update__15CB3ScrapeSystemFv -- hand-matched (a66).
// [L] DNAT: CB3ScrapeSystem::Update() (research/proto/new_names.csv, high); sibling Render() is B3ScrapeSystem_00375AA0.cpp
typedef unsigned int u_long128 __attribute__((mode(TI)));
enum UnkEnum_00375BF0 { UnkEnum_00375BF0_0 = 0, UnkEnum_00375BF0_1 = 1 };
struct UnkStruct_00375BF0_el {
    u_long128 a;
    u_long128 b;
};

struct UnkStruct_00375BF0_buf {
    int field_0;
    unsigned char pad_4[0xC];
    UnkStruct_00375BF0_el field_10[1];
};

struct UnkStruct_00375BF0_b {
    unsigned char pad_0[0x210];
};

struct UnkStruct_00375BF0_p {
    unsigned char pad_0[0x3C];
    float field_3C;
};

struct UnkStruct_00375BF0_e {
    unsigned char pad_0[0x4];
    float field_4;
    int field_8;
    UnkStruct_00375BF0_p * field_C;
    short field_10;
    unsigned char pad_12[0xE];
    UnkStruct_00375BF0_b field_20[2];
    UnkStruct_00375BF0_buf * field_440;
    UnkStruct_00375BF0_buf * field_444;
};

struct UnkStruct_00375BF0_s {
    unsigned char pad_0[0x8A00];
    UnkStruct_00375BF0_e ** field_8A00;
    int field_8A04;
    unsigned char pad_8A08[0x84];
    UnkStruct_00375BF0_e * field_8A8C[32];
    int field_8B0C;
};

struct UnkStruct_D_00522680 {
    float field_0;
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_00522680 D_00522680;
// [G] inlined predicate (retail materialises a bool, then compares it with 1)
static inline int func_00375BF0_inl0(const UnkStruct_00375BF0_e * e)
{
    return D_00522680.field_0 - e->field_4 > e->field_C->field_3C;
}

// 0x00375BF0
extern "C" void Update__15CB3ScrapeSystemFv(UnkStruct_00375BF0_s * self)
{
    int i = 0;
    UnkStruct_00375BF0_e ** const arr = self->field_8A8C;
    int * const cnt = &self->field_8B0C;
    UnkStruct_00375BF0_e ** const arrm = self->field_8A8C - 1;
    UnkStruct_00375BF0_e *** const fl = &self->field_8A00;
    int * const fc = &self->field_8A04;
    for (; ; i++) {
        if (i >= *cnt) return;
        UnkStruct_00375BF0_e * e = arr[i];
        if (e->field_10 & 3) {
            e->field_444->field_0 = e->field_440->field_0;
            e->field_444->field_10[e->field_444->field_0 - 1] = e->field_440->field_10[e->field_444->field_0 - 1];
            e->field_444->field_10[0] = e->field_440->field_10[0];
            e->field_10 &= ~3;
        }
        UnkEnum_00375BF0 v;
        if (D_00522680.field_0 - e->field_4 > e->field_C->field_3C) v = UnkEnum_00375BF0_1; else v = UnkEnum_00375BF0_0;
        if (v == UnkEnum_00375BF0_1) {

            UnkStruct_00375BF0_e * t7;
            UnkStruct_00375BF0_e *const  t5 = ((UnkStruct_00375BF0_e *)(t7 = arr[i]));
            t7 = t7;
            e = t5;
            e->field_8 = -1;
            if (i == *cnt - 1) {
                arr[i] = 0;
            } else {
                arr[i] = arrm[*cnt];
                arrm[*cnt] = 0;
            }
            (*cnt)--;
            i--;
            (*fl)[(*fc)++] = e;
        }
    }
}
