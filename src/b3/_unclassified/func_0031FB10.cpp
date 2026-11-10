// func_0031FB10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (BUILD-HOST: wibo (N165)).

// BUILD-HOST: wibo
// N165 [C]: MWCC b119's register tie-breaks depend on the host. Under wine this source is 4 off (s4/s5 swapped);
// under wibo / native Windows it is byte-exact. tools/tiny_compile.sh compiles it under wibo because of the line above.

// from build/vt\try_func_0031FB10_best.cpp
// func_0031FB10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGt2dFrame;

struct UnkStruct_0031FB10;
struct UnkStruct_0031FB10_7;
struct UnkStruct_D_004E0A04;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_00665ED0;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E903E0;
struct UnkStruct_D_01E90424;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    CGt2dFrame *field_14;
};

struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E0A04 {
    float field_0;
};

struct UnkStruct_0031FB10_7 {
    float field_0;
    float field_4;
};

struct UnkStruct_D_00665ED0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0xD0];
    unsigned char field_D0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0031FB10 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x12];
    int field_1C[1];  // [G] element count unknown
    unsigned char pad_20[0x28];
    int field_48[1];  // [G] element count unknown
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern float D_004C52E0[];  // [G] element count unknown
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_004E0A04 D_004E0A04;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, CGt2dFrame *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" float func_00382BE0(int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_001D6C40(int, UnkStruct_0031FB10_7 *, UnkStruct_0031FB10_7 *, void *, int, int, float);
extern "C" void func_00382C00(int, UnkStruct_0031FB10_7 *, UnkStruct_0031FB10_7 *, int);

// 0x0031FB10
extern "C" void func_0031FB10(UnkStruct_0031FB10 * self, int p0, int p1, float f0)
{
    float px;
    float y;
    float x;
    float off;
    float r;
    UnkStruct_0031FB10_7 pos1;
    UnkStruct_0031FB10_7 anc1;
    UnkStruct_0031FB10_7 pos2;
    UnkStruct_0031FB10_7 anc2;
    UnkStruct_D_01E90240 * const g = &D_01E90240;
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    CGt2dFrame *t1 = scene->field_14;
    int t0 = self->field_8;
    if (f0 < 0.0f) {
        f0 = D_004C52E0[p0];
    }
    int w = 550;
    x = 45.0f + f0 * (float)w;
    px = x;
    y = 504.0f;
    if (D_01E90424.field_0 == 5) {
        y = D_004E0A04.field_0;
    }
    r = func_00382BE0(p0);
    off = 5.0f + 0.5f * r;
    if (f0 > 0.5f) {
        f0 = 1.0f;
        px -= off;
    } else {
        f0 = 0.0f;
        px += off;
    }
    if (self->field_1C[p0] == 0) {
        self->field_1C[p0] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, t0, t1);
    }
    int c = func_00271A00(&D_0051BA44, p1);
    anc1.field_4 = 0.5f;
    anc1.field_0 = f0;
    pos1.field_0 = px;
    pos1.field_4 = y;
    func_001D6C40(self->field_1C[p0], &pos1, &anc1, g->field_D0, D_00665ED0.field_0, c, 24.0f);
    if (self->field_48[p0] == 0) {
        self->field_48[p0] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, t0, t1);
    }
    pos2.field_0 = x;
    anc2.field_0 = 0.5f;
    pos2.field_4 = y;
    anc2.field_4 = 0.5f;
    func_00382C00(self->field_48[p0], &pos2, &anc2, p0);
}
