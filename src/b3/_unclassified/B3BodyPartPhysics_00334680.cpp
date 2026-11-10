// CB3BodyPartPhysics::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3BodyPartPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a235: zero/identity V3d via A211 =j/+j asm macros (as CB3NetworkCar::Prepare), memsets).

#include "b3/GtMathPs2.h"
extern "C" void func_001AD850(void *);
extern "C" void *memset(void *, int, unsigned int);
extern "C" void Initialise__21CB3ConvexHullBodyPartFv(void *);

class CB3BodyPartPhysics {
public:
    void Construct();

    unsigned char pad_0[0x215];
    unsigned char field_215;
    unsigned char pad_216[0xA];
    GtMathPs2::CGtV3d field_220;
    GtMathPs2::CGtV3d field_230;
    GtMathPs2::CGtV3d field_240;
    GtMathPs2::CGtV3d field_250;
    GtMathPs2::CGtV3d field_260;
    unsigned char field_270[0x20];
    unsigned char field_290[0x20];
    int field_2B0;
    int field_2B4;
    unsigned short field_2B8;
    unsigned char field_2BA;
    unsigned char field_2BB;
    unsigned char pad_2BC[4];
    unsigned char field_2C0[0x210];
};

#define A211_ZERO(f) { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); f.mData = r; }
#define A211_IDX(f) { u_long128 r = f.mData; asm("vaddw.x %0, $vf0, $vf0w" : "+j"(r)); f.mData = r; }
#define A211_IDY(f) { u_long128 r = f.mData; asm("vaddw.y %0, $vf0, $vf0w" : "+j"(r)); f.mData = r; }
#define A211_IDZ(f) { u_long128 r = f.mData; asm("vaddw.z %0, $vf0, $vf0w" : "+j"(r)); f.mData = r; }

// 0x00334680
void CB3BodyPartPhysics::Construct()
{
    func_001AD850(this);
    field_215 = 7;
    A211_ZERO(field_220)
    A211_ZERO(field_230)
    A211_ZERO(field_240)
    A211_ZERO(field_250)
    A211_IDX(field_220)
    A211_IDY(field_230)
    A211_IDZ(field_240)
    A211_ZERO(field_260)
    field_2B0 = 0;
    field_2B8 = 0;
    field_2BA = 3;
    field_2B4 = 0;
    field_2BB = 0;
    memset(field_270, 0, 0x20);
    memset(field_290, 0, 0x20);
    memset(field_2C0, 0, 0x210);
    Initialise__21CB3ConvexHullBodyPartFv(field_2C0);
}

