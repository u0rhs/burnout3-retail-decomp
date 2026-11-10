// NONMATCHING: func_0043C960 -- retail 154 / ours 154 instructions, 18 in changed runs
// near21: 18 changed (was 21). cnt local reused for the field_8 load (retail's t3 reuse). Left: retail materialises the 38.0f lui (v1) early and keeps 40.0 in f1 in block 2; block 2's slot addu is idx-first (addu v0,v0,s3) while block 1 is self-first -- tried (off + (int)self + 0x90), cnt + arr forms: no effect
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


struct UnkStruct_P16 { unsigned char pad_0[0x10]; };
struct UnkStruct_V2 { float x; float y; };
struct UnkStruct_0043C960 {
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[0x6A];
    int field_74;
    int field_78;
    int field_7C[1];
    unsigned char pad_80[0x10];
    int field_90[1];
    unsigned char pad_94[0x30];
    int field_C4;
    int field_C8;
};
extern UnkStruct_P16 D_01E7A800;
extern UnkStruct_P16 D_01E903E0;
extern "C" int func_0043C880(void *, unsigned int);
extern "C" int func_0043C8F0(void *, unsigned int);
extern "C" void func_004589B0(void *, void *, void *, void *, int, int, void *, int, void *);
extern "C" void func_00458900(void *, int);
extern "C" void func_00283F70(void *);
extern "C" void func_00284B20(void *);
extern "C" void func_00284B60(void *);
extern "C" void CrashModeMultiplier__18CB3HUDSoundManagerFv(void *);

extern "C" void func_0043C960(UnkStruct_0043C960 * self, unsigned int a, unsigned int b)
{
    if (a != 0) {
        int s0 = func_0043C880(self, a);
        int t0 = func_0043C8F0(self, a);
        UnkStruct_V2 vc;
        UnkStruct_V2 vb;
        UnkStruct_V2 va;
        int cnt = self->field_C4;
        self->field_C4 = cnt + 1;
        float f = 40.0f * (float)cnt;
        int *slot = &self->field_7C[cnt];
        cnt = self->field_8;
        va.x = 38.0f;
        va.y = 38.0f;
        vb.x = 0.0f;
        vb.y = 0.0f;
        vc.y = 0.0f;
        vc.x = f;
        func_004589B0(slot, &vc, &vb, &va, t0, s0, &D_01E903E0, cnt, (void *)(self->field_74));
        func_00458900(slot, 6);
    }
    if (b != 0) {
        int s0 = func_0043C880(self, a);
        int t0 = func_0043C8F0(self, b);
        UnkStruct_V2 vc;
        UnkStruct_V2 vb;
        UnkStruct_V2 va;
        int cnt = self->field_C8;
        self->field_C8 = cnt + 1;
        float f = (float)(-cnt);
        f = 40.0f * f;
        int *slot = &self->field_90[cnt];
        cnt = self->field_8;
        va.x = 38.0f;
        va.y = 38.0f;
        vb.x = 0.0f;
        vb.y = 0.0f;
        vc.y = 0.0f;
        vc.x = f;
        func_004589B0(slot, &vc, &vb, &va, t0, s0, &D_01E903E0, cnt, (void *)(self->field_78));
        func_00458900(slot, 6);
    }
    func_00283F70(&D_01E7A800);
    switch (a) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        func_00284B20(&D_01E7A800);
        break;
    case 5:
    case 6:
        CrashModeMultiplier__18CB3HUDSoundManagerFv(&D_01E7A800);
        break;
    case 7:
        func_00284B60(&D_01E7A800);
        break;
    }
    switch (b) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        func_00284B20(&D_01E7A800);
        break;
    case 5:
    case 6:
        CrashModeMultiplier__18CB3HUDSoundManagerFv(&D_01E7A800);
        break;
    case 7:
        func_00284B60(&D_01E7A800);
        break;
    }
}
