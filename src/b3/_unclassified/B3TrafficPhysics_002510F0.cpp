// CB3TrafficPhysics::Prepare(CB3TrafficVehicle*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3TrafficPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (v275: essential-params struct copy + matrix loops, bool return (v0=1 reuse), local Plus/operator*(WAxisType)/vsuby/SetGtV3d stand-ins, N140 pad x4 [G]).

#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

struct UnkStruct_002510F0_lane {
    unsigned char pad_0[0xC];
};
struct UnkStruct_002510F0_prm {
    unsigned char pad_0[0xC];
    signed char field_C;
    signed char field_D;
    unsigned char pad_E[0xA];
    float field_18;
    float field_1C[0x1B];
    unsigned char pad_88[0xAF8];
    CGtMatrix3x4 field_B80[6];
    CGtMatrix3x4 field_D00[0x27];
    UnkStruct_002510F0_lane *field_16C0;
    unsigned char pad_16C4[0x4];
    signed char field_16C8;
};
// [L] CB3VehicleEssentialParams (Prepare__17CB3VehiclePhysics's first parameter type), 0x80 bytes
struct UnkStruct_002510F0_ess {
    u_long128 field_0[4];
    UnkStruct_002510F0_prm *field_40;
    float field_44;
    float field_48;
    float field_4C;
    float field_50;
    float field_54;
    unsigned char field_58;
    signed char field_59;
    signed char field_5A;
    signed char field_5B;
    int field_5C[9];
};
struct UnkStruct_002510F0_204 {
    unsigned char pad_0[0x20];
    CGtV3d field_20;
};
class CB3TrafficVehicle {
public:
    unsigned char pad_0[0x70];
    UnkStruct_002510F0_ess field_70;
    unsigned char pad_F0[0x81];
    unsigned char field_171;
    unsigned char pad_172;
    signed char field_173;
    unsigned char pad_174[0x2];
    unsigned char field_176;
    unsigned char field_177;
};
struct UnkStruct_gaVehicleReflectivityData_e {
    unsigned char pad_0[0xF0];
};
struct UnkStruct_D_01D9BB10_e {
    unsigned char pad_0[0xB0];
};
extern UnkStruct_gaVehicleReflectivityData_e gaVehicleReflectivityData[];
extern UnkStruct_D_01D9BB10_e D_01D9BB10[];

class CB3TrafficPhysics {
public:
    bool Prepare(CB3TrafficVehicle *, int);

    unsigned char pad_0[0xB0];
    CGtV3dPlus field_B0;
    CGtV3d field_C0;
    unsigned char pad_D0[0x100];
    CGtV3d field_1D0;
    CGtV3d field_1E0;
    unsigned char pad_1F0[0x4];
    float field_1F4;
    unsigned char pad_1F8[0xC];
    UnkStruct_002510F0_204 *field_204;
    unsigned char pad_208[0x1158];
    UnkStruct_002510F0_ess field_1360;
    CGtMatrix3x4 field_13E0[6];
    CGtMatrix3x4 field_1560[12];
    unsigned char pad_1860[0x20];
    UnkStruct_gaVehicleReflectivityData_e *field_1880;
    unsigned char pad_1884[0x2C];
    float field_18B0[6];
    unsigned char pad_18C8[0xB3B];
    unsigned char field_2403;
    UnkStruct_002510F0_lane *field_2404;
    unsigned char pad_2408[0x18];
    int field_2420;
    int field_2424;
    unsigned char field_2428;
    unsigned char field_2429;
    unsigned char field_242A;
    unsigned char field_242B;
    unsigned char field_242C;
};

extern "C" void *memset(void *, int, unsigned int);
extern "C" void Prepare__17CB3VehiclePhysicsFP25CB3VehicleEssentialParamsP16CB3VehicleParams(void *, void *, void *);
extern "C" void func_001AB610(void *, void *);
extern "C" void CopyToPhysics__24CB3VehiclePhysicsAttribsFP17CB3VehiclePhysics(void *, void *);
extern "C" void SetRealisticMomentsOfInertia__16CB3CollidingBodyFv(void *);

// [L] CGtV3dPlus::Plus() (B3O0PCH map, 52 bytes): the w lane, as CGtV4d::W(); local stand-in
static inline WAxisType func_002510F0_inl1(const CGtV3dPlus &p) { return WAxisType(p.mData); }
// [L] CGtV3d::operator*(WAxisType) (B3O0PCH map, 68 bytes); local stand-in, compiler-chosen registers
static inline CGtV3d func_002510F0_inl2(const CGtV3d &v, WAxisType w)
{
    u_long128 t;
    asm("vmulw.xyz %0, %1, %2w" : "=j"(t) : "j"(v.mData), "j"(w.lVector));
    return CGtV3d(t);
}
// [L] YAxisType operator-(YAxisType, YAxisType) written in place on the first operand; local stand-in
static inline YAxisType func_002510F0_inl3(YAxisType a, YAxisType b)
{
    asm("vsuby.y %0, %0, %1y" : "+j"(a.lVector) : "j"(b.lVector));
    return YAxisType(a.lVector);
}

// [L] CGtV3dPlus::SetGtV3d(CGtV3d) (B3O0PCH map): the header body, the result read back through its address ([G]: the
// N129 mechanism keeps its slot -- the one slot retail has below the lane copy)
static inline void func_002510F0_inl5(CGtV3dPlus &p, CGtV3d v) { u_long128 m = p.mData; asm("vadd.xyz %0, $vf0, %1" : "+j"(m) : "j"(v.mData)); p.mData = *(const u_long128 *)&m; }
// FAKEMATCH [G]: N140 frame pad -- retail's frame keeps four more 16-byte slots above the lane copy (dead lane /
// by-value inline temporaries of the real GtMathPs2 inlines, not reproduced by the stand-ins)
struct UnkStruct_002510F0_pad { int x[16]; UnkStruct_002510F0_pad() {} ~UnkStruct_002510F0_pad() {} };
// [L] CB3TrafficPhysics::Prepare(CB3TrafficVehicle*, int): copies the vehicle's essential params (+0x70, 0x80 bytes) and
// per-type matrices, then the physics set-up calls; returns true (retail keeps v0 = 1 for the last store) [L]
// 0x002510F0
bool CB3TrafficPhysics::Prepare(CB3TrafficVehicle *v, int idx)
{
    UnkStruct_002510F0_pad pad0;
    memset(&field_13E0, 0, 0x1040);
    field_1360 = v->field_70;
    for (int i = 0; i < field_1360.field_40->field_C; i++)
        field_1560[i] = field_1360.field_40->field_D00[i];
    for (int j = 0; j < field_1360.field_40->field_D; j++) {
        field_13E0[j] = field_1360.field_40->field_B80[j];
        field_18B0[j] = field_1360.field_40->field_18 * field_1360.field_40->field_1C[j];
    }
    field_1880 = &gaVehicleReflectivityData[v->field_176];
    field_1360.field_44 = 0.0f;
    field_1360.field_48 = 1.0f;
    field_1360.field_4C = 0.0f;
    field_1360.field_50 = 1.0f;
    field_2420 = v->field_173;
    field_242A = v->field_176;
    Prepare__17CB3VehiclePhysicsFP25CB3VehicleEssentialParamsP16CB3VehicleParams(this, &field_1360, &field_13E0);
    func_001AB610(this, &field_1360);
    CopyToPhysics__24CB3VehiclePhysicsAttribsFP17CB3VehiclePhysics(&D_01D9BB10[v->field_176], this);
    SetRealisticMomentsOfInertia__16CB3CollidingBodyFv(this);
    field_1F4 = func_002510F0_inl3(field_1D0.Y(), field_1E0.Y()) * 0.3f;
    field_1360.field_58 = v->field_70.field_58;
    field_B0.SetPlus(v->field_70.field_54);
    field_C0 = field_204->field_20;
    func_002510F0_inl5(field_B0, func_002510F0_inl2(field_C0, func_002510F0_inl1(field_B0)));
    field_242B = idx;
    field_2429 = v->field_177;
    field_2424 = 0;
    field_2428 = 0;
    field_2403 = 0;
    if (field_1360.field_40->field_16C8 > 0)
        field_2404 = &field_1360.field_40->field_16C0[v->field_171];
    else
        field_2404 = 0;
    field_242C = 1;
    return true;
}
