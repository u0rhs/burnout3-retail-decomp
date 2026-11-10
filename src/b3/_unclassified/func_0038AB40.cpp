// func_0038AB40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (scene = &D_01E90240.field_1A0 local first, then int l = field_8 and l1 = l + 1 before the Release call; pointer fields).

class CGt2dObject;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x1A0];
    UnkStruct_D_01E903E0 field_1A0;  // = D_01E903E0 (N65)
};

struct UnkStruct_0038AB40 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObject * field_C;
    CGt2dObject * field_10;
    CGt2dObject * field_14;
    void * field_18;
};

extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, CGt2dObject *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void Destruct__10CGt2dFrameFv(void *);  // CGt2dFrame::Destruct()

// 0x0038AB40
extern "C" void func_0038AB40(UnkStruct_0038AB40 * self)
{
    UnkStruct_D_01E903E0 * scene = &D_01E90240.field_1A0;
    int l = self->field_8;
    int l1 = l + 1;
    Release__20CB3MenuComponentBaseFv(self);
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, l, self->field_C);
    self->field_C = 0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, l1, self->field_14);
    self->field_14 = 0;
    if (self->field_10 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, l1, self->field_10);
        self->field_10 = 0;
    }
    Destruct__10CGt2dFrameFv(self->field_18);
    self->field_18 = 0;
}
