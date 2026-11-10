// NONMATCHING: func_002FB890 -- retail 166 / ours 164 instructions, 155 in changed runs
// a124: 164/166 instrs, 155 changed (schedule/load order). Semantics decoded: biquad over 256 shorts (CB3SoundDSPDataBlock type 2 filter, called from Process): out[n]=clamp((c4C*in[n]+c50*in[n-1]+c54*in[n-2])-(c5C*out[n-1]+c60*out[n-2])), mul=(int)(((long)a*b)>>16) (gives mult/mfhi/pextlw/dsra, mult1 alternation reproduced); first two samples use state shorts 0x68..0x6E and clamp [-0x7FFF,0x8000], loop clamps [-0x8000,0x7FFF] via pmaxw/pminw/pextlw asm helpers; state saved from in[254/255], out[254/255]. Left: retail loads the halfword sample before the coefficient word and keeps different temp regs; 2 instrs short
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

class CB3SoundDSPDataBlock {
public:
    unsigned char pad_0[0x4C];
    int field_4C;
    int field_50;
    int field_54;
    unsigned char pad_58[4];
    int field_5C;
    int field_60;
    unsigned char pad_64[4];
    short field_68;
    short field_6A;
    short field_6C;
    short field_6E;
};

static inline int func_002FB890_max(int a, int b)
{
    int r;
    asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline int func_002FB890_min(int a, int b)
{
    int r;
    asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline unsigned int func_002FB890_zx(int a)
{
    unsigned int r;
    asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a));
    return r;
}
static inline int func_002FB890_mul(int a, int b)
{
    return (int)(((long)b * (long)a) >> 16);
}

extern "C" void func_002FB890(CB3SoundDSPDataBlock * self, short * in, short * out)
{
    int s0 = func_002FB890_mul(self->field_4C, in[0]) + func_002FB890_mul(self->field_50, self->field_6E) + func_002FB890_mul(self->field_54, self->field_6C);
    int s1 = func_002FB890_mul(self->field_5C, self->field_6A) + func_002FB890_mul(self->field_60, self->field_68);
    out[0] = func_002FB890_zx(func_002FB890_min(func_002FB890_max(s0 - s1, -0x7FFF), 0x8000));
    int t0 = func_002FB890_mul(self->field_4C, in[1]) + func_002FB890_mul(self->field_50, in[0]) + func_002FB890_mul(self->field_54, self->field_6E);
    int t1 = func_002FB890_mul(self->field_5C, out[0]) + func_002FB890_mul(self->field_60, self->field_6A);
    out[1] = func_002FB890_zx(func_002FB890_min(func_002FB890_max(t0 - t1, -0x7FFF), 0x8000));
    for (unsigned int i = 2; i < 0x100; i++) {
        int a = func_002FB890_mul(self->field_4C, in[i]) + func_002FB890_mul(self->field_50, in[i - 1]) + func_002FB890_mul(self->field_54, in[i - 2]);
        int b = func_002FB890_mul(self->field_5C, out[i - 1]) + func_002FB890_mul(self->field_60, out[i - 2]);
        out[i] = func_002FB890_zx(func_002FB890_min(func_002FB890_max(a - b, -0x8000), 0x7FFF));
    }
    self->field_6E = in[255];
    self->field_6C = in[254];
    self->field_6A = out[255];
    self->field_68 = out[254];
}
