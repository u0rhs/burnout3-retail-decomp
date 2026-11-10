// NONMATCHING: func_00273400 -- retail 505 / ours 532 instructions, 534 in changed runs
// hard1 C-first: [L] the CGtPolygonSoup16 callback overload of GtIntersection::IntersectLine (CGtCollisionKDTree::IntersectLine's other leaf call), from the IntersectLineNearest(Soup16) template without its 2-set pipelining: per triangle (0,1,2 and 2,1,3 for quads) the VU0 microprogram 0x388 (VF2/VF4 line, VF23 offset+scale, VF5-7 raw vertices; VI1 hit, VF24 t/u/v), on a hit the result (point, normal of vertices 2,1,0, t, u, v, polygon, triangle 0) to the callback, false stops; 532/505, calls identical (the callback through t9 vs v0), the 7 result fields the callback reads stored as retail; left: frame 0x230 vs 0x500, retail recomputes GetOffset per vertex (ours CSEs it), asm hazard nops
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm against the archived Soup16 sibling: every call, branch, the VU0 register protocol (vcallms .word N219), the upload / DMA wait and the result fields checked; retail's always-0 triangle index, vertex-2,1,0 normal for second triangles and unwritten maVertices/mpVertices kept

// func_00273400 -- hard1 (C-first draft; deferred-hard by draftAF). 0x273400, 0x7E4. Unnamed in every table, so a placeholder
// with C linkage. [L] the CGtPolygonSoup16 overload of GtIntersection::IntersectLine(const CGtLine&, const CGtPolygonSoup16&,
// callback, void*): CGtCollisionKDTree::IntersectLine dispatches a leaf to IntersectLine__14GtIntersectionFRC7CGtLineRC14CGtPolygonSoup...
// or to this function by the soup kind (son8's archive), and its body is IntersectLineNearest(CGtPolygonSoup16)'s (0x273BF0, same
// file) without the 2-set pipelining. The name stays a placeholder (not in any table).
// What it does [L]: for every triangle of the soup (two per quad: indices 0,1,2 then 2,1,3 when index 3 < 0xFF) runs the VU0
// line/triangle microprogram (vu_game_004787D0 entry 0x388; line in VF2/VF4, offset+scale in VF23, the three raw vertices in
// VF5-VF7; hit flag VI1, (t, u, v) in VF24); on a hit fills a CGtPolygonIntersectionResult (point = line at t, normal from the
// polygon's vertices 2,1,0 dequantised, penetration t, u, v, the polygon, triangle 0) and calls the callback with it and the
// context; a false return stops with false; else returns whether any triangle was hit.
// [C] retail always reports triangle 0 and the normal of vertices 2,1,0, also for a quad's second triangle; mpVertices and
// maVertices are never written (the callback sees stack garbage there). Kept as retail.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
extern "C" int sceDmaGetChan(int);
extern "C" int sceDmaSync(int, int, int);
// [C] names: E B3O0PCH map (CGtVu0CodeManager::UploadVu0Code 0x2294A0, WaitForUploadToFinish 0x2293C0,
// GetCurrentVu0CodePointer 0x229520); signatures from Revenge types.h; static data gmpCurrentVu0Code (retail tables).
class CGtVu0CodeManager {
public:
    static void *gmpCurrentVu0Code;
    static bool UploadVu0Code(void *code);
    static void WaitForUploadToFinish();
    static void *GetCurrentVu0CodePointer() { return gmpCurrentVu0Code; }
};
// [L] bodies from retail's inlined copies (gifq2 probes, N203)
inline bool CGtVu0CodeManager::UploadVu0Code(void *code)
{
    if (gmpCurrentVu0Code == code) {
        return false;
    } else {
        gmpCurrentVu0Code = code;
        if (code) {
            *(volatile unsigned int *)0x10008020 = 0;
            *(volatile unsigned int *)0x10008030 = (unsigned int)code;
            *(volatile unsigned int *)0x10008000 = 0x145;
            return true;
        } else {
            return false;
        }
    }
}
inline void CGtVu0CodeManager::WaitForUploadToFinish()
{
    while (sceDmaSync(sceDmaGetChan(0), 1, 0) != 0) {}
}
extern char vu_game_004787D0[];

typedef enum { eGtIR_Outside = 0, eGtIR_Intersect = 1, eGtIR_Inside = 2 } EGtIntersectionResult;   // [L] Revenge STABS
union U128Types { u_long128 mu128Data; float marReal[4]; int manInt[4]; unsigned int mauInt[4]; };   // [L] Revenge STABS

// [G] stand-ins on compiler-chosen registers (header operator+/operator- hard-code $vf1/$vf2)
static inline CGtV3d func_00273BF0_inl1(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
static inline CGtV3d func_00273BF0_inl2(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}

struct CGtPolygonSoupVertex16 {
    unsigned short mu16X;
    unsigned short mu16Y;
    unsigned short mu16Z;
    CGtV3d GetGtV3d(CGtV3d lOffset) const;   // [C] name: E B3O0PCH map (0x178)
};
// [L] body from retail's inlined copies: the unsigned components scaled by 1/65536 then 1000, plus the soup offset.
// [G] the (unsigned int) conversion (retail's bltz/srl/or/add.s unsigned int -> float sequence).
inline CGtV3d CGtPolygonSoupVertex16::GetGtV3d(CGtV3d lOffset) const
{
    CGtV3d v;
    v.SetX((float)(unsigned int)mu16X);
    v.SetY((float)(unsigned int)mu16Y);
    v.SetZ((float)(unsigned int)mu16Z);
    v = func_00273BF0_inl1(v * (1.0f / 65536.0f) * 1000.0f, lOffset);
    return v;
}
struct CGtPolygonSoupPolygonBase { unsigned char mau8Indices[4]; };
class CGtPolygonSoup16 {
public:
    void *mpPolygons;
    CGtPolygonSoupVertex16 *mpVertices;
    unsigned short mu16DataSize;
    signed char mn8OffsetX;
    signed char mn8OffsetY;
    signed char mn8OffsetZ;
    unsigned char mu8PolygonSize;
    unsigned char mu8PolygonCount;
    unsigned char mu8VertexCount;
    // [C] names: E B3O0PCH map (GetVertex(int) 0x108, GetOffset() 0x90, GetVertices() 0x1C); bodies [L] from retail
    CGtPolygonSoupVertex16 *GetVertices() const { return mpVertices; }
    CGtV3d GetOffset() const
    {
        CGtV3d o;
        o.SetX((float)mn8OffsetX);
        o.SetY((float)mn8OffsetY);
        o.SetZ((float)mn8OffsetZ);
        return o * 500.0f;
    }
    CGtV3d GetVertex(int i) const { return GetVertices()[i].GetGtV3d(GetOffset()); }
};
class CGtLine {
public:
    CGtV3d mStartPoint;
    CGtV3d mEndPoint;
};
class CGtPolygonIntersectionResult {
public:
    CGtV3d mPoint;
    CGtV3d mNormal;
    CGtV3d maVertices[3];
    float mrPenetration;
    float mrU;
    float mrV;
    float mrQWPadding;
    CGtPolygonSoupPolygonBase *mpPolygon;
    unsigned int muTriangle;
    void *mpVertices;
};
static inline u_long128 func_00273BF0_inl3(const CGtPolygonSoupVertex16 *v)
{
    u_long128 q;
    unsigned long lo = ((unsigned long)v->mu16Y << 32) | (unsigned long)v->mu16X;
    asm("pcpyld %0, %1, %2" : "=r"(q) : "r"((unsigned long)v->mu16Z), "r"(lo));
    return q;
}


typedef bool (*UnkFunc_00273400_cb)(const CGtPolygonIntersectionResult &, void *);

// [G] scoped pragma: opt_repositioncode off as the proven GtIntersection siblings (N203 SetCode shape); vcallms as .word (N219)
#pragma push
#pragma opt_repositioncode off
// 0x00273400
extern "C" bool func_00273400(const CGtLine &lLine, const CGtPolygonSoup16 &lPolygonSoup, UnkFunc_00273400_cb lpCallback, void *lpData)
{
    bool lbHasIntersected = false;
    CGtPolygonIntersectionResult lResult;
    unsigned int luPolygonSize = lPolygonSoup.mu8PolygonSize;
    unsigned char *luPolygonAddress = (unsigned char *)lPolygonSoup.mpPolygons;
    CGtPolygonSoupVertex16 *lpu16VertexArray = lPolygonSoup.mpVertices;
    unsigned char *luLastPolygonAddress = luPolygonAddress + luPolygonSize * lPolygonSoup.mu8PolygonCount;
    unsigned char luPolyIndexA = 0;
    unsigned char luPolyIndexB = 1;
    unsigned char luPolyIndexC = 2;
    unsigned int luTriangle = 0;
    float lrScale = 500.0f / 32768.0f;
    U128Types lInput;
    lInput.marReal[0] = (float)lPolygonSoup.mn8OffsetX;
    lInput.marReal[1] = (float)lPolygonSoup.mn8OffsetY;
    lInput.marReal[2] = (float)lPolygonSoup.mn8OffsetZ;
    CGtV3d lShift = (*(const CGtV3d *)&lInput) * 500.0f;
    if (CGtVu0CodeManager::GetCurrentVu0CodePointer() != (void *)vu_game_004787D0) {
        if (CGtVu0CodeManager::UploadVu0Code((void *)vu_game_004787D0)) CGtVu0CodeManager::WaitForUploadToFinish();
    }
    CGtV3dPlus lShiftScale;
    lShiftScale.SetGtV3d(lShift);
    lShiftScale.SetPlus(lrScale);
    while (luPolygonAddress < luLastPolygonAddress) {
        const CGtPolygonSoupVertex16 *lpVertexA = &lpu16VertexArray[luPolygonAddress[luPolyIndexA]];
        const CGtPolygonSoupVertex16 *lpVertexB = &lpu16VertexArray[luPolygonAddress[luPolyIndexB]];
        const CGtPolygonSoupVertex16 *lpVertexC = &lpu16VertexArray[luPolygonAddress[luPolyIndexC]];
        U128Types lData;
        int lbHit;
        asm volatile("ctc2.i %0, $vi0" : : "r"(lpVertexA));   // [C] retail writes vertex A's address to VI0 (hard-wired 0: no effect)
        asm volatile("lqc2 $vf2, 0(%0)" "\n\t" "lqc2 $vf4, 0x10(%0)" : : "r"(&lLine));
        asm volatile("qmtc2.ni %0, $vf23" : : "r"(lShiftScale.mData));
        asm volatile("qmtc2.ni %0, $vf5" : : "r"(func_00273BF0_inl3(lpVertexA)));
        asm volatile("qmtc2.ni %0, $vf6" : : "r"(func_00273BF0_inl3(lpVertexB)));
        asm volatile("qmtc2.ni %0, $vf7" : : "r"(func_00273BF0_inl3(lpVertexC)));
        asm volatile(".word 0x4A001C78");   // vcallms 0x388 (N219 [G])
        asm volatile("cfc2.i %0, $vi1" : "=r"(lbHit));
        asm volatile("qmfc2.ni %0, $vf24" : "=r"(lData.mu128Data));
        if (lbHit) {
            lResult.mrPenetration = lData.marReal[0];
            lResult.mPoint = Interpolate(lLine.mStartPoint, lLine.mEndPoint, lData.marReal[0]);
            CGtV3d laVerts[3];
            laVerts[0] = lPolygonSoup.GetVertex(luPolygonAddress[2]);
            laVerts[1] = lPolygonSoup.GetVertex(luPolygonAddress[1]);
            laVerts[2] = lPolygonSoup.GetVertex(luPolygonAddress[0]);
            CGtV3d n = CrossProduct(func_00273BF0_inl2(laVerts[1], laVerts[2]), func_00273BF0_inl2(laVerts[0], laVerts[2]));
            n.Normalise();
            lResult.mNormal = n;
            lResult.mrU = lData.marReal[1];
            lResult.mrV = lData.marReal[2];
            lResult.mpPolygon = (CGtPolygonSoupPolygonBase *)luPolygonAddress;
            lResult.muTriangle = 0;
            if (!lpCallback(lResult, lpData)) return false;
            lbHasIntersected = true;
        }
        if (luTriangle == 0 && luPolygonAddress[3] < 0xFFu) {
            luTriangle = 1; luPolyIndexA = 2; luPolyIndexB = 1; luPolyIndexC = 3;
        } else {
            luTriangle = 0; luPolyIndexA = 0; luPolyIndexB = 1; luPolyIndexC = 2;
            luPolygonAddress += luPolygonSize;
        }
    }
    return lbHasIntersected;
}
#pragma pop
