// CB3HUDSoundManager::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3SoundHUDManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-written from cfgmap; 0x50 voice params local, cur==0 arm first).

// CB3HUDSoundManager::Update()
// [C] name: the mangled symbol in retail's tables. Hand-written (L243); the lifter refused it.
// Fields are placeholders, types [G] (instruction widths).

struct UnkStruct_00286C60_rnd { int field_0; int field_4; };
struct UnkStruct_00286C60_p { unsigned char pad_0[0x10]; };
struct UnkStruct_00286C60_o {
    unsigned char pad_0[0x1B4];
    void * field_1B4;
};
struct UnkStruct_00286C60_g { UnkStruct_00286C60_o * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00286C60_f { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00286C60_i { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00286C60_st { unsigned long field_0; };
struct UnkStruct_00286C60_sp { UnkStruct_00286C60_st * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00286C60_vp {
    unsigned char pad_0[0x1C];
    float field_1C;
    unsigned char pad_20[0x30];
};
struct UnkStruct_00286C60 {
    unsigned char pad_0[0x8];
    void * field_8;
    void * field_C;
    unsigned char field_10;
    unsigned char field_11;
    unsigned char field_12;
    unsigned char pad_13;
    int field_14;
    unsigned char pad_18[0x4];
    float field_1C;
    unsigned char pad_20[0x28];
    int field_48;
    unsigned char pad_4C[0x4];
    int field_50;
    int field_54;
    unsigned char pad_58[0x8];
    int field_60;
    unsigned char pad_64[0x4];
    unsigned char field_68;
    unsigned char field_69;
    unsigned char field_6A;
    unsigned char field_6B;
    unsigned char field_6C;
    unsigned char pad_6D[0x3];
    int field_70;
    unsigned char pad_74[0x4];
    int field_78;
    int field_7C;
};

extern "C" UnkStruct_00286C60_rnd _mRandom__13CGtSoundUtils;
extern UnkStruct_00286C60_g D_0051BA88;
extern UnkStruct_00286C60_p D_0051B340;
extern UnkStruct_00286C60_p D_0051A6A8;
extern UnkStruct_00286C60_f D_0064E740;
extern UnkStruct_00286C60_f D_0064E47C;
extern UnkStruct_00286C60_sp D_01EA2974;
extern UnkStruct_00286C60_i D_01E32B08;
extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" void Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(void *, const void *);
extern "C" void Stop__20CGtSoundVirtualVoiceFv(void *);

extern "C" void Update__18CB3HUDSoundManagerFv(UnkStruct_00286C60 * self)
{
    int a = _mRandom__13CGtSoundUtils.field_0;
    int x = (a << 16) + (a >> 16);
    x += _mRandom__13CGtSoundUtils.field_4;
    _mRandom__13CGtSoundUtils.field_4 += x;
    _mRandom__13CGtSoundUtils.field_0 = x;
    if (D_0051BA88.field_0 != 0 && D_0051BA88.field_0->field_1B4 == &D_0051B340) {
        int n = (int)(D_0064E740.field_0 - D_0064E47C.field_0);
        if (n < 0) {
            self->field_60 = 999;
        } else if (n > 9) {
            self->field_60 = 999;
        } else if (self->field_60 > n) {
            PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xBD69B91E81C00000UL, (const void *)self->field_78, 0.75f, 1.0f, 0, 0.0f);
            self->field_60 = n;
        }
    }
    if (self->field_50 != 0) {
        self->field_50--;
    }
    if (self->field_54 != 0) {
        self->field_54--;
    }
    if (self->field_69 > 0) {
        self->field_69--;
    }
    if (self->field_68 != 0) {
        self->field_68--;
        if (self->field_68 == 0) {
            PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xA4F3B88DDAB40000UL, (const void *)self->field_7C, 1.0f, 1.0f, 0, 0.0f);
        }
    }
    if (self->field_6A != 0) {
        self->field_6A--;
    }
    if (self->field_6B != 0) {
        self->field_6B--;
    }
    if (self->field_6C != 0) {
        self->field_6C--;
    }
    if (self->field_14 != 0) {
        self->field_14--;
    }
    if (self->field_1C < 1.0f) {
        self->field_1C += 0.05f;
    }
    if (self->field_48 != 0) {
        UnkStruct_00286C60_vp params;
        self->field_48--;
        Construct__19CGtSoundVoiceParamsFv(&params);
        params.field_1C = self->field_1C;
        if (self->field_8 != 0) {
            Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(self->field_8, &params);
        }
        if (self->field_C != 0) {
            Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(self->field_C, &params);
        }
        if (self->field_48 == 0) {
            if (self->field_8 != 0) {
                Stop__20CGtSoundVirtualVoiceFv(self->field_8);
                self->field_8 = 0;
            }
            if (self->field_C != 0) {
                Stop__20CGtSoundVirtualVoiceFv(self->field_C);
                self->field_C = 0;
            }
        }
    }
    self->field_10 = 0;
    self->field_11 = 0;
    self->field_12 = 0;
    if (D_0051BA88.field_0 == (UnkStruct_00286C60_o *)&D_0051A6A8) {
        unsigned long id;
        if (D_01EA2974.field_0 != 0) {
            id = D_01EA2974.field_0->field_0;
        } else {
            id = 0x6D6123044330FCCFUL;
        }
        if (id == 0x94414018F8506AFEUL) {
            int cur = D_01E32B08.field_0;
            int old = self->field_70;
            if (old != cur) {
                if (old == -1) {
                    self->field_70 = cur;
                } else {
                    if (cur < old) {
                        if (cur == 0) {
                            PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0x709430F4887C8000UL, (const void *)self->field_7C, 0.35f, 1.0f, 0, 0.0f);
                        } else {
                            PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xA6864CCE3DFE6C00UL, (const void *)self->field_7C, 0.5f, 1.0f, 0, 0.0f);
                        }
                    } else {
                        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xA6864CCE3352D480UL, (const void *)self->field_7C, 0.5f, 1.0f, 0, 0.0f);
                    }
                    self->field_70 = D_01E32B08.field_0;
                }
            }
        }
    }
}
