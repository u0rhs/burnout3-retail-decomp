// func_00285770 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (float v = 1.0f at the declaration; .lit4 pitch ratios as float literals; case 0 an empty break).

// func_00285770 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtSoundBank;

class CB3SoundGameModeManager;
struct UnkStruct_00285770;
struct UnkStruct_D_004E092C;
struct UnkStruct_D_004E0930;
struct UnkStruct_D_004E0934;
struct UnkStruct_D_004E0938;

class CB3SoundGameModeManager {
public:
    void TriggerSpotDucker(float);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E092C {
    float field_0;
};

struct UnkStruct_D_004E0930 {
    float field_0;
};

struct UnkStruct_D_004E0934 {
    float field_0;
};

struct UnkStruct_D_004E0938 {
    float field_0;
};

struct UnkStruct_00285770 {
    unsigned char pad_0[0x78];
    int field_78;
};

extern UnkStruct_D_004E092C D_004E092C;
extern UnkStruct_D_004E0930 D_004E0930;
extern UnkStruct_D_004E0934 D_004E0934;
extern UnkStruct_D_004E0938 D_004E0938;
extern CB3SoundGameModeManager D_01E77540;

extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  // CB3HUDSoundManager::PlayHudSound(unsigned long,const CGtSoundBank*,float,float,bool), passed 1 more argument(s) [G]

extern "C" void func_00285770(UnkStruct_00285770 * self, int p0)
{
    float v = 1.0f;
    switch (p0) {
    case 0:
        break;
    case 1:
        v = 1.12246f;
        break;
    case 2:
        v = 1.18921f;
        break;
    case 3:
        v = 1.25992f;
        break;
    case 4:
        v = 1.41421f;
        break;
    case 99:
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xBCB1BD0D08820000, (const CGtSoundBank*)self->field_78, 1.0f, 1.0f, 0, 0.0f);
        break;
    }
    PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xBCB1BD0D08820000, (const CGtSoundBank*)self->field_78, 1.0f, v, 0, 0.0f);
    PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xBCB1BD0D08820000, (const CGtSoundBank*)self->field_78, 1.0f, v, 0, 0.0f);
    D_01E77540.TriggerSpotDucker(0.5f);
}
