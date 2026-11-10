// NONMATCHING: func_003F8C30 -- retail 880 / ours 880 instructions, 67 in changed runs
// draft4 + grind1: twin of proven func_003F99F0; frame right. grind1 fixed: bool callees (!f() vs ==0 picks andi), GtRandom Random() + const float k, stop==true, player loop as empty-then (if (!all || x==0) {} else b=true), rebuild block as inline (stack order). Open: the state-9 rebuild block lands out of line (the field_C break block after it triggers it; removing that block puts it inline)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm and Ghidra draft on the proven twin's declarations; every state, branch, store and call accounted for; same call multiset (calls.sh)

#include "b3/_unclassified/GtRandom.h"
// func_003F8C30 -- draft4 (breadth-first draft): the jingle/music stream state machine Update [G], twin of
// func_003F99F0 (same struct, same inlines; declarations copied from it). Types/field names placeholders [G].
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
    unsigned char pad_0[0xC];
    unsigned char field_C;                   // [C] lb: a further bank cycle requested (state 12)
    unsigned char pad_D[0xEC - 0xD];
    int field_EC;                          // [C] passed to func_003FBB50
    char field_F0[0x20];
    char field_110[0x20];
    unsigned char field_130[0x26];         // [C] track shuffle table, indexed by field_195 (mod 38)
    unsigned char pad_156[0xA];
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
    float field_190;                       // [C] seconds until the next jingle
    signed char field_194;
    signed char field_195;                 // [C] shuffle position
    unsigned char pad_196[0x2];
    int field_198;
    unsigned char pad_19C[0x4];
    float field_1A0;
    unsigned char pad_1A4[0x4];
    float field_1A8;
    unsigned char field_1AC;
    unsigned char pad_1AD[0x2];
    unsigned char field_1AF;               // [C] lbu, tested with func_003FBBE0 in state 2
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
extern UnkStruct_99F0_f D_004E1EFC;   // [C] gp-relative volume scale
extern UnkStruct_99F0_i D_0052267C;   // [C] frame time (lwc1 %lo), read as float
struct UnkStruct_8C30_hash { unsigned long *p; unsigned char pad[0xC]; };
extern UnkStruct_8C30_hash D_00516E44; // [C] pointer to the current 64-bit mode hash (or null)
extern UnkStruct_99F0_o D_00522660;
struct UnkStruct_8C30_sb { signed char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_8C30_sb D_004F507A;
extern UnkStruct_99F0_b D_004F5077;
extern UnkStruct_99F0_i2 D_004E1EC0;
extern UnkStruct_99F0_i2 D_004E1EC4;
extern "C" CGtRandom _mRandom__13CGtSoundUtils;
extern "C" void func_003FC470(void *);
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" void * TriggerRealVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(void *, const void *);
extern "C" void IgnoreGlobalPitch__17CGtSoundRealVoiceFv(void *);
extern "C" bool IsPlaying__17CGtSoundRealVoiceCFv(void *);
extern "C" void Stop__17CGtSoundRealVoiceFv(void *);
extern "C" UnkStruct_99F0_stream * AllocStream__21CGtSoundStreamManagerFb(void *, bool);
extern "C" int GetStreamsPreparing__21CGtSoundStreamManagerFv(void *);
extern "C" void FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(void *, void *);
extern "C" bool func_00385FD0(void *);
extern "C" bool func_00385FE0(void *);
extern "C" int func_00385EC0(void *);
extern "C" void func_00385EA0(void *, int, float, float, float, float);
extern "C" void func_00385EB0(void *);
extern "C" bool AttachMedia__14CGtSoundStreamFPCc(void *, const char *, int);
extern "C" void Stop__14CGtSoundStreamFv(void *);
extern "C" int Release__14CGtSoundStreamFv(void *);
extern "C" void Play__14CGtSoundStreamFb(void *, bool);
extern "C" void SetVolume__14CGtSoundStreamFfi(void *, float, int);
extern "C" void UnloadBank__19CGtSoundBankManagerFP12CGtSoundBank(void *, void *);
extern "C" void * LoadBank__19CGtSoundBankManagerFPCcbbi(void *, const char *, bool, bool, int);
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);
extern "C" int sprintf(char *, const void *, ...);
extern "C" int func_00131E40(void *);

extern "C" bool func_003865A0(void *, const char *, int, int, int, int);
extern "C" void func_003F8580(UnkStruct_99F0 *, char *, int *, int *);
extern "C" void func_003FBA40(UnkStruct_99F0 *, int);
extern "C" int func_003FBBE0(UnkStruct_99F0 *);
extern "C" bool func_003FBBB0(UnkStruct_99F0 *);
extern "C" void func_003FC520(UnkStruct_99F0 *);
extern "C" void func_003FC260(UnkStruct_99F0 *);
extern "C" void func_003FC2E0(UnkStruct_99F0 *);
extern "C" int func_003FC210(UnkStruct_99F0 *);
extern "C" int func_003FB890(UnkStruct_99F0 *);
extern "C" int func_003FB7C0(UnkStruct_99F0 *);
extern "C" void func_003FBB50(UnkStruct_99F0 *, int, char *);
extern "C" void func_003FBA00(UnkStruct_99F0 *, int);
extern "C" int func_003FBDB0(UnkStruct_99F0 *);
extern "C" int func_003FC060(UnkStruct_99F0 *, char *, int, int);
extern "C" void func_003FC5D0(UnkStruct_99F0 *);

// [L] inlines (repeated verbatim in retail; names unknown), as in func_003F99F0 (after7):
static inline void func_003F8C30_inl1(UnkStruct_99F0 *self)  // stop the jingle voice
{
    bool playing = self->field_16C != 0 ? IsPlaying__17CGtSoundRealVoiceCFv(self->field_16C) : false;
    if (playing)
        Stop__17CGtSoundRealVoiceFv(self->field_16C);
    self->field_16C = 0;
    self->field_198 = self->field_198 & -5;
}
static inline void func_003F8C30_inl2(UnkStruct_99F0 *self)  // release the old jingle bank, load the next one
{
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
        if (self->field_194 == 10)
            self->field_194 = 0;
    }
}
static inline void func_003F8C30_inl3(UnkStruct_99F0 *self)  // start the jingle voice
{
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
}
static inline void func_003F8C30_inl4(UnkStruct_99F0 *self)  // next jingle in 60..70 s (CGtSoundUtils::mRandom)
{
    const float k = 2.3283064e-10f;
    self->field_190 = k * (float)_mRandom__13CGtSoundUtils.Random() * 10.0f + 60.0f;
}
static inline unsigned long func_003F8C30_inl5()  // the current mode's hash, a default when unset
{
    if (D_00516E44.p != 0)
        return *D_00516E44.p;
    return 0x6D6123044330FCCFUL;
}

static inline void func_003F8C30_inl6(UnkStruct_99F0 *self)  // rebuild the playlist [G]
{
    char buf[0x60];
    func_003FC470(self);
    func_003FBB50(self, self->field_EC, buf);
    int n = 2;
    if (D_004F507A.field_0 == 0)
        n = 1;
    func_003FBA00(self, n);
    int v = func_003FBDB0(self);
    func_003FC060(self, buf, v, n);
    D_004F5077.field_0 = v;
}

// 0x003F8C30
extern "C" void func_003F8C30(UnkStruct_99F0 *self)
{
    bool all = true;
    bool stop = false;
    if (D_0064D3A0.field_0 > 1 || func_00131E40(&D_004EE040) != 0) {
        func_003FC470(self);
        return;
    }
    if (func_00131E40(&D_004EE040) != 0 || D_01E65499.field_0 != 0 || self->field_1AC != 0 || D_01E900B4.field_0 != 0) {
        func_003FBA40(self, 1);
        stop = true;
    }
    if (func_003F8C30_inl5() == 0xBA38E82B9CC11F7FUL || func_003F8C30_inl5() == 0xBA38E7C8878337FFUL) {
        func_003FBA40(self, 1);
        stop = true;
    } else {
        for (int i = 0; i < D_0064D3A0.field_0; i++) {
            bool b = false;
            if (!all || *((unsigned char *)&D_00522660 + i * 0x27D0 + 0x12C63A) == 0) {
            } else
                b = true;
            all = b;
        }
        if (all) {
            func_003F8C30_inl1(self);
            if ((self->field_198 & 0x80) == 0) {
                func_003FC2E0(self);
                self->field_198 = self->field_198 | 0x80;
            }
            if (self->field_160 != 0) {
                Stop__14CGtSoundStreamFv(self->field_160);
                Release__14CGtSoundStreamFv(self->field_160);
                FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, self->field_160);
                self->field_160 = 0;
            }
            self->field_F0[0] = 0;
            self->field_174 = 9;
            self->field_198 = self->field_198 & -2;
            self->field_198 = self->field_198 & -3;
            self->field_184 = -1;
            return;
        }
    }

    switch (self->field_174) {
    case 2:
        if (func_003FBBE0(self) != 0 || self->field_1AF != 0) {
            if (self->field_1AF != 0 && func_003FBBE0(self) == 0)
                func_003FC520(self);
            goto st11;
        }
        goto ready;
    case 11:
    st11:
        if (stop)
            return;
        self->field_190 = self->field_190 - *(float *)&D_0052267C.field_0;
        if (self->field_190 > 0.0f)
            return;
        if (self->field_174 != 11) {
            if (func_003FC210(self) < 20000) {
                func_003F8C30_inl4(self);
                break;
            }
            func_003FC2E0(self);
            self->field_198 = self->field_198 | 0x80;
        }
    ready:
        self->field_198 = self->field_198 & -2;
        if (stop == true) {
            self->field_174 = 9;
            break;
        }
        self->field_174 = 3;
    case 3:
        func_003F8C30_inl3(self);
        self->field_174 = 4;
    case 4:
        self->field_160 = AllocStream__21CGtSoundStreamManagerFb(&D_01E774E0, false);
        if (self->field_160 == 0)
            return;
        func_003F8580(self, self->field_F0, &self->field_188, &self->field_18C);
        self->field_174 = 5;
    case 5: {
        if (func_00385FD0(self->field_160) == 0 && GetStreamsPreparing__21CGtSoundStreamManagerFv(&D_01E774E0) != 0)
            return;
        if (AttachMedia__14CGtSoundStreamFPCc(self->field_160, self->field_F0, 4) == 0)
            return;
        self->field_184 = func_00385EC0(self->field_160);
        if (self->field_18C == 0)
            self->field_18C = self->field_184;
        int old = self->field_180;
        int span = self->field_18C - self->field_188;
        self->field_195 = (self->field_195 + 1) % 38;
        self->field_180 = self->field_188 + (int)self->field_130[self->field_195] % span;
        if (old == self->field_180) {
            self->field_195 = (self->field_195 + 1) % 38;
            self->field_180 = self->field_188 + (int)self->field_130[self->field_195] % span;
        }
        self->field_174 = 6;
    }
    case 6:
        if (func_003865A0(self->field_160, self->field_F0, 0, 0, self->field_180, 4) == 0)
            return;
        self->field_174 = 7;
    case 7:
        if (self->field_16C != 0 ? IsPlaying__17CGtSoundRealVoiceCFv(self->field_16C) : false)
            return;
        func_003F8C30_inl1(self);
        func_003F8C30_inl2(self);
        func_00385EA0(self->field_160, -1, 1.0f, 0.0f, 0.125f, 0.0f);
        Play__14CGtSoundStreamFb(self->field_160, false);
        func_00385EB0(self->field_160);
        SetVolume__14CGtSoundStreamFfi(self->field_160, self->field_1A0 * D_004E1EFC.field_0, -1);
        self->field_160->field_1EC = 14;
        self->field_174 = 8;
    case 8:
        if (func_00385FE0(self->field_160) == 0)
            return;
        Release__14CGtSoundStreamFv(self->field_160);
        self->field_184 = -1;
        FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, self->field_160);
        self->field_160 = 0;
        self->field_174 = 9;
    case 9:
        func_003F8C30_inl3(self);
        func_003F8C30_inl4(self);
        if (!func_003FBBB0(self)) {
            if ((self->field_198 & 0x80) == 0 && (func_003FB890(self) != 0 || func_003FB7C0(self) == 0))
                func_003F8C30_inl6(self);
            if (self->field_C != 0) {
                self->field_174 = 12;
                break;
            }
            func_003FC5D0(self);
        }
        self->field_174 = 0;
    case 0:
        if (func_003FBBB0(self) == 0)
            return;
        self->field_174 = 1;
    case 1:
        if (self->field_16C != 0 ? IsPlaying__17CGtSoundRealVoiceCFv(self->field_16C) : false)
            return;
        func_003F8C30_inl1(self);
        func_003F8C30_inl2(self);
        if ((self->field_198 & 0x80) != 0) {
            func_003FC260(self);
            self->field_198 = self->field_198 & -129;
        } else {
            func_003FC520(self);
            self->field_198 = self->field_198 & -65;
        }
        self->field_198 = self->field_198 | 1;
        self->field_174 = 2;
        break;
    case 12:
        if (self->field_16C != 0 ? IsPlaying__17CGtSoundRealVoiceCFv(self->field_16C) : false)
            return;
        func_003F8C30_inl1(self);
        func_003F8C30_inl2(self);
        self->field_174 = 11;
        break;
    case 10:
    default:
        break;
    }
}




