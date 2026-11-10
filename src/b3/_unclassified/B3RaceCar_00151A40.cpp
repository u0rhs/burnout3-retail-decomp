// CB3RaceCar::Draw() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near11: header operator- + GetSquaredLength instead of stand-ins; drop 16-byte pad).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CB3RaceCar;
class CB3VehicleRenderer;
enum EVehicleLOD {};
struct CB3VehicleEssentialParams;
struct CB3VehicleParams;
class CB3EffectsManager { public: unsigned char pad[0x20]; void ActuallyRenderRaceCarImmediateEffects(CB3RaceCar *); };
class CB3VehicleRenderer { public: void RenderVehicle(const CB3VehicleEssentialParams *, const CB3VehicleParams *, EVehicleLOD); unsigned char pad_0[0x18]; unsigned char field_18; unsigned char pad_19[0xF7]; };
struct UnkStruct_a187_cam { unsigned char pad_0[0x20]; CGtV3d field_20; };
struct UnkStruct_a187_g { unsigned char pad_0[0x68]; UnkStruct_a187_cam *field_68; unsigned char pad_6C[0x24]; float field_90; };
struct UnkStruct_a187_f { float field_0; };
extern UnkStruct_a187_g *D_00666270[4];
extern unsigned char D_00665F26[16];
extern float D_00665F30[3];
extern CB3VehicleRenderer gVehicleRenderer;
extern CB3EffectsManager D_01D9D200;
class CB3RaceCar {
public:
    void Draw();
    CGtMatrix3x4 field_0;
    float field_40;
    float field_44;
    float field_48;
    float field_4C;
    float field_50;
    unsigned char pad_54[0x2C];
    unsigned char field_80[0x10];
    unsigned char pad_90[0x1858];
    unsigned char field_18E8;
    unsigned char field_18E9;
    unsigned char field_18EA;
    unsigned char field_18EB;
    unsigned char pad_18EC[2];
    unsigned char field_18EE;
    unsigned char pad_18EF[0x31];
    CGtMatrix3x4 field_1920;
    unsigned char pad_1960[0x3B];
    unsigned char field_199B;
};
// 0x00151A40
// near11: header CGtV3d operator- + GetSquaredLength replace the a210 stand-ins (frame then exact without the 16-byte pad).
void CB3RaceCar::Draw()
{
    if (field_18E8 == 0 || D_00665F26[0] == 0) {
        return;
    }
    UnkStruct_a187_g *g = D_00666270[0];
    CGtV3d d = *(const CGtV3d *)((char *)this + 0x30) - g->field_68->field_20;
    float d2 = d.GetSquaredLength();
    float r = g->field_90;
    int lod;
    if (d2 > (D_00665F30[2] * r) * (D_00665F30[2] * r)) {
        lod = 0;
    } else if (d2 > (D_00665F30[1] * r) * (D_00665F30[1] * r)) {
        lod = 1;
    } else if (d2 > (D_00665F30[0] * r) * (D_00665F30[0] * r)) {
        lod = 2;
    } else {
        lod = 3;
    }
    field_4C = 0.0f;
    field_50 = 1.0f;
    field_44 = 0.0f;
    field_48 = 1.0f;
    CGtMatrix3x4 saved;
    if (field_199B != 0) {
        saved = field_0;
        field_0 = field_1920;
    }
    unsigned char s0;
    if (field_18EE != 0) {
        s0 = gVehicleRenderer.field_18;
        gVehicleRenderer.field_18 = 1;
    }
    gVehicleRenderer.RenderVehicle((const CB3VehicleEssentialParams *)this, (const CB3VehicleParams *)((char *)this + 0x80), (EVehicleLOD)lod);
    if (field_18EE != 0) {
        gVehicleRenderer.field_18 = s0;
    }
    if (field_18EA == 0) {
        D_01D9D200.ActuallyRenderRaceCarImmediateEffects(this);
    }
    if (field_199B != 0) {
        field_0 = saved;
    }
}
