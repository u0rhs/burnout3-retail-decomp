// CB3AITarget::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AITarget.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3AITarget has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].

#include "b3/GtMathPs2.h"

class CB3AICar;

class CB3AITarget;
class CB3AITargetSpline;

class CB3AITargetSpline {
public:
    void Prepare(CB3AICar*);
};

class CB3AITarget {
public:
    int Prepare();

    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x8];
    CB3AITargetSpline field_10;
    unsigned char pad_11[0x1BF];
    int field_1D0;
    int field_1D4;
    unsigned short field_1D8;
    unsigned char pad_1DA[0x2];
    int field_1DC;
    int field_1E0;
    int field_1E4;
    int field_1E8;
    int field_1EC;
    unsigned char field_1F0;
    unsigned char field_1F1;
    unsigned char field_1F2;
    unsigned char field_1F3;
    unsigned char pad_1F4[0xC];
    GtMathPs2::CGtV3d field_200;
    unsigned char pad_210[0x2];
    unsigned char field_212;
    unsigned char field_213;
    unsigned char pad_214[0x3C];
    GtMathPs2::CGtV3d field_250;
    unsigned char pad_260[0x20];
    GtMathPs2::CGtV3d field_280;
    signed char field_290;
    unsigned char field_291;
    unsigned char field_292;
    unsigned char field_293;
    unsigned char field_294;
    unsigned char field_295;
    unsigned char field_296;
    unsigned char pad_297[0x1];
    int field_298;
    int field_29C;
    int field_2A0;
    short field_2A4;
    short field_2A6;
};

extern "C" void Prepare__24CB3AIAggressionBehaviourFP8CB3AICar(void *, void *);  // CB3AIAggressionBehaviour::Prepare(CB3AICar*)
extern "C" void ResetCornerStatus__11CB3AITargetFv(void *);  // CB3AITarget::ResetCornerStatus()

// 0x0014DC70
int CB3AITarget::Prepare()
{
    field_10.Prepare((CB3AICar*)field_4);
    Prepare__24CB3AIAggressionBehaviourFP8CB3AICar(((char *)this + 0x170), (CB3AICar*)field_4);
    field_200.Zero();
    field_1D0 = 0;
    field_280.Zero();
    field_212 = 0;
    field_213 = 0;
    field_1D4 = 0;
    field_296 = 1;
    field_1DC = 0;
    field_1E0 = 0;
    field_1D8 = 65535;
    field_290 = -1;
    ResetCornerStatus__11CB3AITargetFv(this);
    field_298 = 0;
    field_29C = 0;
    field_2A0 = 0;
    field_1E4 = 0;
    field_1E8 = 0;
    field_1EC = 0;
    field_1F0 = 1;
    field_1F1 = 0;
    field_1F2 = 1;
    field_291 = 1;
    field_292 = 1;
    field_293 = 1;
    field_294 = 0;
    field_295 = 0;
    field_2A4 = 0;
    field_2A6 = 0;
    field_1F3 = 0;
    field_250.Zero();
    return 1;
}
