// Hand-written; the lifter refused it (pass2e: zero colour as a named CGtV4d local in its own block inside the null test (slot 0x50 as retail)).

// fresh3: 3-row list refresh (sibling of func_004313E0); logic/layout/frame size exact, SetColour by-value stand-in gives the 0xC0 frame; left: zero-colour ctor temp at sp+0x40, retail sp+0x50 (5 instrs)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00431160_a { unsigned char pad_0[0x8]; int field_8; int field_C; int field_10; unsigned char field_14; unsigned char pad_15[0xB]; };
struct UnkStruct_00431160_b { unsigned char pad_0[0x4]; unsigned int field_4; unsigned char pad_8[0x4C]; unsigned char field_54; unsigned char pad_55[0xB]; };
struct UnkStruct_00431160_obj { unsigned char pad_0[0x10]; CGtV4d field_10; };
struct UnkStruct_00431160 {
    unsigned char pad_0[0x4];
    unsigned short field_4[3][3];
    unsigned char pad_16[0xFA];
    unsigned short field_110[3][0x80];
    unsigned short field_410[0xB8];
    unsigned short field_580[3][0x20];
    unsigned char pad_640[0x2EC];
    UnkStruct_00431160_obj *field_92C[3];
    int field_938;
    unsigned char pad_93C[0x7C];
    int field_9B8;
    UnkStruct_00431160_b *field_9BC;
};
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0051BA44 D_0051BA44;
extern unsigned short D_004E25F0[2];
extern const int D_004D19E0[4];
extern "C" void PrintUInt__10CGtUnicodeFPUsUii(unsigned short *, unsigned int, int);
extern "C" unsigned short *Append__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" unsigned short *Copy__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" unsigned short *func_00271A00(void *, int);
extern "C" void func_003FBB00(int, int, void *, void *, int, int);

static inline int func_00431160_inl1(int x)
{
    int r;
    asm("pabsw %0,%1" : "=r"(r) : "r"(x));
    return r;
}
static inline unsigned int func_00431160_inl2(unsigned int x)
{
    unsigned int r;
    asm("pextlw %0,$0,%1" : "=r"(r) : "r"(x));
    return r;
}

// [L] stand-in for CGt2dObject::SetColour(GtMathPs2::CGtV4d) (E map 0x19CC60, by value); the colour at +0x10
static inline void func_00431160_inl3(UnkStruct_00431160_obj *o, CGtV4d c)
{
    o->field_10 = c;
}

// 0x00431160
extern "C" void func_00431160(UnkStruct_00431160 *self)
{
    for (int i = 0; i < 3; i++) {
        int idx = self->field_938 - 1 + i;
        if (idx >= 0 && (unsigned int)idx < self->field_9BC->field_4) {
        PrintUInt__10CGtUnicodeFPUsUii(self->field_4[i], idx + 1, 0);
        if (self->field_9BC->field_54 != 0) {
            UnkStruct_00431160_a la;
            func_003FBB00(self->field_9B8, idx, self->field_9BC, &la, 0, 0);
            unsigned short *s;
            Copy__10CGtUnicodeFPUsPCUs(s = self->field_110[i], func_00271A00(&D_0051BA44, la.field_10));
            Append__10CGtUnicodeFPUsPCUs(s, D_004E25F0);
            Append__10CGtUnicodeFPUsPCUs(s, func_00271A00(&D_0051BA44, la.field_8));
            Append__10CGtUnicodeFPUsPCUs(s, D_004E25F0);
            Append__10CGtUnicodeFPUsPCUs(s, func_00271A00(&D_0051BA44, la.field_C));
            int k;
            switch (la.field_14 & 7) {
            case 7:
                k = 0;
                break;
            case 1:
                k = 1;
                break;
            case 4:
                k = 2;
                break;
            default:
                k = 3;
                break;
            }
            Copy__10CGtUnicodeFPUsPCUs(self->field_580[i], func_00271A00(&D_0051BA44, D_004D19E0[k]));
        }
        CGtV4d c(1.0f, 1.0f, 1.0f, 1.0f);
        c.SetA(1.0f - 0.400000006f * (float)(int)func_00431160_inl2(func_00431160_inl1(i - 1)));
        if (self->field_92C[i] != 0) func_00431160_inl3(self->field_92C[i], c);
        } else {
        self->field_4[i][0] = 0;
        self->field_110[i][0] = 0;
        self->field_580[i][0] = 0;
        if (self->field_92C[i] != 0) { CGtV4d z(0.0f, 0.0f, 0.0f, 0.0f); func_00431160_inl3(self->field_92C[i], z); }
        }
    }
}
