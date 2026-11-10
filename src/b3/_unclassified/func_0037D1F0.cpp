// Hand-written; the lifter refused it (draftZ: login create/save page Update FSM, twin of func_0034BEB0 (inl1 error popup, inl2 login update with first flag, inl3 prompt bar by field_19); 'return' after the confirm if/else gives retail's separate join block).

// func_0037D1F0 -- menu page Update() state machine (login create/save flow); hand-written (draftZ) from the retail
// asm, shaped on the matched twin func_0034BEB0 ([L] CB3OnlineLoginToLobbyPage::Update). DNAT row (low):
// CB3OnlineDupNameMenuPage::Update() -- not adopted (its Prepare func_0037CF00 uses a different field layout).
// Field names are placeholders; every type is [G] (instruction widths).
enum EB3MenuFlowFSMEvents {};
enum SLoginProcessE {};
class CB3SFIOCallbacks {
public:
    static int SharedNetworkLoginUpdate(SLoginProcessE*);
    static int SharedNetworkLoginCreatePrepare(char *, char *, void *);
    static void SharedNetworkLoginSavePrepare(char *, char *);
};
class CB3InputManager {
public:
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);
    int GetMenuConfirm(signed char);
    unsigned char pad_0[0x10];
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E898E8 { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E898F2 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004C9288 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0037D1F0 {
    unsigned char pad_0[0x4];
    int field_4[4];
    unsigned short field_14;
    unsigned char pad_16[0x2];
    unsigned char field_18;
    unsigned char field_19;
};
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8, D_01E8D4B0, D_01E8970C;
extern CB3InputManager D_004F50C0;
extern UnkStruct_P D_01E90240, D_005185A0, D_0051BA44, D_004EE040;
extern UnkStruct_P D_004C9268, D_004C9270, D_004C9278, D_004C9280;
extern UnkStruct_D_004C9288 D_004C9288;
extern char D_01EA3084[0x20];
extern char D_01EA30A4[0x20];
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_0032CC00(void *, int, int, int, int, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" int func_003615B0();
extern "C" int func_0030A8C0(void *);
extern "C" int Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(void *, int, int *);
extern "C" void Format__16CMemoryDevicePS2Fv(void *);
extern "C" bool func_00351F00(void *, void *, void *, void *, void *, void *, int, int, int, int, int, float, float);
extern "C" int func_0039BCD0(void *, void *, void *, int, int, float);

static inline void func_0037D1F0_inl1(UnkStruct_0037D1F0 *self, int k)
{
    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    int s2 = func_00271A00(&D_0051BA44, 0xC0E);
    int s1 = func_00271A00(&D_0051BA44, 0x1C2);
    func_0032CC00(&D_01E898E8, 9, func_00271A00(&D_0051BA44, k), s1, s2, 0xD, 0);
    self->field_18 = 6;
}

static inline void func_0037D1F0_inl3(UnkStruct_0037D1F0 *self)
{
    if (self->field_19) {
        func_00351F00(&D_01E8D4B0, &D_004C9268, &D_004C9270, &D_004C9278, &D_004C9280, &D_004C9288, 0x83, 3, 1, 3, 0, 32.0f, D_004C9288.field_0);
    } else {
        func_00351F00(&D_01E8D4B0, &D_004C9268, &D_004C9270, &D_004C9278, &D_004C9280, &D_004C9288, 0x412, 3, 1, 3, 0, 32.0f, D_004C9288.field_0);
    }
}

static inline void func_0037D1F0_inl2(UnkStruct_0037D1F0 *self, SLoginProcessE &e, bool first)
{
    int s1 = CB3SFIOCallbacks::SharedNetworkLoginUpdate(&e);
    if (s1 == 0) {
        if ((int)e == 2) {
            func_003615B0();
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        }
        return;
    }
    func_003615B0();
    if (s1 == 1) {
        func_0037D1F0_inl1(self, 0xAC);
    } else if (s1 == 4) {
        if (first) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 7, 0x438, 5, 0);
            self->field_18 = 4;
        } else {
            func_0037D1F0_inl1(self, 0xAC);
        }
    } else if (s1 == 3) {
        func_0037D1F0_inl1(self, 0x7E);
    } else if (s1 == 2) {
        switch (func_0030A8C0(&D_005185A0)) {
        case 3:
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 7, 0x7D, 5, 0);
            self->field_18 = 5;
            break;
        case 1:
            func_0037D1F0_inl1(self, 0x7C);
            break;
        default:
            func_0037D1F0_inl1(self, 0xAC);
            break;
        }
    } else {
        func_0037D1F0_inl1(self, 0xAC);
    }
}

// 0x0037D1F0
extern "C" void func_0037D1F0(UnkStruct_0037D1F0 *self)
{
    SLoginProcessE e1; SLoginProcessE e2; int ms5; int ms7;
    if (D_01E90424.field_0 != 5) return;
    switch (self->field_18) {
    case 0:
        if ((D_004F50C0.GetMenuUp(0) && func_00319360(&self->field_14)) || (D_004F50C0.GetMenuDown(0) && func_00319330(&self->field_14))) {
            ((UnkStruct_D_01E898E8 *)&D_01E8D4B0)->vfunc_C();
            func_0037D1F0_inl3(self);
            return;
        }
        if (D_004F50C0.GetMenuConfirm(0)) {
            if (self->field_14 == 0) {
                ((UnkStruct_D_01E898E8 *)&D_01E8970C)->vfunc_C();
                ((UnkStruct_D_01E898E8 *)&D_01E8D4B0)->vfunc_C();
                if (CB3SFIOCallbacks::SharedNetworkLoginCreatePrepare(D_01EA3084, D_01EA30A4, &D_004EE040)) {
                    func_0037D1F0_inl1(self, 0xAC);
                } else {
                    func_0032D080(&D_01E898E8, 1, 0xAB, 0xF, 0);
                    self->field_18 = 1;
                }
            } else {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
            }
            return;
        }
        break;
    case 1:
        func_0037D1F0_inl2(self, e1, true);
        break;
    case 2:
        func_0037D1F0_inl2(self, e2, false);
        break;
    case 3:
        if (D_01E898F2.field_0 != 0) {
            if (func_0032B2C0(&D_01E898E8, 0, 1) == 0)
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        }
        break;
    case 4:
        switch (func_0032B2C0(&D_01E898E8, 0, 1)) {
        case 4:
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            self->field_18 = 2;
            CB3SFIOCallbacks::SharedNetworkLoginSavePrepare(D_01EA3084, D_01EA30A4);
            func_0032D080(&D_01E898E8, 1, 0xAB, 0xF, 0);
            break;
        case 5:
            func_0037D1F0_inl3(self);
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0039BCD0(&D_01E8970C, &self->field_14, self->field_4, 3, 0, 516.0f);
            self->field_18 = 0;
            break;
        }
        break;
    case 5: {
        int r = Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(&D_005185A0, 0, &ms5);
        if (r == 0xD) {
            switch (func_0030A8C0(&D_005185A0)) {
            case 1:
                func_0037D1F0_inl1(self, 0x7C);
                return;
            }
        }
        switch (func_0032B2C0(&D_01E898E8, 0, 1)) {
        case 4:
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            self->field_18 = 7;
            Format__16CMemoryDevicePS2Fv(&D_005185A0);
            func_0032D080(&D_01E898E8, 1, 0xAF, 0xF, 0);
            break;
        case 5:
            func_0037D1F0_inl3(self);
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0039BCD0(&D_01E8970C, &self->field_14, self->field_4, 3, 0, 516.0f);
            self->field_18 = 0;
            break;
        }
        break;
    }
    case 6:
        switch (func_0032B2C0(&D_01E898E8, 0, 1)) {
        case 0xD:
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            self->field_18 = 1;
            CB3SFIOCallbacks::SharedNetworkLoginCreatePrepare(D_01EA3084, D_01EA30A4, &D_004EE040);
            func_0032D080(&D_01E898E8, 1, 0xAB, 0xF, 0);
            break;
        case 0xE:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
            break;
        }
        break;
    case 7:
        switch (Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(&D_005185A0, 0, &ms7)) {
        case 0:
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 1, 0xAB, 0xF, 0);
            CB3SFIOCallbacks::SharedNetworkLoginCreatePrepare(D_01EA3084, D_01EA30A4, &D_004EE040);
            self->field_18 = 1;
            break;
        case 0xD:
            func_0037D1F0_inl1(self, 0xB0);
            break;
        }
        break;
    default:
        break;
    }
}
