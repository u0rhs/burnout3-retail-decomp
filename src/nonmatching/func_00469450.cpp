// NONMATCHING: func_00469450 -- retail 59 / ours 59 instructions, 17 in changed runs
// near25: static inline find helpers (goto loop, short i) + r join: left: loop var in a2/a1 vs retail a3 (retail's i+1 reads the stored short, ours the extended copy; the for-form fixes that but loses the tail), 2nd tail's -1 block order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_00469450_g {
    unsigned char pad_0[0x10];
    short field_10;
};
struct UnkStruct_D_004E2FC8_a { UnkStruct_00469450_g * field_0; };
extern UnkStruct_D_004E2FC8_a D_004E2FC8;

static inline int func_00469450_inl1(unsigned short mask, short i)
{
    goto t;
b:
    if ((1 << i) & mask) goto d;
    i = i + 1;
t:
    if (i <= 7) goto b;
d:
    if (i > 7) return -1; return i;
}
static inline int func_00469450_inl2(unsigned short mask, short i)
{
    goto t;
b:
    if ((1 << i) & mask) goto d;
    i = i - 1;
t:
    if (i >= 0) goto b;
d:
    return i >= 0 ? i : -1;
}

extern "C" int func_00469450(unsigned short mask, int dir)
{
    int r;
    int cur = D_004E2FC8.field_0->field_10;
    if (dir == 0) r = func_00469450_inl1(mask, cur + 1);
    else if (dir == 1) r = func_00469450_inl2(mask, cur - 1);
    else return -1;
    return r;
}
