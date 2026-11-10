// Update__11CB3DNASPageFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (Hand-structured: if (field_8) / else if (D_01E898F2) / else chain; block-form ifs instead of early returns (keeps bodies inline), explicit return at the end of the D_01E898F2 arm, C arm ends with an early-return form; ELobbyKickReason declared (lifter: undeclared enum)).

// lifter variant 0
// Update__11CB3DNASPageFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3MenuFlowFSMEvents {};
enum EB3BackgroundType {};

enum ELobbyKickReason {};
class CB3InputManager;
struct UnkStruct_003530F0;
struct UnkStruct_003530F0_10;
struct UnkStruct_D_004E2918;
struct UnkStruct_D_0051A6A8;
struct UnkStruct_D_0051A9A0;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E3CD44;
struct UnkStruct_D_01E65489;
struct UnkStruct_D_01E654BC;
struct UnkStruct_D_01E654C2;
struct UnkStruct_D_01E654C8;
struct UnkStruct_D_01E7A888;
struct UnkStruct_D_01E88A80;
struct UnkStruct_D_01E89788;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E8980A;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E898F2;
struct UnkStruct_D_01E8D4B0;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E90424;

class CB3InputManager {
public:
    int GetMenuBack(signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3CD44 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(int, void *, void *, void *, void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E2918 {
    int field_0;
};

struct UnkStruct_D_01E65489 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898F2 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E654C8 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8980A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E654C2 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003530F0_10 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_D_01E89788 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D4B0 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E88A80 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E654BC {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A9A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898E8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A6A8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E7A888 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003530F0 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char field_8;
    unsigned char field_9;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_004E2918 D_004E2918;
extern UnkStruct_D_01E65489 D_01E65489;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E654C8 D_01E654C8;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E654C2 D_01E654C2;
extern UnkStruct_D_01E89788 D_01E89788;
extern UnkStruct_D_01E8D4B0 D_01E8D4B0;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E654BC D_01E654BC;
extern UnkStruct_D_0051A9A0 D_0051A9A0;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_01E7A888 D_01E7A888;
extern UnkStruct_D_01E90240 D_01E90240;
extern CB3InputManager D_004F50C0;

extern "C" bool PlayerListChangedCallback__17CB3NetworkManagerFiPv(int, void*);  // CB3NetworkManager::PlayerListChangedCallback(int,void*), its address taken
extern "C" int PlayerBootedCallback__17CB3NetworkManagerF16ELobbyKickReasonPv(ELobbyKickReason, void*);  // CB3NetworkManager::PlayerBootedCallback(ELobbyKickReason,void*), its address taken
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" int Prepare__17CB3NetworkManagerFb(void *, bool);  // CB3NetworkManager::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)
extern "C" int func_00130D50(void *);
extern "C" void func_003FA600(void *, int);
extern "C" void func_0026D260(void *);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_0032CF60(void *, int, void *, int, int);
extern "C" int func_0032B2C0(void *, int, int);

// 0x003530F0
extern "C" void Update__11CB3DNASPageFv(UnkStruct_003530F0 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    if (self->field_8 != 0) {
        if (func_00130D50(&D_0051A6A8) != 0) {
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_18(1234, (void *)&PlayerListChangedCallback__17CB3NetworkManagerFiPv, &D_01E32AE0, (void *)&PlayerBootedCallback__17CB3NetworkManagerF16ELobbyKickReasonPv, &D_01E32AE0, D_004E2918.field_0);
            func_003FA600(&D_01E7A888, 1);
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)self->field_4, 0);
        } else if (D_004F50C0.GetMenuBack(0) != 0 && self->field_4 != 3) {
            func_0026D260(&D_01E32AE0);
            D_01E65489.field_0 = 0;
            self->field_4 = 3;
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
    } else if (D_01E898F2.field_0 != 0) {
        if (D_0051A9A0.field_0 != 23) {
            func_00130D50(&D_0051A6A8);
        }
        if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
            func_0026D260(&D_01E32AE0);
            D_01E65489.field_0 = 0;
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            if (D_0051A9A0.field_0 == 23) {
                func_003FA600(&D_01E7A888, 1);
                StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            } else {
                self->field_8 = 1;
                self->field_4 = 3;
            }
            return;
        }
    } else {
        if (Prepare__17CB3NetworkManagerFb(&D_01E32AE0, 0) != 0) {
            self->field_8 = 1;
            self->field_4 = 18;
            return;
        }
        if (D_01E654C8.field_0 >= 0 && D_01E8980A.field_0 == 0 && self->field_9 == 0) {
            func_0031ECD0(&D_01E89800, 2, 3);
        }
        if (D_01E654C8.field_0 >= 0) {
            if (D_004F50C0.GetMenuBack(0) != 0) {
                D_01E654C2.field_0 = 1;
                ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
                self->field_9 = 1;
            }
        }
        if (D_01E654C8.field_0 == 10) {
            ((UnkStruct_D_01E89788 *)&D_01E89788)->vfunc_C();
            ((UnkStruct_D_01E8D4B0 *)&D_01E8D4B0)->vfunc_C();
            if (D_01E8980A.field_0 != 0) {
                ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
            }
            ((UnkStruct_D_01E88A80 *)&D_01E88A80)->vfunc_C();
            Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)4);
            func_0032CF60(&D_01E898E8, 2, (void *)(D_01E654BC.field_0), 0, 0);
        }
        if (self->field_9 != 0 && D_01E654C8.field_0 != 6 && D_0051A9A0.field_0 != 23) {
            func_00130D50(&D_0051A6A8);
        }
        if (D_01E654C8.field_0 != 11) {
            return;
        }
        if (D_0051A9A0.field_0 == 23) {
            func_0026D260(&D_01E32AE0);
            D_01E65489.field_0 = 0;
            func_003FA600(&D_01E7A888, 1);
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            return;
        }
        func_00130D50(&D_0051A6A8);
    }
}
