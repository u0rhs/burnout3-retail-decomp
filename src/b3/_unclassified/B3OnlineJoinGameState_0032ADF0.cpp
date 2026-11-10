// CB3OnlineJoinGameState::Action(EGtStateAction,void*,void*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineJoinGameState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (sibling GameCreateState shape: SetScene(h,k) inline, one-case switch(field_10)).

// CB3OnlineJoinGameState::Action(EGtStateAction,void*,void*,void*)
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineJoinGameState.cpp.
// Hand-written (L243) after the matched sibling B3OnlineGameCreateState_003248F0.cpp (SetScene inline, one-case event switches).

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
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_r { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_s { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_D_01EA2974 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2980 { UnkStruct_s * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2984 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_Q { unsigned long field_0; unsigned long pad_8; };
struct UnkStruct_JGS {
    unsigned char pad_0[0x10];
    int field_10;
};
extern UnkStruct_Q D_01E90130;
extern UnkStruct_Q D_01E999A8;
extern UnkStruct_Q D_01E90198;
extern UnkStruct_I D_01E999D4;
extern UnkStruct_I D_01E900C0;
extern UnkStruct_P D_01E999A0;
extern UnkStruct_FSM D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void Prepare__21CB3OnlineJoinGamePageFPcPcPcib(void *, char *, char *, char *, int, bool);
extern "C" void OnKeyboardDone__21CB3OnlineJoinGamePageFv(void *);
extern "C" void OnKeyboardShow__21CB3OnlineJoinGamePageFv(void *);
extern "C" void OnKeyboardCancel__21CB3OnlineJoinGamePageFv(void *);

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

extern "C" void Action__22CB3OnlineJoinGameStateF14EGtStateActionPvPvPv(UnkStruct_JGS * self, EGtStateAction p0, void * p1, void * p2, void * p3)
{
    switch (p0) {
    case 3:
        self->field_10 = 0;
        D_01E90130.field_0 = 0;
        Prepare__21CB3OnlineJoinGamePageFPcPcPcib(&D_01E999A0, 0, 0, 0, -1, false);
        break;
    case 2:
        break;
    case 5:
        switch ((int)p2) {
        case 1:
            switch (self->field_10) {
            case 0:
                D_01E90198.field_0 = D_01E999A8.field_0;
                D_01E900C0.field_0 = D_01E999D4.field_0;
                SetScene(0x94414018F8506AFEUL, 0);
                break;
            }
            break;
        case 3:
            switch (self->field_10) {
            case 0:
                SetScene(0x94414018F8535FC2UL, 0);
                break;
            }
            break;
        case 0x18:
            SetScene(0x94414018F8535FC2UL, 0);
            break;
        case 0x1B:
            OnKeyboardDone__21CB3OnlineJoinGamePageFv(&D_01E999A0);
            break;
        case 0x19:
            OnKeyboardShow__21CB3OnlineJoinGamePageFv(&D_01E999A0);
            break;
        case 0x1A:
            OnKeyboardCancel__21CB3OnlineJoinGamePageFv(&D_01E999A0);
            break;
        case 0x24:
            SetScene(0x94413E2F8A91F137UL, 1);
            break;
        }
        break;
    }
}
