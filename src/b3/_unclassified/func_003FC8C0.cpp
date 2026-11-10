// Hand-written; the lifter refused it (mwperm: 'int field_D4;' -> 'unsigned int field_D4;').

// func_003FC8C0 -- music stream state machine Update [G] (states 0/11 -> 4 -> 5 -> 6 -> 7 -> 8 -> 13; siblings func_003FA510 (bank load), func_003F8580/8AA0 (track pick))
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

struct UnkStruct_C8C0_p { unsigned char pad_0[0x14]; int field_14; };
struct UnkStruct_C8C0 {
    float field_0;
    float field_4;
    unsigned char field_8[0xB4];
    unsigned char field_BC;
    unsigned char pad_BD[0x3];
    UnkStruct_99F0_stream * field_C0;
    UnkStruct_C8C0_p * field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    unsigned int field_D4;
    int field_D8;
    unsigned char pad_DC[0x4];
    int field_E0;
    unsigned char pad_E4[0x4];
    unsigned char field_E8;
};
struct UnkStruct_C8C0_g { void * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_C8C0_g D_0051BA88;
extern UnkStruct_99F0_o D_0051A6A8;
extern unsigned char D_004F5040[];
extern "C" int func_003865A0(void *, const char *, int, int, int, int);
extern "C" void func_003FC700(void *);
extern "C" void func_0042B5C0(void *);
extern "C" void func_0042B580(void *);
extern "C" int func_003FBDB0(void *);
extern "C" void func_003FBC20(void *, int);

static inline void func_003FC8C0_stop(UnkStruct_C8C0 * self)
{
    self->field_E8 = self->field_E8 & 0xFE;
    if (self->field_BC != 0) {
        if (self->field_C0 != 0) {
            Stop__14CGtSoundStreamFv(self->field_C0);
            Release__14CGtSoundStreamFv(self->field_C0);
            FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, self->field_C0);
            self->field_C0 = 0;
        }
        if (self->field_D0 == 4) {
            self->field_D0 = 5;
            func_003FC700(self);
        }
        self->field_C8 = 6;
    } else {
        func_0042B580(self->field_8);
    }
}

// 0x003FC8C0
extern "C" void func_003FC8C0(UnkStruct_C8C0 * self)
{
    int v;
    switch (self->field_C8) {
    case 0:
    case 5:
        if (D_0064D370.field_0 == 0 || D_0064D3A0.field_0 <= 1) {
            self->field_C0 = AllocStream__21CGtSoundStreamManagerFb(&D_01E774E0, false);
        } else {
            self->field_C0 = AllocStream__21CGtSoundStreamManagerFb(&D_01E774E0, true);
        }
        if (self->field_C0 == 0) return;
        self->field_E8 = self->field_E8 & 0xDF;
        self->field_C8 = 1;
    case 1:
        {
            int t1 = 4;
            if (D_0051BA88.field_0 == (void *)&D_0051A6A8) t1 = 16;
            if (!(unsigned char)func_003865A0(self->field_C0, (const char *)self + 0x48, 0, self->field_D4, self->field_D8 - self->field_E0 * 22, t1)) return;
        }
        self->field_E8 = self->field_E8 & 0xEF;
        self->field_C8 = 2;
    case 2:
        if ((self->field_E8 & 1) == 0) goto tail;
        {
            bool k = false;
            if (self->field_CC == 4) k = true;
            Play__14CGtSoundStreamFb(self->field_C0, k);
        }
        SetVolume__14CGtSoundStreamFfi(self->field_C0, self->field_0 * self->field_4, 0);
        self->field_C0->field_1EC = 13;
        func_00385EB0(self->field_C0);
        self->field_C8 = 3;
        goto tail;
    case 3:
        if (func_00385FE0(self->field_C0) == 0) goto vol;
        self->field_C4->field_14 = self->field_C4->field_14 & -9;
        D_004F5040[self->field_D8] = D_004F5040[self->field_D8] & 0xF7;
        func_003FC8C0_stop(self);
        v = func_003FBDB0(self);
        if (v != -1) goto call20;
        func_003FC8C0_stop(self);
        return;
    case 4:
    case 6:
    case 7:
    default:
    tail:
        func_003FC700(self);
        func_0042B5C0(self->field_8);
        break;
    }
    return;
call20:
    func_003FBC20(self, v);
    return;
vol:
    SetVolume__14CGtSoundStreamFfi(self->field_C0, self->field_0 * self->field_4, 0);
    goto tail;
}
