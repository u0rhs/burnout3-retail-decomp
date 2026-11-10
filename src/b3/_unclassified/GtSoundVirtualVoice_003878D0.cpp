// CGtSoundVirtualVoice::Pause() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVirtualVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (twin of RealVoice::Pause; case 0 plain if(p1)).

struct UnkStruct_003878D0 {
    unsigned char pad_0[0x2C];
    unsigned char field_2C;
    unsigned char field_2D;
};
extern "C" void UpdatePause__20CGtSoundVirtualVoiceFv(UnkStruct_003878D0 *self);
extern "C" void Pause__20CGtSoundVirtualVoiceFv(UnkStruct_003878D0 *self, bool p1)
{
    switch (self->field_2C) {
    case 2:
        if (p1 == false) self->field_2C = 3;
        break;
    case 0:
        if (p1) self->field_2C = 1;
        break;
    case 3:
        if (p1 != false) {
            self->field_2D = 5 - self->field_2D;
            self->field_2C = 1;
        }
        break;
    case 1:
        if (p1 != true) {
            self->field_2D = 5 - self->field_2D;
            self->field_2C = 3;
        }
        break;
    }
    UpdatePause__20CGtSoundVirtualVoiceFv(self);
}
