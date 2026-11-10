// NONMATCHING: func_00448BB0 -- retail 296 / ours 296 instructions, 8 in changed runs
// pass2c: 9 -> 8: loopA ends goto store (retail b store; nop) and afterC label dropped. Left: the shared constant 1 -- retail li a2,1 first (before sd ra) and move s1,a2 / move s0,a2; ours li a0,1 after move s2,a0. Decl orders, void* self copy, 6 scoped pragmas tried
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// NONMATCHING: func_00448BB0 -- retail 296 / ours 289 instructions, 32 in changed runs
// a158: layout+logic exact (289/296 instrs, 32 changed): jtbl switch, clamp out-of-line arms, goto-placed loop A/B after return, case-4 arms un-merged by a byte-offset pun, args evaluated dst-after-Str. Left: (1) retail keeps the dead local-array store (addiu s3,v0,0x70; sw v0,0(s3)) = same open problem as func_004480E0 (volatile would be a fakematch), which also shifts locals 0x70->0x80 and frame 0x80->0x90; (2) constant 1 held in a2 (ours a0) -> move s1,a2 / move s0,a2.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_00448BB0 -- hand-written (a158): menu page SetMode-style row setup (mode at +0x90, rows of 8 bytes from +0x10, cursor +0xC, count +0xE)
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01ECD520 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E90430 { void *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004F507F { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E97DBC { unsigned char pad_0[0x10]; };
struct UnkStruct_00448BB0_p { unsigned char pad_0[0x49B]; signed char field_49B; };
struct UnkStruct_00448BB0_row { unsigned short *field_0; unsigned char field_4; unsigned char field_5; unsigned char pad_6[2]; };
struct UnkStruct_00448BB0 {
    unsigned char pad_0[0xC];
    short field_C;
    short field_E;
    UnkStruct_00448BB0_row field_10[6];
    unsigned char pad_40[0x28];
    int field_68;
    unsigned char pad_6C[0x24];
    signed char field_90;
    unsigned char pad_91;
    unsigned short field_92[3][16];
};
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern UnkStruct_D_01E90430 D_01E90430;
extern UnkStruct_D_004F507F D_004F507F;
extern UnkStruct_D_01E97DBC D_01E97DBC;
extern UnkStruct_D_01E97DBC D_01E96418;
extern UnkStruct_D_01E97DBC D_01E96424;
extern UnkStruct_D_01E97DBC D_01E96450;
extern "C" unsigned short *func_00271A00(void *, int);
extern "C" int func_004480E0();
extern "C" void *func_00420FE0(UnkStruct_D_01ECD520 *, int);
extern "C" void *func_001A3AA0(unsigned short *, unsigned short *, int *);

// 0x00448BB0
extern "C" int func_00448BB0(UnkStruct_00448BB0 *self, int p0)
{
    int nA1, nA0, nB1, nB0;
    UnkStruct_00448BB0_p *p[3];
    int s1 = 1;
    int s0 = 0;
    int i;
    switch (self->field_90) {
    case 1:
        s1 = 2;
        if ((unsigned)p0 < 2) s0 = p0; else s0 = 1;
        self->field_10[0].field_0 = func_00271A00(&D_0051BA44, 0x1B5);
        self->field_10[0].field_4 = 0;
        self->field_10[0].field_5 = 0;
        self->field_10[1].field_0 = func_00271A00(&D_0051BA44, 0x1B6);
        self->field_10[1].field_4 = 0;
        self->field_10[1].field_5 = 0;
        break;
    case 2:
        self->field_10[0].field_0 = func_00271A00(&D_0051BA44, 0x1BD);
        self->field_10[0].field_4 = 0;
        self->field_10[0].field_5 = 0;
        break;
    case 3:
        s1 = 2;
        if ((unsigned)p0 < 2) s0 = p0; else s0 = 1;
        self->field_10[0].field_0 = func_00271A00(&D_0051BA44, 0x1BD);
        self->field_10[0].field_4 = 0;
        self->field_10[0].field_5 = 0;
        self->field_10[1].field_0 = func_00271A00(&D_0051BA44, 0x1C2);
        self->field_10[1].field_4 = 0;
        self->field_10[1].field_5 = 0;
        break;
    case 4: {
        s1 = 2;
        if ((unsigned)p0 < 2) s0 = p0; else s0 = 1;
        int s3;
        if (D_01E90430.field_0 == &D_01E97DBC) {
            s3 = 0x2DA04;
            self->field_10[0].field_0 = func_00271A00(&D_0051BA44, 0x1A7);
            self->field_10[0].field_4 = 0;
            self->field_10[0].field_5 = 0;
        } else {
            s3 = 0x2DA04;
            *(unsigned short **)((char *)self + 0x10) = func_00271A00(&D_0051BA44, 0x1A7);
            self->field_10[0].field_4 = 0;
            self->field_10[0].field_5 = 0;
        }
        self->field_10[1].field_0 = func_00271A00((char *)&D_004EE040 + s3, 0x1AC);
        self->field_10[1].field_4 = 0;
        self->field_10[1].field_5 = 0;
        break;
    }
    case 5:
        s1 = 4;
        if ((unsigned)p0 < 4) s0 = p0; else s0 = 3;
        self->field_10[0].field_0 = func_00271A00(&D_0051BA44, 0x1A7);
        self->field_10[0].field_4 = 0;
        self->field_10[0].field_5 = 0;
        self->field_10[1].field_0 = func_00271A00(&D_0051BA44, 0x1A8);
        self->field_10[1].field_4 = 0;
        self->field_10[1].field_5 = 0;
        if (D_004F507F.field_0 != 0) {
            self->field_10[2].field_0 = func_00271A00(&D_0051BA44, 0x1AA);
            self->field_10[2].field_4 = 0;
            self->field_10[2].field_5 = 0;
        } else {
            self->field_10[2].field_0 = func_00271A00(&D_0051BA44, 0x1AB);
            self->field_10[2].field_4 = 0;
            self->field_10[2].field_5 = 0;
        }
        self->field_10[3].field_0 = func_00271A00(&D_0051BA44, 0x1AC);
        self->field_10[3].field_4 = 0;
        self->field_10[3].field_5 = 0;
        break;
    case 6: {
        s1 = 3;
        self->field_68 = func_004480E0();
        s0 = self->field_68;
        void *cur = D_01E90430.field_0;
        if (cur == &D_01E96418) goto loopA;
        if (cur == &D_01E96424 || cur == &D_01E96450) goto loopB;
        break;
    }
    }
store:
    self->field_C = s0;
    self->field_E = s1;
    if (self->field_90 == 0) s1 = 0;
    return s1;
loopA:
    for (i = 0; i < 3; i++) {
        p[i] = (UnkStruct_00448BB0_p *)func_00420FE0(&D_01ECD520, i);
        unsigned char flag;
        unsigned short *dst;
        if (p[i]->field_49B == 0) {
            flag = p[i]->field_49B != 0;
            nA0 = i + 1;
            func_001A3AA0(dst = self->field_92[i], func_00271A00(&D_0051BA44, 0x9B9), &nA0);
        } else {
            flag = 1;
            nA1 = i + 1;
            func_001A3AA0(dst = self->field_92[i], func_00271A00(&D_0051BA44, 0x9B9), &nA1);
        }
        self->field_10[i].field_0 = dst;
        self->field_10[i].field_4 = flag;
        self->field_10[i].field_5 = 0;
    }
    goto store;
loopB:
    for (i = 0; i < 3; i++) {
        p[i] = (UnkStruct_00448BB0_p *)func_00420FE0(&D_01ECD520, i);
        unsigned char flag = 0;
        unsigned short *dst;
        if (p[i]->field_49B == 0) {
            flag = p[i]->field_49B != 0;
            nB0 = i + 1;
            func_001A3AA0(dst = self->field_92[i], func_00271A00(&D_0051BA44, 0x9B9), &nB0);
        } else {
            nB1 = i + 1;
            func_001A3AA0(dst = self->field_92[i], func_00271A00(&D_0051BA44, 0x9B9), &nB1);
        }
        self->field_10[i].field_0 = dst;
        self->field_10[i].field_4 = flag;
        self->field_10[i].field_5 = 0;
    }
    goto store;
}




