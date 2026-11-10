// NONMATCHING: IntersectLine__14GtIntersectionFRC7CGtLineRC14CGtPolygonSoupPFRC28CGtPolygonIntersectionResultPv_bPv -- retail 239 / ours 243 instructions, 135 in changed runs
// draftAN fork B C-first: the float-vertex twin of the archived Soup16 callback overload func_00273400 (types from the archived IntersectLineNearest(CGtPolygonSoup)): per triangle (0,1,2 and 2,1,3 for quads) the VU0 line microprogram (entry 0x3D8; line VF2/VF4, vertices VF5-7; VI1 hit, VF5 t/u/v), on a hit point = Interpolate(line, t), normal = normalised (v1-v0)x(v2-v0) of the polygon's vertices 0,1,2, t, u, v, polygon, triangle 0 -> callback, false stops; calls identical (callback through t9 vs v0); scoped opt_removeemptyloops off keeps retail's empty maVertices ctor loop
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm against func_00273400: every call, branch, the VU0 register protocol (vcallms .word 0x4A001EF8 = retail bytes), the upload / DMA wait and the result fields checked; retail's always-0 triangle index, first-triangle normal for quads and unwritten maVertices/mpVertices kept

// GtIntersection::IntersectLine(const CGtLine&, const CGtPolygonSoup&, bool (*)(const CGtPolygonIntersectionResult&, void*), void*)
// -- draftAN fork B (C-first draft). 0x275220, 0x3BC. [C] name: the mangled symbol in retail's tables (E map row 0x28cc80,
// GtIntersectionPS2.cpp). Types from the archived IntersectLineNearest(CGtPolygonSoup) (draftO); body the float-vertex twin of the
// archived Soup16 callback overload func_00273400 (hard1), without its offset/scale VF23.
// What it does [L]: for every triangle of the soup (indices 0,1,2 then 2,1,3 when a quad's index 3 < 0xFF) runs the VU0
// line/triangle microprogram (vu_game_004787D0 entry 0x3D8; line in VF2/VF4, the three vertices in VF5-VF7; hit flag VI1,
// (t, u, v) in VF5); on a hit fills a CGtPolygonIntersectionResult (point = line at t, normal = (v1 - v0) x (v2 - v0) of the
// polygon's vertices 0,1,2, normalised; penetration t, u, v, the polygon, triangle 0) and calls the callback; a false return
// stops with false, else returns whether any triangle was hit.
// [C] retail always reports triangle 0 and the normal of the polygon's first triangle, also for a quad's second triangle;
// maVertices and mpVertices are never written (the callback sees stack garbage there). Kept as retail (as func_00273400).
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

// [G] stand-in on compiler-chosen registers (header operator- hard-codes $vf1/$vf2)
static inline CGtV3d func_00275220_inl2(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}

struct CGtPolygonSoupVertex {
    float mrX;
    float mrY;
    float mrZ;
    CGtV3d GetGtV3d() const { return CGtV3d(mrX, mrY, mrZ); }   // [L] name: Revenge types.h; body [L] from retail (3 stores + lq)
};
struct CGtPolygonSoupPolygonBase { unsigned char mau8Indices[4]; };
class CGtPolygonSoup {
public:
    void *mpPolygons;
    CGtPolygonSoupVertex *mpVertices;
    unsigned int muDataSize;
    unsigned char mu8PolygonSize;
    unsigned char mu8PolygonCount;
    unsigned char mu8VertexCount;
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
// [G] the vertex's three words packed into one quad for the microprogram (as func_00274ED0's GetGtV3d)
static inline u_long128 func_00275220_inl3(const CGtPolygonSoupVertex *v)
{
    const unsigned int *w = (const unsigned int *)v;
    u_long128 q;
    unsigned long lo = ((unsigned long)w[1] << 32) | (unsigned long)w[0];
    asm("pcpyld %0, %1, %2" : "=r"(q) : "r"((unsigned long)w[2]), "r"(lo));
    return q;
}

class GtIntersection {
public:
    static bool IntersectLine(const CGtLine &lLine, const CGtPolygonSoup &lPolygonSoup,
                              bool (*lpCallback)(const CGtPolygonIntersectionResult &, void *), void *lpData);
};

// [G] scoped pragma: opt_repositioncode off as the GtIntersection siblings; vcallms as .word (N219)
#pragma push
#pragma opt_removeemptyloops off
#pragma opt_repositioncode off
// 0x00275220
bool GtIntersection::IntersectLine(const CGtLine &lLine, const CGtPolygonSoup &lPolygonSoup,
                                   bool (*lpCallback)(const CGtPolygonIntersectionResult &, void *), void *lpData)
{
    bool lbHasIntersected = false;
    CGtPolygonIntersectionResult lResult;
    unsigned int luPolygonSize = lPolygonSoup.mu8PolygonSize;
    unsigned char *luPolygonAddress = (unsigned char *)lPolygonSoup.mpPolygons;
    CGtPolygonSoupVertex *lpVertexArray = lPolygonSoup.mpVertices;
    unsigned char *luLastPolygonAddress = luPolygonAddress + luPolygonSize * lPolygonSoup.mu8PolygonCount;
    unsigned char luPolyIndexA = 0;
    unsigned char luPolyIndexB = 1;
    unsigned char luPolyIndexC = 2;
    unsigned int luTriangle = 0;
    if (CGtVu0CodeManager::GetCurrentVu0CodePointer() != (void *)vu_game_004787D0) {
        if (CGtVu0CodeManager::UploadVu0Code((void *)vu_game_004787D0)) CGtVu0CodeManager::WaitForUploadToFinish();
    }
    while (luPolygonAddress < luLastPolygonAddress) {
        const CGtPolygonSoupVertex *lpVertexA = &lpVertexArray[luPolygonAddress[luPolyIndexA]];
        const CGtPolygonSoupVertex *lpVertexB = &lpVertexArray[luPolygonAddress[luPolyIndexB]];
        const CGtPolygonSoupVertex *lpVertexC = &lpVertexArray[luPolygonAddress[luPolyIndexC]];
        U128Types lData;
        int lbHit;
        asm volatile("ctc2.i %0, $vi0" : : "r"(lpVertexA));   // [C] retail writes vertex A's address to VI0 (hard-wired 0: no effect)
        asm volatile("lqc2 $vf2, 0(%0)" "\n\t" "lqc2 $vf4, 0x10(%0)" : : "r"(&lLine));
        asm volatile("qmtc2.ni %0, $vf5" : : "r"(func_00275220_inl3(lpVertexA)));
        asm volatile("qmtc2.ni %0, $vf6" : : "r"(func_00275220_inl3(lpVertexB)));
        asm volatile("qmtc2.ni %0, $vf7" : : "r"(func_00275220_inl3(lpVertexC)));
        asm volatile(".word 0x4A001EF8");   // vcallms 0x3D8 (N219 [G])
        asm volatile("cfc2.i %0, $vi1" : "=r"(lbHit));
        asm volatile("qmfc2.ni %0, $vf5" : "=r"(lData.mu128Data));
        if (lbHit) {
            lResult.mrPenetration = lData.marReal[0];
            lResult.mPoint = Interpolate(lLine.mStartPoint, lLine.mEndPoint, lData.marReal[0]);
            CGtV3d laVerts[3];
            laVerts[0] = lpVertexArray[luPolygonAddress[2]].GetGtV3d();
            laVerts[1] = lpVertexArray[luPolygonAddress[1]].GetGtV3d();
            laVerts[2] = lpVertexArray[luPolygonAddress[0]].GetGtV3d();
            CGtV3d n = CrossProduct(func_00275220_inl2(laVerts[1], laVerts[2]), func_00275220_inl2(laVerts[0], laVerts[2]));
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
