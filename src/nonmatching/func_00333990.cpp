// NONMATCHING: func_00333990 -- retail 393 / ours 346 instructions, 311 in changed runs
// fix2 (2026-11-01): the CB3BodyPartPhysics virtual call goes to slot +0x10 (the draft declared vfunc_0.. first, putting vfunc_10 at +0x18) [C] retail 0x3339B4 | Before: son5: logic/control flow complete (CB3BodyPartPhysics-like update: matrix compose, PRNG jitter, normalise, ConvexHull init); remaining: retail copies matrix rows 1-3 via byte-pair loops into a 2nd matrix (frame 0x2C0 vs ours smaller) and VU reg/sched differences
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

extern "C" void func_001AB610(void *, void *);
extern "C" void Initialise__21CB3ConvexHullBodyPartFv(void *);
extern "C" void MakeFromBoundingBox__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d12EB3HullShape(void *, const void *, const void *, int);

struct UnkStruct_00333990_pr { int field_0; int field_4; };   // [L] D_0055E948/94C: PRNG state pair
extern int D_0055E948;
extern int D_0055E94C;

struct UnkStruct_00333990_row { CGtV3d field_0; unsigned char pad_10[0xB0]; };
struct UnkStruct_00333990_veh {
    unsigned char pad_0[0xB0];
    CGtV3d field_B0;
    unsigned char pad_C0[0x10];
    CGtV3d field_D0;
    CGtV3d field_E0;
    unsigned char pad_F0[0x1F0 - 0xF0];
    float field_1F0;
    unsigned char pad_1F4[0x204 - 0x1F4];
    CGtMatrix3x4 *field_204;
    unsigned char pad_208[0x10];
    signed char field_218;
    unsigned char pad_219[0xD70 - 0x219];
    UnkStruct_00333990_row field_D70[1];   // [G] count; rows of 0xC0
};

class CB3BodyPartPhysics {
public:
    // fix2: MWCC's first virtual sits at vtable +8 (vfunc_XX = slot offset): the draft's vfunc_0.. put vfunc_10 at +0x18
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(int, int);        // [C] retail 0x3339B4 vcall [+0][+0x10]
    unsigned char pad_4[0xB0 - 4];
    CGtV3dPlus field_B0;
    CGtV4d field_C0;
    CGtV4d field_D0;
    CGtV3d field_E0;
    CGtV4d field_F0;
    CGtV4d field_100;
    unsigned char pad_110[0x1C0 - 0x110];
    CGtV4d field_1C0;
    CGtV3d field_1D0;
    CGtV3d field_1E0;
    float field_1F0;
    unsigned char pad_1F4[0x204 - 0x1F4];
    CGtMatrix3x4 *field_204;
    void *field_208;
    unsigned char field_20C;
    unsigned char pad_20D[0x260 - 0x20D];
    CGtV3d field_260;
    unsigned char pad_270[0x40];
    UnkStruct_00333990_veh *field_2B0;
    int field_2B4;
    short field_2B8;
    unsigned char field_2BA;
    unsigned char field_2BB;
    unsigned char pad_2BC[4];
    unsigned char field_2C0[0x210];
};

static inline float func_00333990_inl1()
{
    unsigned int h = (D_0055E948 << 16) + (D_0055E948 >> 16) + D_0055E94C;
    D_0055E948 = h;
    D_0055E94C = D_0055E94C + h;
    return (float)h * 2.3283064e-10f;
}

// 0x00333990
extern "C" void func_00333990(CB3BodyPartPhysics *self)
{
    UnkStruct_00333990_veh *veh = self->field_2B0;
    if (veh->field_218 >= 0) {
        self->vfunc_10(veh->field_218, 0);
    }
    CGtMatrix3x4 *a = self->field_204;
    CGtMatrix3x4 *b = self->field_2B0->field_204;
    CGtMatrix3x4 m;
    m.mRight = TransformVector(*b, a->mRight);
    m.mUp = TransformVector(*b, a->mUp);
    m.mAt = TransformVector(*b, a->mAt);
    m.mPos = TransformPoint(*b, a->mPos);
    CGtMatrix3x4 m2 = m;
    func_001AB610(self, &m2);
    veh = self->field_2B0;
    CGtV3d v = (CrossProduct(veh->field_D0, self->field_204->mPos - veh->field_204->mPos) + veh->field_B0) * 1.0f;
    CGtV3d r;
    if (self->field_2BA == 2) {
        float x = func_00333990_inl1() - 0.5f;
        float y = func_00333990_inl1() * 0.5f;
        float z = func_00333990_inl1() - 0.5f;
        r.Set(x, y, z);
        r = r * (func_00333990_inl1() * 15.0f + 15.0f);
        v += r; // [C] w = v.w: 0x333F58 lqc2 vf1, 0x260(sp); 0x333F74 vadd.xyz vf1, vf1, vf2; 0x333F80 sqc2 vf1, 0x260(sp) (`a + b` took r's w)
    }
    self->field_B0.SetGtV3d(v);
    XAxisType l = v.GetSquaredLength();
    if ((float)l < 2.3283064e-10f) {
        self->field_B0.SetPlus(0.0f);
        self->field_C0 = *(CGtV4d *)&self->field_204->mAt;
    } else {
        *(CGtV3d *)&self->field_C0 = v;
        XAxisType len = ((CGtV3d *)&self->field_C0)->NormaliseGetLength();
        self->field_B0.SetPlus((float)len);
    }
    if (self->field_2BA == 0) {
        CGtV3dPlus t = self->field_B0;
        float f = ((float *)&t)[3] / (float)self->field_100.X();
        *(CGtV3d *)&self->field_100 = (*(CGtV3d *)self->field_204) * f;
    } else {
        self->field_E0 = self->field_2B0->field_E0;
        self->field_E0 = self->field_E0 * (self->field_1F0 / self->field_2B0->field_1F0);
        CGtV3d t = TransformVector(*self->field_2B0->field_204, self->field_2B0->field_D70[self->field_2B8].field_0);
        self->field_E0 = (self->field_E0 + t) * 2.5f;
    }
    if (self->field_2BA == 1) {
        self->field_1E0 = self->field_1E0 - self->field_260;
        self->field_1D0 = self->field_1D0 - self->field_260;
    }
    self->field_20C = 1;
    self->field_208 = self->field_2C0;
    Initialise__21CB3ConvexHullBodyPartFv(self->field_2C0);
    MakeFromBoundingBox__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d12EB3HullShape(self->field_2C0, &self->field_1E0, &self->field_1D0, 0);
}
