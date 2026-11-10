// Hand-written; the lifter refused it (a73: hand-written from sibling SetMasterVolumeScalar shapes).

// [L] DNAT: CB3SoundManager::Update() (research/proto/new_names.csv, medium)
struct UnkStruct__grMasterVolumeScalar { float field_0; };
struct UnkStruct__grMasterPitchScalar { float field_0; };
struct UnkStruct_D_004F509C { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004F50A0 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BAC4 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004F5073 { signed char field_0; unsigned char pad_1[0xF]; };

class CB3SoundManager {
public:
    unsigned char pad_0[0x720C];
    int field_720C;
    unsigned char pad_7210[0x4];
    unsigned char field_7214;
};

extern UnkStruct__grMasterVolumeScalar _grMasterVolumeScalar;
extern UnkStruct__grMasterPitchScalar _grMasterPitchScalar;
extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_004F50A0 D_004F50A0;
extern UnkStruct_D_0051BAC4 D_0051BAC4;
extern UnkStruct_D_004F5073 D_004F5073;

extern "C" void func_00384FF0(void *);
extern "C" void func_00384FD0(void *);
extern "C" void Update__15CGtSoundManagerFffff(void *, float, float, float, float);
extern "C" void SetSpeakerConfig__15CB3SoundManagerF16EB3SpeakerConfig(void *, int);

// 0x0028B160
extern "C" void func_0028B160(CB3SoundManager * self)
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
