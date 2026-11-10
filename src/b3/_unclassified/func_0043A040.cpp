// Hand-written; the lifter refused it (twin of func_00431160 (7 rows): pabsw/pextlw stand-ins, SetA fade, by-value SetColour stand-in; idx = i + (field_C00 - 3)).

// func_0043A040 -- hand-written from retail (ghvu2; the lifter refused it: pabsw). Twin of func_00431160's colour fade
// (seven rows here). Unnamed in every table, so a placeholder with C linkage; file and Area unknown, so _unclassified/.
// Structs carry only the fields touched; every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

struct UnkStruct_0043A040_obj { unsigned char pad_0[0x10]; CGtV4d field_10; };
struct UnkStruct_0043A040 {
    unsigned char pad_0[0x60C];
    unsigned short *field_60C[7];
    unsigned char pad_628[0x238];
    unsigned short *field_860[7];
    unsigned char pad_87C[0x368];
    UnkStruct_0043A040_obj *field_BE4[7];
    int field_C00;
};
extern "C" int func_0043A420(UnkStruct_0043A040 *, unsigned short *, int, int);

static inline int func_0043A040_inl1(int x)
{
    int r;
    asm("pabsw %0,%1" : "=r"(r) : "r"(x));
    return r;
}
static inline unsigned int func_0043A040_inl2(unsigned int x)
{
    unsigned int r;
    asm("pextlw %0,$0,%1" : "=r"(r) : "r"(x));
    return r;
}

// [L] stand-in for CGt2dObject::SetColour(GtMathPs2::CGtV4d) (E map 0x19CC60, by value); the colour at +0x10 (as func_00431160)
static inline void func_0043A040_inl3(UnkStruct_0043A040_obj *o, CGtV4d c)
{
    o->field_10 = c;
}

// 0x0043A040
extern "C" void func_0043A040(UnkStruct_0043A040 *self)
{
    for (int i = 0; i < 7; i++) {
        int idx = i + (self->field_C00 - 3);
        if (idx >= 0 && idx < 15) {
        func_0043A420(self, self->field_860[i], idx, 0);
        func_0043A420(self, self->field_60C[i], idx, 1);
        CGtV4d c(1.0f, 1.0f, 1.0f, 1.0f);
        c.SetA(1.0f - 0.2333333343f * (float)(int)func_0043A040_inl2(func_0043A040_inl1(i - 3)));
        if (self->field_BE4[i] != 0) func_0043A040_inl3(self->field_BE4[i], c);
        } else {
        *self->field_860[i] = 0;
        *self->field_60C[i] = 0;
        if (self->field_BE4[i] != 0) { CGtV4d z(0.0f, 0.0f, 0.0f, 0.0f); func_0043A040_inl3(self->field_BE4[i], z); }
        }
    }
}
