// CB3CrashCombo::DetectAirAndGround() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (YAxisType operator- for vsub.y; float temps for add.s order; N140 pad for 0x60 frame).

// CB3CrashCombo::DetectAirAndGround() -- hand-written (fresh1).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3CrashCombo.cpp.
// Field names are placeholders and every type is [G] (instruction widths). `-Y()` is the header's
// YAxisType::operator-() (retail `vsub.y $vf1, $vf0, $vf1`).
#include "b3/GtMathPs2.h"
#include "b3/classes/UnkStruct_D_0052267C.h"

// [G] int return: retail tests the result with sltu/xori (an int callee), not andi.
class CB3VehiclePhysics {
public:
    int IsVehicleTouchingHorizontalSurface(bool, float);
    unsigned char pad_0[0xB0];
    GtMathPs2::CGtV4d field_B0;
};

class CB3CrashCombo {
public:
    void DetectAirAndGround();

    unsigned char pad_0[0x198];
    int field_198;
    unsigned char pad_19C[0x20];
    unsigned char field_1BC;
    unsigned char field_1BD;
    unsigned char field_1BE;
    unsigned char pad_1BF[0x1];
    float field_1C0;
    float field_1C4;
    float field_1C8;
    unsigned char pad_1CC[0x4];
    int field_1D0;
    float field_1D4;
    float field_1D8;
    unsigned char pad_1DC[0x4C];
    CB3VehiclePhysics * field_228;
};

extern UnkStruct_D_0052267C D_0052267C;

// N140 frame pad [G]: retail's 0x60 frame keeps one more 16-byte slot than the YAxisType temporaries give.
struct UnkStruct_00361F70_pad { int x[4]; UnkStruct_00361F70_pad() {} ~UnkStruct_00361F70_pad() {} };
// 0x00361F70
void CB3CrashCombo::DetectAirAndGround()
{
    UnkStruct_00361F70_pad pad;
    field_1BE = !field_228->IsVehicleTouchingHorizontalSurface(true, 30.0f);
    if (field_1BE) {
        float a = D_0052267C.field_0;
        field_1C8 = field_1C8 + a;
        float b = D_0052267C.field_0;
        field_1C0 = field_1C0 + b;
        field_1C4 = 0;
    } else {
        field_1C0 = 0;
        float c = D_0052267C.field_0;
        field_1C4 = field_1C4 + c;
    }
    field_1BD = 0;
    if (field_1BE || field_1BC) {
        if (field_1BE && field_1BC && !(field_1C0 <= 0.2f)) field_1BC = 0;
    } else {
        float y = -field_228->field_B0.Y();
        if (!(y <= field_1D4)) { field_1D4 = y; field_1D0 = field_198; }
        if (!(y <= field_1D8)) field_1D8 = y;
        field_1BC = 1;
        field_1BD = 1;
    }
}
