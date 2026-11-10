// CGtSoundVoiceManager::Update(float,float,float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVoiceManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (goto entry-jump loops (N24) with unsigned char counters; bool b = !(IsPlaying()!=0 || (flags&1)>0) in one statement; element/output pointers (output first) in loop 3; real member arrays).

// from build/vt\try_Update__20CGtSoundVoiceManagerFffff_best.cpp
// CGtSoundVoiceManager::Update(float,float,float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVoiceManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundVoice;
class CGtSoundVoiceManager;
struct UnkStruct_00389100_8;
struct UnkStruct_00389100_e0;
struct UnkStruct_00389100_e2;
struct UnkStruct_00389100_e4;
struct UnkStruct_00389100_e5;
struct UnkStruct_00389100_e6;
struct UnkStruct_00389100_e7;
struct UnkStruct_D_01EA4B00;

struct UnkStruct_00389100_e0 {
    unsigned char pad_0[0x1F];
    unsigned char field_1F;
};

struct UnkStruct_00389100_e2 {
    unsigned char pad_0[0x33];
    unsigned char field_33;
};

struct UnkStruct_00389100_e4 {
    UnkStruct_00389100_8 * field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0x8];
};

struct UnkStruct_00389100_8 {
    float field_0;
    float field_4;
};

struct UnkStruct_00389100_e5 {
    float field_0;
    float field_4;
};

struct UnkStruct_D_01EA4B00 {
    UnkStruct_00389100_e5 field_0[1];  // [G] element count unknown
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00389100_e6 {
    unsigned char pad_0[0xC];
    float field_C;
    float field_10;
};

struct UnkStruct_00389100_e7 {
    unsigned char pad_0[0x20];
};

class CGtSoundVoice {
public:
    static float _mrMasterPitch;
    static float _mrMasterVolume;
};

struct UnkStruct_00389100_e9 {
    float field_0;
    float field_4;
    UnkStruct_00389100_8 * field_8;
    float field_C;
    float field_10;
};

class CGtSoundVoiceManager {
public:
    void Update(float p0, float p1, float p2, float p3);

    UnkStruct_00389100_e2 field_0[128];
    UnkStruct_00389100_e0 field_1A00[16];
    unsigned char pad_1C00[0x4];
    UnkStruct_00389100_e9 field_1C04[16];
    unsigned char field_1D44[128];
    unsigned char pad_1DC4[0x60];
    unsigned char field_1E24[16];
    unsigned char pad_1E34[0x4];
    int field_1E38;
    int field_1E3C;
};

extern UnkStruct_D_01EA4B00 D_01EA4B00;

extern "C" void Update__17CGtSoundRealVoiceFffff(void *, float, float, float, float);  // CGtSoundRealVoice::Update(float,float,float,float)
extern "C" int IsPlaying__17CGtSoundRealVoiceCFv(void *);  // CGtSoundRealVoice::IsPlaying() const
extern "C" void Stop__17CGtSoundRealVoiceFv(void *);  // CGtSoundRealVoice::Stop()
extern "C" void Update__20CGtSoundVirtualVoiceFffff(void *, float, float, float, float);  // CGtSoundVirtualVoice::Update(float,float,float,float)
extern "C" int IsPlaying__20CGtSoundVirtualVoiceFv(void *);  // CGtSoundVirtualVoice::IsPlaying()

// 0x00389100
void CGtSoundVoiceManager::Update(float p0, float p1, float p2, float p3)
{
    CGtSoundVoice::_mrMasterPitch = p1;
    CGtSoundVoice::_mrMasterVolume = p0;
    field_1E3C = 0;
    unsigned char i = 0;
    goto test1;
body1:
    {
        void * v = (char *)&field_1A00[i] + 4;
        Update__17CGtSoundRealVoiceFffff(v, p0, p1, p2, p3);
        bool b = !(IsPlaying__17CGtSoundRealVoiceCFv(v) != 0 || (field_1A00[i].field_1F & 1) > 0);
        if (b) {
            Stop__17CGtSoundRealVoiceFv(v);
            field_1E24[field_1E3C++] = i;
        }
    }
    i++;
test1:
    if ((unsigned int)i < 16) goto body1;
    field_1E38 = 0;
    unsigned char j = 0;
    goto test2;
body2:
    {
        void * v = (char *)&field_0[j] + 4;
        Update__20CGtSoundVirtualVoiceFffff(v, p0, p1, p2, p3);
        bool b = !(IsPlaying__20CGtSoundVirtualVoiceFv(v) != 0 || (field_0[j].field_33 & 1) > 0);
        if (b) {
            field_1D44[field_1E38++] = j;
        }
    }
    j++;
test2:
    if ((unsigned int)j < 128) goto body2;
    unsigned int k = 0;
    goto test3;
body3:
    {
        UnkStruct_00389100_e5 * o = &D_01EA4B00.field_0[k];
        UnkStruct_00389100_e9 * e = &field_1C04[k];
        if (!(e->field_10 < 0.0f) && !(e->field_C <= 0.0f)) {
            float t = 1.0f - e->field_10 / e->field_C;
            UnkStruct_00389100_8 * p = e->field_8;
            o->field_0 = e->field_0 + t * (p->field_0 - e->field_0);
            o->field_4 = e->field_4 + t * (p->field_4 - e->field_4);
            e->field_10 -= p3;
        } else {
            UnkStruct_00389100_8 * p = e->field_8;
            if (p != 0) {
                o->field_0 = p->field_0;
                o->field_4 = p->field_4;
            }
        }
    }
    k++;
test3:
    if (k < 16) goto body3;
}
