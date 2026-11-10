// CB3GraphicsManagerBase::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3GraphicsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (L262: from a31v7 -- texture-find inline takes (dic, name) for s3/s4 order; field_30/38 as float[2] struct copy).

class CGt2dFont;
// [G] 8-byte float pair copied as a whole (retail loads both lanes, then stores both): an array member, as
// GtMathPs2::CGtV2d::marValues; x/y scalar members give the other register order (L262).
struct UnkStruct_0019EE40_v2 { float v[2]; };
class CGtTexture;
struct RwCamera;

struct UnkStruct_0019EE40_dic;
struct UnkStruct_0019EE40_e0;

struct UnkStruct_0019EE40_dic {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_0019EE40_e0 * field_C;
};

struct UnkStruct_0019EE40_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113).
struct UnkStruct_0019EE40_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

// [G] a CB3Viewport (Construct__11CB3ViewportFiii / CGtViewport calls at +0x90, +0x130, +0x310); 0xA0 apart.
struct UnkStruct_0019EE40_vp {
    unsigned char pad_0[0x58];
    RwCamera * field_58;
    unsigned char pad_5C[0x28];
    float field_84;
    float field_88;
    unsigned char pad_8C[0x14];
};

// [G] a CB3Bloom (+0x0), an object func_00426070 constructs (+0x10) and three words; at +0x220 and +0x2C0.
struct UnkStruct_0019EE40_bl {
    unsigned char field_0[0x10];
    unsigned char field_10[0x30];
    int field_40;
    int field_44;
    float field_48;
    unsigned char pad_4C[0x4];
};

class CB3GraphicsManagerBase {
public:
    void Construct();

    static CGt2dFont * mgpFontDef;
    static CGt2dFont * mgpSmallFontDef;
    static CGt2dFont * mgpFontTexDic;
    static UnkStruct_0019EE40_dic * mgpB3LogoTexDic;
    static UnkStruct_0019EE40_dic * mgpSmallFontTexDic;

    int field_0;
    int field_4;
    int field_8;
    unsigned char field_C;
    unsigned char pad_D[0x2];
    unsigned char field_F;
    CGt2dFont * field_10;
    CGt2dFont * field_14;
    CGt2dFont * field_18;
    unsigned char field_1C[0x14];
    UnkStruct_0019EE40_v2 field_30;
    UnkStruct_0019EE40_v2 field_38;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    unsigned char pad_50;
    unsigned char field_51;
    unsigned char pad_52[0x1E];
    float field_70[5];
    unsigned char pad_84[0x4];
    int field_88;
    unsigned char pad_8C[0x4];
    UnkStruct_0019EE40_vp field_90;
    UnkStruct_0019EE40_vp field_130;
    unsigned char pad_1D0[0x50];
    UnkStruct_0019EE40_bl field_220;
    unsigned char pad_270[0x50];
    UnkStruct_0019EE40_bl field_2C0;
    UnkStruct_0019EE40_vp field_310;
    int field_3B0;
    int field_3B4;
};

struct UnkStruct_gVehicleRenderer {
    unsigned char pad_0[0x10];
};

struct UnkStruct_D_01E32A10 {
    unsigned char pad_0[0x10];
};

extern const char * D_004E1574;
extern const char * D_004E1578;
extern UnkStruct_0019EE40_dic * D_004E1588;
extern char D_004B7378[];
extern float karDefaultLodSwitchDistances[5];
extern UnkStruct_gVehicleRenderer gVehicleRenderer;
extern UnkStruct_D_01E32A10 D_01E32A10;

extern "C" int strcasecmp(const char *, const char *);
extern "C" void Construct__12Gt2dRendererFv();  // Gt2dRenderer::Construct()
extern "C" void Construct__6B3Im3dFv();  // B3Im3d::Construct()
extern "C" void Construct__11CB3ViewportFiii(UnkStruct_0019EE40_vp *, int, int, int);  // CB3Viewport::Construct(int,int,int)
extern "C" void SetFOV__11CGtViewportFf(UnkStruct_0019EE40_vp *, float);  // CGtViewport::SetFOV(float)
extern "C" void Prepare__11CGtViewportFv(UnkStruct_0019EE40_vp *);  // CGtViewport::Prepare()
extern "C" RwCamera * RwCameraSetNearClipPlane(RwCamera *, float);
extern "C" RwCamera * RwCameraSetFarClipPlane(RwCamera *, float);
extern "C" void Construct__15CGtScreenCentreFv(void *);  // CGtScreenCentre::Construct()
extern "C" float GetPositionX__15CGtScreenCentreFv(void *);  // CGtScreenCentre::GetPositionX()
extern "C" float GetPositionY__15CGtScreenCentreFv(void *);  // CGtScreenCentre::GetPositionY()
extern "C" void Construct__18CB3VehicleRendererFv(void *);  // CB3VehicleRenderer::Construct()
extern "C" void func_0026BCA0(void *);
extern "C" void Construct__8CB3BloomFv(void *);  // CB3Bloom::Construct()
extern "C" void func_00426070(void *);
extern "C" void Prepare__9CGt2dFontFP10CGtTexture(CGt2dFont *, CGtTexture *);  // CGt2dFont::Prepare(CGtTexture*)
extern "C" void MakeNumberCharactersFixedWidth__9CGt2dFontFv(CGt2dFont *);  // CGt2dFont::MakeNumberCharactersFixedWidth()
// [C] retail reads a1 (daddu s0, a1): an extra argument beyond the mangled name's.
extern "C" void SetViewportsSinglePlayer__22CB3GraphicsManagerBaseFv(CB3GraphicsManagerBase *, int);

static inline CGtTexture * func_0019EE40_inl1(UnkStruct_0019EE40_dic * t0, const char * name)
{
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_0019EE40_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return (CGtTexture *)t2;
        }
    }
    return 0;
}

// 0x0019EE40
void CB3GraphicsManagerBase::Construct()
{
    Construct__12Gt2dRendererFv();
    Construct__6B3Im3dFv();
    Construct__11CB3ViewportFiii(&field_310, field_0, field_4, field_8);
    Construct__11CB3ViewportFiii(&field_90, 0, 0, 0);
    Construct__11CB3ViewportFiii(&field_130, 0, 0, 0);
    SetFOV__11CGtViewportFf(&field_310, 30.0f);
    field_310.field_84 = 0.5f;
    RwCameraSetNearClipPlane(field_310.field_58, field_310.field_84);
    field_310.field_88 = 10000;
    RwCameraSetFarClipPlane(field_310.field_58, field_310.field_88);
    field_90.field_84 = 0.5f;
    RwCameraSetNearClipPlane(field_90.field_58, field_90.field_84);
    field_90.field_88 = 10000;
    RwCameraSetFarClipPlane(field_90.field_58, field_90.field_88);
    field_130.field_84 = 0.5f;
    RwCameraSetNearClipPlane(field_130.field_58, field_130.field_84);
    field_130.field_88 = 10000;
    RwCameraSetFarClipPlane(field_130.field_58, field_130.field_88);
    field_40 = 0;
    field_44 = 0;
    field_48 = 0;
    field_4C = 0;
    Construct__15CGtScreenCentreFv(field_1C);
    field_30.v[0] = GetPositionX__15CGtScreenCentreFv(field_1C);
    field_30.v[1] = GetPositionY__15CGtScreenCentreFv(field_1C);
    field_38 = field_30;
    field_3B0 = 0;
    field_3B4 = 0;
    field_C = 0;
    field_F = 0;
    Construct__18CB3VehicleRendererFv(&gVehicleRenderer);
    func_0026BCA0(&D_01E32A10);
    for (int i = 0; i < 5; i++) {
        field_70[i] = karDefaultLodSwitchDistances[i];
    }
    Construct__8CB3BloomFv(field_220.field_0);
    func_00426070(field_220.field_10);
    field_220.field_40 = 0;
    field_220.field_44 = 0;
    field_220.field_48 = 1.0f;
    Construct__8CB3BloomFv(field_2C0.field_0);
    func_00426070(field_2C0.field_10);
    field_2C0.field_40 = 0;
    field_2C0.field_44 = 0;
    field_2C0.field_48 = 1.0f;
    field_51 = 0;
    field_10 = mgpFontDef;
    field_14 = mgpSmallFontDef;
    field_18 = mgpFontTexDic;
    Prepare__9CGt2dFontFP10CGtTexture(field_10, func_0019EE40_inl1(D_004E1588, D_004E1574));
    MakeNumberCharactersFixedWidth__9CGt2dFontFv(field_10);
    Prepare__9CGt2dFontFP10CGtTexture(field_14, func_0019EE40_inl1(mgpB3LogoTexDic, D_004E1578));
    MakeNumberCharactersFixedWidth__9CGt2dFontFv(field_14);
    Prepare__9CGt2dFontFP10CGtTexture(field_18, func_0019EE40_inl1(mgpSmallFontTexDic, D_004B7378));
    MakeNumberCharactersFixedWidth__9CGt2dFontFv(field_18);
    for (int j = 0; j < 5; j++) {
        field_70[j] = karDefaultLodSwitchDistances[j];
    }
    SetViewportsSinglePlayer__22CB3GraphicsManagerBaseFv(this, 0);
    Prepare__11CGtViewportFv(&field_310);
    Prepare__11CGtViewportFv(&field_90);
    Prepare__11CGtViewportFv(&field_130);
    field_88 = 1;
}
