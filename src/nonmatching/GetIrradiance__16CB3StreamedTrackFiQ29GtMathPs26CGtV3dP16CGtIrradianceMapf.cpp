// NONMATCHING: GetIrradiance__16CB3StreamedTrackFiQ29GtMathPs26CGtV3dP16CGtIrradianceMapf -- retail 496 / ours 496 instructions, 61 in changed runs
// draftAE: 496/496 with every mnemonic in place (dh.py 0 hunks), calls identical; 61 changed = stack offsets only (retail keeps two more 16-byte slots below lIrradiance2: frame 0x1A0 vs 0x170; the N140 pad of the out-of-line IntersectLineNearestWithUnit lands above, not below) plus one f0/f1 swap in a band-0 Decompress. Forms: lPosition copied first (by-value parameter slot at the top), inlined IntersectLineNearestWithUnit tested == false (retail's double andi), mpPolygon re-read per branch, the blend loop as -=, *=, +=
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm with Revenge STABS/types (identical algorithm, 483 vs 496 instrs): loaded-unit lookup, down line, inlined IntersectLineNearestWithUnit on the paired collision track, triangle 0/1 vertex index sets, CGtIrradianceMapCompressed::Decompress band scales (2, 0.75, 0.5) x 1.6/128, barycentric blend

// GetIrradiance__16CB3StreamedTrackFiQ29GtMathPs26CGtV3dP16CGtIrradianceMapf -- draftAE (0x301340, 0x7C0) --
// CB3StreamedTrack::GetIrradiance(int, CGtV3d, CGtIrradianceMap*, float)
// Written from the retail asm; Revenge STABS of CB4StreamedTrack::GetIrradiance (B4StreamedTrack.cpp, 483 instrs: lLine,
// lPolygonIntersectionResult, lIrradiance0/1/2, lnIndex, lpUnit, lpPoly) [L]. Layouts [C] Revenge types.h: CGtLine,
// CGtPolygonIntersectionResult, CGtIrradianceMap (float marCoeff[9]), CGtIrradianceMapCompressed (signed char man8Coeff[9]),
// CB4CollisionPolygon (mau16VertexIrradianceIndices[4] at +6), the unit's mpaIrradianceData at +0x94.
// [L] a line straight down from the position is cast against the unit's collision tree (the inlined
// IntersectLineNearestWithUnit on the paired collision track D_00522660 + 0x12A348 + field_1C * 0x1CC); on a hit the hit
// triangle's three vertex irradiance maps are decompressed (CGtIrradianceMapCompressed::Decompress, inlined) and blended with
// the hit's barycentric u, v into *lpIrradiance. Types [G] where not from Revenge.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CGtCollisionKDTree;
struct CGtLine {
    CGtV3d mStartPoint;
    CGtV3d mEndPoint;
};
struct CGtPolygonSoupPolygonBase { unsigned char mau8Indices[4]; };
struct CB3CollisionPolygon : CGtPolygonSoupPolygonBase {
    unsigned short mCollisionTag;                     // [G] CB4CollisionTag (2 bytes)
    unsigned short mau16VertexIrradianceIndices[4];
};
struct CGtPolygonIntersectionResult {
    CGtV3d mPoint;
    CGtV3d mNormal;
    CGtV3d maVertices[3];
    float mrPenetration;
    float mrU;
    float mrV;
    float mrQWPadding;
    CB3CollisionPolygon * mpPolygon;
    unsigned int muTriangle;
    void * mpVertices;
};
struct CGtIrradianceMap {
    float marCoeff[9];
};
struct CGtIrradianceMapCompressed {
    signed char man8Coeff[9];
    // [C] name: B3O0PCH map (CGtIrradianceMapCompressed::Decompress(CGtIrradianceMap*), 0x134). [L] body from the inlined copies:
    // band 0 x2, band 1 x0.75, band 2 x0.5, all x1.6 / 128
    void Decompress(CGtIrradianceMap * lpOut) const {
        int i;
        lpOut->marCoeff[0] = 1.6f * (2.0f * (float)man8Coeff[0]) / 128.0f;
        for (i = 1; i < 4; i++)
            lpOut->marCoeff[i] = 1.6f * (0.75f * (float)man8Coeff[i]) / 128.0f;
        for (; i < 9; i++)
            lpOut->marCoeff[i] = 1.6f * (0.5f * (float)man8Coeff[i]) / 128.0f;
    }
};
struct CB3StreamedTrackLODAndCollisionData {
    int meLoadedState;              // [C] Revenge CB4StreamedTrackData (2 = loaded, read uncached)
    unsigned char pad_4[0x8C];
    CGtCollisionKDTree * mpKDTree;
    CGtIrradianceMapCompressed * mpaIrradianceData;
};
extern "C" int IntersectLineNearest__18CGtCollisionKDTreeCFRC7CGtLineP28CGtPolygonIntersectionResult(const CGtCollisionKDTree *, const CGtLine &, CGtPolygonIntersectionResult *);

class CB3StreamedTrack {
public:
    void GetIrradiance(int lnUnit, CGtV3d lPosition, CGtIrradianceMap * lpIrradiance, float lrAmountToTestDownwards);

    // [G] the loaded-unit lookup as the proven GetUnitOriginalID / IntersectLineNearestWithUnit (the unit being streamed in,
    // out-of-range units and units not loaded give 0)
    CB3StreamedTrackLODAndCollisionData * func_00301340_inl1(int lnUnit) {
        CB3StreamedTrackLODAndCollisionData * lpUnit;
        if (field_24 != field_2C && lnUnit == field_24 % field_C) {
            lpUnit = 0;
        } else if (lnUnit >= 0 && lnUnit < field_C) {
            CB3StreamedTrackLODAndCollisionData * x = field_17C[lnUnit];
            if (*(int *)((unsigned int)x | 0x20000000) == 2) lpUnit = x;
            else lpUnit = 0;
        } else {
            lpUnit = 0;
        }
        return lpUnit;
    }
    // [C] name: B3O0PCH map (CB3StreamedTrack::IntersectLineNearestWithUnit(unsigned int, const CGtLine&, CGtPolygonIntersectionResult*));
    // body as its proven out-of-line copy (B3StreamedTrack_00301C80.cpp)
    bool IntersectLineNearestWithUnit(unsigned int lnUnit, const CGtLine & lLine, CGtPolygonIntersectionResult * lpResult) {
        CB3StreamedTrackLODAndCollisionData * u = func_00301340_inl1((int)lnUnit);
        if (u != 0) {
            if (IntersectLineNearest__18CGtCollisionKDTreeCFRC7CGtLineP28CGtPolygonIntersectionResult(u->mpKDTree, lLine, lpResult) == 1)
                return true;
            return false;
        }
        return false;
    }

    unsigned char pad_0[0xC];
    int field_C;                    // [G] unit count
    unsigned char pad_10[0xC];
    int field_1C;                   // [G] index of the paired collision track
    unsigned char pad_20[0x4];
    int field_24;                   // [G] unit being streamed
    unsigned char pad_28[0x4];
    int field_2C;
    unsigned char pad_30[0x14C];
    CB3StreamedTrackLODAndCollisionData * field_17C[20];   // [G] count unknown; the object is 0x1CC bytes
};
struct UnkStruct_D_00522660 { unsigned char pad_0[0x12A348]; CB3StreamedTrack field_12A348[1]; };
extern UnkStruct_D_00522660 D_00522660;

void CB3StreamedTrack::GetIrradiance(int lnUnit, CGtV3d lPosition, CGtIrradianceMap * lpIrradiance, float lrAmountToTestDownwards)
{
    CGtV3d lPos = lPosition;
    CGtLine lLine;
    CGtPolygonIntersectionResult lPolygonIntersectionResult;
    CGtIrradianceMap lIrradiance0;
    CGtIrradianceMap lIrradiance1;
    CGtIrradianceMap lIrradiance2;
    int lnIndex;
    if (lnUnit < 0)
        return;
    CB3StreamedTrackLODAndCollisionData * lpUnit = func_00301340_inl1(lnUnit);
    lLine.mStartPoint = lPos;
    lLine.mEndPoint = lPos + CGtV3d(0.0f, -lrAmountToTestDownwards, 0.0f);
    if (D_00522660.field_12A348[field_1C].IntersectLineNearestWithUnit(lnUnit, lLine, &lPolygonIntersectionResult) == false)
        return;
    if (lPolygonIntersectionResult.muTriangle == 0) {
        CB3CollisionPolygon * lpPoly = lPolygonIntersectionResult.mpPolygon;
        lpUnit->mpaIrradianceData[lpPoly->mau16VertexIrradianceIndices[0]].Decompress(&lIrradiance0);
        lpUnit->mpaIrradianceData[lpPoly->mau16VertexIrradianceIndices[1]].Decompress(&lIrradiance1);
        lpUnit->mpaIrradianceData[lpPoly->mau16VertexIrradianceIndices[2]].Decompress(&lIrradiance2);
    } else {
        CB3CollisionPolygon * lpPoly = lPolygonIntersectionResult.mpPolygon;
        lpUnit->mpaIrradianceData[lpPoly->mau16VertexIrradianceIndices[2]].Decompress(&lIrradiance0);
        lpUnit->mpaIrradianceData[lpPoly->mau16VertexIrradianceIndices[1]].Decompress(&lIrradiance1);
        lpUnit->mpaIrradianceData[lpPoly->mau16VertexIrradianceIndices[3]].Decompress(&lIrradiance2);
    }
    for (lnIndex = 0; lnIndex < 9; lnIndex++) {
        lIrradiance1.marCoeff[lnIndex] -= lIrradiance0.marCoeff[lnIndex];
        lIrradiance2.marCoeff[lnIndex] -= lIrradiance0.marCoeff[lnIndex];
        lIrradiance1.marCoeff[lnIndex] *= lPolygonIntersectionResult.mrU;
        lIrradiance2.marCoeff[lnIndex] *= lPolygonIntersectionResult.mrV;
        lIrradiance0.marCoeff[lnIndex] += lIrradiance1.marCoeff[lnIndex];
        lIrradiance0.marCoeff[lnIndex] += lIrradiance2.marCoeff[lnIndex];
    }
    *lpIrradiance = lIrradiance0;
}
