// NONMATCHING: RenderSpatialTriggers__15CB3TrafficDebugFv -- retail 833 / ours 876 instructions, 1006 in changed runs
// draftAH C-first: leftmost-lane walk then per-lane slice walls (y-5..y+20) with type-5 side flaps; per-lane body as one inline used twice (retail inlines twice); 876/833, call set identical (EndRendering placed before the out-of-line type!=5 blocks in retail), VU op counts equal except vmove 6/4; left: colour byte copies, frame 0x280 vs 0x410
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm with Revenge STABS locals (same function, 740 instrs); every vertex position/colour of the 3 quad kinds traced per lane instance; op counts per kind equal for VU

// CB3TrafficDebug::RenderSpatialTriggers() -- draftAH (C-first draft; the lifter refused it). 0x2EF0F0, 0xD04.
// [C] name: retail symbol table; [L] file B3TrafficDebug.cpp (retail_names.csv). Local names after Revenge's own
// RenderSpatialTriggers__15CB4TrafficDebug (STABS, B4TrafficDebug.cpp, 740 instrs: laPoints[4], laRenderVerts[6], lpAILane,
// lnSegmentIndex, lnNextSegmentIndex, lu8NextLaneIndex, lu16LHSIndex, lu16RHSIndex, lbLeft, lbRight, lrLength, lVector1,
// lOtherPointLow, lOtherPointHigh, lPackedColour0/1; the colour pack's lu64Clamp / lu128Int / lu64Packed / lu32Packed) [L].
// Written from the retail asm. Layouts as the proven CB3AILane::GetTotalWidth (B3AILane_00148140.cpp) and RenderClampBoxes'
// CB3Im3dVertex (B3VehicleDeform_00460C20.cpp).
// What it does [L]: while the debug switch D_00527440 is set (and D_0055D7F7 clear), for the debug slice D_0055D7E4: walk the
// left links from lane 0 to the leftmost lane, then draw each lane's slice from left to right as a wall from y-5 to y+20
// between its left and right edge vertices; a segment of type 5 instead gets fading 5-unit flaps on the sides that have a
// neighbour (left link / right link set).
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct RwRGBA { unsigned char red, green, blue, alpha; };   // [L] RW 3.x layout

struct UnkStruct_002EF0F0_v { unsigned short field_0; unsigned short field_2; };   // slice: left / right edge vertex
struct UnkStruct_002EF0F0_e {               // segment, 10 bytes (as UnkStruct_00146DB0_e, plus field_0)
    short field_0;                          // [G] first slice of the segment
    unsigned char pad_2[1];
    unsigned char field_3;                  // low 3 bits: type
    unsigned char field_4[2];               // side lane links (0xFF none): [0] left, [1] right
    unsigned short field_6[2];              // side segment links
};
struct CB3AILaneStruct {                    // as B3AILane_00148140.cpp
    UnkStruct_002EF0F0_v *field_0;
    unsigned char pad_4[4];
    UnkStruct_002EF0F0_e *field_8;
};
class CB3AILane {
public:
    unsigned char pad_0[4];
    CB3AILaneStruct *field_4;
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2C];
    CB3AILane field_2C[1];
};
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_002EF0F0_p { CGtV3d field_0; };
struct UnkStruct_D_0064D354 {
    UnkStruct_002EF0F0_p *field_0;          // the lane vertex pool
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_0064D354 D_0064D354;
extern int D_00527440;                      // [G] debug switch
extern unsigned char D_0055D7F7[];
extern unsigned short D_0055D7E4;           // [G] debug slice index
extern int D_0064D368;                      // [G] slice count

// [L] name: E map CB3Im3dVertex (B3Im3d::RenderTrilist's argument); layout and constructor as RenderClampBoxes'
struct CB3Im3dVertex {
    CGtV3dPlus field_0;
    unsigned char pad_10[8];
    RwRGBA field_18;
    unsigned char pad_1C[4];
    CB3Im3dVertex() { field_0.SetPlus(0.0f); }   // [L] B3O0PCH map ctor; [G] body: w = 0
};
class CGtTexture;
namespace B3Im3d {
void BeginRendering();
void EndRendering();
void SetTexture(CGtTexture *);
void SetZWrite(bool);
void RenderTrilist(const CB3Im3dVertex *, int);
}
class CB3TrafficDebug {
public:
    void RenderSpatialTriggers();
};

// [G] header gap (queued): colour -> RwRGBA (x 128, to int, clamped to (255, 255, 255, 128), packed), the body of
// RenderClampBoxes' CB3Im3dVertex::SetColour (B3O0PCH map) returning the packed colour; Revenge's locals lu64Clamp, lu128Int,
// lu64Packed, lu32Packed
static inline RwRGBA func_002EF0F0_inl1(const CGtV4d &c)
{
    CGtV4d s = c * 128.0f;
    u_long128 lu128Int, lu128Clamp, m, lu64Packed;
    unsigned int lu32Packed;
    asm("vftoi0.xyzw %0, %1" : "=j"(lu128Int) : "j"(s.mData));
    unsigned long lu64Clamp = 0x00FF00FFUL | (0x008000FFUL << 32);
    asm("pextlh %0, $0, %1" : "=r"(lu128Clamp) : "r"(lu64Clamp));
    asm("pminw %0, %1, %2" : "=r"(m) : "r"(lu128Int), "r"(lu128Clamp));
    asm("ppach %0, $0, %1" : "=r"(lu64Packed) : "r"(m));
    asm("ppacb %0, $0, %1" : "=r"(lu32Packed) : "r"(lu64Packed));
    union { unsigned int u; RwRGBA c; } r;
    r.u = lu32Packed;
    return r.c;
}

// [G] one vertex: xyz = p (w kept), colour
static inline void func_002EF0F0_inl2(CB3Im3dVertex &v, const CGtV3d &p, const RwRGBA &c)
{
    v.field_0.SetGtV3d(p);
    v.field_18 = c;
}

// [G] one lane's slice (retail inlines it twice: the leftmost lane, then each lane to the right)
static inline void func_002EF0F0_inl3(const CB3AILane *lpAILane, int lnSegmentIndex, CGtV3d *laPoints, CB3Im3dVertex *laRenderVerts,
                                      const RwRGBA &lPackedColour0, const RwRGBA &lPackedColour1)
{
    const CB3AILaneStruct *d = lpAILane->field_4;
    unsigned short lu16LHSIndex = d->field_0[lnSegmentIndex].field_0;
    unsigned short lu16RHSIndex = d->field_0[lnSegmentIndex].field_2;
    const CGtV3d &lLeft = D_0064D354.field_0[lu16LHSIndex].field_0;
    const CGtV3d &lRight = D_0064D354.field_0[lu16RHSIndex].field_0;
    laPoints[0] = lLeft;
    laPoints[0].SetY(lLeft.Y() - 5.0f);
    laPoints[1] = lRight;
    laPoints[1].SetY(lRight.Y() - 5.0f);
    laPoints[2] = lLeft;
    laPoints[2].SetY(lLeft.Y() + 20.0f);
    laPoints[3] = lRight;
    laPoints[3].SetY(lRight.Y() + 20.0f);
    const UnkStruct_002EF0F0_e &s = d->field_8[lnSegmentIndex];
    if ((s.field_3 & 7) == 5) {
        bool lbLeft = false;
        bool lbRight = false;
        if (s.field_4[0] != 0xFF)
            lbLeft = true;
        if (s.field_4[1] != 0xFF)
            lbRight = true;
        if (lbLeft) {
            CGtV3d lVector1 = laPoints[1] - laPoints[0];
            lVector1.SetY(0.0f);
            float lrLength = lVector1.NormaliseGetLength();
            if (lrLength > 5.0f)
                lrLength = 5.0f;
            CGtV3d lOtherPointLow = laPoints[0] + lVector1 * lrLength;
            CGtV3d lOtherPointHigh = laPoints[2] + lVector1 * lrLength;
            func_002EF0F0_inl2(laRenderVerts[0], laPoints[0], lPackedColour0);
            func_002EF0F0_inl2(laRenderVerts[1], lOtherPointLow, lPackedColour0);
            func_002EF0F0_inl2(laRenderVerts[2], laPoints[2], lPackedColour1);
            func_002EF0F0_inl2(laRenderVerts[3], laPoints[2], lPackedColour1);
            func_002EF0F0_inl2(laRenderVerts[4], lOtherPointLow, lPackedColour0);
            func_002EF0F0_inl2(laRenderVerts[5], lOtherPointHigh, lPackedColour0);
            B3Im3d::RenderTrilist(laRenderVerts, 6);
        }
        if (lbRight) {
            CGtV3d lVector1 = laPoints[0] - laPoints[1];
            lVector1.SetY(0.0f);
            float lrLength = lVector1.NormaliseGetLength();
            if (lrLength > 5.0f)
                lrLength = 5.0f;
            CGtV3d lOtherPointLow = laPoints[1] + lVector1 * lrLength;
            CGtV3d lOtherPointHigh = laPoints[3] + lVector1 * lrLength;
            func_002EF0F0_inl2(laRenderVerts[0], lOtherPointLow, lPackedColour0);
            func_002EF0F0_inl2(laRenderVerts[1], laPoints[1], lPackedColour1);
            func_002EF0F0_inl2(laRenderVerts[2], lOtherPointHigh, lPackedColour0);
            func_002EF0F0_inl2(laRenderVerts[3], lOtherPointHigh, lPackedColour0);
            func_002EF0F0_inl2(laRenderVerts[4], laPoints[1], lPackedColour1);
            func_002EF0F0_inl2(laRenderVerts[5], laPoints[3], lPackedColour1);
            B3Im3d::RenderTrilist(laRenderVerts, 6);
        }
    } else {
        func_002EF0F0_inl2(laRenderVerts[0], laPoints[0], lPackedColour1);
        func_002EF0F0_inl2(laRenderVerts[1], laPoints[1], lPackedColour1);
        func_002EF0F0_inl2(laRenderVerts[2], laPoints[2], lPackedColour1);
        func_002EF0F0_inl2(laRenderVerts[3], laPoints[2], lPackedColour1);
        func_002EF0F0_inl2(laRenderVerts[4], laPoints[1], lPackedColour1);
        func_002EF0F0_inl2(laRenderVerts[5], laPoints[3], lPackedColour1);
        B3Im3d::RenderTrilist(laRenderVerts, 6);
    }
}

// 0x002EF0F0
void CB3TrafficDebug::RenderSpatialTriggers()
{
    CGtV3d laPoints[4];
    CB3Im3dVertex laRenderVerts[6];
    if (D_00527440 == 0)
        return;
    if (D_0055D7F7[0] != 0)
        return;
    RwRGBA lPackedColour0 = func_002EF0F0_inl1(CGtV4d(0.0f, 0.5f, 0.0f, 0.0f));
    RwRGBA lPackedColour1 = func_002EF0F0_inl1(CGtV4d(0.0f, 0.5f, 0.0f, 0.5f));
    B3Im3d::BeginRendering();
    B3Im3d::SetTexture(0);
    B3Im3d::SetZWrite(false);
    if (D_0055D7E4 < D_0064D368) {
        // the leftmost lane at segment 0 of lane 0
        const CB3AILane *lpAILane = &D_00522660.field_2C[0];
        int lnSegmentIndex = 0;
        unsigned char lu8NextLaneIndex = lpAILane->field_4->field_8[0].field_4[0];
        unsigned short lnNextSegmentIndex = lpAILane->field_4->field_8[0].field_6[0];
        while (lu8NextLaneIndex != 0xFF) {
            lnSegmentIndex = lnNextSegmentIndex;
            lpAILane = &D_00522660.field_2C[lu8NextLaneIndex];
            lu8NextLaneIndex = lpAILane->field_4->field_8[lnNextSegmentIndex].field_4[0];
            lnNextSegmentIndex = lpAILane->field_4->field_8[lnNextSegmentIndex].field_6[0];
        }
        lnSegmentIndex += D_0055D7E4 - lpAILane->field_4->field_8[lnSegmentIndex].field_0;
        func_002EF0F0_inl3(lpAILane, lnSegmentIndex, laPoints, laRenderVerts, lPackedColour0, lPackedColour1);
        // then each lane to the right
        while (lpAILane->field_4->field_8[lnSegmentIndex].field_4[1] != 0xFF) {
            unsigned char lu8Lane = lpAILane->field_4->field_8[lnSegmentIndex].field_4[1];
            lnSegmentIndex = lpAILane->field_4->field_8[lnSegmentIndex].field_6[1];
            lpAILane = &D_00522660.field_2C[lu8Lane];
            func_002EF0F0_inl3(lpAILane, lnSegmentIndex, laPoints, laRenderVerts, lPackedColour0, lPackedColour1);
        }
    }
    B3Im3d::EndRendering();
}
