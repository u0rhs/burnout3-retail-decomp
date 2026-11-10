// NONMATCHING: Construct__17CB3EffectsManagerFv -- retail 264 / ours 264 instructions, 37 in changed runs
// near31: header drift had moved field_B0.. by -8 (fixed with pad_A8[8]); still 42 off, all GPR colouring in the 36-address SetX/Y/Z block (retail -1.0 in v1, 1.0 lui after 0's qmtc2 reusing t0; ours hoists the 1.0 lui into a3)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: Construct__17CB3EffectsManagerFv -- retail 264 / ours 264 instructions, 42 in changed runs
// v298: logic and frame exact; 42 instrs in the 6-axis SetX/Y/Z(float) block: GPR allocation of the 36 un-CSE'd this+0x20000 addresses vs the -1/0/1 constants (retail -1.0 in v1, 1.0 reuses 0's t0). Tried float-constant locals, inline helper, GPR in/out stand-in, member/struct/array forms, 16 pragmas.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3TrailSystem { public: void Construct(); unsigned char pad_0[0x14680]; };

struct UnkStruct_00262CD0_cor { unsigned char pad_0[0x34]; };
struct UnkStruct_00262CD0_deb { unsigned char pad_0[0x30]; };
struct UnkStruct_00262CD0_par { unsigned char pad_0[0x150]; };
struct UnkStruct_00262CD0_pop { unsigned char pad_0[0x40]; };
struct UnkStruct_00262CD0_spk { unsigned char pad_0[0xA8]; };
struct UnkStruct_00262CD0_cp { int field_0; int field_4; };
struct UnkStruct_D_01EA4BB0 { unsigned char pad_0[0x10]; };

class CB3EffectsManager {
public:
    void Construct();

    int field_0;
    int field_4;
    int field_8;
    UnkStruct_00262CD0_cor field_C[3];
    unsigned char pad_A8[8];
    UnkStruct_00262CD0_deb field_B0[4];
    UnkStruct_00262CD0_par field_170[24];
    UnkStruct_00262CD0_pop field_20F0[4];
    UnkStruct_00262CD0_spk field_21F0[6];
    unsigned char pad_25E0[0x20];
    CB3TrailSystem field_2600;
    unsigned char pad_16C80[0x1F7A0 - 0x16C80];
    CGtV3d field_1F7A0[6];
};

extern UnkStruct_00262CD0_cp _gaCoronaParams[];
extern int _gnEffectsMemoryAllocation;
extern UnkStruct_D_01EA4BB0 D_01EA4BB0;
extern "C" void Construct__17CB3DebrisRendererFv();
extern "C" void Construct__19CB3ParticleRendererFv();
extern "C" void Construct__16CB3SparkRendererFv();
extern "C" void Construct__15CB3ScrapeSystemFv(void *);
extern "C" void Construct__21CB3CoronaDynamicArrayFi(void *, int);
extern "C" void Construct__14CB3DebrisArrayF15EDebrisGeometry(void *, int);
extern "C" void Construct__16CB3ParticleArrayF16EParticleArrayID(void *, int);
extern "C" void Construct__15CB3PopcornArrayF15EPopcornArrayID(void *, int);
extern "C" void Construct__13CB3SparkArrayF13ESparkArrayID(void *, int);
extern "C" void func_0039AD80(void *);

// 0x00262CD0
void CB3EffectsManager::Construct()
{
    _gnEffectsMemoryAllocation = 0;
    Construct__17CB3DebrisRendererFv();
    Construct__19CB3ParticleRendererFv();
    Construct__16CB3SparkRendererFv();
    field_2600.Construct();
    Construct__15CB3ScrapeSystemFv((char *)this + 0x16C80);
    field_8 = 0;
    field_0 = 0;
    field_4 = 0;
    for (int i = 0; i < 3; i++) {
        Construct__21CB3CoronaDynamicArrayFi(&field_C[i], _gaCoronaParams[i].field_0);
    }
    for (int i = 0; i < 4; i++) {
        Construct__14CB3DebrisArrayF15EDebrisGeometry(&field_B0[i], i);
    }
    for (int i = 0; i < 24; i++) {
        Construct__16CB3ParticleArrayF16EParticleArrayID(&field_170[i], i);
    }
    for (int i = 0; i < 4; i++) {
        Construct__15CB3PopcornArrayF15EPopcornArrayID(&field_20F0[i], i);
    }
    for (int i = 0; i < 6; i++) {
        Construct__13CB3SparkArrayF13ESparkArrayID(&field_21F0[i], i);
    }
    func_0039AD80(&D_01EA4BB0);
    field_1F7A0[0].SetX(-1.0f);
    field_1F7A0[0].SetY(0.0f);
    field_1F7A0[0].SetZ(0.0f);
    field_1F7A0[1].SetX(1.0f);
    field_1F7A0[1].SetY(0.0f);
    field_1F7A0[1].SetZ(0.0f);
    field_1F7A0[2].SetX(0.0f);
    field_1F7A0[2].SetY(1.0f);
    field_1F7A0[2].SetZ(0.0f);
    field_1F7A0[3].SetX(0.0f);
    field_1F7A0[3].SetY(-1.0f);
    field_1F7A0[3].SetZ(0.0f);
    field_1F7A0[4].SetX(0.0f);
    field_1F7A0[4].SetY(0.0f);
    field_1F7A0[4].SetZ(1.0f);
    field_1F7A0[5].SetX(0.0f);
    field_1F7A0[5].SetY(0.0f);
    field_1F7A0[5].SetZ(-1.0f);
    _gnEffectsMemoryAllocation = -1;
}
