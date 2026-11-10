// NONMATCHING: func_003FACC0 -- retail 267 / ours 268 instructions, 1 in changed runs
// sig1: 10 -> 1. Tail 'if (f131E40) {} else FC8C0(); return; out0: return;' (explicit return blocks) fixed the epilogue relays; chain 'int c = a0 != 0 && !(D==3 && func_0041E910() != 0);'. func_0041E910 stays int (retail sltu after the call, no andi). Left: one andi v1,0xFF at the chain join (bool-typed && result); int/bool/uchar/int-d forms either add it or move the call block out of line
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_003FACC0 -- retail 267 / ours 267 instructions, 10 in changed runs
// 269/267, 2 extra instrs (b; move v1,zero): bool-chain 'd = D_01E900B4==3; if (d) d = f()!=0; c = d^1' -- the 'else d=0' arm in this variant adds the b/move; without else (variant q) MWCC moves the call block out of line (10 changed). Rest exact: JTBL switch w/ explicit case 0/3, six: block placed via 'goto main; six:..return; main: load/unload; tail' order, load/unload/play/rnd inlines | classic-op fallback | guard: n/a (classic ops) | mwperm: 16 -> 10 ('return;' -> 'goto out0;'; +'out0: ;')
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

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

struct UnkStruct_ACC0 {
    unsigned char pad_0[0xEC];
    int field_EC;
    unsigned char pad_F0[0x20];
    char field_110[0x50];
    UnkStruct_99F0_stream * field_160;
    void * field_164;
    int field_168;
    unsigned char pad_16C[0x4];
    int field_170;
    int field_174;
    int field_178;
    unsigned char pad_17C[0x18];
    signed char field_194;
    unsigned char pad_195[0x3];
    int field_198;
    unsigned char pad_19C[0x13];
    unsigned char field_1AF;
    unsigned char field_1B0;
};
extern UnkStruct_99F0_o D_01E33A8C;
extern UnkStruct_99F0_o D_004F50C0;
extern "C" int func_0041E910(void *);
extern "C" int func_0022B850(void *);
extern "C" void func_003F8C30(void *);
extern "C" void func_003F9F70(void *);
extern "C" void func_003F99F0(void *);
extern "C" void func_003FC8C0(void *);

static inline void func_003FACC0_load(UnkStruct_ACC0 * self)
{
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
}

static inline void func_003FACC0_unload(UnkStruct_ACC0 * self)
{
    if ((self->field_198 & 0x10) != 0) {
        self->field_198 = self->field_198 | 0x20;
    } else if (self->field_164 != 0) {
        UnloadBank__19CGtSoundBankManagerFP12CGtSoundBank(&D_01E75648, self->field_164);
        self->field_164 = 0;
        self->field_168 = 0;
        self->field_198 = self->field_198 & -33;
    }
}

static inline void func_003FACC0_play(UnkStruct_ACC0 * self, UnkStruct_A600_out & out)
{
    func_003FC470(self);
    func_003FBB50(self, self->field_EC, &out);
    int k = D_004F507A.field_0 ? 2 : 1;
    func_003FBA00(self, k);
    int v = func_003FBDB0(self);
    func_003FC060(self, &out, v, k);
    D_004F5077.field_0 = v;
}

// 0x003FACC0
extern "C" void func_003FACC0(UnkStruct_ACC0 * self)
{
    UnkStruct_A600_out out;
    bool t2 = false;
    bool t1 = false;
    bool t0 = false;
    func_003FA600_rnd();
    self->field_1AF = 0;
    int mode = self->field_178;
    if (mode != 3) {
        if (self->field_1B0 != 0) t0 = true;
    }
    if (t0) {
        if (D_0064D370.field_0 != 0) t1 = true;
    }
    if (t1) {
        if (self->field_174 == 2) t2 = true;
    }
    int a0 = t2;
    if ((unsigned)(mode - 4) < 3) {
        if (self->field_160 != 0) a0 = 0;
    }
    int c = a0 != 0 && !(D_01E900B4.field_0 == 3 && func_0041E910(&D_01E33A8C) != 0);
    if (c != 0) {
        if (func_0022B850(&D_004F50C0) != 0) {
            func_003FACC0_play(self, out);
            self->field_1AF = 1;
        }
    }
    switch (self->field_178) {
    case 1:
    case 2:
        func_003F9F70(self);
        break;
    case 4:
        func_003F99F0(self);
        break;
    case 5:
        func_003F8C30(self);
        break;
    case 6:
        goto six;
    case 0:
    case 3:
        break;
    }
    goto main;
six:
    if ((self->field_198 & 0x10) != 0) {
        func_003FACC0_load(self);
    }
    if ((self->field_198 & 0x20) != 0) {
        func_003FACC0_unload(self);
    }
    goto out0;
main:
    if ((self->field_198 & 0x10) != 0) {
        func_003FACC0_load(self);
    }
    if ((self->field_198 & 0x20) != 0) {
        func_003FACC0_unload(self);
    }
    if (func_00131E40(&D_004EE040) != 0) {
    } else {
        func_003FC8C0(self);
    }
    return;
out0:
    return;
}
