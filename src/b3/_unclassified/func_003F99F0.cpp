// Hand-written; the lifter refused it (music stream FSM: exits are break (return only for AllocStream==0); AllocStream result stored/tested via int pun (continuation out of line); IsPlaying bool; ||-chain state=13; pick if(!=0) first; span computed before RNG).

// func_003F99F0 -- music stream state machine Update [G] (states 0/11 -> 4 -> 5 -> 6 -> 7 -> 8 -> 13; siblings func_003FA510 (bank load), func_003F8580/8AA0 (track pick))
struct UnkStruct_99F0_params {
    unsigned char pad_0[0x18];
    int field_18;
    float field_1C;
    unsigned char pad_20[0x24];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char field_46;
    unsigned char pad_47[0x9];
};
struct UnkStruct_99F0_stream {
    unsigned char pad_0[0x1EC];
    unsigned char field_1EC;
};
struct UnkStruct_99F0 {
    unsigned char pad_0[0xF0];
    char field_F0[0x20];
    char field_110[0x50];
    UnkStruct_99F0_stream * field_160;
    void * field_164;
    int field_168;
    void * field_16C;
    unsigned char pad_170[0x4];
    int field_174;
    unsigned char pad_178[0x8];
    int field_180;
    int field_184;
    int field_188;
    int field_18C;
    unsigned char pad_190[0x4];
    signed char field_194;
    unsigned char pad_195[0x3];
    int field_198;
    unsigned char pad_19C[0x4];
    float field_1A0;
    unsigned char pad_1A4[0x4];
    float field_1A8;
    unsigned char field_1AC;
};
struct UnkStruct_99F0_i { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_99F0_b { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_99F0_o { unsigned char pad_0[0x10]; };
struct UnkStruct_99F0_rnd { int field_0; int field_4; };
struct UnkStruct_99F0_l { unsigned long field_0; unsigned char pad_8[8]; };
struct UnkStruct_99F0_f { float field_0; };
struct UnkStruct_99F0_i2 { int field_0; };

extern UnkStruct_99F0_i D_0064D3A0;
extern UnkStruct_99F0_b D_01E65499;
extern UnkStruct_99F0_i D_01E900B4;
extern UnkStruct_99F0_o D_01E7569C;
extern UnkStruct_99F0_o D_01E774E0;
extern UnkStruct_99F0_o D_01E75648;
extern UnkStruct_99F0_o D_004EE040;
extern UnkStruct_99F0_o D_004CE9C8;
extern UnkStruct_99F0_o D_004CE9D0;
extern UnkStruct_99F0_l D_0064D370;
extern UnkStruct_99F0_f D_004E1F04;
extern UnkStruct_99F0_i2 D_004E1EC0;
extern UnkStruct_99F0_i2 D_004E1EC4;
extern "C" UnkStruct_99F0_rnd _mRandom__13CGtSoundUtils;
extern "C" void func_003FC470(void *);
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" void * TriggerRealVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(void *, const void *);
extern "C" void IgnoreGlobalPitch__17CGtSoundRealVoiceFv(void *);
extern "C" bool IsPlaying__17CGtSoundRealVoiceCFv(void *);
extern "C" void Stop__17CGtSoundRealVoiceFv(void *);
extern "C" UnkStruct_99F0_stream * AllocStream__21CGtSoundStreamManagerFb(void *, bool);
extern "C" int GetStreamsPreparing__21CGtSoundStreamManagerFv(void *);
extern "C" void FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(void *, void *);
extern "C" int func_00385FD0(void *);
extern "C" int func_00385FE0(void *);
extern "C" int func_00385EC0(void *);
extern "C" void func_00385EA0(void *, int, float, float, float, float);
extern "C" void func_00385EB0(void *);
extern "C" int AttachMedia__14CGtSoundStreamFPCc(void *, const char *, int);
extern "C" int func_003865A0(void *, const char *, int, int, int, int);
extern "C" void Stop__14CGtSoundStreamFv(void *);
extern "C" int Release__14CGtSoundStreamFv(void *);
extern "C" void Play__14CGtSoundStreamFb(void *, bool);
extern "C" void SetVolume__14CGtSoundStreamFfi(void *, float, int);
extern "C" void UnloadBank__19CGtSoundBankManagerFP12CGtSoundBank(void *, void *);
extern "C" void * LoadBank__19CGtSoundBankManagerFPCcbbi(void *, const char *, bool, bool, int);
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);
extern "C" int sprintf(char *, const void *, ...);
extern "C" int func_00131E40(void *);
extern "C" void func_003F88E0(void *, char *);
extern "C" void func_003F8AA0(void *, unsigned long, char *, int *, int *, int, int);

// 0x003F99F0
extern "C" void func_003F99F0(UnkStruct_99F0 * self)
{
    if (self->field_1AC != 0 || !(D_0064D3A0.field_0 < 2) || D_01E65499.field_0 != 0 || D_01E900B4.field_0 != 0) {
        self->field_174 = 13;
    }
    switch (self->field_174) {
    case 0:
        func_003FC470(self);
    case 11:
        self->field_174 = 4;
    case 4:
    st4:
        if (self->field_164 != 0 && self->field_16C == 0) {
            UnkStruct_99F0_params p;
            Construct__19CGtSoundVoiceParamsFv(&p);
            p.field_18 = self->field_168;
            p.field_1C = self->field_1A8;
            p.field_44 = 13;
            p.field_45 = 0;
            p.field_46 = 1;
            self->field_16C = TriggerRealVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(&D_01E7569C, &p);
            if (self->field_16C != 0) {
                self->field_198 = self->field_198 | 4;
                IgnoreGlobalPitch__17CGtSoundRealVoiceFv(self->field_16C);
            }
        }
        *(int *)&self->field_160 = (int)AllocStream__21CGtSoundStreamManagerFb(&D_01E774E0, false);
        if (*(int *)&self->field_160 != 0) goto pick;
        break;
    case 5:
    st5:
        if (GetStreamsPreparing__21CGtSoundStreamManagerFv(&D_01E774E0) != 0) {
            if (func_00385FD0(self->field_160) == 0) return;
        }
        if (AttachMedia__14CGtSoundStreamFPCc(self->field_160, self->field_F0, 4) != 0) goto attached;
        return;
    case 6:
    st6:
        if (func_003865A0(self->field_160, self->field_F0, 0, 0, self->field_180, 4) == 0) return;
        self->field_174 = 7;
    case 7:
    st7:
        {
            bool playing = self->field_16C != 0 ? IsPlaying__17CGtSoundRealVoiceCFv(self->field_16C) : false;
            if (!playing) goto after7;
            return;
        }
    case 8:
    st8:
        if (func_00385FE0(self->field_160) == 0) return;
        self->field_198 = self->field_198 & -3;
        if (self->field_160 != 0) {
            Stop__14CGtSoundStreamFv(self->field_160);
            Release__14CGtSoundStreamFv(self->field_160);
            FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, self->field_160);
            self->field_160 = 0;
        }
        self->field_F0[0] = 0;
        self->field_174 = 13;
    case 13:
    default:
        return;
    }
    return;
pick:
    {
        unsigned long s0 = D_0064D370.field_0;
        if (func_00131E40(&D_004EE040) != 0) {
            func_003F8AA0(self, s0, self->field_F0, &self->field_188, &self->field_18C, 1, 0);
        } else {
            int a = _mRandom__13CGtSoundUtils.field_0;
            int x = (a << 16) + (a >> 16);
            x += _mRandom__13CGtSoundUtils.field_4;
            _mRandom__13CGtSoundUtils.field_4 += x;
            _mRandom__13CGtSoundUtils.field_0 = x;
            if ((x & 1) != 0) {
                func_003F88E0(self, self->field_F0);
                self->field_188 = 0;
                self->field_18C = 0;
            } else {
                func_003F8AA0(self, s0, self->field_F0, &self->field_188, &self->field_18C, 0, 0);
            }
        }
        self->field_174 = 5;
        goto st5;
    }
attached:
    self->field_184 = func_00385EC0(self->field_160);
    if (self->field_18C == 0) self->field_18C = self->field_184;
    {
        unsigned span = self->field_18C - self->field_188;
        int a = _mRandom__13CGtSoundUtils.field_0;
        int x = (a << 16) + (a >> 16);
        x += _mRandom__13CGtSoundUtils.field_4;
        _mRandom__13CGtSoundUtils.field_4 += x;
        _mRandom__13CGtSoundUtils.field_0 = x;
        unsigned r = _mRandom__13CGtSoundUtils.field_0;
        self->field_180 = self->field_188 + r % span;
        self->field_174 = 6;
        goto st6;
    }
after7:
    {
        bool playing = self->field_16C != 0 ? IsPlaying__17CGtSoundRealVoiceCFv(self->field_16C) : false;
        if (playing) {
            Stop__17CGtSoundRealVoiceFv(self->field_16C);
        }
        self->field_16C = 0;
    }
    self->field_198 = self->field_198 & -5;
    if ((self->field_198 & 0x10) != 0) {
        self->field_198 = self->field_198 | 0x20;
    } else if (self->field_164 != 0) {
        UnloadBank__19CGtSoundBankManagerFP12CGtSoundBank(&D_01E75648, self->field_164);
        self->field_164 = 0;
        self->field_168 = 0;
        self->field_198 = self->field_198 & -33;
    }
    if ((self->field_198 & 0x10) == 0) {
        sprintf(self->field_110, &D_004CE9D0, D_004E1EC0.field_0, D_004E1EC4.field_0, self->field_194);
        self->field_198 = self->field_198 | 0x10;
    }
    self->field_164 = LoadBank__19CGtSoundBankManagerFPCcbbi(&D_01E75648, self->field_110, true, false, 0x800);
    if (self->field_164 != 0) {
        self->field_168 = FindWave__12CGtSoundBankCFRCUlb(self->field_164, &D_004CE9C8, false);
        self->field_198 = self->field_198 & -17;
        self->field_194 = self->field_194 + 1;
        if (self->field_194 == 10) self->field_194 = 0;
    }
    func_00385EA0(self->field_160, -1, 1.0f, 0.0f, 0.125f, 0.0f);
    Play__14CGtSoundStreamFb(self->field_160, false);
    func_00385EB0(self->field_160);
    self->field_160->field_1EC = 14;
    SetVolume__14CGtSoundStreamFfi(self->field_160, self->field_1A0 * D_004E1F04.field_0, -1);
    self->field_198 = self->field_198 | 2;
    self->field_174 = 8;
    goto st8;
}
