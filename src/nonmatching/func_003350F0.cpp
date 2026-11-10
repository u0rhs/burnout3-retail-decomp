// NONMATCHING: func_003350F0 -- retail 179 / ours 179 instructions, 6 in changed runs
// 6 off: first arm's ay = &anchor.marValues[1] after the anchor.x store fixes the addiu s1 slot; left: both Interpolates' t lui before the by-ref pointer addiu (const& locals tried) and mov.s f13,f20 two slots late
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_003350F0 -- retail 179 / ours 179 instructions, 8 in changed runs
// near2: 8 off (was 13). In-body asm volatile pextlw dropped (header-style non-volatile helpers max/min/zx); k_t1 declared right after the vfunc_20 call (t in a0 as retail). Left, all single-instruction scheduling: first arm's addiu s1 (ay) one slot early; both Interpolates' t lui scheduled before the by-value pointer addiu (retail after it -- same residual as func_00394280/func_00394660); mov.s f13,f20 two slots late.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.


// NONMATCHING: func_003350F0 -- retail 179 / ours 179 instructions, 42 in changed runs
// v279: 42 off (was 82). Both if/else arms exact (statement order pos.x, ay, size, scale / pos.x, anchor.x, size, scale; &anchor.y as a per-arm float* gives retail's per-arm addiu s1). Interpolate kept compact by volatility (N214: in-body volatile pextlw); clamp asm in the body. Left: register swap v0/v1 in both Interpolate blocks (retail t in v1/a0, b and result in v0) and the result's sq scheduled after the argument setup (retail: sq right after qmfc2)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.


// Hand-written (v273); the lifter refused it.
// func_003350F0 -- the lap HUD's text objects (called from func_00335450, the CB3HUDLap Prepare [L]: lap / total-lap
// digits through func_003824D0, then the second object scaled about its position). Types/fields placeholders [G].
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/classes/UnkStruct_D_0051BA88.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x30];
    CGtV4d field_30;
    unsigned char pad_40[0x20];
    CGtV4d field_60;
};
struct UnkStruct_003350F0_font { unsigned char pad_0[0x10]; float field_10; };
struct UnkStruct_003350F0_car { unsigned char pad_0[0x14]; int field_14; unsigned char pad_18[0x2AC]; int field_2C4; };
struct UnkStruct_003350F0 {
    unsigned char pad_0[0x24];
    CGt2dObject * field_24;
    CGt2dObject * field_28;
    CGt2dObject * field_2C;
    UnkStruct_003350F0_car * field_30;
    int field_34;
    int field_38;
    float field_3C;
    unsigned char pad_40[0x8];
    unsigned short field_48;
    unsigned short field_4A;
    unsigned char pad_4C[0x2];
    unsigned short field_4E;
    unsigned char pad_50[0x2];
    unsigned char field_52;
};
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_003350F0_font * D_00665ED0[4];
extern UnkStruct_D_0051BA88 D_0051BA88;
extern "C" void func_003824D0(CGt2dObject *obj, const CGtV2d &a, const CGtV2d &b, float c, CGtV4d d, CGtV4d e,
                              const unsigned short *text, unsigned char f, float g, float h);

// [L] N185/N188 stand-in for GtMathPs2::Interpolate(CGtV4d, CGtV4d, float): the header body with the moves written .i
// (tools/vu0_ni_fixup.py restores .ni) so b's lq/qmtc2 and the result's qmfc2/sq stay unfolded as in retail.
static inline int func_003350F0_max(int a, int b) { int r; asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline int func_003350F0_min(int a, int b) { int r; asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline unsigned int func_003350F0_zx(int a) { unsigned int r; asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a)); return r; }


// 0x003350F0
extern "C" void func_003350F0(UnkStruct_003350F0 * self)
{
    CGtV2d pos;
    CGtV2d anchor;
    UnkStruct_D_0066A4C0 * const mgr = &D_0066A4C0;
    UnkStruct_003350F0_font * font = D_00665ED0[0];
    unsigned char flags;
    float * ay;
    float size;
    float scale;
    if (self->field_52 != 0) {
        flags = 0x61;
        pos.marValues[1] = self->field_24->mObjectSpace.mTopLeftPos.marValues[1];
        anchor.marValues[0] = 1.0f;
        ay = &anchor.marValues[1];
        pos.marValues[0] = 0.0f;
        *ay = 0.0f;
    } else {
        flags = 0x21;
        pos.marValues[0] = self->field_24->mObjectSpace.mTopLeftPos.marValues[0];
        pos.marValues[1] = 47.0f;
        ay = &anchor.marValues[1];
        *ay = font->field_10;
        anchor.marValues[0] = 0.0f;
    }
    self->field_38 = self->field_30->field_2C4;
    self->field_4A = self->field_38 + 0x30;
    float k_t0 = 0.25f;
    func_003824D0(self->field_28, pos, anchor, 27.0f, GtMathPs2::Interpolate(mgr->field_60, mgr->field_30, k_t0), mgr->field_30,
                  &self->field_48, flags, 1.5f, 3.402823466e+38f);
    if (self->field_52 != 0) {
        pos.marValues[0] = self->field_28->mObjectSpace.mTopLeftPos.marValues[0];
        *ay = 0.06f;
        size = 40.0f;
        scale = 1.5f;
    } else {
        pos.marValues[0] = self->field_28->mObjectSpace.mTopLeftPos.marValues[0] - 5.0f;
        anchor.marValues[0] = 1.0f;
        size = 56.0f;
        scale = 1.5f;
    }
    int n = D_0051BA88.field_0->vfunc_20();
    float k_t1 = 0.75f;
    self->field_34 = func_003350F0_zx(func_003350F0_min(func_003350F0_max(self->field_30->field_14, 0), n - 1));
    self->field_4E = self->field_34 + 0x31;
    func_003824D0(self->field_2C, pos, anchor, size, mgr->field_60, GtMathPs2::Interpolate(mgr->field_60, mgr->field_30, k_t1),
                  &self->field_4E, flags, scale, 3.402823466e+38f);
    float s = 2.5f * self->field_3C;
    CGt2dObject * o = self->field_2C;
    o->mObjectSpace.mTopLeftPos = o->mObjectSpace.mTopLeftPos - o->mObjectSpace.mSize * s;
    self->field_2C->mObjectSpace.mSize = self->field_2C->mObjectSpace.mSize * (1.0f + s);
}




