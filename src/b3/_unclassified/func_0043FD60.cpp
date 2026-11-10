// Hand-written; the lifter refused it (a135: FSM event handler; jtbl switch with explicit empty cases 0,1,7,8,9+default; switch(p2){case 0: case 2:}; GetStateFromID inline swap block).

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
struct UnkStruct_0043FD60 { unsigned char pad_0[0x14]; unsigned char field_14; };
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_P16 D_01E7A888;
extern UnkStruct_P16 D_01E98478;
extern int D_004E2918;
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_003FA600(void *, int);
extern "C" int func_00424750(void *, int, int, int, float);

// 0x0043FD60
extern "C" void func_0043FD60(UnkStruct_0043FD60 * self, int p0, int p1, int p2)
{
    switch (p0) {
    case 3: {
        int id;
        self->field_14 = 1;
        func_003FA600(&D_01E7A888, 0);
        switch (D_004E2918) {
        case 0:
        case 1:
        case 7:
        case 8:
        case 9:
        default:
            id = 2;
            break;
        case 10:
            id = 1;
            break;
        case 11:
            id = 8;
            break;
        case 5:
            id = 7;
            break;
        case 3:
            id = 4;
            break;
        case 4:
            id = 3;
            break;
        case 6:
            id = 5;
            break;
        case 2:
            id = 6;
            break;
        }
        func_00424750(&D_01E98478, id, 0, 0xFA5, 1000.0f);
        break;
    }
    case 5:
        switch (p2) {
        case 0:
        case 2:
        {
            if (self->field_14 == 0) {
                UnkStruct_State *r = (UnkStruct_State *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x944140D320FEDE85UL);
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
            } else {
                self->field_14 = 0;
                func_00424750(&D_01E98478, 9, 0, 0xFA5, 1000.0f);
            }
        }
        }
        break;
    case 2:
        return;
    }
}
