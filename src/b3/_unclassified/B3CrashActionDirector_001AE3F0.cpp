// CB3CrashActionDirector::ExplodeVehicle(GtMathPs2::CGtV3d,CB3VehiclePhysics*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashActionDirector.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a188: two local VU asm statements (vadd.xyz keep-w; SetW via qmtc2.ni/vsubw.w/vaddx.w)).

#include "b3/GtMathPs2.h"
#include "b3/classes/UnkStruct_D_00522680.h"
using namespace GtMathPs2;
extern UnkStruct_D_00522680 D_00522680;
struct UnkStruct_1AE3F0_body {
    unsigned char pad_0[0x1000];
    CGtV4d field_1000;
    unsigned char pad_1010[4];
    unsigned char field_1014;
    unsigned char field_1015;
    unsigned char field_1016;
};
class CB3VehiclePhysics {
public:
    unsigned char pad_0[0xCC4];
    UnkStruct_1AE3F0_body *field_CC4;
};
class CB3CrashActionDirector {
public:
    void ExplodeVehicle(CGtV3d p, CB3VehiclePhysics *v);
};
// 0x001AE3F0
void CB3CrashActionDirector::ExplodeVehicle(CGtV3d p, CB3VehiclePhysics *v)
{
    UnkStruct_1AE3F0_body *b = v->field_CC4;
    float w = D_00522680.field_0;
    asm("vadd.xyz %0, $vf0, %1" : "+j"(b->field_1000.mData) : "j"(p.mData));
    asm("qmtc2.ni %1, $vf1\n\tvsubw.w %0, $vf0, $vf0w\n\tvaddx.w %0, %0, $vf1x" : "+j"(b->field_1000.mData) : "r"(w));
    b->field_1015 |= 0x18;
    v->field_CC4->field_1016 |= 0xF0;
    b->field_1015 &= 0xF9;
    if (b->field_1014 != 2) {
        b->field_1014 = 2;
        b->field_1015 |= 1;
    }
}
