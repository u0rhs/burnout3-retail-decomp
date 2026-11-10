// func_003F3400 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (controller record pointer local, two guarded checks merged with || into one return, toggle through a bool local passed !v to the int parameter (as matched SetOptionText__26CB3VOptionsSelectComponentFiUi), port initialised before the state check).

// func_003F3400 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3MenuFlowFSMEvents {};

class CB3InputManager;
class CB3MenuFlowFSM;
struct UnkStruct_003F3400;
struct UnkStruct_003F3400_e1;
struct UnkStruct_003F3400_e3;
struct UnkStruct_D_0051BA94;
struct UnkStruct_D_01E65499;
struct UnkStruct_D_01E7A800;
struct UnkStruct_D_01E8961C;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E90424;

struct UnkStruct_003F3400_e3 {
    unsigned char pad_0[0x14];
    short field_14;
    unsigned char pad_16[0xA];
    short field_20;
    unsigned char pad_22[0xA];
    short field_2C;
    unsigned char pad_2E[0xA];
    short field_38;
    unsigned char pad_3A[0x16];
    short field_50;
    unsigned char pad_52[0xA];
    short field_5C;
    unsigned char pad_5E[0xCE];
};

struct UnkStruct_003F3400_e1 {
    unsigned char pad_0[0x78];
    short field_78;
    unsigned char pad_7A[0xA];
    short field_84;
    unsigned char pad_86[0xA];
    short field_90;
    unsigned char pad_92[0xA];
    short field_9C;
    unsigned char pad_9E[0x16];
    short field_B4;
    unsigned char pad_B6[0xA];
    short field_C0;
    unsigned char pad_C2[0x6A];
};

class CB3InputManager {
public:
    int GetLockedPlayersPort(signed char);

    unsigned char pad_0[0xD48];
    UnkStruct_003F3400_e3 field_D48[4];  // [G] element count unknown
};

class CB3MenuFlowFSM {
public:
    void ApplyEvent(unsigned int, void*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E65499 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA94 {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8961C {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E7A800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003F3400 {
    unsigned char pad_0[0x4];
    unsigned short field_4;
    unsigned char pad_6[0x2A];
    int field_30;
    unsigned char field_34;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E65499 D_01E65499;
extern UnkStruct_D_0051BA94 D_0051BA94;
extern signed char D_004F6061[];  // [G] element count unknown
extern CB3InputManager D_004F50C0;
extern signed char D_004F506C[];  // [G] element count unknown
extern UnkStruct_D_01E8961C D_01E8961C;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern CB3MenuFlowFSM D_01EA2970;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);  // CB3HUDSoundManager::FEVerticalMove(), passed 1 more argument(s) [G]
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, unsigned short, int);
extern "C" int func_0012FB10(void *, int);

// 0x003F3400
extern "C" void func_003F3400(UnkStruct_003F3400 * self)
{
    signed char port = 0;
    if (D_01E90424.field_0 != 5) {
        return;
    }
    if (self->field_30 == 1 && D_01E65499.field_0 == 0) {
        port = D_0051BA94.field_0;
    }
    UnkStruct_003F3400_e3 * m = &D_004F50C0.field_D48[D_004F6061[port]];
    if ((m->field_2C != 0 && func_00319360((char *)self + 0x4)) || (m->field_38 != 0 && func_00319330((char *)self + 0x4))) {
        return;
    }
    if (m->field_14 != 0 || m->field_20 != 0) {
        int idx;
        if (self->field_30 == 1) {
            idx = (signed char)D_004F50C0.GetLockedPlayersPort(port);
        } else {
            idx = self->field_4;
        }
        signed char * p = &D_004F506C[idx];
        bool v = !*p;
        *p = v;
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, self->field_4, !v);
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
        D_01EA2970.ApplyEvent(75, 0);
        return;
    }
    if (m->field_50 != 0) {
        self->field_34 = 1;
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        return;
    }
    if (func_0012FB10(m, 1)) {
        if (self->field_30 == 0) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        } else {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)6, 1);
        }
        return;
    }
    if (m->field_5C != 0) {
        self->field_34 = 1;
        D_01EA2970.ApplyEvent(74, 0);
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        return;
    }
}
