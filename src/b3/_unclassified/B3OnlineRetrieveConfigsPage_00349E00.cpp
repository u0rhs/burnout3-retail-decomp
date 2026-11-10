// CB3OnlineRetrieveConfigsPage::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (low); file: research/retail_names.csv -> B3OnlineRetrieveConfigsPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (exact; switch jump table retargeted at retail's (tools/jtbl_retarget.py)).

// func_00349E00 -- CB3OnlineRetrieveConfigsPage::Update()
// [L] DNAT: CB3OnlineRetrieveConfigsPage::Update() (research/proto/new_names.csv, medium)

enum EB3MenuFlowFSMEvents {};
enum EMemDevPollOrWait {};

struct UnkStruct_D_01E898E8 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };

class CB3OnlineRetrieveConfigsPage {
public:
    unsigned char pad_0[0x4];
    signed char field_4;
};

extern UnkStruct_I D_01E90424;
extern UnkStruct_P D_01E3C620;
extern UnkStruct_P D_005185A0;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_P D_01E32AE0;
extern UnkStruct_P D_01E90240;
extern UnkStruct_B D_01E65489;
extern UnkStruct_B D_01E6548B;
extern UnkStruct_B D_0051BA90;

extern "C" int func_0022F320(void *);
extern "C" int func_0022D2D0(void *);
extern "C" int Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(void *, int, void *);
extern "C" int func_0030A8C0(void *);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int GetAdapterErrorString__17CB3NetworkManagerFi(void *, int);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);

#define HIDE() ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C()

// 0x00349E00
extern "C" void func_00349E00(CB3OnlineRetrieveConfigsPage * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    switch (self->field_4) {
    case 0:
        switch (func_0022F320(&D_01E3C620)) {
        case 1:
            return;
        case 3:
            {
                int e = func_0022D2D0(&D_01E3C620);
                if (e == 4) {
                    D_01E65489.field_0 = 0;
                    self->field_4 = 2;
                    Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(&D_005185A0, 0, (void *)(0));
                    break;
                }
                D_01E65489.field_0 = 0;
                HIDE();
                if (e != 3 && e != 5) {
                    func_0032D080(&D_01E898E8, 2, GetAdapterErrorString__17CB3NetworkManagerFi(&D_01E32AE0, e), 0, 0);
                    self->field_4 = 5;
                } else {
                    func_0032D080(&D_01E898E8, 7, GetAdapterErrorString__17CB3NetworkManagerFi(&D_01E32AE0, e), 5, 0);
                    self->field_4 = 6;
                }
                return;
            }
        case 2:
            D_01E65489.field_0 = 0;
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
            break;
        }
        break;
    case 1:
        {
            int r = Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(&D_005185A0, 0, (void *)(0));
            if (r == 0xD) {
                if (func_0030A8C0(&D_005185A0) != 1) {
                    if (func_0030A8C0(&D_005185A0) != 2) {
                        HIDE();
                        func_0032D080(&D_01E898E8, 7, 0x67, 5, 0);
                        self->field_4 = 7;
                    }
                } else {
                    HIDE();
                    func_0032D080(&D_01E898E8, 5, 0x79, 1, 0);
                    self->field_4 = 3;
                }
                break;
            }
            if (r == 0) {
                D_01E65489.field_0 = 1;
                self->field_4 = 0;
            }
        }
        break;
    case 2:
        {
            int r = Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(&D_005185A0, 0, (void *)(0));
            if (r == 0xD) {
                if (func_0030A8C0(&D_005185A0) != 1) {
                    if (func_0030A8C0(&D_005185A0) != 2) {
                        HIDE();
                        func_0032D080(&D_01E898E8, 7, 0x67, 5, 0);
                        self->field_4 = 7;
                    }
                } else {
                    HIDE();
                    func_0032D080(&D_01E898E8, 5, 0x79, 1, 0);
                    self->field_4 = 3;
                }
                break;
            }
            if (r == 0) {
                HIDE();
                func_0032D080(&D_01E898E8, 7, 0x67, 5, 0);
                self->field_4 = 7;
            }
        }
        break;
    case 3:
        switch (func_0032B2C0(&D_01E898E8, 0, 1)) {
        case 2:
            self->field_4 = 1;
            HIDE();
            func_0032D080(&D_01E898E8, 1, 0x78, 0xF, 0);
            break;
        case 1:
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            break;
        }
        break;
    case 5:
        if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        }
        break;
    case 7:
        switch (func_0032B2C0(&D_01E898E8, 0, 1)) {
        case 4:
            HIDE();
            func_0032D080(&D_01E898E8, 7, 0x435, 5, 0);
            self->field_4 = 4;
            break;
        case 5:
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            break;
        }
        break;
    case 6:
        switch (func_0032B2C0(&D_01E898E8, 0, 1)) {
        case 4:
            HIDE();
            func_0032D080(&D_01E898E8, 7, 0x435, 5, 0);
            self->field_4 = 4;
            break;
        case 5:
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            break;
        }
        break;
    case 4:
        switch (func_0032B2C0(&D_01E898E8, 0, 1)) {
        case 4:
            HIDE();
            D_0051BA90.field_0 = 1;
            D_01E6548B.field_0 = 1;
            break;
        case 5:
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            break;
        }
        break;
    }
}
