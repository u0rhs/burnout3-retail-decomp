// NONMATCHING: func_00372400 -- retail 56 / ours 56 instructions, 6 in changed runs
// 56/56 instrs, 6 changed, scheduling only: retail stores f12 (sz.x) at 0x58(sp) before the lwc1 a1/a2 loads and lq a3 one slot later; variants tried: sz set/ctor/order, c2 copy, ey local. SelectionBar2dObject::Prepare(pos,anchor,size,f,f,colour); no DNAT row
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
using namespace GtMathPs2;
struct UnkStruct_SB_data {
    CGtV2d field_0;
    float field_8;
    float field_C;
};
class CB3SelectionBar2dObject : public CGt2dObject {};
extern const CGtV2d kSelectionBarEndSize;
extern "C" void _Render__23CB3SelectionBar2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv(void *, void *);
extern "C" void func_00372400(CB3SelectionBar2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, float size, float p2, float p3, CGtV4d colour)
{
    UnkStruct_SB_data *d = (UnkStruct_SB_data *)self->mauDataBlock;
    CGtV2d sz(size, kSelectionBarEndSize.Y());
    d->field_0 = CGtV2d(1.0f, 1.0f) / sz;
    d->field_8 = p2;
    d->field_C = p3;
    self->CGt2dObject::Prepare(pos - sz * anchor, sz, colour, (CGt2dObject::UnkFn_RenderCallback)_Render__23CB3SelectionBar2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv, 0x40, 0x10);
}
