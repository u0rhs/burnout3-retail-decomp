// func_00446A40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source ([G] VU inline: qmtc2.ni x/y to vf4/vf3 (inputs only), then qmtc2.ni z to vf2 and the three vaddx as "+j"(m) asms, so lqc2 lands between).

// from build/vt\try_func_00446A40_best.cpp
// func_00446A40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

struct UnkStruct_00446A40;
struct UnkStruct_00446A40_1;
struct UnkStruct_00446A40_a1;

struct UnkStruct_00446A40_a1 {
    unsigned char pad_0[0x4];
    float field_4;
    float field_8;
    float field_C;
};

struct UnkStruct_00446A40_1 {
    GtMathPs2::CGtV3d field_0;
};

struct UnkStruct_00446A40 {
    GtMathPs2::CGtV3d field_0;
};

// [G] placeholder inline: likely CGtV3d::Set(float,float,float) (B3O0PCH map) in a form this header lacks; retail keeps
// x/y/z in $vf4/$vf3/$vf2 and the vector in $vf1 (cf. B3TrafficAxle_0015FA60.cpp's inl2).
static inline void func_00446A40_inl1(GtMathPs2::CGtV3d & v, float x, float y, float z)
{
    u_long128 m = v.mData;
    asm("qmtc2.ni %0, $vf4" "
	" "qmtc2.ni %1, $vf3" : : "r"(x), "r"(y));
    asm("qmtc2.ni %1, $vf2" : "+j"(m) : "r"(z));
    asm("vaddx.x %0, $vf0, $vf4x" "
	" "vaddx.y %0, $vf0, $vf3x" "
	" "vaddx.z %0, $vf0, $vf2x" : "+j"(m));
    v.mData = m;
}

// 0x00446A40
extern "C" void func_00446A40(UnkStruct_00446A40 * self, UnkStruct_00446A40_a1 * p0)
{
    UnkStruct_00446A40_1 local;
    func_00446A40_inl1(local.field_0, p0->field_4, p0->field_8, p0->field_C);
    self->field_0 = local.field_0;
}
