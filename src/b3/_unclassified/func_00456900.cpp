// Hand-written; the lifter refused it (a158: FSM handler, jtbl 9 entries, GetStateFromID swap inline x3 (shape of func_0043FD60)).

// func_00456900 -- hand-written (a158): FSM action handler (action 3 / 5); GetStateFromID swap block (func_00456900_inl1, [G] placeholder) inlined at three sites; sibling shape of func_0043FD60.
struct UnkStruct_D_01EA2974 { void *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2970 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_00431F90_3 { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_D_01EA2980 { UnkStruct_00431F90_3 *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2984 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_State { unsigned char pad_0[8]; float field_8; };
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E95BDC { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00456900 { unsigned char pad_0[0x10]; unsigned char field_10; };
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_P16 D_01E95BD8;
extern UnkStruct_P16 D_01E98418;
extern UnkStruct_D_01E95BDC D_01E95BDC;
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_00457120(void *);
extern "C" int func_00456E60(void *);
extern "C" int func_00454120(void *, int, int, int);

static inline void func_00456900_inl1(unsigned long id)
{
    UnkStruct_State *r = (UnkStruct_State *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, id);
    if (D_01EA2974.field_0 == r) return;
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
    void *t0 = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_00431F90_3 *t1 = D_01EA2980.field_0;
    if (t1 != 0) {
        D_01EA2984.field_0 = t1->field_20;
        if (r != 0) {
            r->field_8 = t1->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
}

// 0x00456900
extern "C" void func_00456900(UnkStruct_00456900 * self, int p0, int p1, int p2)
{
    switch (p0) {
    case 3:
        func_00457120(&D_01E95BD8);
        func_00456E60(&D_01E95BD8);
        self->field_10 = 0;
        break;
    case 5:
        switch (p2) {
        case 2:
        case 0:
            if (self->field_10 != 0) {
                func_00456E60(&D_01E95BD8);
                self->field_10 = 0;
                break;
            }
            switch (D_01E95BDC.field_0) {
            case 0:
                func_00456900_inl1(0x94413FEB5B627369UL);
                break;
            case 1:
                func_00454120(&D_01E98418, 6, 0, 1);
                self->field_10 = 1;
                break;
            case 2:
                func_00454120(&D_01E98418, 6, 1, 1);
                self->field_10 = 1;
                break;
            case 3:
                func_00454120(&D_01E98418, 6, 2, 1);
                self->field_10 = 1;
                break;
            case 4:
                func_00454120(&D_01E98418, 6, 3, 1);
                self->field_10 = 1;
                break;
            case 5:
                func_00454120(&D_01E98418, 6, 4, 1);
                self->field_10 = 1;
                break;
            case 8:
                func_00454120(&D_01E98418, 8, 2, 1);
                self->field_10 = 1;
                break;
            case 6:
                func_00454120(&D_01E98418, 8, 0, 1);
                self->field_10 = 1;
                break;
            case 7:
                func_00454120(&D_01E98418, 8, 1, 1);
                self->field_10 = 1;
                break;
            default:
                func_00456900_inl1(0x94413FD6EF6E02D9UL);
                break;
            }
            break;
        case 3:
            if (self->field_10 != 0) {
                func_00456E60(&D_01E95BD8);
                self->field_10 = 0;
                break;
            }
            func_00456900_inl1(0x94413FD6EF6E02D9UL);
            break;
        }
        break;
    }
}
