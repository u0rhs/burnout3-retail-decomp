// CGt2dObject and its simple kinds (E map: Gt2dObject.cpp, Gt2dObjectBox.cpp, Gt2dObjectImage.cpp).
// Header name and folder: project convention (K18/K19: Criterion's header names are not known).
// Layout from retail code only (docs/hud2d.md Phase 2, K24); Burnout 2's C2dObject does not carry over.
// Members without a recovered name are field_XX; meanings in comments are [L]/[G] unless marked [C].
#ifndef B3_GT2DOBJECT_H
#define B3_GT2DOBJECT_H

#include "b3/B3Ptr.h"
#include "b3/GtMathPs2.h"

class CGtTexture;
class CGt2dFrame;

// Gt2dRendererPS2.cpp's sprite calls (namespace or static class: the mangled names have no 'this' [G namespace]).
namespace Gt2dRenderer {
void RenderSpritesUntex(GtMathPs2::CGtV4d, const GtMathPs2::CGtV2d&, int, const GtMathPs2::CGtV2d*);
void RenderSpritesTex(GtMathPs2::CGtV4d, const GtMathPs2::CGtV2d&, int, const GtMathPs2::CGtV2d*,
                      const GtMathPs2::CGtV2d*);
void SetTexture(CGtTexture*);
void SetTexture(CGtTexture*, int);
// Triangle strips (full mangled names: config/symbol_addrs.txt). Argument meanings [L]: colour (or a per-vertex
// colour array), an offset added to every vertex, the vertex count, positions, UVs.
void RenderTriStripFlatTex(GtMathPs2::CGtV4d, const GtMathPs2::CGtV2d&, int, const GtMathPs2::CGtV2d*,
                           const GtMathPs2::CGtV2d*);                                                   // 0x218D00
void RenderTriStripFlatUntex(GtMathPs2::CGtV4d, const GtMathPs2::CGtV2d&, int, const GtMathPs2::CGtV2d*);
void RenderTriStripGouraudUntex(const GtMathPs2::CGtV2d&, int, const GtMathPs2::CGtV2d*, const GtMathPs2::CGtV4d*);
// gapN (2026-11-01): [C] names and signatures: B3O0PCH map (Gt2dRenderer::SetTextureAddressMode 0x2220A0, RenderTriStripGouraudTex
// 0x220E90, RenderTriListFlatTex 0x220310; Gt2dRendererPS2.c); enumerators unknown (placeholder enum, docs/conventions.md).
enum EGt2dRendererTexAddress { };
void SetTextureAddressMode(EGt2dRendererTexAddress);
void RenderTriStripGouraudTex(const GtMathPs2::CGtV2d&, int, const GtMathPs2::CGtV2d*, const GtMathPs2::CGtV2d*, const GtMathPs2::CGtV4d*);
void RenderTriListFlatTex(GtMathPs2::CGtV4d, const GtMathPs2::CGtV2d&, int, const GtMathPs2::CGtV2d*, const GtMathPs2::CGtV2d*);
// gapO (2026-11-01): [C] names and signatures: B3O0PCH map (Gt2dRenderer::Begin() 0x21EDD0, End() 0x21F000, Suspend() 0x21F420,
// Resume() 0x21F620, SetZ(float,float,float) 0x222500, EnableZTest(bool) 0x222590); return types void [L] (callers ignore v0).
void Begin();
void End();
void Suspend();
void Resume();
void SetZ(float, float, float);
void EnableZTest(bool);
}

class CGt2dObject {
public:
    // E map: CGt2dObject::CGt2dObjectSpace. [C] _Render's first argument: +0x0 and +0x8 corner/extent pairs, +0x10
    // the colour (CGt2dObjectBox::_Render, CGt2dObjectImage::_Render) - the same shape as the object's first 0x20 bytes.
    // Member names: [L] Burnout Revenge prototype stabs (research/burnout3-symbols/.../SLUS_212.42/types.h),
    // whose CGt2dObject layout matches retail's (N8).
    struct CGt2dObjectSpace {
        GtMathPs2::CGtV2d mTopLeftPos;
        GtMathPs2::CGtV2d mSize;
        GtMathPs2::CGtV4d mColour;
    };

    // The render callback every kind installs: E map `_Render(const CGt2dObject::CGt2dObjectSpace&, const void*)`
    // (same parameter list in every kind's mangled name [C]); the second argument is probably the kind's data block at
    // +0x20 [L]. Type name is ours.
    B3_FNPTR(UnkFn_RenderCallback, void, (const CGt2dObjectSpace&, const void*));

    // [C] name: config/symbol_addrs_b3names.txt (0x66EB20, size 0x1000). Scratch vertex data the _Render
    // callbacks fill before a Gt2dRenderer strip call (CB3RotatingImage2dObject/CHeadingBar2dObject).
    static unsigned char mgu8RenderBatchData[0x1000];

    void SetPos(const GtMathPs2::CGtV2d&, const GtMathPs2::CGtV2d&);  // 0x1D5E00
    // 0x1D5E70; full mangled name from the raw map (H9): the two unsigned ints are not used by this body.
    void Prepare(const GtMathPs2::CGtV2d&, const GtMathPs2::CGtV2d&, const GtMathPs2::CGtV4d, UnkFn_RenderCallback,
                 unsigned int, unsigned int);

    // Member names: [L] Revenge stabs (as above). mObjectSpace: [C] position written by Prepare a1 and by SetPos
    // (= a1 - mSize * a2), size by Prepare a2, colour by one 128-bit store in Prepare.
    // API: E map (research/E_B3O0PCH_symbols.csv: ObjectSpace() 0x18, Pos() 0x18, Size() 0x1C, Colour() 0x34,
    // Render(const CGt2dObjectSpace&) 0x50) [C names]. Return types [L]: Revenge stabs (types.h `CGt2dObjectSpace & ObjectSpace()
    // const`, `CGtV2dArg Pos()/Size() const`, `CGtV4dArg Colour() const`, `void Render(const CGt2dObjectSpace &) const`); the
    // CGtV2dArg = const CGtV2d& / CGtV4dArg = CGtV4d reading and the bodies from -O0 size calibration against the map (N220).
    CGt2dObjectSpace& ObjectSpace() const { return (CGt2dObjectSpace&)mObjectSpace; }
    const GtMathPs2::CGtV2d& Pos() const { return mObjectSpace.mTopLeftPos; }
    const GtMathPs2::CGtV2d& Size() const { return mObjectSpace.mSize; }
    GtMathPs2::CGtV4d Colour() const { return GtMathPs2::CGtV4d(mObjectSpace.mColour.mData); }
    void Render(const CGt2dObjectSpace& s) const { mpfRender(s, mauDataBlock); }
    CGt2dObjectSpace mObjectSpace;
    unsigned int mauDataBlock[6];          // [C] per-kind data (CGt2dObjectImage: UVs, texture)
    B3_PTR(CGt2dFrame) mpFrame;            // [C] CGt2dScene::ConstructObject(int, CGt2dFrame*) stores the frame here
    UnkFn_RenderCallback mpfRender;        // [C] Prepare stores the callback (CGt2dObjectBox passes its _Render)
    // Prepare's two unsigned ints (not stored): box passes (0x40, 0), image (0x40, 0x18 = its data block's size) [L]
    // size not known yet (>= 0x40); objects live 8 bytes after their CGtFreeList link (CGt2dScene::ConstructObject)
};
B3_CHECK_OFFSET(CGt2dObject, mObjectSpace, 0x0);
B3_CHECK_OFFSET(CGt2dObject, mauDataBlock, 0x20);
B3_CHECK_OFFSET(CGt2dObject, mpFrame, 0x38);
B3_CHECK_OFFSET(CGt2dObject, mpfRender, 0x3C);

class CGt2dObjectBox : public CGt2dObject {   // no members of its own seen
public:
    static void _Render(const CGt2dObject::CGt2dObjectSpace&, const void*);                       // 0x1D5EA0
    void Prepare(const GtMathPs2::CGtV2d&, const GtMathPs2::CGtV2d&, const GtMathPs2::CGtV2d&,
                 const GtMathPs2::CGtV4d);                                                                   // 0x1D5F20
};

// CGt2dObjectImage's data block, at CGt2dObject +0x20 (type name: placeholder, offset-based).
struct UnkStruct_Gt2dObject_20 {
    GtMathPs2::CGtV2d field_0;             // [C] SetUVs a1 (+0x20): top-left UV [L]
    GtMathPs2::CGtV2d field_8;             // [C] SetUVs a2 (+0x28): bottom-right UV [L]
    B3_PTR(CGtTexture) field_10;           // [C] SetTexture a1 (+0x30)
    unsigned int field_14;                 // [C] SetTexture a2 (+0x34), although the E signature has one parameter (B13)
};
B3_CHECK_SIZE(UnkStruct_Gt2dObject_20, 0x18);

class CGt2dObjectImage : public CGt2dObject {
public:
    UnkStruct_Gt2dObject_20& Data() { return *(UnkStruct_Gt2dObject_20*)mauDataBlock; }   // accessor: project convention
    static void _Render(const CGt2dObject::CGt2dObjectSpace&, const void*);                       // 0x1D5FB0
    void SetTexture(CGtTexture*);                                                                      // 0x1D6070
    void SetUVs(const GtMathPs2::CGtV2d&, const GtMathPs2::CGtV2d&);                                   // 0x1D6080
    // Retail's body also reads an 8th, stack-passed argument into +0x34 (docs/known.md N68); retail callers
    // pass it, so B3HeadingComponent_00319E80.cpp calls this through its link name with that argument.
    void Prepare(const GtMathPs2::CGtV2d&, const GtMathPs2::CGtV2d&, const GtMathPs2::CGtV2d&,
                 const GtMathPs2::CGtV4d, CGtTexture*, const GtMathPs2::CGtV2d&, const GtMathPs2::CGtV2d&);  // 0x1D60B0 (full name: raw map)
};

#endif
