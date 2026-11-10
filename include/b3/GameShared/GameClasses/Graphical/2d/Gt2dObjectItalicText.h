// CGt2dObjectItalicText (E map: Gt2dObjectItalicText.cpp). Not yet placed/matched in this repo --
// only its Prepare() signature is needed so far, as an extern call target from
// CB3HSelectComponent::Update() (Target #28). Signature recovered in full from Revenge's stabs
// debug info (research/R_jul14/symtab.csv, map_symbols.csv): retail's own name tables
// (config/symbol_addrs_b3names.txt, research/E_*_symbols.csv) only carry a truncated form.
#ifndef B3_GT2DOBJECTITALICTEXT_H
#define B3_GT2DOBJECTITALICTEXT_H

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

class CGt2dFont;

class CGt2dObjectItalicText : public CGt2dObject {
public:
    // [L] enum name from the mangled signature itself (Revenge symtab.csv); no enumerator names
    // evidenced, only that value 1 is used by one caller so far.
    enum ETextType { };

    // 0x0033D4E0 (one of three near-identical compiled copies in retail, also at 0x33D380/0x33D650),
    // not yet decompiled/verified -- declared only, as a call target.
    void Prepare(const GtMathPs2::CGtV2d&, const GtMathPs2::CGtV2d&, float, GtMathPs2::CGtV4d,
                 const CGt2dFont*, const unsigned short*, const GtMathPs2::CGtV2d&, ETextType);
};

#endif
