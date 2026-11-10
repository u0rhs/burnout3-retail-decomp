#ifndef B3_B3HSELECTCOMPONENT_H
#define B3_B3HSELECTCOMPONENT_H

#include "b3/B3Ptr.h"
#include "b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectItalicText.h"

// [L] one text/data pair per selectable option (Target #28): field_10 indexes an array of these,
// only the first member (the display text) is read so far.
struct UnkStruct_HSelectComponent_10 {
    const unsigned short *text;  // [L]
    int field_4;                  // [L] not yet read by any decompiled method
};
B3_CHECK_SIZE(UnkStruct_HSelectComponent_10, 0x8);

// [L] folder: same Menu/DebugMenu/Components/ area as CB3VListComponent -- the horizontal-select
// counterpart to it (same CB3MenuComponentBase base, same Construct(1) tail-call pattern); no
// literal alienbrain path of its own found yet.
class CB3HSelectComponent : public CB3MenuComponentBase {
public:
    void Construct();      // 0x0031CD90 [C]: decompiled and objdiff-verified (Target #26)
    void Release();         // 0x0031CC90 [C]: decompiled and objdiff-verified (Target #27)
    void Update(float);     // 0x0031CCD0 [C]: decompiled and objdiff-verified (Target #28)

private:
    unsigned short *field_C;                   // [L] points at the "live" current-selection value,
                                                 // re-read and compared every Update() (Target #28)
    UnkStruct_HSelectComponent_10 *field_10;    // [L] array of selectable options, indexed by field_18
    CGt2dObjectItalicText *field_14;            // [C] the on-screen text object (was CGt2dObject*
                                                 // until Target #28 narrowed it)
    int field_18;                               // [L] cached selected index, re-rendered on change
};

#endif
