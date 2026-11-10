// CB3StreamedTrack::ComputeVehicleRenderData(CB3VehicleEssentialParams*,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamedTrack.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a79: early return on field_44==0, then plain if (field_5A >= 0) call).

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x20];
};
extern UnkStruct_D_00522660 D_00522660;
struct CB3VehicleEssentialParams {
    unsigned char pad_0[0x30];
    unsigned char field_30[0x10];
    unsigned char pad_40[0x1A];
    signed char field_5A;
    unsigned char pad_5B;
    unsigned char field_5C[0x10];
};
extern "C" void GetIrradiance__16CB3StreamedTrackFiQ29GtMathPs26CGtV3dP16CGtIrradianceMapf(void *, int, const void *, void *, float);
class CB3StreamedTrack {
public:
    void ComputeVehicleRenderData(CB3VehicleEssentialParams *, float);
    unsigned char pad_0[0x1C];
    int field_1C;
    unsigned char pad_20[0x24];
    unsigned char field_44;
};
// 0x003012D0
void CB3StreamedTrack::ComputeVehicleRenderData(CB3VehicleEssentialParams *p, float f)
{
    if (field_44 == 0) {
        return;
    }
    if (p->field_5A >= 0) {
        GetIrradiance__16CB3StreamedTrackFiQ29GtMathPs26CGtV3dP16CGtIrradianceMapf((char *)&D_00522660 + field_1C * 460 + 0x12A348, p->field_5A, p->field_30, p->field_5C, f);
    }
}
