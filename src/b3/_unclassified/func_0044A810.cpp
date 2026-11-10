// Hand-written; the lifter refused it (near16: inner switch on D_01E90424 (cases 2/3/4 then 5) + two-statement SetA stand-in (v277)).


#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
using GtMathPs2::CGtV4d;
class CB3A810 {
public:
    void func_0044A810();
    unsigned char pad_0[0x12C];
    CGt2dObject *field_12C;
    int field_130;
    int field_134;
    unsigned char pad_138[0x204-0x138];
    unsigned char field_204;
};
struct UnkStruct_D_01E90424 { int value; unsigned char pad[0x100]; };
struct UnkStruct_D_01E90420 { float value; unsigned char pad[0x100]; };
struct UnkStruct_D_01E90350 { CGtV4d field_0; };
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E90420 D_01E90420;
extern UnkStruct_D_01E90350 D_01E90350;
extern "C" void func_0044CBD0(CB3A810 *, float);
extern "C" void func_0044B9F0(CB3A810 *, float);
extern "C" void func_0044A8F0(CB3A810 *, float);
// 0x0044A810
// pass1: f12 (dt; a virtual's float parameter) goes to the three per-state updates (self, float dt) untouched
extern "C" void func_0044A810(CB3A810 *self, float dt)
{
    CB3A810 *const  v0 = self;
    switch (self->field_134) {
    case 0: case 3: case 4: func_0044CBD0(self, dt); goto out0;
    case 1: case 2: func_0044B9F0(self, dt); break;
    case 5: case 6: func_0044A8F0(self, dt); break;
    default:
        switch (D_01E90424.value) {
        case 2: case 3: case 4: {
                    CGtV4d c;
                    c = D_01E90350.field_0;
                    // [L] N185 stand-in: CGtV4d::SetA second shape (v277: alpha's qmtc2.ni ahead of the colour lqc2, as func_0044CBD0)
                    asm("qmtc2.ni %0, $vf2" : : "r"(D_01E90420.value));
                    asm("vmulx.w %0, $vf0, $vf2x" : "+j"(c.mData));
                    self->field_12C->mObjectSpace.mColour = c;
            }
            break;
        case 5:
            v0->field_204 = 1;
            break;
        }
    }
out0:
    ;
}
