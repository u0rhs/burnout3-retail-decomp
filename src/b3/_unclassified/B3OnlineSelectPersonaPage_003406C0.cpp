// CB3OnlineSelectPersonaPage::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OnlineSelectPersonaPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (draftJ: hand-written from asm+Ghidra; if-chain on field_8C (6,5,8,0,1,9,2,3,7,4) with no trailing returns, timeout as then-branch with return; bitfield RMW written as explicit masks; func_003609A0 takes a 6th arg (language index, as in matched siblings); entry setter inline).

// Update__26CB3OnlineSelectPersonaPageFv -- hand-written (draftJ) from the retail asm and the Ghidra draft.
// [C] name: retail tables. Shape [C asm]: field_90 counts frames (60000 -> lead out); field_8C is the page state, tested as an
// if-chain 6,5,8,0,1,9,2,3,7,4: 0 = persona list (confirm selects / opens the new-persona keyboard, delete, up/down),
// 1 = waiting for the lobby, then buddy-server connect, 2 = name keyboard, 3 = create persona result, 4/5/6/8 = message
// boxes, 7 = delete result, 9 = buddy connect wait. Field names placeholders, types [G].
struct UnkStruct_003406C0_e {                 // [L] CB3VSelectComponentEntryData (Prepare's parameter type)
    unsigned short * field_0;
    unsigned char field_4;
    unsigned char field_5;
    unsigned char pad_6[0x2];
};
struct UnkStruct_003406C0_sel { unsigned short field_0; unsigned char pad_2[0x2]; };  // [L] CB3MenuComponentSelectionData

class CB3OnlineSelectPersonaPage {
public:
    void Update();
    unsigned char pad_0[0x4];
    int field_4;                              // chosen persona
    int field_8;                              // persona count
    char field_C[4][0x20];                    // persona names (utf8)
    int field_8C;                             // state
    int field_90;                             // frame counter
    UnkStruct_003406C0_e field_94[5];
    UnkStruct_003406C0_sel field_BC;
    unsigned short * field_C0[4];
    char field_D0[0x20];
};

struct UnkStruct_003406C0_P { unsigned char pad_0[0x10]; };
struct UnkStruct_003406C0_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_003406C0_flag { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_003406C0_ulong { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_003406C0_float { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_003406C0_bf18 { unsigned int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_003406C0_bf1C { unsigned int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_003406C0_vc {
    virtual void vfunc_8();
    virtual void vfunc_C();
};
struct UnkStruct_003406C0_lobby {
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
    virtual int vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual int vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual int vfunc_94();
};
#define VC(g) ((UnkStruct_003406C0_vc *)&(g))
#define LOBBY ((UnkStruct_003406C0_lobby *)&D_01E3CD44)

extern UnkStruct_003406C0_int D_01E90424;
extern UnkStruct_003406C0_int D_01E8CBCC;
extern UnkStruct_003406C0_P D_01E90240;
extern UnkStruct_003406C0_P D_01E32AE0;
extern UnkStruct_003406C0_P D_01E3CD44;
extern UnkStruct_003406C0_P D_01E3D390;
extern UnkStruct_003406C0_flag D_01E3D4B0;
extern UnkStruct_003406C0_flag D_01E3D45C;
extern UnkStruct_003406C0_int D_01E3CE48;
extern UnkStruct_003406C0_P D_004F50C0;
extern UnkStruct_003406C0_P D_01E7A800;
extern UnkStruct_003406C0_P D_01E899C0;
extern UnkStruct_003406C0_P D_01E89788;
extern UnkStruct_003406C0_flag D_01E89792;
extern UnkStruct_003406C0_P D_01E89800;
extern UnkStruct_003406C0_ulong D_01E89810;
extern UnkStruct_003406C0_int D_01E89818;
extern UnkStruct_003406C0_P D_01E89544;
extern UnkStruct_003406C0_flag D_01E8954E;
extern UnkStruct_003406C0_P D_0051BA44;
extern UnkStruct_003406C0_P D_01E8D4B0;
extern UnkStruct_003406C0_flag D_01E8D4BA;
extern UnkStruct_003406C0_P D_01E898E8;
extern UnkStruct_003406C0_flag D_01E898F2;
extern UnkStruct_003406C0_P D_01E99880;
extern UnkStruct_003406C0_int D_01E99888;
extern UnkStruct_003406C0_bf18 D_01E99898;
extern UnkStruct_003406C0_bf1C D_01E9989C;
extern char * D_004D1B70[];
extern int D_004E2918;
extern char D_004C5C80[];
extern UnkStruct_003406C0_P D_004C5C30;
extern UnkStruct_003406C0_P D_004C5C38;
extern UnkStruct_003406C0_P D_004C5C40;
extern UnkStruct_003406C0_P D_004C5C48;
extern UnkStruct_003406C0_P D_004C5C50;
extern UnkStruct_003406C0_P D_004C5C58;
extern UnkStruct_003406C0_P D_004C5C60;
extern UnkStruct_003406C0_P D_004C5C68;
extern UnkStruct_003406C0_P D_004C5C70;
extern UnkStruct_003406C0_float D_004C5C78;

extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, int, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, int, bool);
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);
extern "C" int GetErrorString__17CB3NetworkManagerFi(void *, int);
extern "C" int GetMenuConfirm__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuBack__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuUp__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuDown__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuLeft__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuRight__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuKeyboardShift__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuKeyboardCapsLock__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuDeletePersona__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(void *, int, signed char);
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);
extern "C" void FEBack__18CB3HUDSoundManagerFv(void *);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);
extern "C" void FEKeyboardMove__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardSel__18CB3HUDSoundManagerFv(void *);
extern "C" void Show__28CB3OnScreenKeyboardComponentFbb(void *, bool, bool);
extern "C" void SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(void *, int);
extern "C" void SelectNextLeft__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectNextRight__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectNextUp__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectNextDown__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectShift__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectCapsLock__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectSymbols__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void Select__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void func_00350CF0(void *);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short*, bool, bool, float);
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short*, bool, float);
extern "C" void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, const UnkStruct_003406C0_sel *, UnkStruct_003406C0_e *, float);
extern "C" int func_00271A00(void *, int);
extern "C" bool func_00351F00(void *, void *, void *, void *, void *, void *, int, int, int, int, int, float, float);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_00319330(void *);
extern "C" int func_00319360(void *);
extern "C" void DeletePersona__20CGtLobbyPS2DirtySockFPc(void *, char *);
extern "C" void SelectPersona__20CGtLobbyPS2DirtySockFPc(void *, char *);
extern "C" void func_0033A600(void *, char *, int, int *);
extern "C" int func_003609A0(void *, char *, char *, char *, int, int);
extern "C" int Connect__22CGtBuddiesPS2DirtySockFPcPc(void *, char *, void *, void *, char *);
extern "C" void * memset(void *, int, unsigned int);
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(int, void *, int);
extern "C" void ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(char *, unsigned short *, int);

static inline void func_003406C0_inl2(UnkStruct_003406C0_e *e, unsigned short *t)
{
    e->field_0 = t;
    e->field_4 = 0;
    e->field_5 = 0;
}
static inline void func_003406C0_inl1(CB3OnlineSelectPersonaPage *p)
{
    if (p->field_C[p->field_BC.field_0][0]) {
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 | 0x10000, D_01E89818.field_0);
    } else {
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 & ~0x10000UL, D_01E89818.field_0);
    }
}

// 0x003406C0
void CB3OnlineSelectPersonaPage::Update()
{
    if (D_01E90424.field_0 != 5) return;
    field_90++;
    if (field_90 > 60000) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, 0);
        return;
    } else {
    int s = field_8C;
    if (s == 6) {
        if (!func_0032B2C0(&D_01E898E8, 0, 1)) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 1, 0);
        }
    } else if (s == 5) {
        if (!func_0032B2C0(&D_01E898E8, 0, 1)) {
        FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
        if (!LOBBY->vfunc_64()) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, 0);
            return;
        }
        if (D_01E8D4BA.field_0 != 0) VC(D_01E8D4B0)->vfunc_C();
        func_00351F00(&D_01E8D4B0, &D_004C5C58, &D_004C5C60, &D_004C5C68, &D_004C5C70, &D_004C5C78, 0x429, 3, 1, 103, 0, 26.0f, D_004C5C78.field_0);
        field_8C = 0;
        VC(D_01E898E8)->vfunc_C();
        if (!D_01E8954E.field_0) {
            Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, &field_BC, field_94, 640.0f);
        }
        if (D_01E89792.field_0 != 0) VC(D_01E89788)->vfunc_C();
        func_003406C0_inl1(this);
        }
    } else if (s == 8) {
        int r = func_0032B2C0(&D_01E898E8, 0, 1);
        if (r == 4) {
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            if (D_01E898F2.field_0 != 0) VC(D_01E898E8)->vfunc_C();
            DeletePersona__20CGtLobbyPS2DirtySockFPc(&D_01E3CD44, field_C[field_BC.field_0]);
            func_0032D080(&D_01E898E8, 0, 0x427, 15, 0);
            field_8C = 7;
        } else if (r == 5) {
            field_8C = 0;
            VC(D_01E898E8)->vfunc_C();
            FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
        }
    } else if (s == 0) {
        if (GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            if (field_BC.field_0 < field_8) {
                VC(D_01E89800)->vfunc_C();
                FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
                field_4 = field_BC.field_0;
                SelectPersona__20CGtLobbyPS2DirtySockFPc(&D_01E3CD44, field_C[field_BC.field_0]);
                VC(D_01E89544)->vfunc_C();
                if (D_01E89792.field_0 != 0) {
                    SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short *)func_00271A00(&D_0051BA44, 0x50), 0, 0, 80.0f);
                } else {
                    Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short *)func_00271A00(&D_0051BA44, 0x50), 1, 80.0f);
                }
                VC(D_01E8D4B0)->vfunc_C();
                func_00351F00(&D_01E8D4B0, &D_004C5C30, &D_004C5C38, &D_004C5C40, &D_004C5C48, &D_004C5C50, 0x50, 3, 0, 1, 0, 32.0f, 400.0f);
                field_8C = 1;
                return;
            }
            if (field_BC.field_0 == 4) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 0x2B, 0);
            } else {
                Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, 1, 1);
                SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(&D_01E899C0, 0x295);
                D_01E8CBCC.field_0 = 13;
                field_8C = 2;
                FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            }
        }
        if (GetMenuDeletePersona__15CB3InputManagerFSc(&D_004F50C0, -1) && field_C[field_BC.field_0][0]) {
            if (D_01E898F2.field_0 != 0) VC(D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 7, 0x425, 5, 0);
            field_8C = 8;
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
        }
        if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, 0);
            return;
        } else if ((GetMenuUp__15CB3InputManagerFSc(&D_004F50C0, 0) && func_00319360(&field_BC)) ||
                   (GetMenuDown__15CB3InputManagerFSc(&D_004F50C0, 0) && func_00319330(&field_BC))) {
            if (field_BC.field_0 < 4) {
                func_003406C0_inl1(this);
            } else {
                SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 & ~0x10000UL, D_01E89818.field_0);
            }
            FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            return;
        }
    } else if (s == 1) {
        if (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0) == 2) {
            char buf1D0[100];
            char buf160[100];
            char buf60[0x100];
            int n;
            memset(&D_01E99880, 0, 0x3C);
            D_01E99888.field_0 = 6;
            D_01E9989C.field_0 = (D_01E9989C.field_0 & 0xFFFFFF) | 0x3000000;
            D_01E99898.field_0 = (D_01E99898.field_0 & 0xFF00FFFF) | 0x10000;
            func_0033A600(&D_01E3CD44, buf60, 0x100, &n);
            ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(func_00271A00(&D_0051BA44, 5), buf1D0, 100);
            ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(func_00271A00(&D_0051BA44, 0xC08), buf160, 100);
            func_003609A0(&D_01E3D390, buf1D0, buf160, D_004D1B70[D_004E2918], D_01E3CE48.field_0, D_004E2918);
            if (D_01E3D4B0.field_0 != 0) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 1, 0);
            } else {
            Connect__22CGtBuddiesPS2DirtySockFPcPc(&D_01E3D390, buf60, (void *)(n), (void *)(LOBBY->vfunc_94()), D_004C5C80);
            field_8C = 9;
            }
        } else if (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0) == 1) {
            int e = LOBBY->vfunc_58();
            if (e) {
                field_8C = 5;
                VC(D_01E8D4B0)->vfunc_C();
                if (D_01E898F2.field_0 != 0) VC(D_01E898E8)->vfunc_C();
                func_0032D080(&D_01E898E8, 2, GetErrorString__17CB3NetworkManagerFi(&D_01E32AE0, e), 0, 0);
                if (D_01E89792.field_0 != 0) VC(D_01E89788)->vfunc_C();
            }
        }
    } else if (s == 9) {
        if (D_01E3D4B0.field_0 != 0) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 1, 0);
        } else if (D_01E3D45C.field_0 == 0) {
            field_8C = 6;
            VC(D_01E8D4B0)->vfunc_C();
            if (D_01E898F2.field_0 != 0) VC(D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, 0x4B6, 0, 0);
            if (D_01E89792.field_0 != 0) VC(D_01E89788)->vfunc_C();
        }
    } else if (s == 2) {
        if (GetMenuLeft__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectNextLeft__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuRight__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectNextRight__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuUp__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectNextUp__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuDown__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectNextDown__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            Select__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuKeyboardShift__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectShift__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuKeyboardCapsLock__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectCapsLock__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 14, 0)) {
            SelectSymbols__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 15, 0)) {
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
            func_00350CF0(&D_01E899C0);
        } else if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, 0, 0);
            field_8C = 0;
        }
    } else if (s == 3) {
        switch (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0)) {
        case 0:
            break;
        case 2:
            if (D_01E898F2.field_0 != 0) VC(D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, 0x422, 0, 0);
            field_8C = 4;
            strncpy(field_C[field_8], field_D0, 0x20);
            ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(field_C[field_8], field_C0[field_8], 0x20);
            func_003406C0_inl2(&field_94[field_8], field_C0[field_8]);
            field_8++;
            VC(D_01E89544)->vfunc_C();
            Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, &field_BC, field_94, 640.0f);
            break;
        case 1: {
            int e = LOBBY->vfunc_58();
            if (e == -7) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 0x22, 0);
                break;
            }
            field_8C = 5;
            if (D_01E8D4BA.field_0 != 0) VC(D_01E8D4B0)->vfunc_C();
            if (D_01E898F2.field_0 != 0) VC(D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, GetErrorString__17CB3NetworkManagerFi(&D_01E32AE0, e), 0, 0);
            break;
        }
        }
    } else if (s == 7) {
        switch (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0)) {
        case 0:
            break;
        case 2: {
            if (D_01E898F2.field_0 != 0) VC(D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, 0x428, 0, 0);
            field_8C = 4;
            int i;
            for (i = field_BC.field_0; i < 3; i++) {
                strncpy(field_C[i], field_C[i + 1], 0x20);
            }
            strncpy(field_C[3], D_004C5C80, 0x20);
            field_8--;
            for (i = 0; i < field_8; i++) {
                ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(field_C[i], field_C0[i], 0x14);
                func_003406C0_inl2(&field_94[i], field_C0[i]);
            }
            for (; i < 4; i++) {
                func_003406C0_inl2(&field_94[i], (unsigned short *)func_00271A00(&D_0051BA44, 0x421));
            }
            VC(D_01E89544)->vfunc_C();
            Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, &field_BC, field_94, 640.0f);
            break;
        }
        case 1: {
            int e = LOBBY->vfunc_58();
            if (e == -7) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 0x22, 0);
                break;
            }
            field_8C = 5;
            VC(D_01E8D4B0)->vfunc_C();
            if (D_01E898F2.field_0 != 0) VC(D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, GetErrorString__17CB3NetworkManagerFi(&D_01E32AE0, e), 0, 0);
            break;
        }
        }
    } else if (s == 4) {
        if (!func_0032B2C0(&D_01E898E8, 0, 1)) {
        VC(D_01E898E8)->vfunc_C();
        field_8C = 0;
        func_003406C0_inl1(this);
        }
    }
    }
}
