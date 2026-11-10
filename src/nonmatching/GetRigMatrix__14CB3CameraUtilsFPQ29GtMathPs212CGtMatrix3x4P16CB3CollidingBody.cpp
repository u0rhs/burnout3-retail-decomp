// NONMATCHING: GetRigMatrix__14CB3CameraUtilsFPQ29GtMathPs212CGtMatrix3x4P16CB3CollidingBody -- retail 91 / ours 91 instructions, 6 in changed runs
// hdr8: rerouted to the N214 header / volatile dropped
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: GetRigMatrix__14CB3CameraUtilsFPQ29GtMathPs212CGtMatrix3x4P16CB3CollidingBody -- retail 91 / ours 91 instructions, 6 in changed runs
// hdr8: SetIdentity/Normalise from the header (stand-ins dropped).
// v241: logic+VU exact (sibling GetTrackMatrix queued exact with the same stand-ins); 6 off: dir copy at sp+0x80 vs retail 0x70 (retail slot order tmp A0, ?, ?, dir 70, ? 60 suggests dir is a temporary after the W-lane temp), and move s0,a0 fills the bc1f delay slot where retail hoists lw a0,0x204(a1)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

class CB3CollidingBody;
struct UnkStruct_002F6210_1 {
    unsigned char pad_0[0x18B4];
    void * field_18B4;
    unsigned short field_18B8;
};
struct UnkStruct_002F6370_1 {
    unsigned char pad_0[0x20];
    CGtV3d field_20;
};
class CB3CollidingBody {
public:
    unsigned char pad_0[0xB0];
    CGtSphere field_B0;
    CGtV3d field_C0;
    unsigned char pad_D0[0x134];
    UnkStruct_002F6370_1 * field_204;
};
class CB3RaceCarPhysics : public CB3CollidingBody {
public:
    unsigned char pad_210[0x13F4 - 0x210];
    UnkStruct_002F6210_1 * field_13F4;
};

extern "C" bool func_00148080(void * lane, unsigned short seg, CGtV3d * out);  // [L] CB3AILane::GetForwardsVector (retail_names low)
extern CGtV3d kAxisY;


struct UnkStruct_002F6210_pad { int x[8]; UnkStruct_002F6210_pad() {} ~UnkStruct_002F6210_pad() {} };
struct UnkStruct_002F6370_pad { int x[4]; UnkStruct_002F6370_pad() {} ~UnkStruct_002F6370_pad() {} };  // [G] N140 frame pad

static inline CGtV3d v241_cross(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b.mData) : "j"(a.mData));
    return CGtV3d(t);
}
// hdr8: CGtV3d::Normalise() (header) with the N140 frame pad [G] in an inline; v241_cross not volatile (hdr8 volatility rule).
static inline void func_002F6370_inl1(CGtV3d& v) { UnkStruct_002F6210_pad pad; v.Normalise(); }
class CB3CameraUtils {
public:
    static void GetTrackMatrix(CGtMatrix3x4 * m, CB3RaceCarPhysics * phys);
    static void GetRigMatrix(CGtMatrix3x4 * m, CB3CollidingBody * body);
    static void GetRigPosition(CGtV3d * p, CB3CollidingBody * body);
};

void CB3CameraUtils::GetRigMatrix(CGtMatrix3x4 * m, CB3CollidingBody * body)
{
    CGtV3d tmp;
    UnkStruct_002F6370_pad p;
    float r = body->field_B0.Radius();
    if (r < 0.1f)
        tmp = body->field_204->field_20;
    else
        tmp = body->field_C0;
    CGtV3d dir = tmp;
    m->SetIdentity();
    GetRigPosition(&m->mPos, body);
    m->mUp = kAxisY;
    if (GtMath::Abs(tmp.Y()) > 0.9f) {
        m->mAt.Set(0.0f, 0.0f, 1.0f);
    } else {
        m->mAt = dir;
        m->mAt.SetY(0.0f);
        func_002F6370_inl1(m->mAt);
    }
    m->mRight = v241_cross(m->mUp, m->mAt);
}








