// Hand-written; the lifter refused it (v303: DNAT TabbedDisplayComponent::Update; by-value colour setter (frame), CGtV2d operator locals for zoom, direct madd forms, scoped opt_pulloutconstants off [G], func_0042ECF0 schar/uchar params).

// func_003A5ED0 -- [L] DNAT: CB3TabbedDisplayComponent::Update(float) (research/proto/new_names.csv, medium; vtable slot 2).
// Hand-written (no lifter draft). The menu-state alpha switch of the component Updates (sibling func_003A6900), then in
// state 5 the selected tab's pulse: a 0.3 s lead, a cosine swell, the next-unlocked step (func_0042ECF0) and the
// records zoom when no tab is selected. Float shapes [G]: GtMath::CosDeg / Modulo (B3O0PCH map names) written as file-local
// inlines with placeholder names. func_0042ECF0 declared (void*, int, signed char, unsigned char) returning signed char:
// the int form loads its arguments in another order (the sibling func_003A6330 declares it with ints; reconcile on merge).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CGt2dObject;
class CGtTexture;

struct UnkStruct_D_01E90350 { u_long128 field_0; };
struct UnkStruct_D_01E90270 { u_long128 field_0; };
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E90420 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA46F4 { CGtTexture *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BF9C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E90350 D_01E90350;
extern UnkStruct_D_01E90270 D_01E90270;
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E90420 D_01E90420;
extern UnkStruct_D_01EA46F4 D_01EA46F4;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_Pad16 D_01E7A800;
extern UnkStruct_D_Pad16 D_01ECD9F0;
extern unsigned char D_004E2EDC;

struct UnkStruct_003A5ED0_col { unsigned char pad_0[0x10]; u_long128 field_10; };
struct UnkStruct_003A5ED0_box { unsigned char pad_0[0x8]; CGtV2d field_8; };
struct UnkStruct_003A5ED0_frm { CGtV2d field_0; CGtV2d field_8; };
struct UnkStruct_003A5ED0_tab {
    CGt2dObject *field_0;
    UnkStruct_003A5ED0_col *field_4;
    void *field_8;
};
struct UnkStruct_003A5ED0 {
    unsigned char pad_0[0x64];
    int field_64;
    unsigned char pad_68[0x18];
    UnkStruct_003A5ED0_tab field_80[5];
    unsigned char pad_BC[0x14];
    UnkStruct_003A5ED0_col *field_D0;
    UnkStruct_003A5ED0_frm *field_D4;
    UnkStruct_003A5ED0_box *field_D8[5];
    UnkStruct_003A5ED0_box *field_EC[5];
    float field_100;
    unsigned char pad_104[0x9];
    signed char field_10D;
};

extern "C" float cosf(float);
extern "C" void func_00283CE0(void *);
extern "C" signed char func_0042ECF0(void *, int, signed char, unsigned char);
extern "C" int func_0013A630(void *, int);
extern "C" void SetTexture__16CGt2dObjectImageFP10CGtTexture(CGt2dObject *, CGtTexture *, int);

// [G] GtMath::CosDeg(float) (B3O0PCH map, 0x38)
static inline float func_003A5ED0_inl1(float d) { return cosf(0.017453292f * d); }
// [G] GtMath::Modulo(float,float) (B3O0PCH map, 0x7C)
static inline float func_003A5ED0_inl3(float a, float b) { return a - b * (float)(int)(a / b); }
// [G] a colour setter taking the CGtV4d by value (each use keeps retail's dead 16-byte slot, N186)
static inline void func_003A5ED0_inl5(UnkStruct_003A5ED0_col *o, CGtV4d c) { o->field_10 = c.mData; }

// N182 [G] scoped to this function: opt_pulloutconstants off keeps the 1.0f of each zoom path in its own register (not
// reused at the join).
#pragma push
#pragma opt_pulloutconstants off
// 0x003A5ED0
extern "C" void func_003A5ED0(UnkStruct_003A5ED0 *self, float dt)
{
    CGtV4d c;
    c.mData = D_01E90350.field_0;
    switch (D_01E90424.field_0) {
    case 0:
    case 1:
        c.SetA(0.0f);
        break;
    case 2:
    case 3:
    case 4:
        {
            float a = D_01E90420.field_0;
            // [L] N185: stands in for CGtV4d::SetA in its second shape (v277: alpha moved before the colour's lqc2)
            asm("qmtc2.ni %0, $vf2" : : "r"(a));
            asm("vmulx.w %0, $vf0, $vf2x" : "+j"(c.mData));
        }
        break;
    case 5: {
        float s = 0.0f;
        float t = self->field_100;
        if (t < 0.0f) break;
        self->field_100 = t + dt;
        if (self->field_10D >= 0) {
            int i = self->field_10D % 5;
            float nt = self->field_100;
            if (nt >= 0.3f) {
                if (nt < 1.5f) {
                    s = 0.5f * (1.0f - func_003A5ED0_inl1(720.0f * (0.8333333f * (nt - 0.3f))));
                    func_003A5ED0_inl5(self->field_80[i].field_4, *(CGtV4d *)&D_01E90350);
                } else {
                    if (t <= 1.5f) func_00283CE0(&D_01E7A800);
                    self->field_10D = func_0042ECF0(&D_01ECD9F0, self->field_64, self->field_10D, D_004E2EDC);
                    SetTexture__16CGt2dObjectImageFP10CGtTexture(self->field_80[i].field_0, D_01EA46F4.field_0, 0);
                    func_003A5ED0_inl5(self->field_80[i].field_4, *(CGtV4d *)&D_01E90270);
                    self->field_100 = 0.0f;
                    if (self->field_10D >= (self->field_64 + 1) * 5 || self->field_10D < 0) {
                        self->field_10D = -1;
                        int j;
                        for (j = 0; j < 5; j++) {
                            if (func_0013A630((void *)(D_0051BF9C.field_0), j + self->field_64 * 5) == 0) break;
                        }
                        if (j < 5 && D_004E2EDC == 0) {
                            self->field_100 = -1.0f;
                        } else {
                            for (int k = 0; k < 5; k++)
                                func_003A5ED0_inl5(self->field_80[k].field_4, *(CGtV4d *)&D_01E90350);
                        }
                    }
                }
            }
            float a = 1.0f + 0.25f * s;
            self->field_D8[i]->field_8 = CGtV2d(a, a);
            float b = 1.0f + 0.04f * s;
            self->field_EC[i]->field_8 = CGtV2d(b, b);
        } else {
            float t2 = self->field_100;
            float g;
            if (t2 < 0.3f) {
                g = 0.04f * (0.5f * (1.0f - func_003A5ED0_inl1(180.0f * (3.3333333f * t2))));
            } else {
                float r = func_003A5ED0_inl3(t2 - 0.3f, 1.2f);
                g = 0.04f * (0.5f + 0.25f * (1.0f + func_003A5ED0_inl1(720.0f * (0.8333333f * r))));
            }
            CGtV2d sc = CGtV2d(g, g) + CGtV2d(1.0f, 1.0f);
            CGtV2d ps = CGtV2d(-320.0f, -240.0f) * g;
            self->field_D4->field_0 = ps;
            self->field_D4->field_8 = sc;
        }
        break;
    }
    }
    self->field_D0->field_10 = c.mData;
}
#pragma pop
