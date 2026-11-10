// CB3ScrapeRenderer::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScrapeRenderPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (re-queue: static member spelled mRandom__17CB3ScrapeRenderer (the evidenced mangled name); the earlier queue failed to link on _mRandom).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV4d;
struct UnkStruct_ScrapeParams {
    CGtV4d field_0;
    CGtV4d field_10;
    unsigned char pad_20[0x14];
    float field_34;
    float field_38;
    float field_3C;
};
struct UnkStruct_ScrapeDerived {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[4];
    CGtV4d field_10;
    CGtV4d field_20;
};
struct UnkStruct_rnd { int field_0; int field_4; };
extern UnkStruct_ScrapeParams D_01EA4910;
extern UnkStruct_ScrapeDerived D_01EA4950;
extern "C" UnkStruct_rnd mRandom__17CB3ScrapeRenderer;
// a186 TEST ONLY: missing header API CGtV4d::operator-(const CGtV4d&) (vsub.xyzw), written as asm to test the rest
static inline CGtV4d V4Sub(const CGtV4d &a, const CGtV4d &b) {
    u_long128 t;
    asm("vsub.xyzw %0, %2, %1" : "=j"(t) : "j"(b.mData), "j"(a.mData));
    return CGtV4d(t);
}
class CB3ScrapeRenderer {
public:
    static void Construct();
};
// 0x00376290
void CB3ScrapeRenderer::Construct()
{
    UnkStruct_ScrapeParams *p = (UnkStruct_ScrapeParams *)((unsigned int)&D_01EA4910 | 0x30000000);
    UnkStruct_ScrapeDerived *o = (UnkStruct_ScrapeDerived *)((unsigned int)&D_01EA4950 | 0x30000000);
    o->field_0 = p->field_34 / 2.0f;
    o->field_4 = (p->field_38 - p->field_34) / p->field_3C / 2.0f;
    o->field_8 = 1.0f / p->field_3C;
    o->field_10 = p->field_0;
    o->field_20 = V4Sub(p->field_10, p->field_0);
    mRandom__17CB3ScrapeRenderer.field_4 = 0x2B9D6F8;
    mRandom__17CB3ScrapeRenderer.field_0 = 0xFD462907;
}
