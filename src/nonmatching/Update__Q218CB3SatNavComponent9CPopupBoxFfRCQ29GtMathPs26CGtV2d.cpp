// NONMATCHING: Update__Q218CB3SatNavComponent9CPopupBoxFfRCQ29GtMathPs26CGtV2d -- retail 201 / ours 201 instructions, 58 in changed runs
// v277: instruction stream identical except stack offsets (201/201, 58 changed = sp offsets only): frame 0x100 vs retail 0x110 -- retail's CGtV2d temp slots are ordered differently and it has 5 empty 8-byte slots (0xB8, 0xC0, 0xE0-0xF0). Two-statement SetA stand-in (qmtc2 then vmulx.w) reproduces retail's early qmtc2; the qmfc2/sq reuse for field_8 comes out naturally
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

// CB3Panel2dObject::Prepare(const CGtV2d&, const CGtV2d&, const CGtV2d&, unsigned int, float), by its link name
// (as func_003792C0.cpp).
extern "C" void Prepare__16CB3Panel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUif(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, unsigned int flags, float f);

// [C] D_01E88D18 holds a pointer to an offset/scale pair (lwc1 0/4 added, 8/0xC multiplied).
struct UnkStruct_003B14C0_xf {
    CGtV2d field_0;
    CGtV2d field_8;
};
struct UnkStruct_D_01E88D18 {
    UnkStruct_003B14C0_xf *field_0;
    unsigned char pad_4[0x20];
};
extern UnkStruct_D_01E88D18 D_01E88D18;
// [C] rodata CGtV2d offsets (0.0f pairs) added to the panel position for the two text objects.
struct UnkStruct_D_004C9FD0 {
    CGtV2d field_0;
    unsigned char pad_8[0x8];
};
extern const UnkStruct_D_004C9FD0 D_004C9FD0;
extern const UnkStruct_D_004C9FD0 D_004C9FD8;
// [L] D_01E90240 + 0x10 (CB3MenuPageManager::field_0[1], a colour).
struct UnkStruct_D_01E90250 {
    CGtV4d field_0;
};
extern UnkStruct_D_01E90250 D_01E90250;

// [L] N185: stands in for a missing GtMathPs2 inline -- CGtV4d::SetA's lane write with the qmtc2 as its own
// statement (retail moves the alpha into $vf2 well before the colour's lqc2, then vmulx.w).
static inline void func_003B14C0_inl1(CGtV4d &v, float a)
{
    asm("qmtc2.ni %0, $vf2" : : "r"(a));
    asm("vmulx.w %0, $vf0, $vf2x" : "+j"(v.mData));
}

class CB3SatNavComponent {
public:
    class CPopupBox {
    public:
        void Update(float, const CGtV2d &);

        CGt2dObject *field_0;  // [C] the panel (CB3Panel2dObject::Prepare)
        CGt2dObject *field_4;  // [C] placed at the panel position, alpha-faded
        CGt2dObject *field_8;  // [C] optional second object, same treatment
        signed char field_C;   // [C] side: < 0 picks it from the screen half
    };
};

// 0x003B14C0
void CB3SatNavComponent::CPopupBox::Update(float t, const CGtV2d &pos)
{
    CGtV2d size;
    CGtV2d p;
    CGtV2d q;
    if (field_0 == 0)
        return;
    float k;
    float a;
    if (t < 0.3f) {
        k = 3.33333325f * t;
        a = 0.0f;
    } else {
        a = 1.42857146f * (t - 0.3f);
        k = 1.0f;
    }
    UnkStruct_003B14C0_xf *xf = D_01E88D18.field_0;
    p = pos * xf->field_8 + xf->field_0;
    float side;
    if (field_C < 0) {
        if (p.marValues[0] > 320.0f)
            side = 1.0f;
        else
            side = 0.0f;
    } else {
        side = (float)field_C;
    }
    if (side > 0.0f)
        q = p + CGtV2d(-5.0f, 5.0f);
    else
        q = p + CGtV2d(5.0f, 5.0f);
    CGtV2d from;
    CGtV2d to;
    if (field_8 != 0) {
        float w4 = field_4->mObjectSpace.mSize.marValues[0];
        float w8 = field_8->mObjectSpace.mSize.marValues[0];
        float w = 20.0f + GtMath::Max(w4, w8);
        from.Set(w, 2.0f);
        to.Set(w, 50.0f);
    } else {
        float w = 20.0f + field_4->mObjectSpace.mSize.marValues[0];
        from.Set(w, 2.0f);
        to.Set(w, 30.0f);
    }
    size = from + (to - from) * k;
    Prepare__16CB3Panel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUif(
        field_0, q, CGtV2d(side, 0.0f), size, 0x31, 8.0f);
    field_4->mObjectSpace.mTopLeftPos = field_0->mObjectSpace.mTopLeftPos + D_004C9FD0.field_0;
    CGtV4d c;
    c = D_01E90250.field_0;
    func_003B14C0_inl1(c, a);
    field_4->mObjectSpace.mColour = c;
    if (field_8 != 0) {
        field_8->mObjectSpace.mTopLeftPos = field_0->mObjectSpace.mTopLeftPos + D_004C9FD8.field_0;
        field_8->mObjectSpace.mColour = c;
    }
}

