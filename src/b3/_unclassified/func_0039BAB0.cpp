// Hand-written; the lifter refused it (Ghidra draft + VSelect sibling shape; switch on pabsw/pextlw abs; const& CGtV4d vmul stand-in (no dead slots); size declared before y, assigned late).

// func_0039BAB0 -- hand-written (ghvu7) from the Ghidra draft and the sibling item preparer func_00320EB0
// (B3VSelectComponent_00320EB0.cpp). [L] DNAT: CB3ScrollVSelectComponent::PrepareItem(int) (research/proto/new_names.csv,
// low -- hint only). Field names are placeholders and every type is [G].
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

extern CB3MenuPageManager D_01E90240;
struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;
extern const CGtV4d D_004C9A30;
extern const CGtV4d D_004C9A40;
extern unsigned short D_004C9A50[];
extern const CGtV2d D_004C9A20;

class CB3FlashText2dObject : public CGt2dObject {
public:
    void Prepare(const CGtV2d &pos, const CGtV2d &anchor, float size, CGtV4d colour, const CGt2dFont *font,
                 const unsigned short *text, const CGtV2d &outline);
};
struct UnkStruct_0039BAB0_e { unsigned short *field_0; unsigned char field_4; unsigned char pad_5[3]; };
struct UnkStruct_0039BAB0_c { unsigned short field_0; unsigned short field_2; };
struct UnkStruct_0039BAB0 {
    unsigned char pad_0[0xC];
    UnkStruct_0039BAB0_c *field_C;
    UnkStruct_0039BAB0_e *field_10;
    CB3FlashText2dObject *field_14[11];
    float field_40;
    float field_44;
    unsigned char pad_48[4];
    float field_4C;
    float field_50;
    unsigned char pad_54[5];
    signed char field_59;
    unsigned char field_5A;
};

// [L] integer abs via MMI (as func_00301D50's helpers): pabsw, then zero-extended with pextlw.
static inline int func_0039BAB0_inl1(int x) { int r; asm("pabsw %0,%1" : "=r"(r) : "r"(x)); return r; }
static inline long func_0039BAB0_inl2(int x) { long r; asm("pextlw %0,$0,%1" : "=r"(r) : "r"(x)); return r; }

// [L] N185: CGtV4d::operator*(CGtV4d) with the argument by reference (the header's by-value copy leaves a dead
// 16-byte slot per call, which retail's frame doesn't have).
static inline CGtV4d func_0039BAB0_inl3(const CGtV4d &a, const CGtV4d &o) { u_long128 t; asm("vmul.xyzw %0, %2, %1" : "=j"(t) : "j"(o.mData), "j"(a.mData)); return CGtV4d(t); }

// 0x0039BAB0
extern "C" void func_0039BAB0(UnkStruct_0039BAB0 *self, int item)
{
    CB3MenuPageManager *mgr = &D_01E90240;
    float size;
    float y = self->field_40 + 32.0f * (float)item;
    int d = item - self->field_59;
    int k = d + self->field_C->field_0;
    size = 30.0f;
    CGtV4d colour;
    if (!self->field_5A) {
        switch (func_0039BAB0_inl2(func_0039BAB0_inl1(d))) {
        case 0:
            colour = mgr->field_0[1];
            size = 40.0f;
            break;
        case 1:
            colour = mgr->field_0[0];
            break;
        case 2:
            colour = func_0039BAB0_inl3(mgr->field_0[0], D_004C9A30);
            break;
        case 3:
            colour = func_0039BAB0_inl3(mgr->field_0[0], D_004C9A40);
            break;
        }
    } else if (d == 0) {
        colour = mgr->field_0[1];
        size = 40.0f;
    } else {
        colour = mgr->field_0[0];
    }
    const unsigned short *text;
    if (k < 0 || k >= self->field_C->field_2) {
        text = D_004C9A50;
    } else {
        UnkStruct_0039BAB0_e *e = &self->field_10[k];
        text = e->field_0;
        if (self->field_5A && e->field_4) colour = mgr->field_0[2];
    }
    float w = D_00665ED0.pFont->GetStringWidth(text);
    if (w * size > self->field_50)
        size = self->field_50 / w;
    self->field_14[item]->Prepare(CGtV2d(self->field_44, y), CGtV2d(self->field_4C, 0.5f), size, colour,
                                  D_00665ED0.pFont, text, D_004C9A20);
}
