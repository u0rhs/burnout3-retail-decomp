// func_0031F970 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (const scene/mgr pointers, fused 5+0.5*r, x -= / +=, second D_004C5360 read via const float& (stops CSE), float decl order).

// from build/vt\try_func_0031F970_best.cpp
// func_0031F970 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGt2dFrame;

struct UnkStruct_0031F970;
struct UnkStruct_0031F970_5;
struct UnkStruct_D_004C52EC;
struct UnkStruct_D_004C5360;
struct UnkStruct_D_004C5364;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_00665ED0;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_004C5360 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_D_004C5364 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C52EC {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0031F970_5 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
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

struct UnkStruct_0031F970 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x1E];
    int field_28;
    unsigned char pad_2C[0x28];
    int field_54;
};

extern UnkStruct_D_004C5360 D_004C5360;
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_004C5364 D_004C5364;
extern UnkStruct_D_004C52EC D_004C52EC;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" float func_00382BE0(int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_001D6C40(void *, void *, void *, void *, void *, void *, float);
extern "C" void func_00382C00(void *, void *, UnkStruct_0031F970_5 *, int);

// 0x0031F970
extern "C" void func_0031F970(UnkStruct_0031F970 * self)
{
    UnkStruct_0031F970_5 local;  // [G] the frame's one local (size: up to the frame top)
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    char * const mgr = (char *)&D_01E90240;
    const float & rf = D_004C5360.field_0;  // [G] read through a reference: retail loads D_004C5360 twice (a direct second read is CSE-d)
    float x;
    float m0;
    float v1;
    float t0;
    float t4;
    x = D_004C5360.field_0;
    t0 = rf;
    int t3 = scene->field_14;
    int t1 = self->field_8;
    t4 = D_004C5364.field_0;
    m0 = 5.0f + 0.5f * func_00382BE0(3);
    if (!(D_004C52EC.field_0 <= 0.5f)) {
        x -= m0;
        v1 = 1.0f;
    } else {
        x += m0;
        v1 = 0.0f;
    }
    if (self->field_28 == 0) {
        self->field_28 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, t1, (CGt2dFrame*)t3);
    }
    int r2 = func_00271A00(&D_0051BA44, 3087);
    local.field_14 = 0.5f;
    local.field_10 = v1;
    local.field_18 = x;
    local.field_1C = t4;
    func_001D6C40((void *)(self->field_28), ((char *)&local + 0x18), ((char *)&local + 0x10), mgr + 0xD0, (void *)(D_00665ED0.field_0), (void *)(r2), 24.0f);
    if (self->field_54 == 0) {
        self->field_54 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, t1, (CGt2dFrame*)t3);
    }
    local.field_8 = t0;
    local.field_0 = 0.5f;
    local.field_C = t4;
    local.field_4 = 0.5f;
    func_00382C00((void *)(self->field_54), ((char *)&local + 0x8), &local, 3);
}
