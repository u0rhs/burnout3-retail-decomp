// NONMATCHING: func_001618C0 -- retail 150 / ours 150 instructions, 6 in changed runs
// near38: 150/150, 6 changed (was 158/150, 92). Fixes: asm volatile + .word vcallms replaced by plain asm with the vcallms mnemonic (N208) and the microprogram block (19 lqc2, vcallms, cfc2.i, 4 sqc2) in a .set noreorder region (real asm); the point table / quad base read into locals before the 4-pass copy loop (retail hoists both loads); the y/x lane setters read their ZAxisType argument through its address (lqc2 0(ptr): retail's sqc2/lqc2 temp round trips at 0xD0/0xA0); a 0x60 N140 pad in a static inline called before the microprogram for retail's six dead bottom slots (frame 0x180 exact). Left: head schedule only -- retail puts the (int)t cvt.w.s + mfc1 inside the a.SetX(field_34) asm (after its lqc2, after the n load + nop); every statement order / i placement / SetX form and 15 pragmas give the cvt first
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// logic draft, 158/150, frame 0x120 vs 0x180: SetCode + spline param vector (t^3,t^2,t,1) via lane stand-ins [L] N185; chained lane setters leave qmfc2/qmtc2 round trips and dead qmfc2 that retail folds (b119 stops VU move folds/dead-move removal in functions with the vcallms microcode asm; .word-encoded vcallms restores lqc2/sqc2 folds only). Retail's ZAxisType temps at 0xD0/0xA0 reloaded through address regs (lane-op temps in memory). setc
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_001618C0 -- hand-written (setc). Evaluates a cubic over four control quads with a VU0 microprogram
// (vu_game_004839E0): the parameter vector (t^3, t^2, t, 1), eight quads from the spline's point table and the two
// target-parameter matrices go to fixed VF registers; the 4x4 result comes back in vf2..vf5. The code upload is the
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
extern char vu_game_004839E0[];
extern u_long128 _gTargetParamPosMtx[4];
extern u_long128 _gTargetParamVelMtx[4];
struct UnkStruct_001618C0_e { unsigned short field_0; unsigned short field_2; };
struct UnkStruct_001618C0_s { UnkStruct_001618C0_e *field_0; int field_4; int field_8; u_long128 *field_C; int field_10; };
struct UnkStruct_001618C0_r { UnkStruct_001618C0_s *field_0; unsigned char pad_4[0x48]; };
struct UnkStruct_00522660 { unsigned char pad_0[0x22C]; UnkStruct_001618C0_r field_22C[1]; };
extern UnkStruct_00522660 D_00522660;
struct UnkStruct_001618C0 { unsigned char pad_0[0x34]; float field_34; unsigned char pad_38[9]; unsigned char field_41; };
struct UnkStruct_001618C0_m { u_long128 field_0[4]; };
// [L] N185 stand-ins (GtMathPs2 lane ops in the form retail inlines here: the vector in $vf2, the lane value in $vf1)
static inline void func_001618C0_inl1(CGtV4d &v, float f)   // w = 1.0 * f
{
    u_long128 t;
    asm("qmtc2 %1, $vf2" "\n\t" "qmtc2.ni %2, $vf1" "\n\t" "vmulx.w $vf2, $vf0, $vf1x" "\n\t" "qmfc2 %0, $vf2" : "=r"(t) : "r"(v.mData), "r"(f));
    v.mData = t;
}
static inline void func_001618C0_inl2(CGtV4d &v, float f)   // z = f
{
    u_long128 t;
    asm("qmtc2 %1, $vf2" "\n\t" "qmtc2.ni %2, $vf1" "\n\t" "vaddx.z $vf2, $vf0, $vf1x" "\n\t" "qmfc2 %0, $vf2" : "=r"(t) : "r"(v.mData), "r"(f));
    v.mData = t;
}
static inline ZAxisType func_001618C0_inl3(ZAxisType a, ZAxisType b)   // a.z * b.z
{
    u_long128 t;
    asm("qmtc2 %1, $vf2" "\n\t" "vmulz.z $vf1, $vf2, $vf2z" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(a.lVector));
    return ZAxisType(t);
}
static inline ZAxisType func_001618C0_inl6(ZAxisType a, YAxisType b)   // a.z * b.y
{
    u_long128 t;
    asm("qmtc2 %1, $vf2" "\n\t" "vmuly.z $vf1, $vf2, $vf2y" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(a.lVector));
    return ZAxisType(t);
}
static inline void func_001618C0_inl4(CGtV4d &v, ZAxisType a)   // y = a.z
{
    u_long128 t;
    asm("lqc2 $vf1, 0(%1)" "\n\t" "qmtc2 %2, $vf2" "\n\t" "vaddz.y $vf2, $vf0, $vf1z" "\n\t" "qmfc2 %0, $vf2" : "=r"(t) : "r"(&a), "r"(v.mData));
    v.mData = t;
}
static inline void func_001618C0_inl5(CGtV4d &v, ZAxisType a)   // x = a.z
{
    u_long128 t;
    asm("lqc2 $vf1, 0(%1)" "\n\t" "qmtc2 %2, $vf2" "\n\t" "vaddz.x $vf2, $vf0, $vf1z" "\n\t" "qmfc2 %0, $vf2" : "=r"(t) : "r"(&a), "r"(v.mData));
    v.mData = t;
}
static inline int func_001618C0_max(int a, int b) { int r; asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline int func_001618C0_min(int a, int b) { int r; asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline unsigned int func_001618C0_zx(int a) { unsigned int r; asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a)); return r; }

// [G] N140 pad standing in for retail's six dead 16-byte frame slots below the lane temporaries (0x20..0x90)
struct UnkStruct_001618C0_pad { int x[24]; UnkStruct_001618C0_pad() {} ~UnkStruct_001618C0_pad() {} };
static inline void func_001618C0_inl7() { UnkStruct_001618C0_pad p; }
// 0x001618C0
extern "C" void func_001618C0(UnkStruct_001618C0 *self, UnkStruct_001618C0_m *out, float t)
{
    u_long128 buf[8];
    CGtV4d b;
    CGtV4d a;
    unsigned char idx = self->field_41;
    UnkStruct_001618C0_r *r = (idx == 0xFF) ? 0 : &D_00522660.field_22C[idx];
    int n = r->field_0->field_10;
    int i = (int)t;
    a.SetX(self->field_34);
    if (!(i < n - 1)) {
        t = (float)(n - 1);
        i = n - 2;
    }
    float f = t - (float)i;
    func_001618C0_inl1(b, 1.0f);
    func_001618C0_inl2(b, f);
    func_001618C0_inl4(b, func_001618C0_inl3(b.Z(), b.Z()));
    func_001618C0_inl5(b, func_001618C0_inl6(b.Z(), b.Y()));
    UnkStruct_001618C0_s *sp = r->field_0;
    u_long128 *q = sp->field_C;
    UnkStruct_001618C0_e *ents = sp->field_0;
    for (int j = 0; j < 4; j++) {
        UnkStruct_001618C0_e *e = &ents[func_001618C0_zx(func_001618C0_min(func_001618C0_max(i + j - 1, 0), n - 1))];
        buf[j * 2] = q[e->field_0];
        buf[j * 2 + 1] = q[e->field_2];
    }
    if (CGtVu0CodeManager::GetCurrentVu0CodePointer() != (void *)vu_game_004839E0) {
        if (CGtVu0CodeManager::UploadVu0Code((void *)vu_game_004839E0)) CGtVu0CodeManager::WaitForUploadToFinish();
    }
    func_001618C0_inl7();
    asm(".set noreorder");
    asm("lqc2 $vf1, 0x0(%0)" "\n\t" "lqc2 $vf2, 0x0(%1)" "\n\t" "lqc2 $vf3, 0x10(%1)" "\n\t" "lqc2 $vf4, 0x20(%1)" "\n\t"
                 "lqc2 $vf5, 0x30(%1)" "\n\t" "lqc2 $vf6, 0x40(%1)" "\n\t" "lqc2 $vf7, 0x50(%1)" "\n\t" "lqc2 $vf8, 0x60(%1)" "\n\t"
                 "lqc2 $vf9, 0x70(%1)" "\n\t" "lqc2 $vf11, 0x0(%2)" "\n\t" "lqc2 $vf12, 0x10(%2)" "\n\t" "lqc2 $vf13, 0x20(%2)" "\n\t"
                 "lqc2 $vf14, 0x30(%2)" "\n\t" "lqc2 $vf15, 0x0(%3)" "\n\t" "lqc2 $vf16, 0x10(%3)" "\n\t" "lqc2 $vf17, 0x20(%3)" "\n\t"
                 "lqc2 $vf18, 0x30(%3)" "\n\t" "lqc2 $vf19, 0x0(%4)"
                 : : "r"(&a), "r"(buf), "r"(_gTargetParamPosMtx), "r"(_gTargetParamVelMtx), "r"(&b));
    asm("vcallms 0x0" "\n\t" "cfc2.i $0, $vi0");
    asm("sqc2 $vf4, 0x20(%0)" "\n\t" "sqc2 $vf3, 0x10(%0)" "\n\t" "sqc2 $vf5, 0x30(%0)" "\n\t" "sqc2 $vf2, 0x0(%0)" : : "r"(out));
    asm(".set reorder");
}

