// func_004328C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (menu input handler: collapsed lifter nesting into (Up&&f360)||(Down&&f330) chain; explicit returns after Back/VerticalMove arms; StartLeadOut a2 and FEVerticalMove a1 extra args).

// func_004328C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3MenuFlowFSMEvents {};

class CB3HUDSoundManager;
class CB3HardCodedCrashStageList;
class CB3InputManager;
struct UnkStruct_004328C0;
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

class CB3HardCodedCrashStageList {
public:
    static unsigned long GetCrashStageTrackID(unsigned long);
};

class CB3HUDSoundManager {
public:
    void FEVerticalMove();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004328C0 {
    unsigned char pad_0[0x8];
    unsigned long field_8;
    unsigned long field_10;
    int field_18;
    unsigned char pad_1C[0x4];
    int field_20;
    unsigned char pad_24[0xCC];
    unsigned long field_F0[1];  // [G] element count unknown
    unsigned char pad_F8[0xF0];
    unsigned long field_1E8[1];  // [G] element count unknown
    unsigned char pad_1F0[0x4C8];
    int field_6B8;
    int field_6BC;
    int field_6C0;
};

extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern CB3HUDSoundManager D_01E7A800;

extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents)
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" void func_00432560(UnkStruct_004328C0 *);

extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);
// 0x004328C0
extern "C" void func_004328C0(UnkStruct_004328C0 * self)
{
    if (D_004F50C0.GetMenuConfirm(0) != 0) {
        if (self->field_20 != 3) {
            self->field_8 = self->field_F0[self->field_6B8];
            self->field_10 = 0;
            self->field_18 = self->field_6C0;
        } else {
            self->field_10 = self->field_1E8[self->field_6BC];
            self->field_8 = CB3HardCodedCrashStageList::GetCrashStageTrackID(self->field_10);
            self->field_18 = 0;
        }
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0, 0);
        return;
    }
    if (D_004F50C0.GetMenuBack(0) != 0) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        return;
    } else if ((D_004F50C0.GetMenuUp(0) != 0 && func_00319360((char *)self + 0x24) != 0)
            || (D_004F50C0.GetMenuDown(0) != 0 && func_00319330((char *)self + 0x24) != 0)) {
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
        return;
    } else if (D_004F50C0.GetMenuLeft(0) != 0 || D_004F50C0.GetMenuRight(0) != 0) {
        func_00432560(self);
    }
}
