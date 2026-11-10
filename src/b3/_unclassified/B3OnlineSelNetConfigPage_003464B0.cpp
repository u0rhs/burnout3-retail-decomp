// CB3OnlineSelNetConfigPage::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineSelNetConfigPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (explicit return; after the switch + case-0 confirm chain ends return;, Back arm return;, Sync exit break; (sdra rule 2: return/break placement picks the unthreaded join blocks and which epilogue branch gets ld ra)).

enum EB3MenuFlowFSMEvents {};
enum EMemDevPollOrWait {};
enum EGlobalStrings {};
struct UnkStruct_V_a149 { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_I_a149 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_B_a149 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_P_a149 { unsigned char pad_0[0x10]; };
class CB3InputManager {
public:
    int GetMenuConfirm(signed char);
    int GetMenuBack(signed char);
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);
    unsigned char pad_0[0x10];
};
extern UnkStruct_I_a149 D_01E90424;
extern UnkStruct_P_a149 D_005185A0, D_01E90240, D_0051BA44, D_01E89788, D_004C6E48, D_004C6E50;
extern UnkStruct_V_a149 D_01E898E8, D_01E8970C, D_01E8D4F0;
extern UnkStruct_B_a149 D_01E89716, D_01E8D4FA, D_01E89792;
extern CB3InputManager D_004F50C0;
extern "C" {
int Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(void *, int, void *);
void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);
int func_00319360(void *);
int func_00319330(void *);
void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short *, bool, bool, float);
void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short *, bool, float);
int func_00271A00(void *, int);
void func_0032D080(void *, int, int, int, int);
int func_0032B2C0(void *, int, int);
int func_0039BCD0(void *, void *, void *, int, int, float);
void Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d14EGlobalStringsUi(void *, const void *, const void *, EGlobalStrings, unsigned int);
}
#define HIDE(o) ((UnkStruct_V_a149 *)&(o))->vfunc_C()
class CB3OnlineSelNetConfigPage {
public:
    void Update();
    unsigned char pad_0[4];
    int field_4;
    unsigned char pad_8[0x18];
    int field_20[6];
    unsigned char field_38[8];
    unsigned char pad_40[0x38];
    unsigned short field_78;
    unsigned char pad_7A[2];
    signed char field_7C[8];
    int field_84;
    signed char field_88;
};
// 0x003464B0
void CB3OnlineSelNetConfigPage::Update()
{
    if (D_01E90424.field_0 == 5) {
        switch (field_88) {
        case 0:
            if (Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(&D_005185A0, 0, (void *)(0)) == 0xD) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x29, 0);
                break;
            }
            if ((D_004F50C0.GetMenuUp(0) != 0 && func_00319360(&field_78) != 0) || (D_004F50C0.GetMenuDown(0) != 0 && func_00319330(&field_78) != 0)) {
                if (field_84 == field_78) {
                    int r = func_00271A00(&D_0051BA44, 0x434);
                    SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short *)r, false, false, 80.0f);
                } else {
                    SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short *)field_20[field_78], false, false, 80.0f);
                }
                return;
            }
            if (D_004F50C0.GetMenuConfirm(0) != 0) {
                unsigned short c = field_78;
                if (field_84 == c) {
                    if (D_01E89716.field_0 != 0) HIDE(D_01E8970C);
                    if (D_01E8D4FA.field_0 != 0) HIDE(D_01E8D4F0);
                    if (D_01E89792.field_0 != 0) HIDE(D_01E89788);
                    field_88 = 1;
                    func_0032D080(&D_01E898E8, 7, 0x435, 5, 0);
                } else if (field_38[c] == 0) {
                    func_0032D080(&D_01E898E8, 2, 0xE6B, 0xF, 0);
                    field_88 = 3;
                } else {
                    field_4 = field_7C[c] + 1;
                    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
                }
                return;
            } else if (D_004F50C0.GetMenuBack(0) != 0) {
                StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
                return;
            }
            break;
        case 3:
            if (D_004F50C0.GetMenuConfirm(0) != 0) {
                field_88 = 0;
                HIDE(D_01E898E8);
            }
            break;
        case 2:
            if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
                StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            }
            break;
        case 1:
            switch (func_0032B2C0(&D_01E898E8, 0, 1)) {
            case 4:
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x1C, 0);
                break;
            case 5:
                if (D_01E89716.field_0 != 0) HIDE(D_01E8970C);
                func_0039BCD0(&D_01E8970C, &field_78, (char *)this + 0x40, 2, 0, 516.0f);
                if (D_01E8D4FA.field_0 != 0) HIDE(D_01E8D4F0);
                Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d14EGlobalStringsUi(&D_01E8D4F0, &D_004C6E48, &D_004C6E50, (EGlobalStrings)0x432, 0x67);
                if (D_01E89792.field_0 != 0) HIDE(D_01E89788);
                Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short *)field_20[0], true, 80.0f);
                field_88 = 0;
                HIDE(D_01E898E8);
                break;
            }
            break;
        }
        return;
    }
}
