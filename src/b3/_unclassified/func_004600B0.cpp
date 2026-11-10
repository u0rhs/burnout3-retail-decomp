// func_004600B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (scene = &D_01E90240.field_1A0 local (keeps the scene in s2)).

// func_004600B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGt2dFrame;

struct UnkStruct_004600B0;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_004600B0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    unsigned char pad_1C[0x664];
    int field_680;
    int field_684;
    int field_688;
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x1A0];
    UnkStruct_D_01E903E0 field_1A0;  // = D_01E903E0 (N65)
};

extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Prepare()
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" int func_0045FB10(UnkStruct_004600B0 *);
extern "C" unsigned long func_0045FC80(UnkStruct_004600B0 *);

// 0x004600B0
extern "C" int func_004600B0(UnkStruct_004600B0 * self, int p0, int p1, int p2)
{
    Prepare__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E903E0 * scene = &D_01E90240.field_1A0;
    int root = scene->field_14;
    self->field_C = p0;
    self->field_10 = p1;
    self->field_14 = func_0045FB10(self);
    self->field_18 = p2;
    self->field_680 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, (CGt2dFrame*)root);
    self->field_684 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, (CGt2dFrame*)root);
    self->field_688 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, (CGt2dFrame*)root);
    func_0045FC80(self);
    return 1;
}
