// func_004617B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (mwperm: +'static inline unsigned int func_004617B0_inl1(UnkStruct_004617B0 * a0) { unsigne'; +'UnkStruct_004617B0_7 * p1; unsigned short uf; UnkStruct_004617B0 * v1 = self; un'; 'int flags = D_004B06F2.field_0[self->field_94].field_0; UnkS' -> 'flags = ((unsigned short)D_004B06F2.field_0[func_004617B0_inl1(v0)].field_0); in'; 'if (flags & 0x8000) { self->field_A8 = 90.0f; } else if (fla' -> 'if (!(0x8000 ).

// lifter variant 0
// func_004617B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_004617B0;
struct UnkStruct_004617B0_7;
struct UnkStruct_004617B0_8;
struct UnkStruct_004617B0_9;
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_004617B0_e0;
struct UnkStruct_004617B0_e1;
struct UnkStruct_D_004B06F0;
struct UnkStruct_D_004B06F2;

struct UnkStruct_004617B0_e0 {
    unsigned short field_0;
    unsigned char pad_2[0x2];
};

struct UnkStruct_D_004B06F2 {
    UnkStruct_004617B0_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004617B0_e1 {
    unsigned short field_0;
    unsigned char pad_2[0x2];
};

struct UnkStruct_D_004B06F0 {
    UnkStruct_004617B0_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004617B0_7 {
    GtMathPs2::CGtV2d field_0;
    float field_8;
};

struct UnkStruct_004617B0_8 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};

struct UnkStruct_004617B0_9 {
    float field_0;
    float field_4;
};

struct UnkStruct_004617B0 {
    unsigned char pad_0[0x94];
    int field_94;
    unsigned char pad_98[0x4];
    float field_9C;
    unsigned char pad_A0[0x4];
    float field_A4;
    float field_A8;
};

extern UnkStruct_D_004B06F2 D_004B06F2;
extern UnkStruct_D_004B06F0 D_004B06F0;
extern float D_004D3A70[];  // [G] element count unknown

extern "C" UnkStruct_004617B0_7 * func_004614B0(UnkStruct_004617B0 *, unsigned short, unsigned short);

static inline unsigned int func_004617B0_inl1(UnkStruct_004617B0 * a0)
{
    unsigned int t6 = a0->field_94;
    const unsigned int t9 = t6;
    unsigned int t11 = t9;
    return t11;
}

// N182: `#pragma opt_rebuildconditionals off` ([G] scoped to this function; found by mwperm).
#pragma push
#pragma opt_rebuildconditionals off
static inline int func_004617B0_inl2(unsigned int a0)
{
    unsigned int t7 = 0x1000 & a0;
    return t7;
}

static inline float func_004617B0_inl3(int a0)
{
    return D_004D3A70[a0] * 0.9f;
}

// 0x004617B0
extern "C" void func_004617B0(UnkStruct_004617B0 * self)
{
    UnkStruct_004617B0_7 * p1;
    unsigned short uf;
    UnkStruct_004617B0 * v1 = self;
    unsigned short f;
    UnkStruct_004617B0 * v0 = v1;
    short t1;
    int t2;
    float v;
    unsigned int flags;
    if (self->field_94 == -1) {
        return;
    }
    flags = ((unsigned short)D_004B06F2.field_0[func_004617B0_inl1(v0)].field_0);
    int t5;
    t5 = flags & 0xFF;
    t1 = D_004B06F0.field_0[func_004617B0_inl1(v0)].field_0;
    UnkStruct_004617B0_7 * t8 = func_004614B0(self, flags, t1);
    t2 = func_004617B0_inl1(v0);
    float t4;
    float t3;
    t3 = ((func_004617B0_inl3(t5)));
    v = ((D_004D3A70[0xFF & flags] * 0.9f));
    int t0;
    t3 = t3;
    if (self->field_94 != -1) {
        if (!(0x8000 & flags)) {
            if (!((func_004617B0_inl2(flags)))) {
            } else {
                v0->field_A8 = 70.0f;
            }
        } else {
            v0->field_A8 = 90.0f;
        }
        if (!(0x400 & flags)) {
        } else {
            flags = (func_004617B0_inl1(((UnkStruct_004617B0 *)v0)) + D_004B06F2.field_0)->field_0;
            p1 = func_004614B0(self, flags, D_004B06F0.field_0[self->field_94].field_0);
            CGtV2d a(304.0f - t8->field_8, t8->field_0.Y());
            t8->field_0 = a;
            CGtV2d b(336.0f, p1->field_0.Y());
            p1->field_0 = b;
        }
        if (self->field_94 != -1) {
            f = (*(func_004617B0_inl1(v0) + D_004B06F2.field_0)).field_0;
            if (1) {
                t5 = 0xFF & f;
                if ((t5) == 2) {
                    do {
                        v += 60.0f;
                    } while (0);
                } else if (1 == (t5)) {
                    v += 20.0f;
                } else if (3 == (t5)) {
                    v += 120.0f;
                } else if ((t5) == 7) {
                    v += 10.0f;
                } else if ((t5) == 5) {
                    v += 16.0f;
                }
            }
            if (f & 0x100) {
                v += 320.0f;
            }
        }
    }
    uf = flags;
    do {
        if ((t0 = 0x200 & uf)) {
            v += 320.0f;
        }
        if (!(uf & 0x2000)) {
        } else {
            v += (t4 = t3);
        }
        self->field_9C = v / (0, v0->field_A4);
    } while (0);
}
