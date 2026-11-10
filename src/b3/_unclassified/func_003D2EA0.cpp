// func_003D2EA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (field_38 address taken into a local first, element pointer local, frame (field_28) declared before field_10 local).

// func_003D2EA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EHUDAlign {};
class CGt2dFrame;

struct UnkStruct_003D2EA0;
struct UnkStruct_003D2EA0_3;
struct UnkStruct_003D2EA0_e0;
struct UnkStruct_003D2EA0_e1;
struct UnkStruct_003D2EA0_e2;
struct UnkStruct_D_00522660;

struct UnkStruct_003D2EA0_e0 {
    unsigned char pad_0[0x28];
    int field_28;
    unsigned char pad_2C[0x14];
    UnkStruct_003D2EA0_e1 * field_40;
    unsigned char pad_44[0x2C];
};

struct UnkStruct_003D2EA0_e1 {
    int field_0;
    unsigned char pad_4[0xC];
};

struct UnkStruct_003D2EA0_3 {
    unsigned char pad_0[0xE0];
    unsigned char field_E0;
};

struct UnkStruct_003D2EA0_e2 {
    unsigned char pad_0[0x27D0];
};

struct UnkStruct_D_00522660 {
    UnkStruct_003D2EA0_e2 field_0[1];  // [G] element count unknown
};

struct UnkStruct_003D2EA0 {
    unsigned char pad_0[0x4];
    UnkStruct_003D2EA0_e0 * field_4;
    unsigned char pad_8[0x8];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    unsigned char pad_30[0x4];
    int field_34;
    void * field_38;
};

extern UnkStruct_D_00522660 D_00522660;

extern "C" void Prepare__15CB3HUDComponentFiiii9EHUDAligni(void *, int, int, int, int, EHUDAlign, int);  // CB3HUDComponent::Prepare(int,int,int,int,EHUDAlign,int)
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" void func_003D2AA0(UnkStruct_003D2EA0 *, int);

// 0x003D2EA0
extern "C" int func_003D2EA0(UnkStruct_003D2EA0 * self, int p0, int p1, int p2)
{
    Prepare__15CB3HUDComponentFiiii9EHUDAligni(self, 3, 6, 0, p0, (EHUDAlign)p1, p2);
    void * p = ((char *)&D_00522660 + (p0 * 10192)) + 0x12BE10;
    UnkStruct_003D2EA0_e0 * e = &self->field_4[self->field_1C];
    int t3 = e->field_28;
    short t2 = self->field_10;
    self->field_38 = p;
    e->field_40[t2].field_0 = 8;
    int r1 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(((char *)e + 0x14), t2, (CGt2dFrame*)t3);
    self->field_20 = r1;
    int r2 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(((char *)e + 0x14), t2, (CGt2dFrame*)t3);
    self->field_24 = r2;
    int r3 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(((char *)e + 0x14), t2, (CGt2dFrame*)t3);
    self->field_28 = r3;
    int r4 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(((char *)e + 0x14), t2, (CGt2dFrame*)t3);
    self->field_2C = r4;
    int r5 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(((char *)e + 0x14), (t2 + 2), (CGt2dFrame*)t3);
    self->field_34 = r5;
    func_003D2AA0(self, 2);
    ((UnkStruct_003D2EA0_3 *)self->field_4)->field_E0 = 1;
    return 1;
}
