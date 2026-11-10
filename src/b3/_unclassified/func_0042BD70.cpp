// func_0042BD70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (inline bool guard with three early 'return false'; CGt2dObject* arrays; int i declared before scene=&D_01E903E0 const local).

// func_0042BD70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGt2dObject;

struct UnkStruct_0042BD70;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0042BD70 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x1E2];
    CGt2dObject * field_1EC[4];

    CGt2dObject * field_1FC[4];
    unsigned char pad_20C[0x2C];
    int field_238;
    int field_23C;
    int field_240;
    int field_244;
    unsigned char pad_248[0xC];
    int field_254;
    int field_258;
    int field_25C;
};

extern UnkStruct_D_01E903E0 D_01E903E0;

extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void func_0042B7C0(UnkStruct_0042BD70 *);
extern "C" void func_0042DAE0(UnkStruct_0042BD70 *);

static inline bool func_0042BD70_inl1(UnkStruct_0042BD70 * self)
{
    if (self->field_25C != 9) return false;
    if (self->field_238 != 0) return false;
    if (self->field_258 <= 0) return false;
    return true;
}

// 0x0042BD70
extern "C" void func_0042BD70(UnkStruct_0042BD70 * self)
{
    if (!func_0042BD70_inl1(self)) {
        return;
    }
    self->field_254 = self->field_258;
    self->field_258 = self->field_258 - 1;
    self->field_240 = self->field_244;
    self->field_244 = 0;
    func_0042B7C0(self);
    int i;
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    for (i = 0; i < 4; i++) {
        if (self->field_1EC[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 1, self->field_1EC[i]);
            self->field_1EC[i] = 0;
        }
        if (self->field_1FC[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 1, self->field_1FC[i]);
            self->field_1FC[i] = 0;
        }
    }
    func_0042DAE0(self);
    self->field_238 = 4;
    self->field_23C = 0;
}
