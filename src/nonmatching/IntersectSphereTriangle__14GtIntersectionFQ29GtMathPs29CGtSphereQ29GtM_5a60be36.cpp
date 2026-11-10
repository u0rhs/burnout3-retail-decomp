// NONMATCHING: IntersectSphereTriangle__14GtIntersectionFQ29GtMathPs29CGtSphereQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3d -- retail 96 / ours 97 instructions, 76 in changed runs
// logic complete, 97/96. b119: a real vcallms disables VU move folds in the whole function (vcallms is .word-encoded here [G]); any asm volatile in the block disables scheduling (retail hoists the 7 address addiu's and interleaves the 3 mfc1), non-volatile no-output asm is deleted per instruction. Missing: WAxisType temp at 0x80 + copy (frame 0xD0 vs 0xE0). setc
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// GtIntersection::IntersectSphereTriangle(CGtSphere,CGtV3d,CGtV3d,CGtV3d,CGtV3d*) -- hand-written (setc).
// [C] name: the mangled symbol in retail's tables; file: GtIntersectionPS2.cpp (E dnat map). Area not evidenced.
// The VU0 microprogram reads fixed VF registers, so its loads, vcallms and cfc2 are inline asm; the code upload is the
// inlined CGtVu0CodeManager::UploadVu0Code (N203).
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
class GtIntersection { public: static bool IntersectSphereTriangle(CGtSphere s, CGtV3d a, CGtV3d b, CGtV3d c, CGtV3d *out); };
struct UnkStruct_00275D20_v3 { float x, y, z; };   // [G] 12-byte vertex view (RwV3d-like)
// [L] N185: stands in for a missing GtMathPs2 inline (w * w on a hard-coded $vf1)
static inline WAxisType func_00275D20_inl1(WAxisType w)
{
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "vmulw.w $vf1, $vf1, $vf1w" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(w.lVector));
    return WAxisType(t);
}
// [L] N185: stands in for CGtV3d::SetFromRwV3d(const RwV3d*) (B3O0PCH map, 72 bytes): three words packed into a quad
static inline void func_00275D20_inl2(CGtV3d &v, const UnkStruct_00275D20_v3 *p)
{
    u_long128 r;
    unsigned long x, y;
    asm("lwu %1, 0(%3)" "\n\t" "lwu %2, 4(%3)" "\n\t" "lwu %0, 8(%3)" "\n\t" "dsll32 %2, %2, 0" "\n\t" "or %2, %2, %1" "\n\t"
        "pcpyld %0, %0, %2" : "=r"(r), "=&r"(x), "=&r"(y) : "r"(p));
    v.mData = r;
}
// [L] N185: stands in for CGtV3d::Set(float,float,float) (B3O0PCH map) in this form (each float through $vf1)
static inline void func_00275D20_inl3(CGtV3d &v, float x, float y, float z)
{
    u_long128 m = v.mData;
    asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.x %0, $vf0, $vf1x" "\n\t" "qmtc2.ni %2, $vf1" "\n\t" "vaddx.y %0, $vf0, $vf1x" "\n\t"
        "qmtc2.ni %3, $vf1" "\n\t" "vaddx.z %0, $vf0, $vf1x" : "+j"(m) : "r"(x), "r"(y), "r"(z));
    v.mData = m;
}

// N182/N203: GtIntersection's inlined SetCode copies keep the no-reposition `bne; nop; b join` shape: [G] scoped to
// this function (opt_repositioncode off; [L] GtIntersection*.cpp compiled with it, gifq2 probe ur7).
#pragma push
#pragma opt_repositioncode off
// 0x00275D20
bool GtIntersection::IntersectSphereTriangle(CGtSphere s, CGtV3d a, CGtV3d b, CGtV3d c, CGtV3d *out)
{
    CGtSphere sc = s;
    CGtV3d pa = a;
    CGtV3d pb = b;
    CGtV3d pc = c;
    if (CGtVu0CodeManager::GetCurrentVu0CodePointer() != (void *)vu_game_004787D0) {
        if (CGtVu0CodeManager::UploadVu0Code((void *)vu_game_004787D0)) CGtVu0CodeManager::WaitForUploadToFinish();
    }
    float r2 = func_00275D20_inl1(sc.Radius());
    CGtV3d rr;
    func_00275D20_inl3(rr, r2, r2, r2);
    asm volatile("lqc2 $vf2, 0(%0)" "\n\t" "lqc2 $vf3, 0(%1)" : : "r"(&sc), "r"(&rr));
    CGtV3d va, vb, vc;
    func_00275D20_inl2(va, (const UnkStruct_00275D20_v3 *)&pa);
    asm volatile("qmtc2.i %0, $vf4" : : "r"(va.mData));
    func_00275D20_inl2(vb, (const UnkStruct_00275D20_v3 *)&pb);
    asm volatile("qmtc2.i %0, $vf5" : : "r"(vb.mData));
    func_00275D20_inl2(vc, (const UnkStruct_00275D20_v3 *)&pc);
    asm volatile("qmtc2.i %0, $vf6" : : "r"(vc.mData));
    int hit;
    asm volatile(".word 0x4A000338");   // vcallms 0x60 [G] encoded: see header note
    asm volatile("cfc2.i %0, $vi1" : "=r"(hit));
    asm volatile("qmfc2.i %0, $vf8" : "=r"(out->mData));
    return hit != 0;
}
#pragma pop
