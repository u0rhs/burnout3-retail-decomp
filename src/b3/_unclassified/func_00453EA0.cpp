// func_00453EA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (s313: clone of func_00424480 (simfind 0.80); case 2 written as goto blocks in retail order; a1=3 reused compare constant).

// func_00453EA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// s313: cloned from func_00424480 (simfind 0.80). Sibling notes: hand-finished from the lifted source (the 0..9 test is an && chain of != (a switch becomes a range check); virtual call through a cast pointer (the object form is devirtualised); accept test written as one !((confirm || start) && field_C) return; field_4 = 4 then break, not return).

// lifter variant 0
// func_00453EA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3BackgroundType {};
enum EB3MenuFlowFSMEvents {};

class CB3HUDSoundManager;
class CB3InputManager;
struct UnkStruct_00453EA0;
struct UnkStruct_00453EA0_4;
struct UnkStruct_D_0051A6A8;
struct UnkStruct_D_0051A870;
struct UnkStruct_D_0051A9A4;
struct UnkStruct_D_01E7A888;
struct UnkStruct_D_01E88A80;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E90424;

class CB3InputManager {
public:
    int GetMenuConfirm(signed char);
    int GetStartButton(bool, signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3HUDSoundManager {
public:
    void FESelect();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E88A80 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A9A4 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00453EA0_4 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_D_01E7A888 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A6A8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A870 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00453EA0 {
    unsigned char pad_0[0x4];
    int field_4;
    float field_8;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char field_E;
    unsigned char field_F;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_0051A9A4 D_0051A9A4;
extern UnkStruct_D_01E7A888 D_01E7A888;
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern UnkStruct_D_0051A870 D_0051A870;
extern CB3InputManager D_004F50C0;
extern CB3HUDSoundManager D_01E7A800;
extern UnkStruct_D_01E90240 D_01E90240;
struct UnkStruct_D_01E8FFF0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E8FFF0 D_01E8FFF0;

extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void ImmediateLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents);  // CB3MenuPageManager::ImmediateLeadOut(EB3MenuFlowFSMEvents)
extern "C" void func_003FA600(void *, int);
extern "C" int func_00130EE0(void *);
extern "C" int func_00130D50(void *);
extern "C" void func_0031D920(void *, float);
extern "C" int func_00324EE0(void *);
extern "C" void func_00130C70(void *);
extern "C" void func_00130D00(void *);
extern "C" int func_00461A30(void *);

// 0x00453EA0
extern "C" void func_00453EA0(UnkStruct_00453EA0 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    switch (self->field_4) {
    case 0:
        if (self->field_F == 0) {
            func_003FA600(&D_01E7A888, 3);
        }
        if (self->field_D == 0) {
            self->field_D = func_00130EE0(&D_0051A6A8);
        } else if (self->field_C == 0) {
            self->field_C = func_00130D50(&D_0051A6A8);
        }
        if (self->field_C == 0 || self->field_D == 0) {
            return;
        }
        self->field_4 = 1;
        break;
    case 1:
        ((UnkStruct_D_01E88A80 *)&D_01E88A80)->vfunc_C();
        Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)10);
        func_0031D920(&D_01E88A80, self->field_8);
        self->field_4 = 2;
        break;
    case 2:
        if (func_00324EE0(&D_0051A870) == 0) {
            if (D_004F50C0.GetMenuConfirm(0) == 0) goto start;
        e:
            if (self->field_E == 0) goto fblk;
            D_01E7A800.FESelect();
            self->field_4 = 4;
            break;
        fblk:
            if (self->field_F == 0) return;
            if (func_00461A30(&D_01E8FFF0) == 0) return;
            self->field_4 = 3;
            break;
        start:
            if (D_004F50C0.GetStartButton(1, 0) != 0) goto e;
            goto fblk;
        }
        self->field_4 = 3;
        break;
    case 4:
    case 3:
        ((UnkStruct_D_01E88A80 *)&D_01E88A80)->vfunc_C();
        func_00130C70(&D_0051A6A8);
        func_00130D00(&D_0051A6A8);
        func_003FA600(&D_01E7A888, 1);
        Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)4);
        if (self->field_4 == 3) {
            ImmediateLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2);
        } else {
            ImmediateLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0);
        }
        break;
    }
}
