// func_001A0560 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (products computed into float temps inline from the globals).

// from build/vt\try_func_001A0560_best.cpp
// func_001A0560 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_001A0560;
struct UnkStruct_001A0560_6;
struct UnkStruct_001A0560_7;
struct UnkStruct_001A0560_e0;
struct UnkStruct_D_004E105C;
struct UnkStruct_D_004E1060;
struct UnkStruct_D_00665EC0;
struct UnkStruct_D_00665EC4;

struct UnkStruct_001A0560_e0 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_D_00665EC0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665EC4 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E105C {
    float field_0;
};

struct UnkStruct_D_004E1060 {
    float field_0;
};

struct UnkStruct_001A0560_6 {
    int field_0;
    float field_4;
    float field_8;
    float field_C;
    unsigned char pad_10[0x28];
    float field_38;
    float field_3C;
};

struct UnkStruct_001A0560_7 {
    unsigned char pad_0[0x8];
    float field_8;
    float field_C;
    u_long128 field_10;
};

struct UnkStruct_001A0560 {
    float field_0;
    int field_4;
    int field_8;
    int field_C;
    unsigned char pad_10[0x18];
    UnkStruct_001A0560_7 * field_28;
    unsigned char pad_2C[0x14];
    UnkStruct_001A0560_e0 * field_40;
    unsigned char pad_44[0x14];
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
};

extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_00665EC4 D_00665EC4;
extern UnkStruct_D_004E105C D_004E105C;
extern UnkStruct_D_004E1060 D_004E1060;

extern "C" void Destruct__10CGt2dFrameFv(void *);  // CGt2dFrame::Destruct()
extern "C" void Prepare__10CGt2dSceneFv(void *);  // CGt2dScene::Prepare()

extern "C" void func_001A0560(UnkStruct_001A0560 * self)
{
    UnkStruct_001A0560_6 local;
    UnkStruct_001A0560_7 * t0 = self->field_28;
    self->field_58 = 0;
    self->field_5C = 0;
    self->field_60 = 0;
    if (self->field_64 != 0) {
        for (int i = 0; (i < 18); i++) {
            self->field_40[i].field_C = 0;
        }
        int t1 = self->field_64;
        if (t1 != 0) {
            Destruct__10CGt2dFrameFv((void *)t1);
            self->field_64 = 0;
        }
    }
    Prepare__10CGt2dSceneFv(((char *)self + 0x14));
    float a = D_004E105C.field_0 * (float)D_00665EC0.field_0;
    float b = D_004E1060.field_0 * (float)D_00665EC4.field_0;
    local.field_0 = 0x3F000000;
    local.field_C = 1.0f;
    local.field_4 = 0.5f;
    local.field_8 = 0.5f;
    u_long128 t6 = *(u_long128 *)&local.field_0;
    t0->field_8 = a;
    t0->field_C = b;
    t0->field_10 = t6;
    local.field_38 = a;
    self->field_0 = -1.0f;
    local.field_3C = b;
    self->field_4 = 0;
    self->field_8 = 5;
    self->field_C = 6;
}
