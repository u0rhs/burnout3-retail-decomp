// func_00398DE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (rewritten from 685-instr lift: early-return input chain, one-case switch for the Down test (bcond; b epilogue), Left||Right switch with case 2/3 sharing default, StartLeadOut's phantom 4th arg dropped).

// lifter variant 0
// func_00398DE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3MenuFlowFSMEvents {};
enum EGlobalStrings {};

class CB3InputManager;
class CB3OnScreenKeyboardComponent;
struct UnkStruct_00398DE0;
struct UnkStruct_D_01E8CBCC;
struct UnkStruct_D_01E90240;

class CB3InputManager {
public:
    int GetMenuConfirm(signed char);
    int GetMenuBack(signed char);
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);
    int GetMenuLeft(signed char);
    int GetMenuRight(signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnScreenKeyboardComponent {
public:
    void RegisterKeyboardCallbacks();
    void Show(bool, bool);
    void SetAllowableCharacters(EGlobalStrings);
    void SetDisplayText(char*, bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8CBCC {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00398DE0 {
    unsigned char pad_0[0x4];
    void * field_4;
    void * field_8;
    int field_C;
    unsigned char pad_10[0x10];
    int field_20;
    unsigned char pad_24[0x1C];
    unsigned short field_40;
    unsigned char pad_42[0x9E];
    int field_E0;
    int field_E4;
    int field_E8;
};

extern UnkStruct_D_01E8CBCC D_01E8CBCC;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern CB3OnScreenKeyboardComponent D_01E899C0;

extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)
extern "C" void func_00398850(UnkStruct_00398DE0 *);
extern "C" int func_00319330(void *);
extern "C" int func_00319360(void *);

// 0x00398DE0
extern "C" void func_00398DE0(UnkStruct_00398DE0 * self)
{
    if (D_004F50C0.GetMenuConfirm(0) != 0) {
        self->field_4 = (char *)self + 0xAC;
        self->field_8 = (char *)self + 0xCC;
        self->field_C = self->field_E8;
        int t = self->field_E4;
        self->field_20 &= ~0xFF;
        self->field_20 |= t;
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        return;
    }
    if (D_004F50C0.GetMenuBack(0) != 0) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        return;
    }
    if (D_004F50C0.GetMenuUp(0) != 0 && func_00319360((char *)self + 0x40) != 0) {
        return;
    }
    if (D_004F50C0.GetMenuDown(0) != 0) {
        switch (func_00319330((char *)self + 0x40)) {
        case 0:
            break;
        default:
            return;
        }
    }
    if (D_004F50C0.GetMenuLeft(0) != 0 || D_004F50C0.GetMenuRight(0) != 0) {
        switch (self->field_40) {
        case 0:
            self->field_E0 = 1;
            D_01E899C0.RegisterKeyboardCallbacks();
            D_01E899C0.Show(1, 0);
            D_01E899C0.SetAllowableCharacters((EGlobalStrings)663);
            D_01E8CBCC.field_0 = 32;
            D_01E899C0.SetDisplayText((char *)self + 0xAC, 1);
            break;
        case 1:
            self->field_E0 = 2;
            D_01E899C0.RegisterKeyboardCallbacks();
            D_01E899C0.Show(1, 0);
            D_01E899C0.SetAllowableCharacters((EGlobalStrings)3160);
            D_01E8CBCC.field_0 = 17;
            D_01E899C0.SetDisplayText((char *)self + 0xCC, 0);
            break;
        case 2:
        case 3:
        default:
            func_00398850(self);
            break;
        }
    }
}
