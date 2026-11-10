// Hand-written; the lifter refused it (a131: int t0; b,a computed before Release; row struct).

class CGt2dObject;
struct UnkStruct_0039C2C0_e0 {
    CGt2dObject * field_0;
    CGt2dObject * field_4[2];
    CGt2dObject * field_C;
    CGt2dObject * field_10;
};
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x10]; };
struct UnkStruct_0039C2C0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    UnkStruct_0039C2C0_e0 field_C[3];
    CGt2dObject * field_48[2];
    CGt2dObject * field_50;
    CGt2dObject * field_54;
    CGt2dObject * field_58;
    CGt2dObject * field_5C;
    void * field_60;
    unsigned char pad_64[0x4];
    unsigned char field_68;
};
extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void Release__20CB3MenuComponentBaseFv(void *);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
extern "C" void Destruct__10CGt2dFrameFv(void *);

// 0x0039C2C0
extern "C" void func_0039C2C0(UnkStruct_0039C2C0 * self)
{
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    int i; int j; int k;
    int t0 = self->field_8;
    int b = t0 + 1;
    int a = t0 + 2;
    Release__20CB3MenuComponentBaseFv(self);
    if (self->field_68 == 0) {
        for (i = 0; i < 3; i++) {
            UnkStruct_0039C2C0_e0 * e = &self->field_C[i];
            if (e->field_0 != 0) {
                DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a, e->field_0);
                e->field_0 = 0;
            }
            for (j = 0; j < 2; j++) {
                if (e->field_4[j] != 0) {
                    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a, e->field_4[j]);
                    e->field_4[j] = 0;
                }
            }
            if (e->field_C != 0) {
                DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, b, e->field_C);
                e->field_C = 0;
            }
            if (e->field_10 != 0) {
                DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, t0, e->field_10);
                e->field_10 = 0;
            }
        }
        for (k = 0; k < 2; k++) {
            if (self->field_48[k] != 0) {
                DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a, self->field_48[k]);
                self->field_48[k] = 0;
            }
        }
        if (self->field_50 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a, self->field_50);
            self->field_50 = 0;
        }
    } else {
        if (self->field_54 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a, self->field_54);
        }
        if (self->field_58 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a, self->field_58);
        }
        if (self->field_5C != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a, self->field_5C);
        }
        if (self->field_48[0] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a, self->field_48[0]);
            self->field_48[0] = 0;
        }
        if (self->field_50 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a, self->field_50);
            self->field_50 = 0;
        }
        if (self->field_C[0].field_C != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, b, self->field_C[0].field_C);
        }
        self->field_54 = 0;
        self->field_58 = 0;
        self->field_5C = 0;
        self->field_48[0] = 0;
        self->field_50 = 0;
        self->field_C[0].field_C = 0;
    }
    Destruct__10CGt2dFrameFv(self->field_60);
    self->field_60 = 0;
}
