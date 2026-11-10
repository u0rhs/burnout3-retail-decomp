// CB3OnlineMenuPage::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineMenuPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (explicit return; after the switch (inside the if) keeps retail's unthreaded 'b epi; nop' join; StartLeadOut exit is a return, case 2 breaks: the first epilogue branch in layout gets ld ra (sdra rule 2)).

enum EB3MenuFlowFSMEvents {};
struct UnkStruct_D_01E3CD44 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual int vfunc_14();
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
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E898E8 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
class CB3InputManager {
public:
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);
    int GetMenuConfirm(signed char);
    int GetMenuBack(signed char);
    unsigned char pad_0[0x10];
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
class CB3OnlineMenuPage {
public:
    void Update();
    unsigned char pad_0[0x4];
    unsigned char field_4[0x34];
    int field_38;
};
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_P D_01E32AE0;
extern UnkStruct_P D_01E90240;
extern UnkStruct_I D_01E90424;
extern UnkStruct_B D_01E6549A;
extern UnkStruct_B D_01EA2F0C;
extern UnkStruct_B D_01EA2F0E;
extern "C" void ClearAllPlayers__23CGtNetworkPlayerManagerFv(void *);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);
extern "C" int func_0022CBE0(void *, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" void func_0026CA00(void *);
// 0x00323740
void CB3OnlineMenuPage::Update()
{
    if (D_01E90424.field_0 == 5) {
        switch (field_38) {
        case 0:
            switch (((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_14()) {
            case 1:
                ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58();
            case 2:
                ClearAllPlayers__23CGtNetworkPlayerManagerFv(&D_01E32AE0);
                field_38 = 1;
            case 0:
                break;
            }
        case 1:
            if (D_004F50C0.GetMenuConfirm(0) && ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_14()) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
                return;
            }
            if (D_004F50C0.GetMenuBack(0) && ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_14()) {
                field_38 = 2;
                func_0032D080(&D_01E898E8, 7, 0x74, 5, 0);
                return;
            }
            if (func_0022CBE0(&D_004F50C0, 0) && ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_14()) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x24, 0);
                return;
            }
            if (D_004F50C0.GetMenuUp(0) && func_00319360(field_4)) break;
            if (D_004F50C0.GetMenuDown(0) && func_00319330(field_4)) return;
            break;
        case 2: {
            int r = func_0032B2C0(&D_01E898E8, 0, 1);
            if (r == 4) {
                D_01E6549A.field_0 = 0;
                func_0026CA00(&D_01E32AE0);
                D_01EA2F0C.field_0 = 0;
                D_01EA2F0E.field_0 = 0;
                StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            } else if (r == 5) {
                ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                field_38 = 1;
            }
            break;
        }

        }
        return;
    }
}
