// CGtSoundVirtualVoice::Stop() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVirtualVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundVirtualVoice;

class CGtSoundVirtualVoice {
public:
    void Stop();

    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x20];
    int field_28;
    unsigned char field_2C;
    unsigned char pad_2D[0x2];
    unsigned char field_2F;
};

extern "C" void _rwaVirtualVoiceSetTrigger(int, int);
extern "C" void _rwaVirtualVoiceSetWave(int, int);

// 0x00387A40
void CGtSoundVirtualVoice::Stop()
{
    _rwaVirtualVoiceSetTrigger(field_4, 0);
    _rwaVirtualVoiceSetWave(field_4, 0);
    field_2C = 0;
    field_28 = 0;
    field_2F = (field_2F & 1);
}
