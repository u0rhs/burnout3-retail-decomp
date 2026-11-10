// CB3OnlineGameCreateState::Action(EGtStateAction,void*,void*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineGameCreateState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a148: nested event switch (default first, field_10=1 in case 0), SetScene inline, 8-byte union copies stored between the loads).

enum EGtStateAction {};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_FSM {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_Lob {
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
    virtual int vfunc_68();
};
struct UnkStruct_Lob2 {
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
};
struct UnkStruct_r { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_s { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_D_01EA2974 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2980 { UnkStruct_s * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2984 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_U { unsigned int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_Q { unsigned long field_0; unsigned long pad_8; };
struct UnkStruct_Cp { unsigned char pad_0[0x8]; int field_8; unsigned char pad_C[0x34]; };
struct UnkStruct_GCS {
    unsigned char pad_0[0x10];
    int field_10;
};
union UnkUnion_8 { unsigned long l; struct { int a; int b; } s; };
extern UnkStruct_P D_01E32AE0;
extern UnkStruct_P D_01E9987C;
extern UnkStruct_P D_01E9996C;
extern UnkStruct_P D_01EA0070;
extern UnkStruct_Cp D_01E99880;
extern UnkStruct_I D_01E9988C;
extern UnkStruct_I D_01E99894;
extern UnkStruct_U D_01E99898;
extern UnkStruct_U D_01E9989C;
extern UnkStruct_I D_01E998A0;
extern UnkStruct_I D_01E998A4;
extern UnkStruct_I D_01E998A8;
extern UnkStruct_I D_01E900C0;
extern UnkStruct_Q D_01E90198;
extern UnkStruct_Q D_01E901F0;
extern UnkStruct_B D_01EA0771;
extern UnkStruct_B D_01EA0772;
extern UnkStruct_P D_01E3CD44;
extern UnkStruct_P D_01E3C620;
extern UnkStruct_FSM D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern "C" void * memset(void *, int, unsigned int);
extern "C" void ClearAllPlayers__23CGtNetworkPlayerManagerFv(void *);
extern "C" void RestNATStatusData__17CB3NetworkManagerFv(void *);
extern "C" void SetGameID__23CGtNetworkPlayerManagerFi(void *, int);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int func_00399130(void *);
extern "C" void func_003986C0(void *);
extern "C" void func_00398670(void *);
extern "C" void OnKeyboardCancel__30CB3OnlineGameCreateOptionsPageFv(void *);
extern "C" int func_003A03B0(void *, int, void *);
extern "C" void Prepare__23CB3OnlineGameCreatePageFP24CB3LobbyCreateGameParams(void *, void *);
extern "C" void func_00235D90(void *);
extern "C" void func_00324E10(void *);
extern "C" void func_0022D400(void *);

static inline void SetScene(unsigned long h)
{
    UnkStruct_r * r = (UnkStruct_r *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, h);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_FSM *)&D_01EA2970)->vfunc_18(r, 0);
    void * t = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_s * s = D_01EA2980.field_0;
    if (s != 0) {
        D_01EA2984.field_0 = s->field_20;
        if (r != 0) {
            r->field_8 = s->field_20;
        }
    }
    ((UnkStruct_FSM *)&D_01EA2970)->vfunc_1C(t, 0);
}

extern "C" void Action__24CB3OnlineGameCreateStateF14EGtStateActionPvPvPv(UnkStruct_GCS * self, EGtStateAction p0, void * p1, void * p2, void * p3)
{
    switch (p0) {
    case 0:
        memset(&D_01E99880, 0, 0x3C);
        D_01E99880.field_8 = 6;
        D_01E9989C.field_0 = (D_01E9989C.field_0 & 0x00FFFFFF) | 0x03000000;
        D_01E99898.field_0 = (D_01E99898.field_0 & 0xFF00FFFF) | 0x10000;
        break;
    case 3:
        self->field_10 = 0;
        ClearAllPlayers__23CGtNetworkPlayerManagerFv(&D_01E32AE0);
        RestNATStatusData__17CB3NetworkManagerFv(&D_01E32AE0);
        func_00399130(&D_01E9987C);
        break;
    case 2:
        break;
    case 5:
        switch ((int)p2) {
        case 1: case 0: case 2:
            switch (self->field_10) {
            default:
                break;
            case 0:
                self->field_10 = 1;
                D_01EA0771.field_0 = 0;
                D_01EA0772.field_0 = 0;
                func_003A03B0(&D_01EA0070, 1, &D_01E99880);
                break;
            case 1: {
                UnkUnion_8 hi;
                UnkUnion_8 lo;
                D_01E900C0.field_0 = D_01E99894.field_0;
                self->field_10 = 2;
                hi.s.a = D_01E9988C.field_0;
                hi.s.b = D_01E998A0.field_0;
                D_01E90198.field_0 = hi.l;
                lo.s.a = D_01E998A4.field_0;
                lo.s.b = D_01E998A8.field_0;
                D_01E901F0.field_0 = lo.l;
                Prepare__23CB3OnlineGameCreatePageFP24CB3LobbyCreateGameParams(&D_01E9996C, &D_01E99880);
                break; }
            case 2: {
                char buf[32];
                SetGameID__23CGtNetworkPlayerManagerFi(&D_01E32AE0, ((UnkStruct_Lob *)&D_01E3CD44)->vfunc_68());
                ((UnkStruct_Lob2 *)&D_01E3C620)->vfunc_3C();
                func_00235D90(&D_01E32AE0);
                func_00324E10(buf);
                func_0022D400(buf);
                SetScene(0x94414018F8506AFEUL);
                break; }
            }
            break;
        case 3:
            switch (self->field_10) {
            case 0:
                SetScene(0x94414018F8535FC2UL);
                break;
            case 1:
                self->field_10 = 0;
                func_00399130(&D_01E9987C);
                break;
            case 2:
                SetScene(0x94414018F8535FC2UL);
                break;
            }
            break;
        case 0x1B:
            if (self->field_10 == 0) {
                func_003986C0(&D_01E9987C);
            }
            break;
        case 0x19:
            if (self->field_10 == 0) {
                func_00398670(&D_01E9987C);
            }
            break;
        case 0x1A:
            if (self->field_10 == 0) {
                OnKeyboardCancel__30CB3OnlineGameCreateOptionsPageFv(&D_01E9987C);
            }
            break;
        }
        break;
    }
}
