// NONMATCHING: AddScrapeSegment__16CB3ScrapeEmitterFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPCQ29GtMathPs212CGtMatrix3x4 -- retail 149 / ours 149 instructions, 48 in changed runs
// v257: logic and block layout complete (y += 0.0254, local segment struct {CGtV3dPlus pos+time, CGtV3dPlus dir}, optional TransformPoint, merge with the last segment when |d|^2 >= 2^-32 and Dot(normalised cross) > 0.99999, else append + SetPlus(count)); 149/149, 48 changed: float numbering now f2 vs retail f1, the 2^-32 / 0.99999 constants scheduled into the VU gaps (retail keeps them after qmfc2/mtc1), buf/last base registers, frame 0x60 vs 0xD0 (dead slots of by-value inline params)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_003755E0_seg { CGtV3dPlus field_0; CGtV3dPlus field_10; };
struct UnkStruct_003755E0_buf { int field_0; unsigned char pad_4[0xC]; UnkStruct_003755E0_seg field_10[16]; };
class CB3ScrapeEmitter {
public:
    int AddScrapeSegment(CGtV3d, CGtV3d, const CGtMatrix3x4 *);
    int field_0;
    float field_4;
    unsigned char pad_8[8];
    short field_10;
    unsigned char pad_12[0x432];
    UnkStruct_003755E0_buf * field_444;
};
struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522680 D_00522680;
// [L] N185 stand-ins (compiler-chosen VU registers; the 1.0 parked in a GPR)
static inline YAxisType func_003755E0_inl1(YAxisType a, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, %1, %0x" : "+j"(s) : "j"(a.lVector)); return YAxisType(s); }
static inline void func_003755E0_inl2(CGtV3dPlus &d, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubw.w %0, $vf0, $vf0w" "\n\t" "vaddx.w %0, %0, %1x" : "+j"(d.mData) : "j"(s)); }
static inline u_long128 func_003755E0_inl3() { u_long128 o, one; asm("vaddw.x %0, $vf0, $vf0w" : "=j"(o)); asm("qmfc2.i %0, %1" : "=r"(one) : "j"(o)); return one; }
static inline float func_003755E0_inl4(u_long128 a, u_long128 b)
{
    u_long128 one = func_003755E0_inl3();
    u_long128 m, d;
    asm("vmul.xyz %0, %1, %2" "\n\t" "vadday.x $ACC, %0, %0y" : "=j"(m) : "j"(a), "j"(b));
    u_long128 w;
    asm("qmtc2.i %2, %1" "\n\t" "vmaddz.x %1, %1, %3z" "\n\t" "qmfc2.i %0, %1" : "=r"(d), "=&j"(w) : "r"(one), "j"(m));
    return XAxisType(d);
}
static inline u_long128 func_003755E0_inl5(u_long128 a)
{
    u_long128 one = func_003755E0_inl3();
    u_long128 m, d;
    asm("vmul.xyz %0, %1, %1" "\n\t" "vadday.x $ACC, %0, %0y" : "=j"(m) : "j"(a));
    u_long128 w;
    asm("qmtc2.i %2, %1" "\n\t" "vmaddz.x %1, %1, %3z" "\n\t" "qmfc2.i %0, %1" : "=r"(d), "=&j"(w) : "r"(one), "j"(m));
    return d;
}
static inline u_long128 func_003755E0_inl6(u_long128 a)
{
    u_long128 l = func_003755E0_inl5(a);
    u_long128 t, v = a;
    asm volatile("qmtc2.i %2, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t"
        "vmulq.xyz %1, %1, $Q" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(v) : "r"(l));
    return t;
}
static inline CGtV3d func_003755E0_inl7(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm volatile("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b.mData) : "j"(a.mData));
    return CGtV3d(t);
}
static inline u_long128 func_003755E0_inl8(u_long128 a, u_long128 b) { asm("vsub.xyz %0, %0, %1" : "+j"(a) : "j"(b)); return a; }

// 0x003755E0
int CB3ScrapeEmitter::AddScrapeSegment(CGtV3d pos, CGtV3d dir, const CGtMatrix3x4 * m)
{
    UnkStruct_003755E0_seg s;
    CGtV3d p = pos;
    CGtV3d d = dir;
    float now = D_00522680.field_0;
    field_10 |= 1;
    p.SetY(func_003755E0_inl1(p.Y(), 0.0254f));
    s.field_0.SetGtV3d(p);
    func_003755E0_inl2(s.field_10, now);
    if (m)
        s.field_0.SetGtV3d(TransformPoint(*m, CGtV3d(s.field_0.mData)));
    UnkStruct_003755E0_buf * buf = field_444;
    int n = buf->field_0;
    if (n != 0) {
        u_long128 df = func_003755E0_inl8(s.field_0.mData, buf->field_10[n - 1].field_0.mData);
        if (func_003755E0_inl4(df, df) < 2.3283064e-10f)
            goto fail;
        s.field_10.SetGtV3d(func_003755E0_inl7(CGtV3d(func_003755E0_inl6(df)), d));
        if (n == 1 && !(field_10 & 2)) {
            buf->field_10[0].field_10 = s.field_10;
        } else if (!(func_003755E0_inl4(buf->field_10[n - 1].field_10.mData, s.field_10.mData) <= 0.99999f)) {
            buf->field_10[n - 1] = s;
            field_4 = now;
            return 1;
        }
    }
    {
        UnkStruct_003755E0_buf * nb = field_444;
        nb->field_10[nb->field_0].field_0 = s.field_0;
        nb->field_10[nb->field_0].field_10 = s.field_10;
        nb->field_0++;
    }
    func_003755E0_inl2(field_444->field_10[0].field_0, (float)field_444->field_0);
    field_4 = now;
    return 1;
fail:
    return 0;
}
