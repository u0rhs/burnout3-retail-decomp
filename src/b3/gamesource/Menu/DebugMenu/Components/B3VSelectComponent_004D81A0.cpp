// B3VSelectComponent.cpp's file-scope constants and so its static initializer: retail's func_004D81A0 (.init, 0x2C), its
// .ctor entry (0x4DD8EC) and their .rodata (0x4C5388-0x4C5394).
#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;

// [L] E-build DNAT map, B3VSelectComponent.cpp .rodata: krVSelectOutlineOffset (8 bytes), krVSelectRightBarGapX (4 bytes),
// the same sizes and order as these two; kept as placeholders (no retail table carries the names).
extern const CGtV2d D_004C5388;
extern const float D_004C5390;
const CGtV2d D_004C5388(4.0f, 4.0f);
// [C] runtime sum, literal first in retail's add.s (the stored 4.0 is reused, not reloaded). [G] the literal's spelling:
// retail's pool value is 0x412CCCCC (10.79999924), one unit below 10.8f; 10.799999f rounds to exactly that.
const float D_004C5390 = 10.799999f + D_004C5388.marValues[0];
