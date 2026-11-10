// CB3VehicleDeform::GetFlyingObjectIndex(CB3VehicleData*,EVehicleFlyingBit) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleDeform.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extern C self-explicit, for loop return i).

struct UnkStruct_a167_vd { unsigned char pad_0[0xC]; signed char field_C; unsigned char pad_D[0xAC4 - 0xD]; int field_AC4[1]; };
extern "C" int GetFlyingObjectIndex__16CB3VehicleDeformFP14CB3VehicleData17EVehicleFlyingBit(UnkStruct_a167_vd * self, int p0)
{
    int i;
    for (i = 0; i < self->field_C; i++) {
        if (p0 == self->field_AC4[i]) return i;
    }
    return -1;
}
