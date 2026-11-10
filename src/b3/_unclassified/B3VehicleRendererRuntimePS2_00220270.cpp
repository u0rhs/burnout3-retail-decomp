// CB3VehicleRenderer::FrustumTestUndamagedVehicle(CB3VehicleEssentialParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleRendererRuntimePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (near4: hdrrd CGtSphere SetPosition/SetRadius draft (header N-hdrrd API), exact).

// CB3VehicleRenderer::FrustumTestUndamagedVehicle(CB3VehicleEssentialParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleRendererRuntimePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CB3VehicleEssentialParams;

class CB3VehicleRenderer;
struct CB3VehicleEssentialParams;
struct UnkStruct_00220270_1;
struct UnkStruct_00220270_2;

struct CB3VehicleEssentialParams {
    unsigned char pad_0[0x30];
    GtMathPs2::CGtV3d field_30;
    UnkStruct_00220270_2 * field_40;
    unsigned char pad_44[0x17];
    unsigned char field_5B;
};

struct UnkStruct_00220270_1 {
    GtMathPs2::CGtSphere field_0;
};

struct UnkStruct_00220270_2 {
    unsigned char pad_0[0x14];
    float field_14;
};

class CB3VehicleRenderer {
public:
    void FrustumTestUndamagedVehicle(CB3VehicleEssentialParams* p0);
};

extern "C" int func_002202D0(UnkStruct_00220270_1 *);

// 0x00220270
void CB3VehicleRenderer::FrustumTestUndamagedVehicle(CB3VehicleEssentialParams* p0)
{
    UnkStruct_00220270_1 local;  // [G] the frame's one local (size: up to the frame top)
    local.field_0.SetPosition(p0->field_30);
    local.field_0.SetRadius(p0->field_40->field_14);
    int r0 = func_002202D0(&local);
    p0->field_5B = r0;
}
