// func_0036B0A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (case-3 field_10 test is switch { default: case 1: call; case 0: else } (dead li v0,1 = dropped compare, a62 rule)).


// func_0036B0A0 -- CB3OnlineOptimatchState::Action(EGtStateAction,void*,void*,void*)
// [L] DNAT: CB3OnlineOptimatchState::Action(EGtStateAction,void*,void*,void*) (research/proto/new_names.csv, medium)

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
struct UnkStruct_L { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };

class CB3OnlineOptimatchState {
public:
    unsigned char pad_0[0x10];
    int field_10;
    int field_14;
    int field_18;
    short field_1C;
    short field_1E;
};

extern UnkStruct_P D_01E9E050;
extern UnkStruct_L D_01E9E058;
extern UnkStruct_I D_01E9E064;
extern UnkStruct_P D_01E9F9A0;
extern UnkStruct_L D_01E90130;
extern UnkStruct_L D_01E90198;
extern UnkStruct_I D_01E900C0;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int func_0045BF40(void *, void *);
extern "C" int func_0037C250(void *, int, void *);

static inline void SetScene(unsigned long h, int k)
{
    UnkStruct_r * r = (UnkStruct_r *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, h);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, k);
    void * t = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_s * s = D_01EA2980.field_0;
    if (s != 0) {
        D_01EA2984.field_0 = s->field_20;
        if (r != 0) {
            r->field_8 = s->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t, k);
}

// 0x0036B0A0
extern "C" void func_0036B0A0(CB3OnlineOptimatchState * self, EGtStateAction p0, void * p1, void * p2, void * p3)
{
    switch (p0) {
    case 0:
        self->field_10 = 1;
        break;
    case 3:
        if (*(unsigned long *)p2 == 0x94413E2F8A91F137UL) {
            switch (self->field_10) {
            default:
            case 1:
                func_0045BF40(&D_01E9F9A0, &self->field_18);
                break;
            case 0:
                func_0037C250(&D_01E9E050, self->field_14, &self->field_18);
                break;
            }
        } else {
            self->field_14 = (int)p3;
            D_01E90130.field_0 = 0;
            if (self->field_14 == 1) {
                func_0037C250(&D_01E9E050, *(const int *)&self->field_14, &self->field_18);
                self->field_10 = 0;
            } else {
                self->field_1C = 0;
                self->field_18 = 0;
                self->field_1E = 5;
                func_0045BF40(&D_01E9F9A0, &self->field_18);
                self->field_10 = 1;
            }
        }
        break;
    case 5:
        switch ((int)p2) {
        case 1:
            switch (self->field_10) {
            case 0:
                D_01E90198.field_0 = D_01E9E058.field_0;
                D_01E900C0.field_0 = D_01E9E064.field_0;
                SetScene(0x94414018F8506AFEUL, 0);
                break;
            case 1:
                self->field_10 = 0;
                func_0037C250(&D_01E9E050, self->field_14, &self->field_18);
                break;
            }
            break;
        case 3:
            switch (self->field_10) {
            case 0:
                if (self->field_14 == 1) {
                    SetScene(0x94414018F8512871UL, 0);
                } else {
                    func_0045BF40(&D_01E9F9A0, &self->field_18);
                    self->field_10 = 1;
                }
                break;
            case 1:
                SetScene(0x94414018F8512871UL, 0);
                break;
            }
            break;
        case 0x18:
            if (self->field_14 == 1) {
                SetScene(0x94414018F8512871UL, 0);
            } else {
                func_0045BF40(&D_01E9F9A0, &self->field_18);
                self->field_10 = 1;
            }
            break;
        case 0x2D:
            SetScene(0x94414018F84B7CB7UL, 0);
            break;
        case 0x24:
            SetScene(0x94413E2F8A91F137UL, 1);
            break;
        }
        break;
    }
}
