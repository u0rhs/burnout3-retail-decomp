// CB3OnlineBuddiesState::Action(EGtStateAction,void*,void*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineBuddiesState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (sig1: func_00438520 takes 3 args (callee saves a2); the case-0x26 call passes 1, which MWCC takes from the case-1 compare constant already in a2 -- that fixed the a1/a2 compare swap).


// CB3OnlineBuddiesState::Action(EGtStateAction,void*,void*,void*)
// [C] name: the mangled symbol in retail's tables. Area not evidenced, so _unclassified/ (docs/conventions.md).
// Hand-written (L254) from the asm after the matched siblings B3OnlineJoinGameState_0032ADF0.cpp /
// func_003C71B0 (SetScene(h, k) inline, one-case event switches). Field names are placeholders; types [G].

enum EGtStateAction {};
struct UnkStruct_FSM {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E3CD44 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual int vfunc_D8();
    unsigned char pad_4[0xC];
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_r { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_s { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_D_01EA2974 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2980 { UnkStruct_s * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2984 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_C { char * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_Id { unsigned long field_0; };
struct UnkStruct_BS {
    unsigned char pad_0[0x10];
    unsigned long field_10;
    int field_18;
    unsigned char field_1C;
    unsigned char field_1D;
    char field_1E[0x10];
    char field_2E[0xC8];
    char field_F6[1];
};
extern UnkStruct_P D_01E9B794;
extern UnkStruct_P D_01E9B8F8;
extern UnkStruct_P D_01E8D670;
extern UnkStruct_P D_01E3D390;
extern UnkStruct_P D_01E9B634;
extern UnkStruct_P D_01E999A0;
extern UnkStruct_P D_01E9C870;
extern UnkStruct_P D_01EA08A0;
extern UnkStruct_P D_01E9B798;
extern char D_01E9B7A8[];
extern char D_01E9B7C8[];
extern UnkStruct_C D_01E9B7EC;
extern UnkStruct_I D_01E9B7E8;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_FSM D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int func_00370F30(void *);
extern "C" int func_003734F0(void *);
extern "C" int func_00438520(void *, void *, int);
extern "C" int func_00383830(void *, int, int);
extern "C" int func_0043B4A0(void *, void *);
extern "C" void func_0036F650(void *);
extern "C" void func_00373100(void *);
extern "C" void func_0036F3D0(void *);
extern "C" void func_0036F3E0(void *);
extern "C" void GetSelectedBuddyName__24CB3BuddyDisplayComponentFPc(void *, char *);
extern "C" void GetAndRemoveMail__22CGtBuddiesPS2DirtySockFPciPcPc(void *, char *, int, char *, char *);
extern "C" void Prepare__21CB3OnlineJoinGamePageFPcPcPcib(void *, char *, char *, char *, int, bool);
extern "C" void OnKeyboardShow__30CB3OnlineBuddiesSearchMenuPageFv(void *);
extern "C" void OnKeyboardCancel__30CB3OnlineBuddiesSearchMenuPageFv(void *);

static inline void SetScene(unsigned long h, int k)
{
    UnkStruct_r * r = (UnkStruct_r *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, h);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_FSM *)&D_01EA2970)->vfunc_18(r, k);
    void * t = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_s * s = D_01EA2980.field_0;
    if (s != 0) {
        D_01EA2984.field_0 = s->field_20;
        if (r != 0) {
            r->field_8 = s->field_20;
        }
    }
    ((UnkStruct_FSM *)&D_01EA2970)->vfunc_1C(t, k);
}

extern "C" void Action__21CB3OnlineBuddiesStateF14EGtStateActionPvPvPv(UnkStruct_BS * self, EGtStateAction p0, void * p1, void * p2, void * p3)
{
    switch (p0) {
    case 3:
        self->field_1C = 0;
        func_00370F30(&D_01E9B794);
        self->field_10 = ((UnkStruct_Id *)p2)->field_0;
        self->field_18 = (int)p3;
        break;
    case 5:
        switch ((int)p2) {
        case 0x18:
            self->field_1C = 0;
            func_00370F30(&D_01E9B794);
            break;
        case 0x25:
            if (self->field_1C != 5) {
                GetSelectedBuddyName__24CB3BuddyDisplayComponentFPc(&D_01E8D670, self->field_1E);
                GetAndRemoveMail__22CGtBuddiesPS2DirtySockFPciPcPc(&D_01E3D390, self->field_1E, 0, self->field_2E, self->field_F6);
            }
            func_003734F0(&D_01E9B8F8);
            self->field_1C = 1;
            break;
        case 0x26:
            func_00438520(&D_01E9B634, self->field_1E, 1);
            self->field_1C = 5;
            break;
        case 1:
            switch (self->field_1C) {
            case 1:
                func_00370F30(&D_01E9B794);
                self->field_1C = 0;
                break;
            case 2:
                SetScene(0x94414018F8506AFEUL, 0);
                break;
            case 3:
                SetScene(0x94414018F8535FC2UL, 0);
                break;
            case 4:
                self->field_1C = self->field_1D;
                switch (self->field_1C) {
                case 0:
                    func_00370F30(&D_01E9B794);
                    break;
                }
                break;
            }
            break;
        case 3:
            switch (self->field_1C) {
            case 0:
                if (self->field_10 == 0x94414018F8506AFEUL) {
                    if (((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_D8() != 0) {
                        SetScene(self->field_10, self->field_18);
                    } else {
                        SetScene(0x94414018F8535FC2UL, self->field_18);
                    }
                } else {
                    SetScene(self->field_10, self->field_18);
                }
                break;
            case 1:
                func_00370F30(&D_01E9B794);
                self->field_1C = 0;
                break;
            case 4:
                self->field_1C = self->field_1D;
                switch (self->field_1C) {
                case 0:
                    func_00370F30(&D_01E9B794);
                    break;
                }
                break;
            }
            break;
        case 0x20:
            if (self->field_1C == 0) {
                Prepare__21CB3OnlineJoinGamePageFPcPcPcib(&D_01E999A0, D_01E9B7A8, D_01E9B7EC.field_0, D_01E9B7C8, D_01E9B7E8.field_0, false);
            }
            self->field_1C = 2;
            break;
        case 0x1F:
            if (self->field_1C == 0) {
                func_00383830(&D_01E9C870, (int)(D_01E9B7EC.field_0), 1);
            }
            self->field_1C = 3;
            break;
        case 0x2C:
            if (self->field_1C == 0) {
                self->field_1D = 0;
                func_0043B4A0(&D_01EA08A0, &D_01E9B798);
            }
            self->field_1C = 4;
            break;
        case 0x1B:
            switch (self->field_1C) {
            case 0:
                func_0036F650(&D_01E9B794);
                break;
            case 1:
                func_00373100(&D_01E9B8F8);
                break;
            }
            break;
        case 0x19:
            switch (self->field_1C) {
            case 0:
                func_0036F3D0(&D_01E9B794);
                break;
            case 1:
                OnKeyboardShow__30CB3OnlineBuddiesSearchMenuPageFv(&D_01E9B8F8);
                break;
            }
            break;
        case 0x1A:
            switch (self->field_1C) {
            case 0:
                func_0036F3E0(&D_01E9B794);
                break;
            case 1:
                OnKeyboardCancel__30CB3OnlineBuddiesSearchMenuPageFv(&D_01E9B8F8);
                break;
            }
            break;
        }
        break;
    }
}
