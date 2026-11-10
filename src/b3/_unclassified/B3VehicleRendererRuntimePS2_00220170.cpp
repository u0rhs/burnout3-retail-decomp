// CB3VehicleRenderer::FrustumTestDamagedVehicle(CB3VehicleEssentialParams*,CB3VehicleParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleRendererRuntimePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (near4: CGtSphere local + header SetPosition/SetRadius (hdrrd), cfg pointer read first; exact).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CB3VehicleRenderer;
struct UnkStruct_2201_cfg { unsigned char pad_0[0xC]; signed char field_C; signed char field_D; unsigned char pad_E[6]; float field_14; };
struct CB3VehicleEssentialParams {
    unsigned char pad_0[0x30];
    CGtV3d field_30;
    UnkStruct_2201_cfg *field_40;
    unsigned char pad_44[0x17];
    unsigned char field_5B;
};
struct CB3VehicleParams {
    unsigned char pad_0[0x4AC];
    signed char field_4AC[6];
    signed char field_4B2[0xB70];
    unsigned char field_1022;
    unsigned char field_1023;
};
struct UnkStruct_00220270_1 { CGtSphere field_0; };
extern "C" int func_002202D0(UnkStruct_00220270_1 *);
class CB3VehicleRenderer {
public:
    void FrustumTestDamagedVehicle(CB3VehicleEssentialParams *p, CB3VehicleParams *q);
};
// 0x00220170
void CB3VehicleRenderer::FrustumTestDamagedVehicle(CB3VehicleEssentialParams *p, CB3VehicleParams *q)
{
    UnkStruct_00220270_1 local;
    UnkStruct_2201_cfg *c = p->field_40;
    local.field_0.SetPosition(p->field_30);
    local.field_0.SetRadius(c->field_14);
    int res = func_002202D0(&local);
    bool hit = false;
    for (int i = 0; i < c->field_C; i++) {
        if (q->field_4B2[i] == 3) { hit = true; break; }
    }
    for (int i = 0; i < c->field_D; i++) {
        if (q->field_4AC[i] == 3) { hit = true; break; }
    }
    if (q->field_1023 != 0) hit = true;
    p->field_5B = res;
    q->field_1022 = hit;
}
