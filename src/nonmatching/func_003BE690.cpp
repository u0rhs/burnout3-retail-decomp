// NONMATCHING: func_003BE690 -- retail 111 / ours 112 instructions, 21 in changed runs
// near29: element pointers ps=&score[i], pc=&cars[i] in loop 1 (retail's addiu 72/80 pointers), cars[i] read once into a top-declared cc in loops 2/3 (retail lw a0,0x50(v1)) -> 21. Left: loop-1 hoisted registers (retail lbu limit a0, base t3; ours t1/a0), the *pc = c store scheduled before the field_1128 load (retail: in the top-test beqz delay slot), daddiu vs li for the 1
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_003BE690 -- retail 111 / ours 111 instructions, 40 in changed runs
// a224: dead score[2] store kept by '#pragma opt_dead_assignments off' (N182, [G] scoped) instead of volatile; goto-form entry-jump loops give 111/111. Left 40: register assignment of hoisted values (retail a0=limit v1=0x27D0 t3=base a1=i; ours a1/a0/v1/a2) and cars[i] read folded as lw 0x50(v1) in retail vs addiu+lw
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

enum EB3ScoreFinishState {};
struct UnkStruct_003BE690_car {
    unsigned char pad_0[0x10C8];
    int field_10C8;
    unsigned char pad_10CC[0x60];
    int field_112C_dummy;
};
struct UnkStruct_003BE690_car2 {
    unsigned char pad_0[0x1128 - 0x0];
    int field_1128;
};
struct UnkStruct_D_00522660 { unsigned char pad_0[0x12AD50]; };
struct UnkStruct_003BE690_c {
    unsigned char pad_0[0x10C8];
    int field_10C8;
    unsigned char pad_10CC[0x5C];
    int field_1128;
    unsigned char pad_112C[0x58C];
    int field_16B8;
};
struct UnkStruct_D_01E90220 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_0064D3A0 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_01E90220 D_01E90220;
extern UnkStruct_D_0064D3A0 D_0064D3A0;
struct UnkStruct_0038CBB0;
extern "C" void func_0038CBB0(UnkStruct_0038CBB0 *);
extern "C" void SetFinished__10CB3RaceCarF19EB3ScoreFinishState(void *, EB3ScoreFinishState);

#pragma push
#pragma opt_dead_assignments off
// 0x003BE690
// pass1: a0 reaches func_0038CBB0 untouched (retail live-in)
extern "C" void func_003BE690(UnkStruct_0038CBB0 *self)
{
    bool top[2];
    bool fin[2];
    UnkStruct_003BE690_c * cars[2];
    int score[2];
    int unused[2];
    int s2 = 0;
    int s1 = 0;
    int s0 = 0;
    int i;
    UnkStruct_003BE690_c * cc;
    func_0038CBB0(self);
    char * const base = (char *)&D_00522660;
    i = 0;
    goto t0;
b0:
    {
        UnkStruct_003BE690_c * c = (UnkStruct_003BE690_c *)(base + i * 0x27D0 + 0x12AD50);
        int *ps = &score[i];
        UnkStruct_003BE690_c **pc = &cars[i];
        *ps = c->field_1128;
        top[i] = !(*ps < D_01E90220.field_0);
        *pc = c;
        if (top[i]) s2 = 1;
        fin[i] = c->field_16B8 == 0;
        if (fin[i]) {
            s0 = 1;
            s1++;
        }
    }
    i++;
t0:
    if (i < 2) goto b0;
    if (s0) {
        i = 0;
        goto t1;
    b1:
        if (!fin[i] && (cc = cars[i])->field_10C8 == 0 && s1 == D_0064D3A0.field_0 - 1) {
            SetFinished__10CB3RaceCarF19EB3ScoreFinishState(cc, (EB3ScoreFinishState)5);
        }
        i++;
    t1:
        if (i < 2) goto b1;
    } else if (s2) {
        i = 0;
        goto t2;
    b2:
        cc = cars[i];
        if (cc->field_10C8 == 0) {
            if (top[i]) {
                SetFinished__10CB3RaceCarF19EB3ScoreFinishState(cc, (EB3ScoreFinishState)5);
            } else {
                SetFinished__10CB3RaceCarF19EB3ScoreFinishState(cc, (EB3ScoreFinishState)4);
            }
        }
        i++;
    t2:
        if (i < 2) goto b2;
    }
}
#pragma pop



