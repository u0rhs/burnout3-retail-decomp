// NONMATCHING: func_002BC460 -- retail 324 / ours 324 instructions, 44 in changed runs
// ghvu18: logic complete (Ghidra+asm): frac step, either-flag bool, per-car loop over D_00522660 (CB3World) with real member offsets (0x12AD10 id, 0x12AD40 count, 0x12AD50 car array: retail's hoisted lui/ori offsets + per-iteration base addu), switch on GetTrackRegion (cases 0/1 call the archived siblings func_002BB420/func_002BAF30 by address; case 2 = their colour interpolation + header SinCosFast2 lane tail in a [G] inline with 5 N140 pads). 324/324 instrs, 44 in changed runs, frame exact. Left: interp FPRs f5/f6 swapped, col[1]/col[2] address regs a0/a1 swapped, Z-lane copy slot (ours 0x180 vs 0x190) and v1/a0, vmuly.w/vmulx.w on vf3/vf1 vs retail vf1/vf3 (same as func_002BB420), and the header CosFast4's stage-1 constants (lui 0.5 / 1.5*2^23 hoisted above the vabs moves in retail) + qmfc2 GPR choice (GtMathPs2Trig.h gap, shared with func_002BB420) | N259: (float)pos.Z() cast for the new op-(Z,Z)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_002BC460 -- hand-written (ghvu18): Ghidra draft + retail asm; the region-2 block is the archived siblings'
// (func_002BB420 / func_002BAF30, regions 0 / 1, called here) colour interpolation + SinCosFast2 tail written inline.
// [L] GtMathPs2::SinCosFast2(float,float) (B3O0PCH map; include/b3/GtMathPs2Trig.h).
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;

struct UnkStruct_002BC460_out {
    CGtV3d field_0;
    unsigned char pad_10[0x10];
    float field_20;
    unsigned char pad_24[0x8];
    float field_2C;
    unsigned char pad_30[0x10];
};
struct UnkStruct_002BC460 {
    unsigned char pad_0[0xB0];
    UnkStruct_002BC460_out field_B0[1];
};
struct UnkStruct_002BC460_self {
    unsigned char pad_0[0x134];
    float field_134;
    float field_138;
};
struct UnkStruct_002BC460_d { unsigned char pad_0[0x260]; float field_260; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_002BC460_car { unsigned char pad_0[0x30]; CGtV3d field_30; unsigned char pad_40[0x27D0 - 0x40]; };
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12AD10];
    unsigned long field_12AD10;
    unsigned char pad_12AD18[0x28];
    int field_12AD40;
    unsigned char pad_12AD44[0xC];
    UnkStruct_002BC460_car field_12AD50[6];
};
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_002BC460_g { unsigned char pad_0[0x2B660]; unsigned char field_2B660[0x10]; };
extern UnkStruct_002BC460_g D_004EE040;
extern UnkStruct_P D_00665EC0;
extern unsigned char D_0064D379[];
extern unsigned char D_0064D378[];
extern float D_004C1CA0[];
extern float D_004C1CA4[];
extern float D_004C1CA8[];
extern float D_004C1CAC[];
extern float D_004C1CB0[];
extern float D_004C1CB4[];
extern "C" int GetTrackRegion__12CB3TrackListFUl(void *, unsigned long);
extern "C" void func_002BB420(const void *, UnkStruct_002BC460_out *);
extern "C" void func_002BAF30(const void *, UnkStruct_002BC460_out *);

// [L] GtMath::Interpolate(float,float,float) (map 0x14CCF0), as in func_002BB420
static inline float func_002BC460_inl1(float a, float b, float t) { float d = b - a; return 0.0f + a + t * d; }
// [L] stand-ins (as func_002BB420): operator*(WAxisType,YAxisType), operator*(WAxisType,XAxisType), CGtV3d::SetX(WAxisType),
// CGtV3d::SetY(ZAxisType), CGtV3d::SetZ(WAxisType) on compiler-chosen registers
static inline u_long128 func_002BC460_inl4(u_long128 a) { u_long128 r; asm("vmuly.w %0, %1, %1y" : "=j"(r) : "j"(a)); return r; }
static inline u_long128 func_002BC460_inl5(u_long128 a) { u_long128 r; asm("vmulx.w %0, %1, %1x" : "=j"(r) : "j"(a)); return r; }
static inline void func_002BC460_inl6(CGtV3d &v, u_long128 a) { asm("vaddw.x %0, $vf0, %1w" : "+j"(v.mData) : "j"(a)); }
static inline void func_002BC460_inl7(CGtV3d &v, u_long128 a) { asm("vaddz.y %0, $vf0, %1z" : "+j"(v.mData) : "j"(a)); }
static inline void func_002BC460_inl8(CGtV3d &v, u_long128 a) { asm("vaddw.z %0, $vf0, %1w" : "+j"(v.mData) : "j"(a)); }

struct UnkStruct_002BC460_pad { int x[4]; UnkStruct_002BC460_pad() {} ~UnkStruct_002BC460_pad() {} };  // [G] N140 frame pad
// [G] placeholder inline: either flag set
static inline bool func_002BC460_inl9() { bool r = true; if (D_0064D379[0] == 0 && D_0064D378[0] == 0) r = false; return r; }
// [G] placeholder inline: the sun direction from two angles (SinCosFast2 lanes into x/y/z), as func_002BB420's tail
static inline void func_002BC460_inl10(CGtV3d &d, float a, float b)
{
    UnkStruct_002BC460_pad p0; UnkStruct_002BC460_pad p1; UnkStruct_002BC460_pad p2; UnkStruct_002BC460_pad p3; UnkStruct_002BC460_pad p4;
    CGtV4d sc = SinCosFast2(a, b);
    func_002BC460_inl6(d, func_002BC460_inl4(sc.mData));
    func_002BC460_inl7(d, sc.mData);
    func_002BC460_inl8(d, func_002BC460_inl5(sc.mData));
}
// 0x002BC460
extern "C" void func_002BC460(UnkStruct_002BC460_self * self, float dt)
{
    float t0 = self->field_134 + (1.0f + self->field_138 * dt);
    self->field_134 = t0 - (float)(int)t0;
    bool on = func_002BC460_inl9();
    for (int i = 0; i < D_00522660.field_12AD40; i++) {
        if (on) {
            UnkStruct_002BC460_out * out = &((UnkStruct_002BC460 *)self)->field_B0[i];
            CGtV3d pos = ((UnkStruct_002BC460_car *)((char *)&D_00522660 + i * 0x27D0 + 0x12AD50))->field_30;
            int region = GetTrackRegion__12CB3TrackListFUl(D_004EE040.field_2B660, D_00522660.field_12AD10);
            switch (region) {
            case 0:
                func_002BB420(&pos, out);
                break;
            case 1:
                func_002BAF30(&pos, out);
                break;
            case 2: {
                float t = 0.007142857183f * ((float)pos.Z() - 3290);
                float col[3];
                if (t <= 0.0f) {
                    col[0] = D_004C1CA0[0];
                    col[1] = D_004C1CA4[0];
                    col[2] = D_004C1CA8[0];
                } else if (t < 1.0f) {
                    col[0] = func_002BC460_inl1(D_004C1CA0[0], D_004C1CAC[0], t);
                    col[1] = func_002BC460_inl1(D_004C1CA4[0], D_004C1CB0[0], t);
                    col[2] = func_002BC460_inl1(D_004C1CA8[0], D_004C1CB4[0], t);
                } else {
                    col[0] = D_004C1CAC[0];
                    col[1] = D_004C1CB0[0];
                    col[2] = D_004C1CB4[0];
                }
                func_002BC460_inl10(out->field_0, 0.01745329238f * col[0], 0.01745329238f * col[1]);
                out->field_2C = col[2];
                break;
            }
            }
        }
        ((UnkStruct_002BC460_d *)((char *)&D_00665EC0 + i * 0xA0))->field_260 = ((UnkStruct_002BC460 *)self)->field_B0[i].field_20;
    }
}
