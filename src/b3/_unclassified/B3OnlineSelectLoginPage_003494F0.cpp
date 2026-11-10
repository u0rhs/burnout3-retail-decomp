// CB3OnlineSelectLoginPage::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (low); file: research/retail_names.csv -> B3OnlineSelectLoginPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (re-queued after the jtbl_retarget 2-table fix (from build/vt/hand/func_003494F0_rsw7696157.cpp)).


// func_003494F0 -- [L] DNAT: CB3OnlineSelectLoginPage::Update() (research/proto/new_names.csv, medium); modeled on func_00349840 / func_00348D10
enum EB3MenuFlowFSMEvents {};

class CB3OnlineSelectLoginPage {
public:
    void UpdateSelectLogin();
    void UpdateExistingAccount();
    void UpdateRequestingAccountPassword();
    void UpdateRetrieveLogin();
    void PrepareSelectLoginControls();
    void PrepareExistingAccountControls();

    unsigned char pad_0[0x70];
    unsigned char field_70;
    unsigned char field_71;
    unsigned char pad_72[0xF2];
    int field_164;
};

struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3InputManager {
public:
    int GetMenuConfirm(signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898E8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01E90424 D_01E90424;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void func_003485B0(CB3OnlineSelectLoginPage *);
extern "C" void func_003496C0(CB3OnlineSelectLoginPage *);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)

// 0x003494F0
extern "C" void func_003494F0(CB3OnlineSelectLoginPage * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    self->field_164 = self->field_164 + 1;
    if (self->field_164 >= 600001) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        return;
    }
    switch (self->field_70) {
    case 0:
        self->UpdateSelectLogin();
        break;
    case 1:
        self->UpdateExistingAccount();
        break;
    case 2:
        func_003485B0(self);
        break;
    case 3:
        self->UpdateRequestingAccountPassword();
        break;
    case 4:
        if (D_004F50C0.GetMenuConfirm(0) == 0) {
            return;
        }
        switch (self->field_71) {
        default:
        case 0:
        case 4:
        case 5:
        case 6:
            func_003496C0(self);
            break;
        case 1:
        case 2:
        case 3:
        case 7:
            self->PrepareExistingAccountControls();
            break;
        }
        break;
    case 5:
        self->UpdateRetrieveLogin();
        break;
    case 6: {
        int r = func_0032B2C0(&D_01E898E8, 0, 1);
        switch (r) {
        case 3:
            self->PrepareSelectLoginControls();
            break;
        case 2:
            func_003496C0(self);
            break;
        }
        break;
    }
    case 7:
        if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
            self->PrepareExistingAccountControls();
        }
        break;
    }
}
