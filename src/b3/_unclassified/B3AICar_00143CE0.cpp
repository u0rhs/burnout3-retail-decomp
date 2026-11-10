// CB3AICar::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AICar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near26: header Zero()/Z()/X() + [L] N185 lane-subtract stand-ins (=j result, a then b operands), state switch wrapping the body with a shared return true, N140 pad for the 0x80 frame).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

// [L] N185: stand-ins for missing GtMathPs2 inlines (operator -(ZAxisType, ZAxisType) / (XAxisType, XAxisType)):
// the YAxisType operator-'s shape, `vsubz.z b, a, bz` / `vsubx.x b, a, bx` (retail 0x143D78 / 0x143D94)
static inline ZAxisType func_00143CE0_inl1(ZAxisType a, ZAxisType b)
{
    u_long128 r;
    asm("vsubz.z %0, %1, %2z" : "=j"(r) : "j"(a.lVector), "j"(b.lVector));
    return ZAxisType(r);
}
static inline XAxisType func_00143CE0_inl2(XAxisType a, XAxisType b)
{
    u_long128 r;
    asm("vsubx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector));
    return XAxisType(r);
}

struct UnkStruct_00143CE0_o {
    unsigned char pad_0[0xE80];
    CGtV3d field_E80;
    CGtV3d field_E90;
};
class UnkStruct_00143CE0_vt {
public:
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual int vfunc_40();
};
struct UnkStruct_00143CE0_h {
    unsigned char pad_0[0x1B4];
    UnkStruct_00143CE0_vt * field_1B4;
};
struct UnkStruct_D_0064D370 { unsigned long field_0; unsigned char pad_8[8]; };
struct UnkStruct_D_0051BA88 { UnkStruct_00143CE0_h * field_0; unsigned char pad_4[12]; };
extern UnkStruct_D_0064D370 D_0064D370;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern "C" bool Prepare__10CB3RaceCarFv(void *);
extern "C" bool Prepare__11CB3AIDriverFv(void *);

struct UnkStruct_00143CE0 {
    unsigned char pad_0[0x40];
    UnkStruct_00143CE0_o * field_40;
    unsigned char pad_44[0x196C];
    CGtV3d field_19B0;
    CGtV3d field_19C0;
    int field_19D0[8];
    unsigned char field_19F0[0x100];
    unsigned char pad_1AF0[0xE4];
    float field_1BD4;
    float field_1BD8;
    float field_1BDC;
    unsigned char field_1BE0;
    unsigned char pad_1BE1[0x1];
    unsigned char field_1BE2;
    unsigned char pad_1BE3[0x549];
    float field_212C;
    unsigned char pad_2130[0x304];
    float field_2434;
    float field_2438;
    int field_243C;
    int field_2440;
    int field_2444;
    unsigned short field_2448;
    unsigned short field_244A;
    signed char field_244C;
    unsigned char field_244D;
    unsigned char field_244E;
    unsigned char pad_244F[0x1];
    int field_2450;
    int field_2454;
};

// [G] N140 frame pad: an unused 16-byte local (retail's 0x80 frame keeps one more dead slot)
struct UnkStruct_00143CE0_pad { int x[4]; UnkStruct_00143CE0_pad() {} ~UnkStruct_00143CE0_pad() {} };

extern "C" bool Prepare__8CB3AICarFv(UnkStruct_00143CE0 * self)
{
    UnkStruct_00143CE0_pad pad;
    if (!Prepare__10CB3RaceCarFv(self)) {
        return false;
    }
    if (D_0064D370.field_0 == 0) {
        return true;
    }
    switch (self->field_2454) {
    case 1:
    case 0x18:
        self->field_2454 = 0x17;
    case 0x17:
        self->field_244E = 0;
        self->field_244D = 0;
        self->field_19B0.Zero();
        self->field_19C0.Zero();
        self->field_2438 = func_00143CE0_inl1(self->field_40->field_E80.Z(), self->field_40->field_E90.Z());
        self->field_2434 = func_00143CE0_inl2(self->field_40->field_E80.X(), self->field_40->field_E90.X());
        self->field_243C = 0;
        self->field_244C = -1;
        self->field_2448 = 0xFFFF;
        self->field_244A = 0xFFFF;
        self->field_2450 = 0;
        self->field_2444 = 0;
        for (int i = 0; i < 8; i++) {
            self->field_19D0[i] = 0;
        }
        UnkStruct_00143CE0_vt * p = D_0051BA88.field_0->field_1B4;
        if (p) {
            self->field_2440 = p->vfunc_40();
        } else {
            self->field_2440 = 0;
        }
        if (!Prepare__11CB3AIDriverFv(self->field_19F0)) {
            return false;
        }
        self->field_212C = 20.0f;
        self->field_1BE2 = 1;
        self->field_1BE0 = 0;
        self->field_1BD4 = 50.0f;
        self->field_1BD8 = 0.0f;
        self->field_1BDC = 170.0f;
        break;
    default:
        break;
    }
    return true;
}
