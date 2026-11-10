// B3HelpBarComponent.cpp's file-scope CGtV2d constants and so its static initializer: the compiler's
// __sinit for these is retail's func_004D7E70 (.init, 0x44 bytes), with its .ctor table entry at 0x4DD8E0 and the
// constants themselves in .rodata at 0x4C51F0-0x4C5208 (zero in the image, filled in at startup).
#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;

// [C] name: E-build DNAT map (B3HelpBarComponent.cpp .rodata). The reciprocal of the help strip's 608x28 design
// size (CB3ScrollingText2dObject::_Render multiplies it by the object's size).
extern const CGtV2d kHelpBarRecipSize;
const CGtV2d kHelpBarRecipSize(1.0f / 608.0f, 1.0f / 28.0f);

// [L] the side prompts' anchors (func_0031BD60: left 0x4C51F8, right 0x4C5200). Retail-only, unnamed; declared
// extern so other units can reference them, as retail's do.
extern const CGtV2d D_004C51F8;
extern const CGtV2d D_004C5200;
const CGtV2d D_004C51F8(0.0f, 0.5f);
const CGtV2d D_004C5200(1.0f, 0.5f);
