// func_003C5EE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (last block: if (field_4 != r) { store; SetString(); } instead of early return + trailing return; call result tested in place).

// func_003C5EE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3MenuFlowFSMEvents {};

class CB3InputManager;
struct UnkStruct_003C5EE0;
struct UnkStruct_003C5EE0_3;
struct UnkStruct_003C5EE0_4;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_01E89788;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E90424;

class CB3InputManager {
public:
    int GetMenuConfirm(signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_003C5EE0_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C5EE0_3 {
    unsigned char pad_0[0x1B4];
    UnkStruct_003C5EE0_4 * field_1B4;
};

struct UnkStruct_003C5EE0_4 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
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
    virtual int vfunc_4C();
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89788 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C5EE0 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char field_8;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E89788 D_01E89788;

extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short*, bool, bool, float);  // CB3HelpBarComponent::SetString(const unsigned short*,bool,bool,float)

extern "C" void func_003C5EE0(UnkStruct_003C5EE0 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    if (D_004F50C0.GetMenuConfirm(0) != 0) {
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 0);
        return;
    }
    if (self->field_8 != 0) {
        int r2 = D_0051BA88.field_0->field_1B4->vfunc_4C();
        if (self->field_4 != r2) {
            self->field_4 = r2;
            SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short*)self->field_4, 1, 0, 140.0f);
        }
    }
}
