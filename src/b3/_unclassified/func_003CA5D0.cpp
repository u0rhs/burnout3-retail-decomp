// func_003CA5D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (field_C/field_8 read before test, then inline destroy helper (scene local, ref param) keeps the double null test; const scene ptr + signed char i declared first in loop).

// func_003CA5D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGt2dObject;

struct UnkStruct_003CA5D0;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003CA5D0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObject * field_C;
    CGt2dObject * field_10[2];
    CGt2dObject * field_18[2];
};

extern UnkStruct_D_01E903E0 D_01E903E0;

extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

static inline void func_003CA5D0_inl2(int layer, CGt2dObject *& obj)
{
    void * scene = &D_01E903E0;
    if (obj != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, layer, obj);
        obj = 0;
    }
}

// 0x003CA5D0
extern "C" void func_003CA5D0(UnkStruct_003CA5D0 * self)
{
    Release__20CB3MenuComponentBaseFv(self);
    CGt2dObject * c = self->field_C;
    int layer0 = self->field_8;
    if (c != 0) {
        func_003CA5D0_inl2(layer0, self->field_C);
    }
    signed char i;
    void * const scene = &D_01E903E0;
    for (i = 0; i < 2; i++) {
        int layer = self->field_8 + 1;
        if (self->field_18[(unsigned char)i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, layer, self->field_18[(unsigned char)i]);
            self->field_18[(unsigned char)i] = 0;
            CGt2dObject *& o = self->field_10[(unsigned char)i];
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, layer, o);
            o = 0;
        }
    }
}
