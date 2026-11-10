// func_003C4C70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (early return for ==1; (t < 0 || net) merged condition; vfunc result in an int local before the || ; D_01E898F2 == 0 arm first; int stack local).

// func_003C4C70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3MenuFlowFSMEvents {};

struct UnkStruct_003C4C70;
struct UnkStruct_003C4C70_1;
struct UnkStruct_003C4C70_5;
struct UnkStruct_003C4C70_6;
struct UnkStruct_003C4C70_8;
struct UnkStruct_D_004F509C;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E898F2;
struct UnkStruct_D_01E90240;

struct UnkStruct_D_0051BA88 {
    UnkStruct_003C4C70_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C4C70_1 {
    unsigned char pad_0[0x1B4];
    UnkStruct_003C4C70_5 * field_1B4;
};

struct UnkStruct_D_01E898E8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F509C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C4C70_5 {
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
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual int vfunc_9C();
};

struct UnkStruct_003C4C70_6 {
    int field_0;
};

struct UnkStruct_D_01E898F2 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C4C70_8 {
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
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual int vfunc_9C();
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C4C70 {
    unsigned char pad_0[0x40];
    float field_40;
    int field_44;
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_0051BA44 D_0051BA44;

extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::AmIHost()
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_003904F0(UnkStruct_003C4C70_5 *);
extern "C" void func_00390550(UnkStruct_003C4C70_5 *);
extern "C" int func_0026C8C0(void *);
extern "C" int func_00271A00(void *, int);
extern "C" void *func_001A3AA0(void *, void *, int *);
extern "C" void func_0032B3D0(void *, int);
extern "C" void func_0032CF60(void *, int, void *, int, int);

// 0x003C4C70
extern "C" void func_003C4C70(UnkStruct_003C4C70 * self)
{
    int local;
    if (func_0032B2C0(&D_01E898E8, 0, 1) == 1) {
        func_003904F0(D_0051BA88.field_0->field_1B4);
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)69, 0);
        return;
    }
    {
        float t = self->field_40 - D_004F509C.field_0;
        self->field_40 = t;
        if (t < 0.0f || func_0026C8C0(&D_01E32AE0) != 0) {
            int r = D_0051BA88.field_0->field_1B4->vfunc_9C();
            if (r == 5 || AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) {
                func_00390550(D_0051BA88.field_0->field_1B4);
            }
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)65, 0);
        } else {
            int t2 = self->field_44;
            local = ((int)self->field_40) + 1;
            func_001A3AA0((void *)(t2), (void *)(func_00271A00(&D_0051BA44, 315)), &local);
            if (D_01E898F2.field_0 == 0) {
                func_0032CF60(&D_01E898E8, 3, (void *)(self->field_44), 1, 0);
            } else {
                func_0032B3D0(&D_01E898E8, self->field_44);
            }
        }
    }
}
