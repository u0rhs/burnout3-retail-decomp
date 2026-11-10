// Hand-written; the lifter refused it (object clone loop: u_long128[2] struct copy + int[6] pair-loop copy via casts; scene const ptr inside each block; slot ptr vs array test).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" CGt2dObject *ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
struct UnkStruct_0044C960_obj {
    u_long128 field_0;
    u_long128 field_10;
    int field_20[6];
    int field_38;
    int field_3C;
};
struct UnkStruct_0044C960_q2 { u_long128 q[2]; };
struct UnkStruct_0044C960_d6 { int d[6]; };
struct UnkStruct_0044C960_row {
    CGt2dObject *field_0;
    unsigned char pad_4[0xC];
    CGt2dObject *field_10[5];
};
struct UnkStruct_0044C960 {
    unsigned char pad_0[8];
    short field_8;
};

// 0x0044C960
extern "C" void func_0044C960(UnkStruct_0044C960 *self, int row, int flag)
{
    UnkStruct_0044C960_row *r = (UnkStruct_0044C960_row *)((char *)self + row * 0x24 + 0xC);
    int base = self->field_8;
    int d0 = base + 1;
    int d1 = base + 2;
    int c0 = d0;
    int c1 = d1;
    int j;
    if (flag != 0) {
        c0 = d0 + 2;
        c1 = d1 + 2;
    } else {
        d0 = d0 + 2;
        d1 = d1 + 2;
    }
    if (r->field_0 != 0) {
        void *const scene = &D_01E903E0;
        CGt2dObject *n = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, c0, r->field_0->mpFrame);
        UnkStruct_0044C960_obj *o = (UnkStruct_0044C960_obj *)r->field_0;
        UnkStruct_0044C960_obj *m = (UnkStruct_0044C960_obj *)n;
        *(UnkStruct_0044C960_q2 *)m = *(UnkStruct_0044C960_q2 *)o;
        *(UnkStruct_0044C960_d6 *)m->field_20 = *(UnkStruct_0044C960_d6 *)o->field_20;
        m->field_38 = o->field_38;
        m->field_3C = o->field_3C;
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, d0, r->field_0);
        r->field_0 = n;
    }
    for (j = 0; j < 5; j++) {
        CGt2dObject **slot = &r->field_10[j];
        if (r->field_10[j] != 0) {
            void *const scene = &D_01E903E0;
            CGt2dObject *n = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, c1, r->field_10[j]->mpFrame);
            UnkStruct_0044C960_obj *o = (UnkStruct_0044C960_obj *)*slot;
            UnkStruct_0044C960_obj *m = (UnkStruct_0044C960_obj *)n;
            *(UnkStruct_0044C960_q2 *)m = *(UnkStruct_0044C960_q2 *)o;
            *(UnkStruct_0044C960_d6 *)m->field_20 = *(UnkStruct_0044C960_d6 *)o->field_20;
            m->field_38 = o->field_38;
            m->field_3C = o->field_3C;
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, d1, *slot);
            *slot = n;
        }
    }
}
