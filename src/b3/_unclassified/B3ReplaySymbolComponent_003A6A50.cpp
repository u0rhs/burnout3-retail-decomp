// CB3ReplaySymbolComponent::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ReplaySymbolComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (rewritten on B3BackgroundComponent's model: CGtV2d temporaries, bool func_00131CA0 with !, scene/mgr const pointers, layer+1 local, second mgr pointer for the box block, rand id before the call, 16-byte globals).

// CB3ReplaySymbolComponent::Prepare()
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class CGtTexture;

class CB3ReplaySymbolComponent {
public:
    int Prepare();

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObject * field_C;
    CGt2dObject * field_10;
    CGt2dObject * field_14;
    CGt2dObject * field_18;
};

extern CB3MenuPageManager D_01E90240;  // unnamed global (the page manager instance)
extern CGt2dScene D_01E903E0;          // [L] D_01E90240 + 0x1A0 (the page manager's scene)
struct UnkStruct_D_01EA46D8 {
    CGtTexture * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665ED0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01EA46D8 D_01EA46D8;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern char D_004EE040[];
extern char D_0051BA44[];

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Prepare()
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
#define CGt2dObjectImage_Prepare Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d
extern "C" void Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour);
#define CGt2dObjectBox_Prepare Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d
extern "C" bool func_00131CA0(void *);
extern "C" int func_00271A00(void *, int);
extern "C" void func_001D6C40(CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV4d &, void *, void *, float);

// 0x003A6A50
int CB3ReplaySymbolComponent::Prepare()
{
    Prepare__20CB3MenuComponentBaseFv(this);
    CGt2dScene * const scene = &D_01E903E0;
    int layer = field_8;
    int layer1 = layer + 1;
    CGt2dFrame * root = scene->field_14;
    CB3MenuPageManager * const mgr = &D_01E90240;
    if (!func_00131CA0(D_004EE040)) {
        field_14 = scene->ConstructObject(layer, root);
        field_18 = scene->ConstructObject(layer, root);
    }
    field_C = scene->ConstructObject(layer1, root);
    field_10 = scene->ConstructObject(layer1, root);
    CGt2dObjectImage_Prepare(field_C, CGtV2d(30.0f, 22.0f), CGtV2d(0.0f, 0.0f), CGtV2d(32.0f, 32.0f), mgr->field_110,
                             D_01EA46D8.field_0, CGtV2d(0.0f, 0.0f), CGtV2d(1.0f, 1.0f), 0);
    int r = func_00271A00(D_0051BA44, 451);
    func_001D6C40(field_10, CGtV2d(46.0f, 38.0f), CGtV2d(0.5f, 0.5f), mgr->field_110, (void *)(D_00665ED0.field_0), (void *)(r), 22.0f);
    CB3MenuPageManager * const mgr2 = &D_01E90240;
    if (!func_00131CA0(D_004EE040)) {
        CGt2dObjectBox_Prepare(field_14, CGtV2d(0.0f, 0.0f), CGtV2d(0.0f, 1.0f), CGtV2d(640.0f, 64.0f), mgr2->field_100);
        CGt2dObjectBox_Prepare(field_18, CGtV2d(0.0f, 480.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 64.0f), mgr2->field_100);
    }
    return 1;
}
