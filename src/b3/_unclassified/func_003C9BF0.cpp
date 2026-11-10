// Hand-written; the lifter refused it (CB3TwoPlayerModeSelectState::Action: default-last switches, p3 long, == 2 || == 3).

// func_003C9BF0 -- CB3TwoPlayerModeSelectState::Action(EGtStateAction,void*,void*,void*)
// [L] DNAT: CB3TwoPlayerModeSelectState::Action(EGtStateAction,void*,void*,void*) (research/proto/new_names.csv, medium)

enum EGtStateAction {};

class CB3InputManager {
public:
    void LockPlayerToPort(signed char, signed char);
    unsigned char pad_0[0x10];
};

struct UnkStruct_D_01EA2970 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_003C9BF0_r { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_003C9BF0_s { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_D_01EA2974 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2980 { UnkStruct_003C9BF0_s * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2984 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_L { long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_B { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };

class CB3TwoPlayerModeSelectState {
public:
    void Action(EGtStateAction p0, void* p1, void* p2, void* p3);
    unsigned char pad_0[0x10];
    signed char field_10;
};

extern CB3InputManager D_004F50C0;
extern UnkStruct_I D_01E900BC;
extern UnkStruct_I D_01E900C8;
extern UnkStruct_I D_01E900D4;
extern UnkStruct_I D_01E900D8;
extern UnkStruct_I D_01E900E0;
extern UnkStruct_I D_01E900EC;
extern UnkStruct_I D_01E900F0;
extern UnkStruct_L D_01E90198;
extern UnkStruct_L D_01E901F0;
extern UnkStruct_I D_01E901FC;
extern UnkStruct_B D_01E90224;
extern UnkStruct_P D_01E97640;
extern UnkStruct_L D_01E97648;
extern UnkStruct_L D_01E97650;
extern UnkStruct_I D_01E97658;
extern UnkStruct_I D_01E97D10;
extern UnkStruct_P D_01E97DCC;
extern UnkStruct_P D_01E97F38;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_002142A0(void *, int);
extern "C" void func_003C9A60(void *);
extern "C" bool func_00433C80(void *, int);
extern "C" void func_004343E0(void *);
extern "C" void func_004343F0(void *);
extern "C" void func_00434440(void *);
extern "C" int func_00434A40(void *);
extern "C" long func_00454A60(void *);
extern "C" int func_00454D80(void *, int, int, unsigned long);
extern "C" unsigned long GetCrashStageTrackID__26CB3HardCodedCrashStageListFUl(long);

static inline void SetScene(unsigned long h)
{
    UnkStruct_003C9BF0_r * r = (UnkStruct_003C9BF0_r *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, h);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
    void * t = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_003C9BF0_s * s = D_01EA2980.field_0;
    if (s != 0) {
        D_01EA2984.field_0 = s->field_20;
        if (r != 0) {
            r->field_8 = s->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t, 0);
}

// 0x003C9BF0
extern "C" void func_003C9BF0(CB3TwoPlayerModeSelectState * self, EGtStateAction p0, void* p1, void* p2, long p3)
{
    switch (p0) {
    case 3:
        switch (p3) {
        case 0:
        default:
            func_002142A0(&D_004F50C0, 1);
            func_003C9A60(self);
            break;
        case 3:
            switch (D_01E900BC.field_0) {
            case 4:
                SetScene(0x94414032DE75847DUL);
                break;
            case 2:
            case 3:
                self->field_10 = 2;
                func_00454D80(&D_01E97F38, 1, -1, 0);
                break;
            default:
                self->field_10 = 2;
                func_00433C80(&D_01E97640, D_01E900BC.field_0);
                break;
            }
            break;
        }
        break;
    case 5:
        switch ((int)p2) {
        case 0:
            switch (self->field_10) {
            case 0:
                func_003C9A60(self);
                break;
            case 2:
                if (D_01E900BC.field_0 == 2 || D_01E900BC.field_0 == 3) {
                    long r = func_00454A60(&D_01E97F38);
                    D_01E90198.field_0 = GetCrashStageTrackID__26CB3HardCodedCrashStageListFUl(r);
                    D_01E901F0.field_0 = r;
                    D_01E900C8.field_0 = 0;
                    D_01E901FC.field_0 = 0;
                } else {
                    D_01E90198.field_0 = D_01E97648.field_0;
                    D_01E901F0.field_0 = D_01E97650.field_0;
                    D_01E900C8.field_0 = D_01E97658.field_0;
                    D_01E901FC.field_0 = 0;
                }
                D_01E900E0.field_0 = 0;
                D_01E900EC.field_0 = 9;
                D_01E900F0.field_0 = 9;
                SetScene(0x9441407ECBC88C0FUL);
                break;
            case 1:
                D_004F50C0.LockPlayerToPort(0, (signed char)p3);
                switch (D_01E97D10.field_0) {
                default:
                    D_01E900BC.field_0 = 0;
                    break;
                case 1:
                    D_01E900BC.field_0 = 1;
                    break;
                case 2:
                    D_01E900BC.field_0 = 2;
                    D_01E900D4.field_0 = 2;
                    D_01E900D8.field_0 = 1;
                    D_01E90224.field_0 = 1;
                    break;
                case 3:
                    D_01E900BC.field_0 = 3;
                    D_01E900D4.field_0 = 2;
                    D_01E900D8.field_0 = 1;
                    D_01E90224.field_0 = 1;
                    break;
                case 4:
                    D_01E900BC.field_0 = 4;
                    break;
                }
                switch (D_01E900BC.field_0) {
                case 4:
                    SetScene(0x94414032DE75847DUL);
                    break;
                case 2:
                case 3:
                    self->field_10 = 2;
                    func_00454D80(&D_01E97F38, 1, -1, 0);
                    break;
                default:
                    self->field_10 = 2;
                    func_00433C80(&D_01E97640, D_01E900BC.field_0);
                    break;
                }
                break;
            }
            break;
        case 3:
            switch (self->field_10) {
            case 0:
                func_003C9A60(self);
                break;
            case 2:
                func_003C9A60(self);
                break;
            case 1:
                SetScene(0x94413FC035B0F871UL);
                break;
            }
            break;
        case 0x1B:
            switch (self->field_10) {
            case 0:
                func_00434440(&D_01E97DCC);
            }
            break;
        case 0x19:
            switch (self->field_10) {
            case 0:
                func_004343E0(&D_01E97DCC);
            }
            break;
        case 0x1A:
            switch (self->field_10) {
            case 0:
                func_004343F0(&D_01E97DCC);
            }
            break;
        case 0x3E:
            func_00434A40(&D_01E97DCC);
            self->field_10 = 0;
            break;
        }
        break;
    }
}
