// NONMATCHING: GenerateInitialTraffic__16CB3TrafficSystemFP18CB3StartFinishLinei -- retail 235 / ours 235 instructions, 42 in changed runs
// near33: 50->42, 235=235. Scoped opt_repositioncode off [G] + goto-form k chain (k==1 inline, k0/k2 blocks after the loop, k/x/y at function scope) gives retail's layout. Left: (1) find-loop 'continue' increment block retail keeps at the end (goto form finc: a++ at the end: 39 changed but 236 instrs, near33_t5.txt n33t20); (2) retail does not hoist b9=this+0x363A9 out of the c loop (no loop guard) nor b9+c out of the j loop -- only out of the while (guard + fp=s7+c). Scoped opt_loop_invariants off + explicit 'if (*cnt>0) { q = b9 + c; while ... }' reproduces that shape (near33_t7.txt n33t31) but flips addu operand order (s2,s5) and j/cnt s0/s1; (3) find-loop temps a0/a1/a2 rotated
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: GenerateInitialTraffic__16CB3TrafficSystemFP18CB3StartFinishLinei -- retail 235 / ours 236 instructions, 49 in changed runs
// 236 vs 235 instrs; logic/layout right. Left: retail saves fp+s7 (frame 0xB0): s0=&field_363A9[c] (this+c then +0x363A9) AND fp=s7+c with s7=this+0x363A9 computed inside the outer loop after the k-chain (ours hoists it to loop entry, frame 0x90); k==0/k!=1/k==1 chain beq vs bne polarity; a1/a2 naming for field_0 reload
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

struct UnkStruct_00165A40_ent {
    void * field_0;
    int field_4;
    int field_8;
    unsigned char pad_C[0x4];
    unsigned char * field_10;
    unsigned char field_14;
    unsigned char field_15;
    unsigned char pad_16[0x2];
};

struct UnkStruct_00165A40_dat {
    unsigned char pad_0[0xA4];
    UnkStruct_00165A40_ent * field_A4;
    int field_A8;
};

struct UnkStruct_00165A40_car {
    unsigned char pad_0[0x1910];
    // vptr at +0x1910: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual int vfunc_20();
};

struct UnkStruct_D_00522660 { unsigned char pad_0[0x27D0]; };
struct UnkStruct_D_0064D3A0 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0064D3A0 D_0064D3A0;

extern "C" void RolloutCrashTraffic__15CB3TrafficValveFv(void *);
extern "C" void GenerateInitialTraffic__15CB3TrafficValveFP18CB3StartFinishLinei(void *, void *, int);
extern "C" void PrepareGenerationTimes__15CB3TrafficValveFfb(void *, float, bool);
extern "C" void DoFiller__16CB3TrafficSystemFP22CB3TrafficFillerStructP18CB3StartFinishLineii(void *, void *, void *, int, int);

struct UnkStruct_00165A40 {
    UnkStruct_00165A40_dat * field_0;
    unsigned char pad_4[0x363A7 - 4];
    unsigned char field_363A7[2];
    unsigned char field_363A9[2];
    unsigned char pad_363AB[2];
    unsigned char field_363AD;
    unsigned char pad_363AE[0x9];
    unsigned char field_363B7;
    unsigned char field_363B8;
    unsigned char pad_363B9[0x2];
    unsigned char field_363BB;
};

#pragma push
#pragma opt_repositioncode off  // [G] N182 scoped: retail lays the k==0 / k>1 blocks after the loops
// 0x00165A40
extern "C" void GenerateInitialTraffic__16CB3TrafficSystemFP18CB3StartFinishLinei(UnkStruct_00165A40 * self, void * p0, int p1)
{
    UnkStruct_00165A40_ent * es[3];
    unsigned char k;
    unsigned char x;
    unsigned char y;
    if (self->field_363BB == 0) {
        return;
    }
    if (self->field_363B8 != 0) {
        for (int i = 0; i < self->field_363AD; i++) {
            RolloutCrashTraffic__15CB3TrafficValveFv((char *)self + i * 0x118 + 4);
        }
        return;
    }
    if (self->field_363B7 != 0) {
        for (int i = 0; i < self->field_363AD; i++) {
            GenerateInitialTraffic__15CB3TrafficValveFP18CB3StartFinishLinei((char *)self + i * 0x118 + 4, p0, p1);
        }
        return;
    }
    for (int c = 0; c < D_0064D3A0.field_0; c++) {
        int r = ((UnkStruct_00165A40_car *)((char *)&D_00522660 + c * 0x27D0 + 0x12AD50))->vfunc_20();
        UnkStruct_00165A40_dat * d = self->field_0;
        int n = d->field_A8;
        for (int a = 0; a < n; a++) {
            es[0] = &d->field_A4[a];
            if (r > es[0]->field_8) {
                continue;
            }
            if (r < es[0]->field_4) {
                continue;
            }
            self->field_363A7[c] = a;
            break;
        }
        for (unsigned char v = 0; v < es[0]->field_15; v = v + 1) {
            PrepareGenerationTimes__15CB3TrafficValveFfb((char *)self + es[0]->field_10[v] * 0x118 + 4, 0.0f, false);
        }
        k = self->field_363A7[c];
        if (k == 0) goto k0;
        if (k != 1) goto k2;
        x = k - 1;
        y = self->field_0->field_A8 - 1;
    join:
        es[1] = &self->field_0->field_A4[x];
        es[2] = &self->field_0->field_A4[y];
        unsigned char * b9 = self->field_363A9;
        for (int j = 0; j < 3; j++) {
            UnkStruct_00165A40_ent ** p = &es[j];
            unsigned char * cnt = &self->field_363A9[c];
            *cnt = (*p)->field_14;
            while (*cnt > 0) {
                DoFiller__16CB3TrafficSystemFP22CB3TrafficFillerStructP18CB3StartFinishLineii(self, (char *)(*p)->field_0 + (b9[c] - 1) * 6, p0, p1, c);
                *cnt = *cnt - 1;
            }
        }
    }
    return;
k0:
    x = self->field_0->field_A8 - 1;
    y = self->field_0->field_A8 - 2;
    goto join;
k2:
    x = k - 1;
    y = k - 2;
    goto join;
}
#pragma pop
