// CB3CrashActionDirector::HandleCrashingVehicleWorldCollision(CB3VehiclePhysics*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashActionDirector.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near24: nested block form + header SetPlus(float) + early field_194 read + RNG word local before lhs).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CB3VehiclePhysics;
struct UnkStruct_001AD890_1 {
    unsigned char pad_0[0x1000];
    CGtV3dPlus field_1000;
    unsigned char pad_1010[0x4];
    unsigned char field_1014;
    unsigned char field_1015;
    unsigned char field_1016;
};
class CB3VehiclePhysics {
public:
    unsigned char pad_0[0x160];
    CGtV4d field_160;
    unsigned char pad_170[0x24];
    float field_194;
    unsigned char pad_198[0xB2C];
    UnkStruct_001AD890_1 * field_CC4;
    unsigned char pad_CC8[0x4A4];
    float field_116C;
};
class CB3CrashActionDirector {
public:
    void HandleCrashingVehicleWorldCollision(CB3VehiclePhysics* p0);
    int field_0;
    int field_4;
};
struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522680 D_00522680;
extern float D_004E06D0;
// [L] N185: stands in for a missing GtMathPs2 inline (float - YAxisType, x lane result): `vsuby.x D, f, Y`
static inline float func_001AD890_inl1(float f, YAxisType y) {
    float r;
    asm("qmtc2.ni %2, $vf2" "\n\t" "vsuby.x %0, $vf2, %0y" "\n\t" "qmfc2.ni %1, %0" : "+j"(y.lVector), "=r"(r) : "r"(f));
    return r;
}

// 0x001AD890
void CB3CrashActionDirector::HandleCrashingVehicleWorldCollision(CB3VehiclePhysics* p0)
{
    if ((p0->field_CC4->field_1015 & 0x10) == 0) {
        CGtV4d pos;
        pos.mData = p0->field_160.mData;
        float t = p0->field_194;
        if (func_001AD890_inl1(p0->field_116C, pos.Y()) > 30.0f) {
            int r = field_0;
            float lhs = D_004E06D0 * (t - 8000.0f);
            field_0 = (r << 16) + (r >> 16);
            field_0 += field_4;
            field_4 += field_0;
            if (lhs > 2.3283064e-10f * (float)(unsigned int)field_0) {
                UnkStruct_001AD890_1 * c = p0->field_CC4;
                c->field_1000.SetGtV3d(CGtV3d(pos.mData));
                c->field_1000.SetPlus(D_00522680.field_0);
                c->field_1015 |= 0x18;
                p0->field_CC4->field_1016 |= 0xF0;
                c->field_1015 &= 0xF9;
                if (c->field_1014 != 2) {
                    c->field_1014 = 2;
                    c->field_1015 |= 1;
                }
            }
        }
    }
}
