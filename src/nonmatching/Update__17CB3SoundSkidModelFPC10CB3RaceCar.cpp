// NONMATCHING: Update__17CB3SoundSkidModelFPC10CB3RaceCar -- retail 113 / ours 113 instructions, 126 in changed runs
// a234: 113/113 instrs, ~126 in changed runs, frame 0x1D0 vs 0x1C0. Logic right (callee via extern C const void* params, bool t1 early, e1 stride 0xC0). Misses: retail vector head uses compiler-chosen vadd/vsub/vmulx w/o GPR (file-local stand-ins) and CSEs p0->field_30 via vmove; our order/regs differ; ours holds &local.f120 in s4 (extra saved reg) where retail rebuilds addiu t1,sp each call
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// lifter variant 0
// CB3SoundSkidModel::Update(const CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundSkidModel.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
static inline u_long128 a234_mul(u_long128 a, float s) { u_long128 sv, t; asm("qmtc2.i %1, %0" : "=j"(sv) : "r"(s)); asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(a), "j"(sv)); return t; }
static inline u_long128 a234_add(u_long128 a, u_long128 b) { u_long128 t; asm("vadd.xyz %0, %1, %2" : "=j"(t) : "j"(a), "j"(b)); return t; }
static inline u_long128 a234_sub(u_long128 a, u_long128 b) { u_long128 t; asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a), "j"(b)); return t; }

class CB3RaceCar;
class CB3Wheel;
class CGtSoundVirtualVoice;

class CB3SoundSkidModel;
struct CB3RaceCar;
struct UnkStruct_0028EA10_0;
struct UnkStruct_0028EA10_6;
struct UnkStruct_0028EA10_e0;
struct UnkStruct_0028EA10_e1;
struct UnkStruct_D_0055EFEC;
struct UnkStruct__grEmitterDistanceAt;
struct UnkStruct__grEmitterDistanceRight;

struct UnkStruct_0028EA10_0 {
    float field_0;
    unsigned char pad_4[0x8];
    float field_C;
    float field_10;
    unsigned char pad_14[0x8];
    float field_1C;
    unsigned char pad_20[0x60];
    GtMathPs2::CGtV3d field_80;
    GtMathPs2::CGtV3d field_90;
    unsigned char pad_A0[0x80];
    GtMathPs2::CGtV3d field_120;
    GtMathPs2::CGtV3d field_130;
    void * field_140;
    void * field_144;
    void * field_148;
    void * field_14C;
};

extern "C" void Update__17CB3SoundSkidModelFPPC8CB3WheelfQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPP20CGtSoundVirtualVoiceQ29GtMathPs26CGtV3dbPfPfbbb(CB3SoundSkidModel *, const CB3Wheel **, float, const void *, const void *, CGtSoundVirtualVoice **, const void *, bool, float *, float *, unsigned char, bool, bool);
struct UnkStruct__grEmitterDistanceRight {
    float field_0;
};

struct CB3RaceCar {
    GtMathPs2::CGtV3d field_0;
    unsigned char pad_10[0x10];
    GtMathPs2::CGtV3d field_20;
    GtMathPs2::CGtV3d field_30;
    unsigned char pad_40[0x18AA];
    unsigned char field_18EA;
    unsigned char pad_18EB[0x29];
    int field_1914;
    unsigned char pad_1918[0x94];
    signed char field_19AC;
};

struct UnkStruct__grEmitterDistanceAt {
    float field_0;
};

struct UnkStruct_0028EA10_e0 {
    UnkStruct_0028EA10_6 * field_0;
    unsigned char pad_4[0x2C];
};

struct UnkStruct_D_0055EFEC {
    UnkStruct_0028EA10_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_0028EA10_6 {
    unsigned char pad_0[0xB0];
    u_long128 field_B0;
    unsigned char pad_C0[0x10A9];
    signed char field_1169;
    unsigned char pad_116A[0x35E];
    int field_14C8;
};

struct UnkStruct_0028EA10_e1 {
    unsigned char pad_0[0xC0];
};

class CB3SoundSkidModel {
public:
    void Update(const CB3RaceCar* p0);
    void Update(const CB3Wheel**, float, GtMathPs2::CGtV3d, GtMathPs2::CGtV3d, CGtSoundVirtualVoice**, GtMathPs2::CGtV3d, bool, float*, float*, bool, bool, bool);
};

extern UnkStruct__grEmitterDistanceRight _grEmitterDistanceRight;
extern UnkStruct__grEmitterDistanceAt _grEmitterDistanceAt;
extern UnkStruct_D_0055EFEC D_0055EFEC;

// 0x0028EA10
void CB3SoundSkidModel::Update(const CB3RaceCar* p0)
{
    UnkStruct_0028EA10_0 local;  // [G] the frame's one local (size: up to the frame top)
    float t0 = _grEmitterDistanceRight.field_0;
    bool t1 = (p0->field_1914 == 0);
    float t2 = _grEmitterDistanceAt.field_0;
    signed char t3 = p0->field_19AC;
    UnkStruct_0028EA10_6 * t4 = D_0055EFEC.field_0[t3].field_0;
    unsigned char t5 = p0->field_18EA;
    local.field_140 = ((char *)t4 + 0x8E0);
    signed char t6 = t4->field_1169;
    local.field_148 = ((char *)t4 + 0x820);
    local.field_144 = ((char *)&((UnkStruct_0028EA10_e1 *)t4)[(t6 + -1)] + 0x820);
    local.field_14C = ((char *)&((UnkStruct_0028EA10_e1 *)t4)[(t4->field_1169 + -2)] + 0x820);
    u_long128 p30 = p0->field_30.mData;
    local.field_130.mData = a234_add(a234_add(p30, a234_mul(p0->field_0.mData, t0)), a234_mul(p0->field_20.mData, t2));
    local.field_120.mData = a234_add(a234_sub(p30, a234_mul(p0->field_0.mData, t0)), a234_mul(p0->field_20.mData, t2));
    u_long128 t7 = t4->field_B0;
    local.field_90.mData = t7;
    *(u_long128 *)&local.field_10 = t7;
    Update__17CB3SoundSkidModelFPPC8CB3WheelfQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPP20CGtSoundVirtualVoiceQ29GtMathPs26CGtV3dbPfPfbbb(this, (const CB3Wheel**)((char *)&local + 0x140), local.field_1C, &local.field_90, &p0->field_20, (CGtSoundVirtualVoice**)((char *)this + 0xC), &local.field_130, 1, (float*)((char *)this + 0x24), 0, t5, t1, ((~t4->field_14C8) == 0));
    u_long128 t8 = t4->field_B0;
    unsigned char t9 = p0->field_18EA;
    local.field_80.mData = t8;
    int t10 = t4->field_14C8;
    *(u_long128 *)&local.field_0 = t8;
    Update__17CB3SoundSkidModelFPPC8CB3WheelfQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPP20CGtSoundVirtualVoiceQ29GtMathPs26CGtV3dbPfPfbbb(this, (const CB3Wheel**)((char *)&local + 0x148), local.field_C, &local.field_80, &p0->field_20, (CGtSoundVirtualVoice**)((char *)this + 0x18), &local.field_120, 0, (float*)((char *)this + 0x2C), 0, t9, t1, ((~t10) == 0));
}
