// Hand-written; the lifter refused it (a122: sibling func_0028B160 body inlined x2 (30-iter loops) + inlined SetMasterVolumeScalar(0). RELOC note: D_004F50A0 is a plain constant in retail (a107 exception, bytes equal)).

struct UnkStruct__grMasterVolumeScalar { float field_0; };
struct UnkStruct__grMasterPitchScalar { float field_0; };
struct UnkStruct_D_004F509C { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004F50A0 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BAC4 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004F5073 { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_theMemMgr { unsigned char pad_0[0x10]; };
class CGtSoundBank;
class CGtSoundVoice { public: static float _mrMasterVolume; };
class CB3SoundManager {
public:
    unsigned char pad_0[8];
    unsigned char field_8[0x1ED0];
    unsigned char pad_1ED8[4];
    int field_1EDC;
    unsigned char pad_1EE0[0xFF0];
    unsigned char field_2ED0[0x4330];
    CGtSoundBank *field_7200;
    int field_7204;
    unsigned char pad_7208[4];
    int field_720C;
    unsigned char pad_7210[4];
    unsigned char field_7214;
};
extern UnkStruct__grMasterVolumeScalar _grMasterVolumeScalar;
extern UnkStruct__grMasterPitchScalar _grMasterPitchScalar;
extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_004F50A0 D_004F50A0;
extern UnkStruct_D_0051BAC4 D_0051BAC4;
extern UnkStruct_D_004F5073 D_004F5073;
extern UnkStruct_theMemMgr theMemMgr;
extern "C" void func_00384FF0(void *);
extern "C" void func_00384FD0(void *);
extern "C" int func_00384F80(void *);
extern "C" void func_0027A900(void *, float);
extern "C" void Update__15CGtSoundManagerFffff(void *, float, float, float, float);
extern "C" void SetSpeakerConfig__15CB3SoundManagerF16EB3SpeakerConfig(void *, int);
extern "C" void StopAll__15CGtSoundManagerFv(void *);
extern "C" void UnloadBank__19CGtSoundBankManagerFP12CGtSoundBank(void *, CGtSoundBank *);
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
static inline void func_0028AF10_inl1(CB3SoundManager *self)
{
    func_00384FF0(self);
    Update__15CGtSoundManagerFffff(self,
        _grMasterVolumeScalar.field_0 * ((float)(unsigned int)self->field_7214 / 255.0f),
        _grMasterPitchScalar.field_0,
        D_004F50A0.field_0,
        D_004F509C.field_0 * (float)D_0051BAC4.field_0);
    if (self->field_720C != D_004F5073.field_0) {
        SetSpeakerConfig__15CB3SoundManagerF16EB3SpeakerConfig(self, D_004F5073.field_0);
    }
    func_00384FD0(self);
}
// 0x0028AF10
extern "C" int func_0028AF10(CB3SoundManager *self)
{
    float z = 0.0f;
    _grMasterVolumeScalar.field_0 = z;
    CGtSoundVoice::_mrMasterVolume = z;
    func_0027A900(self->field_2ED0, z * ((float)(unsigned int)self->field_7214 / 255.0f));
    for (int i = 0; i < 30; i++) func_0028AF10_inl1(self);
    StopAll__15CGtSoundManagerFv(self);
    if (self->field_7200 != 0) {
        UnloadBank__19CGtSoundBankManagerFP12CGtSoundBank(self->field_8, self->field_7200);
        self->field_7200 = 0;
    }
    for (int i = 0; i < 30; i++) func_0028AF10_inl1(self);
    if (func_00384F80(self) != 0) {
        ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 15, 0);
        self->field_7204 = 0;
        self->field_1EDC = 24;
        return 1;
    }
    return 0;
}
