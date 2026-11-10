// func_00351F00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bool params/return for the text Prepare; scene = &D_01E90240.field_1A0 and root loaded before the text Prepare call).

class CGt2dFrame;

struct UnkStruct_00351F00;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_01E903E0;
struct UnkStruct_D_01E90240;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    CGt2dFrame * field_14;
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x1A0];
    UnkStruct_D_01E903E0 field_1A0;
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00351F00 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2A];
    void * field_34;
};

extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_0051BA44 D_0051BA44;

extern "C" bool Prepare__16CB3TextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPCUsfbfUib(void *, const void *, const void *, const unsigned short*, float, bool, float, unsigned int, bool);  // CB3TextComponent::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const unsigned short*,float,bool,float,unsigned int,bool)
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" bool Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(void *, const void *, const void *, const void *, unsigned int, int);  // CB3RoundedPanel2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,unsigned int), passed 1 more argument(s) [G]
extern "C" int func_00271A00(void *, int);

// 0x00351F00
extern "C" bool func_00351F00(UnkStruct_00351F00 * self, void *p0_, void *p1_, void *p2_, void *p3_, void *p4_, int p5, int p6, bool p7, unsigned int p8, bool p9, float f0, float f1)
{
    int p0 = (int)p0_;
    int p1 = (int)p1_;
    int p2 = (int)p2_;
    int p3 = (int)p3_;
    int p4 = (int)p4_;
    const unsigned short * str = (const unsigned short *)func_00271A00(&D_0051BA44, p5);
    UnkStruct_D_01E903E0 * scene = &D_01E90240.field_1A0;
    CGt2dFrame * root = scene->field_14;
    bool r = Prepare__16CB3TextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPCUsfbfUib(self, (void *)p0, (void *)p1, str, f0, p7, f1, p8, p9);
    self->field_34 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, root);
    Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(self->field_34, (void *)p2, (void *)p3, (void *)p4, p6 | 24, 0);
    return r;
}
