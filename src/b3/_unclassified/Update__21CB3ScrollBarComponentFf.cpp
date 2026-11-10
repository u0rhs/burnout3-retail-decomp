// Hand-written; the lifter refused it (psweep: scoped #pragma opt_propagation off [G] (N182)).

#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_propagation off
typedef unsigned int u_long128 __attribute__((mode(TI)));
using GtMathPs2::CGtV2d;
class CGt2dObject;
struct UnkStruct_D_01E90424 { int value; unsigned char pad[0x100]; };
extern UnkStruct_D_01E90424 D_01E90424;
struct UnkStruct_D_01E90240 { u_long128 field_0; u_long128 field_10; u_long128 field_20; u_long128 field_30; };
struct UnkStruct_Sel { unsigned short field_0; unsigned short field_2; };
struct UnkStruct_Quad { unsigned char pad_0[0x10]; u_long128 field_10; };
struct UnkStruct_Obj { float field_0; float field_4; float field_8; float field_C; };
class CB3ScrollBarComponent {
public:
    void Update(float);
    unsigned char pad_0[0xC];
    UnkStruct_Sel * field_C;
    UnkStruct_Obj * field_10;
    UnkStruct_Quad * field_14;
    UnkStruct_Quad * field_18;
    unsigned char pad_1C[0x8];
    float field_24;
    unsigned char pad_28[4];
    float field_2C;
    int field_30;
    int field_34;
    float field_38;
};
struct UnkStruct_0041EB70_pad { int x[4]; UnkStruct_0041EB70_pad() {} ~UnkStruct_0041EB70_pad() {} };
extern UnkStruct_D_01E90240 D_01E90240;
static inline void SetPos(UnkStruct_Obj * o, const CGtV2d & p) { o->field_0 = p.X(); o->field_4 = p.Y(); }
static inline void SetSize(UnkStruct_Obj * o, const CGtV2d & p) { o->field_8 = p.X(); o->field_C = p.Y(); }
// 0x0041EB70
void CB3ScrollBarComponent::Update(float)
{
    UnkStruct_0041EB70_pad pd0;
    UnkStruct_0041EB70_pad pd1;
    UnkStruct_0041EB70_pad pd2;
    UnkStruct_0041EB70_pad pd3;
    UnkStruct_0041EB70_pad pd4;
    UnkStruct_0041EB70_pad pd5;
    UnkStruct_D_01E90240 * const g = &D_01E90240;
    if (D_01E90424.value != 5) {
        return;
    }
    if (field_34 != field_C->field_2) {
        field_34 = field_C->field_2;
        float r = (field_2C - 32.0f) / (float)field_34;
        field_38 = r;
        float k = r;
        if (r < 10.0f) {
            field_38 = field_38 - 10.0f / (float)field_34;
            k = 10.0f;
        }
        float y = 0.0f + (16.0f + field_24) + field_38 * (float)field_30;
        *(CGtV2d *)field_10 = CGtV2d(field_10->field_0, y);
        *(CGtV2d *)&field_10->field_8 = CGtV2d(field_10->field_8, k);
        if (field_30 == field_34 - 1) {
            field_18->field_10 = g->field_20;
        } else {
            field_18->field_10 = g->field_0;
        }
    }
    if (field_30 != field_C->field_0) {
        field_30 = field_C->field_0;
        if (field_30 == 0) {
            field_14->field_10 = g->field_20;
        } else {
            field_14->field_10 = g->field_0;
        }
        if (field_30 == field_34 - 1) {
            field_18->field_10 = g->field_20;
        } else {
            field_18->field_10 = g->field_0;
        }
        float y = 0.0f + (16.0f + field_24) + field_38 * (float)field_30;
        *(CGtV2d *)field_10 = CGtV2d(field_10->field_0, y);
    }
}

#pragma pop
