// Hand-written; the lifter refused it (event-state Action cloned from func_003C78A0/func_003C6DF0: swap inline, bool flag to a bool param, int ev copy of p2 for both inner switches, explicit return after the case-3 swap).

// func_003C71B0 -- hand-matched (L254) from the asm, cloning func_003C78A0 / func_003C6DF0 (same file, proven).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction widths).
// [L] DNAT: CB3PostEventRecordsState::Action(EGtStateAction,void*,void*,void*) (research/proto/new_names.csv, low)

struct UnkStruct_003C71B0;
struct UnkStruct_003C71B0_9;
struct UnkStruct_003C71B0_11;
struct UnkStruct_003C71B0_3;
struct UnkStruct_003C71B0_4;

struct UnkStruct_D_01ECDAxx {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_003C71B0_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C71B0_3 {
    unsigned char pad_0[0x1B8];
    UnkStruct_003C71B0_4 * field_1B8;
};

struct UnkStruct_003C71B0_4 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
};

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
    UnkStruct_003C71B0_9 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C71B0_9 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C71B0_11 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_0051BACC {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E2ED8 {
    unsigned short field_0;    // [G] current index
    unsigned short field_2;    // [G] count
};

struct UnkStruct_D_pad10 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C71B0 {
    unsigned char pad_0[0x10];
    signed char * field_10;
    unsigned char field_14;
};

extern UnkStruct_D_01ECDAxx D_01ECDAC1;
extern UnkStruct_D_01ECDAxx D_01ECDAC2;
extern UnkStruct_D_01ECDAxx D_01ECDAC4;
extern UnkStruct_D_01ECDAxx D_01ECDAC5;
extern UnkStruct_D_01ECDAxx D_01ECDAC7;
extern UnkStruct_D_01ECDAxx D_01ECDAC9;
extern UnkStruct_D_01ECDAxx D_01ECDACA;
extern UnkStruct_D_01ECDAxx D_01E65499;
extern UnkStruct_D_01ECDAxx D_00665E52;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0051BACC D_0051BACC;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_004E2ED8 D_004E2ED8;
extern UnkStruct_D_pad10 D_0051A6A8;
extern UnkStruct_D_pad10 D_004EE040;
extern UnkStruct_D_pad10 D_0051B928;
extern UnkStruct_D_pad10 D_01EA2B18;
extern signed char D_004CA370[];
extern signed char D_004CA378[];
extern signed char D_004CA380[];
extern signed char D_004CA388[];
extern signed char D_004CA390[];
extern signed char D_004CA398[];
extern signed char D_004CA3A0[];
extern signed char D_004CA3A8[];

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_00130C20(void *, unsigned long);
extern "C" void func_00131F10(void *, void *);
extern "C" int func_00131E40(void *);
extern "C" void func_003BAE10(void *, int);
extern "C" int func_00319330(void *);
extern "C" int func_00319360(void *);
// [G] third parameter bool: the flag (sltiu / daddiu 1) is passed with no andi; func_003C78A0 compiles identically with a bool p1 (L254)
extern "C" void func_003C78A0(UnkStruct_003C71B0 *, int, bool);
extern "C" void func_003C7AB0(UnkStruct_003C71B0 *, int);

static inline void func_003C71B0_inl1(unsigned long id)  // [G] inlined swap helper (name unknown), as func_003C6DF0
{
    UnkStruct_003C71B0_11 * r = (UnkStruct_003C71B0_11 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, id);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
    void * t0 = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_003C71B0_9 * t1 = D_01EA2980.field_0;
    if (t1 != 0) {
        D_01EA2984.field_0 = t1->field_20;
        if (r != 0) {
            r->field_8 = t1->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
}

// 0x003C71B0
extern "C" void func_003C71B0(UnkStruct_003C71B0 * self, int p0, void * p1, void * p2)
{
    switch (p0) {
    case 0:
        self->field_10 = 0;
        self->field_14 = 0;
        break;
    case 3: {
        self->field_10 = 0;
        self->field_14 = 0;
        bool flag = p2 == &D_01EA2B18;
        if (D_01ECDAC7.field_0 != 0) {
            if (D_01ECDAC2.field_0 == 0) {
                self->field_10 = D_004CA378;
            } else if (D_01ECDACA.field_0 != 0) {
                self->field_10 = D_004CA380;
            } else {
                self->field_10 = D_004CA370;
            }
            flag = true;
        } else if (D_01ECDAC9.field_0 != 0) {
            self->field_10 = D_004CA388;
        } else if (D_01ECDAC5.field_0 != 0) {
            self->field_10 = D_004CA390;
        } else if (D_01ECDAC1.field_0 == 0) {
            self->field_10 = D_004CA3A8;
        } else if (D_01ECDAC2.field_0 != 0) {
            self->field_10 = D_004CA398;
        } else {
            self->field_10 = D_004CA3A0;
        }
        int i;
        for (i = 0; self->field_10[i] != 3; i++) {
        }
        D_004E2ED8.field_2 = i;
        D_004E2ED8.field_0 = 0;
        func_003C78A0(self, self->field_10[0], flag);
        break;
    }
    case 5: {
        int ev = (int)p2;
        if (self->field_14 != 0) {
            switch (ev) {
            case 0xB:
                func_003C71B0_inl1(0x94413FA737AAA797);
                func_00130C20(&D_0051A6A8, 0x94413E09C8514CA1);
                func_00131F10(&D_004EE040, &D_0051A6A8);
                break;
            case 8:
                if (D_01ECDAC1.field_0 != 0) {
                    func_003BAE10(&D_0051B928, 1);
                    break;
                }
            case 7:
                if (D_0051BA88.field_0 == 0 || D_0051BA88.field_0->field_1B8 == 0) {
                    func_003C71B0_inl1(0x94413FA737AAA797);
                    D_0051BACC.field_0 = 7;
                    D_00665E52.field_0 = 0;
                } else {
                    D_0051BA88.field_0->field_1B8->vfunc_20();
                }
                break;
            case 3:
            case 4:
                func_003C78A0(self, self->field_10[D_004E2ED8.field_0], 0);
                break;
            }
        } else {
            switch (ev) {
            case 2: {
                signed char c;
                if (func_00319330(&D_004E2ED8) != 0) {
                    c = self->field_10[D_004E2ED8.field_0];
                } else {
                    c = 3;
                }
                func_003C78A0(self, c, 0);
                break;
            }
            case 0xB:
            case 7:
                func_003C7AB0(self, ev);
                break;
            case 8:
                if (func_00131E40(&D_004EE040) == 0 || D_01E65499.field_0 != 0) {
                    func_003C7AB0(self, ev);
                } else {
                    self->field_14 = 1;
                    if (D_0051BA88.field_0 == 0 || D_0051BA88.field_0->field_1B8 == 0) {
                        func_003C71B0_inl1(0x94413FA737AAA797);
                        D_0051BACC.field_0 = 7;
                        D_00665E52.field_0 = 0;
                    } else {
                        D_0051BA88.field_0->field_1B8->vfunc_20();
                    }
                }
                break;
            case 3:
                if (func_00319360(&D_004E2ED8) != 0 || D_01ECDAC4.field_0 == 0) {
                    func_003C78A0(self, self->field_10[D_004E2ED8.field_0], 0);
                } else {
                    func_003C71B0_inl1(0x94414082ECC11C0AUL);
                    return;
                }
                break;
            }
        }
        break;
    }
    }
}
