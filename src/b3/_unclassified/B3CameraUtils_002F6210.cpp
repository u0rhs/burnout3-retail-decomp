// CB3CameraUtils::GetTrackMatrix(GtMathPs2::CGtMatrix3x4*,CB3RaceCarPhysics*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraUtils.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (.i CrossProduct, N140 pad).

// CB3CameraUtils::GetTrackMatrix(GtMathPs2::CGtMatrix3x4*, CB3RaceCarPhysics*) -- hand-matched (v241).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3CameraUtils.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders; types [G] from instruction widths.
// Body: identity matrix (CGtMatrix3x4::SetIdentity, header, B3O0PCH map), GetRigPosition into the position row, up = kAxisY,
// at = the lane's forwards vector with y cleared and normalised (CGtV3d::Normalise, header; or +Z when it is near vertical),
// right = up x at. hdr8: SetIdentity/Normalise from the header (was V241_* macros and v241_normalise).
// x/y/z = (0, 0, 1) is one CGtV3d::Set(float,float,float) call [L] (B3O0PCH map name; hdr8: the chain needs the vector numbered
// after both scalars, which separate SetX/SetY/SetZ calls don't give).
// [L] N185 stand-in left: CrossProduct with a `.i` result move (retail keeps `qmfc2; sq`, N190; the header's .ni folds into sqc2).
// The 32-byte UnkStruct_002F6210_pad in func_002F6210_inl1 is an N140 frame pad [G] (retail frame 0x90).

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


struct UnkStruct_002F6210_pad { int x[8]; UnkStruct_002F6210_pad() {} ~UnkStruct_002F6210_pad() {} };  // [G] N140 frame pad

// [C] not `asm volatile`: a volatile asm parsed before this file's inline expansions makes every earlier-defined inline's
// asm volatile (hdr8, docs/known.md), which broke the header's CGtMatrix3x4::SetIdentity here.
static inline CGtV3d v241_cross(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b.mData) : "j"(a.mData));
    return CGtV3d(t);
}
// CGtV3d::Normalise() (header) with the N140 frame pad [G] (retail frame 0x90) in an inline, as before.
static inline void func_002F6210_inl1(CGtV3d& v) { UnkStruct_002F6210_pad pad; v.Normalise(); }
class CB3CameraUtils {
public:
    static void GetTrackMatrix(CGtMatrix3x4 * m, CB3RaceCarPhysics * phys);
    static void GetRigPosition(CGtV3d * p, CB3CollidingBody * body);
};

// 0x002F6210
void CB3CameraUtils::GetTrackMatrix(CGtMatrix3x4 * m, CB3RaceCarPhysics * phys)
{
    CGtV3d fwd;
    func_00148080(phys->field_13F4->field_18B4, phys->field_13F4->field_18B8, &fwd);
    CGtV3d dir = fwd;
    m->SetIdentity();
    GetRigPosition(&m->mPos, phys);
    m->mUp = kAxisY;
    if (GtMath::Abs(dir.Y()) > 0.9f) {
        m->mAt.Set(0.0f, 0.0f, 1.0f);
    } else {
        m->mAt = dir;
        m->mAt.SetY(0.0f);
        func_002F6210_inl1(m->mAt);
    }
    m->mRight = v241_cross(m->mUp, m->mAt);
}
