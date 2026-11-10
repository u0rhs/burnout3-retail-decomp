// func_0039C510 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (switch 2/3/4; SetA(float) as two statements (qmtc2 on its own =j, then vmulx.w): [L] N185 stand-in).

// func_0039C510 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

struct UnkStruct_0039C510;
struct UnkStruct_0039C510_3;
struct UnkStruct_D_01E90420;
struct UnkStruct_D_01E90424;

struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90420 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0039C510_3 {
    unsigned char pad_0[0x10];
    GtMathPs2::CGtV4d field_10;
};

struct UnkStruct_0039C510 {
    unsigned char pad_0[0x60];
    UnkStruct_0039C510_3 * field_60;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E90420 D_01E90420;

// [L] N185: stands in for a missing GtMathPs2 inline -- CGtV4d::SetA(float) with the scalar moved by its own statement
// (the CGtSphere::SetRadius / CGtV4d::SetW form); the header's one-statement SetA schedules the lqc2 before the nop.
static inline void func_0039C510_inl1(GtMathPs2::CGtV4d &v, float a)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(a));
    asm("vmulx.w %0, $vf0, %1x" : "+j"(v.mData) : "j"(s));
}

// 0x0039C510
extern "C" void func_0039C510(UnkStruct_0039C510 * self)
{
    switch (D_01E90424.field_0) {
    case 2:
    case 3:
    case 4:
        func_0039C510_inl1(self->field_60->field_10, D_01E90420.field_0);
        break;
    }
}
