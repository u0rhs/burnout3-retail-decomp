// NONMATCHING: func_004231B0 -- retail 347 / ours 347 instructions, 152 in changed runs
// a156: 347/347 instrs, 152 in changed runs; layout is exact (goto form: entry-jump loops, bit2/bit4/bit1 blocks and found/field_178/vfunc_A4 blocks out of line after the return; ls[2] pair on the stack with pl=&ls[1]; push inline; tab[3][29] at +4). Left: register numbering only -- retail n=v1/op=t2/start=t0/count=t1/base=a2/stride=a3 in the first loop (ours op=a0, start=t1, count=t2, base=a3, stride=t0), s3 = player index in loop 2 (ours s4), and the two hoisted calls keep pl in s0 (flag's register) -- 6 declaration orders did not move it.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (a156): online-menu step queue builder (second half), sibling of func_004239F0 / func_00423F30.
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_UB { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_4231B0_obj {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual int vfunc_A4();
    unsigned char pad_4[0xC];
};
struct UnkStruct_4231B0_ctx {
    unsigned char pad_0[0x1B4];
    UnkStruct_4231B0_obj * field_1B4;
};
struct UnkStruct_4231B0_g { UnkStruct_4231B0_ctx * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00423F30 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    int field_4[3][29];
    int field_160;
    int field_164;
    unsigned char pad_168[0xC];
    unsigned char field_174;
    unsigned char field_175;
    unsigned char field_176;
    unsigned char field_177;
    unsigned char field_178;
};
extern UnkStruct_Pad16 D_00522660;
extern UnkStruct_UB D_0064EB04;
extern UnkStruct_UB D_006512D4;
extern UnkStruct_4231B0_g D_0051BA88;
extern "C" int func_00422E40(UnkStruct_00423F30 *, int, bool);

static inline void func_004231B0_push(UnkStruct_00423F30 * q, int op, int a, int b)
{
    q->field_4[0][q->field_174] = op;
    q->field_4[1][q->field_174] = a;
    q->field_4[2][q->field_174] = b;
    q->field_174 = q->field_174 + 1;
}

static inline int func_004231B0_kind(unsigned char b)
{
    if (b & 1) return 7;
    if (b & 4) return 6;
    if (b & 2) return 5;
    return 0;
}

// 0x004231B0
extern "C" void func_004231B0(UnkStruct_00423F30 * self, bool flag)
{
    int n, op;
    int i, mx;
    unsigned char start;
    int ls[2];
    int * pl;
    int * p;
    unsigned char k;
    unsigned char t3;
    unsigned char t4;
    unsigned char t5;
    unsigned char bb;
    bool found;
    if (self->field_178 != 0) {
        n = 2;
        op = 10;
    } else {
        n = 1;
        op = 9;
    }
    start = self->field_174;
    mx = 0;
    i = 0;
    goto t1;
b1:
    {
        unsigned char b = *((unsigned char *)&D_00522660 + i * 0x27D0 + 0x12C4A4);
        int c = 0;
        if (b & 1) c++;
        if (b & 4) c++;
        if (b & 2) c++;
        if (mx < c) mx = c;
        i++;
    }
t1:
    if (i < n) goto b1;
    p = (int *)((char *)self + start * 4);
    k = 0;
    goto t2;
b2:
    p[k + 1] = op;
    k++;
t2:
    if (k < mx) goto b2;
    found = false;
    i = 0;
    goto t3l;
b3:
    t3 = 0;
    if (flag) {
        if (i != 0) {
            bb = D_0064EB04.field_0;
        } else {
            bb = D_006512D4.field_0;
        }
    } else {
        bb = *((unsigned char *)&D_00522660 + i * 0x27D0 + 0x12C4A4);
    }
    if (bb & 2) goto blk2;
c4:
    if (bb & 4) goto blk4;
c1:
    if (bb & 1) goto blk1;
nxt:
    i++;
t3l:
    if (i < n) goto b3;
    self->field_174 = self->field_174 + (unsigned char)mx;
    if (found) goto add2;
post:
    ls[0] = func_00422E40(self, 0, flag);
    pl = &ls[1];
    *pl = func_00422E40(self, 1, flag);
    if (self->field_178 != 0) goto v;
chk:
    if (ls[0] != 0 || *pl != 0) goto last;
    return;
blk2:
    t3++;
    p[30 + 29 * i] = 5;
    goto c4;
blk4:
    p[30 + 29 * i + t3] = 6;
    t3++;
    goto c1;
blk1:
    p[1 + t3] = 2;
    p[30 + t3] = 0;
    t4 = t3;
    if (self->field_178 != 0) {
        t5 = t4 + 1;
        p[1 + t5] = 10;
        p[30 + 29 * i + t5] = 7;
    } else {
        t5 = t4 + 1;
        p[1 + t5] = 9;
        p[30 + 29 * i + t5] = 7;
    }
    t3 = t4 + 2;
    p[1 + t3] = 8;
    p[30 + t3] = 0;
    p[59 + t3] = 0;
    found = true;
    goto nxt;
add2:
    self->field_174 = self->field_174 + 2;
    goto post;
v:
    if (D_0051BA88.field_0->field_1B4->vfunc_A4() == 0) goto chk;
    {
        int x, y;
        self->field_4[0][self->field_174] = 0xB;
        if (ls[0] != 0 || *pl != 0) goto nz;
        x = func_004231B0_kind(D_0064EB04.field_0);
        self->field_4[1][self->field_174] = x;
        if (self->field_178 == 0) {
            y = 0;
        } else {
            y = func_004231B0_kind(D_006512D4.field_0);
        }
        self->field_4[2][self->field_174] = y;
    pushc:
        self->field_174 = self->field_174 + 1;
        func_004231B0_push(self, 0xC, ls[0], *pl);
        goto chk;
    nz:
        self->field_4[1][self->field_174] = ls[0];
        self->field_4[2][self->field_174] = *pl;
        goto pushc;
    }
last:
    func_004231B0_push(self, 3, ls[0], *pl);
    func_004231B0_push(self, 0xD, ls[0], *pl);
}
