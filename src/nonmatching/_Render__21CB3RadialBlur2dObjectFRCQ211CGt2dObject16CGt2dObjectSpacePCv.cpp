// NONMATCHING: _Render__21CB3RadialBlur2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 58 / ours 58 instructions, 17 in changed runs
// near24: kRadialBlurCenter is 8-byte .rodata -> extern const (23->17); left: retail loads p0+0..0x10 all before the first store and centre.y after them; ours interleaves
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// a236: logic exact (lifter draft + CB3GraphicsManager : CB3GraphicsManagerBase fix); left: load scheduling/regs: retail loads kRadialBlurCenter.x first then its .y via a separate lui after p0 loads; li 1 early
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

enum EB3ViewportSelection {};

class CB3GraphicsManager;
class CB3GraphicsManagerBase;
class CB3RadialBlur2dObject;
class CB3RadialBlur;
struct UnkStruct_D_00666274;
struct UnkStruct_D_00667050;
struct UnkStruct_kRadialBlurCenter;

class CB3GraphicsManagerBase {
public:
    void CloseViewport();
};
class CB3GraphicsManager : public CB3GraphicsManagerBase {
public:
    void BuildCustomCameraData(int);
    void OpenViewport(EB3ViewportSelection);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3RadialBlur {
public:
    void Render();

    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    GtMathPs2::CGtV3d field_20;
    unsigned char field_30;
};


struct UnkStruct_D_00666274 {
    CB3RadialBlur * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_kRadialBlurCenter {
    float field_0;
    float field_4;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00667050 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3RadialBlur2dObject {
public:
    void _Render(const CGt2dObject::CGt2dObjectSpace& p0, const void* p1);
};

extern UnkStruct_D_00666274 D_00666274;
struct UnkStruct_kRadialBlurCenter_b { float field_0; float field_4; };
extern const UnkStruct_kRadialBlurCenter_b kRadialBlurCenter;
extern UnkStruct_D_00667050 D_00667050;
extern CB3GraphicsManager D_00665EC0;

extern "C" void Suspend__12Gt2dRendererFv(void *);  // Gt2dRenderer::Suspend()


// 0x003D2FD0
void CB3RadialBlur2dObject::_Render(const CGt2dObject::CGt2dObjectSpace& p0, const void* p1)
{
    CB3RadialBlur * t0 = D_00666274.field_0;
    Suspend__12Gt2dRendererFv(this);
    D_00665EC0.BuildCustomCameraData(-1);
    D_00667050.field_0 = 0;
    t0->field_0 = kRadialBlurCenter.field_0;
    t0->field_4 = kRadialBlurCenter.field_4;
    t0->field_8 = p0.mTopLeftPos.marValues[0];
    t0->field_C = p0.mTopLeftPos.marValues[1];
    t0->field_10 = p0.mSize.marValues[0];
    t0->field_14 = p0.mSize.marValues[1];
    t0->field_18 = p0.mColour.f[0];
    t0->field_1C = p0.mColour.f[1];
    t0->field_30 = 1;
    t0->field_20.SetX(0.0f);
    t0->field_20.SetY(0.0f);
    t0->field_20.SetZ(0.0f);
    t0->field_30 = 1;
    t0->Render();
    D_00665EC0.CloseViewport();
    D_00665EC0.OpenViewport((EB3ViewportSelection)0);
    Gt2dRenderer::Resume();
}
