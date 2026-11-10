// Hand-written; the lifter refused it (mwperm: 'sprintf(self->field_F0, D_004CE958, D_004E1EC8.field_0, D_00' -> 'int t1 = func_003EAA60((void *)(FindTrack__21CB3HardCodedTrackListFUl(s1))); sprintf(self-').

// func_003F9F70 -- music stream state machine Update [G] (states 0/11 -> 4 -> 5 -> 6 -> 7 -> 8 -> 13; siblings func_003FA510 (bank load), func_003F8580/8AA0 (track pick))
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

struct UnkStruct_9F70 {
    unsigned char pad_0[0xF0];
    char field_F0[0x20];
    char field_110[0x20];
    unsigned char field_130[0x26];
    unsigned char pad_156[0x2];
    unsigned long field_158;
    UnkStruct_99F0_stream * field_160;
    unsigned char pad_164[0x10];
    int field_174;
    unsigned char pad_178[0x4];
    int field_17C;
    int field_180;
    int field_184;
    int field_188;
    int field_18C;
    unsigned char pad_190[0x5];
    signed char field_195;
    unsigned char pad_196[0x2];
    int field_198;
    unsigned char pad_19C[0x4];
    float field_1A0;
    unsigned char pad_1A4[0x8];
    unsigned char field_1AC;
    unsigned char field_1AD;
};
struct UnkStruct_9F70_i { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_9F70_f { float field_0; };
extern UnkStruct_9F70_i D_0051A9A4;
extern UnkStruct_99F0_o D_01E88AF0;
extern UnkStruct_9F70_f D_004E1F00;
extern UnkStruct_99F0_i2 D_004E2918;
extern UnkStruct_99F0_i2 D_004E1EC8;
extern UnkStruct_99F0_i2 D_004E1ED8;
extern int D_004A55D0[];
extern int D_004A55C0[];
extern char D_004CE958[];
extern "C" unsigned long func_003A7060(void *);
extern "C" int func_003A7000(void *);
extern "C" int FindTrack__21CB3HardCodedTrackListFUl(unsigned long);
extern "C" int func_003EAA60(void *);
extern "C" unsigned char func_003FBBB0(void *);
extern "C" int func_003FBBE0(void *);
extern "C" void func_003FC260(void *);
extern "C" void func_003FC520(void *);

static inline void func_003F9F70_free(UnkStruct_9F70 * self)
{
    if (self->field_160 != 0) {
        Stop__14CGtSoundStreamFv(self->field_160);
        Release__14CGtSoundStreamFv(self->field_160);
        FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, self->field_160);
        self->field_160 = 0;
    }
}

// 0x003F9F70
extern "C" void func_003F9F70(UnkStruct_9F70 * self)
{
    bool s2 = false;
    if (D_0051A9A4.field_0 < 26) return;
    switch (self->field_17C) {
    case 0:
    case 1:
    case 2:
        func_003F9F70_free(self);
        self->field_F0[0] = 0;
        self->field_198 = self->field_198 & -3;
        self->field_1AD = 0;
        break;
    case 4:
    case 3:
        if (self->field_F0[0] == 0) goto pick;
    chk:
        if (D_01E900B4.field_0 == 0) s2 = !(self->field_1AC != 0);
        break;
    default:
        break;
    }
gate:
    if (s2 && self->field_1AD == 0) {
        if (self->field_160 == 0) goto alloc;
    got:
        if (self->field_160 != 0) {
            if ((self->field_198 & 2) != 0) goto waitloop;
            if (AttachMedia__14CGtSoundStreamFPCc(self->field_160, self->field_F0, 8) != 0) goto attached;
        after:
            if (self->field_184 > 0) {
                if (func_003865A0(self->field_160, self->field_F0, 0, 0, self->field_180, 4) != 0) {
                    self->field_198 = self->field_198 | 2;
                    Play__14CGtSoundStreamFb(self->field_160, false);
                    SetVolume__14CGtSoundStreamFfi(self->field_160, self->field_1A0 * D_004E1F00.field_0, -1);
                    ((UnkStruct_99F0_stream *)self->field_160)->field_1EC = 14;
                    self->field_1AD = 1;
                }
            }
        }
    } else {
        if (self->field_1AD == 0) {
            self->field_198 = self->field_198 & -3;
            func_003F9F70_free(self);
            self->field_F0[0] = 0;
            self->field_184 = -1;
        }
    }
fsm:
    switch (self->field_174) {
    case 0:
        if (func_003FBBB0(self) == 0) break;
        self->field_174 = 1;
    case 1:
        if ((self->field_198 & 0x80) != 0) {
            func_003FC260(self);
            self->field_198 = self->field_198 & -129;
        } else {
            func_003FC520(self);
            self->field_198 = self->field_198 & -65;
        }
        self->field_198 = self->field_198 | 1;
        self->field_174 = 2;
    case 2:
        if (func_003FBBE0(self) != 0) break;
        func_003FC520(self);
    default:
        return;
    case 11:
        break;
    }
    return;
pick:
    {
        unsigned long s0 = func_003A7060(&D_01E88AF0);
        unsigned long s1 = func_003A7060(&D_01E88AF0);
        if (func_003A7000(&D_01E88AF0) == 0) {
            int a = _mRandom__13CGtSoundUtils.field_0;
            int x = (a << 16) + (a >> 16);
            x += _mRandom__13CGtSoundUtils.field_4;
            _mRandom__13CGtSoundUtils.field_4 += x;
            _mRandom__13CGtSoundUtils.field_0 = x;
            if ((x & 7) != 0) {
                func_003F8AA0(self, s1, self->field_F0, &self->field_188, &self->field_18C, 0, 1);
            } else {
                int t1 = func_003EAA60((void *)(FindTrack__21CB3HardCodedTrackListFUl(s1)));
                sprintf(self->field_F0, D_004CE958, D_004E1EC8.field_0, D_004A55D0[D_004E2918.field_0], D_004A55C0[t1], D_004E1ED8.field_0);
                self->field_188 = 0;
                self->field_18C = 0;
            }
        } else {
            func_003F8AA0(self, s1, self->field_F0, &self->field_188, &self->field_18C, 1, 1);
        }
        self->field_158 = s0;
        goto chk;
    }
alloc:
    self->field_160 = AllocStream__21CGtSoundStreamManagerFb(&D_01E774E0, false);
    goto got;
attached:
    self->field_184 = func_00385EC0(self->field_160);
    if (self->field_18C == 0) self->field_18C = self->field_184;
    {
        int span = self->field_18C - self->field_188;
        int a2 = self->field_180;
        self->field_195 = (self->field_195 + 1) % 38;
        self->field_180 = self->field_188 + self->field_130[self->field_195] % span;
        if (a2 == self->field_180) {
            self->field_195 = (self->field_195 + 1) % 38;
            self->field_180 = self->field_188 + self->field_130[self->field_195] % span;
        }
    }
    goto after;
waitloop:
    if (func_00385FE0(self->field_160) == 0) goto fsm;
    self->field_198 = self->field_198 & -3;
    func_003F9F70_free(self);
    self->field_F0[0] = 0;
    self->field_184 = -1;
    goto fsm;
}
