// Hand-written; the lifter refused it (ghvu3: Ghidra draft; switch in source order 0-3; SetA second shape (compiler-chosen scalar) as an [L] stand-in).

// Hand-written (ghvu3, Ghidra draft); the lifter refused it. Mask fade state machine (0 shown, 1 fading out, 2 swap,
// 3 fading in) at 5/s, then the texture cycle every 0.05 s and the mask alpha from field_B0.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CGtTexture;
struct CGt2dObjectImage { unsigned char pad_0[0x10]; CGtV4d field_10; };
extern "C" void SetTexture__16CGt2dObjectImageFP10CGtTexture(CGt2dObjectImage *, CGtTexture *, int);
struct UnkStruct_D_01E7A800 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E7A800 D_01E7A800;
extern "C" void func_00284260(UnkStruct_D_01E7A800 *);
extern CGtV4d D_01E90350;
class CB3CarViewComponent {
public:
    void UpdateMaskCarChangeState(float dt);
    unsigned char pad_0[0x98];
    int field_98;
    unsigned char pad_9C[4];
    CGt2dObjectImage *field_A0;
    float field_A4;
    unsigned char pad_A8[8];
    float field_B0;
    unsigned char pad_B4[4];
    float field_B8;
    int field_BC;
    CGtTexture *field_C0[5];
};
// [L] stands in for CGtV4d::SetA(float) in retail's second shape (B3EnvironmentManager_002BC190, v277): the scalar moved by its
// own qmtc2.ni statement onto a compiler-chosen register (the header body hard-codes $vf2 in one statement; here that
// form schedules the field_A0 load after the colour lqc2)
static inline void func_00427AD0_inl1(CGtV4d &c, float a) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(a)); asm("vmulx.w %0, $vf0, %1x" : "+j"(c.mData) : "j"(s)); }
// 0x00427AD0
void CB3CarViewComponent::UpdateMaskCarChangeState(float dt)
{
    switch (field_98) {
    case 0:
        field_B0 = 1.0f;
        break;
    case 1: {
        float x = field_B0 - 5.0f * dt;
        field_B0 = x;
        if (x <= 0.0f) {
            field_B0 = 0.0f;
            field_98 = 2;
        }
        break;
    }
    case 2:
        field_B0 = 0.0f;
        func_00284260(&D_01E7A800);
        break;
    case 3: {
        float x = field_B0 + 5.0f * dt;
        field_B0 = x;
        if (x >= 1.0f) {
            field_B0 = 1.0f;
            field_98 = 0;
        }
        break;
    }
    }
    if (field_A4 > field_B8) {
        CGtTexture *t = field_C0[field_BC];
        if (t != 0) {
            SetTexture__16CGt2dObjectImageFP10CGtTexture(field_A0, t, 0);
            field_B8 = field_A4 + 0.05f;
            field_BC = (field_BC + 1) % 5;
        }
    }
    CGtV4d c;
    c = D_01E90350;
    func_00427AD0_inl1(c, field_B0);
    field_A0->field_10 = c;
}
