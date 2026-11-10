// NONMATCHING: IntersectLineNearest__14GtIntersectionFRC7CGtLineRC16CGtPolygonSoup16P28CGtPolygonIntersectionResult -- retail 959 / ours 1021 instructions, 995 in changed runs
// calls identical; loop/branch structure, result stores, VU program protocol right; residue: post-loop vector temps in GPRs vs retail stack homes (mnemonic-vcallms mode), offset CSE across GetVertex, scheduling; .word vcallms N219 + scoped pragmas [G]
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: every branch, call, store and VU op accounted for (pipelined 2-set microprogram loop, closest-hit update, final drain, normal from the three dequantised vertices)

// GtIntersection::IntersectLineNearest(const CGtLine&,const CGtPolygonSoup16&,CGtPolygonIntersectionResult*) -- drafted (draftO).
// [C] name: the mangled symbol in retail's tables; file GtIntersectionPS2.cpp (Revenge STABS, E dnat map). Area not
// evidenced. Layouts [L]: Revenge STABS types (CGtPolygonSoup16, CGtPolygonSoupVertex16, CGtPolygonSoupPolygonBase,
// CGtLine, CGtPolygonIntersectionResult, U128Types, EGtIntersectionResult); locals named from Revenge's
// IntersectLineNearest(CGtPolygonSoup16) STABS [L]. The VU0 microprogram (vu_game_004787D0; entries 0x388 start, 0x550 /
// 0x390 the two pipelined triangle sets) reads fixed VF registers, so its loads, vcallms and result moves are inline asm
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
class GtIntersection {
public:
    static EGtIntersectionResult IntersectLineNearest(const CGtLine &lLine, const CGtPolygonSoup16 &lPolygonSoup,
                                                      CGtPolygonIntersectionResult *lpPolygonIntersectionOut);
};

// [G] the packed integer vertex for the microprogram: x | y << 32 in the low half, z in the high half
static inline u_long128 func_00273BF0_inl3(const CGtPolygonSoupVertex16 *v)
{
    u_long128 q;
    unsigned long lo = ((unsigned long)v->mu16Y << 32) | (unsigned long)v->mu16X;
    asm("pcpyld %0, %1, %2" : "=r"(q) : "r"((unsigned long)v->mu16Z), "r"(lo));
    return q;
}

// [G] scoped pragmas: opt_repositioncode off as the proven GtIntersection siblings (N203 SetCode shape);
// opt_dead_assignments / opt_pulloutconstants off from a sweep (post-loop 786 -> 374 changed; they also add empty
// bltz joins retail lacks, prag1 caution). vcallms as .word (N219 [G]): the mnemonic adds andi on every lbu/lhu
// before it but gives retail's stack homes for the post-loop vector temps (any mnemonic in the function does).
#pragma push
#pragma opt_repositioncode off
#pragma opt_dead_assignments off
#pragma opt_pulloutconstants off
// 0x00273BF0
EGtIntersectionResult GtIntersection::IntersectLineNearest(const CGtLine &lLine, const CGtPolygonSoup16 &lPolygonSoup,
                                                           CGtPolygonIntersectionResult *lpPolygonIntersectionOut)
{
    unsigned int luPolygonSize = lPolygonSoup.mu8PolygonSize;
    unsigned char *luPolygonAddress = (unsigned char *)lPolygonSoup.mpPolygons;
    float lrClosestDistance = lpPolygonIntersectionOut->mrPenetration;
    CGtPolygonSoupVertex16 *lpu16VertexArray = lPolygonSoup.mpVertices;
    float lrClosestU = 0.0f;
    float lrClosestV = lrClosestU;
    unsigned int luClosestTriangle = 0;
    CGtPolygonSoupPolygonBase *lpClosestPolygon = 0;
    unsigned char *luLastPolygonAddress = luPolygonAddress + luPolygonSize * lPolygonSoup.mu8PolygonCount;
    bool lbUsingSecondSet = false;
    U128Types lInput;
    lInput.marReal[0] = (float)lPolygonSoup.mn8OffsetX;
    lInput.marReal[1] = (float)lPolygonSoup.mn8OffsetY;
    lInput.marReal[2] = (float)lPolygonSoup.mn8OffsetZ;
    CGtV3d lShift = (*(const CGtV3d *)&lInput) * 500.0f;
    float lrScale = 500.0f / 32768.0f;
    if (CGtVu0CodeManager::GetCurrentVu0CodePointer() != (void *)vu_game_004787D0) {
        if (CGtVu0CodeManager::UploadVu0Code((void *)vu_game_004787D0)) CGtVu0CodeManager::WaitForUploadToFinish();
    }
    CGtV3dPlus lShiftScale;
    lShiftScale.SetGtV3d(lShift);
    lShiftScale.SetPlus(lrScale);

    unsigned char luPolyIndexA = 0;
    unsigned char luPolyIndexB = 1;
    unsigned char luPolyIndexC = 2;
    unsigned int luTriangle = 0;
    CGtPolygonSoupPolygonBase *lpLastPolygon;
    unsigned int luLastTriangle;
    U128Types lData;
    int lbHit;
    {
        const CGtPolygonSoupVertex16 *lpVertexA = &lpu16VertexArray[luPolygonAddress[luPolyIndexA]];
        const CGtPolygonSoupVertex16 *lpVertexB = &lpu16VertexArray[luPolygonAddress[luPolyIndexB]];
        const CGtPolygonSoupVertex16 *lpVertexC = &lpu16VertexArray[luPolygonAddress[luPolyIndexC]];
        asm volatile("ctc2.i %0, $vi0" : : "r"(lpVertexA));
        asm volatile("lqc2 $vf2, 0(%0)" "\n\t" "lqc2 $vf4, 0x10(%0)" : : "r"(&lLine));
        asm volatile("qmtc2.ni %0, $vf23" : : "r"(lShiftScale.mData));
        asm volatile("qmtc2.ni %0, $vf5" : : "r"(func_00273BF0_inl3(lpVertexA)));
        asm volatile("qmtc2.ni %0, $vf6" : : "r"(func_00273BF0_inl3(lpVertexB)));
        asm volatile("qmtc2.ni %0, $vf7" : : "r"(func_00273BF0_inl3(lpVertexC)));
        asm volatile(".word 0x4A001C78");   // vcallms 0x388 (N219 [G])
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
            const CGtPolygonSoupVertex16 *lpVertexA = &lpu16VertexArray[luPolygonAddress[luPolyIndexA]];
            const CGtPolygonSoupVertex16 *lpVertexB = &lpu16VertexArray[luPolygonAddress[luPolyIndexB]];
            const CGtPolygonSoupVertex16 *lpVertexC = &lpu16VertexArray[luPolygonAddress[luPolyIndexC]];
            asm volatile("qmtc2.ni %0, $vf8" : : "r"(func_00273BF0_inl3(lpVertexA)));
            asm volatile("qmtc2.ni %0, $vf9" : : "r"(func_00273BF0_inl3(lpVertexB)));
            asm volatile("qmtc2.ni %0, $vf10" : : "r"(func_00273BF0_inl3(lpVertexC)));
            asm volatile(".word 0x4A002AB8");   // vcallms 0x550 (N219 [G])
            asm volatile("cfc2.ni %0, $vi1" : "=r"(lbHit));
            asm volatile("qmfc2.i %0, $vf24" : "=r"(lData.mu128Data));
        }
        lbUsingSecondSet = true;
        if (lbHit && lData.marReal[0] < lrClosestDistance) {
            lrClosestU = lData.marReal[1];
            lpClosestPolygon = lpLastPolygon;
            lrClosestV = lData.marReal[2];
            luClosestTriangle = luLastTriangle;
            lrClosestDistance = lData.marReal[0];
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
            const CGtPolygonSoupVertex16 *lpVertexA = &lpu16VertexArray[luPolygonAddress[luPolyIndexA]];
            const CGtPolygonSoupVertex16 *lpVertexB = &lpu16VertexArray[luPolygonAddress[luPolyIndexB]];
            const CGtPolygonSoupVertex16 *lpVertexC = &lpu16VertexArray[luPolygonAddress[luPolyIndexC]];
            asm volatile("qmtc2.ni %0, $vf5" : : "r"(func_00273BF0_inl3(lpVertexA)));
            asm volatile("qmtc2.ni %0, $vf6" : : "r"(func_00273BF0_inl3(lpVertexB)));
            asm volatile("qmtc2.ni %0, $vf7" : : "r"(func_00273BF0_inl3(lpVertexC)));
            asm volatile(".word 0x4A001CB8");   // vcallms 0x390 (N219 [G])
            asm volatile("cfc2.ni %0, $vi2" : "=r"(lbHit));
            asm volatile("qmfc2.i %0, $vf8" : "=r"(lData.mu128Data));
        }
        lbUsingSecondSet = false;
        if (lbHit && lData.marReal[0] < lrClosestDistance) {
            lrClosestU = lData.marReal[1];
            lpClosestPolygon = lpLastPolygon;
            lrClosestV = lData.marReal[2];
            luClosestTriangle = luLastTriangle;
            lrClosestDistance = lData.marReal[0];
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
        asm volatile("qmfc2.i %0, $vf8" : "=r"(lData.mu128Data));
        lbHasIntersected = h;
    } else {
        int h;
        asm volatile("cfc2.i %0, $vi1" : "=r"(h));
        asm volatile("qmfc2.i %0, $vf24" : "=r"(lData.mu128Data));
        lbHasIntersected = h;
    }
    if (lbHasIntersected && lData.marReal[0] < lrClosestDistance) {
        lrClosestU = lData.marReal[1];
        lpClosestPolygon = lpLastPolygon;
        lrClosestV = lData.marReal[2];
        luClosestTriangle = luLastTriangle;
        lrClosestDistance = lData.marReal[0];
    }
    if (lpClosestPolygon == 0) return eGtIR_Outside;
    lpPolygonIntersectionOut->mPoint = Interpolate(lLine.mStartPoint, lLine.mEndPoint, lrClosestDistance);
    if (luClosestTriangle == 0) {
        CGtV3d laClosestVerts[3];
        laClosestVerts[0] = lPolygonSoup.GetVertex(lpClosestPolygon->mau8Indices[2]);
        laClosestVerts[1] = lPolygonSoup.GetVertex(lpClosestPolygon->mau8Indices[1]);
        laClosestVerts[2] = lPolygonSoup.GetVertex(lpClosestPolygon->mau8Indices[0]);
        CGtV3d n = CrossProduct(func_00273BF0_inl2(laClosestVerts[1], laClosestVerts[2]),
                                func_00273BF0_inl2(laClosestVerts[0], laClosestVerts[2]));
        n.Normalise();
        lpPolygonIntersectionOut->mNormal = n;
    } else {
        CGtV3d laClosestVerts[3];
        laClosestVerts[0] = lPolygonSoup.GetVertex(lpClosestPolygon->mau8Indices[3]);
        laClosestVerts[1] = lPolygonSoup.GetVertex(lpClosestPolygon->mau8Indices[1]);
        laClosestVerts[2] = lPolygonSoup.GetVertex(lpClosestPolygon->mau8Indices[2]);
        CGtV3d n = CrossProduct(func_00273BF0_inl2(laClosestVerts[1], laClosestVerts[2]),
                                func_00273BF0_inl2(laClosestVerts[0], laClosestVerts[2]));
        n.Normalise();
        lpPolygonIntersectionOut->mNormal = n;
    }
    lpPolygonIntersectionOut->mrPenetration = lrClosestDistance;
    lpPolygonIntersectionOut->mpPolygon = lpClosestPolygon;
    lpPolygonIntersectionOut->mpVertices = lpu16VertexArray;
    lpPolygonIntersectionOut->muTriangle = luClosestTriangle;
    lpPolygonIntersectionOut->mrU = lrClosestU;
    lpPolygonIntersectionOut->mrV = lrClosestV;
    return eGtIR_Intersect;
}
#pragma pop
