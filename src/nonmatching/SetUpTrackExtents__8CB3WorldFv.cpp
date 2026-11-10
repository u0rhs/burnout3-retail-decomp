// NONMATCHING: SetUpTrackExtents__8CB3WorldFv -- retail 169 / ours 177 instructions, 108 in changed runs
// fix1 (2026-11-01): port6 checker/replay found two source errors, fixed: whole scan/extent block skipped when the segment count <= 0 [C retail 0x199788 blez], and pad_12ACFC was 0x2000 too long (stores at this+0x145810). Before: logic believed right (max u16 index scan, then min/max bbox of points[0..mx] into D_00143820/30 and centre (min+max)*0.5 into D_00143810), 137 off: retail's lane copies take the source q in a compiler-chosen vf2 qmtc2.ni'd in the branch delay slot (header SetX(XAxisType) uses vf1/vf2 swapped), frame 0x1B0 vs 0x110 (dead lane-copy slots), saved s0/s1, offset constants via lui/ori
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [C] fix1 (2026-11-01): the 5 port6 live captures (port6-e1/e97) pass the Burn3 checker at tolerance 0 (5/5) and replay identical on the host (the port project capture_replay; f0 is scratch here) -- on those inputs


#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// [L] N185: lane copy on a compiler-chosen destination, source a compiler-chosen register (retail's inlined SetX/Y/Z(XAxisType..) here)
static inline void SetLX(CGtV3d &d, u_long128 s) { u_long128 t = d.mData; asm("vaddx.x %0, $vf0, %1x" : "+j"(t) : "j"(s)); d.mData = t; }
static inline void SetLY(CGtV3d &d, u_long128 s) { u_long128 t = d.mData; asm("vaddy.y %0, $vf0, %1y" : "+j"(t) : "j"(s)); d.mData = t; }
static inline void SetLZ(CGtV3d &d, u_long128 s) { u_long128 t = d.mData; asm("vaddz.z %0, $vf0, %1z" : "+j"(t) : "j"(s)); d.mData = t; }
struct UnkStruct_00199770_pair { unsigned short field_0; unsigned short field_2; };
struct UnkStruct_00199770_seg {
    UnkStruct_00199770_pair * field_0;
    unsigned char pad_4[0x8];
    unsigned short field_C;
    unsigned char pad_E[0x2];
};
class CB3World {
public:
    void SetUpTrackExtents();
    unsigned char pad_0[0x12ACE8];
    UnkStruct_00199770_seg * field_12ACE8;
    unsigned char pad_12ACEC[0x8];
    CGtV3d * field_12ACF4;
    int field_12ACF8;
    unsigned char pad_12ACFC[0x18B14];   // fix1: was 0x1AB14 (put field_143810 at 0x145810) [C] retail 0x19984C lui 0x14 + ori 0x3830
    CGtV3d field_143810;
    CGtV3d field_143820;
    CGtV3d field_143830;
};

// 0x00199770
void CB3World::SetUpTrackExtents()
{
    int n = field_12ACF8;
    // [C] retail 0x199788 `blez $t0, .L00199968`: no segments -> no scan, the extents keep their old values, only the centre is recomputed
    if (n > 0) {
    int mx = 0;
    for (int i = 0; i < n; i++) {
        UnkStruct_00199770_seg * s = &field_12ACE8[i];
        for (int j = 0; j < s->field_C + 1; j++) {
            UnkStruct_00199770_pair * p = &s->field_0[j];
            if (mx < p->field_0) mx = p->field_0;
            if (mx < p->field_2) mx = p->field_2;
        }
    }
    field_143820 = field_12ACF4[0];
    field_143830 = field_12ACF4[0];
    for (int k = 1; k <= mx; k++) {
        CGtV3d q = field_12ACF4[k];
        if (!((float)q.X() <= (float)field_143830.X())) SetLX(field_143830, q.mData);
        if (!((float)q.Y() <= (float)field_143830.Y())) SetLY(field_143830, q.mData);
        if (!((float)q.Z() <= (float)field_143830.Z())) SetLZ(field_143830, q.mData);
        if ((float)q.X() < (float)field_143820.X()) SetLX(field_143820, q.mData);
        if ((float)q.Y() < (float)field_143820.Y()) SetLY(field_143820, q.mData);
        if ((float)q.Z() < (float)field_143820.Z()) SetLZ(field_143820, q.mData);
    }
    }
    field_143810 = (field_143820 + field_143830) * 0.5f;
}
