// NONMATCHING: GetSignedForwardDistBetweenParams__9CB3AILaneFff -- retail 152 / ours 149 instructions, 45 in changed runs
// a91: logic right (inline param->distance helper x3, unsigned-path float conv, adda/madd lerp); 45 instrs in changed runs, 3 short: register allocation (retail r overwrites a0, n masked into v1 separate from the float-converted raw a1; idx re-masked per use).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3AILane::GetSignedForwardDistBetweenParams(float, float) -- hand-written from the lifter draft.
class CB3AILane;
struct UnkStruct_00147410_e0 {
    float field_0;
    unsigned char pad_4[0x4];
};
struct UnkStruct_00147410_1 {
    unsigned char pad_0[0x4];
    UnkStruct_00147410_e0 *field_4;
    unsigned char pad_8[0x4];
    unsigned short field_C;
    unsigned char field_E;
};
class CB3AILane {
public:
    float GetSignedForwardDistBetweenParams(float p0, float p1);
    unsigned char pad_0[0x4];
    UnkStruct_00147410_1 *field_4;
};
static inline float func_00147410_inl1(UnkStruct_00147410_1 *r, unsigned int n, float p)
{
    unsigned int idx = (int)p & 0xFFFF;
    if ((int)(n & 0xFFFF) < (int)idx) {
        idx = n & 0xFFFF;
    }
    UnkStruct_00147410_e0 *segs = r->field_4;
    float prev;
    int pi = (int)(idx & 0xFFFF) - 1;
    if (pi >= 0) {
        prev = segs[pi].field_0;
    } else {
        prev = 0.0f;
    }
    if ((int)(idx & 0xFFFF) < (int)(n & 0xFFFF)) {
        float cur = segs[idx & 0xFFFF].field_0;
        prev = prev + (p - (float)idx) * (cur - prev);
    }
    return prev;
}
// 0x00147410
float CB3AILane::GetSignedForwardDistBetweenParams(float p0, float p1)
{
    UnkStruct_00147410_1 *r = field_4;
    unsigned int n = r->field_C;
    float nf = (float)n;
    float da = func_00147410_inl1(r, n, p0);
    float db = func_00147410_inl1(r, n, p1);
    float d = da - db;
    if (r->field_E != 0) {
        if (p0 < p1) {
            d = d + func_00147410_inl1(r, n, nf);
        }
    }
    return d;
}
