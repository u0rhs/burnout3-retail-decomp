// Hand-written; the lifter refused it (a86: OpenLobbyState::Action; default: break first, inner switch cases 0,1,2, switch(event){case 1: case 3:} for the or-compare, early return for same scene).

// func_003999E0 -- [L] DNAT: CB3OnlineOpenLobbyState::Action(EGtStateAction,void*,void*,void*) (research/proto/new_names.csv, medium)
// Modeled on func_00346200 / func_0041E3C0 (SetScene inline over GetStateFromID__6CGtFSMFUl).

struct UnkStruct_003999E0_3 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003999E0_4 {
    unsigned char pad_0[0x20];
    float field_20;
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
    UnkStruct_003999E0_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECDAC3 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003999E0 {
    unsigned char pad_0[0x10];
    int field_10;
};

extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01ECDAC3 D_01ECDAC3;
extern unsigned char D_01E9FC00[];

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_00399600(void *, int);
extern "C" int func_00398470(void *);

// 0x003999E0
extern "C" void func_003999E0(UnkStruct_003999E0 * self, int action, void * p1, int event)
{
    switch (action) {
    default:
        break;
    case 3:
        if (D_01ECDAC3.field_0 == 0) {
            self->field_10 = 0;
            func_00398470(&D_01E9FC00);
            break;
        }
        UnkStruct_003999E0_3 * r0 = (UnkStruct_003999E0_3 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E0BA2B41647);
        if (D_01EA2974.field_0 == r0) {
            return;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r0, 0);
        void * t0 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r0;
        UnkStruct_003999E0_4 * t1 = D_01EA2980.field_0;
        if (t1 != 0) {
            D_01EA2984.field_0 = t1->field_20;
            if (r0 != 0) {
                r0->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
        break;
    case 5:
        switch (self->field_10) {
        case 0:
            func_00399600(self, event);
            break;
        case 1:
            switch (event) {
            case 1:
            case 3:
                self->field_10 = 0;
                func_00398470(&D_01E9FC00);
                break;
            }
            break;
        case 2:
            switch (event) {
            case 1:
            case 3:
                self->field_10 = 0;
                func_00398470(&D_01E9FC00);
                break;
            }
            break;
        }
        break;
    }
}
