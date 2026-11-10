// CB3OnlineMenuState::HandleMainMenuEvents(EB3MenuFlowFSMEvents) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineMenuState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (SetScene inline, jtbl cases in block order 0,1,2,4,3,5; signature as sibling func_003242F0 declares).

// CB3OnlineMenuState::HandleMainMenuEvents(EB3MenuFlowFSMEvents)
// [C] name: the mangled symbol in retail's tables. Hand-written (L243) after the matched sibling func_003242F0.cpp
// (same class; SetScene inline) -- jump table on D_01E99844, cases in retail's block order.

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
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_H { unsigned short field_0; unsigned char pad_2[0xE]; };

struct UnkStruct_00323E30 {
    unsigned char pad_0[0x10];
    int field_10;
};

extern UnkStruct_H D_01E99844;
extern UnkStruct_P D_01E9C870;
extern UnkStruct_P D_01EA1B20;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int func_00383830(void *, int, int);
extern "C" int func_0045B1F0(void *);

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

extern "C" void HandleMainMenuEvents__18CB3OnlineMenuStateF20EB3MenuFlowFSMEvents(void * selfv, int p0_)
{
    void * p0 = (void *)p0_;
    // signature as declared by the sibling func_003242F0.cpp (same TU on merge)
    UnkStruct_00323E30 * self = (UnkStruct_00323E30 *)selfv;
    switch ((int)p0) {
    case 1:
        switch (D_01E99844.field_0) {
        case 0:
            SetScene(0x9441401B116D104FUL, 1);
            break;
        case 1:
            SetScene(0x9441401B116D104FUL, 0);
            break;
        case 2:
            self->field_10 = 1;
            func_00383830(&D_01E9C870, -1, 0);
            break;
        case 4:
            SetScene(0x94413FEA821D8028UL, 0);
            break;
        case 3:
            SetScene(0x9441407F0FDC9797UL, 0);
            break;
        case 5:
            self->field_10 = 2;
            func_0045B1F0(&D_01EA1B20);
            break;
        }
        break;
    case 3:
        SetScene(0x94413FC035B0F871UL, 0);
        break;
    case 0x24:
        SetScene(0x94413E2F8A91F137UL, 0);
        break;
    }
}
