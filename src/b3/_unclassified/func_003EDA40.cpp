// func_003EDA40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3MenuFlowFSMEvents {};

class CB3HUDSoundManager;
class CB3OnScreenKeyboardComponent;
struct UnkStruct_D_0051BF9C;
struct UnkStruct_D_01E8CA94;
struct UnkStruct_D_01E90240;

class CB3HUDSoundManager {
public:
    void FESelect();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnScreenKeyboardComponent {
public:
    void Show(bool, bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8CA94 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BF9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01E8CA94 D_01E8CA94;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern CB3HUDSoundManager D_01E7A800;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" int Length__10CGtUnicodeFPCUs(int);
extern "C" void func_0013B740(int, int);

// 0x003EDA40
extern "C" void func_003EDA40(void *a0 /* passed by every caller, not read here */)
{
    int t0 = D_01E8CA94.field_0;
    int r0 = Length__10CGtUnicodeFPCUs(t0);
    if (r0 == 0) return;
    func_0013B740(D_0051BF9C.field_0, t0);
    D_01E7A800.FESelect();
    D_01E899C0.Show(0, 0);
    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
}
