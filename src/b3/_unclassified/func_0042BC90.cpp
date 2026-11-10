// Hand-written; the lifter refused it (a107 match (0 off); lead: retail's %hi/%lo(D_0012FD30) is the constant 0x12FD30, same bytes).

#include "b3/classes/UnkStruct_D_00522660.h"

struct UnkStruct_D_01E8EBDE { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_0042BC90_blk { unsigned char pad_0[0x60]; struct UnkStruct_0042BC90_obj * field_60; };
struct UnkStruct_0042BC90_obj { unsigned char pad_0[0xA0]; unsigned char field_A0; };
struct UnkStruct_0042BC90_ent { UnkStruct_0042BC90_obj * field_0; int field_4; signed char field_8; unsigned char pad_9[3]; };
struct UnkStruct_0042BC90_self {
    unsigned char pad_0[0xC];
    UnkStruct_0042BC90_ent field_C[8];
    unsigned char pad_6C[0x1EC - 0x6C];
    void * field_1EC;
    void * field_1F0;
    unsigned char pad_1F4[0x244 - 0x1F4];
    int field_244;
    unsigned char pad_248[0x260 - 0x248];
    int field_260;
};

extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_01E8EBDE D_01E8EBDE;
extern "C" void func_00427070(void *, int);

static inline int a107_pminw(int a, int b)
{
    int r;
    asm("pminw %0,%1,%2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline unsigned int a107_pextlw0(int a)
{
    unsigned int r;
    asm("pextlw %0,$0,%1" : "=r"(r) : "r"(a));
    return r;
}

// 0x0042BC90
extern "C" void func_0042BC90(UnkStruct_0042BC90_self * self)
{
    int p = D_01E8EBDE.field_0;
    UnkStruct_0042BC90_blk * blk = *(UnkStruct_0042BC90_blk **)((char *)&D_00522660 + p * 0x2460 + 0x12FD30);
    int n = blk->field_60->field_A0;
    self->field_C[self->field_244].field_8 = (self->field_C[self->field_244].field_8 + 1) % (int)a107_pextlw0(a107_pminw(n, 6));
    if (self->field_260 == -1) {
        int c = self->field_C[self->field_244].field_0->field_A0;
        if (c != 0) {
            int m = self->field_C[self->field_244].field_8 % (int)a107_pextlw0(a107_pminw(c, 6));
            if (self->field_244 == 0) {
                func_00427070(self->field_1EC, m);
            } else {
                func_00427070(self->field_1F0, m);
            }
        }
    }
}
