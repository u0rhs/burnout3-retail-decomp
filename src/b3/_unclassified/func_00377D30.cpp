// func_00377D30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (early returns for confirm/back; up/down/scroll tail in a static inline whose returns join at its end).

enum EB3MenuFlowFSMEvents {};

class CB3InputManager;
struct UnkStruct_D_01E90240;

class CB3InputManager {
public:
    int GetMenuConfirm(signed char);
    int GetMenuBack(signed char);
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)
extern "C" void func_003787D0(void *);
extern "C" int func_0022CBE0(void *, int);
extern "C" int func_00319330(void *);
extern "C" int func_00319360(void *);

// [G] placeholder inline: the up/down/scroll handling (its early returns go to the inline's end, retail's block layout).
static inline void func_00377D30_inl1(int n0)
{
    if (D_004F50C0.GetMenuUp(0) != 0 && func_00319360((void *)(n0 + 0xF06)) != 0) return;
    if (D_004F50C0.GetMenuDown(0) != 0 && func_00319330((void *)(n0 + 0xF06)) != 0) return;
    if (func_0022CBE0(&D_004F50C0, 0) != 0) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)36, false);
    }
}

// 0x00377D30
extern "C" void func_00377D30(void *n0_)
{
    int n0 = (int)n0_;
    if (D_004F50C0.GetMenuConfirm(0) != 0) {
        func_003787D0((void *)(n0));
        return;
    }
    if (D_004F50C0.GetMenuBack(0) != 0) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, false);
        return;
    }
    func_00377D30_inl1(n0);
}
