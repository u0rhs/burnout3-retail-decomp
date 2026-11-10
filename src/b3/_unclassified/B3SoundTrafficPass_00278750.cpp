// CB3SoundTrafficPass::Prepare(ETrafficVehicleCategories,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTrafficPass.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum ETrafficVehicleCategories {};

class CB3SoundTrafficPass;
class CGtSoundVirtualVoice;

class CGtSoundVirtualVoice {
public:
    int IsPlaying();
    void Stop();

    unsigned char pad_0[0xC];
    int field_C;
};

class CB3SoundTrafficPass {
public:
    int Prepare(ETrafficVehicleCategories p0, int p1);

    CGtSoundVirtualVoice * field_0;
    unsigned char field_4;
    unsigned char field_5;
    unsigned char field_6;
    unsigned char pad_7[0x19];
    int field_20;
    float field_24;
    float field_28;
    unsigned char pad_2C[0x8];
    int field_34;
    int field_38;
};

// 0x00278750
int CB3SoundTrafficPass::Prepare(ETrafficVehicleCategories p0, int p1)
{
    CGtSoundVirtualVoice * t0 = field_0;
    if (t0 != 0) {
        int r0 = t0->IsPlaying();
        if (r0 != 0) {
            CGtSoundVirtualVoice * t1 = field_0;
            if (field_34 == t1->field_C) {
                t1->Stop();
            }
        }
        field_0 = 0;
    }
    field_6 = 60;
    field_4 = 0;
    field_34 = 0;
    field_0 = 0;
    field_5 = 0;
    field_4 = 0;
    field_24 = -1.0f;
    field_28 = -1.0f;
    field_20 = p0;
    field_6 = 0;
    field_38 = p1;
    return 1;
}
