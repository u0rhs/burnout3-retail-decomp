// NONMATCHING: ConvertTo__20CGtSimpleOrientedBoxCFP14CGtOrientedBox -- retail 64 / ours 64 instructions, 22 in changed runs
// a192: natural b119p 1.0 hoists now hoist (both) but get vf7 not retail's vf2 (the late-defined 1.0 takes a later VU reg than the hard-coded block); header SetNormal/SetDistance still forward sqc2->vmove instead of retail's addiu a0,v1,0x80 + lqc2; 23 changed, 62 vs 64
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: ConvertTo__20CGtSimpleOrientedBoxCFP14CGtOrientedBox -- retail 64 / ours 63 instructions, 19 in changed runs
// 19 off: VU body and both pinned 1.0 hoists (vf2, vf6) match; b119 (and b103) forward SetNormal's sqc2 vf4,0x80(v1) into SetDistance's reload as vmove.xyzw vf3,vf4, where retail/DNAT keep a separate addiu a0,v1,0x80 + lqc2 vf3,0(a0); asm/m/+j/cast/pointer forms all forward
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CGtOrientedBox;
class CGtSimpleOrientedBox {                // [C] layout: Revenge types.h (size 0x80)
public:
    CGtV3d maPoints[8];
    void ConvertTo(CGtOrientedBox* pBox) const;
};
class CGtOrientedBox : public CGtSimpleOrientedBox {   // [C] layout: Revenge types.h (size 0xE0)
public:
    CGtPlane maPlanes[6];
};
extern const signed char kaan8PointPlaneMap[6][4];   // [C] name: E map (GtOrientedBox.cpp); [G] element type

// 0x003D7F70
void CGtSimpleOrientedBox::ConvertTo(CGtOrientedBox* pBox) const
{
    for (int i = 0; i < 8; i++) pBox->maPoints[i] = maPoints[i];
    for (int i = 0; i < 6; i++) {
        const signed char* m = kaan8PointPlaneMap[i];
        u_long128 n, sq, t, d, one, one2, v1, v2;
        asm("qmtc2 %1, $vf4" "\n\t" "qmtc2 %2, $vf3" "\n\t" "qmtc2 %3, $vf1" "\n\t"
            "vsub.xyz $vf5, $vf4, $vf3" "\n\t" "vsub.xyz $vf1, $vf1, $vf3" "\n\t"
            "vopmula.xyz $ACC, $vf5, $vf1" "\n\t" "vopmsub.xyz $vf1, $vf1, $vf5" "\n\t" "qmfc2.i %0, $vf1"
            : "=r"(n) : "r"(pBox->maPoints[m[0]].mData), "r"(pBox->maPoints[m[1]].mData), "r"(pBox->maPoints[m[2]].mData));
        asm("qmtc2.i %1, $vf1" "\n\t" "vsub.xyz $vf3, $vf0, $vf1" "\n\t" "vmul.xyz $vf1, $vf3, $vf3" "\n\t"
            "vadday.x $ACC, $vf1, $vf1y" : "=r"(v1) : "r"(n));
        asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one));
        asm("vmaddz.x $vf1, %1, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(sq) : "j"(one));
        asm("qmtc2.i %1, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz $vf3, $vf3, $Q" "\n\t" "qmfc2.i %0, $vf3"
            : "=r"(n) : "r"(sq));
        asm("qmtc2.i %1, $vf3" "\n\t" "vmul.xyz $vf1, $vf4, $vf3" "\n\t" "vadday.x $ACC, $vf1, $vf1y" : "=r"(v2) : "r"(n));
        asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one2));
        asm("vmaddz.x $vf1, %1, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(d) : "j"(one2));
        pBox->maPlanes[i].SetNormal(CGtV3d(n));
        pBox->maPlanes[i].SetDistance(XAxisType(d));
    }
}
