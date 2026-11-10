// NONMATCHING: func_0044CF90 -- retail 123 / ours 123 instructions, 22 in changed runs
// near32: 22 off, registers only (retail self s0 / off s1 / buf s2 / rest s4; ours self s4 / off s0 / buf s1 / rest s2). mfc1 one-instruction asm as proven func_00288480; if (small) n = range; else compute; switch case 6: case 2: for the 2/6 block order; n > 1. sreg 2 rounds (PLSHVF) no gain
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

static inline int func_0044CF90_max(int a, int b) { int r; asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline int func_0044CF90_min(int a, int b) { int r; asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline unsigned int func_0044CF90_zx(int a) { unsigned int r; asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a)); return r; }
struct UnkStruct_D_16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_16 D_01E7A800;
extern UnkStruct_D_16 D_01E90438;
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_002841F0(void *);
extern "C" void ustrFromInt(void *, int, int, int);
extern "C" void func_003B8840(void *, int);
struct UnkStruct_0044CF90 {
    unsigned char pad_0[0x134];
    int field_134;
    unsigned char pad_138[0x8];
    int field_140[8];
    int field_160[8];
    int field_180[8];
    int field_1A0[8];
};

// 0x0044CF90
extern "C" void func_0044CF90(UnkStruct_0044CF90 *self, int idx, float frac)
{
    int off = idx * 4;
    int hi = (*(int *)((char *)self->field_1A0 + off));
    int range = hi - (*(int *)((char *)self->field_180 + off));
    unsigned int n;
    unsigned int bits;
    asm("mfc1 %0, %1" : "=r"(bits) : "f"(frac));
    if ((bits & 0x7F800000) <= 0x37800000) {
        n = range;
    } else {
        n = func_0044CF90_zx(func_0044CF90_min(func_0044CF90_max((int)((1.0f - frac) * (float)range), 0), range));
    }
    int rest = hi - n;
    int *sp = (int *)((char *)self->field_140 + off);
    if (*sp == 0) *sp = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x20);
    void *buf = (void *)*sp;
    if (!(frac <= 0.0f) && frac < 1.0f && (int)n > 1) {
        func_002841F0(&D_01E7A800);
    }
    if (self->field_134 == 1) {
        if ((int)n <= 0) {
            (*(int *)((char *)self->field_160 + off)) = 0;
        } else {
            int *np = (int *)((char *)self->field_160 + off);
            if (*np == 0) *np = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x20);
            ustrFromInt((void *)*np, n, 1, 1);
        }
    }
    switch (self->field_134) {
    case 6:
    case 2:
        func_003B8840(buf, rest);
        break;
    default:
        ustrFromInt(buf, rest, 1, 0);
        break;
    }
}
