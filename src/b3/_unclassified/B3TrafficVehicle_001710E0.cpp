// CB3TrafficVehicle::ApplyNiceOncomingBehaviour(CB3TrafficRaceCarInfo*,int,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficVehicle.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (L284: diff hoisted before the far/near branch, bool result, F0 slot pointer via byte offset [G]).

// CB3TrafficVehicle::ApplyNiceOncomingBehaviour(CB3TrafficRaceCarInfo*,int,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficVehicle.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished (L284: hand-written from the asm, after the sibling ApplyNiceSameWayBehaviour; header DotProduct/operator-;
// the lane difference computed once before the branch; bool result; no pragma needed).

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"

using GtMathPs2::CGtV3d;

class CB3TrafficRaceCarInfo {                    // [G] 0x70-byte records (as DoTrafficBehaviour)
public:
    unsigned char pad_0[0x30];
    CGtV3d field_30;
    unsigned char pad_40[0x30];
};

struct UnkStruct_001710E0_2 {
    unsigned char pad_0[0x28];
    float field_28;
    unsigned char pad_2C[0x4];
    float field_30;
    unsigned char pad_34[0x15];
    unsigned char field_49;
};

// [C] 0x50-byte lane records at D_00522660+0x34210: a direction at +0, a position at +0x30.
struct UnkStruct_001710E0_e1 {
    CGtV3d field_0;
    unsigned char pad_10[0x20];
    CGtV3d field_30;
    unsigned char pad_40[0x10];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x34210];
    UnkStruct_001710E0_e1 field_34210[1];  // [G] element count unknown
};

// [G] the 0x40-byte stack local func_001618C0 fills (a direction at +0, a position at +0x30).
struct UnkStruct_001710E0_8 {
    CGtV3d field_0;
    unsigned char pad_10[0x20];
    CGtV3d field_30;
};

class CB3TrafficVehicle {
public:
    bool ApplyNiceOncomingBehaviour(CB3TrafficRaceCarInfo *p0, int p1, float p2);

    unsigned char pad_0[0xF0];
    float field_F0[1];  // [G] element count unknown
    unsigned char pad_F4[0x20];
    UnkStruct_001710E0_2 *field_114;
    unsigned char pad_118[0xC];
    float field_124;
    unsigned char pad_128[0x1C];
    float field_144;
    unsigned char pad_148[0x28];
    unsigned char field_170;
    unsigned char pad_171[0x1];
    signed char field_172;
    signed char field_173;
    unsigned char pad_174[0x4];
    unsigned char field_178;
    unsigned char field_179;
};

extern UnkStruct_D_00522660 D_00522660;
extern float karTrafficOncomingSwerveSpeed[];  // [G] element count unknown
extern unsigned char _gu8NextFlashPattern;

// [L] low name CB3TrafficParam::CalculateTargetParamMatrix(float, CGtMatrix3x4*) (research/retail_names.csv); retail's a2/a3
// at the call are leftovers (the callee overwrites both before reading).
extern "C" void func_001618C0(UnkStruct_001710E0_2 *, UnkStruct_001710E0_8 *, float);

// 0x001710E0
bool CB3TrafficVehicle::ApplyNiceOncomingBehaviour(CB3TrafficRaceCarInfo *p0, int p1, float p2)
{
    UnkStruct_001710E0_8 local;
    bool r = false;
    UnkStruct_001710E0_2 *t = field_114;
    UnkStruct_001710E0_e1 *lane = &D_00522660.field_34210[t->field_49];
    float *spp = (float *)((char *)field_F0 + p1 * 4);  // [G] byte-offset form: retail's `addu v0,v0,s4` operand order
    float sp = *spp;
    bool far = true;
    if (sp < 0.0f) {
        if (!(p2 < 20.0f))
            return false;
        far = false;
    }
    CGtV3d diff = p0[p1].field_30 - lane->field_30;
    if (far) {
        float d = GtMathPs2::DotProduct(diff, lane->field_0);
        if (d > -20.0f && d < 20.0f) {
            func_001618C0(t, &local, t->field_30 + sp / 6.0f);
            float d2 = GtMathPs2::DotProduct(p0[p1].field_30 - local.field_30, local.field_0);
            if ((d2 > -6.0f && d2 < -1.0f) || (d2 > 1.0f && d2 < 6.0f)) {
                if (d2 > 0.0f)
                    field_114->field_28 = field_114->field_28 + 1.5f;
                else
                    field_114->field_28 = field_114->field_28 - 1.5f;
                field_124 = GtMath::Max(karTrafficOncomingSwerveSpeed[field_173], field_124);
                r = true;
            }
        }
    } else {
        float d = GtMathPs2::DotProduct(diff, lane->field_0);
        if ((d > -6.0f && d < -1.0f) || (d > 1.0f && d < 6.0f)) {
            if (d > 0.0f)
                t->field_28 = t->field_28 + 1.5f;
            else
                t->field_28 = t->field_28 - 1.5f;
            field_124 = GtMath::Max(karTrafficOncomingSwerveSpeed[field_173], field_124);
            r = true;
        }
    }
    if (r && *spp > 0.0f) {
        if (field_172 == 0) {
            field_172 = 2;
            field_178 = _gu8NextFlashPattern;
            _gu8NextFlashPattern = (_gu8NextFlashPattern + 1) % 5;
            field_144 = 0.0f;
            field_179 = 0;
        }
        field_170 = p1;
    }
    return r;
}
