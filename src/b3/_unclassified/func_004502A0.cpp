// Hand-written; the lifter refused it (a158: table-row Prepare; inline of func_00453380 layout x4, sum as one expression + named last term, cnt float local).

// func_004502A0 -- hand-written (a158): table component, build the rows for the current mode, then lay the frames out (func_00453380's body inlined).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_byte { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_sbyte { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_word { unsigned int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_byte D_01ECDAC5;
extern UnkStruct_D_byte D_01ECDAC7;
extern UnkStruct_D_byte D_01ECDAC8;
extern UnkStruct_D_sbyte D_01ECDACE;
extern UnkStruct_D_word D_01ECDA0C;
extern UnkStruct_P16 D_01ECD9F0;
struct UnkStruct_004502A0_frame { CGtV2d field_0; };
struct UnkStruct_004502A0_row {
    unsigned char pad_0[8];
    UnkStruct_004502A0_frame *field_8;
    unsigned char pad_C[0x18];
};
struct UnkStruct_004502A0 {
    unsigned char pad_0[0xC];
    UnkStruct_004502A0_row field_C[8];
    unsigned char pad_12C[8];
    int field_134;
    int field_138;
};
extern "C" void func_00453560(void *);
extern "C" void func_004508A0(void *);
extern "C" void func_004526F0(void *);
extern "C" int func_0042EE00(void *, int);
extern "C" void func_004506E0(void *, int, int, int, int);
extern "C" void func_00453380(void *, int, int, float, float, float);

static inline void func_004502A0_inl1(UnkStruct_004502A0 *self, int from, int to, float base, float stride)
{
    if (from != to) {
        float cnt = (float)(to - from - 1);
        float y = 0.0f + base - 0.5f * (cnt * stride);
        int i;
        for (i = from; i < to; i++) {
            self->field_C[i].field_8->field_0 = CGtV2d(640.0f, y);
            y += stride;
        }
    }
}

// 0x004502A0
extern "C" int func_004502A0(UnkStruct_004502A0 *self)
{
    int s0;
    int s2;
    int r;
    int t0;
    func_00453560(self);
    s0 = self->field_138;
    self->field_134 = 3;
    if (D_01ECDAC5.field_0 != 0) {
        func_004508A0(self);
        func_004502A0_inl1(self, s0, self->field_138, 150.0f, 34.0f);
        s0 = self->field_138;
        func_004526F0(self);
        func_004502A0_inl1(self, s0, self->field_138, 330.0f, 50.0f);
        r = D_01ECDAC8.field_0;
        goto tail;
    }
    r = func_0042EE00(&D_01ECD9F0, 7);
    if (r > 0) {
        func_004506E0(self, self->field_138, 0x9D1, 0x9D2, r);
        self->field_138 = self->field_138 + 1;
    }
    t0 = D_01ECDACE.field_0;
    if (t0 > 0) {
        func_004506E0(self, self->field_138, 0x9D3, 0x9D4, t0);
        self->field_138 = self->field_138 + 1;
    }
    s2 = func_0042EE00(&D_01ECD9F0, 0) + func_0042EE00(&D_01ECD9F0, 1) + func_0042EE00(&D_01ECD9F0, 2) + func_0042EE00(&D_01ECD9F0, 4);
    int c5 = func_0042EE00(&D_01ECD9F0, 5);
    t0 = c5 + s2;
    if (t0 > 0) {
        func_004506E0(self, self->field_138, 0x9D5, 0x9D6, t0);
        self->field_138 = self->field_138 + 1;
    }
    func_00453380(self, s0, self->field_138, 180.0f, 34.0f, 640.0f);
    s0 = self->field_138;
    if ((D_01ECDA0C.field_0 & 0x10) != 0) func_004526F0(self);
    func_004508A0(self);
    func_004502A0_inl1(self, s0, self->field_138, 340.0f, 44.0f);
    r = D_01ECDAC7.field_0;
tail:
    if (r != 0) {
        int n = self->field_138;
        if (n > 1) {
            int a1 = n - 1;
            func_004502A0_inl1(self, 0, a1, 150.0f, 34.0f);
            n = self->field_138;
            self->field_C[n - 1].field_8->field_0 = CGtV2d(640.0f, 50.0f + self->field_C[n - 2].field_8->field_0.marValues[1]);
        }
    }
    return 1;
}
