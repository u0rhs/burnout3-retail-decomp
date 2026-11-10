// CGtSoundVoiceManager::Construct(RwaSPU2Output*,CGtSoundRealVoiceDSPSend*,int,CGtSoundListenerManager*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVoiceManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class RwaSPU2Output;
class CGtSoundRealVoiceDSPSend;
class CGtSoundListenerManager;

class CGtSoundVoiceManager;
struct RwaSPU2Output;
struct UnkStruct_00389380_2;
struct UnkStruct_00389380_e1;
struct UnkStruct_00389380_e2;
struct UnkStruct_00389380_e3;
struct UnkStruct_D_01EA4B00;

struct RwaSPU2Output {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    unsigned char pad_10[0x18];
    unsigned char field_28;
};

struct UnkStruct_00389380_2 {
    int field_0;
    unsigned char pad_4[0x18];
    unsigned char field_1C;
    unsigned char pad_1D[0xB];
    int field_28;
    unsigned char pad_2C[0x4];
};

struct UnkStruct_00389380_e1 {
    float field_0;
    float field_4;
};

struct UnkStruct_D_01EA4B00 {
    UnkStruct_00389380_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00389380_e2 {
    unsigned char pad_0[0x20];
};

struct UnkStruct_00389380_e3 {
    unsigned char pad_0[0x34];
};

class CGtSoundVoiceManager {
public:
    void Construct(RwaSPU2Output* p0, CGtSoundRealVoiceDSPSend* p1, int p2, CGtSoundListenerManager* p3);

    UnkStruct_00389380_e2 field_0[1];  // [G] element count unknown
    unsigned char pad_20[0x1DA4];
    int field_1DC4[1];  // [G] element count unknown
    unsigned char pad_1DC8[0x6C];
    int field_1E34;
    unsigned char pad_1E38[0x8];
    int field_1E40;
};

extern UnkStruct_D_01EA4B00 D_01EA4B00;

extern "C" void Construct__17CGtSoundRealVoiceFP13RwaSPU2OutputP24CGtSoundRealVoiceDSPSendi(void *, void *, void *, int);  // CGtSoundRealVoice::Construct(RwaSPU2Output*,CGtSoundRealVoiceDSPSend*,int)
extern "C" void Construct__20CGtSoundVirtualVoiceFP13RwaSPU2Output(void *, void *);  // CGtSoundVirtualVoice::Construct(RwaSPU2Output*)
extern "C" void Update__20CGtSoundVoiceManagerFffff(void *, float, float, float, float, void *);  // CGtSoundVoiceManager::Update(float,float,float,float), passed 1 more argument(s) [G]
extern "C" int RwaSPU2VoiceCreate(int, void *, int, int, int);
extern "C" void RwaVoiceManagerRegister(int, void *, int);

// 0x00389380
void CGtSoundVoiceManager::Construct(RwaSPU2Output* p0, CGtSoundRealVoiceDSPSend* p1, int p2, CGtSoundListenerManager* p3)
{
    UnkStruct_00389380_2 local;  // [G] the frame's one local (size: up to the frame top)
    field_1E40 = p0->field_0;
    field_1E34 = p0->field_4;
    local.field_28 = 16;
    int i = 0;
    do {
        Construct__17CGtSoundRealVoiceFP13RwaSPU2OutputP24CGtSoundRealVoiceDSPSendi(((char *)&field_0[i] + 0x1A04), (RwaSPU2Output*)p0->field_0, (CGtSoundRealVoiceDSPSend*)p0->field_8, p0->field_C);
        i++;
    } while ((unsigned int)i < (unsigned int)16);
    int i1 = 0;
    do {
        int r1 = RwaSPU2VoiceCreate(p0->field_0, ((char *)&local + 0x28), 0, 0, 0);
        field_1DC4[i1] = r1;
        i1++;
    } while ((unsigned int)i1 < (unsigned int)24);
    RwaVoiceManagerRegister(p0->field_0, ((char *)this + 0x1DC4), 24);
    local.field_0 = p0->field_0;
    local.field_1C = p0->field_28;
    int i2 = 0;
    do {
        Construct__20CGtSoundVirtualVoiceFP13RwaSPU2Output(((char *)((char *)this + ((i2 * 13) << 2)) + 0x4), (RwaSPU2Output*)&local);
        i2++;
    } while ((unsigned int)i2 < (unsigned int)128);
    int i3 = 0;
    do {
        D_01EA4B00.field_0[i3].field_0 = 1.0f;
        D_01EA4B00.field_0[i3].field_4 = 1.0f;
        i3++;
    } while ((unsigned int)i3 < (unsigned int)16);
    Update__20CGtSoundVoiceManagerFffff(this, 1.0f, 1.0f, 0.0f, 0.0f, &D_01EA4B00);
}
