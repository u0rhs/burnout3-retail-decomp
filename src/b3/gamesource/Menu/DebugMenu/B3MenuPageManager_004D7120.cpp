// B3MenuPageManager.cpp's file-scope constant and so its static initializer: retail's func_004D7120 (.init, 0x30), its
// .ctor entry (0x4DD8C8) and the constant's .rodata (0x4C4AC0-0x4C4AD0; the file's jump table follows in asm).
#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV4d;

// [L] name: the E-build DNAT map's B3MenuPageManager.cpp .rodata is k255ColourScale (16 bytes) and one jump table, as
// here, and the value is (1/255, 1/255, 1/255, 1); retail's tables don't carry it, so a placeholder.
extern const CGtV4d D_004C4AC0;
const CGtV4d D_004C4AC0(1.0f / 255.0f, 1.0f / 255.0f, 1.0f / 255.0f, 1.0f);
