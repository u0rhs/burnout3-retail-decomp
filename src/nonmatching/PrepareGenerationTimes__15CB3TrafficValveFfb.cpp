// NONMATCHING: PrepareGenerationTimes__15CB3TrafficValveFfb -- retail 133 / ours 133 instructions, 51 in changed runs
// near38: j and i declared at the function top (j assigned from one per pass, i = 0 in the for), sreg declaration order (j, i, then ra, z, one, rb): 59 -> 51. Left: retail keeps ra/rb in a3/a2 and the per-row bases this+i*4 / this+i*28 in t1/t0 with j*4 in v1; ours gives the row bases a3/v1 and ra/rb t-registers; removing the ra/rb locals (globals in the inline) costs 17 instrs
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// structure right (single loop nest, RNG via ra/rb pointers, adda/madd); 139 vs 133 instrs: address hoists (retail a3/a2 pointer bases, i/j regs) and extra add.s differ
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

struct UnkStruct_D_0055D7F7 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_0055D788 { int field_0; unsigned char pad[0xC]; };
struct UnkStruct_D_0055D78C { int field_0; unsigned char pad[0xC]; };
struct UnkStruct_268270_cnt { unsigned char pad_0[0x8]; int field_8; };
struct UnkStruct_268270_row { unsigned char pad_0[0x10]; float field_10[1]; unsigned char pad_14[0x8]; };
class CB3TrafficValve {
public:
    void PrepareGenerationTimes(float p0, bool p1);
    unsigned char pad_0[0x10];
    float *field_10[1];
    unsigned char pad_14[0x2C];
    UnkStruct_268270_cnt *field_40;
    unsigned char pad_44[0x48];
    UnkStruct_268270_row field_8C[1];
    unsigned char pad_A8[0x6C];
    unsigned char field_114;
};
extern UnkStruct_D_0055D7F7 D_0055D7F7;
extern UnkStruct_D_0055D788 D_0055D788;
extern UnkStruct_D_0055D78C D_0055D78C;
static inline unsigned int func_00268270_inl1(int *ra, int *rb)
{
    int a = *ra;
    int b = *rb;
    unsigned int r = (a << 16) + (a >> 16);
    r += b;
    *ra = r;
    *rb = b + r;
    return r;
}
static inline float func_00268270_inl2(int *ra, int *rb, float p0, CB3TrafficValve *v, int i, int j)
{
    float rr = ((2.3283064e-10f * (float)func_00268270_inl1(ra, rb)) - 0.5f) * 2.0f;
    float t = 60.0f / v->field_10[i][j];
    return (p0 + t) + rr * (0.3f * t);
}
// N182: `#pragma opt_propagation off` [G] scoped to this function (N236: pragmas are per-function).
#pragma push
#pragma opt_propagation off
// 0x00268270
void CB3TrafficValve::PrepareGenerationTimes(float p0, bool p1)
{
    int j;
    int i;
    if (field_114 == 0 && D_0055D7F7.field_0 != 0) return;
    float z = 0.0f;
    int one = 1;
    int * const ra = &D_0055D788.field_0;
    int * const rb = &D_0055D78C.field_0;
    for (i = 0; i < field_40->field_8; i++) {
        j = one;
        do {
            if (field_10[i][j] <= z) continue;
            if (j >= 6) {
                field_8C[i].field_10[j] = p0;
            } else if (p1) {
                float &g = field_8C[i].field_10[j];
                if (g <= p0) {
                    g = func_00268270_inl2(ra, rb, p0, this, i, j);
                }
            } else {
                field_8C[i].field_10[j] = func_00268270_inl2(ra, rb, p0, this, i, j);
            }
        } while (++j < 7);
    }
}
#pragma pop




