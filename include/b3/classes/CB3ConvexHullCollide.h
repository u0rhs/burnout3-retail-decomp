// CB3ConvexHullCollide -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3CONVEXHULLCOLLIDE_H
#define B3_CLASSES_CB3CONVEXHULLCOLLIDE_H

#include "b3/GtMathPs2.h"

class CB3CollidingBody;
class CB3ConvexHullCollide;
struct CB3HullWorldTriCollideParams;

class CB3ConvexHullCollide {
public:
    int CollideBodyHullWithWorld(CB3HullWorldTriCollideParams* p0, CB3CollidingBody* p1);

    int field_0;
    unsigned char pad_4[0x2C];
    u_long128 field_30;
    u_long128 field_40;
    u_long128 field_50;
    u_long128 field_60;
    u_long128 field_70;
    u_long128 field_80;
    u_long128 field_90;
    u_long128 field_A0;
    unsigned char pad_B0[0x40];
    int field_F0;
    void * field_F4;
    unsigned char pad_F8[0x8];
    GtMathPs2::CGtV3d field_100;
    unsigned char pad_110[0x1];
    unsigned char field_111;
};

#endif
