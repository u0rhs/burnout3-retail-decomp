// Hand-written; the lifter refused it (hdr15: header SetA two-statement (N234)).

// func_0042B030 -- hand-written (fresh6). Unnamed in every table (research/nahelam_check.csv lists an unknown-confidence
// candidate only), so the asm label with C linkage; `self` is whatever a0 points to. Every type is [G].
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV3d;
using GtMathPs2::CGtV4d;

class CGtTexture;
struct UnkStruct_0042B030_e1 { int field_0; unsigned char pad_4[0xC]; };
class CGt2dFrame;
class CGt2dScene {
public:
    int ConstructObject(int, CGt2dFrame *);
    unsigned char pad_0[0x14];
    CGt2dFrame *field_14;
    unsigned char pad_18[0x14];
    UnkStruct_0042B030_e1 *field_2C;
};
struct UnkStruct_0042B030_e0 { unsigned char pad_0[0x8]; int field_8; unsigned char pad_C[0x4]; };
struct UnkStruct_0042B030_4 { unsigned char pad_0[0x8]; int field_8; UnkStruct_0042B030_e0 *field_C; };
struct UnkStruct_D_0051A868 { UnkStruct_0042B030_4 *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0042B030_blk { unsigned char pad_0[0x18]; char field_18[8]; };
struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x110];
    CGtV4d field_110;
    unsigned char pad_120[0x80];
    CGt2dScene field_1A0;
};
class CB3RaceCar { public: void SetCarID(unsigned long); unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051A6A8 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x10]; };
struct UnkStruct_0042B030_cam {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
};

extern UnkStruct_D_0051A868 D_0051A868;
extern UnkStruct_D_01E90240 D_01E90240;
extern CB3RaceCar D_00652350;
extern CB3RaceCar D_006547B0;
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern UnkStruct_D_00665EC0 D_00665EC0;
extern char D_004D1688[];
extern char D_004D1698[];
extern char D_004D16A8[];
extern char D_004D16B8[];
extern char D_004D16C8[];
extern const CGtV2d D_004D1560;
extern const CGtV2d D_004D1568;
extern const CGtV2d D_004D1570;
extern const CGtV2d D_004D15A0;
extern const CGtV2d D_004D15B8;

extern "C" int strcasecmp(const char *, const void *);
extern "C" void func_00130C70(void *);
extern "C" void func_00130D00(void *);
extern "C" void AttachCameraToViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelectionP9CGtCamera(void *, int, void *);
extern "C" void Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, CGtTexture *, const CGtV2d &, const CGtV2d &, unsigned int);

class CB3MenuComponentBase {
public:
    bool Prepare();
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    unsigned char field_C;
    unsigned char pad_D[0x13];
};

class UnkStruct_0042B030 : public CB3MenuComponentBase {
public:
    UnkStruct_0042B030_cam field_20;
    unsigned char pad_24[0x3C];
    CGtV3d field_60;
    float field_70;
    float field_74;
    float field_78;
    float field_7C;
    unsigned char field_80;
    unsigned char pad_81[0x7];
    unsigned long field_88;
    unsigned char pad_90[0x4];
    int field_94;
    int field_98;
    unsigned char field_9C;
    signed char field_9D;
    signed char field_9E;
    unsigned char pad_9F[0x1];
    void *field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    float field_B0;
    float field_B4;
    float field_B8;
    unsigned char pad_BC[0x4];
    CGtTexture *field_C0;
    CGtTexture *field_C4;
    CGtTexture *field_C8;
    CGtTexture *field_CC;
    CGtTexture *field_D0;
    unsigned char field_D4;
    unsigned char pad_D5[0xB];
    void *field_E0;
    unsigned char pad_E4[0x8];
    unsigned char field_EC;
};

// [G] inlined texture find by name (no name known for it)
static inline CGtTexture *func_0042B030_inl1(const char *name)
{
    int i;
    UnkStruct_0042B030_4 *t0 = D_0051A868.field_0;
    for (i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_0042B030_blk *)(t2 + 0x90))->field_18, name) == 0) return (CGtTexture *)t2;
    }
    return (CGtTexture *)0;
}

// 0x0042B030
extern "C" int func_0042B030(UnkStruct_0042B030 *self, unsigned char p1, unsigned char p2)
{
    self->field_A4 = 0;
    self->field_AC = 0x2B9D6F8;
    self->field_A8 = 0xFD462907;
    self->CB3MenuComponentBase::Prepare();
    CGt2dScene *scene = &D_01E90240.field_1A0;
    CGt2dFrame *root = scene->field_14;
    self->field_80 = p2;
    self->field_D4 = p1;
    self->field_A0 = 0;
    self->field_E0 = 0;
    if (self->field_D4 == 0) {
        scene->field_2C[self->field_8].field_0 = 8;
        self->field_A0 = (void *)scene->ConstructObject(self->field_8, root);
    } else {
        scene->field_2C[self->field_8].field_0 = 2;
        self->field_E0 = (void *)scene->ConstructObject(self->field_8, root);
    }
    self->field_B0 = 1.0f;
    self->field_B4 = 0.0f;
    self->field_B8 = 0.0f;
    self->field_C0 = func_0042B030_inl1(D_004D1688);
    self->field_C4 = func_0042B030_inl1(D_004D1698);
    self->field_C8 = func_0042B030_inl1(D_004D16A8);
    self->field_CC = func_0042B030_inl1(D_004D16B8);
    self->field_D0 = func_0042B030_inl1(D_004D16C8);
    CGtV4d c;
    if (self->field_A0 != 0) {
        c = D_01E90240.field_110;
        c.SetA(self->field_B0);
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_A0, D_004D1568, D_004D1560, D_004D1570, c, self->field_C0, D_004D15A0, D_004D15B8, 0);
    }
    if (self->field_E0 != 0) {
        c = D_01E90240.field_110;
        c.SetA(0.0f);
        Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(self->field_E0, D_004D1568, D_004D1560, D_004D1570, c);
    }
    self->field_20.vfunc_10();
    AttachCameraToViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelectionP9CGtCamera(&D_00665EC0, 1, &self->field_20);
    if (self->field_D4 == 0) {
        self->field_78 = 180.0f;
    } else {
        self->field_78 = 0.0f;
    }
    self->field_7C = 1.0f;
    self->field_74 = 9.0f;
    self->field_70 = 1.0f;
    { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); self->field_60.mData = r; }
    self->field_9C = 0;
    self->field_9D = -1;
    self->field_9E = -1;
    D_00652350.SetCarID(0xFFFFFFFFFFFFFFFF);
    D_006547B0.SetCarID(0xFFFFFFFFFFFFFFFF);
    self->field_88 = 0;
    self->field_94 = 0;
    self->field_98 = 0;
    self->field_EC = 0;
    func_00130C70(&D_0051A6A8);
    func_00130D00(&D_0051A6A8);
    AttachCameraToViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelectionP9CGtCamera(&D_00665EC0, 1, &self->field_20);
    self->field_C = 0;
    return 1;
}
