// NONMATCHING: func_00274ED0 -- retail 210 / ours 208 instructions, 84 in changed runs
// 84 changed (210 vs 208), frame 0x1A0 vs 0x190: .word vcallms + 3 scoped pragmas [G] (contradicts N208); left: radius kept copy, qmfc2 delay slot, lane mfc1 scheduling, lwu lo/hi order, tri-2 registers
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00274ED0 -- hand-written (gti; from vcm). [C] name (no symbol form: the table name is truncated): E dnat map /
// retail_names.csv GtIntersection::IntersectSphere(GtMathPs2::CGtSphere,const CGtPolygonSoup&,bool (*)(const
// CGtPolygonIntersectionResult&,void*),void*); file GtIntersectionPS2.cpp. Area not evidenced. Layouts [L]: Revenge types.h
// (CGtPolygonSoup, CGtPolygonSoupVertex, CGtPolygonSoupPolygonBase, CGtPolygonIntersectionResult). The VU0 microprogram
// (vu_game_004787D0, entry 0x60) reads fixed VF registers, so its loads, vcallms and cfc2 are inline asm (N208); the code
// upload is the inlined CGtVu0CodeManager::UploadVu0Code (N203).
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
        return 0;
    } else {
        gmpCurrentVu0Code = code;
        if (code) {
            *(volatile unsigned int *)0x10008020 = 0;
            *(volatile unsigned int *)0x10008030 = (unsigned int)code;
            *(volatile unsigned int *)0x10008000 = 0x145;
            return true;
        } else {
            return 0;
        }
    }
}
inline void CGtVu0CodeManager::WaitForUploadToFinish()
{
    while (sceDmaSync(sceDmaGetChan(0), 1, 0) != 0) {}
}
extern char vu_game_004787D0[];
struct CGtPolygonSoupVertex {
    float mrX; float mrY; float mrZ;
    CGtV3d GetGtV3d() const;   // [L] Revenge types.h; body [G]: the three words packed into one quad
};
inline CGtV3d CGtPolygonSoupVertex::GetGtV3d() const
{
    const unsigned int *w = (const unsigned int *)this;
    u_long128 q;
    unsigned long lo = ((unsigned long)w[1] << 32) | (unsigned long)w[0];
    asm("pcpyld %0, %1, %2" : "=r"(q) : "r"((unsigned long)w[2]), "r"(lo));
    return CGtV3d(q);
}
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
class CGtPolygonIntersectionResult {
public:
    CGtPolygonIntersectionResult() {}   // [L] Revenge types.h declares it; body [G]
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
// [G] stand-in for GtMathPs2 API the header lacks (E map: operator *(WAxisType,WAxisType))
static inline WAxisType func_00274ED0_inl1(WAxisType w)
{
    u_long128 t = w.lVector;
    asm("vmulw.w %0, %0, %0w" : "+j"(t));
    return WAxisType(t);
}
static inline void func_00274ED0_inl2(CGtV3d &v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.x %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_00274ED0_inl3(CGtV3d &v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.y %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_00274ED0_inl4(CGtV3d &v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.z %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
// gti (2026-10-27) [G] EXPERIMENT, contradicts N208: vcallms written as `.word 0x4A000338` (vcallms 0x60) plus scoped
// opt_removeemptyloops/opt_repositioncode/opt_dead_assignments off. Evidence for it: retail's triangle blocks have the
// lw+zext -> lwu fold, no andi on the lbu indices and forwarded GetGtV3d temps -- the mnemonic loses all three in the block
// it ends (probes build/vt/hand/gti_p1..p9). Evidence against: the radius block's kept 0xF0 -> 0x80 copy and the unfilled
// `beqz; nop` after qmfc2 vf8 (mnemonic-only shapes). Left: those two, lane-set mfc1 scheduling, lwu lo/hi load order,
// triangle-2 register choice, frame 0x1A0 vs 0x190 (one 16-byte slot too many between the copy and rv).
#pragma push
#pragma opt_removeemptyloops off
#pragma opt_repositioncode off
#pragma opt_dead_assignments off
// 0x00274ED0
extern "C" int func_00274ED0(const CGtSphere s, const CGtPolygonSoup &soup, bool (*cb)(const CGtPolygonIntersectionResult &, void *),
                              void *data)
{
    int hit = 0;
    CGtPolygonIntersectionResult res;
    unsigned int size = soup.mu8PolygonSize;
    CGtPolygonSoupPolygonBase *p = (CGtPolygonSoupPolygonBase *)soup.mpPolygons;
    CGtPolygonSoupVertex *vtx = soup.mpVertices;
    CGtPolygonSoupPolygonBase *end = (CGtPolygonSoupPolygonBase *)((unsigned char *)p + size * soup.mu8PolygonCount);
    if (CGtVu0CodeManager::GetCurrentVu0CodePointer() != (void *)vu_game_004787D0) {
        if (CGtVu0CodeManager::UploadVu0Code((void *)vu_game_004787D0)) CGtVu0CodeManager::WaitForUploadToFinish();
    }
    CGtV3d rv;
    float r = func_00274ED0_inl1(s.Radius());
    func_00274ED0_inl2(rv, r);
    func_00274ED0_inl3(rv, r);
    func_00274ED0_inl4(rv, r);
    for (; p < end; p = (CGtPolygonSoupPolygonBase *)((unsigned char *)p + size)) {
        {
            const CGtPolygonSoupVertex *a = &vtx[p->mau8Indices[0]];
            const CGtPolygonSoupVertex *b = &vtx[p->mau8Indices[1]];
            const CGtPolygonSoupVertex *c = &vtx[p->mau8Indices[2]];
            int h;
            u_long128 n;
            asm volatile("lqc2 $vf2, 0(%0)" "\n\t" "lqc2 $vf3, 0(%1)" : : "r"(&s), "r"(&rv));
            asm volatile("qmtc2 %0, $vf4" : : "r"(a->GetGtV3d().mData));
            asm volatile("qmtc2 %0, $vf5" : : "r"(b->GetGtV3d().mData));
            asm volatile("qmtc2 %0, $vf6" : : "r"(c->GetGtV3d().mData));
            asm volatile(".word 0x4A000338");
            asm volatile("cfc2.i %0, $vi1" : "=r"(h));
            asm volatile("qmfc2 %0, $vf8" : "=r"(n));
            if (h) {
                res.mNormal.mData = n;
                res.mpPolygon = p;
                res.mpVertices = vtx;
                res.muTriangle = 0;
                if (!cb(res, data)) return 0;
                hit = 1;
            }
        }
        if (p->mau8Indices[3] < 0xFFu) {
        {
            const CGtPolygonSoupVertex *a = &vtx[p->mau8Indices[2]];
            const CGtPolygonSoupVertex *b = &vtx[p->mau8Indices[1]];
            const CGtPolygonSoupVertex *c = &vtx[p->mau8Indices[3]];
            int h;
            u_long128 n;
            asm volatile("lqc2 $vf2, 0(%0)" "\n\t" "lqc2 $vf3, 0(%1)" : : "r"(&s), "r"(&rv));
            asm volatile("qmtc2 %0, $vf4" : : "r"(a->GetGtV3d().mData));
            asm volatile("qmtc2 %0, $vf5" : : "r"(b->GetGtV3d().mData));
            asm volatile("qmtc2 %0, $vf6" : : "r"(c->GetGtV3d().mData));
            asm volatile(".word 0x4A000338");
            asm volatile("cfc2.i %0, $vi1" : "=r"(h));
            asm volatile("qmfc2 %0, $vf8" : "=r"(n));
            if (h) {
                res.mNormal.mData = n;
                res.mpPolygon = p;
                res.muTriangle = 1;
                res.mpVertices = vtx;
                if (!cb(res, data)) return 0;
                hit = 1;
            }
        }
        }
    }
    return hit;
}
#pragma pop
