// NONMATCHING: func_00310200 -- retail 1133 / ours 1133 instructions, 35 in changed runs
// 1133/1133, 35 changed: logic, calls, block layout, frame exact; left = scheduling of the inline's D_01E94F08=0 store (retail hoists it above the D_01E900E0 increment store in the E0<1 and E0==0 paths; ours keeps it after: source-order and page-struct forms negative) + one v0/v1 pick in the c223==0 path -> permuter
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm and Ghidra; every call, branch and store accounted for (draftW)

// func_00310200 -- car-select FSM state Action handler.
// [L] DNAT: CB3CarSelectState::Action(EGtStateAction,void*,void*,void*) (research/proto/new_names.csv, medium).
// SetScene inline as the matched func_0030F620 (CB3OnlineLobbyState::Action) [L]; D_01E900B0 = CB3MenuChoices object
// (RequestNewGameMode__14CB3MenuChoicesFv's this) [C].

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
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_L { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_UB { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_00310200_c8 { unsigned long field_0; int field_8; };

extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
// CB3MenuChoices object at D_01E900B0 [C] (this of RequestNewGameMode); fields by offset, names placeholders.
struct UnkStruct_D_01E900B0 {
    unsigned char pad_0[0x4];
    int field_4;                        // game mode [G]
    unsigned char pad_8[0x4];
    int field_C;
    unsigned char pad_10[0x14];
    int field_24;                       // player count [G]
    unsigned char pad_28[0x8];
    int field_30;                       // current player [G]
    unsigned char pad_34[0x8];
    int field_3C[0x11];
    unsigned long field_80[8];          // car id per player [G]
    int field_C0[0x16];                 // colour per player [G]
    UnkStruct_00310200_c8 * field_118;
    unsigned char pad_11C[0x57];
    unsigned char field_173;
    unsigned char field_174;
    unsigned char pad_175[0xB];
};
extern UnkStruct_D_01E900B0 D_01E900B0;
extern UnkStruct_P D_01E94EF0;
extern UnkStruct_L D_01E94EF8;
extern UnkStruct_I D_01E94F08;
extern UnkStruct_I D_01E94F18;
extern UnkStruct_P D_004F50C0;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int GetClassFromID__14CB3VehicleListFUl(unsigned long);
extern "C" void RequestNewGameMode__14CB3MenuChoicesFv(void *);
extern "C" void LockPlayerToPort__15CB3InputManagerFScSc(void *, signed char, signed char);
extern "C" void func_002142A0(void *, int);
extern "C" int func_0030CEC0(void *);
extern "C" int func_0030CE80(void *);
extern "C" void func_0030B9D0(void *, int);
extern "C" bool func_00318F50(void *self, int p0, unsigned long p1, int p2, int p3, bool p4, unsigned long p5, int p6);

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

// show the current player's car on the car-select page [G]
static inline void func_00310200_inl1(unsigned long car, int colour)
{
    D_01E94F08.field_0 = 0;
    unsigned long p = 0;
    switch (D_01E900B0.field_4) {
    case 0:
        if (D_01E900B0.field_118 != 0 && D_01E900B0.field_118->field_8 == 2) {
            p = D_01E900B0.field_118->field_0;
        }
        break;
    case 2:
        if (D_01E900B0.field_C != 4 || D_01E900B0.field_174 != 0) {
            D_01E94F08.field_0 = D_01E900B0.field_30 % 2;
        }
        break;
    }
    func_00318F50(&D_01E94EF0, D_01E900B0.field_3C[D_01E900B0.field_30], p, func_0030CEC0(&D_01E900B0), func_0030CE80(&D_01E900B0), 1, car, colour);
}

// car id -> class; the special class 5 is split by the current car id [G]
static inline int func_00310200_inl2(unsigned long id)
{
    int c = GetClassFromID__14CB3VehicleListFUl(id);
    if (c == 5) {
        switch (D_01E94EF8.field_0) {
        case 0x790798FBA1182C00UL:
        default:
            c = 1;
            break;
        case 0x790798FBA1163800UL:
            c = 2;
            break;
        case 0x790798FBA1153E00UL:
            c = 3;
            break;
        case 0x790798FBA1173200UL:
            c = 4;
            break;
        case 0x7704283867422A00UL:
            c = 6;
            break;
        case 0x790798FBA1192600UL:
        case 0x790798FBA11A2000UL:
            c = 5;
            break;
        }
    }
    return c;
}

// copy player 0's car and colour to every player [G]
static inline void func_00310200_inl3(UnkStruct_D_01E900B0 * self)
{
    for (int i = 1; i < self->field_24; i++) {
        self->field_80[i] = self->field_80[0];
        self->field_C0[i] = self->field_C0[0];
    }
}

// copy the first pair's cars to every pair [G]
static inline void func_00310200_inl4(UnkStruct_D_01E900B0 * self)
{
    for (int i = 2; i < self->field_24; i += 2) {
        self->field_80[i] = self->field_80[0];
        self->field_80[i + 1] = self->field_80[1];
    }
}

// 0x00310200
extern "C" void func_00310200(void * self, int action, void * p1, void * p2, int p3)
{
    switch (action) {
    case 3:
        switch (D_01E900B0.field_4) {
        case 0:
        default:
            func_00310200_inl1(0, 0);
            break;
        case 1:
        case 2:
            {
                unsigned long car = D_01E900B0.field_80[0];
                int colour = D_01E900B0.field_C0[0];
                func_00310200_inl1(car, colour);
            }
            break;
        }
        break;
    case 5:
        switch ((int)p2) {
        case 0:
            D_01E900B0.field_80[D_01E900B0.field_30] = D_01E94EF8.field_0;
            D_01E900B0.field_C0[D_01E900B0.field_30] = D_01E94F18.field_0;
            switch (D_01E900B0.field_4) {
            case 0:
            default:
                D_01E900B0.field_30 = 1;
                SetScene(0x94414036C5AD5E97UL, 0);
                break;
            case 1:
                D_01E900B0.field_30 = 1;
                func_0030B9D0(&D_01E900B0, func_00310200_inl2(D_01E94EF8.field_0));
                SetScene(0x94414036C5AD5E97UL, 0);
                break;
            case 4:
                D_01E900B0.field_30 = 1;
                RequestNewGameMode__14CB3MenuChoicesFv(&D_01E900B0);
                break;
            case 3:
                D_01E900B0.field_30 = 1;
                RequestNewGameMode__14CB3MenuChoicesFv(&D_01E900B0);
                break;
            case 2:
                if (D_01E900B0.field_C == 4) {
                    if (D_01E900B0.field_173 != 0) {
                        if (D_01E900B0.field_174 == 0) {
                            func_00310200_inl3(&D_01E900B0);
                            RequestNewGameMode__14CB3MenuChoicesFv(&D_01E900B0);
                        } else if (D_01E900B0.field_30 == 0) {
                            D_01E900B0.field_30++;
                            func_00310200_inl1(D_01E900B0.field_80[D_01E900B0.field_30 - 1], D_01E900B0.field_C0[D_01E900B0.field_30 - 1]);
                        } else {
                            LockPlayerToPort__15CB3InputManagerFScSc(&D_004F50C0, 1, p3);
                            func_00310200_inl4(&D_01E900B0);
                            D_01E900B0.field_30 = 0;
                            RequestNewGameMode__14CB3MenuChoicesFv(&D_01E900B0);
                        }
                    } else {
                        if (D_01E900B0.field_174 != 0 && D_01E900B0.field_30 == 1) {
                            LockPlayerToPort__15CB3InputManagerFScSc(&D_004F50C0, 1, p3);
                        }
                        D_01E900B0.field_30++;
                        if (D_01E900B0.field_30 < D_01E900B0.field_24) {
                            func_00310200_inl1(D_01E900B0.field_80[D_01E900B0.field_30 - 1], D_01E900B0.field_C0[D_01E900B0.field_30 - 1]);
                        } else {
                            RequestNewGameMode__14CB3MenuChoicesFv(&D_01E900B0);
                            D_01E900B0.field_30 = 0;
                        }
                    }
                } else if (D_01E900B0.field_30 > 0) {
                    D_01E900B0.field_30 = 2;
                    LockPlayerToPort__15CB3InputManagerFScSc(&D_004F50C0, 1, p3);
                    int c0 = func_00310200_inl2(D_01E900B0.field_80[0]);
                    int c1 = func_00310200_inl2(D_01E900B0.field_80[1]);
                    if (c0 < c1) func_0030B9D0(&D_01E900B0, c0);
                    else func_0030B9D0(&D_01E900B0, c1);
                    RequestNewGameMode__14CB3MenuChoicesFv(&D_01E900B0);
                } else {
                    D_01E900B0.field_30++;
                    func_00310200_inl1(D_01E900B0.field_80[D_01E900B0.field_30], D_01E900B0.field_C0[D_01E900B0.field_30]);
                }
                break;
            }
            break;
        case 3:
            if (D_01E900B0.field_30 > 0) {
                D_01E900B0.field_30--;
                if (D_01E900B0.field_4 == 2 && D_01E900B0.field_C != 4) {
                    func_002142A0(&D_004F50C0, 1);
                }
                func_00310200_inl1(D_01E900B0.field_80[D_01E900B0.field_30], D_01E900B0.field_C0[D_01E900B0.field_30]);
            } else {
                switch (D_01E900B0.field_4) {
                case 0:
                default:
                    SetScene(0x94413E52C3BF9CAAUL, 3);
                    break;
                case 1:
                    SetScene(0x94413CAD86353F29UL, 3);
                    break;
                case 2:
                    if (D_01E900B0.field_C == 4) SetScene(0x94414032DE75847DUL, 3);
                    else SetScene(0x94413CD3ABD53F29UL, 3);
                    break;
                }
            }
            break;
        }
        break;
    }
}




