// NONMATCHING: FindStageIDFromProgressionIndex__10CB3ProfileFi -- retail 43 / ours 43 instructions, 7 in changed runs
// s321: 43/43, 7 off (was 18): every local declared uninitialised at the top (sreg lall) with loop counters in order i, i1, i2 fixes i/i1/i2/e1. Left: g/n1/e0 rotate (retail g=t0 n1=a3 e0=t5; ours g=t5 n1=t0 e0=a3). Tried all g/n1/e0 decl orders, n1/n2 inline, const g, 210 sreg variants
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct S_e2; struct S_5; struct S_e0; struct S_e1; struct S_1;
struct UnkStruct_D_00518690 { S_1 * field_0; unsigned char pad_4[0xC]; };
struct S_1 { unsigned char pad_0[0x4]; S_e0 * field_4; int field_8; };
struct S_e0 { S_e1 * field_0; int field_4; };
struct S_e1 { unsigned char pad_0[0x10]; S_e2 * field_10; int field_14; };
struct S_e2 { unsigned char pad_0[0x28]; int field_28; unsigned char pad_2C[0x8]; S_5 * field_34; unsigned char pad_38[0x8]; };
struct S_5 { unsigned char pad_0[0x8]; unsigned long long field_8; };
extern UnkStruct_D_00518690 D_00518690;
class CB3Profile { public: unsigned long long FindStageIDFromProgressionIndex(int); };
// 0x0013B770
unsigned long long CB3Profile::FindStageIDFromProgressionIndex(int n0)
{
    S_1 * g;
    int n1;
    S_e0 * e0;
    int n2;
    S_e1 * e1;
    int n3;
    S_e2 * e2;
    int i;
    int i1;
    int i2;
    g = D_00518690.field_0;
    n1 = g->field_8;
    for (i = 0; i < n1; i++) {
        e0 = &g->field_4[i];
        n2 = e0->field_4;
        for (i1 = 0; i1 < n2; i1++) {
            e1 = &e0->field_0[i1];
            n3 = e1->field_14;
            for (i2 = 0; i2 < n3; i2++) {
                e2 = &e1->field_10[i2];
                if (e2->field_28 == n0) {
                    return e2->field_34->field_8;
                }
            }
        }
    }
    return 0;
}

