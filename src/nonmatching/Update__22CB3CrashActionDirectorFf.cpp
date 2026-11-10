// NONMATCHING: Update__22CB3CrashActionDirectorFf -- retail 253 / ours 253 instructions, 20 in changed runs
// v297: logic complete, 253/253, 20 changed (registers only). gCalculatedData as a real member struct (PhysicsManager at 0x3C910 with a 0x30-stride array at +0x7C, car pointers at 0x12AD28, crash analysers at 0x128290) reproduces retail's hoisted 0x12AD28/0x3C98C constants and the spilled 0x3C910; goto-form out-of-line blocks (h-=dt, +=1, clear) in retail order; *(const WAxisType*)&field_B0 lane read and a local GetLength->FPR stand-in (header XAxisType::operator float leaves a dead 16-byte slot) give retail's 0xF0 frame; *(const int*)&car->field_1914 makes car the spilled value. Left: n (D_0064D37C, read at the top) is coloured first (s0) in ours, retail gives it s2 (c/t take s0); W copy temp v0/v1 swap. sreg 2 rounds: no gain.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3RaceCarPhysics;
class CB3TrafficPhysics;
class CB3CADTrafficData;

class CB3CrashAnalyser { public: void * GetVehicleBeforeImpact(); };
class CB3VehicleDeform { public: void Update(); };
class CB3SoundCrashManager { public: void FadeOutCrashStream(); unsigned char pad_0[0x10]; };
struct UnkStruct_001B1CC0_pe { void * field_0; unsigned char pad_4[0x2C]; };
class CB3PhysicsManager { public: void ClearCrashingBodies(int); unsigned char pad_0[0x7C]; UnkStruct_001B1CC0_pe field_7C[3]; };

struct UnkStruct_001B1CC0_rc {
    unsigned char pad_0[0x1914];
    int field_1914;
};

struct UnkStruct_001B1CC0_phys {
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;
    unsigned char pad_C0[0x10];
    CGtV3d field_D0;
    unsigned char pad_E0[0x138];
    signed char field_218;
    unsigned char pad_219[0xAAB];
    char * field_CC4;
};

struct UnkStruct_001B1CC0_e0 {
    unsigned char pad_0[0x4];
    float field_4;
    float field_8;
    float field_C;
    unsigned char pad_10[0x2C];
};

struct UnkStruct_001B1CC0_e1 {
    unsigned char pad_0[0xC];
};

class CB3CrashActionDirector {
public:
    void Update(float);
    void UpdateRaceCar(int, CB3RaceCarPhysics *, float);
    void UpdateTraffic(CB3CADTrafficData *, CB3TrafficPhysics *, float);

    unsigned char pad_0[0xD];
    unsigned char field_D;
    unsigned char pad_E[0x11E];
    UnkStruct_001B1CC0_e0 field_12C[3];
    unsigned char pad_1E0[0x98];
    UnkStruct_001B1CC0_e1 field_278[1];
};

struct UnkStruct_001B1CC0_ca { unsigned char pad_0[0x1050]; };
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x3C910];
    CB3PhysicsManager field_3C910;
    unsigned char pad_x[0x128290 - 0x3C910 - sizeof(CB3PhysicsManager)];
    UnkStruct_001B1CC0_ca field_128290[2];
    unsigned char pad_y[0x12AD28 - 0x128290 - 2 * 0x1050];
    UnkStruct_001B1CC0_rc * field_12AD28[3];
};
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_int D_0064D37C;
extern UnkStruct_D_int D_0064D3A0;
extern UnkStruct_D_int D_0064517C;
extern CB3SoundCrashManager D_01E78510;
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004EE040 D_004EE040;
extern "C" bool func_00131E40(void *);  // [L] CB3Game::IsCrashMode() (E map, high)

static inline CB3PhysicsManager * func_001B1CC0_inl1(UnkStruct_D_00522660 * g) { return (CB3PhysicsManager *)((char *)g + 0x3C910); }
// [L] stand-in: CGtV3d::GetLength() read straight into an FPR (the header's XAxisType::operator float reads through the
// temporary's address, which leaves a dead 16-byte frame slot retail doesn't have here)
static inline float func_001B1CC0_inl2(const CGtV3d & v)
{
    XAxisType l = v.GetLength();
    float f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(l.lVector));
    return f;
}

// 0x001B1CC0
void CB3CrashActionDirector::Update(float dt)
{
    UnkStruct_001B1CC0_phys * phys;
    int n = D_0064D37C.field_0;
    int i;
    for (i = 0; i < D_0064D3A0.field_0; i++) {
        int c = *((signed char *)&D_00522660 + i * 0x27D0 + 0x12C6FC);
        if (((CB3CrashAnalyser *)&D_00522660.field_128290[i])->GetVehicleBeforeImpact() != 0) {
            field_12C[c].field_C = 0.75f;
        }
    }
    bool crashMode = func_00131E40(&D_004EE040);
    int j;
    for (j = 0; j < n; j++) {
        float & t = field_12C[j].field_4;
        if (t <= 0.0f) continue;
        UnkStruct_001B1CC0_rc * car = D_00522660.field_12AD28[j];
        phys = (UnkStruct_001B1CC0_phys *)D_00522660.field_3C910.field_7C[j].field_0;
        ((CB3VehicleDeform *)(phys->field_CC4 + 0x300))->Update();
        t -= dt;
        float & h = field_12C[j].field_C;
        if (!(h <= 0.0f)) h -= dt;
        if (!crashMode && t <= 0.5f && field_D == 0) {
            if (field_12C[j].field_8 < 2.0f) {
                if (!(h <= 0.0f)) goto more;
                if (!(*(const WAxisType *)&phys->field_B0 <= 5.0f)) goto more;
                if (!(func_001B1CC0_inl2(phys->field_D0) <= 1.0f)) goto more;
            }
            if (*(const int *)&car->field_1914 == 0) {
                field_D = 1;
                D_01E78510.FadeOutCrashStream();
            }
        }
    next:
        if (field_12C[j].field_4 <= 0.0f) goto clear;
        UpdateRaceCar(j, (CB3RaceCarPhysics *)phys, dt);
        continue;
    more:
        field_12C[j].field_8 += 1.0f;
        field_12C[j].field_4 += 1.0f;
        goto next;
    clear:
        {
            int k = phys->field_218;
            field_12C[k].field_4 = -1.0f;
            D_00522660.field_3C910.ClearCrashingBodies(k);
        }
    }
    for (i = 0; i < D_0064517C.field_0; i++) {
        UpdateTraffic((CB3CADTrafficData *)&field_278[i], *(CB3TrafficPhysics **)((char *)&D_00522660 + (unsigned int)i * 4 + 0x122A10), dt);
    }
}

