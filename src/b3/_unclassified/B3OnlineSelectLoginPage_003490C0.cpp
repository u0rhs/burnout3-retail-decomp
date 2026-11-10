// CB3OnlineSelectLoginPage::UpdateSelectLogin() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineSelectLoginPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (UpdateSelectLogin).

enum EB3MenuFlowFSMEvents {};
enum EMemDevPollOrWait {};
class CB3InputManager {
public:
    int GetMenuConfirm(signed char);
    int GetMenuBack(signed char);
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);
    unsigned char pad_0[0x10];
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
extern CB3InputManager D_004F50C0;
extern UnkStruct_P D_005185A0;
extern UnkStruct_P D_01E90240;
extern UnkStruct_P D_01E7A800;
extern UnkStruct_P D_01ECD520;
class CB3OnlineSelectLoginPage;
extern "C" {
int func_00319330(void *);
int func_00319360(void *);
int Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(void *, EMemDevPollOrWait, int *);
int func_0030A8C0(void *);
void func_003496C0(CB3OnlineSelectLoginPage *);
char *strcpy(char *, const char *);
void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);
void FESelect__18CB3HUDSoundManagerFv(void *);
void func_00420B60(void *);
}
class CB3OnlineSelectLoginPage {
public:
    void UpdateSelectLogin();
    void PrepareExistingAccountControls();
    unsigned char pad_0[0xDC];
    unsigned char field_DC;
    unsigned char pad_DD[7];
    unsigned char field_E4;
    unsigned char pad_E5[0xB];
    unsigned short field_F0;
};
// 0x003490C0
void CB3OnlineSelectLoginPage::UpdateSelectLogin()
{
    if ((D_004F50C0.GetMenuUp(0) != 0 && func_00319360((char *)this + 0xF0) != 0) || (D_004F50C0.GetMenuDown(0) != 0 && func_00319330((char *)this + 0xF0) != 0)) return;
    if (Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(&D_005185A0, (EMemDevPollOrWait)0, 0) == 0xD && func_0030A8C0(&D_005185A0) == 2) {
        func_003496C0(this);
        return;
    }
    if (D_004F50C0.GetMenuConfirm(0) != 0) {
        if (field_F0 == 1 && field_E4 == 0) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        } else if (field_F0 == 2) {
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            PrepareExistingAccountControls();
            func_00420B60(&D_01ECD520);
        } else if (field_F0 == 0) {
            if (field_DC == 0) {
                strcpy((char *)this + 4, (char *)this + 0x73);
                strcpy((char *)this + 0x36, (char *)this + 0xA5);
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
            }
        }
    }
    if (D_004F50C0.GetMenuBack(0) == 0) return;
    StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, false);
}
