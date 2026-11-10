// NONMATCHING: IntersectLineNearest__14GtIntersectionFRC7CGtLineRC14CGtPolygonSoupP28CGtPolygonIntersectionResult -- retail 462 / ours 470 instructions, 294 in changed runs
// calls identical; loop/branch structure, result stores, VU program protocol right (clone of the Soup16 overload); residue: post-loop vector temps in GPRs vs retail stack homes, lwu load order, uninitialised ctc2 operand homed in a register (retail stack 0xBE); .word vcallms N219 + scoped pragmas [G]
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: every branch, call, store and VU op accounted for (pipelined 2-set microprogram loop, closest-hit update, final drain, normal from the three closest vertices)

// GtIntersection::IntersectLineNearest(const CGtLine&,const CGtPolygonSoup&,CGtPolygonIntersectionResult*) -- drafted (draftO),
// cloned from the CGtPolygonSoup16 overload (0x273BF0, same file) with float vertices.
// [C] name: the mangled symbol in retail's tables; file GtIntersectionPS2.cpp (Revenge STABS, E dnat map). Area not
// evidenced. Layouts [L]: Revenge STABS types (CGtPolygonSoup, CGtPolygonSoupVertex, CGtPolygonSoupPolygonBase,
// CGtLine, CGtPolygonIntersectionResult, U128Types, EGtIntersectionResult); locals named from Revenge's
// IntersectLineNearest(CGtPolygonSoup) STABS [L]. The VU0 microprogram (vu_game_004787D0; entries 0x3D8 start, 0x598 /
// 0x3E0 the two pipelined triangle sets) reads fixed VF registers, so its loads, vcallms and result moves are inline asm
// (N208); the code upload is the inlined CGtVu0CodeManager::UploadVu0Code (N203).
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
static inline CGtV3d func_002755E0_inl2(const CGtV3d &a, const CGtV3d &b)
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
class GtIntersection {
public:
    static EGtIntersectionResult IntersectLineNearest(const CGtLine &lLine, const CGtPolygonSoup &lPolygonSoup,
                                                      CGtPolygonIntersectionResult *lpPolygonIntersectionOut);
};

// [G] the vertex's three words packed into one quad for the microprogram (as func_00274ED0's GetGtV3d)
static inline u_long128 func_002755E0_inl3(const CGtPolygonSoupVertex *v)
{
    const unsigned int *w = (const unsigned int *)v;
    u_long128 q;
    unsigned long lo = ((unsigned long)w[1] << 32) | (unsigned long)w[0];
    asm("pcpyld %0, %1, %2" : "=r"(q) : "r"((unsigned long)w[2]), "r"(lo));
    return q;
}

// [G] scoped pragmas: opt_repositioncode off as the proven GtIntersection siblings (N203 SetCode shape);
// opt_lifetimes / opt_propagation off from a sweep (435 -> 294 changed). vcallms as .word (N219 [G]): the mnemonic
// adds andi on every lbu before it but gives retail's stack homes for the post-loop vector temps.
#pragma push
#pragma opt_repositioncode off
#pragma opt_lifetimes off
#pragma opt_propagation off
// 0x002755E0
EGtIntersectionResult GtIntersection::IntersectLineNearest(const CGtLine &lLine, const CGtPolygonSoup &lPolygonSoup,
                                                           CGtPolygonIntersectionResult *lpPolygonIntersectionOut)
{
    float lrClosestDistance = 1.0f;
    unsigned int luClosestTriangle = 0;
    CGtPolygonSoupPolygonBase *lpClosestPolygon = 0;
    unsigned int luPolygonSize = lPolygonSoup.mu8PolygonSize;
    unsigned char *luPolygonAddress = (unsigned char *)lPolygonSoup.mpPolygons;
    CGtPolygonSoupVertex *lpVertexArray = lPolygonSoup.mpVertices;
    float lrClosestU = 0.0f;
    float lrClosestV = lrClosestU;
    bool lbUsingSecondSet = false;
    unsigned char *luLastPolygonAddress = luPolygonAddress + luPolygonSize * lPolygonSoup.mu8PolygonCount;
    if (CGtVu0CodeManager::GetCurrentVu0CodePointer() != (void *)vu_game_004787D0) {
        if (CGtVu0CodeManager::UploadVu0Code((void *)vu_game_004787D0)) CGtVu0CodeManager::WaitForUploadToFinish();
    }

    unsigned char luPolyIndexA = 0;
    unsigned char luPolyIndexB = 1;
    unsigned char luPolyIndexC = 2;
    unsigned int luTriangle = 0;
    CGtPolygonSoupPolygonBase *lpLastPolygon;
    unsigned int luLastTriangle;
    U128Types luResults;
    int lbHit;
    {
        const CGtPolygonSoupVertex *lpVertexA = &lpVertexArray[luPolygonAddress[luPolyIndexA]];
        const CGtPolygonSoupVertex *lpVertexB = &lpVertexArray[luPolygonAddress[luPolyIndexB]];
        const CGtPolygonSoupVertex *lpVertexC = &lpVertexArray[luPolygonAddress[luPolyIndexC]];
        volatile unsigned short t;
        asm volatile("ctc2.i %0, $vi0" : : "r"(t));   // [L] retail reads an uninitialised 16-bit stack local here
        asm volatile("lqc2 $vf2, 0(%0)" "\n\t" "lqc2 $vf4, 0x10(%0)" : : "r"(&lLine));
        asm volatile("qmtc2.ni %0, $vf5" : : "r"(func_002755E0_inl3(lpVertexA)));
        asm volatile("qmtc2.ni %0, $vf6" : : "r"(func_002755E0_inl3(lpVertexB)));
        asm volatile("qmtc2.ni %0, $vf7" : : "r"(func_002755E0_inl3(lpVertexC)));
        asm volatile(".word 0x4A001EF8");   // vcallms 0x3D8 (N219 [G])
    }
    lpLastPolygon = (CGtPolygonSoupPolygonBase *)luPolygonAddress;
    luLastTriangle = luTriangle;
    if (luTriangle == 0 && luPolygonAddress[3] < 0xFFu) {
        luTriangle = 1; luPolyIndexA = 2; luPolyIndexB = 1; luPolyIndexC = 3;
    } else {
        luTriangle = 0; luPolyIndexA = 0; luPolyIndexB = 1; luPolyIndexC = 2;
        luPolygonAddress += luPolygonSize;
    }
    while (luPolygonAddress < luLastPolygonAddress) {
        {
            const CGtPolygonSoupVertex *lpVertexA = &lpVertexArray[luPolygonAddress[luPolyIndexA]];
            const CGtPolygonSoupVertex *lpVertexB = &lpVertexArray[luPolygonAddress[luPolyIndexB]];
            const CGtPolygonSoupVertex *lpVertexC = &lpVertexArray[luPolygonAddress[luPolyIndexC]];
            asm volatile("qmtc2.ni %0, $vf8" : : "r"(func_002755E0_inl3(lpVertexA)));
            asm volatile("qmtc2.ni %0, $vf9" : : "r"(func_002755E0_inl3(lpVertexB)));
            asm volatile("qmtc2.ni %0, $vf10" : : "r"(func_002755E0_inl3(lpVertexC)));
            asm volatile(".word 0x4A002CF8");   // vcallms 0x598 (N219 [G])
            asm volatile("cfc2.ni %0, $vi1" : "=r"(lbHit));
            asm volatile("qmfc2.i %0, $vf5" : "=r"(luResults.mu128Data));
        }
        lbUsingSecondSet = true;
        if (lbHit && luResults.marReal[0] < lrClosestDistance) {
            lrClosestU = luResults.marReal[1];
            lpClosestPolygon = lpLastPolygon;
            lrClosestV = luResults.marReal[2];
            luClosestTriangle = luLastTriangle;
            lrClosestDistance = luResults.marReal[0];
        }
        lpLastPolygon = (CGtPolygonSoupPolygonBase *)luPolygonAddress;
        luLastTriangle = luTriangle;
        if (luTriangle == 0 && luPolygonAddress[3] < 0xFFu) {
            luTriangle = 1; luPolyIndexA = 2; luPolyIndexB = 1; luPolyIndexC = 3;
        } else {
            luTriangle = 0; luPolyIndexA = 0; luPolyIndexB = 1; luPolyIndexC = 2;
            luPolygonAddress += luPolygonSize;
        }
        if (luPolygonAddress >= luLastPolygonAddress) break;
        {
            const CGtPolygonSoupVertex *lpVertexA = &lpVertexArray[luPolygonAddress[luPolyIndexA]];
            const CGtPolygonSoupVertex *lpVertexB = &lpVertexArray[luPolygonAddress[luPolyIndexB]];
            const CGtPolygonSoupVertex *lpVertexC = &lpVertexArray[luPolygonAddress[luPolyIndexC]];
            asm volatile("qmtc2.ni %0, $vf5" : : "r"(func_002755E0_inl3(lpVertexA)));
            asm volatile("qmtc2.ni %0, $vf6" : : "r"(func_002755E0_inl3(lpVertexB)));
            asm volatile("qmtc2.ni %0, $vf7" : : "r"(func_002755E0_inl3(lpVertexC)));
            asm volatile(".word 0x4A001F38");   // vcallms 0x3E0 (N219 [G])
            asm volatile("cfc2.ni %0, $vi2" : "=r"(lbHit));
            asm volatile("qmfc2.i %0, $vf8" : "=r"(luResults.mu128Data));
        }
        lbUsingSecondSet = false;
        if (lbHit && luResults.marReal[0] < lrClosestDistance) {
            lrClosestU = luResults.marReal[1];
            lpClosestPolygon = lpLastPolygon;
            lrClosestV = luResults.marReal[2];
            luClosestTriangle = luLastTriangle;
            lrClosestDistance = luResults.marReal[0];
        }
        lpLastPolygon = (CGtPolygonSoupPolygonBase *)luPolygonAddress;
        luLastTriangle = luTriangle;
        if (luTriangle == 0 && luPolygonAddress[3] < 0xFFu) {
            luTriangle = 1; luPolyIndexA = 2; luPolyIndexB = 1; luPolyIndexC = 3;
        } else {
            luTriangle = 0; luPolyIndexA = 0; luPolyIndexB = 1; luPolyIndexC = 2;
            luPolygonAddress += luPolygonSize;
        }
    }
    unsigned short lbHasIntersected;
    if (lbUsingSecondSet) {
        int h;
        asm volatile("cfc2.i %0, $vi2" : "=r"(h));
        asm volatile("qmfc2.i %0, $vf8" : "=r"(luResults.mu128Data));
        lbHasIntersected = h;
    } else {
        int h;
        asm volatile("cfc2.i %0, $vi1" : "=r"(h));
        asm volatile("qmfc2.i %0, $vf5" : "=r"(luResults.mu128Data));
        lbHasIntersected = h;
    }
    if (lbHasIntersected && luResults.marReal[0] < lrClosestDistance) {
        lrClosestU = luResults.marReal[1];
        lpClosestPolygon = lpLastPolygon;
        lrClosestV = luResults.marReal[2];
        luClosestTriangle = luLastTriangle;
        lrClosestDistance = luResults.marReal[0];
    }
    if (lpClosestPolygon == 0) return eGtIR_Outside;
    lpPolygonIntersectionOut->mPoint = Interpolate(lLine.mStartPoint, lLine.mEndPoint, lrClosestDistance);
    if (luClosestTriangle == 0) {
        CGtV3d laClosestVerts[3];
        laClosestVerts[0] = lpVertexArray[lpClosestPolygon->mau8Indices[2]].GetGtV3d();
        laClosestVerts[1] = lpVertexArray[lpClosestPolygon->mau8Indices[1]].GetGtV3d();
        laClosestVerts[2] = lpVertexArray[lpClosestPolygon->mau8Indices[0]].GetGtV3d();
        CGtV3d n = CrossProduct(func_002755E0_inl2(laClosestVerts[1], laClosestVerts[2]),
                                func_002755E0_inl2(laClosestVerts[0], laClosestVerts[2]));
        n.Normalise();
        lpPolygonIntersectionOut->mNormal = n;
    } else {
        CGtV3d laClosestVerts[3];
        laClosestVerts[0] = lpVertexArray[lpClosestPolygon->mau8Indices[3]].GetGtV3d();
        laClosestVerts[1] = lpVertexArray[lpClosestPolygon->mau8Indices[1]].GetGtV3d();
        laClosestVerts[2] = lpVertexArray[lpClosestPolygon->mau8Indices[2]].GetGtV3d();
        CGtV3d n = CrossProduct(func_002755E0_inl2(laClosestVerts[1], laClosestVerts[2]),
                                func_002755E0_inl2(laClosestVerts[0], laClosestVerts[2]));
        n.Normalise();
        lpPolygonIntersectionOut->mNormal = n;
    }
    lpPolygonIntersectionOut->mrPenetration = lrClosestDistance;
    lpPolygonIntersectionOut->mpPolygon = lpClosestPolygon;
    lpPolygonIntersectionOut->mpVertices = lpVertexArray;
    lpPolygonIntersectionOut->muTriangle = luClosestTriangle;
    lpPolygonIntersectionOut->mrU = lrClosestU;
    lpPolygonIntersectionOut->mrV = lrClosestV;
    return eGtIR_Intersect;
}
#pragma pop
