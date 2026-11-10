// CB3EffectsManager::UpdateCrashingTrafficEffects(CB3VehiclePhysics*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EffectsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near27: float one shared by the 3 clamps, d = 1.0f - r4 with r4 a reference to lighting.field_4 (pointer store), N227 sdata const floats).

// CB3EffectsManager::UpdateCrashingTrafficEffects(CB3VehiclePhysics*) -- hand-matched (near27).
// [C] name: the mangled symbol in retail's tables. Classes/structs declared locally with only the touched fields;
// field names are placeholders, types [G] (instruction widths).
#include "b3/GtMath.h"
class CB3VehiclePhysics;
class CGtMatrix3x4;
// [G] own-unit .sdata floats (unit_00254C90.sdata), read-only: const + sdata keeps $gp addressing (N227)
extern __declspec(sdata) const float D_004E19AC;
extern __declspec(sdata) const float D_004E19B0;
extern __declspec(sdata) const float D_004E19B4;
extern __declspec(sdata) const float D_004E19B8;
extern __declspec(sdata) const float D_004E19BC;
extern __declspec(sdata) const float D_004E29E8;
class CB3SoundTrafficManager {
public:
    void CrashingTraffic(CB3VehiclePhysics *);
    unsigned char pad_0[0x10];
};
extern CB3SoundTrafficManager D_01E78E50;
struct UnkStruct_0026_X { unsigned char pad_0[0x5C]; float field_5C; float field_60; };
struct UnkStruct_0026_Y { unsigned char pad_0[0x4AC]; signed char field_4AC[1]; };
struct UnkStruct_0026_phys { unsigned char pad_0[0xCC0]; UnkStruct_0026_X * field_CC0; UnkStruct_0026_Y * field_CC4; unsigned char pad_CC8[0x4A1]; signed char field_1169; };
class CB3EffectsManager {
public:
    class CLighting {
    public:
        float field_0;
        float field_4;
        unsigned char pad_8[8];
    };
    void UpdateCrashingTrafficEffects(CB3VehiclePhysics *);
    void UpdateCrashingVehicleEffectsPoints(CB3VehiclePhysics *, const CLighting &);
    unsigned char pad_0[0x1F854];
    int field_1F854;
};
extern "C" void UpdateWheelEffects__17CB3EffectsManagerFP17CB3VehiclePhysicsUiPCQ29GtMathPs212CGtMatrix3x4RCQ217CB3EffectsManager9CLightingb(CB3EffectsManager *, CB3VehiclePhysics *, unsigned int, const CGtMatrix3x4 *, const CB3EffectsManager::CLighting &, bool, int);
// 0x00260DB0
void CB3EffectsManager::UpdateCrashingTrafficEffects(CB3VehiclePhysics * p0)
{
    UnkStruct_0026_phys * ph = (UnkStruct_0026_phys *)p0;
    UnkStruct_0026_X * x = ph->field_CC0;
    UnkStruct_0026_Y * y = ph->field_CC4;
    float f4 = x->field_5C;
    float f3 = x->field_60;
    float f6 = GtMath::Min(f3, f4);
    float t0 = GtMath::Max(D_004E19AC * (f4 - D_004E29E8), 0.0f);
    float one = 1.0f;  // [G] one 1.0 shared by the three clamps (retail keeps it in f4 across the if/else); the 1.0 in d is rematerialised
    float a = GtMath::Min(t0, one);
    float b = GtMath::Min(GtMath::Max(D_004E19B4 * (f3 - D_004E19B0), 0.0f), one);
    float sq = (a + b) * (a + b);
    float r;
    if (a < b) {
        r = sq + a;
    } else {
        r = sq + b;
    }
    CLighting lighting;
    float c = GtMath::Min(GtMath::Max(r * D_004E19BC, 0.0f), one);
    float &r4 = lighting.field_4;  // [G] reference: retail stores through addiu v0,sp,0x64 and re-reads the stored value for d
    r4 = c;
    float d = 1.0f - r4;
    lighting.field_0 = GtMath::Min(GtMath::Max(f6 * D_004E19B8, 0.0f), d);
    int s0 = field_1F854 & 1;
    for (int i = 0; i < ph->field_1169; i++) {
        int w = i ^ s0;
        if (y->field_4AC[w] != 3) {
            UpdateWheelEffects__17CB3EffectsManagerFP17CB3VehiclePhysicsUiPCQ29GtMathPs212CGtMatrix3x4RCQ217CB3EffectsManager9CLightingb(this, p0, w, 0, lighting, true, -1);
        }
    }
    UpdateCrashingVehicleEffectsPoints(p0, lighting);
    D_01E78E50.CrashingTraffic(p0);
}
