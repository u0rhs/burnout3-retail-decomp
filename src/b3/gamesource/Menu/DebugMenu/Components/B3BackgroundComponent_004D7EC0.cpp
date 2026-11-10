// B3BackgroundComponent.cpp's file-scope constants and so its static initializer: retail's func_004D7EC0 (.init, 0x23C),
// its .ctor entry (0x4DD8E4), the file's .rodata block 0x4C5210-0x4C52A0 and its whole .bss (0x1EA3190-0x1EA31C0).
#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

// 0x003713A0, unnamed, not yet decompiled: UVs (u0, v0, u1, v1) of the pixel rect x, y, w, h in a tw x th texture;
// flags bit 0 swaps u0/u1, bit 1 v0/v1 [C]. Returns the CGtV4d through a0 (struct return).
extern "C" CGtV4d _CalculateUV__15CB3MenuImageUVsFffffffUi(int flags, float x, float y, float w, float h, float tw, float th);

// Construction order (= declaration order) as in retail; non-const ones land in .bss, const ones in .rodata. E's
// B3BackgroundComponent.cpp .rodata has kBackgroundBorderTopVignetteUVs, kBackgroundBorderCenterUVs,
// kaBackgroundControlsButtonUVs[3], kBackgroundLoadingControllerUVs, kBackgroundBracketUVs, then the three colours;
// retail's set and placement differ, so placeholders except the colour name retail's tables already carry.
CGtV4d D_01EA3190 = _CalculateUV__15CB3MenuImageUVsFffffffUi(0, 0.0f, 0.0f, 40.0f, 4.0f, 64.0f, 32.0f);
CGtV4d D_01EA31A0 = _CalculateUV__15CB3MenuImageUVsFffffffUi(0, 0.0f, 26.0f, 40.0f, 4.0f, 64.0f, 32.0f);
extern const CGtV4d D_004C5210;
const CGtV4d D_004C5210 = _CalculateUV__15CB3MenuImageUVsFffffffUi(0, 0.0f, 4.0f, 40.0f, 2.0f, 64.0f, 32.0f);
CGtV4d D_01EA31B0 = _CalculateUV__15CB3MenuImageUVsFffffffUi(0, 0.0f, 24.0f, 40.0f, 2.0f, 64.0f, 32.0f);
extern const CGtV4d D_004C5220;
const CGtV4d D_004C5220 = _CalculateUV__15CB3MenuImageUVsFffffffUi(0, 0.0f, 6.0f, 40.0f, 18.0f, 64.0f, 32.0f);
// [L] E's kBackgroundTranparentBorderColourScale / kBackgroundVideoDarkColour by order and value (alpha 0.5; 0.25 grey).
extern const CGtV4d D_004C5230;
extern const CGtV4d kBackgroundBorderColourScale;
extern const CGtV4d D_004C5250;
const CGtV4d D_004C5230(1.0f, 1.0f, 1.0f, 0.5f);
const CGtV4d kBackgroundBorderColourScale(1.0f, 1.0f, 1.0f, 1.0f);
const CGtV4d D_004C5250(0.25f, 0.25f, 0.25f, 1.0f);
extern const CGtV2d kB3DNASImageBackgroundPos;
extern const CGtV2d kB3DNASImageBackgroundHandle;
extern const CGtV2d kB3DNASImageBackgroundSize;
extern const CGtV2d kB3DNASImageTextPos;
extern const CGtV2d kB3DNASImageBTextHandle;
extern const CGtV2d kB3DNASImagePos;
extern const CGtV2d kB3DNASImageHandle;
extern const CGtV2d kB3DNASImageSize;
const CGtV2d kB3DNASImageBackgroundPos(65.0f, 97.0f);
const CGtV2d kB3DNASImageBackgroundHandle(0.0f, 0.0f);
const CGtV2d kB3DNASImageBackgroundSize(512.0f, 192.0f);
const CGtV2d kB3DNASImageTextPos(320.0f, 276.0f);
const CGtV2d kB3DNASImageBTextHandle(0.5f, 0.5f);
const CGtV2d kB3DNASImagePos(320.0f, 176.0f);
const CGtV2d kB3DNASImageHandle(0.5f, 0.5f);
const CGtV2d kB3DNASImageSize(128.0f, 128.0f);
