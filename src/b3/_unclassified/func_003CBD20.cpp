// Hand-written; the lifter refused it (CB3PartyCrashSetupState::Action: D_01E900B0 as one struct (counts at +0x24/+0x28 reload), stacked case 1/0, SetScene inline).

// func_003CBD20 -- CB3PartyCrashSetupState::Action(EGtStateAction,void*,void*,void*)
// [L] DNAT: CB3PartyCrashSetupState::Action(EGtStateAction,void*,void*,void*) (research/proto/new_names.csv, medium)

enum EGtStateAction {};

struct UnkStruct_D_01EA2970 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_r { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_s { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_D_01EA2974 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2980 { UnkStruct_s * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2984 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E900B0 {
    unsigned char pad_0[0x24];
    int field_24;
    int field_28;
    unsigned char pad_2C[0x10];
    int field_3C[1];
    unsigned char pad_40[0xB0];
    long field_F0[1];
};

class CB3PartyCrashSetupState {
public:
    unsigned char pad_0[0x10];
    unsigned char field_10;
    unsigned char field_11;
};

extern UnkStruct_B D_01E9578E;
extern UnkStruct_B D_01E9578C;
extern UnkStruct_B D_01E9578D;
extern UnkStruct_I D_01E95788;
extern UnkStruct_I D_01E95784;
extern UnkStruct_P D_01E95780;
extern UnkStruct_P D_01E97F38;
extern UnkStruct_B D_01E90223;
extern UnkStruct_B D_01E90224;
extern UnkStruct_D_01E900B0 D_01E900B0;
extern long D_01E901A0[];
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int func_003CBBC0(void *);
extern "C" int func_00454D80(void *, int, int, long);
extern "C" long func_00454A60(void *);
extern "C" long func_00454AC0();

static inline void SetScene(unsigned long h)
{
    UnkStruct_r * r = (UnkStruct_r *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, h);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
    void * t = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_s * s = D_01EA2980.field_0;
    if (s != 0) {
        D_01EA2984.field_0 = s->field_20;
        if (r != 0) {
            r->field_8 = s->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t, 0);
}

// 0x003CBD20
extern "C" void func_003CBD20(CB3PartyCrashSetupState * self, EGtStateAction p0, void * p1, long p2, int p3)
{
    switch (p0) {
    case 3:
        if (p3 != 3) {
            func_003CBBC0(&D_01E95780);
            self->field_11 = 0;
            break;
        }
        if (D_01E9578E.field_0 != 0) {
            func_003CBBC0(&D_01E95780);
            self->field_11 = 0;
        } else {
            self->field_10--;
            func_00454D80(&D_01E97F38, 0, self->field_10, D_01E901A0[self->field_10]);
        }
        break;
    case 5:
        switch (p2) {
        case 1:
        case 0:
            if (self->field_11 != 0) {
                D_01E901A0[self->field_10] = func_00454A60(&D_01E97F38);
                self->field_10++;
                if (self->field_10 >= D_01E900B0.field_28) {
                    SetScene(0x9441407ECBC88C0FUL);
                } else {
                    func_00454D80(&D_01E97F38, 0, self->field_10, D_01E901A0[self->field_10]);
                }
                break;
            }
            D_01E900B0.field_24 = D_01E9578C.field_0;
            D_01E900B0.field_28 = D_01E9578D.field_0;
            if (D_01E95788.field_0 == 0) {
                D_01E90223.field_0 = 1;
            } else {
                D_01E90223.field_0 = 0;
            }
            if (D_01E95784.field_0 == 0) {
                D_01E90224.field_0 = 0;
            } else {
                D_01E90224.field_0 = 1;
            }
            {
                int i;
                for (i = 0; i < D_01E900B0.field_24; i++) {
                    D_01E900B0.field_3C[i] = 9;
                }
            }
            if (D_01E9578E.field_0 != 0) {
                int j;
                for (j = 0; j < D_01E900B0.field_28; j++) {
                    D_01E900B0.field_F0[j] = func_00454AC0();
                }
                SetScene(0x9441407ECBC88C0FUL);
            } else {
                int k;
                for (k = 0; k < D_01E900B0.field_28; k++) {
                    D_01E900B0.field_F0[self->field_10] = 0;
                }
                func_00454D80(&D_01E97F38, 0, 0, 0);
                self->field_11 = 1;
                self->field_10 = 0;
            }
            break;
        case 3:
            if (self->field_11 != 0) {
                if (self->field_10 == 0) {
                    func_003CBBC0(&D_01E95780);
                    self->field_11 = 0;
                } else {
                    self->field_10--;
                    func_00454D80(&D_01E97F38, 0, self->field_10, D_01E901A0[self->field_10]);
                }
            } else {
                SetScene(0x94413CD3ABD53F29UL);
            }
            break;
        }
        break;
    }
}
