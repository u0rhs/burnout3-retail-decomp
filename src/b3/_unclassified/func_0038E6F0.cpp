// Hand-written; the lifter refused it (CB3OnlineCoOpCrashLogic::Update [L] DNAT: block-form 'if (call()) {state=N;} break;' (not early return), case 9 + default: break at the switch end followed by explicit return;, car const ptr declared before first call, vcall via cast).

struct UnkStruct_D_00 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_uc { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_sc { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_0064D3B0 { unsigned char pad_0[0x18EA]; unsigned char field_18EA; unsigned char pad_18EB[0x15]; };
struct UnkStruct_D_00516E40 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_004F50C0 { unsigned char pad_0[0x10]; };
struct UnkStruct_0038E6F0 {
    unsigned char pad_0[0x4A];
    unsigned char field_4A;
    unsigned char pad_4B[0x15];
    int field_60;
    unsigned char pad_64[8];
    unsigned char field_6C;
    unsigned char field_6D;
    unsigned char pad_6E;
    unsigned char field_6F;
    unsigned char field_70;
    unsigned char pad_71;
    unsigned char field_72;
};
enum EB3ScoreFinishState {};
extern UnkStruct_D_00 D_01E32AE0;
extern UnkStruct_D_00 D_01E7A888;
extern UnkStruct_D_00 D_01E90240;
extern UnkStruct_D_00 D_01E900B0;
extern UnkStruct_D_int D_01E32B08;
extern UnkStruct_D_int D_01E90430;
extern UnkStruct_D_int D_0064EA78;
extern UnkStruct_D_uc D_0064FB79;
extern UnkStruct_D_sc D_004F6061;
extern UnkStruct_D_0064D3B0 D_0064D3B0;
extern UnkStruct_D_00516E40 D_00516E40;
extern UnkStruct_D_004F50C0 D_004F50C0;
extern "C" void func_0026FAA0(void *, int);
extern "C" void func_003FA600(void *, int);
extern "C" int func_00391B80(void *, int, int);
extern "C" int UpdateLaunch__19CB3OnlineStageLogicFv(void *);
extern "C" void func_00391B20(void *);
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);
extern "C" int func_00391820(void *);
extern "C" int func_003916D0(void *);
extern "C" int func_00391630(void *);
extern "C" void SetFinished__10CB3RaceCarF19EB3ScoreFinishState(void *, EB3ScoreFinishState);
extern "C" int func_00391490(void *);
extern "C" void func_003906F0(void *);
extern "C" int func_00390380(void *);
extern "C" int func_003910B0(void *, int);
extern "C" int func_00390D70(void *);
extern "C" void * func_002366D0(void *, int);
extern "C" void func_003CC280(void *, int);
extern "C" int func_00270AC0(void *);
extern "C" void ReleaseCurrentMenu__18CB3MenuPageManagerFv(void *);
extern "C" void PrepareForGameStart__17CB3NetworkManagerFv(void *);
extern "C" void func_0026DE80(void *, int);
extern "C" void RequestNewGameMode__14CB3MenuChoicesFv(void *);

// 0x0038E6F0
extern "C" void func_0038E6F0(UnkStruct_0038E6F0 * self)
{
    func_0026FAA0(&D_01E32AE0, 0);
    if (self->field_60 == 13) {
        return;
    }
    if (self->field_6F != 0) {
        self->field_60 = 12;
    }
    switch (self->field_60) {
    case 0:
        self->field_60 = 1;
        break;
    case 1:
        func_003FA600(&D_01E7A888, 4);
        if (func_00391B80(self, 1, 1) != 0) {
            self->field_60 = 2;
        }
        break;
    case 2:
        if (UpdateLaunch__19CB3OnlineStageLogicFv(self) != 0) {
            func_00391B20(self);
            if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) {
                self->field_60 = 3;
            } else {
                self->field_60 = 4;
            }
        }
        break;
    case 3:
        if (func_00391820(self) != 0) {
            self->field_60 = 5;
        }
        break;
    case 4:
        if (func_003916D0(self) != 0) {
            self->field_60 = 5;
        }
        break;
    case 5:
        func_00391630(self);
        break;
    case 6: {
        UnkStruct_D_0064D3B0 * const car = &D_0064D3B0;
        func_003FA600(&D_01E7A888, 5);
        if (self->field_6C != 0) {
            if (self->field_6D != 0) {
                SetFinished__10CB3RaceCarF19EB3ScoreFinishState(car, (EB3ScoreFinishState)6);
            }
        } else {
            if (car->field_18EA != 0) {
                self->field_6C = 1;
            }
        }
        if (func_00391490(self) != 0) {
            if (D_0064EA78.field_0 == 1) {
                ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(18, 0);
                D_0064FB79.field_0 = 1;
            }
            func_003906F0(self);
            self->field_60 = 7;
        } else {
            func_00390380(self);
        }
        break;
    }
    case 7: {
        int k = D_004F6061.field_0 * 15;
        *(short *)((char *)&D_004F50C0 + (k + k * 4) * 4 + 0xD8E) = 0;
        if (func_003910B0(self, k) != 0) {
            self->field_72 = 1;
            self->field_60 = 8;
        }
        break;
    }
    case 8:
        if (func_00390D70(self) != 0) {
            self->field_60 = 10;
        }
        break;
    case 10: {
        if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0 && self->field_4A != 0) {
            int n = D_01E32B08.field_0;
            for (int i = 0; i < n; i++) {
                void * pl = func_002366D0(&D_01E32AE0, i);
                if (pl != 0) {
                    func_003CC280((char *)pl + 0x1630, 8);
                }
            }
            self->field_60 = 11;
        }
        break;
    }
    case 11: {
        bool ok = true;
        int n = D_01E32B08.field_0;
        for (int i = 0; i < n; i++) {
            void * pl = func_002366D0(&D_01E32AE0, i);
            if (pl != 0) {
                if (*((unsigned char *)pl + 0x4EFC) == 0) {
                    ok = false;
                }
            }
        }
        if (self->field_70 != 0 || ok) {
            self->field_60 = 12;
        }
        break;
    }
    case 12:
        func_00270AC0(&D_01E32AE0);
        if (D_01E90430.field_0 != 0) {
            ReleaseCurrentMenu__18CB3MenuPageManagerFv(&D_01E90240);
        }
        PrepareForGameStart__17CB3NetworkManagerFv(&D_01E32AE0);
        func_0026DE80(&D_01E32AE0, 0);
        RequestNewGameMode__14CB3MenuChoicesFv(&D_01E900B0);
        self->field_60 = 13;
    case 9:
    default:
        break;
    }
    return;
}
