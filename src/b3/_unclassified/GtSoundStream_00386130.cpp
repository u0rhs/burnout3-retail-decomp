// CGtSoundStream::ApplyVolumesAndPitch() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundStream.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (status ==6 || ==5 merged; pitch ternary; element ptr into D_01EA4B00; unsigned loop counter).

// CGtSoundStream::ApplyVolumesAndPitch() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundStream.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundStream;
class CGtSoundVoice;
struct UnkStruct_00386130_4;
struct UnkStruct_00386130_e0;
struct UnkStruct_D_01EA4B00;

struct UnkStruct_00386130_e0 {
    float field_0;
    float field_4;
};

struct UnkStruct_D_01EA4B00 {
    UnkStruct_00386130_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00386130_4 {
    int field_0;
    float field_4;
};

class CGtSoundVoice {
public:
    static float _mrMasterPitch;
};

class CGtSoundStream {
public:
    void ApplyVolumesAndPitch();

    unsigned char pad_0[0x1A4];
    float field_1A4[1];  // [G] element count unknown
    unsigned char pad_1A8[0x24];
    int field_1CC;
    unsigned char pad_1D0[0x1C];
    unsigned char field_1EC;
    unsigned char field_1ED;
    unsigned char pad_1EE[0x2];
    int field_1F0;
};

extern UnkStruct_D_01EA4B00 D_01EA4B00;

extern "C" int _rwaStreamGetStatus(int);
extern "C" void _rwaStreamSetStreamGain(int, UnkStruct_00386130_4 *);
extern "C" void func_002A2B80(int, float);

// 0x00386130
void CGtSoundStream::ApplyVolumesAndPitch()
{
    UnkStruct_00386130_4 local;
    if (_rwaStreamGetStatus(field_1CC) == 6 || _rwaStreamGetStatus(field_1CC) == 5) {
        float v = (field_1ED & 16) ? 1.0f : CGtSoundVoice::_mrMasterPitch;
        UnkStruct_00386130_e0 * e = &D_01EA4B00.field_0[field_1EC];
        float t1 = e->field_4;
        float t2 = e->field_0;
        for (unsigned int i = 0; i < field_1F0; i++) {
            local.field_0 = i;
            local.field_4 = field_1A4[i] * t1;
            _rwaStreamSetStreamGain(field_1CC, &local);
        }
        func_002A2B80(field_1CC, t2 * v);
    }
}
