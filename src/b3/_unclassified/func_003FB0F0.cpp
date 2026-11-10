// Hand-written; the lifter refused it (sig1: 'const float k = 2^-32; float v = k * (float)rnd();' hoists the constant (func_0026BD50 idiom); func_003FBBB0 declared bool as proven, tested with !; func_0042B4E0 keeps its float arg (retail sets f12; the callee is an empty stub)).


struct UnkStruct_FB0F0_rnd { int field_0; int field_4; };
struct UnkStruct_FB0F0_o { unsigned char pad_0[0x10]; };
struct UnkStruct_FB0F0_f { float field_0; };
struct UnkStruct_FB0F0_i { int field_0; };
struct UnkStruct_FB0F0_c { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_FB0F0 {
    float field_0;
    unsigned char pad_4[4];
    unsigned char field_8[0x4];
    unsigned char field_C;
    unsigned char pad_D[0xDF];
    int field_EC;
    char field_F0[0x20];
    char field_110[0x20];
    unsigned char field_130[0x26];
    unsigned char pad_156[0xA];
    void * field_160;
    void * field_164;
    int field_168;
    void * field_16C;
    int field_170;
    int field_174;
    int field_178;
    int field_17C;
    int field_180;
    int field_184;
    int field_188;
    int field_18C;
    float field_190;
    signed char field_194;
    unsigned char field_195;
    unsigned char pad_196[2];
    int field_198;
    unsigned char pad_19C[4];
    float field_1A0;
    unsigned char pad_1A4[4];
    float field_1A8;
    unsigned char pad_1AC;
    unsigned char field_1AD;
    unsigned char field_1AE;
};
extern UnkStruct_FB0F0_o D_01E75648;
extern UnkStruct_FB0F0_o D_01E774E0;
extern UnkStruct_FB0F0_o D_004CE9C8;
extern UnkStruct_FB0F0_o D_004CE9D0;
extern UnkStruct_FB0F0_o D_0051A6A8;
extern UnkStruct_FB0F0_o D_0051AEC0;
struct UnkStruct_FB0F0_p { UnkStruct_FB0F0_o * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_FB0F0_p D_0051BA88;
extern UnkStruct_FB0F0_c D_004F507A;
extern UnkStruct_FB0F0_c D_004F5077;
extern UnkStruct_FB0F0_c D_004F5075;
extern UnkStruct_FB0F0_f D_004E0C6C;
extern UnkStruct_FB0F0_f D_004E1EDC;
extern UnkStruct_FB0F0_f D_004E1EE0;
extern UnkStruct_FB0F0_i D_004E1EC0;
extern UnkStruct_FB0F0_i D_004E1EC4;
extern "C" UnkStruct_FB0F0_rnd _mRandom__13CGtSoundUtils;
extern "C" void * LoadBank__19CGtSoundBankManagerFPCcbbi(void *, const char *, bool, bool, int);
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);
extern "C" int sprintf(char *, const void *, ...);
extern "C" bool func_003FCC10(void *);
extern "C" void func_003FC470(void *);
extern "C" bool IsPlaying__17CGtSoundRealVoiceCFv(void *);
extern "C" void Stop__17CGtSoundRealVoiceFv(void *);
extern "C" void Stop__14CGtSoundStreamFv(void *);
extern "C" int Release__14CGtSoundStreamFv(void *);
extern "C" void FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(void *, void *);
extern "C" void func_003FBA10(void *, int);
extern "C" int func_003FB890(void *);
extern "C" int func_003FB7C0(void *);
extern "C" void func_003FBB50(void *, int, void *);
extern "C" void func_003FBA00(void *, int);
extern "C" int func_003FBDB0(void *);
extern "C" int func_003FC060(void *, void *, int, int);
extern "C" void func_003FC5D0(void *);
extern "C" void func_003FC8C0(void *);
extern "C" bool func_003FBBB0(void *);
extern "C" void func_003FA600(void *, int);
extern "C" void func_0042B4E0(void *, float);
static inline unsigned func_003FB0F0_inl1()
{
    int a = _mRandom__13CGtSoundUtils.field_0;
    int x = (a << 16) + (a >> 16);
    x += _mRandom__13CGtSoundUtils.field_4;
    _mRandom__13CGtSoundUtils.field_4 += x;
    _mRandom__13CGtSoundUtils.field_0 = x;
    return x;
}
static inline float func_003FB0F0_rf()
{
    return 2.3283064e-10f * (float)func_003FB0F0_inl1();
}
static inline void func_003FB0F0_inl2(UnkStruct_FB0F0 * self)
{
    unsigned n = 0x26;
    self->field_195 = func_003FB0F0_inl1() % n;
    unsigned t = 0;
    do {
        unsigned j = t + func_003FB0F0_inl1() % (n - t);
        unsigned char a = self->field_130[t];
        unsigned char b = self->field_130[j];
        self->field_130[j] = a;
        self->field_130[t] = b;
        t++;
    } while (t < 0x26);
}
// 0x003FB0F0
extern "C" int func_003FB0F0(UnkStruct_FB0F0 * self, int p1)
{
    char sp60[0x60];
    int st = self->field_170;
    UnkStruct_FB0F0_o * s0 = D_0051BA88.field_0;
    switch (st) {
    case 1:
    case 0x19:
    case 0x18:
        self->field_174 = 13;
        self->field_170 = 2;
    case 2:
        if (s0 != &D_0051A6A8) {
            bool ok;
            if (!(self->field_198 & 0x10)) {
                sprintf(self->field_110, &D_004CE9D0, D_004E1EC0.field_0, D_004E1EC4.field_0, self->field_194);
                self->field_198 = self->field_198 | 0x10;
            }
            self->field_164 = LoadBank__19CGtSoundBankManagerFPCcbbi(&D_01E75648, self->field_110, true, false, 0x800);
            if (self->field_164 == 0) {
                ok = false;
            } else {
                self->field_168 = FindWave__12CGtSoundBankCFRCUlb(self->field_164, &D_004CE9C8, false);
                self->field_198 = self->field_198 & -17;
                self->field_194 = self->field_194 + 1;
                if (self->field_194 == 10) self->field_194 = 0;
                ok = true;
            }
            if (ok == false) return 0;
        }
        self->field_170 = 3;
    case 3:
        self->field_170 = 4;
    case 4:
        if (s0 != &D_0051AEC0 && func_003FCC10(self) == false) return 0;
        self->field_170 = 5;
    case 5:
        self->field_170 = 6;
    case 0x17:
    case 6:
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
            if (playing) {
                Stop__17CGtSoundRealVoiceFv(self->field_16C);
            }
            self->field_16C = 0;
        }
        self->field_198 = self->field_198 & -5;
        if (self->field_160 != 0) {
            Stop__14CGtSoundStreamFv(self->field_160);
            Release__14CGtSoundStreamFv(self->field_160);
            FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, self->field_160);
            self->field_160 = 0;
        }
        self->field_F0[0] = 0;
        func_003FB0F0_inl2(self);
        const float k = 2.3283064e-10f;
        float v = k * (float)func_003FB0F0_inl1();
        self->field_190 = 0.0f + 60.0f + 10.0f * v;
        if (self->field_1AE != 0 && self->field_174 != 0) {
            if (p1 == 5) {
                func_003FBA10(self, 1);
            } else {
                func_003FBA10(self, 0);
            }
            if (func_003FB890(self) != 0 || func_003FB7C0(self) == 0) {
                func_003FC470(self);
                func_003FBB50(self, self->field_EC, sp60);
                int s0b = D_004F507A.field_0 != 0 ? 2 : 1;
                func_003FBA00(self, s0b);
                int s3 = func_003FBDB0(self);
                func_003FC060(self, sp60, s3, s0b);
                D_004F5077.field_0 = s3;
            }
            if (self->field_C != 0) {
                self->field_174 = 0xB;
                self->field_170 = 0x17;
                goto fin;
            }
            func_003FC5D0(self);
            self->field_174 = 0;
            if (self->field_178 == 2) {
                self->field_170 = 0x17;
                return 1;
            }
        }
        self->field_170 = 7;
    case 7:
        if (self->field_1AE != 0) {
            func_003FC8C0(self);
            if (!func_003FBBB0(self)) return 0;
            self->field_174 = 1;
        } else {
            self->field_174 = 13;
        }
        self->field_170 = 0x17;
    fin:
    default:
        func_003FA600(self, p1);
        {
            float f20 = D_004E0C6C.field_0 * (float)D_004F5075.field_0;
            self->field_0 = f20;
            func_0042B4E0(self->field_8, f20);
            self->field_1A0 = f20 * D_004E1EDC.field_0;
            self->field_1A8 = f20 * D_004E1EE0.field_0;
        }
        func_003FB0F0_inl2(self);
        return 1;
    }
}
