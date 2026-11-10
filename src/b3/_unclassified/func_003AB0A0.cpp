// func_003AB0A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (scene const ptr + four t0+K locals (as func_003A8A90), CGt2dObject* fields, 12-element array at 0xA4, goto-shaped wait loop (body after the exit path)).

// lifter variant 0
// func_003AB0A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGt2dObject;

struct UnkStruct_003AB0A0;
struct UnkStruct_003AB0A0_e0;
struct UnkStruct_003AB0A0_e1;
struct UnkStruct_D_0051A6A8;
struct UnkStruct_D_0051A870;
struct UnkStruct_D_0051A9A0;
struct UnkStruct_D_0051A9A4;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x2C];
    UnkStruct_003AB0A0_e0 * field_2C;
};

struct UnkStruct_003AB0A0_e0 {
    int field_0;
    unsigned char pad_4[0xC];
};

class CGt2dObject;

class CGt2dFrame;

struct UnkStruct_003AB0A0_e1 {
    CGt2dObject * field_0;
    CGt2dObject * field_4;
    CGt2dObject * field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_D_0051A9A4 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A9A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A6A8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A870 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003AB0A0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x9A];
    UnkStruct_003AB0A0_e1 field_A4[12];  // [G] 12: the loop bound
    unsigned char pad_164[0xBC];
    CGt2dObject * field_220;
    CGt2dObject * field_224;
    unsigned char pad_228[0x8];
    CGt2dObject * field_230;
    CGt2dObject * field_234;
    CGt2dObject * field_238;
    CGt2dObject * field_23C;
    CGt2dObject * field_240;
    CGt2dObject * field_244;
    CGt2dObject * field_248;
    CGt2dFrame * field_24C;
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_0051A9A4 D_0051A9A4;
extern UnkStruct_D_0051A9A0 D_0051A9A0;
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern UnkStruct_D_0051A870 D_0051A870;

extern "C" void Destruct__10CGt2dFrameFv(CGt2dFrame *);  // CGt2dFrame::Destruct()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(UnkStruct_D_01E903E0 *, int, CGt2dObject *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void func_00130C70(void *);
extern "C" void func_00130D00(void *);
extern "C" void func_00130C30(void *, int);
extern "C" void func_00130D50(void *);
extern "C" void func_00324EC0(void *);

// 0x003AB0A0
extern "C" void func_003AB0A0(UnkStruct_003AB0A0 * self)
{
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    int i;
    short t0 = self->field_8;
    int a = t0 + 15;
    int b = t0 + 16;
    int c = t0 + 19;
    int d = t0 + 20;
    scene->field_2C[a].field_0 = 0;
    scene->field_2C[b].field_0 = 0;
    Destruct__10CGt2dFrameFv(self->field_24C);
    self->field_24C = 0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, t0 + 10, self->field_230);
    self->field_230 = 0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a, self->field_238);
    self->field_238 = 0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a, self->field_234);
    self->field_234 = 0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, b, self->field_23C);
    self->field_23C = 0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, t0 + 18, self->field_244);
    self->field_244 = 0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, t0 + 17, self->field_240);
    self->field_240 = 0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, c, self->field_248);
    self->field_248 = 0;
    for (i = 0; i < 12; i++) {
        UnkStruct_003AB0A0_e1 * e = &self->field_A4[i];
        if (e->field_0 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, c, e->field_0);
            e->field_0 = 0;
        }
        if (e->field_4 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, c, e->field_4);
            e->field_4 = 0;
        }
        if (e->field_8 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, d, e->field_8);
            e->field_8 = 0;
        }
    }
    if (self->field_220 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, c, self->field_220);
        self->field_220 = 0;
    }
    if (self->field_224 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, c, self->field_224);
        self->field_224 = 0;
    }
    if (D_0051A9A4.field_0 != 26) {
        func_00130C70(&D_0051A6A8);
        func_00130D00(&D_0051A6A8);
        func_00130C30(&D_0051A6A8, 26);
    loop:  // [G] goto shape: retail places the wait loop's body after the exit path (no while/for form does)
        if (D_0051A9A0.field_0 != 23) {
            goto body;
        }
    }
    func_00324EC0(&D_0051A870);
    return;
body:
    func_00130D50(&D_0051A6A8);
    goto loop;
}
