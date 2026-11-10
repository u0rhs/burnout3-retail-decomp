// NONMATCHING: func_003D17D0 -- retail 179 / ours 179 instructions, 111 in changed runs
// 179/179 instrs, layout exact, only register numbering differs (retail uses a3 scratch, consts t4,t1,t3,t2,t0; ours t3,t0,t2,t1,a3)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

enum UnkEnum_003D17D0 { E0 = 0, E1 = 1, E2 = 2, E3 = 3 };
struct UnkStruct_003D17D0_row {
    unsigned short field_0[9];
    unsigned char field_12;
    unsigned char field_13;
    signed char field_14;
    unsigned char field_15;
    float field_18;
    unsigned short field_1C[9];
    unsigned char field_2E;
    unsigned char field_2F;
};
struct UnkStruct_003D17D0_tbl { UnkStruct_003D17D0_row field_0[5]; };

static inline UnkEnum_003D17D0 func_003D17D0_inl1(int a, int b)
{
    UnkEnum_003D17D0 r;
    if (b > a) r = E3;
    else if (a > b) r = E0;
    else r = E1;
    return r;
}
extern "C" void func_003D17D0(UnkStruct_003D17D0_tbl *a, UnkStruct_003D17D0_tbl *b, int p0)
{
    for (int i = 0; i < 5; i++) {
        UnkStruct_003D17D0_row *nb = &b->field_0[i];
        if (nb->field_15 == 0xFF) continue;
        for (int j = 0; j < 5; j++) {
            UnkStruct_003D17D0_row *na = &a->field_0[j];
            UnkEnum_003D17D0 r;
            r = func_003D17D0_inl1(*(int *)&na->field_18, *(int *)&nb->field_18);
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
                if (e == false) r = E1; else r = E2;
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
