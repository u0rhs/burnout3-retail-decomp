// NONMATCHING: DoUnitFrustumTesting__16CB3StreamedTrackFv -- retail 149 / ours 149 instructions, 27 in changed runs
// 149/149, 27 off = s-register rotation only (retail i s3 / j s2 / cam s4; ours i s2 / j s4 / cam s3); logic, block layout (goto none: null-unit block last), VU, frame (0x20 N140 pad) exact. Declaration permutations, sreg run (2 rounds, 139 variants), dropping the cam local and a j copy don't move it. Stand-ins: zero+vaddw.y height vector, compiler-chosen vadd
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3StreamedTrack::DoUnitFrustumTesting() -- hand-matched (ghvu8). Per camera (4) and unit (17): 2 bits of visibility
// in field_58[unit] (0 outside, 1 inside, 2/3 intersecting: refined by a 100-unit sphere around the camera against the
// unit's box) [G].
#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

class CGtFrustum;
class CGtExtrudedBox;
class CGtOrientedBox;

// [G] a camera record of the graphics manager (0x230 bytes; its frustum at +0, position at +0xD0)
struct UnkStruct_0021D080_cam {
    unsigned char pad_0[0xD0];
    CGtV3d field_D0;
    unsigned char pad_E0[0x150];
};
struct UnkStruct_0021D080_gm {
    unsigned char pad_0[0x470];
    UnkStruct_0021D080_cam field_470[4];
};
// [G] a unit: its extruded box (4 base corners, the height in the first corner's w) at +0x10
struct UnkStruct_0021D080_u {
    unsigned char pad_0[0x10];
    CGtV3d field_10[4];
};
// [G] CGtSimpleOrientedBox: 8 corners
struct UnkStruct_0021D080_sb {
    CGtV3d field_0[8];
};
// [G] CGtOrientedBox (0xE0 bytes, filled by ConvertTo)
struct UnkStruct_0021D080_ob {
    unsigned char pad_0[0xE0];
};

class GtIntersection {
public:
    static int IntersectFrustum(const CGtFrustum &f, const CGtExtrudedBox &b);
    static int IntersectSphere(CGtSphere s, const CGtOrientedBox &b);
};

class CB3StreamedTrack {
public:
    void DoUnitFrustumTesting();
    unsigned char pad_0[0x58];
    unsigned short field_58[17];
    unsigned char pad_7A[0x2];
    UnkStruct_0021D080_u *field_7C[17];
};

// [G] N140: two dead 16-byte frame slots below the oriented box
struct UnkStruct_0021D080_pad { int x[8]; UnkStruct_0021D080_pad() {} ~UnkStruct_0021D080_pad() {} };

class CB3GraphicsManager;
extern CB3GraphicsManager D_00665EC0;
extern "C" void ConvertTo__20CGtSimpleOrientedBoxCFP14CGtOrientedBox(const UnkStruct_0021D080_sb *, UnkStruct_0021D080_ob *);

// [L] N185: zero xyz + y lane from another vector's w (compiler-chosen)
static inline CGtV3d DoUnitFrustumTesting_inl1(const CGtV3d &a) {
    u_long128 t;
    asm("vadd.xyz %0, $vf0, $vf0" : "=j"(t));
    asm("vaddw.y %0, $vf0, %1w" : "+j"(t) : "j"(a.mData));
    return CGtV3d(t);
}
// [L] N185: CGtV3d + CGtV3d on compiler-chosen registers
static inline CGtV3d DoUnitFrustumTesting_inl2(const CGtV3d &a, const CGtV3d &b) {
    u_long128 r;
    asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}

// 0x0021D080
void CB3StreamedTrack::DoUnitFrustumTesting()
{
    int i;
    int j;
    UnkStruct_0021D080_cam *cam;
    for (i = 0; i < 17; i++) {
        field_58[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        cam = &((UnkStruct_0021D080_gm *)&D_00665EC0)->field_470[i];
        int sh = i * 2;
        int mask = ~(3 << sh);
        for (j = 0; j < 17; j++) {
            UnkStruct_0021D080_u **pu = &field_7C[j];
            if (*pu == 0) goto none;
            int v;
            int r = GtIntersection::IntersectFrustum(*(const CGtFrustum *)cam, *(const CGtExtrudedBox *)(*pu)->field_10);
            if (r == 0) {
                v = 0;
            } else if (r == 2) {
                v = 1;
            } else {
                CGtSphere s;
                CGtV3d c[8];
                UnkStruct_0021D080_sb sb;
                UnkStruct_0021D080_ob ob;
                UnkStruct_0021D080_pad pad;
                s.SetPosition(cam->field_D0);
                s.SetRadius(100.0f);
                UnkStruct_0021D080_u *u = *pu;
                CGtV3d h = DoUnitFrustumTesting_inl1(u->field_10[0]);
                c[0] = u->field_10[0];
                c[1] = u->field_10[1];
                c[2] = u->field_10[2];
                c[3] = u->field_10[3];
                c[4] = DoUnitFrustumTesting_inl2(c[0], h);
                c[5] = DoUnitFrustumTesting_inl2(c[1], h);
                c[6] = DoUnitFrustumTesting_inl2(c[2], h);
                c[7] = DoUnitFrustumTesting_inl2(c[3], h);
                sb.field_0[0] = c[0];
                sb.field_0[1] = c[3];
                sb.field_0[2] = c[2];
                sb.field_0[3] = c[1];
                sb.field_0[4] = c[4];
                sb.field_0[5] = c[7];
                sb.field_0[6] = c[6];
                sb.field_0[7] = c[5];
                ConvertTo__20CGtSimpleOrientedBoxCFP14CGtOrientedBox(&sb, &ob);
                if (GtIntersection::IntersectSphere(s, *(const CGtOrientedBox *)&ob)) v = 3;
                else v = 2;
            }
            field_58[j] &= mask;
            field_58[j] |= (unsigned short)v << sh;
            continue;
        none:
            field_58[j] &= mask;
        }
    }
}
