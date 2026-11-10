// NONMATCHING: AddTrailSegment__15CB3TrailEmitterFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPCQ29GtMathPs212CGtMatrix3x4 -- retail 240 / ours 239 instructions, 139 in changed runs
// ghvu14: logic complete (Ghidra+asm); 186 changed: frame 0x2A0 vs 0x3B0 (retail has 16 more dead 16-byte slots + one small slot above d), Y/Z lane reads use addiu+lwc1 0(r) where retail folds lwc1 0x94(sp), data/i in t0/t3 vs a2/a1, li v0,1 order | N275 header APIs (gapK)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3TrailEmitter::AddTrailSegment(CGtV3d, CGtV3d, const CGtMatrix3x4*) -- hand-written (ghvu14, Ghidra draft + retail asm).
// [C] name: the mangled symbol in retail's tables; Area not evidenced, so _unclassified/ (docs/conventions.md).
// Emitter / point-data layout as the proven caller CB3TrailSystem::AddTrailSegment (B3TrailSystem_002BD320.cpp): time at +0,
// point data at +8 (16 CGtV3dPlus points, 16 x 3 colour bytes at +0x100), point count +0x10, flags +0x12. Every type and field
// name is [G] (instruction widths). ghvu14: the new point (pos + D_004C1CD0, through the matrix if given) is appended, or
// replaces the last point when the trail runs straight on (cos > 0.9995); the colour bytes are the side vector * 127.

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522680 D_00522680;
struct UnkStruct_D_004C1CD0 { CGtV3d field_0; };
extern UnkStruct_D_004C1CD0 D_004C1CD0;

struct UnkStruct_002BCF60_data {
    CGtV3dPlus field_0[16];
    signed char field_100[16][3];
};
struct UnkStruct_002BCF60_pad { int x[4]; UnkStruct_002BCF60_pad() {} ~UnkStruct_002BCF60_pad() {} };
class CB3TrailEmitter {
public:
    bool AddTrailSegment(CGtV3d, CGtV3d, const CGtMatrix3x4 *);

    float field_0;
    void * field_4;
    UnkStruct_002BCF60_data * field_8;
    unsigned char pad_C[4];
    signed char field_10;
    signed char field_11;
    unsigned char field_12;
};

// [L] N185: normalise in place on a compiler-chosen register (no 1.0 * Q tail), the squared length through a GPR onto $vf1.
static inline void func_002BCF60_inl1(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" : : "r"(l.lVector));
    asm(".set reorder");
    u_long128 t;
    asm("vmulq.xyz %1, %1, $Q" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(v.mData));
    v.mData = t;
}
// [L] N185: CrossProduct (header body) with the result moved out `.i` (retail keeps qmfc2 + sq, v241).
static inline CGtV3d func_002BCF60_inl2(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b.mData) : "j"(a.mData));
    return CGtV3d(t);
}

// [L] N185: a + b on compiler-chosen registers
static inline CGtV3d func_002BCF60_inl3(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r = a.mData;
    asm("vadd.xyz %0, %0, %1" : "+j"(r) : "j"(b.mData));
    return CGtV3d(r);
}

// 0x002BCF60
bool CB3TrailEmitter::AddTrailSegment(CGtV3d pos, CGtV3d dir, const CGtMatrix3x4 *m)
{
        CGtV3d d = dir;
    CGtV3d p = func_002BCF60_inl3(pos, D_004C1CD0.field_0);
    float now = D_00522680.field_0;
    CGtV3d side;
    if (m) p = TransformPoint(*m, p);
    int n = field_10;
    if (n != 0) {
        UnkStruct_002BCF60_data *data = field_8;
        int i = n - 1;
        CGtV3d last = data->field_0[i].mData;
        CGtV3d diff = p - last;
        if (diff.IsEffectivelyZero()) return 0;
        func_002BCF60_inl1(diff);
        side = func_002BCF60_inl2(diff, d);
        if (n == 1 && !(field_12 & 2)) {
            CGtV3d c = side * 127.5f;
            data->field_100[0][0] = (int)c.X();
            data->field_100[0][1] = (int)c.Y();
            data->field_100[0][2] = (int)c.Z();
        } else {
            CGtV3d e = last - CGtV3d(field_8->field_0[field_10 - 2].mData);
            float len = e.GetLength();
            if (DotProduct(diff, e) > 0.9995f * len) {
                field_8->field_0[i].SetGtV3d(p);
                CGtV3d c = side * 127.5f;
                signed char *b = i * 3 + (signed char *)field_8->field_100;
                b[0] = (int)c.X();
                b[1] = (int)c.Y();
                b[2] = (int)c.Z();
                field_8->field_0[i].SetPlus(now);
                field_0 = now;
                return 1;
            }
        }
    }
    CGtV3d c = side * 127.5f;
    field_8->field_0[field_10].SetGtV3d(p);
    signed char *b = field_10 * 3 + (signed char *)field_8->field_100;
    b[0] = (int)c.X();
    b[1] = (int)c.Y();
    b[2] = (int)c.Z();
    field_8->field_0[field_10].SetPlus(now);
    field_10++;
    field_0 = now;
    return 1;
}
