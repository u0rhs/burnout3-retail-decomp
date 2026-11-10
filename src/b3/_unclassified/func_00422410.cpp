// Hand-written; the lifter refused it (exact; switch jump table retargeted at retail's (tools/jtbl_retarget.py)).

// func_00422410 -- CB3MCSlaveSavingState::Action(EGtStateAction,void*,void*,void*)
// [L] DNAT: CB3MCSlaveSavingState::Action(EGtStateAction,void*,void*,void*) (research/proto/new_names.csv, medium)

enum EGtStateAction {};
enum EMemDevPollOrWait {};

struct UnkStruct_D_01EB5D00 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_E {
    unsigned char pad_0[0x4];
    const char * field_4;
    unsigned int field_8;
    unsigned char pad_C[0x4];
};
struct UnkStruct_Pp { UnkStruct_E * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_Pu { UnkStruct_E * field_0; unsigned char pad_4[0xC]; };

class CB3MCSlaveSavingState {
public:
    unsigned char pad_0[0x10];
    int field_10;
    int field_14;
};

extern UnkStruct_P D_005185A0;
extern UnkStruct_P D_01ECD520;
extern UnkStruct_I D_01ECD524;
extern UnkStruct_P D_01ECD52C;
extern UnkStruct_P D_01ECD56C;
extern UnkStruct_Pp D_01ECD580;
extern UnkStruct_Pu D_01ECD57C;
extern UnkStruct_D_01EB5D00 D_01EB5D00;

extern "C" int Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(void *, EMemDevPollOrWait, int *);
extern "C" int OpenFile__16CMemoryDevicePS2FPCcUiUi(void *, const char *, unsigned int, unsigned int);
extern "C" int Write__16CMemoryDevicePS2FPCcUiUi(void *, const char *, unsigned int, unsigned int);
extern "C" int CloseFile__16CMemoryDevicePS2Fv(void *);
extern "C" int MkDir__16CMemoryDevicePS2FPCc(void *, const char *);
extern "C" const char * GetFullFilename__19CMemoryCardFileBaseFv(void *);
extern "C" int func_0030A8C0(void *);
extern "C" void func_00420B60(void *);
extern "C" void func_00420FD0(void *, int);

#define NOTIFY(a) ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14((a), 0)

// 0x00422410
extern "C" void func_00422410(CB3MCSlaveSavingState * self, EGtStateAction p0, void * p1, void * p2, int p3)
{
    int res;
    switch (p0) {
    case 0:
        break;
    case 3:
        self->field_10 = p3;
        func_00420B60(&D_01ECD520);
        self->field_14 = 0;
        break;
    case 4:
        switch (self->field_14) {
        case 0:
            {
                int r = Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(&D_005185A0, (EMemDevPollOrWait)0, &res);
                if (r == 0) {
                    if (self->field_10 != 0) {
                        if (MkDir__16CMemoryDevicePS2FPCc(&D_005185A0, GetFullFilename__19CMemoryCardFileBaseFv(&D_01ECD52C)) != 0) {
                            self->field_14 = 4;
                        } else {
                            NOTIFY(0xA);
                            self->field_14 = 5;
                        }
                    } else {
                        if (OpenFile__16CMemoryDevicePS2FPCcUiUi(&D_005185A0, GetFullFilename__19CMemoryCardFileBaseFv(&D_01ECD56C), 2, 0) != 0) {
                            self->field_14 = 1;
                        } else {
                            NOTIFY(0xA);
                            self->field_14 = 5;
                        }
                    }
                } else if (r == 0xD) {
                    switch (func_0030A8C0(&D_005185A0)) {
                    case 3:
                        NOTIFY(0xB);
                        break;
                    default:
                        NOTIFY(0xA);
                        break;
                    }
                    self->field_14 = 5;
                } else {
                    return;
                }
            }
            break;
        case 4:
            {
                int r = Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(&D_005185A0, (EMemDevPollOrWait)0, &res);
                if (r == 0xA) {
                    break;
                }
                if (r == 0xD) {
                    NOTIFY(0xA);
                    self->field_14 = 5;
                    break;
                }
                if (r != 0) {
                    break;
                }
                D_01ECD580.field_0 = D_01ECD580.field_0 + 1;
                if (OpenFile__16CMemoryDevicePS2FPCcUiUi(&D_005185A0, GetFullFilename__19CMemoryCardFileBaseFv(D_01ECD580.field_0), 6, 0) != 0) {
                    self->field_14 = 1;
                } else {
                    NOTIFY(0xA);
                    self->field_14 = 5;
                }
            }
            break;
        case 1:
            {
                int r = Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(&D_005185A0, (EMemDevPollOrWait)0, &res);
                if (r == 4) {
                    break;
                }
                if (r == 0xD) {
                    NOTIFY(0xA);
                    self->field_14 = 5;
                    break;
                }
                if (r != 0) {
                    break;
                }
                if (Write__16CMemoryDevicePS2FPCcUiUi(&D_005185A0, D_01ECD580.field_0->field_4, D_01ECD580.field_0->field_8, 0) != 0) {
                    self->field_14 = 2;
                } else {
                    NOTIFY(0xA);
                    self->field_14 = 5;
                }
            }
            break;
        case 2:
            {
                int r = Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(&D_005185A0, (EMemDevPollOrWait)0, &res);
                if (r == 8) {
                    break;
                }
                if (r == 0xD) {
                    NOTIFY(0xA);
                    self->field_14 = 5;
                    break;
                }
                if (r != 0) {
                    break;
                }
                if (CloseFile__16CMemoryDevicePS2Fv(&D_005185A0) != 0) {
                    self->field_14 = 3;
                } else {
                    NOTIFY(0xA);
                    self->field_14 = 5;
                }
            }
            break;
        case 3:
            {
                int r = Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(&D_005185A0, (EMemDevPollOrWait)0, &res);
                if (r == 5) {
                    break;
                }
                if (r == 0xD) {
                    NOTIFY(0xA);
                    self->field_14 = 5;
                    break;
                }
                if (r != 0) {
                    break;
                }
                D_01ECD580.field_0 = D_01ECD580.field_0 + 1;
                if (D_01ECD580.field_0 >= D_01ECD57C.field_0) {
                    func_00420FD0(&D_01ECD520, D_01ECD524.field_0);
                    *(int *)&D_01ECD520 = D_01ECD524.field_0;
                    NOTIFY(0xC);
                    self->field_14 = 6;
                } else {
                    if (OpenFile__16CMemoryDevicePS2FPCcUiUi(&D_005185A0, GetFullFilename__19CMemoryCardFileBaseFv(D_01ECD580.field_0), 6, 0) != 0) {
                        self->field_14 = 1;
                    } else {
                        NOTIFY(0xA);
                        self->field_14 = 5;
                    }
                }
            }
            break;
        case 5:
        case 6:
            break;
        }
        break;
    case 5:
        break;
    case 2:
        break;
    }
}
