// NONMATCHING: Construct__13CB3HUDManagerFv -- retail 235 / ours 235 instructions, 30 in changed runs
// v293: logic complete, VU numbering and frame exact (N140 0x80 pad [G] for 8 dead 16-byte slots; CGtV4d*float stand-in on compiler-chosen VU regs, scalar first so the ctor stores are evaluated first); 30 instrs left = list scheduling of the colour-constant stores (retail stores 140.x=194 right after the first lqc2)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_001A1920_e0 {
    unsigned char pad_0[0x10];
    int field_10;
    unsigned char field_14[0x34];
    float field_48;
    float field_4C;
    unsigned char pad_50[0x14];
    int field_64;
    int field_68;
    unsigned char pad_6C[0x4];
};
struct UnkStruct_001A1920_c { unsigned char pad_0[0x54]; };
extern UnkStruct_001A1920_c _gPosComponentP1, _gLapComponentP1, _gBoostBarComponentP1, _gScoreComponentP1, _gSpeedoComponentP1,
    _gLapTimerComponentP1, _gTakedownsComponentP1, _gCrashStyleComponentP1, _gCrashTimerComponentP1, _gTimerComponentP1,
    _gScoreListComponentP1, _gPrimaryMessageComponentP1, D_0066B500, D_0066B550, D_0066B5B0, D_0066B6F0, D_0066B750,
    _gBoostBarComponentP2, _gScoreComponentP2, _gSpeedoComponentP2, D_0066C000, D_0066C0A0, D_0066C100, D_0066C2B0,
    _gCrashHeading, _gCrashComboComponent, _gImpactTime;
extern void * _gapu8HUDSceneBuffers[2];
class CB3HUDManager;
extern "C" void Construct__15CB3HUDComponentFP13CB3HUDManager(void *, CB3HUDManager *);
extern "C" void Construct__10CGt2dSceneFiiiPvUi(void *, int, int, int, void *, unsigned int);
extern "C" void Construct__15CB3HUDComponentFv();
extern "C" void StaticConstruct__14CB3HUDBoostBarFv();
class CB3HUDManager {
public:
    void Construct();
    UnkStruct_001A1920_e0 field_0[2];
    unsigned char pad_E0[0x10];
    CGtV4d field_F0;
    CGtV4d field_100;
    CGtV4d field_110;
    CGtV4d field_120;
    CGtV4d field_130;
    CGtV4d field_140;
    CGtV4d field_150;
    CGtV4d field_160;
    int field_170;
    int field_174;
    int field_178;
};
extern float D_004E1010;

// [L] N185: stands in for a missing GtMathPs2 inline (CGtV4d * float on compiler-chosen VU registers)
static inline CGtV4d func_001A1920_inl1(float s, const CGtV4d &v)
{
    u_long128 k, t;
    asm("qmtc2 %1, %0" : "=j"(k) : "r"(s));
    asm("vmulx.xyzw %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(k));
    return CGtV4d(t);
}
// N140 pad: retail's frame keeps 0x80 bytes of dead 16-byte slots above the colour temporaries [G]
struct UnkStruct_001A1920_pad { int x[32]; UnkStruct_001A1920_pad() {} ~UnkStruct_001A1920_pad() {} };

// 0x001A1920
void CB3HUDManager::Construct()
{
    UnkStruct_001A1920_pad pad;
    field_170 = 0;
    field_174 = 0;
    Construct__15CB3HUDComponentFP13CB3HUDManager(&_gPosComponentP1, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&_gLapComponentP1, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&_gBoostBarComponentP1, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&_gScoreComponentP1, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&_gSpeedoComponentP1, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&_gLapTimerComponentP1, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&_gTakedownsComponentP1, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&_gCrashStyleComponentP1, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&_gCrashTimerComponentP1, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&_gTimerComponentP1, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&_gScoreListComponentP1, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&_gPrimaryMessageComponentP1, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&D_0066B500, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&D_0066B550, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&D_0066B5B0, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&D_0066B6F0, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&D_0066B750, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&_gBoostBarComponentP2, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&_gScoreComponentP2, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&_gSpeedoComponentP2, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&D_0066C000, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&D_0066C0A0, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&D_0066C100, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&D_0066C2B0, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&_gCrashHeading, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&_gCrashComboComponent, this);
    Construct__15CB3HUDComponentFP13CB3HUDManager(&_gImpactTime, this);
    int i = 0;
    goto test;
body:
    {
        UnkStruct_001A1920_e0 * e = &field_0[i];
        e->field_10 = i;
        e->field_68 = 0;
        e->field_64 = 0;
        Construct__10CGt2dSceneFiiiPvUi(e->field_14, 0x12, 0x2F, 0x12, _gapu8HUDSceneBuffers[i], 0x1880);
        e->field_48 = 0;
        e->field_4C = 0;
        e->field_48 = 0;
        e->field_4C = 0;
    }
    i++;
test:
    if (i < 2) goto body;
    field_F0 = func_001A1920_inl1((1.0f / 255.0f), CGtV4d(255, 255, 220, 255));
    field_110 = func_001A1920_inl1((1.0f / 255.0f), CGtV4d(249, 249, 128, 255));
    field_120 = func_001A1920_inl1((1.0f / 255.0f), CGtV4d(240, 120, 0, 255));
    field_160 = CGtV4d(0, 0, 0, 0.75f);
    field_100 = CGtV4d(1, 1, 1, 1);
    field_130 = func_001A1920_inl1((1.0f / 255.0f), CGtV4d(141, 185, 255, 255));
    field_140 = func_001A1920_inl1((1.0f / 255.0f), CGtV4d(194, 41, 35, 255));
    field_150 = func_001A1920_inl1((1.0f / 255.0f), CGtV4d(249, 240, 40, 255));

    Construct__15CB3HUDComponentFv();
    StaticConstruct__14CB3HUDBoostBarFv();
    field_178 = 1;
}
