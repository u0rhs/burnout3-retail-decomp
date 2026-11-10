// CB3SatNavComponent::PrepareCustomLeadIn() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SatNavComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (a131: inline CGtV2d temporaries per call (separate slots), 9th arg unsigned long (sd zero), int i declared after root; sibling func_003A8BF0).

#include "b3/GtMathPs2.h"

class CGt2dFrame;
enum EB3TrackRegion {};
class CGtTexture;

class CB3HardCodedTrackRegionList;
class CB3SatNavComponent;
struct UnkStruct_003AAE30_5;
struct UnkStruct_003AAE30_e2;
struct UnkStruct_003AAE30_e4;
struct UnkStruct_D_004E2EA8;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E903E0;
struct UnkStruct_D_01EA4070;
struct UnkStruct_D_01EA4790;
struct UnkStruct_D_01EA4798;

class CB3HardCodedTrackRegionList {
public:
    static int GetZoomImage(EB3TrackRegion, int);
    static int GetFakeMipImage(EB3TrackRegion, int);
};

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0x14];
    UnkStruct_003AAE30_e2 * field_2C;
};

struct UnkStruct_003AAE30_e2 {
    int field_0;
    unsigned char pad_4[0xC];
};

struct UnkStruct_003AAE30_5 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    float field_28;
    float field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
};

struct UnkStruct_D_01EA4070 {
    unsigned char pad_0[0x400];
    int field_400[1];  // [G] element count unknown
};

struct UnkStruct_D_004E2EA8 {
    int field_0;
};

struct UnkStruct_003AAE30_e4 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x110];
    GtMathPs2::CGtV4d field_110;
};

struct UnkStruct_D_01EA4790 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA4798 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SatNavComponent {
public:
    void PrepareCustomLeadIn();
    void UpdateCustomLeadIn(float);

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    unsigned char pad_C[0x1F8];
    int field_204[2];
    int field_20C[2];
    unsigned char pad_214[0x4];

    int field_218;
    int field_21C;
    unsigned char pad_220[0x34];
    int field_254;
    unsigned char pad_258[0x4AC];
    int field_704;
    unsigned char pad_708[0x2A8];
    int field_9B0;
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_01EA4070 D_01EA4070;
extern UnkStruct_D_004E2EA8 D_004E2EA8;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01EA4790 D_01EA4790;
extern UnkStruct_D_01EA4798 D_01EA4798;

extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, GtMathPs2::CGtV4d, void *, const void *, const void *, unsigned int);  // CGt2dObjectImage::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d,CGtTexture*,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&)
extern "C" bool Prepare__21CB3RadialBlur2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dff(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, float, float);  // CB3RadialBlur2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,float,float)


extern float D_004E0B74;
extern float D_004E0C18;
extern float D_004E06B4;

// 0x003AAE30
void CB3SatNavComponent::PrepareCustomLeadIn()
{
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    int t0 = field_8;
    int root = scene->field_14;
    int i;
    int a = t0 + 2;
    int b = t0 + 10;
    for (i = 0; i < 2; i++) {
        field_204[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, t0 + i, (void *)root);
    }
    for (i = 0; i < 2; i++) {
        field_20C[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, a + i, (void *)root);
        scene->field_2C[a + i].field_0 = 8;
    }
    field_218 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, b, (void *)root);
    for (i = 0; i < 2; i++) {
        int r = CB3HardCodedTrackRegionList::GetZoomImage((EB3TrackRegion)field_254, i);
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d((void *)field_204[i], GtMathPs2::CGtV2d(0.0f, 0.0f), GtMathPs2::CGtV2d(0.0f, 0.0f), GtMathPs2::CGtV2d(640.0f, 416.0f), mgr->field_110, (void *)D_01EA4070.field_400[r], &D_01EA4790, &D_01EA4798, 0);
    }
    for (i = 0; i < 2; i++) {
        int r = CB3HardCodedTrackRegionList::GetFakeMipImage((EB3TrackRegion)field_254, i);
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d((void *)field_20C[i], GtMathPs2::CGtV2d(0.0f, 0.0f), GtMathPs2::CGtV2d(0.0f, 0.0f), GtMathPs2::CGtV2d(640.0f, 416.0f), mgr->field_110, (void *)D_01EA4070.field_400[r], &D_01EA4790, &D_01EA4798, 0);
    }
    Prepare__21CB3RadialBlur2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dff((void *)field_218, GtMathPs2::CGtV2d(D_004E0C18, D_004E0C18), GtMathPs2::CGtV2d(D_004E0B74, D_004E0B74), 1.0f, D_004E06B4);
    field_704 = 0;
    D_004E2EA8.field_0 = 0;
    field_9B0 = 0;
    field_21C = 0;
    UpdateCustomLeadIn(0.0f);
}
