// func_00351E40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bool stack params and bool returns (TextComponent::Prepare), &D_01E903E0 held in a const pointer).

// func_00351E40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGt2dFrame;

struct UnkStruct_00351E40;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_00351E40 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2A];
    int field_34;
};

extern UnkStruct_D_01E903E0 D_01E903E0;

extern "C" bool Prepare__16CB3TextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPCUsfbfUib(void *, const void *, const void *, const unsigned short*, float, bool, float, unsigned int, bool);  // CB3TextComponent::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const unsigned short*,float,bool,float,unsigned int,bool)
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" bool Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(void *, const void *, const void *, const void *, unsigned int, int);  // CB3RoundedPanel2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,unsigned int), passed 1 more argument(s) [G]

// 0x00351E40
extern "C" bool func_00351E40(UnkStruct_00351E40 * self, void *p0_, void *p1_, void *p2_, void *p3_, void *p4_, void *p5_, int p6, bool p7, unsigned int p8, bool p9, float f0, float f1)
{
    int p0 = (int)p0_;
    int p1 = (int)p1_;
    int p2 = (int)p2_;
    int p3 = (int)p3_;
    int p4 = (int)p4_;
    int p5 = (int)p5_;
    UnkStruct_D_01E903E0 * const g = &D_01E903E0;
    int t0 = g->field_14;
    bool r0 = Prepare__16CB3TextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPCUsfbfUib(self, (void *)p0, (void *)p1, (const unsigned short*)p5, f0, p7, f1, p8, p9);
    self->field_34 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(g, self->field_8, (CGt2dFrame*)t0);
    Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi((void *)self->field_34, (void *)p2, (void *)p3, (void *)p4, (p6 | 24), 0);
    return r0;
}
