// func_003F2350 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (row-check loop as a bool static inline (called twice), early returns per menu input, if (flag) X; return; for the parked then-blocks, unsigned prompts passed as unsigned long).

// func_003F2350 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3MenuFlowFSMEvents {};

class CB3InputManager;
struct UnkStruct_003F2350;
struct UnkStruct_D_0051BF9C;
struct UnkStruct_D_01E7A800;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E8E5D8;
struct UnkStruct_D_01E8E7A0;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E90424;

class CB3InputManager {
public:
    int GetMenuBack(signed char);
    int GetMenuConfirm(signed char);
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8E7A0 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BF9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8E5D8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E7A800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003F2350 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    bool field_C;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E8E7A0 D_01E8E7A0;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E8E5D8 D_01E8E5D8;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern UnkStruct_D_01E89800 D_01E89800;

extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);  // CB3HUDSoundManager::FEVerticalMove(), passed 1 more argument(s) [G]
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);  // [G] first parameter 64-bit: retail zero-extends the mask (dsll32/dsrl32) although the mangled name says Ui; matched siblings declare it the same way
extern "C" void func_003A5CC0(void *);
extern "C" void func_003A5C70(void *);
extern "C" int func_0013A630(void *, int);

// [G] inlined helper (no name known): whether all five entries of the current row pass func_0013A630
static inline bool func_003F2350_inl1(UnkStruct_003F2350 * self)
{
    int t = D_0051BF9C.field_0;
    for (int i = 0; i < 5; i++) {
        if (!func_0013A630((void *)(t), i + self->field_4 * 5)) {
            return false;
        }
    }
    return true;
}

// 0x003F2350
extern "C" void func_003F2350(UnkStruct_003F2350 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    switch (self->field_8) {
    case 1:
        if (!D_004F50C0.GetMenuBack(0)) {
            return;
        }
        self->field_8 = 0;
        if (self->field_C) {
            ((UnkStruct_D_01E8E7A0 *)&D_01E8E7A0)->vfunc_C();
        }
        return;
    case 0:
        if (D_004F50C0.GetMenuConfirm(0)) {
            if (self->field_C) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 0);
            }
            return;
        } else if (D_004F50C0.GetMenuBack(0)) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            return;
        } else {
            if (D_004F50C0.GetMenuUp(0)) {
                func_003A5CC0(&D_01E8E5D8);
                self->field_4--;
                if (self->field_4 < 0) {
                    self->field_4 = 0;
                } else {
                    FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
                }
            } else if (D_004F50C0.GetMenuDown(0)) {
                func_003A5C70(&D_01E8E5D8);
                self->field_4++;
                if (self->field_4 > 3) {
                    self->field_4 = 3;
                } else {
                    FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
                }
            }
            self->field_C = func_003F2350_inl1(self);
            unsigned int p = 0x101;
            if (func_003F2350_inl1(self)) {
                p |= 0x10;
            }
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, p, 3);
        }
        break;
    }
}
