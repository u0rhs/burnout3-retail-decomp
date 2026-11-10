// Hand-written; the lifter refused it (a131: inline helper for the destruct rows (called twice), goto-free create blocks come out of line natively, r,i declared before the middle loop).

class CGt2dFrame;
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x10]; };
struct UnkStruct_003AB640_row { void * field_0; void * field_4; void * field_8; unsigned char pad_C[0x4]; };
struct UnkStruct_003AB640 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x9A];
    UnkStruct_003AB640_row field_A4[1];
    unsigned char pad_B4[0x198];
    CGt2dFrame * field_24C;
    unsigned short field_250;
    unsigned short field_252;
    unsigned char pad_254[0x688];
    int field_8DC;
    unsigned char pad_8E0[0x5];
    signed char field_8E5;
    unsigned char pad_8E6[0x1];
    unsigned char field_8E7;
};
extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, CGt2dFrame *);
extern "C" void func_003B0870(void *, float, int);

static inline void func_003AB640_inl(UnkStruct_003AB640 * self, UnkStruct_D_01E903E0 * scene, int a, int b, int i)
{
    UnkStruct_003AB640_row * r;
    for (; i < self->field_252; i++) {
        r = &self->field_A4[i];
        if (r->field_0 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a, r->field_0);
            r->field_0 = 0;
        }
        if (r->field_4 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a, r->field_4);
            r->field_4 = 0;
        }
        if (r->field_8 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, b, r->field_8);
            r->field_8 = 0;
        }
    }
}

// 0x003AB640
extern "C" void func_003AB640(UnkStruct_003AB640 * self)
{
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    int t0 = self->field_8;
    unsigned short saved = self->field_250;
    int a = t0 + 0x13;
    int b = t0 + 0x14;
    func_003AB640_inl(self, scene, a, b, 0);
    self->field_250 = 0;
    self->field_252 = 12;
    self->field_8E5 = -1;
    self->field_8E7 = 0;
    self->field_8DC = 0;
    UnkStruct_003AB640_row * r;
    int i;
    for (i = 0; i < self->field_252; i++) {
        r = &self->field_A4[i];
        if (r->field_0 == 0) {
            r->field_0 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, a, self->field_24C);
        }
        if (r->field_4 == 0) {
            r->field_4 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, a, self->field_24C);
        }
        func_003B0870(r, 0.0f, 0);
    }
    self->field_8E7 = 1;
    func_003AB640_inl(self, scene, a, b, 6);
    self->field_250 = saved;
    self->field_252 = 6;
}
