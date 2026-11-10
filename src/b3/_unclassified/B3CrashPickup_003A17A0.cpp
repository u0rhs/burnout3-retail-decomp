// CB3CrashPickup::Prepare(CB3CrashModePickupStruct*,CGtTexture**) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashPickup.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (extern C self-explicit).

struct UnkStruct_a167_cp0 { unsigned char pad_10[0x10]; unsigned char field_10; };
struct UnkStruct_a167_cp { UnkStruct_a167_cp0 * field_0; unsigned char pad_4[4]; unsigned char field_8; unsigned char field_9; signed char field_A; unsigned char pad_B[1]; void * field_C; };
extern "C" int Prepare__14CB3CrashPickupFP24CB3CrashModePickupStructPP10CGtTexture(UnkStruct_a167_cp * self, UnkStruct_a167_cp0 * p0, void ** p1)
{
    self->field_0 = p0;
    self->field_8 = 0;
    self->field_9 = 0;
    self->field_A = -1;
    self->field_C = p1[self->field_0->field_10];
    return 1;
}
