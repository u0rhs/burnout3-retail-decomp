// NONMATCHING: UpdateBodyPartDustTrail__17CB3EffectsManagerFP18CB3BodyPartPhysics -- retail 111 / ours 114 instructions, 166 in changed runs
// a233: logic complete (clamp locals, scale vec, GetLength); far off: VU head needs retail's GPR-parked 1.0 vmulx/vsub/sqlen/vsqrt form (stand-ins), frame 0x80 vs 0x60
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// lifter variant 0
// CB3EffectsManager::UpdateBodyPartDustTrail(CB3BodyPartPhysics*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EffectsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

#include "b3/GtMath.h"

class CB3BodyPartPhysics;

class CB3EffectsManager;
struct CB3BodyPartPhysics;
struct UnkStruct_00257E10_1;
struct UnkStruct_00257E10_3;
struct UnkStruct_00257E10_4;
struct UnkStruct_00257E10_5;
struct UnkStruct_D_004E19AC;
struct UnkStruct_D_004E19B0;
struct UnkStruct_D_004E19B4;
struct UnkStruct_D_004E19B8;
struct UnkStruct_D_004E19BC;
struct UnkStruct_D_004E29E8;

struct CB3BodyPartPhysics {
    unsigned char pad_0[0xB0];
    u_long128 field_B0;
    unsigned char pad_C0[0x144];
    UnkStruct_00257E10_3 * field_204;
    unsigned char pad_208[0xA8];
    UnkStruct_00257E10_4 * field_2B0;
    float field_2B4;
};

struct UnkStruct_00257E10_1 {
    GtMathPs2::CGtV3d field_0;
    u_long128 field_10;
    GtMathPs2::CGtV3d field_20;
    unsigned char pad_30[0x8];
    float field_38;
    float field_3C;
};

struct UnkStruct_00257E10_3 {
    unsigned char pad_0[0x30];
    GtMathPs2::CGtV3d field_30;
};

struct UnkStruct_00257E10_4 {
    unsigned char pad_0[0xCC0];
    UnkStruct_00257E10_5 * field_CC0;
};

struct UnkStruct_00257E10_5 {
    unsigned char pad_0[0x5C];
    float field_5C;
    float field_60;
};

struct UnkStruct_D_004E29E8 {
    float field_0;
};

struct UnkStruct_D_004E19AC {
    float field_0;
};

struct UnkStruct_D_004E19B0 {
    float field_0;
};

struct UnkStruct_D_004E19B4 {
    float field_0;
};

struct UnkStruct_D_004E19BC {
    float field_0;
};

struct UnkStruct_D_004E19B8 {
    float field_0;
};

class CB3EffectsManager {
public:
    void UpdateBodyPartDustTrail(CB3BodyPartPhysics* p0);

    unsigned char pad_0[0x1F84C];
    float field_1F84C;
};

extern UnkStruct_D_004E29E8 D_004E29E8;
extern UnkStruct_D_004E19AC D_004E19AC;
extern UnkStruct_D_004E19B0 D_004E19B0;
extern UnkStruct_D_004E19B4 D_004E19B4;
extern UnkStruct_D_004E19BC D_004E19BC;
extern UnkStruct_D_004E19B8 D_004E19B8;

extern "C" void func_0025F0C0(CB3EffectsManager *, void *, void *, UnkStruct_00257E10_1 *, int, void *, void *, int, int, float, float, float);

// 0x00257E10
void CB3EffectsManager::UpdateBodyPartDustTrail(CB3BodyPartPhysics* p0)
{
    UnkStruct_00257E10_1 local;
    float t0 = p0->field_2B4;
    if (t0 <= 0.0f) return;
    if (!(t0 < 1.5f)) return;
    local.field_0.mData = p0->field_B0;
    float t1 = field_1F84C;
    UnkStruct_00257E10_3 * t2 = p0->field_204;
    local.field_10 = t2->field_30.mData;
    GtMathPs2::CGtV3d sc = local.field_0 * t1;
    local.field_20 = t2->field_30 - sc;
    float a = p0->field_2B0->field_CC0->field_5C;
    float b = p0->field_2B0->field_CC0->field_60;
    float mm5 = GtMath::Min(b, a);
    float ca = GtMath::Min(GtMath::Max(D_004E19AC.field_0 * (a - D_004E29E8.field_0), 0.0f), 1.0f);
    float cb = GtMath::Min(GtMath::Max(D_004E19B4.field_0 * (b - D_004E19B0.field_0), 0.0f), 1.0f);
    float s = ca + cb;
    float v0;
    if (ca < cb) v0 = s * s + ca; else v0 = s * s + cb;
    float c = GtMath::Min(GtMath::Max(v0 * D_004E19BC.field_0, 0.0f), 1.0f);
    local.field_3C = c;
    local.field_38 = GtMath::Min(GtMath::Max(mm5 * D_004E19B8.field_0, 0.0f), 1.0f - c);
    float len = sc.GetLength();
    float u = 1.0f - 0.6666667f * t0;
    func_0025F0C0(this, ((char *)&local + 0x20), ((char *)&local + 0x10), &local, 8, ((char *)&local + 0x38), ((char *)p0 + 0x2BB), 0, 1, len, 0.75f + 0.25f * u, 0.5f * u);
}
