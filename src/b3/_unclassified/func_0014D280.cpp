// func_0014D280 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (merged guard (field_1FC==0 && !((t0=field_298)<=0)) sharing one else; r0-r1 in a local; Min operands loaded 23F8 first).

// from build/vt\try_func_0014D280_best.cpp
// func_0014D280 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

#include "b3/GtMath.h"

class CB3AILane;
struct UnkStruct_0014D280;
struct UnkStruct_0014D280_1;
struct UnkStruct_0014D280_3;
struct UnkStruct_0014D280_4;
struct UnkStruct_D_004E0E90;
struct UnkStruct_D_01E7556C;

class CB3AILane {
public:
    float GetDistanceBetweenSegments(unsigned short, unsigned short) const;
    float GetDistFromStartOfSegment(GtMathPs2::CGtV3d, unsigned short) const;
};

struct UnkStruct_0014D280_1 {
    unsigned char pad_0[0x23F8];
    float field_23F8;
    unsigned char pad_23FC[0x34];
    UnkStruct_0014D280_3 * field_2430;
};

struct UnkStruct_D_004E0E90 {
    float field_0;
};

struct UnkStruct_0014D280_3 {
    unsigned char pad_0[0x204];
    UnkStruct_0014D280_4 * field_204;
};

struct UnkStruct_0014D280_4 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
};

struct UnkStruct_D_01E7556C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0014D280 {
    unsigned char pad_0[0x4];
    UnkStruct_0014D280_1 * field_4;
    unsigned char pad_8[0x1C8];
    float field_1D0;
    CB3AILane * field_1D4;
    unsigned short field_1D8;
    unsigned char pad_1DA[0x1E];
    int field_1F8;
    int field_1FC;
    unsigned char pad_200[0x13];
    unsigned char field_213;
    unsigned short field_214;
    unsigned char pad_216[0x82];
    float field_298;
};

extern UnkStruct_D_004E0E90 D_004E0E90;
extern UnkStruct_D_01E7556C D_01E7556C;

extern "C" void func_0014D280(UnkStruct_0014D280 * self)
{
    float t0;
    if (self->field_1FC == 0 && !((t0 = self->field_298) <= 0.0f)) {
        float v1 = t0;
        if (self->field_213 != 0) {
            v1 = D_004E0E90.field_0 * t0;
        }
        if (self->field_1F8 != 0) {
            self->field_1D0 = v1;
        } else {
            float r0 = self->field_1D4->GetDistanceBetweenSegments(self->field_1D8, self->field_214);
            GtMathPs2::CGtV3d vt30;
            vt30.mData = self->field_4->field_2430->field_204->field_30;
            float r1 = self->field_1D4->GetDistFromStartOfSegment(vt30, self->field_1D8);
            float d = r0 - r1;
            self->field_1D0 = v1 + d * D_01E7556C.field_0;
        }
    } else {
        self->field_1D0 = self->field_4->field_23F8;
    }
    float mm1 = self->field_4->field_23F8;
    float mm0 = self->field_1D0;
    self->field_1D0 = GtMath::Min(mm0, mm1);
}
