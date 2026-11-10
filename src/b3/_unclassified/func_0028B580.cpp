// func_0028B580 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class RwaSPU2Output;
class CGtSoundRealVoiceDSPSend;
class CGtSoundManagerConstructParams;
class CGtSoundListener;

class CB3SoundDistortion;
class CB3SoundGameModeManager;
class CB3SoundListener;
class CGtSoundListenerManager;
struct UnkStruct_0028B580;
struct UnkStruct_0028B580_1;
struct UnkStruct_D_004BF7B0;
struct UnkStruct__gaWaveObjectBufferData;
struct UnkStruct__grMasterVolumeScalar;
struct UnkStruct_gVdbDatabase;
struct UnkStruct_kpcVoiceVDBFile;
struct UnkStruct_kpcVoiceVarDir;

class CB3SoundDistortion {
public:
    void Construct(RwaSPU2Output*, int);
    void GetDSPSends(CGtSoundRealVoiceDSPSend**, int*);
};

class CB3SoundListener {
public:
    void Construct();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtSoundListenerManager {
public:
    void SetListener(int, CGtSoundListener*);
    void Prepare(unsigned int);
};

class CB3SoundGameModeManager {
public:
    void Construct(RwaSPU2Output*);
};

struct UnkStruct_0028B580_1 {
    int field_0;
    void * field_4;
    int field_8;
    int field_C;
    unsigned char pad_10[0x10];
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    unsigned char field_38;
    unsigned char pad_39[0x7];
};

struct UnkStruct_gVdbDatabase {
    int field_0;
};

struct UnkStruct_kpcVoiceVarDir {
    int field_0;
};

struct UnkStruct_kpcVoiceVDBFile {
    int field_0;
};

struct UnkStruct__gaWaveObjectBufferData {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct__grMasterVolumeScalar {
    unsigned char pad_0[0x4];  // [G] size: gp-relative addressing needs <= 8 bytes
};

struct UnkStruct_D_004BF7B0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0028B580 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    unsigned char field_4;
    unsigned char pad_5[0x43];
    CGtSoundListenerManager field_48;
    unsigned char pad_49[0x1E8F];
    int field_1ED8;
    unsigned char pad_1EDC[0x4];
    unsigned char field_1EE0;
    unsigned char pad_1EE1[0x1F];
    CB3SoundGameModeManager field_1F00;
    unsigned char pad_1F01[0x34FF];
    CB3SoundDistortion field_5400;
    unsigned char pad_5401[0x1DFF];
    int field_7200;
    int field_7204;
    int field_7208;
    int field_720C;
    int field_7210;
    unsigned char field_7214;
};

extern UnkStruct_gVdbDatabase mpToolBase__Q27GtComms16CGtCommsToolBase;
extern UnkStruct_kpcVoiceVarDir kpcVoiceVarDir;
extern UnkStruct_kpcVoiceVDBFile kpcVoiceVDBFile;
extern UnkStruct__gaWaveObjectBufferData _gaWaveObjectBufferData;
extern CB3SoundListener D_01E7C880;
extern CB3SoundListener D_01E7C89C;
extern UnkStruct__grMasterVolumeScalar _grMasterVolumeScalar;
extern UnkStruct_D_004BF7B0 D_004BF7B0;

extern "C" void Construct__15CGtSoundManagerFP30CGtSoundManagerConstructParams(void *, void *);  // CGtSoundManager::Construct(CGtSoundManagerConstructParams*)
extern "C" void func_0027A900(void *, float);
extern "C" int sceSifAllocSysMemory(int, int, int);
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(int, void *, void *, int, int, int, int, float, float);

// 0x0028B580
extern "C" void func_0028B580(UnkStruct_0028B580 * self)
{
    UnkStruct_0028B580_1 local;  // [G] the frame's one local (size: up to the frame top)
    self->field_4 = 0;
    if (self->field_1EE0 == 0) {
        self->vfunc_14();
    }
    local.field_0 = 11;
    local.field_4 = &_gaWaveObjectBufferData;
    local.field_8 = 2;
    local.field_C = 16;
    self->field_5400.Construct((RwaSPU2Output*)self->field_1ED8, 0);
    self->field_5400.GetDSPSends((CGtSoundRealVoiceDSPSend**)((char *)&local + 0x18), (int*)((char *)&local + 0x1C));
    local.field_38 = 0;
    local.field_20 = 0;
    local.field_24 = 0;
    local.field_30 = 0;
    local.field_34 = 0;
    local.field_28 = 0;
    local.field_2C = 0;
    Construct__15CGtSoundManagerFP30CGtSoundManagerConstructParams(self, (CGtSoundManagerConstructParams*)&local);
    D_01E7C880.Construct();
    D_01E7C89C.Construct();
    self->field_48.SetListener(0, (CGtSoundListener*)&D_01E7C880);
    self->field_48.SetListener(1, (CGtSoundListener*)&D_01E7C89C);
    self->field_48.Prepare(1);
    self->field_1F00.Construct((RwaSPU2Output*)self->field_1ED8);
    func_0027A900(((char *)self + 0x2ED0), 1.0f);
    self->field_7214 = 255;
    self->field_7200 = 0;
    self->field_7204 = 0;
    self->field_7208 = 0;
    int r11 = sceSifAllocSysMemory(0, 0x40000, 0);
    self->field_7208 = r11;
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), &_grMasterVolumeScalar, &D_004BF7B0, kpcVoiceVarDir.field_0, kpcVoiceVDBFile.field_0, 0, 0, 0.0f, 0.0f);
    self->field_7210 = 1;
    self->field_720C = 0;
}
