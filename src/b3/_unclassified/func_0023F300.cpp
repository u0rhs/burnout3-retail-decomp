// func_0023F300 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (tick clamp as ternary into unsigned short (a217)).

// 8 instrs (105 vs 107): v7 as merged && condition, rem computed before the 2nd GetPlayerIndexByID call, last section as block form (gets the fall-off 'b; ld ra' shape) all match; left: the clamped tick (unsigned short, 0xFFFF->0) lands in a0 with andi after the mult, retail keeps it in v1 with andi before mult and 2 nops after div. Tried int/unsigned short/inline getter/separate num+den temps/t0,t1 locals: all identical

// lifter variant 0
// func_0023F300 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtNetworkPlayerManager;
struct UnkStruct_0023F300;
struct UnkStruct_0023F300_5;
struct UnkStruct_D_004E2A14;
struct UnkStruct_D_004F50A0;
struct UnkStruct_D_01E654A0;

class CGtNetworkPlayerManager {
public:
    int GetPlayerIndexByID(int);

    unsigned char pad_0[0x28];
    int field_28;
};

struct UnkStruct_D_01E654A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E2A14 {
    unsigned short field_0;
};

struct UnkStruct_D_004F50A0 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0023F300_5 {
    float field_0;
};

struct UnkStruct_0023F300 {
    unsigned char pad_0[0xC];
    CGtNetworkPlayerManager * field_C;
    unsigned char pad_10[0x4A0];
    unsigned char field_4B0;
    unsigned char pad_4B1[0x10F];
    unsigned char field_5C0;
    unsigned char field_5C1;
    unsigned char pad_5C2[0x2];
    float field_5C4;
    unsigned char pad_5C8[0x118];
    int field_6E0;
    unsigned char pad_6E4[0x4808];
    float field_4EEC;
    unsigned char pad_4EF0[0x4];
    short field_4EF4;
};

extern UnkStruct_D_01E654A0 D_01E654A0;
extern UnkStruct_D_004E2A14 D_004E2A14;
extern UnkStruct_D_004F50A0 D_004F50A0;
extern CGtNetworkPlayerManager D_01E32AE0;

extern "C" int func_0022FBB0(UnkStruct_0023F300 *);
extern "C" void func_002B70C0(void *, float);
extern "C" int func_002B7080(void *, UnkStruct_0023F300_5 *);
extern "C" void func_002B7030(void *, float);
extern "C" int func_002B6FF0(void *, UnkStruct_0023F300_5 *);

// 0x0023F300
extern "C" void func_0023F300(UnkStruct_0023F300 * self)
{
    UnkStruct_0023F300_5 local;
    if (self->field_4B0 == 0) {
        return;
    }
    int v7;
    if (self->field_5C0 != 0 && self->field_5C1 == 0 && self->field_6E0 != 0 && D_01E654A0.field_0 != -1) {
        v7 = 60;
    } else {
        v7 = 10;
    }
    int r0 = func_0022FBB0(self);
    self->field_C->GetPlayerIndexByID(r0);
    unsigned short v10 = D_004E2A14.field_0 == 65535 ? 0 : D_004E2A14.field_0;
    int rem = v10 % (v7 * self->field_C->field_28);
    int r2 = D_01E32AE0.GetPlayerIndexByID(r0);
    if (rem == v7 * r2) {
        func_002B70C0(((char *)self + 0xBF4), D_004F50A0.field_0);
    }
    if ((func_002B7080(((char *)self + 0xC08), &local) & 255) != 0) {
        unsigned short v13 = D_004E2A14.field_0;
        if (D_004E2A14.field_0 == 65535) {
            v13 = 0;
        }
        self->field_4EF4 = v13;
        self->field_4EEC = D_004F50A0.field_0;
        func_002B7030(((char *)self + 0xC1C), local.field_0);
    }
    if ((func_002B6FF0(((char *)self + 0xC30), &local) & 255) != 0) {
        unsigned short v16 = D_004E2A14.field_0;
        if (D_004E2A14.field_0 == 65535) {
            v16 = 0;
        }
        self->field_4EF4 = v16;
        self->field_4EEC = D_004F50A0.field_0;
        float t2 = D_004F50A0.field_0;
        float t3 = local.field_0;
        self->field_5C4 = (1000.0f * (t2 - t3));
    }
}
