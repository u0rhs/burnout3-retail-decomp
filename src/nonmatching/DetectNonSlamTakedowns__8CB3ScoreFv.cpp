// NONMATCHING: DetectNonSlamTakedowns__8CB3ScoreFv -- retail 253 / ours 253 instructions, 35 in changed runs
// near33: 49->35, 253=253. 'CB3RaceCar **pcar = &D_00522660.field_12AD28[i];' before the if and 'car = *pcar' inside fixes the group-1 recent layout (beqz t2 exit form) and the count. Left: car lands in t7 (retail a3, loaded in the beqz delay slot via lui %hi(D_0012AD28) not lui/ori at); retail recomputes i*4 in the then-path (sll a3,a0,2) where ours reuses the top i*4 (t3); j copy / inline helper did not split it
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: DetectNonSlamTakedowns__8CB3ScoreFv -- retail 253 / ours 252 instructions, 49 in changed runs
// a137: 252 vs 253 instrs, 49 changed. Solved: prev/prevc inlines with shared max.s(1,1) 'one' passed in, recent() bool-diamond inline (same as ConfirmTradePaint), !found-first layout, while(k-- != 0) loop. Left: group-1 recent pair: retail uses separate regs t4/t2 for the two bools and 'beqz t2 -> exit; b exit; daddu t6,1' (then-block falls right after the test), ours reuses a3 and branches bnez to a distant skip block; car pointer lands in t7 vs a3
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

class CB3RaceCar;
struct UnkStruct_D_00522660 { unsigned char pad_0[0x12AD28]; CB3RaceCar *field_12AD28[6]; };
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004F509C { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0052267C { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_0052267C D_0052267C;
extern CB3RaceCar * D_0064D388[];
extern "C" void OnRub__13CB3ScoreBonusFP10CB3RaceCarP16CB3ScoreCategory(void *, CB3RaceCar *, void *);
extern "C" void AddBurn__7CB3BurnFf(void *, float);
static inline float a137_maxs(float a, float b) { float r; asm("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
class CB3Score {
public:
    void DetectNonSlamTakedowns();
    static float gmrRubbingMinTime;
    static float gmrTakedownCrashTimeNoSlam;
    static float gmrRubbingBurnValue;
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0xB8];
    CB3RaceCar * field_C8;
    unsigned char pad_CC[0x58];
    unsigned char field_124[0x3EC];
    float field_510[6];
    float field_528[6];
    float field_540[6];
    unsigned char pad_558[6];
    unsigned char field_55E[6];
    float field_564;
    float field_568;
    float field_56C;
    float * field_570;
    unsigned char field_574;
    signed char field_575;
    signed char field_576;
    signed char field_577;
    unsigned char pad_578[4];
    CB3RaceCar * field_57C;
    int field_580;
    unsigned char pad_584[0x68];
    CB3RaceCar * field_5EC;
    float field_5F0;
};
#define CAR_F(c, o) (*(float *)((char *)(c) + (o)))
#define CAR_I(c, o) (*(int *)((char *)(c) + (o)))
static inline CB3RaceCar * a137_prev(CB3Score * s, float one)
{
    if (s->field_5F0 == -1.0f) {
        return 0;
    }
    if (s->field_5F0 + one < s->field_C) {
        return 0;
    }
    return s->field_5EC;
}
static inline CB3RaceCar * a137_prevc(CB3RaceCar * c, float one)
{
    if (CAR_F(c, 0x16B0) == -1.0f) {
        return 0;
    }
    if (CAR_F(c, 0x16B0) + one < CAR_F(c, 0x10CC)) {
        return 0;
    }
    return (CB3RaceCar *)CAR_I(c, 0x16AC);
}
static inline bool a137_recent(CB3RaceCar * c, int off)
{
    float one = 1.0f;
    float t = CAR_F(c, off);
    bool v;
    if (t < 0.0f) {
        v = false;
    } else {
        if (CAR_F(c, 0x10CC) > t + one) v = false;
        else v = true;
    }
    return v;
}
void CB3Score::DetectNonSlamTakedowns()
{
    int i;
    bool found = false;
    for (i = 0; i < D_0064D37C.field_0; i++) {
        CB3RaceCar ** pcar = &D_00522660.field_12AD28[i];
        if (field_55E[i] != 0) {
            CB3RaceCar * car = *pcar;
            float one = a137_maxs(1.0f, 1.0f);
            CB3RaceCar * x = a137_prev(this, one);
            CB3RaceCar * y = a137_prevc(car, one);
            bool skip = false;
            if (y == field_C8) {
                CB3RaceCar * o = (CB3RaceCar *)CAR_I(car, 0x1188);
                if (a137_recent(o, 0x1588) || a137_recent(o, 0x1680)) skip = true;
            }
            if (x == car) {
                CB3RaceCar * o = field_C8;
                if (a137_recent(o, 0x1588) || a137_recent(o, 0x1680)) skip = true;
            }
            if (skip) {
                field_528[i] = 0.0f;
            } else {
                if (field_528[i] == 0.0f) field_540[i] = field_C;
                field_528[i] += D_004F509C.field_0;
                if (!(field_528[i] < gmrRubbingMinTime)) {
                    field_580 = i;
                    found = true;
                }
            }
        } else {
            if (field_528[i] > 0.0f) {
                if (!(field_C <= field_510[i] + gmrTakedownCrashTimeNoSlam)) {
                    field_528[i] = 0.0f;
                }
            }
        }
    }
    if (!found) {
        if (field_574 != 0) {
            OnRub__13CB3ScoreBonusFP10CB3RaceCarP16CB3ScoreCategory((char *)this + 0x124, D_0064D388[field_580], &field_564);
            field_56C = field_564;
            field_576 = field_575;
            field_568 = CAR_F(field_57C, 0xC);
            field_564 = 0;
            field_574 = 0;
            field_575 = -1;
        }
    } else {
        float f1 = field_564;
        float f2 = f1 + D_0052267C.field_0;
        field_56C = f1;
        field_564 = f2;
        field_568 = CAR_F(field_57C, 0xC);
        int n = field_577;
        int cur = field_575;
        if (cur < n - 1) {
            int k = n;
            while (k-- != 0) {
                if (f2 < field_570[k]) continue;
                field_576 = cur;
                field_575 = k;
                break;
            }
        }
        AddBurn__7CB3BurnFf((char *)this + 0xCC, gmrRubbingBurnValue * D_0052267C.field_0);
        field_574 = 1;
        CB3RaceCar * c = D_0064D388[field_580];
        if (CAR_I(c, 0x1914) == 1) {
            CAR_F(c, 0x1644) = CAR_F(c, 0x10CC);
        }
    }
}
