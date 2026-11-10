// CGt2dObjectText (E map: Gt2dObjectText.cpp). Not yet placed/matched in this repo -- only Prepare() is declared, as
// an extern call target (CB3PromptsComponent's func_0031F5E0).
#ifndef B3_GT2DOBJECTTEXT_H
#define B3_GT2DOBJECTTEXT_H

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GtMathPs2.h"

class CGt2dFont;

class CGt2dObjectText : public CGt2dObject {
public:
    // [C] class name: E-build maps (CGt2dObjectText::COutlineDropShadow::COutlineDropShadow(), operator=). [L] layout and
    // member names: Burnout Revenge prototype stabs (types.h, size 0x20). The three-value constructor is [G]: no map
    // has it (inlined wherever used); shaped to retail's static initializer func_004D7D30 (still a draft, N108).
    class COutlineDropShadow {
    public:
        COutlineDropShadow() {}
        // [G] the closest shape found (N108): retail's frame and temporaries, but MWCC propagates the drop offsets'
        // constants where retail copies each temporary with one ld/sd.
        COutlineDropShadow(const GtMathPs2::CGtV4d &colour, const GtMathPs2::CGtV2d &dropShadowOffset,
                           const GtMathPs2::CGtV2d &outlineOffset)
        {
            mDropShadowColour = colour;
            mDropShadowOffset = dropShadowOffset;
            mOutlineOffset.marValues[0] = outlineOffset.marValues[0];
            mOutlineOffset.marValues[1] = outlineOffset.marValues[1];
        }
        GtMathPs2::CGtV4d mDropShadowColour;
        GtMathPs2::CGtV2d mDropShadowOffset;
        GtMathPs2::CGtV2d mOutlineOffset;
    };

    // 0x001D6C40, not yet decompiled. [C] name and first five parameters: config/symbol_addrs_b3names.txt ("[high]",
    // truncated after "const unsig"); [L] the sixth, const unsigned short*: the truncation, and func_0031F5E0 passes
    // a CB3Strings::GetString result in t1 and nothing after it.
    void Prepare(const GtMathPs2::CGtV2d &pos, const GtMathPs2::CGtV2d &anchor, float size, GtMathPs2::CGtV4d colour,
                 const CGt2dFont *font, const unsigned short *text);
};

#endif
