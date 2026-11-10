// CGt2dFrame -- not yet placed/matched in this repo; declared only as a call target from the
// CB3HeadingComponent methods (Targets #30/#31). Folder: same Gt2d family as CGt2dScene (project
// convention, N10 [L]).
#ifndef B3_GT2DFRAME_H
#define B3_GT2DFRAME_H

#include "b3/GtMathPs2.h"

class CGt2dFrame {
public:
    // E map / retail name: CGt2dFrame::CGt2dFrameSpace. [C] SetIdentity (0x1D5DC0) writes 0x0/0x4 = 0,
    // 0x8/0xC = 1.0f, 0x10 = (1,1,1,1): the same shape as CGt2dObject::CGt2dObjectSpace.
    struct CGt2dFrameSpace {
        GtMathPs2::CGtV2d field_0;   // [L] position (identity 0,0)
        GtMathPs2::CGtV2d field_8;   // [L] scale/extent (identity 1,1)
        GtMathPs2::CGtV4d field_10;  // [L] colour (identity 1,1,1,1)
        void SetIdentity();          // 0x001D5DC0
    };

    CGt2dFrame *ConstructChild();    // 0x001D5D60 [C]: returns the new frame (its free-list link + 8)
    void Destruct();                 // 0x001D5B10 (config/symbol_addrs_b3names.txt); not yet decompiled

    CGt2dFrameSpace field_0;         // [C] ConstructChild and SetIdentity both initialize 0x0-0x1F
    // [L] name and offset: Revenge stabs (types.h CGt2dFrame: mLocalSpace 0x0, mWorldSpace 0x20); [C] retail's _Render tails read
    // the world space at frame+0x20/+0x28/+0x30 (CGt2dObjectTable::RenderBox 0x33DF50).
    CGt2dFrameSpace mWorldSpace;
    // API: E map (research/E_B3O0PCH_symbols.csv: WorldPos() 0x1C, WorldScale() 0x1C, WorldColour() 0x34) [C names]. Return
    // types [L]: Revenge stabs (`CGtV2dArg WorldPos()/WorldScale() const`, `CGtV4dArg WorldColour() const`) with -O0 sizes (N220).
    const GtMathPs2::CGtV2d& WorldPos() const { return mWorldSpace.field_0; }
    const GtMathPs2::CGtV2d& WorldScale() const { return mWorldSpace.field_8; }
    GtMathPs2::CGtV4d WorldColour() const { return GtMathPs2::CGtV4d(mWorldSpace.field_10.mData); }
};

#endif
