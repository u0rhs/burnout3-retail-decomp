// NONMATCHING: func_0044C7F0 -- retail 89 / ours 89 instructions, 12 in changed runs
// 12 off (pass3a: byte slots as int arithmetic (a + (int)self) + 0x1C0 give retail's addu a1,a0 order, 13->12). Left: temp regs t6/t5/t7 vs ours t2/t1/t5 and retail hoisting the tt copy-loop init (addiu t2,sp,16; li t1,5) to the top. Tried: inline Swap helpers (much worse), tt/pad declared at top, tt copy before the h reads, 15-pragma sweep, sreg 2 rounds (210 variants): no change
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_propagation off
// a222: 18 changed (was 25); left: byte-swap/row regs t6/t4/t5 vs t2/t1/t4, loop-init addiu/li hoisted early in retail, float t order. t as struct copy keeps dead sp+0x28 stores
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.


struct UnkStruct_0044C7F0_v { float x; float y; };
struct UnkStruct_0044C7F0_h {
    int field_0;
    int field_4;
    UnkStruct_0044C7F0_v * field_8;
    int field_C;
};
struct UnkStruct_0044C7F0_t { int field_0[5]; };
struct UnkStruct_0044C7F0_r {
    UnkStruct_0044C7F0_h h;
    UnkStruct_0044C7F0_t t;
};
struct UnkStruct_0044C7F0 {
    unsigned char pad_0[0xC];
    UnkStruct_0044C7F0_r field_C[1];
    unsigned char pad_30[0x190];
    signed char field_1C0[1];
    unsigned char pad_1C1[0x39];
    signed char field_1FA;
};
struct UnkStruct_0044C7F0_pad { UnkStruct_0044C7F0_pad() {} ~UnkStruct_0044C7F0_pad() {} int x[4]; };
// 0x0044C7F0
extern "C" void func_0044C7F0(UnkStruct_0044C7F0 * self, int a, int b)
{
    signed char * ca = (signed char *)(a + (int)self) + 0x1C0;
    signed char * cb = (signed char *)(b + (int)self) + 0x1C0;
    signed char c = *ca;
    *ca = *cb;
    *cb = c;
    UnkStruct_0044C7F0_r * ra = &self->field_C[a];
    UnkStruct_0044C7F0_r * rb = &self->field_C[b];
    UnkStruct_0044C7F0_v * pa = ra->h.field_8;
    UnkStruct_0044C7F0_v * pb = rb->h.field_8;
    UnkStruct_0044C7F0_v t = *pa;
    UnkStruct_0044C7F0_v u;
    u = *pb;
    *pa = u;
    UnkStruct_0044C7F0_v * pc = rb->h.field_8;
    *pc = t;
    int h0 = ra->h.field_0;
    int h1 = ra->h.field_4;
    UnkStruct_0044C7F0_v * h2 = ra->h.field_8;
    int h3 = ra->h.field_C;
    UnkStruct_0044C7F0_t tt = ra->t;
    UnkStruct_0044C7F0_pad padv;
    ra->h = rb->h;
    ra->t = rb->t;
    rb->h.field_0 = h0;
    rb->h.field_4 = h1;
    rb->h.field_8 = h2;
    rb->h.field_C = h3;
    rb->t = tt;
    int v = self->field_1FA;
    if (a == v) {
        self->field_1FA = b;
    } else if (b == v) {
        self->field_1FA = a;
    }
}




#pragma pop
