// NONMATCHING: CollideBodyHulls__20CB3ConvexHullCollideFP20CB3HullCollideParamsP16CB3CollidingBodyP16CB3CollidingBodyb -- retail 70 / ours 69 instructions, 1 in changed runs
// pass2c: 4 -> 1: float l = d.GetSquaredLength(); int r = 0; if (!(l < 0.0009f)) r = DoCollideHullToHull(p); return r; gives retail's relay tail (b L; ld ra / jal; b L; andi). Left: our move v0,zero fills the bc1f delay slot, retail leaves nop and puts daddu v0 on the fall-through. if/else, goto, bool/uchar r, inline wrappers, 9 pragmas tried
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)



#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_2B9520_t { CGtV3d f0; CGtV3d f10; CGtV3d f20; CGtV3d f30; };
struct CB3CollidingBody {
    unsigned char pad_0[0x70];
    u_long128 field_70; u_long128 field_80; u_long128 field_90; u_long128 field_A0;
    unsigned char pad_B0[0x154];
    UnkStruct_2B9520_t *field_204;
    int field_208;
};
struct CB3HullCollideParams {
    int field_0;
    unsigned char pad_4[0x2C];
    u_long128 field_30; u_long128 field_40; u_long128 field_50; u_long128 field_60;
    u_long128 field_70; u_long128 field_80; u_long128 field_90; u_long128 field_A0;
    unsigned char pad_B0[0x40];
    int field_F0;
    unsigned char pad_F4[0x2C];
    u_long128 field_120; u_long128 field_130; u_long128 field_140; u_long128 field_150;
    u_long128 field_160; u_long128 field_170; u_long128 field_180; u_long128 field_190;
    unsigned char pad_1A0[0x40];
    int field_1E0;
    int field_1E4;
};
class CB3ConvexHullCollide { public:
static bool DoCollideHullToHull(CB3HullCollideParams *p);
static int CollideBodyHulls(CB3HullCollideParams *p, CB3CollidingBody *a, CB3CollidingBody *b, bool c);
};
static inline bool func_002B9520_inl1(CB3HullCollideParams *p, const CGtV3d &d)
{
    if (d.GetSquaredLength() < 0.0009f) return false;
    return CB3ConvexHullCollide::DoCollideHullToHull(p);
}
// 0x002B9520
int CB3ConvexHullCollide::CollideBodyHulls(CB3HullCollideParams *p, CB3CollidingBody *a, CB3CollidingBody *b, bool c)
{
    p->field_1E4 = 0;
    p->field_1E0 = c;
    p->field_0 = a->field_208;
    UnkStruct_2B9520_t *t = a->field_204;
    p->field_30 = t->f0.mData;
    p->field_40 = t->f10.mData;
    p->field_50 = t->f20.mData;
    p->field_60 = t->f30.mData;
    p->field_70 = a->field_70;
    p->field_80 = a->field_80;
    p->field_90 = a->field_90;
    p->field_A0 = a->field_A0;
    p->field_F0 = b->field_208;
    UnkStruct_2B9520_t *u = b->field_204;
    p->field_120 = u->f0.mData;
    p->field_130 = u->f10.mData;
    p->field_140 = u->f20.mData;
    p->field_150 = u->f30.mData;
    p->field_160 = b->field_70;
    p->field_170 = b->field_80;
    p->field_180 = b->field_90;
    p->field_190 = b->field_A0;
    CGtV3d d = CGtV3d(p->field_60) - CGtV3d(p->field_150);
    float l = d.GetSquaredLength();
    int r = 0;
    if (!(l < 0.0009f)) r = DoCollideHullToHull(p);
    return r;
}


