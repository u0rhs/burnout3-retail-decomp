// NONMATCHING: func_001576B0 -- retail 140 / ours 148 instructions, 108 in changed runs
// 148 vs 140 instrs, frame 0x40 vs 0x50. Draft logic complete. Dot product now via file-local a211_dot ((x-y).b: vsub on compiler regs vf1=b, vf2=y/result, vf3=x, 1.0 vaddw.x parked in a GPR at function top, qmtc2.i back, vmaddz.x vf1,vf1,vf2z): the VU block now matches retail. Remaining: self should be s0 and the player ptr t6 s1 (ours reversed; retail loads t6 in the bc1f delay slot after the compare), t4 kept in a1 not reloaded, and a 16-byte dead frame slot. Header gap: DotProduct(CGtV3d,CGtV3d) with the 1.0 in a GPR (same shape as GetSquaredLength in GetWidth/UpdateLastPositions).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
// [L] N185: stands in for (x - y) . b as retail inlines it: vsub on compiler registers, 1.0 parked in a GPR
static inline GtMathPs2::XAxisType a211_dot(const GtMathPs2::CGtV3d &b, const GtMathPs2::CGtV3d &x, const GtMathPs2::CGtV3d &y)
{
    u_long128 vo, one, d, o, g;
    u_long128 k = b.mData;
    asm("vaddw.x %0, $vf0, $vf0w" : "=j"(vo));
    asm("qmfc2.i %0, %1" : "=r"(one) : "j"(vo));
    asm("vsub.xyz %1, %3, %2" "\n\t" "vmul.xyz %1, %1, %0" "\n\t" "vadday.x $ACC, %1, %1y" : "+j"(k), "=&j"(d) : "j"(y.mData), "j"(x.mData));
    asm("qmtc2.i %1, %0" : "=j"(o) : "r"(one));
    asm("vmaddz.x %0, %0, %1z" : "+j"(o) : "j"(d));
    asm("qmfc2.i %0, %1" : "=r"(g) : "j"(o));
    return GtMathPs2::XAxisType(g);
}

class CB3RaceCarPhysics;
class CB3CollidingPair;
class CB3CrashStartInfo;
class CB3RaceCar;
class CB3ScoreCategory;

class CB3CrashActionDirector;
class CB3Score;
class CB3ScoreBonus;
struct UnkStruct_001576B0;
struct UnkStruct_001576B0_2;
struct UnkStruct_001576B0_5;
struct UnkStruct_001576B0_6;
struct UnkStruct_001576B0_e1;
struct UnkStruct_D_0052267C;
struct UnkStruct_D_0055EFEC;

class CB3CrashActionDirector {
public:
    void StartRaceCarCrashing(CB3RaceCarPhysics*, int, CB3CollidingPair*, CB3CrashStartInfo*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3ScoreBonus {
public:
    void OnGrind(CB3RaceCar*, CB3ScoreCategory*);
};

struct UnkStruct_D_0052267C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_001576B0_2 {
    unsigned char pad_0[0xC];
    float field_C;
};

struct UnkStruct_001576B0_5 {
    unsigned char pad_0[0x30];
    GtMathPs2::CGtV3d field_30;
    unsigned char pad_40[0x18AA];
    unsigned char field_18EA;
    unsigned char pad_18EB[0x29];
    int field_1914;
    unsigned char pad_1918[0x94];
    signed char field_19AC;
};

struct UnkStruct_001576B0_6 {
    GtMathPs2::CGtV3d field_0;
    unsigned char pad_10[0x20];
    GtMathPs2::CGtV3d field_30;
};

struct UnkStruct_001576B0_e1 {
    int field_0;
    unsigned char pad_4[0x2C];
};

struct UnkStruct_D_0055EFEC {
    UnkStruct_001576B0_e1 field_0[1];  // [G] element count unknown
};

class CB3Score {
public:
    static float gmrGrindingExtraBurnValue;
};

struct UnkStruct_001576B0 {
    unsigned char pad_0[0xC8];
    UnkStruct_001576B0_6 * field_C8;
    unsigned char pad_CC[0x58];
    CB3ScoreBonus field_124;
    unsigned char pad_125[0x49F];
    float field_5C4;
    float field_5C8;
    float field_5CC;
    float * field_5D0;
    unsigned char field_5D4;
    signed char field_5D5;
    unsigned char field_5D6;
    signed char field_5D7;
    unsigned char pad_5D8[0x4];
    UnkStruct_001576B0_2 * field_5DC;
    UnkStruct_001576B0_5 * field_5E0;
    unsigned char field_5E4;
};

extern UnkStruct_D_0052267C D_0052267C;
extern UnkStruct_D_0055EFEC D_0055EFEC;
extern CB3CrashActionDirector D_0055E948;

extern "C" void AddBurn__7CB3BurnFf(void *, float, signed char);  // CB3Burn::AddBurn(float), passed 1 more argument(s) [G]
extern "C" void func_001CC520(int, int, int, float);

// 0x001576B0
extern "C" void func_001576B0(UnkStruct_001576B0 * self)
{
    if (self->field_5E4 != 0) {
        float t0 = self->field_5C4;
        float t1 = D_0052267C.field_0;
        self->field_5CC = t0;
        self->field_5C4 = (t0 + t1);
        self->field_5C8 = self->field_5DC->field_C;
        signed char t2 = self->field_5D7;
        signed char t3 = self->field_5D5;
        signed char v0 = t2;
        if (t3 < (t2 + -1)) {
            signed char m0 = t2;
            while (m0--) {
                if ((t0 + t1) < self->field_5D0[m0]) {
                    continue;
                }
                self->field_5D6 = t3;
                self->field_5D5 = m0;
                break;
            }
            v0 = m0;
        }
        AddBurn__7CB3BurnFf(((char *)self + 0xCC), (CB3Score::gmrGrindingExtraBurnValue * D_0052267C.field_0), v0);
        self->field_5E4 = 0;
        self->field_5D4 = 1;
        UnkStruct_001576B0_5 * t4 = self->field_5E0;
        if (t4 == 0) {
            return;
        }
        if (t4->field_18EA != 0) {
            return;
        }
        if (t4->field_1914 != 1) {
            return;
        }
        if (self->field_5D5 != (self->field_5D7 + -1)) {
            return;
        }
        if (self->field_5C4 < 1.0f) {
            return;
        }
        signed char t5 = t4->field_19AC;
        int t6 = D_0055EFEC.field_0[t5].field_0;
        if (!(a211_dot(self->field_C8->field_0, self->field_C8->field_30, t4->field_30) < 0.0f)) {
            func_001CC520(t6, 8, 0, 0.25f);
        } else {
            func_001CC520(t6, 4, 0, 0.25f);
        }
        D_0055E948.StartRaceCarCrashing((CB3RaceCarPhysics*)t6, self->field_5E0->field_19AC, 0, 0);
        return;
    }
    if (self->field_5D4 == 0) {
        return;
    }
    self->field_124.OnGrind((CB3RaceCar*)self->field_5E0, (CB3ScoreCategory*)((char *)self + 0x5C4));
    self->field_5CC = self->field_5C4;
    self->field_5D6 = self->field_5D5;
    UnkStruct_001576B0_2 * t7 = self->field_5DC;
    float t8 = t7->field_C;
    self->field_5C8 = t8;
    self->field_5C4 = 0.0f;
    self->field_5D4 = 0;
    self->field_5D5 = -1;
}

