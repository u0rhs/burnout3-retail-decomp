// NONMATCHING: func_004407B0 -- retail 156 / ours 156 instructions, 182 in changed runs
// sdra: const pointee on a read-only param [G] (const loads are not ordered after stores, sdra rule 1)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_004407B0 -- retail 156 / ours 161 instructions, 187 in changed runs
// a135: draft only, layout far off (retail: shared out-of-line tails L9E0/L9E4 (state!=4 -> SetFinished 5/4 via two b-stubs), L9F8/L9FC/LA00 for the float table, loops use leftover consts a2=4 / v1=3 (li v0,3; beqz v0), case order 6,4,3,1,0 tested in that order). Logic: mode switch on D_01E901DC[D_0051B938]->14; cases 3/4 are inlined find-slot loops over a 3-entry int/float table; skipped after one round
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

enum EB3MenuFlowFSMEvents {};
enum EB3ScoreFinishState {};
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_Mode { unsigned char pad_0[0x14]; int field_14; };
struct UnkStruct_Mode_t { UnkStruct_Mode *field_0[1]; };
struct UnkStruct_Car {
    unsigned char pad_0[0x10CC];
    float field_10CC;
    unsigned char pad_10D0[0x2C];
    float field_10FC;
    unsigned char pad_1100[0xC];
    int field_110C;
    unsigned char pad_1110[0x18];
    int field_1128;
    unsigned char pad_112C[4];
    int field_1130;
    int field_1134;
    unsigned char pad_1138[4];
    float *field_113C;
    int *field_1140;
    unsigned char pad_1144[0x57C];
    short field_16C0;
};
struct UnkStruct_004407B0 {
    unsigned char pad_0[0x1C];
    int field_1C;
    unsigned char pad_20[0x14];
    int field_34;
    unsigned char pad_38[0x14];
    int field_4C;
    unsigned char pad_50[0x14];
    int field_64;
    unsigned char pad_68[0x14];
    float field_7C;
};
extern UnkStruct_I D_0051B938;
extern UnkStruct_Mode_t D_01E901DC;
extern UnkStruct_Car D_0064D3B0;
extern UnkStruct_I D_0064CE48;
extern UnkStruct_P16 D_01E90240;
extern "C" void SetFinished__10CB3RaceCarF19EB3ScoreFinishState(void *, EB3ScoreFinishState);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);

extern "C" void func_004407B0(const UnkStruct_004407B0 * self)
{
    UnkStruct_Car * const g = &D_0064D3B0;
    switch (D_01E901DC.field_0[D_0051B938.field_0]->field_14) {
    case 6:
        D_0064CE48.field_0 = self->field_4C;
        SetFinished__10CB3RaceCarF19EB3ScoreFinishState(g, (EB3ScoreFinishState)6);
        break;
    case 4: {
        g->field_110C = self->field_34;
        float *tbl = g->field_113C;
        g->field_10FC = self->field_7C;
        g->field_10CC = self->field_7C;
        if (tbl != 0) {
            for (int i = 2; i >= 0; i--) {
                if (g->field_10FC <= tbl[i]) {
                    if (g->field_1130 < i || g->field_1130 == 4) {
                        g->field_1130 = i;
                        break;
                    }
                }
            }
        }
        SetFinished__10CB3RaceCarF19EB3ScoreFinishState(g, (EB3ScoreFinishState)1);
        break;
    }
    case 3: {
        g->field_110C = self->field_34;
        int *tbl = g->field_1140;
        g->field_1128 = self->field_64;
        int v = self->field_64;
        g->field_1128 = v;
        if (tbl != 0) {
            for (int i = 2; i >= 0; i--) {
                if (v >= tbl[i]) {
                    if (g->field_1134 < i || g->field_1134 == 4) {
                        g->field_1134 = i;
                        break;
                    }
                }
            }
        }
        if (g->field_1134 != 4) {
            SetFinished__10CB3RaceCarF19EB3ScoreFinishState(g, (EB3ScoreFinishState)5);
        } else {
            SetFinished__10CB3RaceCarF19EB3ScoreFinishState(g, (EB3ScoreFinishState)4);
        }
        break;
    }
    case 1:
        g->field_10FC = self->field_7C;
        g->field_110C = self->field_34;
        g->field_1128 = self->field_64;
        if (self->field_1C == 1) {
            SetFinished__10CB3RaceCarF19EB3ScoreFinishState(g, (EB3ScoreFinishState)5);
        } else {
            SetFinished__10CB3RaceCarF19EB3ScoreFinishState(g, (EB3ScoreFinishState)2);
        }
        g->field_16C0 = self->field_1C;
        break;
    case 0:
        g->field_10FC = self->field_7C;
        g->field_110C = self->field_34;
        g->field_1128 = self->field_64;
        SetFinished__10CB3RaceCarF19EB3ScoreFinishState(g, (EB3ScoreFinishState)1);
        g->field_16C0 = self->field_1C;
        break;
    default:
        return;
    }
    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
}
