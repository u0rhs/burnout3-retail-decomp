// NONMATCHING: func_00138530 -- retail 522 / ours 514 instructions, 84 in changed runs
// L280: logic complete, 514/522, 84 in changed runs, frame 0x110 vs 0x120. Left: in the prerequisite loop retail jump-threads the id==0 path (copies the 0x10 any/all test with flags CSE'd in a0, 'move s6,s1') -- ours never duplicates it (tried done-before-call, id!=0 first, else-if, inline helpers with/without early returns); then loop-counter registers (k in fp, half-2 i1/i2/j) and retail's sw (not sq) spill of the group pointer. Declaration order idx,rec,i1,i2,e1,e0,g per half at function top is best.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00138530 -- hand-written (L280) from the asm; table walk as in the proven func_003EA0E0.
// [L] DNAT: CB3Profile::EvaluateChallengeUnlocking() (research/proto/new_names.csv, medium) -- placeholder kept.
// Unnamed in the retail tables, so a placeholder with C linkage; Area unknown, so _unclassified/.
// Structs are declared with only the fields touched; every type is [G] (instruction widths).
// Two halves (race challenges -> D_0051BFA0.field_57 / profile field_386, crash stages -> field_A0 / field_3CF): unlock
// flags 0x400/0x800/0x1000 (state 3), 0 (always), 1 (previous done), 2 (field_40 >= threshold), 8 (prerequisite list
// field_24[4] via FindStageIDFromProgressionIndex, 0x10 = any / else all, 4 = gold), 0x20 (all earlier records).

struct UnkStruct_00138530_1;
struct UnkStruct_00138530_5;
struct UnkStruct_00138530_e0;
struct UnkStruct_00138530_e1;
struct UnkStruct_00138530_e2;

struct UnkStruct_D_00518690 {
    UnkStruct_00138530_1 *field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_00138530_1 {
    unsigned char pad_0[0x4];
    UnkStruct_00138530_e0 *field_4;
    int field_8;
};
struct UnkStruct_00138530_e0 {
    UnkStruct_00138530_e1 *field_0;
    int field_4;
};
struct UnkStruct_00138530_e1 {
    unsigned char pad_0[0x10];
    UnkStruct_00138530_e2 *field_10;
    int field_14;
};
struct UnkStruct_00138530_e2 {
    unsigned char pad_0[0x1C];
    unsigned int field_1C;
    unsigned int field_20;
    unsigned char field_24[4];
    unsigned char pad_28[0xC];
    UnkStruct_00138530_5 *field_34;
    unsigned char pad_38[0x8];
};
struct UnkStruct_00138530_5 {
    unsigned char pad_0[0x8];
    unsigned long field_8;
};
struct UnkStruct_D_0051BFA0 {
    unsigned char pad_0[0x57];
    unsigned char field_57[0x49];
    unsigned char field_A0[0x64];
};
struct UnkStruct_gCalculatedData {
    unsigned char pad_0[0x30];
    int field_30;
    int field_34;
    unsigned char pad_38[0x8];
};
class CB3Profile {
public:
    unsigned char pad_0[0x40];
    unsigned int field_40;
    unsigned char pad_44[0x341];
    signed char field_385[1];
    signed char field_386[0x48];
    signed char field_3CE[1];
    signed char field_3CF[0x64];
};

extern UnkStruct_D_00518690 D_00518690;
extern UnkStruct_D_0051BFA0 D_0051BFA0;
extern UnkStruct_gCalculatedData gCalculatedData;

extern "C" int FindChallengeIndex__25CB3HardCodedRaceStageListFUl(unsigned long);
extern "C" int FindCrashStage__26CB3HardCodedCrashStageListFUl(unsigned long);
extern "C" unsigned long FindStageIDFromProgressionIndex__10CB3ProfileFi(CB3Profile *, int);

// 0x00138530
extern "C" void func_00138530(CB3Profile *self)
{
    int i;
    int idxA;
    UnkStruct_00138530_e2 *recA;
    int i1A;
    int i2A;
    UnkStruct_00138530_e1 *e1A;
    UnkStruct_00138530_e0 *e0A;
    int g;
    int idxB;
    UnkStruct_00138530_e2 *recB;
    int i2B;
    int i1B;
    UnkStruct_00138530_e1 *e1B;
    UnkStruct_00138530_e0 *e0B;
    int g2;
    for (i = 0; i < 0x49; i++) {
        D_0051BFA0.field_57[i] = 0;
    }
    for (i = 0; i < 0x64; i++) {
        D_0051BFA0.field_A0[i] = 0;
    }
    gCalculatedData.field_30 = 0;
    gCalculatedData.field_34 = 0;
    for (g = 0; g < D_00518690.field_0->field_8; g++) {
        e0A = &D_00518690.field_0->field_4[g];
        for (i1A = 0; i1A < e0A->field_4; i1A++) {
            e1A = &e0A->field_0[i1A];
            for (i2A = 0; i2A < e1A->field_14; i2A++) {
                recA = &e1A->field_10[i2A];
                idxA = FindChallengeIndex__25CB3HardCodedRaceStageListFUl(recA->field_34->field_8);
                if (idxA != -1) {
                    if ((recA->field_1C & 0x400) || (recA->field_1C & 0x800) || (recA->field_1C & 0x1000)) {
                        self->field_386[idxA] = 3;
                    }
                    if (recA->field_1C == 0) {
                        D_0051BFA0.field_57[idxA] = 1;
                    }
                    if (recA->field_1C & 1) {
                        if (idxA == 0) {
                            D_0051BFA0.field_57[idxA] = 1;
                        } else if (self->field_385[idxA] > 0) {
                            D_0051BFA0.field_57[idxA] = 1;
                        }
                    }
                    if ((recA->field_1C & 2) && !(self->field_40 < recA->field_20)) {
                        D_0051BFA0.field_57[idxA] = 1;
                    }
                    if (recA->field_1C & 8) {
                        bool v = true;
                        if (recA->field_1C & 0x10) v = false;
                        int k;
                        for (k = 0; k < 4; k++) {
                            if (recA->field_24[k] != 0xFF) {
                                bool done = false;
                                unsigned long id = FindStageIDFromProgressionIndex__10CB3ProfileFi(self, recA->field_24[k]);
                                if (id == 0) {
                                    done = true;
                                } else {
                                    int st = 0;
                                    int c = FindChallengeIndex__25CB3HardCodedRaceStageListFUl(id);
                                    if (c != -1) {
                                        st = self->field_386[c];
                                    } else {
                                        c = FindCrashStage__26CB3HardCodedCrashStageListFUl(id);
                                        if (c != -1) st = self->field_3CF[c];
                                    }
                                    if (recA->field_1C & 4) {
                                        if (st == 3) done = true;
                                    } else {
                                        if (st > 0) done = true;
                                    }
                                }
                                if (recA->field_1C & 0x10) {
                                    if (done) {
                                        v = true;
                                        break;
                                    }
                                } else {
                                    if (!done) {
                                        v = false;
                                        break;
                                    }
                                }
                            }
                        }
                        D_0051BFA0.field_57[idxA] = v;
                    }
                    if (recA->field_1C & 0x20) {
                        bool v = true;
                        int j;
                        for (j = 0; j < i2A; j++) {
                            int c = FindChallengeIndex__25CB3HardCodedRaceStageListFUl(e1A->field_10[j].field_34->field_8);
                            if (c != -1) {
                                int st = self->field_386[c];
                                if (recA->field_1C & 4) {
                                    if (st != 3) {
                                        v = false;
                                        break;
                                    }
                                } else {
                                    if (st > 0) {
                                        v = false;
                                        break;
                                    }
                                }
                            }
                        }
                        D_0051BFA0.field_57[idxA] = v;
                    }
                    if (D_0051BFA0.field_57[idxA] != 0) {
                        gCalculatedData.field_30++;
                    }
                }
            }
        }
    }
    for (g2 = 0; g2 < D_00518690.field_0->field_8; g2++) {
        e0B = &D_00518690.field_0->field_4[g2];
        for (i1B = 0; i1B < e0B->field_4; i1B++) {
            e1B = &e0B->field_0[i1B];
            for (i2B = 0; i2B < e1B->field_14; i2B++) {
                recB = &e1B->field_10[i2B];
                idxB = FindCrashStage__26CB3HardCodedCrashStageListFUl(recB->field_34->field_8);
                if (idxB != -1) {
                    if ((recB->field_1C & 0x400) || (recB->field_1C & 0x800) || (recB->field_1C & 0x1000)) {
                        self->field_3CF[idxB] = 3;
                    }
                    if (recB->field_1C == 0) {
                        D_0051BFA0.field_A0[idxB] = 1;
                    }
                    if (recB->field_1C & 1) {
                        if (idxB == 0) {
                            D_0051BFA0.field_A0[idxB] = 1;
                        } else if (self->field_3CE[idxB] > 0 && D_0051BFA0.field_A0[idxB - 1] != 0) {
                            D_0051BFA0.field_A0[idxB] = 1;
                        }
                    }
                    if ((recB->field_1C & 2) && !(self->field_40 < recB->field_20)) {
                        D_0051BFA0.field_A0[idxB] = 1;
                    }
                    if (recB->field_1C & 8) {
                        bool v = true;
                        if (recB->field_1C & 0x10) v = false;
                        int k;
                        for (k = 0; k < 4; k++) {
                            if (recB->field_24[k] != 0xFF) {
                                bool done = false;
                                unsigned long id = FindStageIDFromProgressionIndex__10CB3ProfileFi(self, recB->field_24[k]);
                                if (id == 0) {
                                    done = true;
                                } else {
                                    int st = 0;
                                    int c = FindChallengeIndex__25CB3HardCodedRaceStageListFUl(id);
                                    if (c != -1) {
                                        st = self->field_386[c];
                                    } else {
                                        c = FindCrashStage__26CB3HardCodedCrashStageListFUl(id);
                                        if (c != -1) st = self->field_3CF[c];
                                    }
                                    if (recB->field_1C & 4) {
                                        if (st == 3) done = true;
                                    } else {
                                        if (st > 0) done = true;
                                    }
                                }
                                if (recB->field_1C & 0x10) {
                                    if (done) {
                                        v = true;
                                        break;
                                    }
                                } else {
                                    if (!done) {
                                        v = false;
                                        break;
                                    }
                                }
                            }
                        }
                        D_0051BFA0.field_A0[idxB] = v;
                    }
                    if (recB->field_1C & 0x20) {
                        bool v = true;
                        int j;
                        for (j = 0; j < i2B; j++) {
                            int c = FindCrashStage__26CB3HardCodedCrashStageListFUl(e1B->field_10[j].field_34->field_8);
                            if (c != -1) {
                                int st = self->field_3CF[c];
                                if (recB->field_1C & 4) {
                                    if (st != 3) {
                                        v = false;
                                        break;
                                    }
                                } else {
                                    if (st > 0) {
                                        v = false;
                                        break;
                                    }
                                }
                            }
                        }
                        D_0051BFA0.field_A0[idxB] = v;
                    }
                    if (D_0051BFA0.field_A0[idxB] != 0) {
                        gCalculatedData.field_34++;
                    }
                }
            }
        }
    }
}
