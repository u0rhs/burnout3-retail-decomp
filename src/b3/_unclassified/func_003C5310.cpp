// func_003C5310 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bool a = X != 0 && !(Y != 0); bool b = a != false, else field_48 != 0; switch assigns v6 = 0/1/2 per case (MWCC reuses the compare register) with int v6 and int param; phantom vfunc_C arg dropped (slot 0xC is Release())).

class CB3InputManager;
struct UnkStruct_003C5310;
struct UnkStruct_003C5310_e0;
struct UnkStruct_D_004F6061;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_01E89518;
struct UnkStruct_D_01E89538;
struct UnkStruct_D_01E8953C;
struct UnkStruct_D_01E89614;
struct UnkStruct_D_01E89788;
struct UnkStruct_D_01E898A4;
struct UnkStruct_D_01E8F09A;
struct UnkStruct_D_01E8F1CC;
struct UnkStruct_D_01E8F294;
struct UnkStruct_D_01E90424;
struct UnkStruct_D_01E91C3D;
struct UnkStruct_D_01ECDA08;
struct UnkStruct_D_01ECDAB8;
struct UnkStruct_D_01ECDACF;

struct UnkStruct_003C5310_e0 {
    unsigned char pad_0[0x12C];
};

class CB3InputManager {
public:
    int GetMenuConfirm(signed char);

    UnkStruct_003C5310_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_D_01E8F09A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8F294 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898A4 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E91C3D {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8953C {
    short field_0;
    unsigned char pad_2[0xE];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89538 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89788 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();  // [L] slot 0xC of __vt__19CB3HelpBarComponent is Release() (no args)
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89614 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8F1CC {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECDAB8 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECDACF {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECDA08 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F6061 {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89518 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C5310 {
    unsigned char pad_0[0x28];
    int field_28;
    unsigned char pad_2C[0x1C];
    unsigned char field_48;
    unsigned char pad_49[0x4];
    unsigned char field_4D;
};

extern UnkStruct_D_01E8F09A D_01E8F09A;
extern UnkStruct_D_01E8F294 D_01E8F294;
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E898A4 D_01E898A4;
extern UnkStruct_D_01E91C3D D_01E91C3D;
extern UnkStruct_D_01E8953C D_01E8953C;
extern UnkStruct_D_01E89538 D_01E89538;
extern UnkStruct_D_01E89788 D_01E89788;
extern UnkStruct_D_01E89614 D_01E89614;
extern UnkStruct_D_01E8F1CC D_01E8F1CC;
extern UnkStruct_D_01ECDAB8 D_01ECDAB8;
extern UnkStruct_D_01ECDACF D_01ECDACF;
extern UnkStruct_D_01ECDA08 D_01ECDA08;
extern UnkStruct_D_004F6061 D_004F6061;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E89518 D_01E89518;

extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short*, bool, float);  // CB3HelpBarComponent::Prepare(const unsigned short*,bool,float)
extern "C" int func_00271A00(void *, int);
extern "C" void func_0031A840(void *, int, int);
extern "C" void func_003C4E20(UnkStruct_003C5310 *, void *);

// 0x003C5310
extern "C" void func_003C5310(UnkStruct_003C5310 * self)
{
    bool a = D_01E8F09A.field_0 != 0 && !(D_01E8F294.field_0 != 0);
    bool b = a != false;
    if (!b) {
        b = self->field_48 != 0;
    }
    int t0 = D_01E90424.field_0;
    D_01E898A4.field_0 = b;
    if (t0 != 5) {
        return;
    }
    unsigned char t1 = D_01E91C3D.field_0;
    if (self->field_48 != t1) {
        self->field_48 = t1;
        if (self->field_48 != 0) {
            D_01E8953C.field_0 = 214;
            int r0 = func_00271A00(&D_0051BA44, 214);
            Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short*)r0, 0, 80.0f);
        } else {
            D_01E89538.field_0 = self->field_28;
            ((UnkStruct_D_01E89788 *)&D_01E89788)->vfunc_C();
        }
        D_01E89614.field_0 = self->field_48;
    }
    if (self->field_48 != 0) {
        return;
    }
    if (a != false) {
        if (D_004F50C0.GetMenuConfirm(0) != 0) {
            D_01E8F1CC.field_0 = 600.0f;
        }
        return;
    }
    if (self->field_4D != 0) {
        int v6;
        switch (D_01ECDAB8.field_0) {
        case 0:
            v6 = 0;
            break;
        case 1:
            v6 = 1;
            break;
        case 2:
            v6 = 2;
            break;
        default:
            v6 = D_01ECDACF.field_0;
            break;
        }
        func_0031A840(&D_01E89518, v6, D_01ECDA08.field_0);
        self->field_4D = 0;
    }
    func_003C4E20(self, ((char *)&D_004F50C0.field_0[D_004F6061.field_0] + 0xD48));
}
