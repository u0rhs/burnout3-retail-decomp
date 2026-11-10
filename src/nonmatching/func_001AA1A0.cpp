// NONMATCHING: func_001AA1A0 -- retail 145 / ours 134 instructions, 128 in changed runs
// logic believed right (4 CGtV4d globals: lanes = +/-((1<<(15-bits))-1) for velocity/position frac bits, +/- D_004B7A70 offset, D_01E86598 -1->0, Construct__17CB3NetworkMessageFv); 128 off: retail keeps 4 vectors live in vf2-vf5 with eager lqc2 at top and 6 more s-regs (frame 0x50 vs 0x20); our schedule differs; needs lane-setter APIs on compiler-chosen vectors (SetX via vaddx.x D,vf0,vf1x)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
extern signed char kan8VelocityNumFracBits[3];
extern signed char kan8PositionNumFracBits[3];
extern CGtV4d gMinLinearVelocity;
extern CGtV4d D_0066C550;
extern CGtV4d D_0066C560;
extern CGtV4d D_0066C570;
extern CGtV4d D_004B7A70;
struct UnkStruct_D_01E86598 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E86598 D_01E86598;
extern "C" void Construct__17CB3NetworkMessageFv(void *);  // CB3NetworkMessage::Construct()
// [L] N185: lane setters on a compiler-chosen vector register: the scalar through $vf1 as retail's inlined SetX/SetY/SetZ
static inline void SetLX(u_long128 &v, float f) { asm("qmtc2.ni %1, $vf1\n\tvaddx.x %0, $vf0, $vf1x" : "+j"(v) : "r"(f)); }
static inline void SetLY(u_long128 &v, float f) { asm("qmtc2.ni %1, $vf1\n\tvaddx.y %0, $vf0, $vf1x" : "+j"(v) : "r"(f)); }
static inline void SetLZ(u_long128 &v, float f) { asm("qmtc2.ni %1, $vf1\n\tvaddx.z %0, $vf0, $vf1x" : "+j"(v) : "r"(f)); }
static inline int func_001AA1A0_inl1(signed char b) { return (1 << (15 - b)) - 1; }

// 0x001AA1A0
// pass1: a0 (the message; func_0023F7F0 / func_0023F860 pass self+0x924 / +0x6E4) is never read here and reaches
// Construct__17CB3NetworkMessageFv untouched (retail's tail call)
extern "C" void func_001AA1A0(void *msg)
{
    u_long128 vmin = gMinLinearVelocity.mData;
    u_long128 vmax = D_0066C550.mData;
    u_long128 pmax = D_0066C570.mData;
    u_long128 pmin = D_0066C560.mData;
    int r;
    r = func_001AA1A0_inl1(kan8VelocityNumFracBits[0]);
    SetLX(vmax, (float)r);
    SetLX(vmin, (float)-r);
    r = func_001AA1A0_inl1(kan8VelocityNumFracBits[1]);
    SetLY(vmax, (float)r);
    SetLY(vmin, (float)-r);
    r = func_001AA1A0_inl1(kan8VelocityNumFracBits[2]);
    SetLZ(vmax, (float)r);
    SetLZ(vmin, (float)-r);
    r = func_001AA1A0_inl1(kan8PositionNumFracBits[0]);
    SetLX(pmax, (float)r);
    SetLX(pmin, (float)-r);
    r = func_001AA1A0_inl1(kan8PositionNumFracBits[1]);
    SetLY(pmax, (float)r);
    SetLY(pmin, (float)-r);
    r = func_001AA1A0_inl1(kan8PositionNumFracBits[2]);
    SetLZ(pmax, (float)r);
    SetLZ(pmin, (float)-r);
    u_long128 off = D_004B7A70.mData;
    asm("vsub.xyz %0, %0, %1" : "+j"(vmax) : "j"(off));
    asm("vadd.xyz %0, %0, %1" : "+j"(vmin) : "j"(off));
    asm("vsub.xyz %0, %0, %1" : "+j"(pmax) : "j"(off));
    asm("vadd.xyz %0, %0, %1" : "+j"(pmin) : "j"(off));
    D_0066C550.mData = vmax;
    gMinLinearVelocity.mData = vmin;
    D_0066C570.mData = pmax;
    D_0066C560.mData = pmin;
    if (D_01E86598.field_0 == -1) D_01E86598.field_0 = 0;
    Construct__17CB3NetworkMessageFv(msg);
}
