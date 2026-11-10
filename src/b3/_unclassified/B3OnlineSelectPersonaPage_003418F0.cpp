// CB3OnlineSelectPersonaPage::Prepare(char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineSelectPersonaPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a149: sibling func_0037CF00 shapes; ~0x10000UL mask; goto fin shared return).

enum EB3BackgroundType {};
class CB3PromptBarComponent { public: void Prepare(); unsigned char pad_0[0x10]; };
struct UnkStruct_Pad16_a149 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C5C78_a149 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E89544_a149 { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
extern UnkStruct_Pad16_a149 D_01E90438, D_01E89518, D_01E88A80, D_01E899C0, D_01E89800, D_01E89788, D_0051BA44, D_01E8D4B0, D_01E3CD44;
extern UnkStruct_Pad16_a149 D_004C5C30, D_004C5C38, D_004C5C40, D_004C5C48, D_004C5C50, D_004C5C58, D_004C5C60, D_004C5C68, D_004C5C70;
extern UnkStruct_D_004C5C78_a149 D_004C5C78;
extern UnkStruct_D_01E89544_a149 D_01E89544;
extern CB3PromptBarComponent D_01E894FC;
struct UnkStruct_D_01E89810_a149 { unsigned long field_0; int field_8; int pad_C; };
extern UnkStruct_D_01E89810_a149 D_01E89810;
extern "C" {
void Prepare__15CB3MenuPageBaseFb(void *, bool);
int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
void func_00319C80(void *, int, int);
int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);
int func_003517F0(void *);
void ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(void *, int, int);
int func_00271A00(void *, int);
void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, const void *, void *, float);
void SelectPersona__20CGtLobbyPS2DirtySockFPc(void *, char *);
void Prepare__19CB3HelpBarComponentFv(void *);
void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short *, bool, bool, float);
bool func_00351F00(void *, void *, void *, void *, void *, void *, int, int, int, int, int, float, float);
bool func_0031ECD0(void *, unsigned long, int);
void RegisterKeyboardCallbacks__28CB3OnScreenKeyboardComponentFv(void *);
void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
}
struct UnkStruct_a149_ent { int field_0; unsigned char field_4; unsigned char field_5; unsigned char pad_6[2]; };
class CB3OnlineSelectPersonaPage {
public:
    int Prepare(char *);
    unsigned char pad_0[8];
    int field_8;
    char field_C[4][0x20];
    int field_8C;
    int field_90;
    UnkStruct_a149_ent field_94[4];
    int field_B4;
    unsigned char field_B8;
    unsigned char field_B9;
    unsigned char pad_BA[2];
    short field_BC;
    short field_BE;
    int field_C0[4];
};
// 0x003418F0
int CB3OnlineSelectPersonaPage::Prepare(char *name)
{
    int s0;
    int r;
    int t;
    Prepare__15CB3MenuPageBaseFb(this, 0);
    s0 = 0;
    do {
        field_C0[s0] = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x20);
        s0++;
    } while (s0 < 4);
    func_00319C80(&D_01E89518, 0x420, 0xE);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    D_01E894FC.Prepare();
    func_003517F0(&D_01E899C0);
    for (s0 = 0; s0 < field_8; s0++) {
        int *p = &field_C0[s0];
        ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(field_C[s0], *p, 0x14);
        field_94[s0].field_0 = *p;
        field_94[s0].field_4 = 0;
        field_94[s0].field_5 = 0;
    }
    for (; s0 < 4; s0++) {
        t = func_00271A00(&D_0051BA44, 0x421);
        field_94[s0].field_0 = t;
        field_94[s0].field_4 = 0;
        field_94[s0].field_5 = 0;
    }
    field_B4 = func_00271A00(&D_0051BA44, 0x80);
    field_B8 = 0;
    field_B9 = 0;
    field_BC = 0;
    field_BE = 5;
    Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, &field_BC, field_94, 640.0f);
    field_90 = 0;
    if (name != 0) {
        field_8C = 1;
        if (name != 0) SelectPersona__20CGtLobbyPS2DirtySockFPc(&D_01E3CD44, name);
        else SelectPersona__20CGtLobbyPS2DirtySockFPc(&D_01E3CD44, field_C[0]);
        ((UnkStruct_D_01E89544_a149 *)&D_01E89544)->vfunc_C();
        Prepare__19CB3HelpBarComponentFv(&D_01E89788);
        r = func_00271A00(&D_0051BA44, 0x50);
        SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short *)r, true, true, 80.0f);
        func_00351F00(&D_01E8D4B0, &D_004C5C30, &D_004C5C38, &D_004C5C40, &D_004C5C48, &D_004C5C50, 0x50, 3, 0, 1, 0, 32.0f, 400.0f);
    fin:
        return 1;
    }
    field_8C = 0;
    func_0031ECD0(&D_01E89800, 0x105, 3);
    RegisterKeyboardCallbacks__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
    if (field_C[(unsigned short)field_BC][0] != 0) {
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 | 0x10000, D_01E89810.field_8);
    } else {
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 & ~0x10000UL, D_01E89810.field_8);
    }
    func_00351F00(&D_01E8D4B0, &D_004C5C58, &D_004C5C60, &D_004C5C68, &D_004C5C70, &D_004C5C78, 0x429, 3, 1, 0x67, 0, 26.0f, D_004C5C78.field_0);
    goto fin;
}
