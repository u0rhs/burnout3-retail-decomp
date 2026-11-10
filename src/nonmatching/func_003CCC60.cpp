// NONMATCHING: func_003CCC60 -- retail 103 / ours 103 instructions, 54 in changed runs
// a132: 103/103 instrs, register-only: retail ia=t1, ib=t0 (arg regs a1/a2 not reused for the index vars), ours ia=t0, ib=a1 and downstream f/addr regs shift. Logic exact: two find loops, p/q ratio madd updates, 4 clamps (second D_004E1278 load via const pun). [L] DNAT CB3CrashScore::HandleCrashBattleDelta
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_CCC60 {
    unsigned char pad_0[0x18];
    void *field_18[0x42];
    int field_120[0x42];
    float field_228[2][0x42];
    unsigned char pad_438[0x77];
    unsigned char field_4AF;
};
extern float D_004E1278;

static inline int func_003CCC60_inl1(UnkStruct_CCC60 *self, void *car)
{
    int j;
    int n = self->field_4AF;
    for (j = 0; j < n; j++) {
        if (self->field_18[j] == car) return j;
    }
    return -1;
}

static inline void func_003CCC60_inl2(float *p)
{
    float x = *p;
    if (x > 0.0f) {
        if (x < D_004E1278) *p = *(const float *)&D_004E1278;
    }
}

extern "C" void func_003CCC60(UnkStruct_CCC60 *self, void *a, void *b, float fa, float fb)
{
    int n = self->field_4AF;
    int ib, ia;
    for (ia = 0; ia < n; ia++) {
        if (self->field_18[ia] == a) goto f1;
    }
    ia = -1;
f1:
    for (ib = 0; ib < n; ib++) {
        if (self->field_18[ib] == b) goto f2;
    }
    ib = -1;
f2:
    float p0 = self->field_228[0][ib];
    float p1 = self->field_228[1][ib];
    float q0 = self->field_228[0][ia];
    float q1 = self->field_228[1][ia];
    float sb = p0 + p1;
    float sa = q0 + q1;
    self->field_228[0][ia] = q0 + fa * (p0 / sb);
    self->field_228[1][ia] = q1 + fa * (p1 / sb);
    self->field_228[0][ib] = p0 + fb * (q0 / sa);
    self->field_228[1][ib] = p1 + fb * (q1 / sa);
    func_003CCC60_inl2(&self->field_228[0][ia]);
    func_003CCC60_inl2(&self->field_228[1][ia]);
    func_003CCC60_inl2(&self->field_228[0][ib]);
    func_003CCC60_inl2(&self->field_228[1][ib]);
}

