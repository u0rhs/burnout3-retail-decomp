// Hand-written; the lifter refused it (a220: o=*slot local before white; d from o; params in natural s-reg order).

#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
using namespace GtMathPs2;
struct UnkStruct_004589B0_d { int field_0; int field_4; int field_8; unsigned char field_C; unsigned char field_D; };
static inline CGtV2d inl1(const CGtV2d &a, const CGtV2d &b) { return a - b; }
extern "C" void func_00458AE0(void *, const void *);
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, const void *, unsigned int, unsigned int);

// 0x004589B0
extern "C" void func_004589B0(CGt2dObject ** slot, const CGtV2d & pos, const CGtV2d & anchor, const CGtV2d & size, int p0, int p1,
                              CGt2dScene * scene, int id, CGt2dFrame * frame)
{
    *slot = scene->ConstructObject(id, frame);
    CGt2dObject * o = *slot;
    UnkStruct_004589B0_d * d = (UnkStruct_004589B0_d *)((char *)o + 0x20);
    CGtV4d white(1.0f, 1.0f, 1.0f, 1.0f);
    CGtV2d tp = inl1(pos, anchor * size);
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(o, tp, size, white, (const void *)&func_00458AE0, 64, 16);
    d->field_0 = p0;
    d->field_4 = p1;
    d->field_8 = 0;
    d->field_C = 0;
    d->field_D = 0;
}
