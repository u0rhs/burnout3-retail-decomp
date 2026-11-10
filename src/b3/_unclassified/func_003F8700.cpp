// Hand-written; the lifter refused it (reset + shuffle; void* field_160 keeps block inline; single store after if).

struct UnkStruct_003F8700 {
    unsigned char pad_0[0xF0];
    unsigned char field_F0;
    unsigned char pad_F1[0x3F];
    unsigned char field_130[0x30];
    void *field_160;
    unsigned char pad_164[0x8];
    void *field_16C;
    unsigned char pad_170[0x4];
    int field_174;
    unsigned char pad_178[0x4];
    int field_17C;
    int field_180;
    int field_184;
    int field_188;
    int field_18C;
    unsigned char pad_190[0x5];
    unsigned char field_195;
    unsigned char pad_196[0x2];
    unsigned int field_198;
    unsigned char pad_19C[0x11];
    unsigned char field_1AD;
};
struct UnkStruct_003F8700_rnd { int field_0; int field_4; };
struct UnkStruct_D_01E774E0_x { unsigned char pad_0[0x10]; };
extern "C" UnkStruct_003F8700_rnd _mRandom__13CGtSoundUtils;
extern UnkStruct_D_01E774E0_x D_01E774E0;
extern "C" void func_003FC470(void *);
extern "C" bool IsPlaying__17CGtSoundRealVoiceCFv(void *);
extern "C" void Stop__17CGtSoundRealVoiceFv(void *);
extern "C" void Stop__14CGtSoundStreamFv(void *);
extern "C" int Release__14CGtSoundStreamFv(void *);
extern "C" void FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(void *, void *);
static inline unsigned int func_003F8700_inl1()
{
    int a = _mRandom__13CGtSoundUtils.field_0;
    int x = (a << 16) + (a >> 16);
    x += _mRandom__13CGtSoundUtils.field_4;
    _mRandom__13CGtSoundUtils.field_4 += x;
    _mRandom__13CGtSoundUtils.field_0 = x;
    return x;
}
// 0x003F8700
extern "C" void func_003F8700(UnkStruct_003F8700 *self)
{
    self->field_17C = 0;
    self->field_180 = -1;
    self->field_184 = -1;
    self->field_188 = 0;
    self->field_18C = 0;
    self->field_198 &= 0x30;
    self->field_1AD = 0;
    self->field_174 = 13;
    func_003FC470(self);
    bool playing;
    if (self->field_16C != 0) {
        playing = IsPlaying__17CGtSoundRealVoiceCFv(self->field_16C);
    } else {
        playing = false;
    }
    if (playing) {
        Stop__17CGtSoundRealVoiceFv(self->field_16C);
    }
    self->field_16C = 0;
    self->field_198 &= ~4;
    void *h = self->field_160;
    if (h != 0) {
        Stop__14CGtSoundStreamFv(h);
        Release__14CGtSoundStreamFv(self->field_160);
        FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, self->field_160);
        self->field_160 = 0;
    }
    self->field_F0 = 0;
    unsigned int n = 0x26;
    self->field_195 = func_003F8700_inl1() % n;
    unsigned int i = 0;
    do {
        unsigned int j = i + func_003F8700_inl1() % (n - i);
        unsigned char t = self->field_130[i];
        unsigned char u = self->field_130[j];
        self->field_130[j] = t;
        self->field_130[i] = u;
        i++;
    } while (i < 0x26);
}
