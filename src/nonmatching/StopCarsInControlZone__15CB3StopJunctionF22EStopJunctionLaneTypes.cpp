// NONMATCHING: StopCarsInControlZone__15CB3StopJunctionF22EStopJunctionLaneTypes -- retail 271 / ours 270 instructions, 59 in changed runs
// a142: logic complete 270/271 instrs, 59 differ. Needed the a123 double-0xFF test (inl3 = 'if n==0xFF return 0; return inl1(n)') for every next-lookup and gotos null1/null2/null3/lanepath placed after the loop for retail's out-of-line 'b join; move s4,zero' blocks. Left: s2/s3 (slot ptr vs hi) swap in the prologue, the 'q->field_46==2 {46=1; 10=-1.0}' then-block lands out-of-line in ours (retail inline, 2 sites), loop-exit 'bnez s4' polarity
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

enum EStopJunctionLaneTypes {};
struct UnkStruct_002B5B70_S {
    int field_0[6];
    int field_18[4];
    int field_28[10];
};
struct UnkStruct_002B5B70_p {
    unsigned char pad_0[0x10];
    float field_10;
    unsigned char pad_14[0x1C];
    float field_30;
    unsigned char pad_34[0xD];
    unsigned char field_41;
    unsigned char pad_42[3];
    unsigned char field_45;
    unsigned char field_46;
    unsigned char pad_47[2];
    unsigned char field_49;
    unsigned char pad_4A[6];
};
struct UnkStruct_002B5B70_l {
    unsigned char pad_0[4];
    unsigned short field_4;
    unsigned char pad_6[0x40];
    unsigned char field_46;
    unsigned char pad_47[5];
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x22C];
    UnkStruct_002B5B70_l field_22C[1];
    unsigned char pad_278[0x2F038];
    UnkStruct_002B5B70_p field_2F2B0[1];
};
struct UnkStruct_D_0055D7DC { unsigned char * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0055D7DC D_0055D7DC;
extern "C" float GetSignedForwardDistBetweenParams__14CB3TrafficLaneFff(void *, float, float);
class CB3StopJunction {
public:
    UnkStruct_002B5B70_S * field_0;
    unsigned char pad_4[0xC];
    unsigned char field_10[5];
    unsigned char field_15;
    unsigned char field_16;
    unsigned char field_17;
    unsigned char field_18;
    unsigned char pad_19[3];
    unsigned char field_1C;
    void StopCarsInControlZone(EStopJunctionLaneTypes);
};
static inline UnkStruct_002B5B70_p * func_002B5B70_inl1(unsigned char i)
{
    if (i == 0xFF) {
        return 0;
    }
    return &D_00522660.field_2F2B0[i];
}
static inline UnkStruct_002B5B70_p * func_002B5B70_inl3(unsigned char n)
{
    if (n == 0xFF) {
        return 0;
    }
    return func_002B5B70_inl1(n);
}
void CB3StopJunction::StopCarsInControlZone(EStopJunctionLaneTypes p0)
{
    if (p0 == 1 && field_1C == 0) return;
    unsigned char *slot = &field_10[p0];
    int laneIdx = field_0->field_0[p0];
    int lo = field_0->field_18[p0];
    int hi = field_0->field_28[p0];
    UnkStruct_002B5B70_l *lane = &D_00522660.field_22C[laneIdx];
    unsigned char id = *slot;
    UnkStruct_002B5B70_p *q;
    if (id != 0xFF) {
        q = func_002B5B70_inl1(id);
        if (q->field_41 == laneIdx) {
            float d = GetSignedForwardDistBetweenParams__14CB3TrafficLaneFff(lane, (float)hi, q->field_30);
            if (d < 0.0f) d = 0.0f;
            if (q->field_46 == 2) q->field_10 = d;
            return;
        }
        if (q->field_46 == 2) {
            q->field_46 = 1;
            q->field_10 = -1.0f;
        }
        *slot = 0xFF;
        return;
    }
    unsigned char first = D_0055D7DC.field_0[lane->field_4 + hi];
    UnkStruct_002B5B70_p *p;
    unsigned char n;
    if (first == 0xFF) goto lanepath;
    n = func_002B5B70_inl1(first)->field_45;
    if (n == 0xFF) goto null1;
    p = func_002B5B70_inl1(n);
have:
    if (p == 0) return;
    if (p->field_49 == field_17) {
        n = func_002B5B70_inl1(field_17)->field_45;
        if (n == 0xFF) goto null2;
        p = func_002B5B70_inl1(n);
    } else if (p->field_49 == field_18) {
        n = func_002B5B70_inl1(field_18)->field_45;
        if (n == 0xFF) goto null3;
        p = func_002B5B70_inl1(n);
    }
loop:
    if (p != 0) {
        float d1 = GetSignedForwardDistBetweenParams__14CB3TrafficLaneFff(lane, (float)hi, p->field_30);
        float d2 = GetSignedForwardDistBetweenParams__14CB3TrafficLaneFff(lane, p->field_30, (float)lo);
        if (d1 > 0.0f && d2 > 0.0f) {
            p->field_46 = 2;
            p->field_10 = d1;
            *slot = p->field_49;
            return;
        }
        n = p->field_45;
        if (n != 0xFF) {
            p = func_002B5B70_inl1(n);
            goto loop;
        }
        p = 0;
        goto loop;
    }
    return;
null1:
    p = 0;
    goto have;
lanepath:
    n = lane->field_46;
    if (n == 0xFF) {
        p = 0;
        goto have;
    }
    p = func_002B5B70_inl1(n);
    goto have;
null2:
    p = 0;
    goto loop;
null3:
    p = 0;
    goto loop;
}
