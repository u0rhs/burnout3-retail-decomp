// NONMATCHING: func_003C6360 -- retail 676 / ours 676 instructions, 5 in changed runs
// gif5: 6 -> 5 with file-scoped opt_dead_assignments off [G]: e=&root->field_4[i] now t5 as retail; left the j-bound/f pair t3/t4 swapped. Inert: e/f/bound decl orders (kept-local N183 forms: e defined twice, e=0 init), int found, root local, full expressions, the other 14 pragmas
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#pragma push
#pragma opt_dead_assignments off
// logic/layout/frame exact (676/676); only the search-loop row pointers swap t4/t5 (retail e=&root->field_4[i] in t5, f=&e->field_0[j] in t4). Needed: D_01E901C8 as D_01E900B0.field_118 (one struct, so the field_12C[n] stores alias it and the loop test reloads) -- check the RELOC on that; key compare via a static inline (beq order); char buf[32] for the 0x70 frame. Tried decl orders (24), locals/full expressions/inline forms, 5 pragmas

// func_003C6360 -- hand-written (L254) from the asm after the proven siblings func_003C6DF0 / func_003C78A0
// and the queued func_003C71B0 (same file: event-state Action, D_01EA2970 swap inline).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction widths).

struct UnkStruct_003C6360;
struct UnkStruct_003C6360_9;
struct UnkStruct_003C6360_11;

struct UnkStruct_003C6360_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_003C6360_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_003C6360_L { unsigned long field_0; unsigned long pad_8; };
struct UnkStruct_003C6360_P { unsigned char pad_0[0x10]; };

struct UnkStruct_D_01EA2974 {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2970 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_003C6360_9 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C6360_9 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C6360_11 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003C6360 {
    unsigned char pad_0[0x10];
    int field_10;
    int field_14;
};

// the stage-data search tree under D_00518690 [G]
struct UnkStruct_003C6360_k { unsigned char pad_0[0x8]; unsigned long field_8; unsigned char pad_10[0x10]; };
struct UnkStruct_003C6360_e64 {
    unsigned long field_0;
    int field_8;
    unsigned char pad_C[0x28];
    UnkStruct_003C6360_k * field_34;
    int field_38;
    unsigned char pad_3C[0x4];
};
struct UnkStruct_003C6360_e24 {
    unsigned char pad_0[0x10];
    UnkStruct_003C6360_e64 * field_10;
    int field_14;
};
struct UnkStruct_003C6360_e8 {
    UnkStruct_003C6360_e24 * field_0;
    int field_4;
};
struct UnkStruct_003C6360_root {
    unsigned char pad_0[0x4];
    UnkStruct_003C6360_e8 * field_4;
    int field_8;
};
struct UnkStruct_D_00518690 { UnkStruct_003C6360_root * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E901C8 { UnkStruct_003C6360_e64 * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_003C6360_sd { unsigned long field_0; unsigned long field_8; };
struct UnkStruct_D_01E900B0 {
    unsigned char pad_0[0x118];
    UnkStruct_003C6360_e64 * field_118;
    unsigned char pad_11C[0x10];
    UnkStruct_003C6360_k * field_12C[1];
};
struct UnkStruct_D_0051BF9C { void * field_0; unsigned char pad_4[0xC]; };

extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_00518690 D_00518690;
extern UnkStruct_D_01E901C8 D_01E901C8;
extern UnkStruct_D_01E900B0 D_01E900B0;
extern UnkStruct_003C6360_sd * D_01E901DC[];  // [G] element count unknown
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_003C6360_I D_01E900E0;
extern UnkStruct_003C6360_I D_01E900EC;
extern UnkStruct_003C6360_I D_01E90190;
extern UnkStruct_003C6360_I D_01E88D44;
extern UnkStruct_003C6360_I D_01E95924;
extern UnkStruct_003C6360_I D_01E95928;
extern UnkStruct_003C6360_L D_01E90130;
extern UnkStruct_003C6360_L D_01E90198;
extern UnkStruct_003C6360_L D_01E901F0;
extern int D_004E26A4;
extern UnkStruct_003C6360_P D_00516DF4;
extern UnkStruct_003C6360_P D_01EA2A58;
extern UnkStruct_003C6360_P D_01EA2A68;
extern UnkStruct_003C6360_P D_01EA2B40;
extern UnkStruct_003C6360_P D_01E95920;
extern UnkStruct_003C6360_P D_01E88AF0;
extern UnkStruct_003C6360_P D_01E7A888;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int func_0013B730(void *);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(void *, int, int);
extern "C" int func_003C4150(void *, int, int, int);
extern "C" int func_003A7000(void *);
extern "C" unsigned long func_003A7010(void *, int, void *);
extern "C" int func_00135B50(void *, int);
extern "C" void func_003F8C00(void *, int);
extern "C" UnkStruct_003C6360_sd * GetGameStageData__14CB3MenuChoicesFP18CB3StageDataStruct(void *, void *);
extern "C" void func_0021ADF0(unsigned long, void *);
extern "C" unsigned long GtIDCompress__FPCc(const char *);

static inline void func_003C6360_inl1(unsigned long id)  // [G] inlined swap helper (name unknown), as func_003C6DF0
{
    UnkStruct_003C6360_11 * r = (UnkStruct_003C6360_11 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, id);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
    void * t0 = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_003C6360_9 * t1 = D_01EA2980.field_0;
    if (t1 != 0) {
        D_01EA2984.field_0 = t1->field_20;
        if (r != 0) {
            r->field_8 = t1->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
}

static inline void func_003C6360_inl2(unsigned long id, int k)  // [G] same swap with a k argument
{
    UnkStruct_003C6360_11 * r = (UnkStruct_003C6360_11 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, id);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, k);
    void * t0 = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_003C6360_9 * t1 = D_01EA2980.field_0;
    if (t1 != 0) {
        D_01EA2984.field_0 = t1->field_20;
        if (r != 0) {
            r->field_8 = t1->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, k);
}

static inline void func_003C6360_inl3(unsigned long id)  // [G] inlined stage-id -> type switch (name unknown)
{
    switch (id) {
    case 0x5B55815244000000UL:
    default:
        D_01E900EC.field_0 = 0;
        break;
    case 0x9616458830000000UL:
        D_01E900EC.field_0 = 1;
        break;
    case 0x5C378F7891000000UL:
        D_01E900EC.field_0 = 2;
        break;
    case 0xB8A15D9FD0000000UL:
        D_01E900EC.field_0 = 3;
        break;
    case 0xB959B894FE000000UL:
        D_01E900EC.field_0 = 4;
        break;
    case 0x790796B24F000000UL:
        D_01E900EC.field_0 = 5;
        break;
    }
}

static inline bool func_003C6360_inl4(UnkStruct_003C6360_e64 * x, unsigned long id)  // [G]
{
    return x->field_34->field_8 == id;
}

// 0x003C6360
extern "C" void func_003C6360(UnkStruct_003C6360 * self, int p0, void * p1, void * p2)
{
    switch (p0) {
    case 0:
        return;
    case 3: {
        void * s = D_0051BF9C.field_0;
        CopyN__10CGtUnicodeFPUsiPCUs(&D_00516DF4, 9, func_0013B730(s));
        if (p2 == &D_01EA2A58) {
            func_003C4150(&D_01E95920, D_01E90190.field_0, func_003A7000(&D_01E88AF0) ? 2 : 4, 2);
        } else if (p2 == &D_01EA2B40 && func_00135B50(s, D_01E90190.field_0) == 0) {
            func_003C4150(&D_01E95920, D_01E90190.field_0, 1, 0);
        } else if (p2 == &D_01EA2A68) {
            if (self->field_14 != D_004E26A4) {
                self->field_10 = 0;
                D_01E90190.field_0 = 0;
            }
            func_003C4150(&D_01E95920, D_01E90190.field_0, self->field_10, 2);
        } else {
            func_003C4150(&D_01E95920, D_01E90190.field_0, 0, 0);
        }
        break;
    }
    case 5:
        switch ((int)p2) {
        case 2:
            func_003C4150(&D_01E95920, D_01E88D44.field_0, func_003A7000(&D_01E88AF0) ? 2 : 4, 2);
            break;
        case 0: {
            D_01E90190.field_0 = D_01E95928.field_0;
            unsigned long key = func_003A7010(&D_01E88AF0, p0, p1);
            int i, j, k;
            bool found = false;
            for (i = 0; i < D_00518690.field_0->field_8; i++) {
                for (j = 0; j < D_00518690.field_0->field_4[i].field_4; j++) {
                    UnkStruct_003C6360_e24 * f = &D_00518690.field_0->field_4[i].field_0[j];
                    for (k = 0; k < f->field_14; k++) {
                        if (func_003C6360_inl4(&f->field_10[k], key)) {
                            found = true;
                            break;
                        }
                    }
                    if (found) break;
                }
                if (found) break;
            }
            D_01E900B0.field_118 = &D_00518690.field_0->field_4[i].field_0[j].field_10[k];
            for (int n = 0; n < D_01E900B0.field_118->field_38; n++) {
                D_01E900B0.field_12C[n] = &D_01E900B0.field_118->field_34[n];
            }
            D_01E90198.field_0 = D_01E901DC[0]->field_0;
            D_01E901F0.field_0 = D_01E901DC[0]->field_8;
            if (func_003A7000(&D_01E88AF0) == 0) {
                UnkStruct_003C6360_sd * r = GetGameStageData__14CB3MenuChoicesFP18CB3StageDataStruct(&D_01E900B0, D_01E901DC[0]);
                unsigned long s0 = r->field_0;
                unsigned long s1 = r->field_8;
                if (s0 == 0) {
                    D_01E900EC.field_0 = 9;
                    D_01E900E0.field_0 = 0;
                    func_003C6360_inl1(0x9441407ECBC88C0FUL);
                } else if (s1 != 0) {
                    char buf[32];
                    func_0021ADF0(s0, buf);
                    func_0021ADF0(s1, buf + 4);
                    unsigned long v = GtIDCompress__FPCc(buf);
                    D_01E900B0.field_118->field_8 = 2;
                    D_01E900B0.field_118->field_0 = v;
                    func_003C6360_inl3(s0);
                    D_01E90130.field_0 = v;
                    D_01E900E0.field_0 = 0;
                    func_003C6360_inl1(0x9441407ECBC88C0FUL);
                } else {
                    D_01E900E0.field_0 = 0;
                    D_01E900B0.field_118->field_8 = 1;
                    D_01E900B0.field_118->field_0 = s0;
                    func_003C6360_inl3(s0);
                    func_003C6360_inl1(0x9441407ECBC88C0FUL);
                }
            } else {
                D_01E900E0.field_0 = 1;
                func_003C6360_inl1(0x94414036C5AD5E97UL);
            }
            break;
        }
        case 3:
            func_003C6360_inl1(0x94413FC035B0F871UL);
            break;
        case 0x49:
            self->field_10 = D_01E95924.field_0;
            D_01E90190.field_0 = D_01E95928.field_0;
            D_004E26A4 = self->field_14;
            func_003F8C00(&D_01E7A888, 0);
            func_003C6360_inl2(0x94413FD6EF6E02D9UL, 1);
            break;
        }
        break;
    }
}

#pragma pop
