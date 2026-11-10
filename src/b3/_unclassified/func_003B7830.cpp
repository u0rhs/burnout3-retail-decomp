// PrepareSpinning__17CB3GlobeComponentFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (scene global held in a const local pointer (saved register)).

// lifter variant 0
// PrepareSpinning__17CB3GlobeComponentFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGt2dFrame;
class CGt2dObject;

class CB3Globe2dObject;
struct UnkStruct_003B7830;
struct UnkStruct_D_01E903E0;

class CB3Globe2dObject {
public:
    int Prepare();
};

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_003B7830 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x16];
    CB3Globe2dObject * field_20;
    unsigned char pad_24[0x30];
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
};

extern UnkStruct_D_01E903E0 D_01E903E0;

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Prepare()
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void Release__16CB3Globe2dObjectFv(CB3Globe2dObject *);

// 0x003B7830
extern "C" int PrepareSpinning__17CB3GlobeComponentFv(UnkStruct_003B7830 * self)
{
    Prepare__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    self->field_20 = (CB3Globe2dObject *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, (CGt2dFrame*)scene->field_14);
    if (self->field_20->Prepare() == 0) {
        Release__16CB3Globe2dObjectFv(self->field_20);
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8, (CGt2dObject*)self->field_20);
        self->field_20 = 0;
    }
    self->field_54 = 8;
    self->field_58 = 3;
    self->field_5C = 3;
    self->field_60 = 0;
    self->field_64 = 0;
    return 1;
}
