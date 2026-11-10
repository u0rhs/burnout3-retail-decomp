// func_0031BD60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (hdr12: exact with the N224 Interpolate(CGtV4d) + call-site float t).

// DRAFT -- NOT MATCHING, NOT WIRED IN (retail's asm is still linked: game/unit_0031B860.s). func_0031BD60, see
// docs/known.md N94.
#include "b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

// [L] a colour table (two of its CGtV4d entries are blended for the prompt text). Padded for N51.
struct UnkStruct_D_0066A4C0 {
    unsigned char pad0[0x30];
    CGtV4d field_30;
    unsigned char pad40[0x20];
    CGtV4d field_60;
    unsigned char pad70[0x100];
};
extern UnkStruct_D_0066A4C0 D_0066A4C0;

// [L] a running time (stored as each prompt's start time, compared against in Update). Padded for N51.
struct UnkStruct_D_004F50A0 {
    float value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_004F50A0 D_004F50A0;

// Same object as B3HeadingComponent_00319A90.cpp's. Padded for N51.
struct UnkStruct_D_01E7A800 {
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E7A800 D_01E7A800;

// [C] class and method name: retail name table (0x289320). Padded for N51.
class CB3SoundGameModeManager {
public:
    void TriggerSpotDucker(float);
    unsigned char pad[0x100];
};
extern CB3SoundGameModeManager D_01E77540;

// [L] file-scope CGtV2d constants of this file (.rodata, filled in by its static initializer): the prompt
// anchors for the left and right side. Retail-only; unnamed.
extern const CGtV2d D_004C51F8;
extern const CGtV2d D_004C5200;

extern "C" void func_003B8840(const unsigned short *text);
extern "C" void func_002859F0(UnkStruct_D_01E7A800 *p);
// Same declaration as B3HeadingComponent_00319490.cpp.
extern "C" void func_003824D0(CGt2dObject *obj, const CGtV2d &a, const CGtV2d &b, float c, CGtV4d d, CGtV4d e,
                              const unsigned short *text, int f, float g, float h);

// 0x0031BD60. Shows one side prompt: plays the cue, lays the prompt text out beside the main text (left) or the
// right prompt text (right), 20 units away, and records its size, position and start time for Update's pop-in.
void func_0031BD60(CB3HelpBarComponent *self, int, bool right)
{
    UnkStruct_D_0066A4C0 *colours = &D_0066A4C0;
    const unsigned short *text = right ? self->field_48[1] : self->field_48[0];
    CGtV4d base;
    float t = 0.75f;
    base = colours->field_60;  // one 128-bit move (operator=), as retail; initialization copies float-wise
    CGtV4d blend = GtMathPs2::Interpolate(colours->field_60, colours->field_30, t);
    func_003B8840(text);
    func_002859F0(&D_01E7A800);
    D_01E77540.TriggerSpotDucker(10.0f);
    if (right) {
        func_003824D0(self->field_18[1], CGtV2d(self->field_20->mObjectSpace.mTopLeftPos.marValues[0] - 20.0f, 400.0f),
                      D_004C5200, 30.0f, base, blend, text, 1, 1.25f, 3.402823466e+38f);
        self->field_6F[1] = 1;
        self->field_54[1] = D_004F50A0.value;
        self->field_28[1] = self->field_18[1]->mObjectSpace.mSize;
        self->field_38[1] = self->field_18[1]->mObjectSpace.mTopLeftPos;
    } else {
        func_003824D0(self->field_18[0],
                      CGtV2d(20.0f + (self->field_14->mObjectSpace.mTopLeftPos.marValues[0] +
                                      self->field_14->mObjectSpace.mSize.marValues[0]), 400.0f),
                      D_004C51F8, 30.0f, base, blend, text, 1, 1.25f, 3.402823466e+38f);
        self->field_6F[0] = 1;
        self->field_54[0] = D_004F50A0.value;
        self->field_28[0] = self->field_18[0]->mObjectSpace.mSize;
        self->field_38[0] = self->field_18[0]->mObjectSpace.mTopLeftPos;
    }
}
