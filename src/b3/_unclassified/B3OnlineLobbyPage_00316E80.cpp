// CB3OnlineLobbyPage::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near4: explicit return labels (r10 in the 0x10 block, r13e join in blkD13) keep retail's relay branches; exact).

// near4 (from a209 archive): goto-heavy FSM, far blocks in retail address order; the 0x10 block's return is a label
// (r10) that f614's StartLeadOut arm jumps back to, and blkD13 is an if/else with a shared r13e return (retail's
// relay blocks at 0x316F28 / 0x31775C).

enum EB3MenuFlowFSMEvents {};
class CB3InputManager { public: int GetMenuConfirm(signed char); unsigned char pad_0[0x10]; };
class CB3OnScreenKeyboardComponent { public: void Show(bool, bool); unsigned char pad_0[0x10]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E898E8 { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E898F2 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E3D596 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E3D58A { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E8997C { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E32B08 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E90130 { unsigned long field_0; unsigned long pad_8; };
struct UnkStruct_D_004F509C { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E3CD44 { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual int vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94(); virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4(); virtual void vfunc_A8(); virtual void vfunc_AC(); virtual void vfunc_B0(void *); virtual void vfunc_B4(void *); virtual void vfunc_B8(void *); virtual void vfunc_BC(void *); virtual void vfunc_C0(); virtual void vfunc_C4(); virtual void vfunc_C8(); virtual void vfunc_CC(); virtual void vfunc_D0(void *, int); virtual void vfunc_D4(); virtual int vfunc_D8(); unsigned char pad_4[0xC]; };
struct UnkStruct_Lobby {
    unsigned char pad_0[0x8];
    unsigned char field_8;
    unsigned char field_9;
    unsigned char pad_A[0x2];
    float field_C;
    unsigned char pad_10[0x40];
    char field_50[0x1290];
    unsigned char field_12E0[0x10];
    unsigned int field_12F0;
    unsigned char pad_12F4[0x28];
    unsigned char field_131C[0x14];
    unsigned int field_1330;
    unsigned char pad_1334[0x6C];
    int field_13A0;
    unsigned char field_13A4;
    unsigned char field_13A5;
    unsigned char pad_13A6;
    unsigned char field_13A7;
    unsigned char field_13A8;
    unsigned char field_13A9;
    unsigned char pad_13AA[0x2];
    signed char field_13AC;
};
extern CB3InputManager D_004F50C0;
extern signed char D_004F6061[];
extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_01E90130 D_01E90130;
extern UnkStruct_D_01E3D58A D_01E3D58A;
extern UnkStruct_D_01E3D596 D_01E3D596;
extern UnkStruct_D_01E8997C D_01E8997C;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_P D_01E32AE0, D_01E33A8C, D_01E90240, D_01E7A800;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);
extern "C" void ClearAllPlayers__23CGtNetworkPlayerManagerFv(void *);
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);
extern "C" void FEBack__18CB3HUDSoundManagerFv(void *);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void func_00316640(UnkStruct_Lobby *);
extern "C" int func_00311EA0(UnkStruct_Lobby *, unsigned long, unsigned char);
extern "C" bool func_00335F40(void *);
extern "C" void func_00335E90(void *);
extern "C" void *func_002366D0(void *, int);
extern "C" int func_003392C0(void *, void *, int *);
extern "C" int func_00339380(void *, int *);
extern "C" int func_0026C950(void *, int);
extern "C" int func_0041E8A0(void *);
extern "C" int func_0041E8B0(void *);
extern "C" void func_0041E9A0(void *);
extern "C" int func_002351C0(void *);
extern "C" void func_00284E50(void *);
extern "C" void func_00284ED0(void *);
extern "C" void func_00315560(UnkStruct_Lobby *);
extern "C" void func_00315170(UnkStruct_Lobby *);
extern "C" void func_00314E50(UnkStruct_Lobby *);
extern "C" void func_00314CC0(UnkStruct_Lobby *);
extern "C" void func_00315CE0(UnkStruct_Lobby *);
extern "C" void func_00312420(UnkStruct_Lobby *);
extern "C" void func_00312A60(UnkStruct_Lobby *);
extern "C" void HandleError__18CB3OnlineLobbyPageFi(UnkStruct_Lobby *, int);
extern "C" void BuildGameOptionsText__18CB3OnlineLobbyPageFv(UnkStruct_Lobby *);
extern "C" void UpdateVoIP__18CB3OnlineLobbyPageFv(UnkStruct_Lobby *);
extern "C" void UpdateLatency__18CB3OnlineLobbyPageFv(UnkStruct_Lobby *);
extern "C" void UpdateNATData__18CB3OnlineLobbyPageFv(UnkStruct_Lobby *);
extern "C" void UpdateLaunchGame__18CB3OnlineLobbyPageFv(UnkStruct_Lobby *);
extern "C" void UpdateKeyboard__18CB3OnlineLobbyPageFv(UnkStruct_Lobby *);
extern "C" void UpdateConfirmLeave__18CB3OnlineLobbyPageFv(UnkStruct_Lobby *);

extern "C" void Update__18CB3OnlineLobbyPageFv(UnkStruct_Lobby *self)
{
    char *ctrl = (char *)&D_004F50C0 + D_004F6061[0] * 0x12C + 0xD48;
    if (D_01E90424.field_0 != 5) return;
    self->field_C = self->field_C + D_004F509C.field_0;
    if (self->field_13AC == 0x10) {
        int host = AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0;
        if (func_0032B2C0(&D_01E898E8, 0, host ^ 1) == 0) goto f614;
    r10:
        return;
    }
    switch (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0)) {
    case 1:
        HandleError__18CB3OnlineLobbyPageFi(self, ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58());
        break;
    case 2: {
            int st = self->field_13AC;
            if (st == 0xC) goto blkC12;
            if (st == 0xD) goto blkD13;
            if (st == 0xE) {
                if (D_01E898F2.field_0 != 0) goto eVC;
            eChk:
                if (self->field_13A8 != 0) goto eA8;
                if (self->field_13A9 == 0) goto eReset;
                self->field_13AC = 2;
            ret1:
                return;
            }
            if (self->field_8 == 0) goto blkA;
        chkB:
            if (self->field_8 != 0) goto blkB;
            if (D_01E3D596.field_0 != 0) goto blkC;
            if (self->field_13A8 == 0) goto top;
            if (self->field_9 != 0) goto blk9;
        blkD:
            self->field_13A8 = 0;
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B0(self->field_131C);
            self->field_13AC = 0xD;
            if (D_01E898F2.field_0 != 0) ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 0, 0x3B3, 0xF, 0);
            self->field_13A0 = 0x4E;
        }
        break;
    case 0:
        break;
    }
top:
    if (self->field_13AC != 0xA) {
        if (D_01E898F2.field_0 == 0) {
            if (self->field_13A7 != 0) goto blkX;
        chkX:
            if (self->field_13A7 == 0) {
                if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) {
                    self->field_13A7 = 1;
                    func_00316640(self);
                }
            }
        }
    afterX:
        if (self->field_13AC != 0xF && GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0) == 2 && func_00311EA0(self, D_01E90130.field_0, D_01E3D58A.field_0) == 0) {
            self->field_13AC = 0xF;
            if (D_01E898F2.field_0 != 0) ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, 0x3B5, 0, 0);
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B8(self->field_131C);
            self->field_1330 &= ~1;
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B0(self->field_131C);
        }
        BuildGameOptionsText__18CB3OnlineLobbyPageFv(self);
        func_00312420(self);
        UpdateVoIP__18CB3OnlineLobbyPageFv(self);
        func_00312A60(self);
        UpdateLatency__18CB3OnlineLobbyPageFv(self);
        UpdateNATData__18CB3OnlineLobbyPageFv(self);
        if (self->field_13AC != 0xB && self->field_13AC != 0xF && self->field_13AC != 0x11) {
            UpdateLaunchGame__18CB3OnlineLobbyPageFv(self);
        }
    }
    switch (self->field_13AC) {
    case 17:
        if (func_00335F40(&D_01E3CD44)) {
            if (self->field_13A5 != 0 && self->field_13A4 != 0 && D_01E32B08.field_0 > 1) {
                ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_6C();
                self->field_13AC = 0xB;
            } else {
                goto blk17;
            }
        }
        break;
    case 11:
        if (func_0041E8A0(&D_01E33A8C) != 0 || func_0041E8B0(&D_01E33A8C) != 0) {
            func_0041E9A0(&D_01E33A8C);
        }
        if (self->field_13A4 != 0) {
            if (func_002351C0(&D_01E32AE0) != 0) {
                if (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0) == 2) {
                    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
                    func_00284E50(&D_01E7A800);
                }
            }
        }
        break;
    case 10:
        switch (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0)) {
        case 2:
            ClearAllPlayers__23CGtNetworkPlayerManagerFv(&D_01E32AE0);
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x1D, 0);
            func_00284ED0(&D_01E7A800);
            break;
        case 1:
            return;
        case 0:
            return;
        }
        break;
    case 9:
        UpdateConfirmLeave__18CB3OnlineLobbyPageFv(self);
        break;
    case 15:
        if (func_0032B2C0(&D_01E898E8, 0, (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) ^ 1) == 0) {
            if (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0) == 2) {
                ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x1E, 0);
                FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            }
        }
        break;
    case 0:
        func_00315560(self);
        break;
    case 1:
        func_00315170(self);
        break;
    case 3:
        func_00314E50(self);
        break;
    case 4:
        if (D_01E8997C.field_0 == 2 && D_004F50C0.GetMenuConfirm(0)) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_00316640(self);
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
        }
        break;
    case 5:
        UpdateKeyboard__18CB3OnlineLobbyPageFv(self);
        if (*(short *)(ctrl + 0x5C) != 0) {
            if (self->field_13AC == 2) goto blk5;
            if (self->field_13AC == 5) {
                self->field_13AC = 3;
                D_01E899C0.Show(0, 1);
            }
        }
        break;
    case 6:
        if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_00315CE0(self);
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
        }
        break;
    case 7:
        func_00314CC0(self);
        break;
    case 8: {
            int r = func_0032B2C0(&D_01E898E8, 0, (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) ^ 1);
            if (r == 4) goto blk8;
            if (r == 5) {
                ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                self->field_13AC = 3;
                FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
            }
            break;
        }
    case 2:
        UpdateKeyboard__18CB3OnlineLobbyPageFv(self);
        break;
    case 12: case 13: case 14: case 16:
    default:
        break;
    }
brk:
    return;
f614:
    FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    if (((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_D8()) {
        func_00316640(self);
        return;
    }
    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x1D, 0);
    goto r10;
blkC12:
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B8(self->field_131C);
    self->field_1330 |= 1;
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B0(self->field_131C);
    if (D_01E898F2.field_0 != 0) ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    self->field_13AC = 0xD;
    func_0032D080(&D_01E898E8, 0, 0x3B3, 0xF, 0);
    self->field_13A0 = 0x4E;
    return;
blkD13:
    if (D_01E898F2.field_0 != 0) ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    if (self->field_13A0 == 0x4E) goto r13;
    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)*(const int *)&self->field_13A0, 0);
    goto r13e;
r13:
    func_00316640(self);
r13e:
    return;
eVC:
    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    goto eChk;
eA8:
    self->field_13A8 = 0;
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B0(self->field_131C);
    self->field_13AC = 0xD;
    if (D_01E898F2.field_0 != 0) ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    func_0032D080(&D_01E898E8, 0, 0x3B3, 0xF, 0);
    self->field_13A0 = 0x4E;
    goto ret1;
eReset:
    func_00316640(self);
    goto ret1;
blkA:
    if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0 && func_00335F40(&D_01E3CD44) && self->field_13AC != 0x11) {
        func_00335E90(&D_01E3CD44);
        self->field_13AC = 0xC;
        if (D_01E898F2.field_0 != 0) ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        func_0032D080(&D_01E898E8, 0, 0x3B2, 0xF, 0);
        goto top;
    }
    goto chkB;
blkB:
    self->field_8 = 0;
    if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) {
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B4(self->field_12E0);
        self->field_13AC = 0xC;
        if (D_01E898F2.field_0 != 0) ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        func_0032D080(&D_01E898E8, 0, 0x3B2, 0xF, 0);
    }
    goto top;
blkC:
    D_01E3D596.field_0 = 0;
    if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) {
        int i;
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_BC(self->field_12E0);
        int v;
        unsigned int sum = 0;
        for (i = 0; i < D_01E32B08.field_0; i++) {
            void *p = func_002366D0(&D_01E32AE0, i);
            if (p != 0) {
                if (func_003392C0(&D_01E3CD44, (char *)p + 0x4B8, &v) == 0) v = 0;
            } else {
                func_00339380(&D_01E3CD44, &v);
            }
            sum += v;
        }
        unsigned int avg = sum / D_01E32B08.field_0;
        if (avg != self->field_12F0) {
            self->field_12F0 = avg;
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B4(self->field_12E0);
            self->field_13A9 = self->field_13AC == 2;
            self->field_13AC = 0xE;
            if (D_01E898F2.field_0 != 0) ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 0, 0x3B2, 0xF, 0);
        }
    }
    goto top;
blk9:
    self->field_9 = 0;
    if (func_0026C950(&D_01E32AE0, -1) != 0) self->field_1330 |= 2;
    goto blkD;
blkX:
    if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) goto chkX;
    self->field_13A7 = 0;
    func_00316640(self);
    goto afterX;
blk17:
    self->field_13AC = 0xC;
    goto brk;
blk5:
    D_01E899C0.Show(0, 1);
    func_00316640(self);
    goto brk;
blk8:
    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_D0(self->field_50, 0);
    func_00316640(self);
    FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
    goto brk;
}
