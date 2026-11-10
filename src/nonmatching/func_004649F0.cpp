// NONMATCHING: func_004649F0 -- retail 182 / ours 179 instructions, 55 in changed runs
// a226: ternary-ish 'if (r!=0) v=r+K; else v=0' written 'if (r==0) v=0; else v=r+K' matches retail's bnez/b/move-zero layout at all 4 error-code sites (64->55). Left: retail's out-of-line 'b exit; li v0,6' stubs (ours inline), leading sltu on the D_004E2FBC test, s0/s1 swap
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_004649F0 -- retail 182 / ours 179 instructions, 64 in changed runs
// 182/179 instrs, ~60 changed: alloc inline (pp=&G->80 in s0,size s1) block layout differs: retail has error/divu blocks out of line (b join; li 4/6), ours inline li 6;beqz; register s0/s1 swap
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_004649F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_004649F0;
struct UnkStruct_004649F0_2;
struct UnkStruct_004649F0_3;
struct UnkStruct_004649F0_4;
struct UnkStruct_004649F0_5;
struct UnkStruct_D_004D3B70;
struct UnkStruct_D_004E2FBC;

struct UnkStruct_D_004E2FBC {
    UnkStruct_004649F0_2 * field_0;
};

struct UnkStruct_004649F0_2 {
    unsigned char pad_0[0x64];
    int field_64;
    int field_68;
    UnkStruct_004649F0_5 * field_6C;
    UnkStruct_004649F0_3 * field_70;
    unsigned char pad_74[0xC];
    int field_80;
    unsigned char pad_84[0xC];
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    unsigned char pad_A4[0x4];
    unsigned char field_A8;
};

struct UnkStruct_004649F0_3 {
    int field_0;
};

struct UnkStruct_004649F0_4 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

struct UnkStruct_004649F0_5 {
    int field_0;
};

struct UnkStruct_D_004D3B70 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004649F0 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
};

extern UnkStruct_D_004E2FBC D_004E2FBC;
extern UnkStruct_D_004D3B70 D_004D3B70;

extern "C" void * memset(void *, int, unsigned int);
extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" int func_00467FE0(void *, void *, int);
extern "C" int func_00360AE0(int, int, int);
extern "C" void func_00466E70(void *);
extern "C" void func_004652B0(int, void *, void *);

static inline int func_004649F0_inl1(int heap, int *pp, int n, int al)
{
    if (pp == 0) {
        return 4;
    }
    *pp = func_00360AE0(heap, n, al);
    if (*pp == 0) {
        return 6;
    }
    memset((void *)*pp, 0, n);
    memcpy((void *)*pp, &D_004D3B70, 12);
    *pp = *pp + 12;
    return 0;
}


// 0x004649F0
extern "C" int func_004649F0(UnkStruct_004649F0 * self)
{
    int la, lb, lc, ld;
    if (D_004E2FBC.field_0 != 0) {
        return 1;
    }
    int r0 = func_00467FE0((void *)(self->field_4), (void *)(self->field_8), self->field_18);
    if (r0 != 0) {
        int v14;
        if (r0 == 0) {
            v14 = 0;
        } else {
            v14 = (r0 + 100);
        }
        return v14;
    }
    int r1 = func_00360AE0(self->field_18, 172, 4);
    D_004E2FBC.field_0 = (UnkStruct_004649F0_2 *)r1;
    if (r1 == 0) {
        return 6;
    }
    func_00466E70((void *)((r1 + 112)));
    int r3 = ((int (*)(int))D_004E2FBC.field_0->field_70->field_0)(self->field_18);
    if (r3 != 0) {
        int v0;
        if (r3 == 0) {
            v0 = 0;
        } else {
            v0 = (r3 + 300);
        }
        return v0;
    }
    D_004E2FBC.field_0->field_6C = (UnkStruct_004649F0_5 *)self->field_14;
    UnkStruct_004649F0_5 * t1 = D_004E2FBC.field_0->field_6C;
    if (t1 != 0) {
        int r10 = ((int (*)(int))t1->field_0)(self->field_18);
        if (r10 != 0) {
            int v13;
            if (r10 == 0) {
                v13 = 0;
            } else {
                v13 = (r10 + 200);
            }
            return v13;
        }
        D_004E2FBC.field_0->field_68 = self->field_10;
        int r11 = func_00360AE0(self->field_18, D_004E2FBC.field_0->field_68, 4);
        D_004E2FBC.field_0->field_64 = r11;
        if (D_004E2FBC.field_0->field_64 == 0) {
            return 6;
        }
        memcpy((void *)D_004E2FBC.field_0->field_64, (const void *)self->field_C, D_004E2FBC.field_0->field_68);
    }
    D_004E2FBC.field_0->field_90 = self->field_0;
    D_004E2FBC.field_0->field_94 = 0;
    D_004E2FBC.field_0->field_98 = 0;
    int r4 = func_00360AE0(self->field_18, (self->field_0 << 4), 4);
    D_004E2FBC.field_0->field_9C = r4;
    UnkStruct_004649F0_2 * t2 = D_004E2FBC.field_0;
    if (t2->field_9C == 0) {
        return 6;
    }
    int t3 = t2->field_A0;
    int *pp = &t2->field_80;
    la = 4;
    lb = 1;
    func_004652B0(1, &la, &lb);
    lc = 4;
    ld = 1;
    func_004652B0(1, &lc, &ld);
    int t4 = ld;
    int v1 = t4;
    if ((unsigned int)t4 < (unsigned int)13) {
        v1 = (((unsigned int)(t4 - ((unsigned int)12 % (unsigned int)t4)) % (unsigned int)t4) + 12);
    }
    int v6 = func_004649F0_inl1(t3, pp, v1, la);
    if (v6 == 0) {
        D_004E2FBC.field_0->field_80 = (D_004E2FBC.field_0->field_80 + -12);
        D_004E2FBC.field_0->field_A0 = self->field_18;
        D_004E2FBC.field_0->field_A8 = 0;
        return 0;
    }
    return v6;
}

