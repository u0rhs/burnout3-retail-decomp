// CGtSoundRealVoice::Update(float,float,float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundRealVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (shared clamp tail after if/else; t5 read before t4 (delay slot)).

struct UnkStruct_003856D0_e0 { float field_0; float field_4; };
struct UnkStruct_D_01EA4B00 { UnkStruct_003856D0_e0 field_0[1]; unsigned char pad_8[0x8]; };
struct UnkStruct_00385A00_v {
    unsigned char pad_0[0x5C];
    unsigned short field_5C;
    unsigned char pad_5E[0x3A];
    float field_98;
    unsigned char pad_9C[4];
    float field_A0;
};
class CGtSoundVoice {
public:
    static float _mrMasterPitch;
    static float _mrMasterVolume;
};
extern UnkStruct_D_01EA4B00 D_01EA4B00;
class CGtSoundRealVoice;
extern "C" void UpdatePause__17CGtSoundRealVoiceFv(CGtSoundRealVoice *);
class CGtSoundRealVoice {
public:
    void Update(float, float, float, float);
    unsigned char pad_0[0xC];
    float field_C;
    float field_10;
    UnkStruct_00385A00_v *field_14;
    unsigned char field_18;
    unsigned char pad_19[1];
    unsigned char field_1A;
    unsigned char field_1B;
    unsigned char pad_1C[1];
    unsigned char field_1D;
};
// 0x00385A00
void CGtSoundRealVoice::Update(float, float, float, float)
{
    if (field_18 != 2) {
        UnkStruct_003856D0_e0 *e = &D_01EA4B00.field_0[field_1A];
        float t5 = e->field_4;
        float t4 = e->field_0;
        if (field_1B & 0x10) {
            field_14->field_5C = (field_14->field_5C | 1);
            field_14->field_98 = field_10 * t4;
        } else {
            field_14->field_5C = (field_14->field_5C | 1);
            field_14->field_98 = t4 * (field_10 * CGtSoundVoice::_mrMasterPitch);
        }
        float x;
        if (field_1D != 0) {
            x = field_C * t5;
        } else {
            x = t5 * (field_C * CGtSoundVoice::_mrMasterVolume);
        }
        float v10 = (x < 0.0f) ? 0.0f : ((x > 1.0f) ? 1.0f : x);
        field_14->field_5C = (field_14->field_5C | 2);
        field_14->field_A0 = v10;
    }
    UpdatePause__17CGtSoundRealVoiceFv(this);
}
