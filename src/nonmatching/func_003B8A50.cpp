// NONMATCHING: func_003B8A50 -- retail 99 / ours 98 instructions, 22 in changed runs
// ghvu4: logic/layout right (goto arms, header SetA, N140 pad, const g); left: field_18 vs D_004E0850 load order at entry, retail's kept dead stores of the scale to local+0x18/0x1C with field_14 loaded once, f0/f1 naming of 5.0f*(t-D) and armA constant materialisation
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

// [L] DNAT: CB3EventFinishedComponent::UpdateAnimation(float) (research/proto/new_names.csv, medium)
struct UnkStruct_003B8A50_12 { unsigned char pad_0[0x10]; CGtV4d field_10; };
struct UnkStruct_003B8A50_13 { unsigned char pad_0[0x8]; float field_8; float field_C; CGtV4d field_10; };
struct UnkStruct_003B8A50_4 { CGtV4d field_0; unsigned char pad_10[0x8]; float field_18; float field_1C; };
struct UnkStruct_003B8A50 {
unsigned char pad_0[0x10];
UnkStruct_003B8A50_12 * field_10;
UnkStruct_003B8A50_13 * field_14;
float field_18;
};
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x110]; CGtV4d field_110; };
struct UnkStruct_D_01E8F09A { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E8F09A D_01E8F09A;
extern UnkStruct_D_01E8F09A D_01E8F294;
extern float D_004E0850;
extern float D_004E07C8;
extern float D_004E0854;
extern float D_004E06B4;
extern float D_004E0858;
extern float D_004E06CC;
extern float D_004E06AC;

// [G] N140 frame pad: retail's frame keeps one unused 16-byte slot below the local.
struct UnkStruct_003B8A50_pad { int x[4]; UnkStruct_003B8A50_pad() {} ~UnkStruct_003B8A50_pad() {} };
static inline CGtV4d func_003B8A50_inl1(CGtV4d c, float a) { c.SetA(a); return c; }

// 0x003B8A50
extern "C" void func_003B8A50(UnkStruct_003B8A50 * self, float dt)
{
if (self->field_18 < D_004E0850) {
UnkStruct_D_01E90240 * const g = &D_01E90240;
float s = 1.0f;
UnkStruct_003B8A50_4 local;
UnkStruct_003B8A50_pad pad;
local.field_0 = g->field_110;
if (D_01E8F09A.field_0 != 0 && D_01E8F294.field_0 != 0) {
self->field_18 = D_004E0850;
} else {
self->field_18 += dt;
}
float t = self->field_18;
if (t < D_004E07C8) goto armA;
if (t < D_004E06B4) goto armB;
if (t < D_004E06AC) {
} else if (t < D_004E0850) {
UnkStruct_003B8A50_12 * o = self->field_10;
if (o != 0) {
CGtV4d c;
c = g->field_110;
c.SetA(5.0f * (t - D_004E06AC));
o->field_10 = c;
}
} else {
if (self->field_10 != 0) {
self->field_10->field_10 = g->field_110;
}
}
join:
local.field_18 = s;
local.field_1C = s;
self->field_14->field_8 = local.field_18;
self->field_14->field_C = local.field_1C;
self->field_14->field_10 = local.field_0;
return;
armA:
{
float a = 5.0f * t;
local.field_0.SetA(a);
s = 1.0f + a * D_004E0854;
}
goto join;
armB:
{
float u = 2.0f * (t - D_004E07C8);
s = D_004E06CC + u * D_004E0858;
}
goto join;
}
}
