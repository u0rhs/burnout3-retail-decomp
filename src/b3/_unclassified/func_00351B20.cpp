// func_00351B20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (added float p3 param (f12->f20) passed 4th (between p1 and &D_01E90240) to func_0033D380; const global ptr locals).

// func_00351B20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGt2dFrame;

struct UnkStruct_00351B20;
struct UnkStruct_00351B20_2;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_00665ED0;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_00351B20_2 {
    int field_0;
    int field_4;
    int field_8;
    float field_C;
    unsigned char pad_10[0x10];
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
};

struct UnkStruct_D_00665ED0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00351B20 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char field_A;
    unsigned char pad_B[0x5];
    u_long128 field_10;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    int field_30;
    int field_34;
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Prepare()
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" int func_00271A00(void *, int);
extern "C" void func_0033D380(void *, void *, void *, float, void *, void *, void *, void *);

// 0x00351B20
extern "C" int func_00351B20(UnkStruct_00351B20 * self, void *p0, void *p1, int p2, float p3)
{
    UnkStruct_00351B20_2 local;
    UnkStruct_D_01E90240 * const g1 = &D_01E90240;
    UnkStruct_D_01E903E0 * const g0 = &D_01E903E0;
    int t0 = g0->field_14;
    if (self->field_A == 0) {
        Prepare__20CB3MenuComponentBaseFv(self);
    }
    if (self->field_30 == 0) {
        self->field_30 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(g0, self->field_8 + 1, (void *)t0);
    }
    local.field_0 = 0;
    local.field_4 = 0;
    local.field_8 = 0;
    local.field_C = 1.0f;
    u_long128 t1 = *(u_long128 *)&local.field_0;
    local.field_28 = 3.0f;
    local.field_2C = 3.0f;
    local.field_20 = 1.0f;
    local.field_24 = 1.0f;
    self->field_10 = t1;
    self->field_20 = 3.0f;
    self->field_24 = 3.0f;
    self->field_28 = 1.0f;
    self->field_2C = 1.0f;
    int r2 = func_00271A00(&D_0051BA44, p2);
    func_0033D380((void *)(self->field_30), (void *)(p0), (void *)(p1), p3, g1, (void *)(D_00665ED0.field_0), (void *)(r2), (char *)self + 0x10);
    self->field_34 = 0;
    return 1;
}
