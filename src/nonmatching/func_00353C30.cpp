// NONMATCHING: func_00353C30 -- retail 120 / ours 122 instructions, 77 in changed runs
// near37: N163 pinned hoists dropped for header DotProduct/GetSquaredLength (b119p hoists all three 1.0s) + one compiler-chosen 3-operand vsub stand-in; 77 changed (scoped opt_repositioncode off gives 74/119). Left: if-body out of line after the loop (retail inline beqz), frame 0x70 vs 0x60 (one extra dead slot), VU numbering (retail o=vf1 then hard-coded vf1 chains; lp vf3/lq vf2/ld vf9/d vf4/ones vf8/vf6/vf5), mul.s operand order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00353C30_o { CGtV3d field_0; unsigned char field_10; };
struct UnkStruct_00353C30_e {
    UnkStruct_00353C30_o* field_0;
    unsigned char pad_4[4];
    unsigned char field_8;
    unsigned char pad_9[7];
};
struct UnkStruct_D_00522660 { unsigned char pad_0[0x125B40]; UnkStruct_00353C30_e field_125B40[1]; };
extern UnkStruct_D_00522660 D_00522660;
extern unsigned char D_0064872C;

// [G] element test (an inline returning bool, negated by the caller)
static inline bool func_00353C30_inl0(UnkStruct_00353C30_e* e) { bool b = e->field_8 != 0; return !b; }
// [G] CGtV3d subtraction on compiler-chosen VU registers (three-operand form; the header's operator- hard-codes $vf1/$vf2)
static inline CGtV3d func_00353C30_inl1(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(t);
}

// 0x00353C30
extern "C" float func_00353C30(void* a0, CGtV3d p, CGtV3d q, CGtV3d dir)
{
    CGtV3d lp = p; CGtV3d lq = q; CGtV3d ld = dir;
    float sum = 0.0f;
    for (int i = 0; i < D_0064872C; i++) {
        UnkStruct_00353C30_e* e = &D_00522660.field_125B40[i];
        if (func_00353C30_inl0(e)) {
            UnkStruct_00353C30_o* o = e->field_0;
            CGtV3d d = func_00353C30_inl1(o->field_0, lp);
            float t = DotProduct(d, ld);
            if (!(t <= 0.0f)) {
                float a = 1.0f - 2.5e-05f * (float)func_00353C30_inl1(o->field_0, lq).GetSquaredLength();  // [C] retail FPU form, not a VU lane op: 0x353D50 / 0x353D8C msub.s (the cast keeps the port's PS2 float model)
                if (!(a <= 0.0f)) {
                    float b = 1.0f - 0.01f * (float)func_00353C30_inl1(d, ld * t).GetSquaredLength();  // [C] retail FPU form, not a VU lane op: 0x353D50 / 0x353D8C msub.s (the cast keeps the port's PS2 float model)
                    if (!(b <= 0.0f)) {
                        float w = 0.0f;
                        switch (o->field_10) {
                        case 1: w = 1000.0f; break;
                        case 2: w = 2000.0f; break;
                        case 3: w = 5000; break;
                        case 7: w = 10000; break;
                        case 5: w = 25000; break;
                        case 6: w = 50000; break;
                        }
                        float s = b * a; s = w * s; sum = sum + s;
                    }
                }
            }
        }
    }
    return sum;
}
