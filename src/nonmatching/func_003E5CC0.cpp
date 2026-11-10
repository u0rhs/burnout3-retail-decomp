// NONMATCHING: func_003E5CC0 -- retail 485 / ours 482 instructions, 208 in changed runs
// draftAO (2026-11-01): rewritten with header APIs (GtMath::Clamp / Max = retail max.s/min.s, CGtV4d SetY(float), CGtMatrix3x4::operator* rest * bone for the wheel and bone 6/7 products), typed box/bone/rest layouts, wheel-slot search as an inline; logic as before, every store/call rechecked | Before: fix3 (2026-11-01): func_003E6C20's output is two quads: the y floor came from an uninitialised separate local (retail sp+0x340 = out[1]) | psweep: scoped #pragma inline_depth(4) [G] improves 1260 -> 873
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm (0x3E5CC0..0x3E6450): calls identical (DeformRoof a0/a1/f12 as retail), non-stack stores as retail, max.s/min.s via GtMath; behaviour_audit quiet

// func_003E5CC0 -- [G] a CB3VehicleDeform roof crush (self = the deform: field_10 its matrix, field_14 the bone block, field_18
// the rest data, as SetVirtualBoneMatrix / RenderClampBoxes; DeformRoof sound at the end). draftAO (2026-11-01): rewritten with
// the header APIs (CGtV4d::SetY(float), CGtMatrix3x4::operator* for retail's row products: rest * bone, vf4/vf3/vf2 = the bone
// rows, 0x3E5E70 / 0x3E61A8 / 0x3E62E4) in retail's statement order; every store and call checked against 0x3E5CC0..0x3E6450.
//   c = GtMath::Clamp(p0, 0, 1); deform+0x101B = 1; clamp box 6 (func_003E6C20 writes two quads: min / max corner);
//   +0x1010 += 0.25 c (0 + f + 0.25 c, adda/madd); roof height y = max(bone[7].pos.y - c, box max.y) into bone[7] and bone[6]
//   position y; ratio = bone[7].pos.y / rest +0x260 y; for wheel slots 0 then 1 (field_18 +0xAC4 table, count +0xC): the first
//   index k with that slot, if (signed char)+0x4B2[k] is 0 or 1: per-wheel y scaled by ratio into +0xC70 + k*0x80, the wheel
//   matrix +0x940 + k*0x80 = rest(+0x7B0 + k*0x80) * wheel(+0xC40 + k*0x80), then the slot searched again and +0x101C[k] = 1;
//   bone[7] / bone[6] skinning matrices (+0x6C0 / +0x680) = rest * bone; DeformRoof(c, roof position) when c > 0.
// Field names are placeholders, every type [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_003E5CC0_box {       // [G] func_003E6C20's out-parameter (sq 0x0 / 0x10 at 0x3E6ED8): clamp box corners
    CGtV3d field_0;
    CGtV3d field_10;
};
struct UnkStruct_003E5CC0_wheel {     // [G] stride 0x80 from +0x940
    CGtMatrix3x4 field_0;
    CGtMatrix3x4 field_40;
};
struct UnkStruct_003E5CC0_bones {
    unsigned char pad_0[0x4B2];
    signed char field_4B2[6];         // [G] per-wheel state (0 / 1 = still attached?)
    unsigned char pad_4B8[0x48];
    CGtMatrix3x4 field_500[8];        // skinning matrices (bone * rest)
    CGtMatrix3x4 field_700[8];        // bone matrices
    unsigned char pad_900[0x40];
    CGtMatrix3x4 field_940[6];        // [G] wheel matrices, stride 0x80 with field_C40
    unsigned char pad_AC0[0x180];
    CGtMatrix3x4 field_C40[1];        // [G] wheel bone (stride 0x80: indexed through field_940's element size below)
    unsigned char pad_C80[0x390];
    float field_1010;
    unsigned char pad_1014[7];
    unsigned char field_101B;
    unsigned char field_101C[6];
};
struct UnkStruct_003E5CC0_rest {
    unsigned char pad_0[0xC];
    signed char field_C;              // wheel count
    unsigned char pad_D[0x253];
    CGtV3d field_260;                 // rest roof position (y read)
    unsigned char pad_270[0x70];
    CGtV3d field_2E0;                 // per-wheel (stride 0x80): y scaled by the roof ratio
    unsigned char pad_2F0[0x280];
    CGtMatrix3x4 field_570[8];        // per-bone rest matrices
    CGtMatrix3x4 field_770[1];        // [G] per-wheel rest matrix at +0x7B0 + k*0x80 (see wheel_rest)
    unsigned char pad_7B0[0x314];
    int field_AC4[6];                 // wheel -> slot table
};
struct UnkStruct_003E5CC0_self {
    unsigned char pad_0[0x10];
    CGtMatrix3x4 *field_10;           // roof position = field_10->mPos (+0x30)
    UnkStruct_003E5CC0_bones *field_14;
    UnkStruct_003E5CC0_rest *field_18;
};
#define WHEEL_REST(s, k) (*(CGtMatrix3x4 *)((char *)(s) + 0x7B0 + (k) * 0x80))
#define WHEEL_Y(s, k) (*(CGtV3d *)((char *)(s) + 0x2E0 + (k) * 0x80))
#define WHEEL_MAT(b, k) (*(CGtMatrix3x4 *)((char *)(b) + 0x940 + (k) * 0x80))
#define WHEEL_BONE(b, k) (*(CGtMatrix3x4 *)((char *)(b) + 0xC40 + (k) * 0x80))

extern "C" void func_003E6C20(UnkStruct_003E5CC0_self *self, int i, UnkStruct_003E5CC0_box *out);
extern "C" void DeformRoof__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(void *mgr, CGtV3d *pos, float amount);   // [C] a0 = &D_01E78510, a1 = field_10 +0x30, f12 = c
extern unsigned char D_01E78510;      // the CB3SoundCrashManager instance

static inline int func_003E5CC0_inl1(UnkStruct_003E5CC0_rest *r, int slot)
{
    int k;
    for (k = 0; k < r->field_C; k++)
        if (r->field_AC4[k] == slot) return k;
    return -1;
}

static inline void func_003E5CC0_inl2(UnkStruct_003E5CC0_self *self, int slot, float ratio)
{
    int k = func_003E5CC0_inl1(self->field_18, slot);
    if (k >= 0 && (unsigned int)self->field_14->field_4B2[k] < 2) {
        CGtV3d v = WHEEL_Y(self->field_18, k) * ratio;   // [C] vmulx.y: only y scaled (lane write on a copy, 0x3E5E34)
        WHEEL_BONE(self->field_14, k).mPos.SetY((float)v.Y());
        WHEEL_MAT(self->field_14, k) = WHEEL_REST(self->field_18, k) * WHEEL_BONE(self->field_14, k);
        k = func_003E5CC0_inl1(self->field_18, slot);
        if (k >= 0) self->field_14->field_101C[k] = 1;
    }
}

// 0x003E5CC0
extern "C" void func_003E5CC0(UnkStruct_003E5CC0_self *self, float p0, float f13 /* passed by every caller, not read here */)
{
    float c = GtMath::Clamp(p0, 0.0f, 1.0f);   // [C] max.s / min.s (0x3E5CDC, 0x3E5CEC)
    self->field_14->field_101B = 1;
    UnkStruct_003E5CC0_box box;
    func_003E6C20(self, 6, &box);
    self->field_14->field_1010 = 0.0f + self->field_14->field_1010 + 0.25f * c;
    float lo = box.field_10.Y();
    float y = (float)self->field_14->field_700[7].mPos.Y() - c;
    y = GtMath::Max(y, lo);   // [C] max.s 0x3E5D54
    self->field_14->field_700[7].mPos.SetY(y);
    self->field_14->field_700[6].mPos.SetY(y);
    float ratio = (float)self->field_14->field_700[7].mPos.Y() / (float)self->field_18->field_260.Y();
    func_003E5CC0_inl2(self, 0, ratio);
    func_003E5CC0_inl2(self, 1, ratio);
    self->field_14->field_500[7] = self->field_18->field_570[7] * self->field_14->field_700[7];
    self->field_14->field_500[6] = self->field_18->field_570[6] * self->field_14->field_700[6];
    if (!(c <= 0.0f))
        DeformRoof__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(&D_01E78510, &self->field_10->mPos, c);
}
