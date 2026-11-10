// CGtSoundRealVoice::Construct(RwaSPU2Output*,CGtSoundRealVoiceDSPSend*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundRealVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class RwaSPU2Output;
class CGtSoundRealVoiceDSPSend;

class CGtSoundRealVoice;
struct UnkStruct_00385E20_1;

struct UnkStruct_00385E20_1 {
    int field_0;
    unsigned char pad_4[0x4];
};

class CGtSoundRealVoice {
public:
    void Construct(RwaSPU2Output* p0, CGtSoundRealVoiceDSPSend* p1, int p2);

    int field_0;
    int field_4;
    int field_8;
    float field_C;
    float field_10;
    int field_14;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char field_1A;
    unsigned char field_1B;
};

extern "C" int RwaSPU2VoiceCreate(RwaSPU2Output*, UnkStruct_00385E20_1 *, int, int, int);

// 0x00385E20
void CGtSoundRealVoice::Construct(RwaSPU2Output* p0, CGtSoundRealVoiceDSPSend* p1, int p2)
{
    UnkStruct_00385E20_1 local;  // [G] the frame's one local (size: up to the frame top)
    field_0 = 0;
    field_18 = 0;
    field_4 = 0;
    field_8 = 0;
    field_19 = 0;
    field_1A = 0;
    field_1B = 0;
    field_C = 1.0f;
    field_10 = ((float)22000);
    local.field_0 = 1;
    int r0 = RwaSPU2VoiceCreate(p0, &local, 0, 0, 0);
    field_14 = r0;
}
