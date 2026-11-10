// Hand-written; the lifter refused it (pmaxw/pextlw helpers; (unsigned)(x-3) <= 1 gives sltiu at).

struct UnkStruct_0042B5F0_obj { unsigned char pad_0[0xA0]; unsigned char field_A0; };
struct UnkStruct_0042B5F0_ent { UnkStruct_0042B5F0_obj * field_0; int field_4; signed char field_8; unsigned char pad_9[3]; };
struct UnkStruct_0042B5F0_self {
    unsigned char pad_0[0xC];
    UnkStruct_0042B5F0_ent field_C[8];
    unsigned char pad_6C[0x238 - 0x6C];
    int field_238;
};

static inline int a107_pmaxw(int a, int b)
{
    int r;
    asm("pmaxw %0,%1,%2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline unsigned int a107_pextlw0(int a)
{
    unsigned int r;
    asm("pextlw %0,$0,%1" : "=r"(r) : "r"(a));
    return r;
}

// 0x0042B5F0
extern "C" int func_0042B5F0(UnkStruct_0042B5F0_self * self, int n1)
{
    if ((unsigned int)(self->field_238 - 3) <= 1) {
        return 0;
    }
    UnkStruct_0042B5F0_obj * o = self->field_C[n1].field_0;
    int n = 0;
    if (o) {
        n = o->field_A0;
    }
    return self->field_C[n1].field_8 % (int)a107_pextlw0(a107_pmaxw(n, 1));
}
