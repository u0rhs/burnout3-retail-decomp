// NONMATCHING: func_0019C120 -- retail 1061 / ours 1069 instructions, 599 in changed runs
// draftL: 1061/1069, 599 changed (mnemonic hunks 97/386); calls, branch senses, VU op counts identical; residue: the lane-end left-extension block is laid out out of line (bnez to the end) where retail keeps it inline (both inlined copies, ~59 instrs each; int/bool/empty-then/helper forms negative), quad's laPoints addresses in s-registers only partly reproduced (const pointer locals), frame 0x380 vs 0x240
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: slice tracking with lap wrap-around, fade alpha, lane walk-back + IncrementSegmentIndexClamped(-15), per-segment quad / triangles / tristrips (8 AddTristrip sites) and the func_0019B770 tail accounted for branch by branch

// func_0019C120 -- draftL (0x19C120, 0x1094) -- [L] CB3WrongWayWall::Update(CB3RaceCar*) (research/proto/new_names.csv, low; in
// B3WrongWayWall.cpp [C asm: after CB3WrongWayWall::Release 0x19B760 / func_0019B770, before AddTristrip 0x19D1C0]). The second
// parameter is a player-car INDEX here (x0x27D0 into the car table at D_00522660+0x12AD50), not a pointer [C asm]. Revenge's
// CB4WrongWayWall::Update (B4WrongWayWall.cpp; AI lane system reworked) gives hints only: laPoints[4], static lColourOpaque,
// lrWallDist, lrRaceCarPrevSliceDist / NextSliceDist / Dist, lrLapLength, lbLeft / lbRight, lnSliceDifference [L].
// What it does [L, from the asm]: tracks the slice the wall sits on (it follows the car forward, with lap wrap-around), fades the
// wall colour in over the last 20 units (alpha up to 0.2), then from 15 segments back along the wall's lane chain builds the wall:
// per segment two collision triangles (+0 array, when the car is within 6 slices) and a tristrip (AddTristrip), with 15-unit
// fade-out extensions at lane ends (segment kind 5). Types/fields [G] (instruction widths), structs after func_0019B770's archive.
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_0019C120_pair { unsigned short field_0; unsigned short field_2; };          // vertex indices of a segment edge
struct UnkStruct_0019C120_seg {                                                               // 10-byte lane segment record
    short field_0;
    unsigned char pad_2[0x1];
    unsigned char field_3;      // low 3 bits: segment kind (5 = lane end)
    unsigned char field_4;      // previous lane (0xFF = none)
    unsigned char field_5;      // next lane (0xFF = none)
    unsigned short field_6;     // previous segment
    unsigned short field_8;     // next segment
};
struct UnkStruct_0019C120_ls { UnkStruct_0019C120_pair * field_0; unsigned char pad_4[0x4]; UnkStruct_0019C120_seg * field_8; };
class CB3AILane {
public:
    unsigned char pad_0[0x4];
    UnkStruct_0019C120_ls * field_4;
};
struct UnkStruct_0019C120_tri { CGtV3d field_0; CGtV3d field_10; CGtV3d field_20; CGtV3d field_30; };
struct UnkStruct_0019C120 {
    UnkStruct_0019C120_tri field_0[42];
    UnkStruct_0019C120_tri field_A80[42];      // func_0019B770's triangles
    unsigned char pad_1500[0xA80];
    int field_1F80;
    int field_1F84;
    int field_1F88;
    CB3AILane * field_1F8C;
    unsigned short field_1F90;
    int field_1F94;
    bool field_1F98;
    bool field_1F99;
};
struct UnkStruct_0019C120_car {                 // player-car record, 0x27D0 bytes
    unsigned char pad_0[0x18B4];
    CB3AILane * field_18B4;     // lane
    unsigned short field_18B8;  // segment
    float field_18BC;           // position within the slice (0..1)
    int field_18C0;             // slice
    unsigned char pad_18C4[0x26];
    unsigned char field_18EA;
    unsigned char pad_18EB[0xEE5];
};
struct UnkStruct_0019C120_w {
    unsigned char pad_0[0x2C];
    CB3AILane field_2C[1];                  // [G] count unknown
    unsigned char pad_34[0x12AD1C];
    UnkStruct_0019C120_car field_12AD50[1]; // [G] count unknown
};
struct UnkStruct_0019C120_sl { float field_0; unsigned char pad_4[0x4]; };   // 8-byte slice rows: distance along the lap at +0
struct UnkStruct_0019C120_gv { CGtV3d * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_0019C120_w D_00522660;
extern UnkStruct_0019C120_gv D_0064D354;
extern UnkStruct_0019C120_sl * D_0064D364;
extern int D_0064D368;                  // slice count
extern unsigned char D_0064D378;        // [G] non-circuit track flag
extern signed char D_004E26B8;          // static-init guard of D_00665EB0
extern CGtV4d D_00665EB0;               // [L] Revenge `static CGtRGBA lColourOpaque`

extern "C" unsigned short IncrementSegmentIndexClamped__9CB3AILaneCFUss(const CB3AILane *, unsigned short, short);
extern "C" void func_0019B770(UnkStruct_0019C120 *, int);
// [L] CB3WrongWayWall::AddTristrip(CGtV3d x4, CGtV4d x4) (new_names.csv, low): by-value parameters passed as the objects' addresses
extern "C" void func_0019D1C0(UnkStruct_0019C120 *, const CGtV3d *, const CGtV3d *, const CGtV3d *, const CGtV3d *,
                              const CGtV4d *, const CGtV4d *, const CGtV4d *, const CGtV4d *);

// [L] N185 stand-in: CGtV3d::operator-(const CGtV3d&) on compiler-chosen registers (as func_0019B770)
static inline CGtV3d func_0019C120_inl1(const CGtV3d& a, const CGtV3d& b)
{
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
// [L] N256 open item stand-in: CrossProduct(a, b) with the result written over a's register (as func_0019B770)
static inline void func_0019C120_inl2(CGtV3d& d, CGtV3d a, CGtV3d b)
{
    asm(".set noreorder");
    asm("vopmula.xyz $ACC, %1, %2" "\n\t" "vopmsub.xyz %1, %2, %1" "\n\t" "qmfc2.i %0, %1" : "=r"(d.mData), "+j"(a.mData), "+j"(b.mData));
    asm(".set reorder");
}
// [G] CGtV4d::SetW(float) in its vmulx.w form (as draftI's func_002E2730_sw)
static inline void func_0019C120_inl3(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.i %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.w %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
// [G] is slice b ahead of slice a (wrap-around on circuits)
static inline bool func_0019C120_inl4(int a, int b)
{
    if (D_0064D378)
        return a < b;
    if (a < b)
        return b - a < D_0064D368 / 2;
    return D_0064D368 / 2 < a - b;
}
// [G] distance along the lap at the start of slice i
static inline float func_0019C120_inl5(int i)
{
    if (i == 0)
        return 0.0f;
    return D_0064D364[i - 1].field_0;
}

// [G] one lane segment of the wall: the edge raised by 20 / lowered by 5, two collision triangles when the car is near,
// then the tristrip (lane ends: 15-unit fade-out extensions)
static inline void func_0019C120_inl6(UnkStruct_0019C120 * self, const CB3AILane * lane, unsigned short seg, CGtV3d * laPoints, const CGtV4d * lTransparent)
{
    UnkStruct_0019C120_pair * e = &lane->field_4->field_0[seg];
    if (e->field_0 != e->field_2) {
        CGtV3d * const p1 = &laPoints[1];
        CGtV3d * const p2 = &laPoints[2];
        CGtV3d * const p3 = &laPoints[3];
        laPoints[0] = D_0064D354.field_0[e->field_0];
        *p1 = D_0064D354.field_0[e->field_2];
        *p2 = laPoints[0];
        *p3 = *p1;
        laPoints[0].SetY(laPoints[0].Y() + -5.0f);
        p2->SetY(p2->Y() + 20.0f);
        p1->SetY(p1->Y() + -5.0f);
        p3->SetY(p3->Y() + 20.0f);
        if (self->field_1F99) {
            self->field_0[self->field_1F80].field_0 = laPoints[0];
            self->field_0[self->field_1F80].field_10 = *p1;
            self->field_0[self->field_1F80].field_20 = *p2;
            func_0019C120_inl2(self->field_0[self->field_1F80].field_30, func_0019C120_inl1(*p2, laPoints[0]), func_0019C120_inl1(*p1, laPoints[0]));
            self->field_0[self->field_1F80].field_30.Normalise();
            self->field_1F80++;
            self->field_0[self->field_1F80].field_0 = *p2;
            self->field_0[self->field_1F80].field_10 = *p1;
            self->field_0[self->field_1F80].field_20 = *p3;
            func_0019C120_inl2(self->field_0[self->field_1F80].field_30, func_0019C120_inl1(*p3, *p2), func_0019C120_inl1(*p1, *p2));
            self->field_0[self->field_1F80].field_30.Normalise();
            self->field_1F80++;
        }
        UnkStruct_0019C120_seg * s = &lane->field_4->field_8[seg];
        if ((s->field_3 & 7) == 5) {
            bool lbLeft = false;
            bool lbRight = false;
            if (s->field_4 != 0xFF) lbLeft = true;
            if (s->field_5 != 0xFF) lbRight = true;
            if (lbLeft && lbRight) {
                CGtV3d d = func_0019C120_inl1(*p1, laPoints[0]);
                d.SetY(0.0f);
                if (d.NormaliseGetLength() < 30.0f) {
                    func_0019D1C0(self, &laPoints[0], p1, p2, p3, &D_00665EB0, &D_00665EB0, &D_00665EB0, &D_00665EB0);
                    lbLeft = false;
                    lbRight = false;
                }
            }
            if (lbLeft) {
                CGtV3d d = func_0019C120_inl1(*p1, laPoints[0]);
                d.SetY(0.0f);
                float lrLength = d.NormaliseGetLength();
                if (lrLength > 15.0f)
                    lrLength = 15.0f;
                CGtV3d e0 = laPoints[0] + d * lrLength;
                CGtV3d e1 = *p2 + d * lrLength;
                func_0019D1C0(self, &laPoints[0], &e0, p2, &e1, &D_00665EB0, lTransparent, &D_00665EB0, lTransparent);
            }
            if (lbRight) {
                CGtV3d d = func_0019C120_inl1(laPoints[0], *p1);
                d.SetY(0.0f);
                float lrLength = d.NormaliseGetLength();
                if (lrLength > 15.0f)
                    lrLength = 15.0f;
                CGtV3d e0 = *p1 + d * lrLength;
                CGtV3d e1 = *p3 + d * lrLength;
                func_0019D1C0(self, &e0, p1, &e1, p3, lTransparent, &D_00665EB0, lTransparent, &D_00665EB0);
            }
        } else {
            func_0019D1C0(self, &laPoints[0], p1, p2, p3, &D_00665EB0, &D_00665EB0, &D_00665EB0, &D_00665EB0);
        }
    }
}

// [G] the wall takes over the car's lane position
static inline void func_0019C120_inl7(UnkStruct_0019C120 * self, const UnkStruct_0019C120_car * car)
{
    self->field_1F8C = car->field_18B4;
    self->field_1F90 = car->field_18B8;
    self->field_1F94 = car->field_18C0;
}

// 0x0019C120
extern "C" void func_0019C120(UnkStruct_0019C120 * self, int idx)
{
    CGtV3d laPoints[4];
    CGtV4d lTransparent(0.5f, 0.0f, 0.0f, 0.0f);
    if (!D_004E26B8) {
        D_00665EB0 = CGtV4d(0.5f, 0.0f, 0.0f, 1.0f);
        D_004E26B8 = 1;
    }
    UnkStruct_0019C120_car * car = &D_00522660.field_12AD50[idx];
    self->field_1F80 = 0;
    self->field_1F84 = 0;
    if (car->field_18B4 == 0 || D_0064D368 <= 0)
        return;
    if (car->field_18C0 != self->field_1F94) {
        if (self->field_1F94 < 0) {
            func_0019C120_inl7(self, car);
        } else if (D_0064D378) {
            if (self->field_1F94 < car->field_18C0)
                func_0019C120_inl7(self, car);
        } else if (self->field_1F94 < car->field_18C0) {
            if (car->field_18C0 - self->field_1F94 < D_0064D368 / 2)
                func_0019C120_inl7(self, car);
        } else {
            if (D_0064D368 / 2 < self->field_1F94 - car->field_18C0)
                func_0019C120_inl7(self, car);
        }
    }
    int N = D_0064D368;
    int lnWall = (self->field_1F94 + -10 + N) % N;
    float lrWallDist = func_0019C120_inl5(lnWall);
    int lnSliceDifference;
    if (D_0064D378) {
        lnSliceDifference = car->field_18C0 - lnWall;
    } else if (car->field_18C0 < lnWall) {
        lnSliceDifference = lnWall - car->field_18C0;
        if (N / 2 < lnSliceDifference)
            lnSliceDifference = car->field_18C0 + N - lnWall;
    } else {
        lnSliceDifference = car->field_18C0 - lnWall;
        if (!(lnSliceDifference < N / 2))
            lnSliceDifference = lnWall + N - car->field_18C0;
    }
    self->field_1F99 = lnSliceDifference < 6;
    int lnCar = car->field_18C0;
    float lrRaceCarPrevSliceDist = func_0019C120_inl5(lnCar);
    float lrRaceCarNextSliceDist = D_0064D364[lnCar].field_0;
    float lrLapLength = D_0064D364[D_0064D368 - 1].field_0;
    float lrRaceCarDist = lrRaceCarPrevSliceDist + car->field_18BC * (lrRaceCarNextSliceDist - lrRaceCarPrevSliceDist);
    bool lbForward = false;
    if (D_0064D378) {
        if (!(lnCar < lnWall))
            lbForward = true;
    } else if (!(lnCar < lnWall)) {
        if (lnCar - lnWall < D_0064D368 / 2)
            lbForward = true;
    } else {
        if (D_0064D368 / 2 < lnWall - lnCar)
            lbForward = true;
    }
    float lrDist;
    if (lbForward) {
        if (lrRaceCarDist >= lrWallDist)
            lrDist = lrRaceCarDist - lrWallDist;
        else
            lrDist = lrRaceCarDist + lrLapLength - lrWallDist;
    } else {
        if (lrWallDist >= lrRaceCarDist)
            lrDist = lrWallDist - lrRaceCarDist;
        else
            lrDist = lrWallDist + lrLapLength - lrRaceCarDist;
    }
    if (lrDist <= 20.0f) {
        float lrClamped = GtMath::Min(GtMath::Max((20.0f - lrDist) / 20.0f, 0.0f), 0.2f);
        func_0019C120_inl3(D_00665EB0, lrClamped);
        if (car->field_18EA)
            self->field_1F98 = false;
        else
            self->field_1F98 = true;
    } else {
        func_0019C120_inl3(D_00665EB0, 0.0f);
        self->field_1F98 = false;
    }
    const CB3AILane * lane = self->field_1F8C;
    unsigned short seg = self->field_1F90;
    UnkStruct_0019C120_seg * s = &lane->field_4->field_8[seg];
    unsigned short l = s->field_4;
    unsigned short n = s->field_6;
    while (l != 0xFF) {
        lane = &D_00522660.field_2C[l];
        seg = n;
        s = &lane->field_4->field_8[seg];
        l = s->field_4;
        n = s->field_6;
    }
    seg = IncrementSegmentIndexClamped__9CB3AILaneCFUss(lane, seg, -15);
    func_0019C120_inl6(self, lane, seg, laPoints, &lTransparent);
    s = &lane->field_4->field_8[seg];
    l = s->field_5;
    n = s->field_8;
    while (l != 0xFF) {
        lane = &D_00522660.field_2C[l];
        seg = n;
        func_0019C120_inl6(self, lane, seg, laPoints, &lTransparent);
        s = &lane->field_4->field_8[seg];
        l = s->field_5;
        n = s->field_8;
    }
    func_0019B770(self, idx);
}
