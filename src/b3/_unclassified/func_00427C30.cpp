// Hand-written; the lifter refused it (.lit4 externs as literals (0.1333f/0.8667f/0.8f), one f variable, f *= 0.8f before SetA).


#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
using GtMathPs2::CGtV4d;
struct UnkStruct_00427C30 {
    unsigned char pad_0[0xE0];
    CGt2dObject *field_E0;
    float field_E4;
    float field_E8;
    unsigned char field_EC;
};
struct UnkStruct_D_01E90350 { CGtV4d field_0; };
extern UnkStruct_D_01E90350 D_01E90350;
// 0x00427C30
extern "C" void func_00427C30(UnkStruct_00427C30 *self, float dt)
{
    if (self->field_EC != 0) {
        CGtV4d c = D_01E90350.field_0;
        self->field_E4 += dt;
        float f = self->field_E4 / self->field_E8;
        if (f < 0.1333f) {
            f = f / 0.1333f;
        } else {
            f = 1.0f - (f - 0.1333f) / 0.8667f;
        }
        if (!(self->field_E4 < self->field_E8)) {
            f = 0.0f;
            self->field_EC = 0;
        }
        f *= 0.8f;
        c.SetA(f);
        self->field_E0->mObjectSpace.mColour = c;
    }
}
