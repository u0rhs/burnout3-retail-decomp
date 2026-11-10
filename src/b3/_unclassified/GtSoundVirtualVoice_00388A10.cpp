// CGtSoundVirtualVoice::Construct(RwaSPU2Output*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVirtualVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class RwaSPU2Output;

class CGtSoundVirtualVoice;

class CGtSoundVirtualVoice {
public:
    void Construct(RwaSPU2Output* p0);

    unsigned char field_0;
    unsigned char pad_1[0x3];
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    float field_14;
    float field_18;
    int field_1C;
    int field_20;
    unsigned char pad_24[0x4];
    int field_28;
    unsigned char field_2C;
    unsigned char field_2D;
    unsigned char field_2E;
    unsigned char field_2F;
};

extern "C" int RwaVirtualVoiceCreate(int, int, int, int, int);

// 0x00388A10
void CGtSoundVirtualVoice::Construct(RwaSPU2Output* p0)
{
    field_8 = 0;
    field_2C = 0;
    field_C = 0;
    field_10 = 0;
    field_2D = 0;
    field_2E = 0;
    field_28 = 0;
    field_14 = 1.0f;
    field_18 = ((float)22000);
    field_1C = 0;
    field_20 = 0;
    field_2F = 0;
    int r0 = RwaVirtualVoiceCreate(0, 0, 0, 0, 0);
    field_4 = r0;
    field_0 = 0;
}
