// Hand-written; the lifter refused it (near11: switch (reverse case order) + two-statement SetA with alpha read first).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
using GtMathPs2::CGtV4d;
class CB3EventFinishedComponent {
public:
    void Update(float);
    unsigned char pad_0[0x14];
    CGt2dObject *field_14;
};
struct UnkStruct_D_01E90424 { int value; unsigned char pad[0x100]; };
struct UnkStruct_D_01E90420 { float value; unsigned char pad[0x100]; };
struct UnkStruct_D_01E90350 { CGtV4d field_0; };
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E90420 D_01E90420;
extern UnkStruct_D_01E90350 D_01E90350;
extern "C" void func_003B8A50(CB3EventFinishedComponent *);
// near11: switch with cases in reverse test order (retail tests 4,3,5,2); [L] CGtV4d::SetA(a) in its two-statement
// shape (v277: scalar by its own qmtc2.ni onto a compiler-chosen register), alpha read before field_14.
// 0x003B8BE0
void CB3EventFinishedComponent::Update(float)
{
    int s = D_01E90424.value;
    switch (s) {
    case 2: case 5:
        func_003B8A50(this);
        break;
    case 3: case 4: {
        float a = D_01E90420.value;
        CGt2dObject *o = field_14;
        CGtV4d c;
        c = D_01E90350.field_0;
        { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(a)); asm("vmulx.w %0, $vf0, %1x" : "+j"(c.mData) : "j"(s)); }
        o->mObjectSpace.mColour = c;
        break; }
    }
}
