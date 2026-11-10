// NONMATCHING: func_00220040 -- retail 75 / ours 75 instructions, 56 in changed runs
// draftX: lpLODData parameter added (a2, unused); stale N140 pads dropped (frame 0x110 -> 0xD0, retail 0xA0); left: stack-slot offsets only (N255 family: live temporaries packed low, 7 dead slots above vs retail's interleaved 4)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every load/store/op as retail; only stack offsets of the six vector temporaries differ

// draftX 2026-10-31: added the unused lpLODData parameter (a2, passed by RenderVehicle); dropped the N140 frame pads
// (stale: they now gave frame 0x110; without them 0xD0, retail 0xA0). Residue = N255 slot order: ours packs the six
// live temporaries at sp+0..0x5F with seven dead slots above; retail interleaves (dead at 0x0 and 0x70..0x9F).
// func_00220040 -- hand-written from retail (ghvu2, Ghidra draft as a reading aid).
// Unnamed in every table (research/retail_names.csv has a low-confidence guess only), so a placeholder with C
// linkage; file and Area unknown, so _unclassified/. Structs carry only the fields touched; every type is [G]
// (instruction widths). p0 = a0, p1 = a1, f12/f13 = two floats.

#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_propagation off

using namespace GtMathPs2;

struct UnkStruct_00220040_2 {
    CGtV4d field_0;
    CGtV4d field_10;
    CGtV4d field_20;
    float field_30;
    unsigned char pad_34[0x8];
    int field_3C;
    unsigned char pad_40[0x2D0];
    CGtMatrix3x4 field_310;
    unsigned char pad_350[0x48];
    int field_398;
    int field_39C;
};

struct UnkStruct_00220040 {
    unsigned char pad_0[0xE0];
    CGtV3d field_E0;
    unsigned char pad_F0[0x10];
    UnkStruct_00220040_2 * field_100;
};

struct UnkStruct_00220040_1 {
    unsigned char pad_0[0x30];
    CGtV3d field_30;
    unsigned char pad_40[0x1C];
    float field_5C[3][3];
};

static inline void func_00220040_inl1(UnkStruct_00220040 *p0, float t, float f0)
{
    p0->field_100->field_20 = CGtV4d(t, t, t, 128.0f * f0);
}
// 0x00220040
// [L] research/nahelam_check.csv: BeginRenderingSingleVehicle(const CB3VehicleEssentialParams*, CB3VehicleLODData*,
// float, float); the caller (RenderVehicle, 0x21E6F0) passes lpLODData in a2 [C], this body never reads it [C].
extern "C" void func_00220040(UnkStruct_00220040 * p0, const UnkStruct_00220040_1 * p1, void * lpLODData, float f0, float f1)
{
    UnkStruct_00220040_2 *o = p0->field_100;
    o->field_3C = 0;
    o->field_398 = 0;
    o->field_39C = 0;
    p0->field_100->field_310.mPos = p1->field_30 - p0->field_E0;
    p0->field_100->field_310.mRight = CGtV3d(p1->field_5C[0][0], p1->field_5C[0][1], p1->field_5C[0][2]);
    p0->field_100->field_310.mUp = CGtV3d(p1->field_5C[1][0], p1->field_5C[1][1], p1->field_5C[1][2]);
    p0->field_100->field_310.mAt = CGtV3d(p1->field_5C[2][0], p1->field_5C[2][1], p1->field_5C[2][2]);
    float t = 128.1f * f1;
    float h = 0.5f * t;
    p0->field_100->field_30 = 128.1f * f0;
    p0->field_100->field_10 = CGtV4d(0.0f, 0.0f, 0.0f, 19.2f * f0);
    p0->field_100->field_0 = CGtV4d(h, h, h, 38.4f * f0);
    func_00220040_inl1(p0, t, f0);
}

#pragma pop
