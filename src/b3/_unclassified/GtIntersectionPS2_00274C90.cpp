// GtIntersection::IntersectLineTriangle(const CGtLine&,GtMathPs2::CGtV3d,GtMathPs2::CGtV3d,GtMathPs2::CGtV3d,float*,float*,float*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtIntersectionPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (setc match; the retail qmtc2.i is kept by config/vu0_keep_i.txt (N205)).

// GtIntersection::IntersectLineTriangle(const CGtLine&,CGtV3d,CGtV3d,CGtV3d,float*,float*,float*) -- hand-written (setc).
// [C] name: the mangled symbol in retail's tables; file: GtIntersectionPS2.cpp (E dnat map). Area not evidenced.
// The VU0 microprogram reads fixed VF registers, so the moves, vcallms and cfc2 are inline asm; the code upload is the
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
struct CGtLine { u_long128 mStart; u_long128 mEnd; };   // [G] two quads (lq 0x0 / 0x10)
class GtIntersection { public: static int IntersectLineTriangle(const CGtLine &l, CGtV3d a, CGtV3d b, CGtV3d c,
                                                                  float *pu, float *pv, float *pt); };
union UnkStruct_00274C90_q { u_long128 q; float f[4]; };

// N182/N203: GtIntersection's inlined SetCode copies keep the no-reposition `bne; nop; b join` shape: [G] scoped to
// this function (opt_repositioncode off; [L] GtIntersection*.cpp compiled with it, gifq2 probe ur7).
#pragma push
#pragma opt_repositioncode off
// 0x00274C90
int GtIntersection::IntersectLineTriangle(const CGtLine &l, CGtV3d a, CGtV3d b, CGtV3d c, float *pu, float *pv, float *pt)
{
    CGtV3d pa = a;
    CGtV3d pb = b;
    CGtV3d pc = c;
    UnkStruct_00274C90_q r;
    int hit;
    if (CGtVu0CodeManager::GetCurrentVu0CodePointer() != (void *)vu_game_004787D0) {
        if (CGtVu0CodeManager::UploadVu0Code((void *)vu_game_004787D0)) CGtVu0CodeManager::WaitForUploadToFinish();
    }
    asm volatile("qmtc2.i %0, $vf2\n\tqmtc2.i %1, $vf4\n\tqmtc2.i %2, $vf5\n\tqmtc2.i %3, $vf6\n\tqmtc2.i %4, $vf7"
                 : : "r"(l.mStart), "r"(l.mEnd), "r"(pa.mData), "r"(pb.mData), "r"(pc.mData));
    asm volatile("vcallms 0x3D8");
    asm volatile("cfc2.i %0, $vi1" : "=r"(hit));
    asm volatile("qmfc2.i %0, $vf24" : "=r"(r.q));
    if (hit == 0) return 0;
    *pu = r.f[0];
    *pv = r.f[1];
    *pt = r.f[2];
    return 1;
}
#pragma pop
