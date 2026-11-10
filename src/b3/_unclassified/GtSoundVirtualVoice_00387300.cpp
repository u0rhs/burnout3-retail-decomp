// CGtSoundVirtualVoice::SetBias(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVirtualVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it ((uchar)(255.0f*x)).

struct UnkStruct_00387300_1 {
    unsigned char pad_0[0x87];
    unsigned char field_87;
};
struct UnkStruct_00387300 {
    unsigned char pad_0[4];
    UnkStruct_00387300_1 *field_4;
};
extern "C" void SetBias__20CGtSoundVirtualVoiceFf(UnkStruct_00387300 *self, float p1)
{
    self->field_4->field_87 = (unsigned char)(255.0f * p1);
}
