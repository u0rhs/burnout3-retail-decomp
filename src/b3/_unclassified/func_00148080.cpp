// func_00148080 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (fam1: clone of func_00147FC0 with vectors swapped).

// func_00148080 -- hand-finished by fam1: clone of func_00147FC0 (same file) with the two segment vectors swapped.
// [L] DNAT: CB3AILane::GetForwardsVector(unsigned short,GtMathPs2::CGtV3d*) const (research/proto/new_names.csv, low).
// Types are [G].
#include "b3/GtMathPs2.h"

struct UnkStruct_00148080;
struct UnkStruct_00148080_1;
struct UnkStruct_00148080_a2;
struct UnkStruct_00148080_e0;
struct UnkStruct_00148080_e1;
struct UnkStruct_D_0064D354;
struct UnkStruct_kYAxis;

struct UnkStruct_00148080_1 {
    UnkStruct_00148080_e0 * field_0;
};

struct UnkStruct_00148080_e0 {
    unsigned short field_0;
    unsigned short field_2;
};

struct UnkStruct_D_0064D354 {
    UnkStruct_00148080_e1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00148080_e1 {
    GtMathPs2::CGtV3d field_0;
};

struct UnkStruct_kYAxis {
    GtMathPs2::CGtV3d field_0;
};

struct UnkStruct_00148080_a2 {
    GtMathPs2::CGtV3d field_0;
};

struct UnkStruct_00148080 {
    unsigned char pad_0[0x4];
    UnkStruct_00148080_1 * field_4;
};

// [L] N185: stands in for a vsub feeding GtMathPs2::CrossProduct (k x (b - a)), result moved out .i (N190; the fixup
// restores .ni). [L] N188: the .set noreorder region around this real asm keeps the result in v0 with the return value
// in the delay slot (scheduled freely, li v0,1 rises above the qmfc2).
static inline GtMathPs2::CGtV3d func_00148080_inl1(GtMathPs2::CGtV3d k, const GtMathPs2::CGtV3d &b, const GtMathPs2::CGtV3d &a) {
    u_long128 t, d;
    asm(".set noreorder");
    asm("vsub.xyz %2, %4, %3" "\n\t" "vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(k.mData), "=&j"(d) : "j"(b.mData), "j"(a.mData));
    asm(".set reorder");
    return GtMathPs2::CGtV3d(t);
}
extern UnkStruct_D_0064D354 D_0064D354;
extern UnkStruct_kYAxis kYAxis;

// 0x00148080
extern "C" bool func_00148080(UnkStruct_00148080 * self, unsigned short p0, UnkStruct_00148080_a2 * p1)
{
    unsigned short t2 = self->field_4->field_0[p0].field_0;
    unsigned short t3 = self->field_4->field_0[p0].field_2;
    if (t2 != t3) {
        p1->field_0 = func_00148080_inl1(kYAxis.field_0, D_0064D354.field_0[t3].field_0, D_0064D354.field_0[t2].field_0);
        return true;
    }
    p1->field_0 = func_00148080_inl1(kYAxis.field_0, D_0064D354.field_0[self->field_4->field_0[p0 + 1].field_2].field_0, D_0064D354.field_0[self->field_4->field_0[p0 + 1].field_0].field_0);
    return false;
}
