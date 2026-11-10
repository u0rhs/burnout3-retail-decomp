// NONMATCHING: Update__16CB3VehicleDeformFv -- retail 74 / ours 74 instructions, 10 in changed runs
// near27: 34 -> 10; N24 goto entry-jump loop, self->field_80[i] indexing (retail's self+i*0x30 base), W() lane-read stand-ins (WAxisType copies give the frame), WAxisType-float + SetPlus(WAxisType) stand-ins, by-value WAxisType test inline; left: first W copy slot 0x50 vs retail 0x70, and retail moves field_10 into vf1 (qmtc2.ni in the bc1f delay slot) for the second W copy's sqc2 (ours sq a0) -- header W()/operator float shape
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
using GtMathPs2::CGtV3dPlus;
using GtMathPs2::CGtV4d;

struct UnkStruct_003DC070_e {
    CGtV3d field_0;
    CGtV3dPlus field_10;
    unsigned char field_20;
    unsigned char pad_21[0xF];
};
struct UnkStruct_D_0052267C { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0052267C D_0052267C;
static inline float func_003DC070_inl0() { return 0.0f; }
static inline float minfa(float a, float b) { float r; asm("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
extern "C" void ImpactBody__16CB3VehicleDeformFv(void *);

class CB3VehicleDeform {
public:
    void Update();
    unsigned char pad_0[0x80];
    UnkStruct_003DC070_e field_80[4];
    unsigned char pad_140x[1];
};
struct UnkStruct_003DC070_s {
    unsigned char pad_0[0x80];
    UnkStruct_003DC070_e field_80[4];
    CGtV4d field_140;
    CGtV4d field_150;
    unsigned char pad_160[0x1C];
    float field_17C;
    float field_180;
};

// [G] local stand-ins for header gaps (B3O0PCH map: CGtV3dPlus W() / WAxisType - float / SetPlus(WAxisType)):
static inline GtMathPs2::WAxisType func_003DC070_inl1(const CGtV3dPlus &v) { return GtMathPs2::WAxisType(v.mData); }
static inline GtMathPs2::WAxisType func_003DC070_inl2(const GtMathPs2::WAxisType &w0, float f)
{
    u_long128 w = w0.lVector;
    asm("qmtc2.ni %1, $vf2" "\n\t" "vsubx.w %0, %0, $vf2x" : "+j"(w) : "r"(f));
    return GtMathPs2::WAxisType(w);
}
static inline bool func_003DC070_inl5(GtMathPs2::WAxisType w, float z) { return w > z; }
static inline void func_003DC070_inl3(CGtV3dPlus &d, const GtMathPs2::WAxisType &w) { asm("vmove.w %0, %1" : "+j"(d.mData) : "j"(w.lVector)); }

extern "C" void Update__16CB3VehicleDeformFv(UnkStruct_003DC070_s *self)
{
    float d = D_0052267C.field_0;
    float lim = 20.0f * d;
    float zero = func_003DC070_inl0();
    int i = 0;
    goto test;
loop:
    if (func_003DC070_inl5(func_003DC070_inl1(self->field_80[i].field_10), zero)) {
        self->field_17C = minfa(lim, func_003DC070_inl1(self->field_80[i].field_10));
        self->field_150.mData = self->field_80[i].field_10.mData;
        self->field_140.mData = self->field_80[i].field_0.mData;
        self->field_180 = zero;
        func_003DC070_inl3(self->field_80[i].field_10, func_003DC070_inl2(func_003DC070_inl1(self->field_80[i].field_10), lim));
        ImpactBody__16CB3VehicleDeformFv(self);
        self->field_80[i].field_20 = self->field_80[i].field_20 - 1;
        if (self->field_80[i].field_20 < 0) {
            self->field_80[i].field_10.SetPlus(zero);
        }
    }
    i++;
test:
    if (i < 4) goto loop;
}

