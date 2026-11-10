// Hand-written; the lifter refused it (fresh3: table image cell render (RenderItalicTextNoTruncation tail clone); char name[13] (was [12], one byte short of the 13 written), texture find inline x2 with i declared first, frame count via (unsigned char) static inline).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

using namespace GtMathPs2;
class CGtTexture;

struct UnkStruct_0033F620_4;
struct UnkStruct_0033F620_e0;
struct UnkStruct_D_0051A868 {
    UnkStruct_0033F620_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
struct UnkStruct_0033F620_4 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_0033F620_e0 * field_C;
};
struct UnkStruct_0033F620_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};
struct UnkStruct_0033F620_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};
struct UnkStruct_0033F620_tex {
    unsigned char pad_0[0xA0];
    unsigned char field_A0;
};
struct UnkStruct_0033F620_d {
    unsigned long field_0;
    int field_8;
    unsigned char pad_C[0x4];
    CGtV2d field_10;
    CGtV2d field_18;
};
extern UnkStruct_D_0051A868 D_0051A868;
extern CB3MenuPageManager D_01E90240;
extern char D_004C5C10[];
extern "C" int strcasecmp(const char *, const char *);
extern "C" void func_0021AB40(unsigned long id, char * out);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
#define CGt2dObjectImage_Prepare Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d

static inline CGtV4d func_0033F620_inl2(const CGtV4d &a, const CGtV4d &b)
{
    u_long128 r;
    asm("vmini.xyzw %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV4d(r);
}
static inline UnkStruct_0033F620_tex * func_0033F620_inl1(const char * name)
{
    int i;
    UnkStruct_0033F620_4 * t0 = D_0051A868.field_0;
    for (i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_0033F620_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return (UnkStruct_0033F620_tex *)t2;
        }
    }
    return 0;
}

static inline int func_0033F620_inl3(const UnkStruct_0033F620_tex *t)
{
    return t->field_A0;
}
// 0x0033F620
extern "C" void func_0033F620(const CGtV2d &pos, const CGtV2d &size, unsigned short *text, const CGt2dFrame &frame, const void *data)
{
    CGtV2d q;
    // [C] 13 bytes: func_0021AB40 writes out[0..12] (GtID.cpp: out[12] = 0); char[12] overran by one natively. Retail:
    // name at sp+0x178 (0x33F66C), next slot sp+0x188 (0x33F6B8); 13..15 keep the object byte-identical (tiny_compile +
    // obj_same), char[0x10] moves it to sp+0x110.
    char name[13];
    const UnkStruct_0033F620_d *d = (const UnkStruct_0033F620_d *)data;
    CGt2dObject obj;
    CGt2dObject::CGt2dObjectSpace sp;
    CGtV4d white(1.0f, 1.0f, 1.0f, 1.0f);
    q = pos + size * d->field_10;
    func_0021AB40(d->field_0, name);
    UnkStruct_0033F620_tex *tex = func_0033F620_inl1(name);
    if (tex == 0) tex = func_0033F620_inl1(D_004C5C10);
    unsigned int fr = d->field_8 % (unsigned char)func_0033F620_inl3(tex);
    CGt2dObjectImage_Prepare(&obj, q, d->field_10, d->field_18, D_01E90240.field_110, (CGtTexture *)tex, CGtV2d(0.0f, 0.0f), CGtV2d(1.0f, 1.0f), fr);
    sp = obj.ObjectSpace();
    sp.mTopLeftPos = frame.WorldPos() + frame.WorldScale() * sp.mTopLeftPos;
    sp.mSize = sp.mSize * frame.WorldScale();
    sp.mColour = func_0033F620_inl2(sp.mColour * frame.WorldColour(), white);
    obj.Render(sp);
}
