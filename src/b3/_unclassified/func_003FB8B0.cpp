// Hand-written; the lifter refused it (regrot: shuffle swap reads/writes field_D[k] by index (no pointer local), k++ after the swap -- same fix as sibling func_003FBDB0).


struct UnkStruct_003FB8B0 {
    unsigned char pad_0[0xD];
    unsigned char field_D[0x30];
    unsigned char pad_3D[0x3];
    int field_40;
    int field_44;
    unsigned char pad_48[0x24];
    int field_6C;
    unsigned char pad_70[0x5C];
    int field_CC;
    unsigned char pad_D0[0x8];
    int field_D8;
};
struct UnkStruct_003FB8B0_rnd { int field_0; int field_4; };
extern "C" UnkStruct_003FB8B0_rnd _mRandom__13CGtSoundUtils;
static inline unsigned int func_003FB8B0_inl1()
{
    int a = _mRandom__13CGtSoundUtils.field_0;
    int x = (a << 16) + (a >> 16);
    x += _mRandom__13CGtSoundUtils.field_4;
    _mRandom__13CGtSoundUtils.field_4 += x;
    _mRandom__13CGtSoundUtils.field_0 = x;
    return x;
}
// 0x003FB8B0
extern "C" void func_003FB8B0(UnkStruct_003FB8B0 *self, int p0)
{
    if (self->field_44 != self->field_6C) {
        int n = self->field_44 = self->field_6C;
        int i = 0;
        while (i < n) {
            self->field_D[i] = i;
            i++;
        }
        unsigned int k = 0;
        while (k < n) {
            unsigned int j = k + func_003FB8B0_inl1() % (n - k);
            unsigned char t = self->field_D[k];
            unsigned char *b = &self->field_D[j];
            unsigned char u = *b;
            *b = t;
            self->field_D[k] = u;
            k++;
        }
        self->field_40 = func_003FB8B0_inl1() % n;
    }
    if (self->field_CC == 1) {
        int v = p0 - 1;
        if (v < 0) v = self->field_6C - 1;
        self->field_D8 = v;
    } else {
        for (int m = 0; m < self->field_44; m++) {
            if (self->field_D[m] == p0) {
                self->field_40 = m;
            }
        }
    }
}
