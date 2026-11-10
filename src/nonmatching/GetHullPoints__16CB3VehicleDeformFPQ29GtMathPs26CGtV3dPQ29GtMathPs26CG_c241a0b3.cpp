// NONMATCHING: GetHullPoints__16CB3VehicleDeformFPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dP13CB3ConvexHullPQ29GtMathPs26CGtV3d -- retail 676 / ours 675 instructions, 633 in changed runs
// draftAK C-first: corner pairs from the deform data (lowered by half the scaled extent, uppers field_28..34 above), four FindPointNearestTo box-fraction points (p5/p7 clamped to +0x7F0's Y), windscreen quad from GetWindscreenPos(true/false) fractions (bones 7/6, redone with bone 8 at the box top when a pair is < 0.05 apart; spread +-0.1 in z when narrower than 0.2), p6/p8 pulled to the windscreen; 675/676, calls identical (FindPointNearestTo through its link name with retail's real list: CGtV3d* fraction, hull, points, bone, out); left: retail reloads the stack arguments per call, frame 0x550 vs 0x6E0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra draft as a reading aid); every call argument, lane store and compare traced; retail's p8 test uses the LEFT edge normal first (nLeft . (p8 - p14)) -- kept; the box-fraction locals' w lanes are stack garbage as retail

// CB3VehicleDeform::GetHullPoints(CGtV3d* x16, CB3ConvexHull*, CGtV3d*) -- draftAK (C-first draft). 0x3D9E90, 0xA90.
// [C] name: the mangled symbol in retail's tables. Written from the retail asm (Ghidra's draft as a reading aid).
// FindPointNearestTo's real argument list ([C] the proven B3VehicleDeform_003DA920.cpp): a CGtV3d fraction of the vehicle
// box by address (not the E map's three floats), the hull, the hull's points, a bone index, the result.
// What it does [L]: fills 16 hull points for the deformation:
//  - p1..p4 / p9..p12: four corner pairs from the deform data (field_14 +0x830 / 0x770 / 0x870 / 0x7B0); each pair's lower
//    point is lowered by half its extent (+0x810 / 0x750 / 0x850 / 0x790, scaled by field_28..34) and the upper one sits
//    field_28..34 above it (Y only);
//  - p5..p8: the hull points nearest to four fixed box fractions (D_004CADB0..E0, bone 8); p5 / p7 clamped to the height
//    field_14+0x7F0's Y;
//  - p13..p16: the hull points nearest to the windscreen's top / bottom positions (as box fractions: x 1 / 0, y 1, z from
//    GetWindscreenPos(true / false, false)), bones 7 / 6; when a pair comes out closer than 0.05 they are redone with bone 8
//    and all four put at the box top (E80.Y);
//  - the windscreen quad is kept at least 0.2 wide (else spread +-0.1 in z around p13), and p6 / p8 are pulled to the
//    windscreen (Y = 0.4 * p5/p7 + 0.6 * p13/p14) when they lie behind its edges.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

extern CGtV3d D_004CADB0;   // [G] box fractions (zero in the ELF: built at run time)
extern CGtV3d D_004CADC0;
extern CGtV3d D_004CADD0;
extern CGtV3d D_004CADE0;

class CB3ConvexHull;
struct UnkStruct_003D9E90_dim { unsigned char pad_0[0xE80]; CGtV3d field_E80; CGtV3d field_E90; };   // [G] box max / min
struct UnkStruct_003D9E90_p { unsigned char pad_0[0x40]; UnkStruct_003D9E90_dim *field_40; };
struct UnkStruct_003D9E90_d {               // [G] the deform data
    unsigned char pad_0[0x750];
    CGtV3d field_750;
    CGtV3d field_760;
    CGtV3d field_770;
    unsigned char pad_780[0x10];
    CGtV3d field_790;
    unsigned char pad_7A0[0x10];
    CGtV3d field_7B0;
    unsigned char pad_7C0[0x30];
    CGtV3d field_7F0;
    unsigned char pad_800[0x10];
    CGtV3d field_810;
    unsigned char pad_820[0x10];
    CGtV3d field_830;
    unsigned char pad_840[0x10];
    CGtV3d field_850;
    unsigned char pad_860[0x10];
    CGtV3d field_870;
};

class CB3VehicleDeform {
public:
    void GetHullPoints(CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *,
                       CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, CB3ConvexHull *, CGtV3d *);
    CGtV3d GetWindscreenPos(bool, bool);

    unsigned char pad_0[0x10];
    UnkStruct_003D9E90_p *field_10;
    UnkStruct_003D9E90_d *field_14;
    unsigned char pad_18[0x10];
    float field_28;
    float field_2C;
    float field_30;
    float field_34;
};

extern "C" void FindPointNearestTo__16CB3VehicleDeformFfffP13CB3ConvexHullPQ29GtMathPs26CGtV3d18EMainBodyBoneIndexPQ29GtMathPs26CGtV3d(CB3VehicleDeform *self, const CGtV3d *v, CB3ConvexHull *hull, CGtV3d *pts, int bone, CGtV3d *out);
#define FIND_NEAREST FindPointNearestTo__16CB3VehicleDeformFfffP13CB3ConvexHullPQ29GtMathPs26CGtV3d18EMainBodyBoneIndexPQ29GtMathPs26CGtV3d


void CB3VehicleDeform::GetHullPoints(CGtV3d *p1, CGtV3d *p2, CGtV3d *p3, CGtV3d *p4, CGtV3d *p5, CGtV3d *p6, CGtV3d *p7,
                                     CGtV3d *p8, CGtV3d *p9, CGtV3d *p10, CGtV3d *p11, CGtV3d *p12, CGtV3d *p13,
                                     CGtV3d *p14, CGtV3d *p15, CGtV3d *p16, CB3ConvexHull *hull, CGtV3d *pts)
{
    *p1 = field_14->field_830;
    *p9 = field_14->field_770;
    *p3 = field_14->field_870;
    *p11 = field_14->field_7B0;
    *p2 = *p1;
    *p10 = *p9;
    *p4 = *p3;
    *p12 = *p11;

    float y[4];
    UnkStruct_003D9E90_d *d = field_14;
    y[0] = (*p1 - d->field_810 * 0.5f * field_28).Y();
    y[1] = (*p9 - d->field_750 * 0.5f * field_2C).Y();
    y[2] = (*p3 - d->field_850 * 0.5f * field_30).Y();
    y[3] = (*p11 - d->field_790 * 0.5f * field_34).Y();
    p1->SetY(y[0]);
    p9->SetY(y[1]);
    p3->SetY(y[2]);
    p11->SetY(y[3]);
    p2->SetY(y[0] + field_28);
    p10->SetY(y[1] + field_2C);
    p4->SetY(y[2] + field_30);
    p12->SetY(y[3] + field_34);

    FIND_NEAREST(this, &D_004CADB0, hull, pts, 8, p5);
    FIND_NEAREST(this, &D_004CADC0, hull, pts, 8, p6);
    FIND_NEAREST(this, &D_004CADD0, hull, pts, 8, p7);
    FIND_NEAREST(this, &D_004CADE0, hull, pts, 8, p8);
    CGtV3d top = field_14->field_7F0;
    p5->SetY(GtMath::Min(top.Y(), p5->Y()));
    p7->SetY(GtMath::Min(top.Y(), p7->Y()));

    float len = field_10->field_40->field_E80.Z() - field_10->field_40->field_E90.Z();
    CGtV3d ws = GetWindscreenPos(true, false);
    float zTop = (0.5f * (float)ws.Z() - field_10->field_40->field_E90.Z()) / len;
    CGtV3d ws2 = GetWindscreenPos(false, false);
    float zBot = (0.5f * (float)ws2.Z() - field_10->field_40->field_E90.Z()) / len;
    CGtV3d f13;                             // [C] w lanes never written (stack garbage, as retail)
    CGtV3d f14;
    CGtV3d f15;
    CGtV3d f16;
    f13.SetX(1.0f);
    f13.SetY(1.0f);
    f13.SetZ(zTop);
    f14.SetX(0.0f);
    f14.SetY(1.0f);
    f14.SetZ(zTop);
    f15.SetX(1.0f);
    f15.SetY(1.0f);
    f15.SetZ(zBot);
    f16.SetX(0.0f);
    f16.SetY(1.0f);
    f16.SetZ(zBot);
    FIND_NEAREST(this, &f13, hull, pts, 7, p13);
    FIND_NEAREST(this, &f14, hull, pts, 7, p14);
    FIND_NEAREST(this, &f15, hull, pts, 6, p15);
    FIND_NEAREST(this, &f16, hull, pts, 6, p16);

    float k = 0.05f;
    if ((*p13 - *p14).GetLength() < k || (*p15 - *p16).GetLength() < k) {
        FIND_NEAREST(this, &f13, hull, pts, 8, p13);
        FIND_NEAREST(this, &f14, hull, pts, 8, p14);
        FIND_NEAREST(this, &f15, hull, pts, 8, p15);
        FIND_NEAREST(this, &f16, hull, pts, 8, p16);
        float h = field_10->field_40->field_E80.Y();
        p13->SetY(h);
        p14->SetY(h);
        p15->SetY(h);
        p16->SetY(h);
    }

    CGtV3d right = *p14 - *p16;
    ((float *)&right)[3] = ((const float *)p16)[3]; // [C] 0x3DA468 lqc2 vf1, 0(a0) (a0 = p16, from 0x720(sp)); 0x3DA478
    // vsub.xyz vf1, vf2, vf1 keeps p16's w; 0x3DA47C sqc2 vf1, 0x680(sp) -- `a - b` took p14's w
    CGtV3d c15 = *p15;
    CGtV3d left = *p13 - c15;
    if (left.GetLength() < 0.2f || right.GetLength() < 0.2f) {
        p13->SetZ(p13->Z() + 0.1f);
        p15->SetZ(p13->Z() - 0.1f);
        p14->SetZ(p13->Z() + 0.1f);
        p16->SetZ(p13->Z() - 0.1f);
        c15 = *p15;
        left = *p13 - c15;
        ((float *)&left)[3] = ((const float *)&c15)[3]; // [C] 0x3DA848 qmtc2 v1, vf2 (c15 = *p15); 0x3DA84C vsub.xyz vf2, vf3, vf2
        // keeps c15's w; 0x3DA858 sqc2 vf2, 0x690(sp) -- `a - b` took p13's w (the first `left` at 0x3DA48C keeps p13's: no change)
        right = *p14 - *p16;
    }

    CGtV3d nLeft = left;
    nLeft.Normalise();
    if (DotProduct(nLeft, *p6 - *p13) < k || DotProduct(nLeft, *p6 - c15) < k) {
        *p6 = *p5;
        p6->SetY(p5->Y() * 0.4f + p13->Y() * 0.6f);
    }
    CGtV3d nRight = right;
    nRight.Normalise();
    // [C] retail tests p8 against nLeft first and nRight second (sp+0x80 = nLeft at 0x3DA658): kept as is.
    if (DotProduct(nLeft, *p8 - *p14) < k || DotProduct(nRight, *p8 - *p16) < k) {
        *p8 = *p7;
        p8->SetY(p7->Y() * 0.4f + p14->Y() * 0.6f);
    }
}
