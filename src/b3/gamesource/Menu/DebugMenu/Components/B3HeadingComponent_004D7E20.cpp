// B3HeadingComponent.cpp's file-scope constants and so its static initializer: retail's func_004D7E20 (.init, 0x44), its
// .ctor entry (0x4DD8DC) and the two constants' .rodata (0x4C5170-0x4C5190; the file's two jump tables follow in asm).
#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

// [C] names and order: E-build DNAT map (B3HeadingComponent.cpp .rodata: krHeadingBarBigCurveEffectiveImageSize 8 bytes,
// kHeadingTextBarFillColourScale 16 bytes, then two jump tables) and retail's tables (config/symbol_addrs_b3names.txt).
extern const CGtV2d krHeadingBarBigCurveEffectiveImageSize;
extern const CGtV4d kHeadingTextBarFillColourScale;
const CGtV2d krHeadingBarBigCurveEffectiveImageSize(136.0f, 176.0f);
const CGtV4d kHeadingTextBarFillColourScale(1.0f, 1.0f, 1.0f, 0.5f);
