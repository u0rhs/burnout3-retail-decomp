#include "b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

using GtMathPs2::CGtV2d;

extern CGt2dScene D_01E903E0;  // unnamed global, no evidence of its real name yet

// [C] class and method name: E-build DNAT map (B3RoundedPanel2dObject.cpp, Prepare(const CGtV2d&, const CGtV2d&,
// const CGtV2d&, unsigned int)); only declared here, as a call target (0x3A2850's caller-facing name). Retail's takes one
// more argument (t1, stored at +0x2C) [C]; its type is [G]. The mangled name this produces is aliased to the table's
// label in config/undefined_syms_manual.txt (N110).
class CB3RoundedPanel2dObject : public CGt2dObject {
public:
    void Prepare(const CGtV2d &a, const CGtV2d &b, const CGtV2d &c, unsigned int flags, unsigned int extra);
};

// 0x00320E20
void func_00320E20(CB3VSelectComponent *self, const CGtV2d &a, const CGtV2d &b, const CGtV2d &c)
{
    CGt2dScene *scene = &D_01E903E0;
    // Read up front (retail loads it before the test, with the scene address); inline in the call it is loaded in the
    // construct block and the scene address rematerialised there.
    int layer = self->field_8;
    if (self->field_60 == 0)
        self->field_60 = scene->ConstructObject(layer, self->field_A8);
    ((CB3RoundedPanel2dObject *)self->field_60)->Prepare(a, b, c, 0x1F, 0);
}
