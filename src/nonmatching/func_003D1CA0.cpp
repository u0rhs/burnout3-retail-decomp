// NONMATCHING: func_003D1CA0 -- retail 150 / ours 150 instructions, 91 in changed runs
// fam1: 150/150 (was 151): float compare in place, k loop + if/else e diamond; left: register colouring only (retail nf=a3 colored before the hoisted constants, pushing r to s1; ours a3=const 4, r=t6). Pragma sweep, comparator/equality inlines, nf local tried
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

enum UnkEnum_003D1CA0 { E0 = 0, E1 = 1, E2 = 2, E3 = 3 };
struct UnkStruct_003D1CA0_row {
    unsigned short field_0[9];
    unsigned char field_12;
    unsigned char field_13;
    signed char field_14;
    unsigned char field_15;
    float field_18;
};
struct UnkStruct_003D1CA0_tbl { UnkStruct_003D1CA0_row field_0[5]; };
static inline UnkEnum_003D1CA0 func_003D1CA0_inl1(float b, float a)
{
    UnkEnum_003D1CA0 r;
    if (b <= a) {
        if (b < a) r = E0; else r = E1;
    } else r = E3;
    return r;
}
static inline bool func_003D1CA0_inl2(UnkStruct_003D1CA0_row *na, UnkStruct_003D1CA0_row *nb)
{
    int k = 0;
    while (na->field_0[k] != 0) {
        if (na->field_0[k] != nb->field_0[k]) return false;
        k++;
    }
    if (na->field_12 != nb->field_12) return false;
    if (na->field_13 != nb->field_13) return false;
    bool e;
    if (na->field_15 == nb->field_15) e = true; else e = false;
    return e;
}
// 0x003D1CA0
extern "C" void func_003D1CA0(UnkStruct_003D1CA0_tbl *a, UnkStruct_003D1CA0_tbl *b, int p0)
{
    for (int i = 0; i < 5; i++) {
        UnkStruct_003D1CA0_row *nb = &b->field_0[i];
        if (nb->field_15 == 0xFF) continue;
        for (int j = 0; j < 5; j++) {
            UnkStruct_003D1CA0_row *na = &a->field_0[j];
            UnkEnum_003D1CA0 r;
            if (nb->field_18 <= na->field_18) {
                if (nb->field_18 < na->field_18) r = E0; else r = E1;
            } else r = E3;
            if (r == E1) {
                int k = 0;
                bool e;
                while (na->field_0[k] != 0) {
                    if (na->field_0[k] != nb->field_0[k]) { e = false; goto done; }
                    k++;
                }
                if (na->field_12 != nb->field_12) e = false;
                else if (na->field_13 != nb->field_13) e = false;
                else if (na->field_15 == nb->field_15) e = true;
                else e = false;
            done:
                if (e) r = E2; else r = E1;
            }
            if (r == E2) break;
            if (r == p0) {
                for (int m = 4; j < m; m--) {
                    a->field_0[m] = a->field_0[m - 1];
                }
                *na = *nb;
                break;
            }
        }
    }
}
