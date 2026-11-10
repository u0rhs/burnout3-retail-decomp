// Hand-written; the lifter refused it (CGtV3dPlus SetGtV3d/SetPlus, GetSquaredLength < 2^-32; NormaliseGetLength stand-in with .set noreorder inside the asm string [L] N185 + N140 pad inside it [G]).

// func_001BEEE0 -- hand-written from retail (ghvu2; the lifter refused it: sqrt.s). Unnamed in every table, so a
// placeholder with C linkage; file and Area unknown, so _unclassified/. Structs carry only the fields touched; every
// type is [G] (instruction widths). Reading [G]: a direction vector stored with its length in w (zero vector: w = 0 and
// a fallback direction), then w divided by a per-element float into each element.

#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

struct UnkStruct_001BEEE0_2 {
    unsigned char pad_0[0x20];
    CGtV3d field_20;
};

struct UnkStruct_001BEEE0_e {
    float field_0;
    unsigned char pad_4[0x8];
    float field_C;
    unsigned char pad_10[0xB0];
};

struct UnkStruct_001BEEE0 {
    unsigned char pad_0[0xB0];
    CGtV3dPlus field_B0;
    CGtV3d field_C0;
    unsigned char pad_D0[0x134];
    UnkStruct_001BEEE0_2 * field_204;
    unsigned char pad_208[0x668];
    UnkStruct_001BEEE0_e field_870[1];  // [G] element count unknown (stride 0xC0)
    unsigned char pad_930[0x839];
    signed char field_1169;
};

// [G] N140 pad: retail's frame (0x90) has three dead 16-byte slots below the W() lane copy; declared inside the
// NormaliseGetLength stand-in they land there (a function-level pad lands above it).
struct UnkStruct_001BEEE0_pad { int x[12]; UnkStruct_001BEEE0_pad() {} ~UnkStruct_001BEEE0_pad() {} };
// [L] N185: stands in for CGtV3d::NormaliseGetLength(): the header body, with `.set noreorder` also inside the asm string --
// with the region only as separate statements MWCC still puts hazard nops after the mtc1 and the mfc1 (retail 0x1BEF98-0x1BEFA4
// has none).
static inline XAxisType func_001BEEE0_inl1(CGtV3d &v)
{
    UnkStruct_001BEEE0_pad pad;
    XAxisType l = v.GetSquaredLength();
    u_long128 t, r;
    float f;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm(".set noreorder" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "qmfc2 %1, $vf1" "\n\t" "mtc1 %1, %2" "\n\t" "sqrt.s %2, %2" "\n\t" "mfc1 %1, %2" "\n\t"
        "qmtc2 %1, $vf1" "\n\t" "qmfc2 %1, $vf1" "\n\t" "vwaitq" "\n\t" "qmtc2 %3, $vf1" "\n\t" "vmulq.xyz $vf1, $vf1, $Q" "\n\t"
        "qmfc2 %0, $vf1" "\n\t" ".set reorder" : "=r"(t), "=&r"(r), "=&f"(f) : "r"(v.mData));
    asm(".set reorder");
    v.mData = t;
    return XAxisType(r);
}
// 0x001BEEE0
extern "C" void func_001BEEE0(UnkStruct_001BEEE0 * self, const CGtV3d * p1)
{
    self->field_B0.SetGtV3d(*p1);
    if (p1->GetSquaredLength() < 2.3283064e-10f) {
        self->field_B0.SetPlus(0.0f);
        self->field_C0 = self->field_204->field_20;
    } else {
        self->field_C0 = *p1;
        self->field_B0.SetPlus(func_001BEEE0_inl1(self->field_C0));
    }
    float w = ((CGtV4d *)&self->field_B0)->W();
    for (int i = 0; i < self->field_1169; i++) {
        self->field_870[i].field_C = w / self->field_870[i].field_0;
    }
}
