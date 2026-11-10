// NONMATCHING: DetectAndScoreCrashEscape__8CB3ScoreFv -- retail 343 / ours 341 instructions, 75 in changed runs
// v311: logic complete, 75 changed, frame 0x110 right (GetLength's operator-float slot removed by a local mtc1 stand-in, N185). Left: (1) Y-lane slots: retail lane1 0xF0 / dead 0xE0 / lane2 0xD0 / dead 0xC0, ours dead 0xF0,0xE0 then lanes 0xD0,0xC0 (named YAxisType local and helper inlines don't move them); (2) retail reloads me->mPos (lqc2 vf2 and vf1 from 0x30(a0)) for the in-place vsuby.y and the in-place vsub (stand-in, result over the second operand), ours loads once + vmove; VU numbers car vf3/me vf2/me vf1; (3) s-registers rotate (retail h s1, s s2, car s3, k s4, idx s5) and retail spills the 0x12AD1C constant at the prologue, ours before loop 2
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3Score::DetectAndScoreCrashEscape() -- hand-written (v311) from the asm after the proven siblings
// DetectAndScoreNearMiss (B3Score_001598F0.cpp) and func_0015A1F0. [C] name: the mangled symbol in retail's tables.
// Field names are placeholders; every type is [G].

#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

class CGtAxisAlignedBox;
class CB3Burn {
public:
    void AddBurn(float p0);
};
class CB3ScoreBonus {
public:
    void OnCrashEscape(int p0);
    unsigned char pad_0[0x1];
};
struct UnkStruct_9390_rc {
    CGtMatrix3x4 field_0;
    unsigned char * field_40;
    unsigned char pad_44[0x10];
    float field_54;
    unsigned char pad_58[0x1574];
    UnkStruct_9390_rc * field_15CC;
    unsigned char pad_15D0[0x31A];
    unsigned char field_18EA;
    unsigned char pad_18EB[0xC1];
    signed char field_19AC;
};
struct UnkStruct_9390_row {
    unsigned char pad_0[0x218];
    signed char field_218;
};
struct UnkStruct_9390_tv {
    unsigned char pad_0[0x204];
    CGtMatrix3x4 * field_204;
    unsigned char pad_208[0x10];
    signed char field_218;
    unsigned char pad_219[0x1187];
    unsigned char * field_13A0;
    unsigned char pad_13A4[0x107C];
    int field_2420;
};
struct UnkStruct_9390_pe { UnkStruct_9390_row * field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_9390_pm {
    unsigned char field_0[6][0x10];
    unsigned char field_60[0x1C];
    UnkStruct_9390_pe field_7C[6];
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x3C910];
    UnkStruct_9390_pm field_3C910;
    unsigned char pad_x[0x122A10 - 0x3C910 - sizeof(UnkStruct_9390_pm)];
    UnkStruct_9390_tv * field_122A10[0xC0];
    unsigned char pad_y[0x12AD1C - 0x122A10 - 0xC0 * 4];
    int field_12AD1C;
    unsigned char pad_z[8];
    UnkStruct_9390_rc * field_12AD28[6];
};
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };
class CB3Score {
public:
    void DetectAndScoreCrashEscape();
    unsigned char DetectCrashNearMiss(const CGtMatrix3x4 * p0, const CGtAxisAlignedBox * p1, int p2);
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0xB8];
    UnkStruct_9390_rc * field_C8;
    CB3Burn field_CC;
    unsigned char pad_CD[0x57];
    CB3ScoreBonus field_124;
    unsigned char pad_125[0x30F];
    int field_434;
    unsigned char field_438[8];
    float field_440[6];
    float field_458[6];
    int field_470[6];
    float field_488[6];
    float field_4A0[6];
    static float gmrCrashEscapeMinimumSpeed;
    static float gmrCrashEscapeMinClearTime;
    static float gmrCrashNearMissChainTime;
    static float gmrCrashEscapeBurnValue;
};
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0064D37C D_0064D37C;

// [L] N185: stands in for a missing GtMathPs2 inline -- retail's inlined vector subtract with compiler-chosen registers,
// the result over the second operand (`vsub.xyz $vf1, $vf3, $vf1`)
static inline CGtV3d func_00159390_inl1(const CGtV3d & a, CGtV3d b)
{
    asm("vsub.xyz %0, %1, %0" : "+j"(b.mData) : "j"(a.mData));
    return b;
}

// [L] N185: CGtV3d::GetLength() + XAxisType::operator float() stand-in (the lane read from the result register, not
// through the temporary's address -- retail keeps no slot for it here; GtSoundVoiceManager_00388BD0.cpp's form)
static inline float func_00159390_inl2(const CGtV3d & d)
{
    XAxisType l = d.GetLength();
    float f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(l.lVector));
    return f;
}

// 0x00159390
void CB3Score::DetectAndScoreCrashEscape()
{
    unsigned char held[8];
    unsigned char hit[8];
    float spd = 2.236936331f * field_C8->field_54;
    int idx = field_C8->field_19AC;
    int n = D_0064D37C.field_0;
    int i;
    for (i = 0; i < n; i++) {
        hit[i] = 0;
        held[i] = 0;
    }
    if (spd < gmrCrashEscapeMinimumSpeed) {
        int j;
        for (j = 0; j < D_0064D37C.field_0; j++) {
            field_438[j] = 0;
            field_440[j] = -1.0f;
        }
        return;
    }
    int k;
    for (k = 0; k < D_00522660.field_12AD1C; k++) {
        UnkStruct_9390_rc * car = D_00522660.field_12AD28[k];
        int s = D_00522660.field_3C910.field_7C[k].field_0->field_218;
        if (s == -1) continue;
        if (car == field_C8) continue;
        if (car->field_18EA == 0) continue;
        if (car->field_15CC == field_C8) {
            held[s] = 1;
            continue;
        }
        if (field_C <= field_458[s] + gmrCrashEscapeMinClearTime) continue;
        unsigned char * h = &hit[s];
        *h = DetectCrashNearMiss(&car->field_0, (const CGtAxisAlignedBox *)(car->field_40 + 0xE80), s);
        if (*h == 0) continue;
        const CGtV3d & me = field_C8->field_0.mPos;
        float dy = car->field_0.mPos.Y() - me.Y();
        float len = func_00159390_inl2(func_00159390_inl1(car->field_0.mPos, me));
        if (len < 3.0f && dy > 1.0f && dy < 15.0f) {
            field_488[s] = dy;
            field_470[s] = 0xC;
        }
    }
    for (k = 0; k < D_00522660.field_3C910.field_60[idx]; k++) {
        unsigned char id = D_00522660.field_3C910.field_0[idx][k];
        UnkStruct_9390_tv * tv = D_00522660.field_122A10[id];
        int s = tv->field_218;
        if (s == -1) continue;
        if (field_C <= field_458[s] + gmrCrashEscapeMinClearTime) continue;
        unsigned char * h = &hit[s];
        *h = DetectCrashNearMiss(tv->field_204, (const CGtAxisAlignedBox *)(tv->field_13A0 + 0xE80), s);
        if (*h == 0) continue;
        const CGtV3d & me = field_C8->field_0.mPos;
        float dy = tv->field_204->mPos.Y() - me.Y();
        float len = func_00159390_inl2(func_00159390_inl1(tv->field_204->mPos, me));
        if (len < 3.0f && dy > 1.0f && dy < 15.0f) {
            field_488[s] = dy;
            field_470[s] = tv->field_2420;
        }
    }
    for (k = 0; k < D_00522660.field_12AD1C; k++) {
        if (held[k] != 0) {
            field_440[k] = -1.0f;
            field_458[k] = field_C;
        } else {
            if (field_438[k] != 0 && hit[k] == 0) {
                field_440[k] = field_C;
            }
            float * t = &field_440[k];
            if (!(*t < 0.0f) && !(field_C <= *t + gmrCrashNearMissChainTime)) {
                *t = -1.0f;
                field_458[k] = field_C;
                field_434 = field_434 + 1;
                field_CC.AddBurn(gmrCrashEscapeBurnValue);
                field_124.OnCrashEscape(k);
                field_470[k] = 0;
                field_488[k] = -1.0f;
                field_4A0[k] = -1.0f;
            }
        }
        field_438[k] = hit[k];
    }
}
