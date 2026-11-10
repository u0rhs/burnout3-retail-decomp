// NONMATCHING: func_003FA600 -- retail 271 / ours 271 instructions, 2 in changed runs
// 271/271, 2 changed: only the order of 'addiu v1,-5' vs 'lw a0,0x198' at the voice-off block (retail constant first; ours lw first); tried &=, ~4, mask locals, unsigned. Everything else exact: JTBL switch (case 4 falls into 1/2/3/5, 0/6 break), gotos stopvoice/none out of line, play/free/rnd inlines, tail wrapped in if(178==4) so last return is return-type | near5: -5 & x, inline with mask parameter, int m=-5; m&=x, const pun, bitfield pun (274): lw still first.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003FA600 -- music stream state machine Update [G] (states 0/11 -> 4 -> 5 -> 6 -> 7 -> 8 -> 13; siblings func_003FA510 (bank load), func_003F8580/8AA0 (track pick))
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
extern "C" void func_00385EA0();
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

struct UnkStruct_A600 {
    unsigned char pad_0[0x4];
    float field_4;
    unsigned char pad_8[0x4];
    unsigned char field_C;
    unsigned char pad_D[0xDF];
    int field_EC;
    char field_F0[0x20];
    unsigned char pad_110[0x20];
    unsigned char field_130[0x26];
    unsigned char pad_156[0xA];
    UnkStruct_99F0_stream * field_160;
    unsigned char pad_164[0x8];
    void * field_16C;
    unsigned char pad_170[0x4];
    int field_174;
    int field_178;
    int field_17C;
    int field_180;
    int field_184;
    int field_188;
    int field_18C;
    unsigned char pad_190[0x5];
    signed char field_195;
    unsigned char pad_196[0x2];
    int field_198;
    unsigned char pad_19C[0x11];
    unsigned char field_1AD;
};
struct UnkStruct_A600_out { unsigned char pad_0[0x50]; int field_50; unsigned char pad_54[0x4]; };
struct UnkStruct_A600_sc { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_A600_uc { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_A600_f { float field_0; };
extern UnkStruct_99F0_o D_01E78510;
extern UnkStruct_A600_sc D_004F507A;
extern UnkStruct_A600_uc D_004F5077;
extern UnkStruct_A600_f D_004E1EE8;
extern UnkStruct_A600_f D_004E1EE4;
extern "C" void func_003FBA10(void *, int);
extern "C" void func_0027A8F0(void *, int);
extern "C" void func_003FC470(void *);
extern "C" int func_003FB890(void *);
extern "C" int func_003FB7C0(void *);
extern "C" void func_003FBB50(void *, int, void *);
extern "C" void func_003FBA00(void *, int);
extern "C" int func_003FBDB0(void *);
extern "C" int func_003FC060(void *, void *, int, int);
extern "C" void func_003FC5D0(void *);

static inline unsigned func_003FA600_rnd()
{
    int a = _mRandom__13CGtSoundUtils.field_0;
    int x = (a << 16) + (a >> 16);
    x += _mRandom__13CGtSoundUtils.field_4;
    _mRandom__13CGtSoundUtils.field_4 += x;
    _mRandom__13CGtSoundUtils.field_0 = x;
    return x;
}

static inline void func_003FA600_free(UnkStruct_A600 * self)
{
    if (self->field_160 != 0) {
        Stop__14CGtSoundStreamFv(self->field_160);
        Release__14CGtSoundStreamFv(self->field_160);
        FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, self->field_160);
        self->field_160 = 0;
    }
}

static inline void func_003FA600_play(UnkStruct_A600 * self, UnkStruct_A600_out & out)
{
    func_003FC470(self);
    func_003FBB50(self, self->field_EC, &out);
    int k = D_004F507A.field_0 ? 2 : 1;
    func_003FBA00(self, k);
    int v = func_003FBDB0(self);
    func_003FC060(self, &out, v, k);
    D_004F5077.field_0 = v;
}

// 0x003FA600
extern "C" void func_003FA600(UnkStruct_A600 * self, int mode)
{
    UnkStruct_A600_out out1;
    UnkStruct_A600_out out2;
    int old = self->field_178;
    bool s2 = false;
    bool s1 = true;
    bool s0 = s1;
    if (mode == 5) {
        func_003FBA10(self, 1);
    } else {
        func_003FBA10(self, 0);
    }
    if ((unsigned)(mode - 4) < 3) {
        self->field_4 = D_004E1EE8.field_0;
    } else {
        self->field_4 = D_004E1EE4.field_0;
    }
    if ((unsigned)(mode - 5) < 2) {
        func_0027A8F0(&D_01E78510, 1);
    } else {
        func_0027A8F0(&D_01E78510, 0);
    }
    if (mode == self->field_178) return;
    self->field_178 = mode;
    switch (old) {
    case 4:
        if (mode == 5 && self->field_174 != 13) {
            s1 = false;
            s0 = false;
        }
    case 1:
    case 2:
    case 3:
    case 5:
        if (self->field_174 == 1) {
            if (self->field_178 != 4) goto tail;
        }
        if (s0) {
            self->field_17C = 0;
            self->field_180 = -1;
            self->field_184 = -1;
            self->field_188 = 0;
            self->field_18C = 0;
            self->field_198 = self->field_198 & 0x30;
            self->field_1AD = 0;
            self->field_174 = 13;
            func_003FC470(self);
            {
                bool playing = self->field_16C != 0 ? IsPlaying__17CGtSoundRealVoiceCFv(self->field_16C) : false;
                if (playing) goto stopvoice;
                self->field_16C = 0;
            }
        voiceoff:
            self->field_198 = self->field_198 & -5;
            func_003FA600_free(self);
            self->field_F0[0] = 0;
            {
                self->field_195 = func_003FA600_rnd() % 38;
            }
            {
                unsigned i = 0;
                do {
                    unsigned j = i + func_003FA600_rnd() % (38 - i);
                    unsigned char a = self->field_130[i];
                    unsigned char b = self->field_130[j];
                    self->field_130[j] = a;
                    self->field_130[i] = b;
                    i++;
                } while (i < 38);
            }
        }
        if (self->field_178 == 3) goto tail;
        if (!s1) goto tail;
        if (func_003FB890(self) != 0 || func_003FB7C0(self) == 0) {
            func_003FA600_play(self, out1);
            s2 = true;
        }
        if (self->field_C == 0) goto none;
        self->field_174 = 11;
        break;
    case 0:
    case 6:
        break;
    }
tail:
    if (self->field_178 == 4) {
        func_003FA600_free(self);
        self->field_F0[0] = 0;
        if (!s2) {
            if (func_003FB890(self) != 0 || func_003FB7C0(self) == 0) {
                func_003FA600_play(self, out2);
            }
        }
        self->field_174 = 0;
    }
    return;
stopvoice:
    Stop__17CGtSoundRealVoiceFv(self->field_16C);
    self->field_16C = 0;
    goto voiceoff;
none:
    func_003FC5D0(self);
    self->field_174 = 0;
    goto tail;
}
