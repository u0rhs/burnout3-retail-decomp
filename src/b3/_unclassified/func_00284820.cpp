// Hand-written; the lifter refused it (a73: separate early-return error ifs, then v < field_60 (slt v1); PlayHudSound with 7th phantom-float arg like siblings).

// [L] DNAT: no row for 0x284820; a CB3HUDSoundManager method [G] (calls PlayHudSound on its own this; fields 0x60/0x78).
struct CGtSoundBank;
struct UnkStruct_D_004E0AAC { float field_0; unsigned char pad_4[0xC]; };
extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);
struct UnkStruct_00284820 {
    unsigned char pad_0[0x60];
    int field_60;
    unsigned char pad_64[0x14];
    int field_78;
};

// 0x00284820
extern "C" void func_00284820(UnkStruct_00284820 * self, float p0, float p1)
{
    int v = (int)p1;
    if (v < 0) {
        self->field_60 = 999;
        return;
    }
    if (v >= 5) {
        self->field_60 = 999;
        return;
    }
    if (v < self->field_60) {
        PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, 0xBD69B91E81C00000, (const CGtSoundBank *)self->field_78, 0.75f, 1.0f, 0, 0.0f);
        self->field_60 = v;
    }
}
