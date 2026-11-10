// func_0045A850 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (element sub-struct at +0x64 held in one pointer; && / else-if chains; StartLeadOut keeps a2=0 (callee reads a2)).

// lifter variant 0
// func_0045A850 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGt2dObjectTable;
class CB3MenuComponentSelectionData;
enum EB3MenuFlowFSMEvents {};

class CB3HUDSoundManager;
class CB3TableSelectComponent;
struct UnkStruct_0045A850;
struct UnkStruct_0045A850_e0;
struct UnkStruct_D_004F50C0;
struct UnkStruct_D_004F6061;
struct UnkStruct_D_01E3D45B;
struct UnkStruct_D_01E3D4B4;
struct UnkStruct_D_01E8D45C;
struct UnkStruct_D_01E8D49A;
struct UnkStruct_D_01E90240;

class CB3TableSelectComponent {
public:
    void Prepare(int, CGt2dObjectTable*, const CB3MenuComponentSelectionData*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3HUDSoundManager {
public:
    void FESelect();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F6061 {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D49A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D45C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3D45B {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};



struct UnkStruct_D_01E3D4B4 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0045A850 {
    unsigned char pad_0[0xCA4];
    unsigned char field_CA4;
};

extern UnkStruct_D_004F6061 D_004F6061;
extern UnkStruct_D_01E8D49A D_01E8D49A;
extern UnkStruct_D_01E8D45C D_01E8D45C;
extern UnkStruct_D_01E3D45B D_01E3D45B;
extern UnkStruct_D_004F50C0 D_004F50C0;
extern CB3TableSelectComponent D_01E8D490;
extern CB3HUDSoundManager D_01E7A800;
extern UnkStruct_D_01E3D4B4 D_01E3D4B4;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);  // CB3HUDSoundManager::FEVerticalMove(), passed 1 more argument(s) [G]
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void func_00459910(UnkStruct_0045A850 *);
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" int func_0026C8B0(void *, unsigned char);
extern "C" void func_0045A9F0(UnkStruct_0045A850 *);

// [G] sub-struct at element +0x64: retail holds &D_004F50C0.field_CE4[i] + 0x64 in s0 (addiu 0xD48).
struct UnkStruct_0045A850_sub {
    unsigned char pad_0[0x2C];
    short field_2C;
    unsigned char pad_2E[0xA];
    short field_38;
    unsigned char pad_3A[0xA];
    short field_44;
    unsigned char pad_46[0x16];
    short field_5C;
    unsigned char pad_5E[0x2E];
    short field_8C;
};
struct UnkStruct_0045A850_e0 {
    unsigned char pad_0[0x64];
    UnkStruct_0045A850_sub field_64;
    unsigned char pad_F2[0x3A];
};

struct UnkStruct_D_004F50C0 {
    unsigned char pad_0[0xCE4];
    UnkStruct_0045A850_e0 field_CE4[1];  // [G] element count unknown
};
// 0x0045A850
extern "C" void func_0045A850(UnkStruct_0045A850 * self)
{
    UnkStruct_0045A850_sub * e = &D_004F50C0.field_CE4[D_004F6061.field_0].field_64;
    if (D_01E8D49A.field_0 == 0) {
        D_01E8D490.Prepare(1, (CGt2dObjectTable*)D_01E8D45C.field_0, (const CB3MenuComponentSelectionData*)((char *)self + 0xCA4));
    }
    unsigned char t1 = D_01E3D45B.field_0;
    D_01E3D45B.field_0 = 0;
    if (t1 != 0) {
        func_00459910(self);
    }
    if (e->field_2C != 0 && func_00319360(((char *)self + 0xCA4)) != 0) {
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
    }
    if (e->field_38 != 0 && func_00319330(((char *)self + 0xCA4)) != 0) {
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
    } else if (e->field_44 != 0) {
        D_01E7A800.FESelect();
        strncpy((char *)self + 0x4, (const char *)func_0026C8B0(&D_01E3D4B4, self->field_CA4), 16);
        func_0045A9F0(self);
    }
    if (e->field_5C != 0) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
    } else if (e->field_8C != 0) {
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)36, 0);
    }
}
