// NONMATCHING: func_00453980 -- retail 185 / ours 185 instructions, 116 in changed runs
// v275: logic complete (ItalicText pulse render: outline grow 0.2, plain cos fade; lane setters as local CGtV4d::SetX/Y/Z(XAxisType)/SetW(WAxisType) stand-ins; pun ld/ld/lq re-copy [G]); left: retail loads space.mColour for the lanes with its own lqc2 (ours CSEs it with the copy's lq -> VU numbering vf1/vf2 swapped), frame 0x180 vs 0x100 (8 dead slots: lane temps read through their address give +4)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using namespace GtMathPs2;

struct UnkStruct_00453980_fx {
    float field_0;
    float field_4;
};
struct UnkStruct_00453980_data {
    unsigned char pad_0[0xC];
    const UnkStruct_00453980_fx *field_C;
};

extern "C" void _RenderOutline__21CGt2dObjectItalicTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &, const void *);
extern "C" void _RenderPlain__21CGt2dObjectItalicTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &, const void *);

// [L] CGtV4d::SetX/SetY/SetZ(XAxisType), SetW(WAxisType) (B3O0PCH map names); local stand-ins on compiler-chosen registers
static inline void func_00453980_inl2(CGtV4d &v, XAxisType a) { asm("vaddx.x %0, $vf0, %1x" : "+j"(v.mData) : "j"(a.lVector)); }
static inline void func_00453980_inl3(CGtV4d &v, XAxisType a) { asm("vaddx.y %0, $vf0, %1x" : "+j"(v.mData) : "j"(a.lVector)); }
static inline void func_00453980_inl4(CGtV4d &v, XAxisType a) { asm("vaddx.z %0, $vf0, %1x" : "+j"(v.mData) : "j"(a.lVector)); }
static inline void func_00453980_inl5(CGtV4d &v, WAxisType a) { asm("vmulw.w %0, $vf0, %1w" : "+j"(v.mData) : "j"(a.lVector)); }

struct UnkStruct_00453980_raw {
    unsigned long field_0;
    unsigned long field_8;
    u_long128 field_10;
};
static inline void func_00453980_inl1(CGt2dObject::CGt2dObjectSpace &s, const CGt2dObject::CGt2dObjectSpace &space, float t, float k)
{
    s.mSize += s.mSize * t * k;
    s.mTopLeftPos += (space.mSize - s.mSize) * 0.5f;
}

// 0x00453980
extern "C" void func_00453980(const CGt2dObject::CGt2dObjectSpace &space, const void *data)
{
    CGt2dObject::CGt2dObjectSpace s;
    s.mTopLeftPos = space.mTopLeftPos;
    s.mSize = space.mSize;
    s.mColour = space.mColour;
    const UnkStruct_00453980_fx *fx = ((const UnkStruct_00453980_data *)data)->field_C;
    if (fx != 0 && fx->field_4 >= 0.0f) {
        func_00453980_inl1(s, space, fx->field_4, 0.2f);
    }
    _RenderOutline__21CGt2dObjectItalicTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(s, data);
    if (fx == 0) return;
    if (fx->field_0 >= 0.0f) {
        float c = cosf(0.0174532924f * (90.0f * fx->field_0));
        *(UnkStruct_00453980_raw *)&s = *(const UnkStruct_00453980_raw *)&space;
        func_00453980_inl2(s.mColour, space.mColour.X());
        func_00453980_inl3(s.mColour, space.mColour.X());
        func_00453980_inl4(s.mColour, space.mColour.X());
        func_00453980_inl5(s.mColour, space.mColour.W() * c);
        func_00453980_inl1(s, space, fx->field_0, 1.0f);
        _RenderPlain__21CGt2dObjectItalicTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(s, data);
    }
    return;
}
