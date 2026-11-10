// CGtSoundRealVoice::Pause() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundRealVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (bool p1 (Fv name reads a1); switch 2,0,3,1; ==/!= false forms).

struct UnkStruct_00385540 {
    unsigned char pad_0[0x18];
    unsigned char field_18;
    unsigned char field_19;
};
extern "C" void UpdatePause__17CGtSoundRealVoiceFv(UnkStruct_00385540 *self);
extern "C" void Pause__17CGtSoundRealVoiceFv(UnkStruct_00385540 *self, bool p1)
{
    switch (self->field_18) {
    case 2:
        if (p1 == false) self->field_18 = 3;
        break;
    case 0:
        if (p1 == true) self->field_18 = 1;
        break;
    case 3:
        if (p1 != false) {
            self->field_19 = 5 - self->field_19;
            self->field_18 = 1;
        }
        break;
    case 1:
        if (p1 != true) {
            self->field_19 = 5 - self->field_19;
            self->field_18 = 3;
        }
        break;
    }
    UpdatePause__17CGtSoundRealVoiceFv(self);
}
