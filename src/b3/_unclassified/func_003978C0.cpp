// func_003978C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (if/else-if input chain with a shared colour store at the end; &D_01E90240 as a const pointer (s1); ternary clamp to 9; row clamp through a short local with both arms storing; element pointers for the u_long128 colour stores; prompt value loaded before the first store).

// lifter variant 0
// func_003978C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

typedef unsigned int u_long128 __attribute__((mode(TI)));

enum EB3MenuFlowFSMEvents {};

class CB3InputManager;
struct UnkStruct_003978C0;
struct UnkStruct_003978C0_15;
struct UnkStruct_003978C0_16;
struct UnkStruct_003978C0_17;
struct UnkStruct_003978C0_2;
struct UnkStruct_003978C0_4;
struct UnkStruct_003978C0_e1;
struct UnkStruct_D_01E3CD44;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E89810;
struct UnkStruct_D_01E8D450;
struct UnkStruct_D_01E8D45A;
struct UnkStruct_D_01E8D490;
struct UnkStruct_D_01E8D49A;
struct UnkStruct_D_01E8EAF8;
struct UnkStruct_D_01E8EB02;
struct UnkStruct_D_01E90240;
struct UnkStruct_func_00396860;

class CB3InputManager {
public:
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);
    int GetMenuConfirm(signed char);
    int GetMenuBack(signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3CD44 {
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
    virtual int vfunc_48();
    virtual void vfunc_4C(int, void *, UnkStruct_003978C0 *);
    virtual void vfunc_50(int, int, void *, UnkStruct_003978C0 *);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003978C0_2 {
    unsigned char pad_0[0x4C];
    int field_4C;
    int field_50;
};

struct UnkStruct_003978C0_4 {
    short field_0;
};

struct UnkStruct_D_01E89810 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    u_long128 field_0;
    u_long128 field_10;
};

struct UnkStruct_003978C0_e1 {
    unsigned char pad_0[0x40];
    u_long128 field_40;
};

struct UnkStruct_D_01E8D45A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D450 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D49A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D490 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8EB02 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8EAF8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003978C0_15 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_003978C0_16 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_003978C0_17 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_func_00396860 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003978C0 {
    unsigned char pad_0[0x4];
    signed char field_4;
    unsigned char pad_5[0x1F];
    short field_24;
    short field_26;
    unsigned short field_28;
    short field_2A;
    unsigned char pad_2C[0x114];
    UnkStruct_003978C0_e1 field_140[1];  // [G] element count unknown
    unsigned char pad_190[0x2A0];
    UnkStruct_003978C0_4 * field_430[1];  // [G] element count unknown
    unsigned char pad_434[0x2C];
    int field_460;
    int field_464;
    int field_468;
};

extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E89810 D_01E89810;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E8D45A D_01E8D45A;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_D_01E8D49A D_01E8D49A;
extern UnkStruct_D_01E8D490 D_01E8D490;
extern UnkStruct_D_01E8EB02 D_01E8EB02;
extern UnkStruct_D_01E8EAF8 D_01E8EAF8;
extern UnkStruct_func_00396860 func_00396860;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3InputManager D_004F50C0;

extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);  // CB3PromptsComponent::SetCurrentPrompts(unsigned int,unsigned int)
extern "C" void GetSelectedLobbyPlayerCallback__22CB3OnlineOpenLobbyPageFPcibiiiPcbPv(char*, int, bool, int, int, int, char*, bool, void*);  // CB3OnlineOpenLobbyPage::GetSelectedLobbyPlayerCallback(char*,int,bool,int,int,int,char*,bool,void*), its address taken
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void func_00396A90(UnkStruct_003978C0 *);
extern "C" int func_0022CBE0(void *, int);
extern "C" void func_00396E50(UnkStruct_003978C0 *);
extern "C" int func_00319330(unsigned short *);
extern "C" int func_00319360(unsigned short *);

// 0x003978C0
extern "C" void func_003978C0(UnkStruct_003978C0 * self)
{
    UnkStruct_D_01E90240 * const colours = &D_01E90240;
    int count = ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_48();
    if (self->field_460 >= count) {
        self->field_460 = count - 1;
    }
    self->field_468 = 0;
    self->field_464 = -1;
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_50(self->field_460, self->field_460 + 8, &func_00396860, self);
    for (int i = self->field_468; i < 9; i++) {
        self->field_430[i]->field_0 = 0;
    }
    int n = count - self->field_460;
    n = (n < 9) ? n : 9;
    unsigned short t = self->field_28;
    if (t < n) {
        self->field_28 = t;
        self->field_2A = n;
    } else {
        self->field_28 = n - 1;
        self->field_2A = n;
    }
    self->field_24 = self->field_460 + self->field_28;
    self->field_26 = count;
    unsigned long prompts = D_01E89810.field_0;
    UnkStruct_003978C0_e1 * e0 = &self->field_140[self->field_28];
    e0->field_40 = colours->field_0;
    SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, prompts | 4, 3);
    if (D_004F50C0.GetMenuUp(0) != 0) {
        if (func_00319360(&self->field_28) != 0) {
            return;
        }
        if (self->field_460 > 0) {
            self->field_460--;
            return;
        }
    } else if (D_004F50C0.GetMenuDown(0) != 0) {
        if (func_00319330(&self->field_28) != 0) {
            return;
        }
        if (self->field_28 < count - self->field_460 - 1) {
            self->field_460++;
            return;
        }
    } else if (D_004F50C0.GetMenuConfirm(0) != 0) {
        self->field_4 = 0;
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_4C(self->field_460 + self->field_28, (void *)&GetSelectedLobbyPlayerCallback__22CB3OnlineOpenLobbyPageFPcibiiiPcbPv, self);
        if (self->field_4 != 0) {
            if (D_01E8D45A.field_0 != 0) {
                ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();
            }
            if (D_01E8D49A.field_0 != 0) {
                ((UnkStruct_D_01E8D490 *)&D_01E8D490)->vfunc_C();
            }
            if (D_01E8EB02.field_0 != 0) {
                ((UnkStruct_D_01E8EAF8 *)&D_01E8EAF8)->vfunc_C();
            }
            func_00396A90(self);
        }
    } else if (D_004F50C0.GetMenuBack(0) != 0) {
        if (D_01E8D45A.field_0 != 0) {
            ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();
        }
        if (D_01E8D49A.field_0 != 0) {
            ((UnkStruct_D_01E8D490 *)&D_01E8D490)->vfunc_C();
        }
        if (D_01E8EB02.field_0 != 0) {
            ((UnkStruct_D_01E8EAF8 *)&D_01E8EAF8)->vfunc_C();
        }
        func_00396E50(self);
    } else if (func_0022CBE0(&D_004F50C0, 0) != 0) {
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)36, 0);
        return;
    }
    UnkStruct_003978C0_e1 * e = &self->field_140[self->field_28];
    e->field_40 = colours->field_10;
}
