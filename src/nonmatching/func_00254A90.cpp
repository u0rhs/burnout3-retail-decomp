// NONMATCHING: func_00254A90 -- retail 125 / ours 121 instructions, 104 in changed runs
// ghvu12: logic, frame 0x40 and entry copies right; left: retail computes the pos/w vector c (vadd.xyz keep-w + SetW) early and stores it to its slot before the buffer stores, ours late; retail's second vftoi0 reads an uninitialised VU temp (qmtc2 a0 + vmove); vmul result GPR round trip before the first vftoi0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// [G] DNAT hint (research/proto/dnat_align.csv, below threshold 0.382): CB3ParticleArray::SpawnParticle(CGtV3d,CGtV3d,float x6,bool,bool)
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00254A90_bank {
    unsigned char pad_0[0x8];
    CGtV4d *field_8;
    unsigned long *field_C;
    unsigned int *field_10;
    unsigned int field_14;
    unsigned int field_18;
    float *field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    unsigned char pad_28[0x4];
};
struct UnkStruct_00254A90_self {
    unsigned char pad_0[0x7C];
    float field_7C;
    unsigned char pad_80[0x68];
    UnkStruct_00254A90_bank field_E8;
    UnkStruct_00254A90_bank field_114;
};
extern CGtV4d D_004BBF70;
extern CGtV4d D_004BBF80;

// [L] N185: operator-(float, WAxisType) stand-in
static inline float func_00254A90_inl1(float a, const CGtV4d &v)
{ u_long128 s, r; float f; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(a)); asm("vsubw.x %0, %1, %2w" : "=j"(r) : "j"(s), "j"(v.mData)); asm("mtc1 %1, %0" : "=f"(f) : "r"(r)); return f; }
static inline u_long128 func_00254A90_inl2(u_long128 a, u_long128 b) { u_long128 r; asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline u_long128 func_00254A90_inl3(u_long128 a, u_long128 b) { u_long128 r; asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline u_long128 func_00254A90_inl4(unsigned long a) { u_long128 r; asm("pextlw %0, %1, %1" : "=r"(r) : "r"(a)); return r; }

// 0x00254A90
extern "C" int func_00254A90(UnkStruct_00254A90_self *self, CGtV3d pos, CGtV3d vel, bool p3, bool p4,
                             float p5, float p6, float p7, float p8, float p9, float p10)
{
    CGtV3d pc = pos;
    CGtV3d vc = vel;
    UnkStruct_00254A90_bank *bank;
    if (p4) bank = &self->field_114; else bank = &self->field_E8;
    CGtV4d *e = (CGtV4d *)((unsigned int)&bank->field_8[bank->field_18] | 0x20000000);
    if (!p3) {
        if (func_00254A90_inl1(self->field_7C, *e) < bank->field_24) return 0;
    }
    CGtV4d c;
    asm("vadd.xyz %0, $vf0, %1" : "+j"(c.mData) : "j"(*(const u_long128 *)&pc.mData));
    c.SetW(p5);
    u_long128 s, t;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(p10));
    asm("vmulz.xyz %0, %1, %2z" : "=j"(t) : "j"(*(const u_long128 *)&vc.mData), "j"(D_004BBF70.mData));
    asm("vmulx.w %0, %1, %2x" : "+j"(t) : "j"(D_004BBF70.mData), "j"(s));
    asm("vftoi0.xyzw %0, %0" : "+j"(t));
    u_long128 q;
    asm("qmfc2 %0, %1" : "=r"(q) : "j"(t));
    q = func_00254A90_inl3(func_00254A90_inl2(q, func_00254A90_inl4(0xFFFF8000FFFF8000UL)), func_00254A90_inl4(0x00007FFF00007FFFUL));
    unsigned long h;
    asm("ppach %0, $0, %1" : "=r"(h) : "r"(q));
    *(unsigned long *)((unsigned int)&bank->field_C[bank->field_18] | 0x30000000) = h;
    CGtV4d k(p7 + (p6 + p6), p7, p9, p8);
    u_long128 m, i;
    asm("vmul.xyzw %0, %1, %2" : "=j"(m) : "j"(k.mData), "j"(D_004BBF80.mData));
    asm("vftoi0.xyzw %0, %1" : "+j"(i) : "j"(m));
    asm("qmfc2 %0, %1" : "=r"(q) : "j"(i));
    q = func_00254A90_inl3(q, func_00254A90_inl4(0x000000FF000000FFUL));
    unsigned int w;
    asm("ppach %0, $0, %1" "\n\t" "ppacb %0, $0, %0" : "=r"(w) : "r"(q));
    *(unsigned int *)((unsigned int)&bank->field_10[bank->field_18] | 0x30000000) = w;
    *(u_long128 *)((unsigned int)&bank->field_8[bank->field_18] | 0x30000000) = *(const u_long128 *)&c.mData;
    bank->field_1C[bank->field_18 / 60] = p5;
    if (bank->field_18 == 0) bank->field_18 = bank->field_14;
    bank->field_18--;
    return 1;
}


