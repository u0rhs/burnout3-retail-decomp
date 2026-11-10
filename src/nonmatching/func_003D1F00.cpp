// NONMATCHING: func_003D1F00 -- retail 150 / ours 150 instructions, 92 in changed runs
// near38: header was stale (now 150/150); field_15 test as != (retail beq to the true block). Left: register colouring only -- retail leaves t8 unused in the j loop and spills r/fa/fb to s1/s2 (nf in a3 ahead of the 7 hoisted constants); comparator/equality inlines (sibling func_003D1AA0 shape), nf local on/off, sreg (on the 1CA0 twin) all inert
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// a231: nf cached (retail reuses a3), bool e tested plainly; logic equal, only constant/pointer register numbering differs (t4/t1/t3/t2/t0 order)


enum UnkEnum_003D1F00 { E0 = 0, E1 = 1, E2 = 2, E3 = 3 };
struct UnkStruct_003D1F00_row {
    unsigned short field_0[9];
    unsigned char field_12;
    unsigned char field_13;
    signed char field_14;
    unsigned char field_15;
    float field_18;
};
struct UnkStruct_003D1F00_tbl { UnkStruct_003D1F00_row field_0[5]; };
extern "C" void func_003D1F00(UnkStruct_003D1F00_tbl *a, UnkStruct_003D1F00_tbl *b, int p0)
{
    for (int i = 0; i < 5; i++) {
        UnkStruct_003D1F00_row *nb = &b->field_0[i];
        unsigned char nf = nb->field_15;
        if (nf == 0xFF) continue;
        for (int j = 0; j < 5; j++) {
            UnkStruct_003D1F00_row *na = &a->field_0[j];
            UnkEnum_003D1F00 r;
            int fb = *(int *)&nb->field_18, fa = *(int *)&na->field_18;
            if (fb > fa) r = E3;
            else if (fa > fb) r = E0;
            else r = E1;
            if (r == E1) {
                int k = 0;
                bool e;
                while (na->field_0[k] != 0) {
                    if (na->field_0[k] != nb->field_0[k]) { e = false; goto done; }
                    k++;
                }
                if (na->field_12 != nb->field_12) e = false;
                else if (na->field_13 != nb->field_13) e = false;
                else if (na->field_15 != nf) e = false;
                else e = true;
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

