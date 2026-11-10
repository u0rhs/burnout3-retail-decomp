// NONMATCHING: func_00272EA0 -- retail 115 / ours 115 instructions, 2 in changed runs
// 2 off: one dsra32 scheduled a slot early in the loop setup (retail dsll32; addiu a0,s1,48; dsra32). Pointer increments are inside the sqc2 asm (+r, [G]: the only form giving retail's addiu order in both loops). Q-result qmfc2 written .i (N190). setc | near5: whole asm volatile -- removing volatile gives 34 off (no-output VU asm blocks deleted / reordered); needs a non-volatile rewrite with memory outputs before queueing (lead rule: no asm volatile).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00272EA0 -- hand-written (setc). [L] GtIntersectionPS2.cpp neighbourhood (between IntersectFrustum's unit
// siblings; no map name). Runs a VU0 microprogram (vu_game_004787D0) over a polygon's vertices: the microprogram reads and
// writes fixed VF registers, so those moves, vcallms and cfc2 are inline asm; the code upload is the inlined
// CGtVu0CodeManager::UploadVu0Code (N203).
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
struct UnkStruct_00272EA0_a0 { u_long128 field_0; u_long128 field_10; u_long128 field_20; };
struct UnkStruct_00272EA0_a2 { int field_0; u_long128 *field_4; };

// N182/N203: GtIntersection's inlined SetCode copies keep the no-reposition `bne; nop; b join` shape: [G] scoped to
// this function (opt_repositioncode off; [L] GtIntersection*.cpp compiled with it, gifq2 probe ur7).
#pragma push
#pragma opt_repositioncode off
// 0x00272EA0
extern "C" int func_00272EA0(const UnkStruct_00272EA0_a0 *p0, int p1, const UnkStruct_00272EA0_a2 *p2, CGtV3d *out, CGtV3d *pn)
{
    if (CGtVu0CodeManager::GetCurrentVu0CodePointer() != (void *)vu_game_004787D0) {
        if (CGtVu0CodeManager::UploadVu0Code((void *)vu_game_004787D0)) CGtVu0CodeManager::WaitForUploadToFinish();
    }
    asm volatile("lqc2 $vf1, 0x0(%0)" "\n\t" "lqc2 $vf2, 0x10(%0)" "\n\t" "lqc2 $vf3, 0x20(%0)" "\n\t" "vcallms 0xA90" "\n\t"
                 "cfc2.i $0, $vi0" : : "r"(p0));
    u_long128 q;
    short n;
    for (int i = 0; i < p2->field_0; i++) {
        long v;
        asm volatile("qmtc2.ni %0, $vf1" "\n\t" "vcallms 0xAD8" : : "r"(p2->field_4[i]));
        asm volatile("cfc2.i %0, $vi6" : "=r"(v));
        asm volatile("qmfc2.ni %0, $vf2" : "=r"(q));
        n = v;
        if (n < 3) return 0;
    }
    if (pn) {
        u_long128 r;
        asm volatile("vwaitq" "\n\t" "qmtc2.ni %1, $vf4" "\n\t" "vmulq.xyz $vf4, $vf4, $Q" "\n\t" "qmfc2.i %0, $vf4" : "=r"(r) : "r"(q));
        *pn = CGtV3d(r);
    }
    asm volatile("vcallms 0xDA8" "\n\t" "cfc2.i $0, $vi0" "\n\t" "sqc2 $vf1, 0x0(%0)" "\n\t" "sqc2 $vf2, 0x10(%0)" "\n\t" "sqc2 $vf3, 0x20(%0)"
                 : : "r"(out));
    int i = 3;
    CGtV3d *o = out + 3;
    for (; i < n - 2; i += 3) {
        asm volatile("vcallms 0xDD0" "\n\t" "cfc2.i $0, $vi0" "\n\t" "sqc2 $vf1, 0x0(%0)" "\n\t" "sqc2 $vf2, 0x10(%0)" "\n\t" "sqc2 $vf3, 0x20(%0)" "\n\t" "addiu %0, %0, 0x30"
                     : "+r"(o));
    }
    for (; i < n; i++) {
        asm volatile("vcallms 0xDF8" "\n\t" "cfc2.i $0, $vi0" "\n\t" "sqc2 $vf1, 0x0(%0)" "\n\t" "addiu %0, %0, 0x10" : "+r"(o));
    }
    return n;
}
#pragma pop
