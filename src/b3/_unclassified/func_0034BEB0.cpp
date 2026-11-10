// Hand-written; the lifter refused it ([L] DNAT CB3OnlineLoginToLobbyPage::Update; jtbl FSM, switch(r) case-order, inl2(bool first), noVoip label inside status switch).

enum EB3MenuFlowFSMEvents {};
enum SLoginProcessE {};
class CB3SFIOCallbacks {
public:
    static int SharedNetworkLoginUpdate(SLoginProcessE*);
    static int SharedNetworkLoginCreatePrepare(char *, char *, void *);
    static void SharedNetworkLoginSavePrepare(char *, char *);
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E898E8 { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E8D4B0 { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E898F2 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E3CD44 { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual int vfunc_58(); unsigned char pad_4[0xC]; };
struct UnkStruct_Login {
    unsigned char pad_0[0x48];
    char *field_48;
    char *field_4C;
    unsigned char field_50;
    signed char field_51;
};
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E8D4B0 D_01E8D4B0;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_P D_01E32AE0, D_01E33A8C, D_01E90240, D_005185A0, D_0051BA44, D_01E89788, D_004EE040;
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);
extern "C" int GetErrorString__17CB3NetworkManagerFi(void *, int);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_0032CC00(void *, int, int, int, int, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, void *, bool, bool, float);
extern "C" int Prepare__21CB3NetworkVoIPManagerFv(void *);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" int func_003615B0();
extern "C" int func_0030A8C0(void *);
extern "C" int Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(void *, int, int *);
extern "C" void Format__16CMemoryDevicePS2Fv(void *);

static inline void func_0034BEB0_inl1(UnkStruct_Login *self, int k)
{
    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    int s2 = func_00271A00(&D_0051BA44, 0xC0E);
    int s1 = func_00271A00(&D_0051BA44, 0x1C2);
    func_0032CC00(&D_01E898E8, 9, func_00271A00(&D_0051BA44, k), s1, s2, 0xD, 0);
    self->field_51 = 5;
}

static inline void func_0034BEB0_inl2(UnkStruct_Login *self, SLoginProcessE &e, bool first)
{
    int s1 = CB3SFIOCallbacks::SharedNetworkLoginUpdate(&e);
    if (s1 == 0) {
        if ((int)e == 2) {
            func_003615B0();
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x13, 0);
        }
        return;
    }
    func_003615B0();
    if (s1 == 1) {
        func_0034BEB0_inl1(self, 0xAC);
    } else if (s1 == 4) {
        if (first) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 7, 0x438, 5, 0);
            self->field_51 = 3;
        } else {
            func_0034BEB0_inl1(self, 0xAC);
        }
    } else if (s1 == 3) {
        func_0034BEB0_inl1(self, 0x7E);
    } else if (s1 == 2) {
        switch (func_0030A8C0(&D_005185A0)) {
        case 3:
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 7, 0x7D, 5, 0);
            self->field_51 = 4;
            break;
        case 1:
            func_0034BEB0_inl1(self, 0x7C);
            break;
        default:
            func_0034BEB0_inl1(self, 0xAC);
            break;
        }
    } else {
        func_0034BEB0_inl1(self, 0xAC);
    }
}

// 0x0034BEB0
extern "C" void func_0034BEB0(UnkStruct_Login *self)
{
    SLoginProcessE e1; SLoginProcessE e2; int ms4; int ms6;
    if (D_01E90424.field_0 != 5) return;
    switch (self->field_51) {
    case 0:
        switch (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0)) {
        case 0:
            return;
        case 2:
            if (self->field_50 == 0) goto noVoip;
            if (D_01E898F2.field_0 == 0) {
                ((UnkStruct_D_01E8D4B0 *)&D_01E8D4B0)->vfunc_C();
                func_0032D080(&D_01E898E8, 7, 0x7A, 4, 0);
                break;
            }
            {
                switch (func_0032B2C0(&D_01E898E8, 0, 1)) {
                case 4:
                    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                    self->field_51 = 1;
                    CB3SFIOCallbacks::SharedNetworkLoginCreatePrepare(self->field_48, self->field_4C, &D_004EE040);
                    SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (void *)(func_00271A00(&D_0051BA44, 0x43B)), 0, 0, 80.0f);
                    func_0032D080(&D_01E898E8, 1, 0xAB, 0xF, 0);
                    Prepare__21CB3NetworkVoIPManagerFv(&D_01E33A8C);
                    break;
                case 5:
                    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                    Prepare__21CB3NetworkVoIPManagerFv(&D_01E33A8C);
                    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x13, 0);
                    break;
                }
            }
            break;
        case 1: {
            int e = ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58();
            if (e != 0) {
            self->field_51 = 7;
            ((UnkStruct_D_01E8D4B0 *)&D_01E8D4B0)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, GetErrorString__17CB3NetworkManagerFi(&D_01E32AE0, e), 0, 0);
            }
            break;
        }
        noVoip:
            Prepare__21CB3NetworkVoIPManagerFv(&D_01E33A8C);
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x13, 0);
        }
        break;
    case 1:
        func_0034BEB0_inl2(self, e1, true);
        break;
    case 2:
        func_0034BEB0_inl2(self, e2, false);
        break;
    case 3: {
        switch (func_0032B2C0(&D_01E898E8, 0, 1)) {
        case 4:
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            self->field_51 = 2;
            CB3SFIOCallbacks::SharedNetworkLoginSavePrepare(self->field_48, self->field_4C);
            func_0032D080(&D_01E898E8, 1, 0xAB, 0xF, 0);
            break;
        case 5:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x13, 0);
            break;
        }
        break;
    }
    case 4: {
        int r = Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(&D_005185A0, 0, &ms4);
        if (r == 0xD) {
            switch (func_0030A8C0(&D_005185A0)) {
            case 1:
                func_0034BEB0_inl1(self, 0x7C);
                return;
            }
        }
        switch (func_0032B2C0(&D_01E898E8, 0, 1)) {
        case 4:
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            self->field_51 = 6;
            Format__16CMemoryDevicePS2Fv(&D_005185A0);
            func_0032D080(&D_01E898E8, 1, 0xAF, 0xF, 0);
            break;
        case 5:
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 7, 0x7A, 4, 0);
            self->field_51 = 0;
            break;
        }
        break;
    }
    case 5: {
        switch (func_0032B2C0(&D_01E898E8, 0, 1)) {
        case 0xE:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x13, 0);
            break;
        case 0xD:
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            self->field_51 = 1;
            CB3SFIOCallbacks::SharedNetworkLoginCreatePrepare(self->field_48, self->field_4C, &D_004EE040);
            func_0032D080(&D_01E898E8, 1, 0xAB, 0xF, 0);
            break;
        }
        break;
    }
    case 6: {
        switch (Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(&D_005185A0, 0, &ms6)) {
        case 0:
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            self->field_51 = 1;
            CB3SFIOCallbacks::SharedNetworkLoginCreatePrepare(self->field_48, self->field_4C, &D_004EE040);
            func_0032D080(&D_01E898E8, 1, 0xAB, 0xF, 0);
            break;
        case 0xD:
            func_0034BEB0_inl1(self, 0xB0);
            break;
        }
        break;
    }
    case 7:
        switch (func_0032B2C0(&D_01E898E8, 0, 1)) {
        case 0:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x17, 0);
            break;
        }
        break;
    default:
        break;
    }
}
