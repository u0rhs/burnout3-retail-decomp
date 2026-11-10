// B3PromptsComponent.cpp's file-scope constants and so its static initializer: retail's func_004D8100 (.init, 0x98),
// its .ctor entry (0x4DD8E8), and the file's .rodata block 0x4C52D8-0x4C5368 (the CGtV2d constants are zero in the
// image, filled in at startup; the two tables between them are plain data).
#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;

// Names: the E map's B3PromptsComponent.cpp .rodata has kOpenLobbyKeyboardPos (8 bytes, first), karPromptButtonXHandles
// (24 bytes), kLobbyTalkPos, kPostTalkPos, kSwitchTeamsPos; retail's block is larger (a 48-byte float table, a new
// 48-byte int table, five positions), so no one-to-one mapping -- placeholders.
extern const CGtV2d D_004C52D8;
const CGtV2d D_004C52D8(41.25f, 400.0f);
// [L] per-button x anchors (func_0031FB10 indexes it by its button argument when its x argument is negative; the
// inlined copy in func_0031F970 reads element 3) -- E's karPromptButtonXHandles grown from 6 to 12 entries [G].
extern const float D_004C52E0[12];
const float D_004C52E0[12] = {0.0f, 1.0f, 0.84f, 0.75f, 0.25f, 0.0f, 0.24f, 0.24f, 0.0f, 0.17f, 0.8f, 0.0f};
extern const int D_004C5310[12];
const int D_004C5310[12] = {5, 8, 0, 9, 6, 7, 4, 3, 10, 2, 1, 0};
extern const CGtV2d D_004C5340;
extern const CGtV2d D_004C5348;
extern const CGtV2d D_004C5350;
extern const CGtV2d D_004C5358;
extern const CGtV2d D_004C5360;
const CGtV2d D_004C5340(496.0f, 447.5f);
const CGtV2d D_004C5348(64.0f, 368.0f);
const CGtV2d D_004C5350(588.0f, 104.0f);
const CGtV2d D_004C5358(280.5f, 447.5f);
const CGtV2d D_004C5360(595, 104.0f);
