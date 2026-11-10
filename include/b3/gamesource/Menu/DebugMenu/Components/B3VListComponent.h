#ifndef B3_B3VLISTCOMPONENT_H
#define B3_B3VLISTCOMPONENT_H

#include "b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

// [L] folder: inherited from CB3MenuComponentBase (Construct/Release both tail-call it directly),
// whose own folder is literally confirmed -- same Menu/DebugMenu/Components/ area.
class CB3VListComponent : public CB3MenuComponentBase {
public:
    void Construct();    // 0x0032B2B0 [C]: decompiled and objdiff-verified (Target #20)
    void Release();        // 0x0032B200 [C]: decompiled and objdiff-verified (Target #22)
    void Update(float);    // 0x0032B290 [C]: decompiled and objdiff-verified (Target #23)

private:
    // field_C sits immediately after CB3MenuComponentBase's own 0xC-byte layout (N50/N52): no
    // padding needed here -- the earlier pad0[0x8]/field_8/pad_A[2] trio was compensating for an
    // under-sized base class definition from before the base's own fields were carved out (Target
    // #21/#22), not real bytes of this class.
    int field_C;               // element count
    int field_10;
    CGt2dObject *elements[1];  // flexible array at offset 0x14, real length = field_C
};

#endif
