// CB3SoundRaceCar::Prepare(unsigned long,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundRaceCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (four separate unsigned long name locals (first declared highest slot); vfunc_14 takes the unsigned long p0 (a1); && guard; direct field null tests).

// lifter variant 0
// CB3SoundRaceCar::Prepare(unsigned long,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundRaceCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3SoundRaceCar;
class CB3SoundSkidModel;
class CGtSoundVirtualVoice;
struct UnkStruct_D_004BFBB0;
struct UnkStruct_D_004BFBC0;
struct UnkStruct_D_004BFBC8;
struct UnkStruct_D_004BFBD0;
struct UnkStruct_D_004E2A68;
struct UnkStruct_D_01E75644;
struct UnkStruct_D_01E75648;
struct UnkStruct__grBoostLoopVol;
struct UnkStruct_kHornSound;

class CGtSoundVirtualVoice {
public:
    void Stop();
    void ForgetMe(float);
};

class CB3SoundSkidModel {
public:
    bool Prepare();
};


struct UnkStruct_D_01E75644 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E2A68 {
    unsigned char field_0;
};

struct UnkStruct__grBoostLoopVol {
    float field_0;
};

struct UnkStruct_D_004BFBB0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E75648 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BFBC0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BFBC8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BFBD0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_kHornSound {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundRaceCar {
public:
    bool Prepare(unsigned long p0, int p1);

    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(unsigned long);
    unsigned char pad_4[0x4];
    CB3SoundSkidModel field_8;
    unsigned char pad_9[0x5F];
    int field_68;
    CGtSoundVirtualVoice * field_6C;
    CGtSoundVirtualVoice * field_70;
    int field_74;
    CGtSoundVirtualVoice * field_78;
    CGtSoundVirtualVoice * field_7C;
    int field_80;
    int field_84;
    unsigned char pad_88[0x8];
    int field_90;
    float field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    unsigned char pad_AC[0x8];
    int field_B4;
    unsigned char pad_B8[0x4];
    unsigned char field_BC;
};

extern UnkStruct_D_01E75644 D_01E75644;
extern UnkStruct_D_004E2A68 D_004E2A68;
extern UnkStruct__grBoostLoopVol _grBoostLoopVol;
extern UnkStruct_D_004BFBB0 D_004BFBB0;
extern UnkStruct_D_01E75648 D_01E75648;
extern UnkStruct_D_004BFBC0 D_004BFBC0;
extern UnkStruct_D_004BFBC8 D_004BFBC8;
extern UnkStruct_D_004BFBD0 D_004BFBD0;
extern UnkStruct_kHornSound kHornSound;

extern "C" int FindWave__19CGtSoundBankManagerCFRCUlb(void *, const void *, bool);  // CGtSoundBankManager::FindWave(const unsigned long&,bool) const
extern "C" unsigned long GtIDCompress__FPCc(void *);

// 0x0028DBB0
bool CB3SoundRaceCar::Prepare(unsigned long p0, int p1)
{
    field_94 = 1.0f;
    unsigned long n0 = GtIDCompress__FPCc(&D_004BFBB0);
    field_9C = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &n0, 0);
    unsigned long n1 = GtIDCompress__FPCc(&D_004BFBC0);
    field_A0 = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &n1, 0);
    unsigned long n2 = GtIDCompress__FPCc(&D_004BFBC8);
    field_A4 = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &n2, 0);
    unsigned long n3 = GtIDCompress__FPCc(&D_004BFBD0);
    field_A8 = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &n3, 0);
    field_B4 = 0;
    field_BC = 1;
    if (D_01E75644.field_0 != 0 && D_004E2A68.field_0 == 0) {
        D_004E2A68.field_0 = 1;
        _grBoostLoopVol.field_0 *= 0.625f;
    }
    if (field_70 != 0) {
        field_70->Stop();
    }
    field_70 = 0;
    if (field_6C != 0) {
        field_6C->Stop();
    }
    field_70 = 0;
    field_74 = 0;
    if (field_78 != 0) {
        field_78->Stop();
    }
    field_78 = 0;
    if (field_7C != 0) {
        field_7C->ForgetMe(0.1f);
        field_7C = 0;
    }
    field_80 = -1;
    field_84 = -1;
    field_90 = 0;
    field_98 = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &kHornSound, 0);
    if (field_68 == 0) {
        vfunc_14(p0);
    }
    return field_8.Prepare();
}
