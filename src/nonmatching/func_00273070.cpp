// NONMATCHING: func_00273070 -- retail 228 / ours 226 instructions, 163 in changed runs
// draftAN fork B C-first: [L] GtIntersection::IntersectSphere(CGtSphere, const CGtPolygonSoup16&, cb, void*) (E map 0x28ed80; the Soup16 leaf call of the archived CGtCollisionKDTree::IntersectSphere func_003BE9B0): r^2 in xyz, offset x 500 + scale 500/32768 in w, VU0 upload, per triangle the sphere microprogram (entry 0x28 with 3 raw u16 vertices; a quad's 2nd triangle entry 0x0 reusing the dequantised vertices 2/1 from maVertices[2]/[1] + raw vertex 3), normal + 3 vertices stored after every call, on a hit polygon/triangle/vertex array -> callback, false stops with 0; 226/228, calls identical (callback through t9 vs s6)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm with the archived siblings func_00274ED0 / func_00273400: the VU register protocol (VF1-VF6, VI1, VF8), both vcallms entries (.word 0x4A000178 / 0x4A000038 = retail bytes), the result stores, the hit / callback / quad-advance branches traced; mPoint/mrPenetration/U/V never written (as retail)

// func_00273070 -- draftAN fork B (C-first draft). 0x273070, 0x390. Unnamed in every table, so a placeholder with C linkage.
// [L] GtIntersection::IntersectSphere(GtMathPs2::CGtSphere, const CGtPolygonSoup16&, bool (*)(const CGtPolygonIntersectionResult&,
// void*), void*) (E B3O0PCH map row 0x28ed80, no symbol form in retail): the archived CGtCollisionKDTree::IntersectSphere
// (func_003BE9B0) calls it for Soup16 leaves where it calls func_00274ED0 (the CGtPolygonSoup overload, [C] E dnat) otherwise;
// same soup header reads as func_00273400 (the Soup16 line overload). Types / helpers from those two archives.
// What it does [L]: radius^2 into the three lanes of a CGtV3d, the soup offset x 500 with w = 500/32768 (dequantise scale), the
// VU0 code upload, then per triangle the VU0 sphere/triangle microprogram (vu_game_004787D0): the first triangle of a polygon
// (indices 0,1,2) through entry 0x28 with the three raw u16 vertices in VF4-VF6, a quad's second triangle (2,1,3) through entry
// 0x0 with VF4 / VF5 = the dequantised vertices 2 / 1 the first call left in the result's maVertices[2] / [1] and the raw
// vertex 3 in VF6. After every call the result's mNormal = VF8 and maVertices = VF4-VF6 (also without a hit); on a hit (VI1 low
// 16 bits) the result gets the polygon, the triangle (0 / 1) and the vertex array, and goes to the callback; false stops with 0.
// Returns whether anything was hit. [C] mPoint / mrPenetration / mrU / mrV are never written (the callback sees stack garbage).
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
static inline CGtV3d func_00273070_inl1(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
static inline CGtV3d func_00273070_inl2(const CGtV3d &a, const CGtV3d &b)
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
    v = func_00273070_inl1(v * (1.0f / 65536.0f) * 1000.0f, lOffset);
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
static inline u_long128 func_00273070_inl3(const CGtPolygonSoupVertex16 *v)
{
    u_long128 q;
    unsigned long lo = ((unsigned long)v->mu16Y << 32) | (unsigned long)v->mu16X;
    asm("pcpyld %0, %1, %2" : "=r"(q) : "r"((unsigned long)v->mu16Z), "r"(lo));
    return q;
}


// [G] stand-in for the E-map GtMathPs2::operator*(WAxisType, WAxisType) (queued header gap; as func_00274ED0_inl1)
static inline WAxisType func_00273070_inl4(WAxisType w)
{
    u_long128 t = w.lVector;
    asm("vmulw.w %0, %0, %0w" : "+j"(t));
    return WAxisType(t);
}

typedef bool (*UnkFunc_00273070_cb)(const CGtPolygonIntersectionResult &, void *);

// [G] scoped pragmas as the archived siblings (func_00273400 / func_00274ED0); vcallms as .word (N219)
#pragma push
#pragma opt_removeemptyloops off
#pragma opt_repositioncode off
// 0x00273070
extern "C" int func_00273070(const CGtSphere lSphere, const CGtPolygonSoup16 &lPolygonSoup, UnkFunc_00273070_cb lpCallback, void *lpData)
{
    int lbHasIntersected = 0;
    CGtPolygonIntersectionResult lResult;
    unsigned int luPolygonSize = lPolygonSoup.mu8PolygonSize;
    unsigned char *luPolygonAddress = (unsigned char *)lPolygonSoup.mpPolygons;
    CGtPolygonSoupVertex16 *lpu16VertexArray = lPolygonSoup.mpVertices;
    unsigned char *luLastPolygonAddress = luPolygonAddress + luPolygonSize * lPolygonSoup.mu8PolygonCount;
    unsigned int luTriangle = 0;
    float lrScale = 500.0f / 32768.0f;
    if (CGtVu0CodeManager::GetCurrentVu0CodePointer() != (void *)vu_game_004787D0) {
        if (CGtVu0CodeManager::UploadVu0Code((void *)vu_game_004787D0)) CGtVu0CodeManager::WaitForUploadToFinish();
    }
    float lrRadiusSq = func_00273070_inl4(lSphere.Radius());
    U128Types lInput;
    lInput.marReal[0] = (float)lPolygonSoup.mn8OffsetX;
    lInput.marReal[1] = (float)lPolygonSoup.mn8OffsetY;
    lInput.marReal[2] = (float)lPolygonSoup.mn8OffsetZ;
    CGtV3d lRadiusSq;
    lRadiusSq.SetX(lrRadiusSq);
    lRadiusSq.SetY(lrRadiusSq);
    lRadiusSq.SetZ(lrRadiusSq);
    CGtV3dPlus lShiftScale;
    lShiftScale.SetGtV3d((*(const CGtV3d *)&lInput) * 500.0f);
    lShiftScale.SetPlus(lrScale);
    while (luPolygonAddress < luLastPolygonAddress) {
        int lbHit;
        if (luTriangle == 0) {
            const CGtPolygonSoupVertex16 *lpVertexA = &lpu16VertexArray[luPolygonAddress[0]];
            const CGtPolygonSoupVertex16 *lpVertexB = &lpu16VertexArray[luPolygonAddress[1]];
            const CGtPolygonSoupVertex16 *lpVertexC = &lpu16VertexArray[luPolygonAddress[2]];
            asm volatile("ctc2.i %0, $vi0" : : "r"(lpVertexA));   // [C] retail writes vertex A's address to VI0 (hard-wired 0: no effect)
            asm volatile("lqc2 $vf2, 0(%0)" : : "r"(&lSphere));
            asm volatile("lqc2 $vf3, 0(%0)" "\n\t" "lqc2 $vf1, 0(%1)" : : "r"(&lRadiusSq), "r"(&lShiftScale));
            asm volatile("qmtc2.ni %0, $vf4" : : "r"(func_00273070_inl3(lpVertexA)));
            asm volatile("qmtc2.ni %0, $vf5" : : "r"(func_00273070_inl3(lpVertexB)));
            asm volatile("qmtc2.ni %0, $vf6" : : "r"(func_00273070_inl3(lpVertexC)));
            asm volatile(".word 0x4A000178");   // vcallms 0x28
            asm volatile("cfc2.i %0, $vi1" : "=r"(lbHit));
        } else {
            const CGtPolygonSoupVertex16 *lpVertexD = &lpu16VertexArray[luPolygonAddress[3]];
            asm volatile("lqc2 $vf2, 0(%0)" : : "r"(&lSphere));
            asm volatile("lqc2 $vf3, 0(%0)" "\n\t" "lqc2 $vf1, 0(%1)" : : "r"(&lRadiusSq), "r"(&lShiftScale));
            asm volatile("lqc2 $vf4, 0x40(%0)" "\n\t" "lqc2 $vf5, 0x30(%0)" : : "r"(&lResult));
            asm volatile("qmtc2.ni %0, $vf6" : : "r"(func_00273070_inl3(lpVertexD)));
            asm volatile(".word 0x4A000038");   // vcallms 0x0
            asm volatile("cfc2.i %0, $vi1" : "=r"(lbHit));
        }
        asm volatile("sqc2 $vf8, 0x10(%0)" "\n\t" "sqc2 $vf4, 0x20(%0)" "\n\t" "sqc2 $vf5, 0x30(%0)" "\n\t" "sqc2 $vf6, 0x40(%0)"
                     : : "r"(&lResult) : "memory");
        if (lbHit & 0xFFFF) {
            lResult.mpPolygon = (CGtPolygonSoupPolygonBase *)luPolygonAddress;
            lResult.mpVertices = lpu16VertexArray;
            lResult.muTriangle = luTriangle;
            if (!lpCallback(lResult, lpData)) return 0;
            lbHasIntersected = 1;
        }
        if (luPolygonAddress[3] < 0xFFu && luTriangle == 0) {
            luTriangle = 1;
        } else {
            luPolygonAddress += luPolygonSize;
            luTriangle = 0;
        }
    }
    return lbHasIntersected;
}
#pragma pop
