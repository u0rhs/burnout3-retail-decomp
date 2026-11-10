// CB3SoundAICar::Prepare(unsigned long,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundAICar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (sibling CB3SoundPlayerCar::Prepare shape: bool r = RaceCar::Prepare; if (r) { if (!field_4) field_4 = RequestESM(0); r = vfunc_8(..); } return r; (!field_4 keeps the create block inline)).

// CB3SoundAICar::Prepare(unsigned long,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundAICar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3SoundAICar;
class CB3SoundESMManager;
class CGtSoundBankManager;
class CGtSoundVirtualVoice;
struct UnkStruct_0028BDD0_1;
struct UnkStruct_0028BDD0_2;
struct UnkStruct_D_004BF820;
struct UnkStruct_D_004BF838;

class CGtSoundBankManager {
public:
    int LoadBank(const char*, bool, bool, int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtSoundVirtualVoice {
public:
    void ForgetMe(float);
};

class CB3SoundESMManager {
public:
    UnkStruct_0028BDD0_2 * RequestESM(bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0028BDD0_1 {
    unsigned long field_0;
    unsigned long field_8;
};

struct UnkStruct_0028BDD0_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual bool vfunc_8(int, unsigned long, int);
};

struct UnkStruct_D_004BF820 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BF838 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundAICar {
public:
    bool Prepare(unsigned long p0, int p1);

    unsigned char pad_0[0x4];
    UnkStruct_0028BDD0_2 * field_4;
    unsigned char pad_8[0x138];
    int field_140;
    int field_144;
    int field_148;
    int field_14C;
    CGtSoundVirtualVoice * field_150;
    CGtSoundVirtualVoice * field_154;
    int field_158;
    int field_15C;
};

extern UnkStruct_D_004BF820 D_004BF820;
extern CGtSoundBankManager D_01E75648;
extern UnkStruct_D_004BF838 D_004BF838;
extern CB3SoundESMManager D_01E78170;

extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const
extern "C" bool Prepare__15CB3SoundRaceCarFUli(void *, unsigned long, int);  // CB3SoundRaceCar::Prepare(unsigned long,int)
extern "C" unsigned long GtIDCompress__FPCc(void *);

// 0x0028BDD0
bool CB3SoundAICar::Prepare(unsigned long p0, int p1)
{
    UnkStruct_0028BDD0_1 local;  // [G] the frame's one local (size: up to the frame top)
    if (field_144 == 0) {
        int r0 = D_01E75648.LoadBank((const char*)&D_004BF820, 1, 0, 6144);
        field_144 = r0;
    }
    if (field_144 != 0) {
        unsigned long r1 = GtIDCompress__FPCc(&D_004BF838);
        local.field_8 = r1;
        int r2 = FindWave__12CGtSoundBankCFRCUlb((void *)field_144, ((char *)&local + 0x8), 0);
        field_148 = r2;
        unsigned long r3 = GtIDCompress__FPCc(&D_004BF838);
        local.field_0 = r3;
        int r4 = FindWave__12CGtSoundBankCFRCUlb((void *)field_144, &local, 0);
        field_14C = r4;
        CGtSoundVirtualVoice * t0 = field_150;
        if (t0 != 0) {
            t0->ForgetMe(0.5f);
            field_150 = 0;
            field_158 = 0;
        }
        CGtSoundVirtualVoice * t1 = field_154;
        if (t1 != 0) {
            t1->ForgetMe(0.5f);
            field_154 = 0;
            field_15C = 0;
        }
        field_140 = 0;
        bool r = Prepare__15CB3SoundRaceCarFUli(this, p0, p1);
        if (r) {
            if (!field_4) {
                field_4 = D_01E78170.RequestESM(0);
            }
            r = field_4->vfunc_8(0, p0, p1);
        }
        return r;
    }
    return 0;
}
