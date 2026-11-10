// DRAFT -- NOT MATCHING, NOT WIRED IN (retail's asm is still linked: sinit_004D7150.s). 55/57 instructions, frame 0x30 right; the
// three drop offsets are stored from propagated constants where retail copies each stack temporary (docs/known.md N108).
// B3MenuComponentBase.cpp's file-scope constants and so its static initializer: retail's func_004D7D30 (.init, 0xEC),
// its .ctor entry (0x4DD8D8) and their .rodata (0x4C50F0-0x4C5170).
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectText.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

// [L] names: the E-build DNAT map's B3MenuComponentBase.cpp .rodata is kDropShadowColour (16 bytes), kMenuODSOutlineOffset
// (8), kMenuOutlineDropShadowSmall/Medium/Large (32 each) -- the same sizes in the same order as these five; retail's
// tables don't carry them, so placeholders.
extern const CGtV4d D_004C50F0;
extern const CGtV2d D_004C5100;
extern const CGt2dObjectText::COutlineDropShadow D_004C5110;
extern const CGt2dObjectText::COutlineDropShadow D_004C5130;
extern const CGt2dObjectText::COutlineDropShadow D_004C5150;
const CGtV4d D_004C50F0(0.0f, 0.0f, 0.0f, 0.25f);
const CGtV2d D_004C5100(1.2f, 1.2f);
const CGt2dObjectText::COutlineDropShadow D_004C5110(D_004C50F0, CGtV2d(2.2f, 2.2f), D_004C5100);
const CGt2dObjectText::COutlineDropShadow D_004C5130(D_004C50F0, CGtV2d(3.0f, 3.0f), D_004C5100);
const CGt2dObjectText::COutlineDropShadow D_004C5150(D_004C50F0, CGtV2d(4.0f, 4.0f), D_004C5100);
