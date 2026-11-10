// Hand-written; the lifter refused it (gif5 rule G; jtbl_retarget now defines the unlabelled retail table (gif6)).

// L255: logic, block layout, frame and jtbl exact; 14 changed in one block (field_10==2, events 0-2): retail loads D_01E99794 (c2B8.lo, sp+0x2B8) right after D_01E99784 and before 77C/790; ours loads it after 790. Tried 48 union-write/declaration orders. Next: inline id-builder helper or reading 794/798 through separate globals.

// func_0030F620 -- online lobby FSM state Action handler [G]; sibling of the matched
// HandleInLobbyEvents/HandleSelectCarEvents (B3OnlineLobbyState_0030F010.cpp); SetScene inline as
// B3OnlineMenuState_00323E30.cpp; presence tail as B3OnlineGameCreatePage_00326FC0.cpp.
// [L] DNAT: CB3OnlineLobbyState::Action(EGtStateAction,void*,void*,void*) (research/proto/new_names.csv, medium).

enum EB3MenuFlowFSMEvents {};

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

// lobby/game info record filled by vfunc_BC (0x3C bytes) [G]
struct UnkStruct_0030F620_info {
    unsigned short * field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
};
struct UnkStruct_0030F620_box { UnkStruct_0030F620_info field_0; unsigned char pad_3C[0x4]; };
union UnkStruct_0030F620_id { unsigned long l; struct { int lo; int hi; } s; };

struct UnkStruct_D_01E3CD44 {
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
    virtual int vfunc_70();
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
    virtual int vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8(void *);
    virtual void vfunc_BC(UnkStruct_0030F620_box *);
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual int vfunc_D8();
    unsigned char pad_4[0xC];
};

class CB3OnlineLobbyState {
public:
    void HandleInLobbyEvents(EB3MenuFlowFSMEvents p0);
    void HandleSelectCarEvents(EB3MenuFlowFSMEvents p0);

    unsigned char pad_0[0x10];
    signed char field_10;
};

struct UnkStruct_D_01E99770 { UnkStruct_0030F620_info field_0; unsigned char pad_3C[0x4]; };

extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_I D_01E32B08;
extern UnkStruct_P D_01E7A800;
extern UnkStruct_P D_01E32AE0;
extern UnkStruct_P D_01E3D390;
extern UnkStruct_P D_01E98490;
extern UnkStruct_P D_01E997AC;
extern UnkStruct_I D_01E997C0;
extern UnkStruct_UB D_01E99838;
extern UnkStruct_UB D_01E98498;
extern UnkStruct_UB D_01E98499;
extern UnkStruct_L D_01E90130;
extern UnkStruct_L D_01E90198;
extern UnkStruct_L D_01E901F0;
extern UnkStruct_I D_01E900C0;
extern UnkStruct_I D_01E90430;
extern UnkStruct_P D_01E90240;
extern UnkStruct_P D_01E95B4C;
extern UnkStruct_P D_0051BA44;
extern UnkStruct_P D_01EA0070;
extern UnkStruct_UB D_01EA0771;
extern UnkStruct_UB D_01EA0772;
extern UnkStruct_I D_01E99824;
extern UnkStruct_I D_01E99828;
extern UnkStruct_D_01E99770 D_01E99770;
extern char * D_004D1B70[];
extern int D_004E2918;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void FEOnlineUpdatePlayersInGame__18CB3HUDSoundManagerFi(void *, int);
extern "C" void Prepare__18CB3OnlineLobbyPageFPc(void *, unsigned short *);
extern "C" unsigned short * func_00271A00(void *, int);
extern "C" void func_00310180(unsigned short *dst, const unsigned short *fmt, unsigned short *const &arg);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(const unsigned short *, char *, int);
extern "C" void SetPresenceDetail__10CGtBuddiesFPcPcPc(void *, char *, char *, char *);
extern "C" int SetPresence__22CGtBuddiesPS2DirtySockF16EGtBuddyPresenceb(void *, int, bool);
extern "C" void PrepareForGameStart__17CB3NetworkManagerFv(void *);
extern "C" void ClearAllPlayers__23CGtNetworkPlayerManagerFv(void *);
extern "C" void ReleaseCurrentMenu__18CB3MenuPageManagerFv(void *);
extern "C" void func_00284ED0(void *);
extern "C" void Prepare__12CB3ErrorPageF14EGlobalStrings14EGlobalStrings17EB3MessageBoxType(void *, int, int, int);
extern "C" unsigned long func_0039EF40(void *);
extern "C" unsigned long func_0039EDB0(void *, int);
extern "C" unsigned long func_0039EC90(void *);
extern "C" int func_003EAA60(void *);
extern "C" int FindTrack__21CB3HardCodedTrackListFUl(unsigned long);
extern "C" unsigned long GetCrashStageTrackID__26CB3HardCodedCrashStageListFUl(unsigned long);
extern "C" void func_0030ED90(void *);

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

static inline unsigned long func_0030F620_inl1(const int *p)  // [G]
{
    UnkStruct_0030F620_id u;
    u.s.lo = p[0];
    u.s.hi = p[1];
    return u.l;
}
// 0x0030F620
extern "C" void func_0030F620(CB3OnlineLobbyState * self, int action, void * p1, void * p2, int p3)
{
    unsigned short ubuf[100];
    char name[100];
    char status[100];
    UnkStruct_0030F620_box info;
    UnkStruct_0030F620_box info2;
    UnkStruct_0030F620_box info3;
    UnkStruct_0030F620_id r300;
    UnkStruct_0030F620_id r2F8;
    UnkStruct_0030F620_id r2F0;
    UnkStruct_0030F620_id r2E8;
    UnkStruct_0030F620_id c2E0;
    UnkStruct_0030F620_id c2D8;
    UnkStruct_0030F620_id a2D0;
    UnkStruct_0030F620_id a2C8;
    UnkStruct_0030F620_id c2C0;
    UnkStruct_0030F620_id c2B8;
    unsigned long prev;
    int kind;

    switch (action) {
    case 2:
        return;
    case 3:
        FEOnlineUpdatePlayersInGame__18CB3HUDSoundManagerFi(&D_01E7A800, D_01E32B08.field_0);
        if (((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_D8() == 0) goto notconn;
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_BC(&info);
        prev = *(unsigned long *)p2;
        if (prev == 0x94413FA737AAA797UL || p3 != 0) goto rejoin;
        if (prev != 0x94413E2F8A91F137UL || D_01E90130.field_0 == 0) goto fresh;
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B8(&D_01E997AC);
        D_01E997C0.field_0 |= 1;
        D_01E99838.field_0 = 1;
        self->field_10 = 1;
        Prepare__18CB3OnlineLobbyPageFPc(&D_01E98490, info.field_0.field_0);
    presence:
        {
            unsigned short * nm = info.field_0.field_0;
            func_00310180(ubuf, func_00271A00(&D_0051BA44, 0xC07), nm);
        }
        ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(ubuf, name, 100);
        ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(func_00271A00(&D_0051BA44, 0xC08), status, 100);
        SetPresenceDetail__10CGtBuddiesFPcPcPc(&D_01E3D390, name, status, D_004D1B70[D_004E2918]);
        SetPresence__22CGtBuddiesPS2DirtySockF16EGtBuddyPresenceb(&D_01E3D390, 1, false);
        PrepareForGameStart__17CB3NetworkManagerFv(&D_01E32AE0);
        break;
    case 5:
        if ((int)p2 == 0x28) {
            if (D_01E90430.field_0 != 0) {
                ReleaseCurrentMenu__18CB3MenuPageManagerFv(&D_01E90240);
            }
            func_00284ED0(&D_01E7A800);
            self->field_10 = 3;
            if (p3 == 0) goto err0;
            if (p3 == 1) goto err1;
            if (p3 == 2) goto err2;
            if (p3 != 3) goto out;
            Prepare__12CB3ErrorPageF14EGlobalStrings14EGlobalStrings17EB3MessageBoxType(&D_01E95B4C, 0x72, 0x3C2, 2);
            break;
        }
        switch (self->field_10) {
        case 0:
            self->HandleSelectCarEvents((EB3MenuFlowFSMEvents)(int)p2);
            break;
        case 1:
            self->HandleInLobbyEvents((EB3MenuFlowFSMEvents)(int)p2);
            break;
        case 2:
            switch ((int)p2) {
            case 1:
            case 2:
            case 0:
                D_01E900C0.field_0 = D_01E99770.field_0.field_14;
                c2C0.s.lo = D_01E99770.field_0.field_C;
                c2C0.s.hi = D_01E99770.field_0.field_20;
                D_01E90198.field_0 = c2C0.l;
                D_01E901F0.field_0 = func_0030F620_inl1(&D_01E99770.field_0.field_24);
                self->field_10 = 1;
                Prepare__18CB3OnlineLobbyPageFPc(&D_01E98490, D_01E99770.field_0.field_0);
                D_01E98498.field_0 = 1;
                break;
            case 3:
                self->field_10 = 1;
                ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B8(&D_01E997AC);
                D_01E997C0.field_0 |= 1;
                D_01E99838.field_0 = 1;
                Prepare__18CB3OnlineLobbyPageFPc(&D_01E98490, D_01E99770.field_0.field_0);
                break;
            }
            break;
        case 3:
            switch ((int)p2) {
            case 1:
            case 2:
            case 0:
                D_01E90130.field_0 = 0;
                SetScene(0x94414018F8535FC2UL, 0);
                break;
            }
            break;
        case 4:
            switch ((int)p2) {
            case 1:
            case 3:
                ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_BC(&info2);
                ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B8(&D_01E997AC);
                D_01E997C0.field_0 |= 1;
                D_01E99838.field_0 = 1;
                self->field_10 = 1;
                Prepare__18CB3OnlineLobbyPageFPc(&D_01E98490, info2.field_0.field_0);
                break;
            }
            break;
        case 5:
            switch ((int)p2) {
            case 1:
            case 3:
                ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_BC(&info3);
                ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B8(&D_01E997AC);
                D_01E997C0.field_0 |= 1;
                D_01E99838.field_0 = 1;
                self->field_10 = 1;
                Prepare__18CB3OnlineLobbyPageFPc(&D_01E98490, info3.field_0.field_0);
                break;
            }
            break;
        default:
            goto out;
        }
        break;
    case 4:
        if (self->field_10 == 1) goto out;
        if (((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_D8() == 0) goto out;
        if (((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_70() == 0) goto out;
        self->field_10 = 1;
        if (D_01E90430.field_0 != 0) {
            ReleaseCurrentMenu__18CB3MenuPageManagerFv(&D_01E90240);
        }
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B8(&D_01E997AC);
        D_01E997C0.field_0 |= 1;
        D_01E99838.field_0 = 1;
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_BC(&info);
        Prepare__18CB3OnlineLobbyPageFPc(&D_01E98490, info.field_0.field_0);
        break;
notconn:
    D_01E90130.field_0 = 0;
    ClearAllPlayers__23CGtNetworkPlayerManagerFv(&D_01E32AE0);
    SetScene(0x94414018F8535FC2UL, 0);
    return;
rejoin:
    if (((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_AC() == 0 || *(unsigned long *)p2 != 0x94414018F8506BD2UL) goto plain;
    if (D_01EA0771.field_0 == 0 && D_01EA0772.field_0 == 0) {
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B8(&D_01E997AC);
        D_01E997C0.field_0 |= 1;
        D_01E99838.field_0 = 1;
        self->field_10 = 1;
        Prepare__18CB3OnlineLobbyPageFPc(&D_01E98490, info.field_0.field_0);
        goto presence;
    }
    kind = info.field_0.field_14;
    switch (kind) {
    case 0:
    case 1:
    default:
        if (D_01EA0771.field_0 != 0) {
            r300.l = func_0039EF40(&D_01EA0070);
            info.field_0.field_C = r300.s.lo;
            info.field_0.field_20 = r300.s.hi;
        } else {
            int * lo = &info.field_0.field_C;
            int * hi = &info.field_0.field_20;
            a2D0.s.lo = *lo;
            a2D0.s.hi = *hi;
            r2F8.l = func_0039EDB0(&D_01EA0070, func_003EAA60((void *)(FindTrack__21CB3HardCodedTrackListFUl(a2D0.l))));
            *lo = r2F8.s.lo;
            *hi = r2F8.s.hi;
        }
        break;
    case 2:
    case 3:
    case 4:
        r2F0.l = func_0039EC90(&D_01EA0070);
        info.field_0.field_24 = r2F0.s.lo;
        info.field_0.field_28 = r2F0.s.hi;
        a2C8.s.lo = info.field_0.field_24;
        a2C8.s.hi = info.field_0.field_28;
        r2E8.l = GetCrashStageTrackID__26CB3HardCodedCrashStageListFUl(a2C8.l);
        info.field_0.field_C = r2E8.s.lo;
        info.field_0.field_20 = r2E8.s.hi;
        break;
    }
    D_01E99770.field_0 = info.field_0;
    c2E0.s.lo = D_01E99770.field_0.field_C;
    c2E0.s.hi = D_01E99770.field_0.field_20;
    D_01E90198.field_0 = c2E0.l;
    c2D8.s.lo = D_01E99770.field_0.field_24;
    c2D8.s.hi = D_01E99770.field_0.field_28;
    D_01E901F0.field_0 = c2D8.l;
    Prepare__18CB3OnlineLobbyPageFPc(&D_01E98490, info.field_0.field_0);
    D_01E98498.field_0 = 1;
    self->field_10 = 1;
    goto presence;
plain:
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_B8(&D_01E997AC);
    D_01E997C0.field_0 |= 1;
    D_01E99838.field_0 = 1;
    self->field_10 = 1;
    Prepare__18CB3OnlineLobbyPageFPc(&D_01E98490, info.field_0.field_0);
    goto presence;
fresh:
    D_01E99824.field_0 = ((unsigned int)info.field_0.field_1C >> 8) & 0xFF;
    D_01E99828.field_0 = ((unsigned int)info.field_0.field_18 >> 8) & 0xFF;
    self->field_10 = 0;
    D_01E98499.field_0 = 1;
    func_0030ED90(self);
    goto presence;
err0:
    Prepare__12CB3ErrorPageF14EGlobalStrings14EGlobalStrings17EB3MessageBoxType(&D_01E95B4C, 0x72, 0x464, 2);
    break;
err1:
    Prepare__12CB3ErrorPageF14EGlobalStrings14EGlobalStrings17EB3MessageBoxType(&D_01E95B4C, 0x72, 0x53, 2);
    break;
err2:
    Prepare__12CB3ErrorPageF14EGlobalStrings14EGlobalStrings17EB3MessageBoxType(&D_01E95B4C, 0x72, 0x464, 2);
    break;
    }
out:;
}
