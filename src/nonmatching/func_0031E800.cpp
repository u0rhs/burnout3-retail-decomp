// NONMATCHING: func_0031E800 -- retail 306 / ours 306 instructions, 201 in changed runs
// L264 first draft from the asm: logic/branch structure believed right (two anchor arms, neighbour searches, 640 fallback, fit + inlined SetPos), 306/306 but frame 0x70 vs 0x80 and registers shifted throughout. Open: retail recomputes field_1C[k] in each arm (ours CSEs it), keeps &o2->mSize in t3, loads size.x once for div+mul (s*w operand order), dead temp stores at 0x50 and ld/sd copies 0x28->0x40, 0x30->0x48, 0x38->0x78 (CGtV2d inline temporaries)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_0031E800 -- hand-written (L264) from the asm. [L] a CB3PromptsComponent method (same unit as Update and
// Release; Update calls it with `this` after building the field_9C icon): fits each visible prompt text into the gap
// before its neighbour, scaling the text size and re-anchoring it. Unnamed in every table, so a placeholder with C
// linkage. Field names are placeholders; every type is [G].
#include "b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using GtMathPs2::CGtV2d;

extern const float D_004C52E0[12];
extern const int D_004C5310[12];

class CB3PromptsComponent : public CB3MenuComponentBase {
public:
    unsigned char pad_C[4];
    unsigned long field_10;
    unsigned char pad_18[4];
    CGt2dObject *field_1C[11];
    CGt2dObject *field_48[11];
    CGt2dObject *field_74[4];
    CGt2dObject *field_84[4];
    CGt2dObject *field_94;
    CGt2dObject *field_98;
    CGt2dObject *field_9C;
};

static inline void func_0031E800_inl1(CGt2dObject *o, const CGtV2d &pos, const CGtV2d &anchor)  // [G] inlined SetPos
{
    o->mObjectSpace.mTopLeftPos = pos - o->mObjectSpace.mSize * anchor;
}

// 0x0031E800
extern "C" void func_0031E800(CB3PromptsComponent *self)
{
    int i;
    // [C] j lives in t6 across the outer loop (0x31E8F0/0x31EA40 write it, nothing resets it per i): the k == 0 arm with
    // field_10 & 0x80 (0x31EA28) skips the search and tests j < 11 at 0x31EA30 with the previous prompt's value. Declared
    // here so it carries; first use with no earlier prompt reaching a search reads the caller's t6 (undefined; 0 here).
    int j = 0;
    for (i = 0; i < 11; i++) {
        int k = D_004C5310[i];
        CGt2dObject *o = self->field_1C[k];
        if (o == 0) continue;
        if (o->mObjectSpace.mTopLeftPos.marValues[1] < 416.0f) continue;
        CGt2dObject **slot;
        const CGtV2d *sz;
        CGtV2d anchor;
        CGtV2d p;
        float cy;
        float space;
        int kk;
        if (D_004C52E0[k] <= 0.5f || (k == 2 && (self->field_10 & 0x80) != 0)) {
            slot = (CGt2dObject **)((char *)self + k * 4 + 0x1C);
            anchor = CGtV2d(0.0f, 0.5f);
            CGt2dObject *o2 = *slot;
            sz = &o2->mObjectSpace.mSize;
            p = o2->mObjectSpace.mTopLeftPos;
            cy = 0.0f + p.marValues[1] + 0.5f * o2->mObjectSpace.mSize.marValues[1];
            if (k == 0 && (self->field_10 & 0x80) != 0) {
                kk = 2;
            } else {
                for (j = i + 1; j < 11; j++) {
                    kk = D_004C5310[j];
                    if (self->field_48[kk] != 0 && self->field_1C[kk]->mObjectSpace.mTopLeftPos.marValues[1] < 416.0f) continue;
                    if (self->field_48[kk] != 0) break;
                }
            }
            CGt2dObject *n9c = self->field_9C;
            if (n9c != 0 && o->mObjectSpace.mTopLeftPos.marValues[0] < n9c->mObjectSpace.mTopLeftPos.marValues[0]) {
                space = n9c->mObjectSpace.mTopLeftPos.marValues[0] - o->mObjectSpace.mTopLeftPos.marValues[0] - 5.0f;
            } else if (j < 11 && self->field_98 != 0 && !(D_004C52E0[kk] <= 0.5f)
                       && o->mObjectSpace.mTopLeftPos.marValues[0] < self->field_98->mObjectSpace.mTopLeftPos.marValues[0]) {
                space = self->field_98->mObjectSpace.mTopLeftPos.marValues[0] - o->mObjectSpace.mTopLeftPos.marValues[0] - 5.0f;
            } else {
                for (j = i + 1; j < 11; j++) {
                    kk = D_004C5310[j];
                    CGt2dObject *b = self->field_48[kk];
                    if (b != 0 && self->field_1C[kk]->mObjectSpace.mTopLeftPos.marValues[1] < 416.0f) continue;
                    if (b != 0) {
                        space = b->mObjectSpace.mTopLeftPos.marValues[0] - o->mObjectSpace.mTopLeftPos.marValues[0] - 5.0f;
                        break;
                    }
                }
                if (j == 11) space = 640.0f;
            }
        } else {
            slot = (CGt2dObject **)((char *)self + k * 4 + 0x1C);
            anchor = CGtV2d(1.0f, 0.5f);
            CGt2dObject *o2 = *slot;
            sz = &o2->mObjectSpace.mSize;
            p = o2->mObjectSpace.mTopLeftPos + o2->mObjectSpace.mSize;
            cy = 0.0f + p.marValues[1] + 0.5f * o2->mObjectSpace.mSize.marValues[1];
            for (j = i - 1; j >= 0; j--) {
                kk = D_004C5310[j];
                if (self->field_48[kk] != 0 && self->field_1C[kk]->mObjectSpace.mTopLeftPos.marValues[1] < 416.0f) continue;
                if (self->field_48[kk] != 0) break;
            }
            if (self->field_98 != 0 && j >= 0 && D_004C52E0[kk] <= 0.5f
                && self->field_94->mObjectSpace.mTopLeftPos.marValues[0] + self->field_94->mObjectSpace.mSize.marValues[0]
                   < o->mObjectSpace.mTopLeftPos.marValues[0] + o->mObjectSpace.mSize.marValues[0]) {
                space = (o->mObjectSpace.mTopLeftPos.marValues[0] + o->mObjectSpace.mSize.marValues[0])
                      - (self->field_94->mObjectSpace.mTopLeftPos.marValues[0] + self->field_94->mObjectSpace.mSize.marValues[0]) - 5.0f;
            } else {
                for (j = i - 1; j >= 0; j--) {
                    kk = D_004C5310[j];
                    CGt2dObject *b = self->field_48[kk];
                    if (b != 0 && self->field_1C[kk]->mObjectSpace.mTopLeftPos.marValues[1] < 416.0f) continue;
                    if (b != 0) {
                        if (D_004C52E0[kk] <= 0.5f) {
                            space = (o->mObjectSpace.mTopLeftPos.marValues[0] + o->mObjectSpace.mSize.marValues[0])
                                  - (self->field_1C[kk]->mObjectSpace.mTopLeftPos.marValues[0] + self->field_1C[kk]->mObjectSpace.mSize.marValues[0]) - 5.0f;
                        } else {
                            space = (o->mObjectSpace.mTopLeftPos.marValues[0] + o->mObjectSpace.mSize.marValues[0])
                                  - (b->mObjectSpace.mTopLeftPos.marValues[0] + b->mObjectSpace.mSize.marValues[0]) - 5.0f;
                        }
                        break;
                    }
                }
                if (j < 0) space = 640.0f;
            }
        }
        if (!(sz->marValues[0] <= space)) {
            CGt2dObject *o3 = *slot;
            float w = o3->mObjectSpace.mSize.marValues[0];
            float s = space / w;
            o3->mObjectSpace.mSize = CGtV2d(s * w, s * o3->mObjectSpace.mSize.marValues[1]);
            func_0031E800_inl1(*slot, CGtV2d(p.marValues[0], cy), anchor);
        }
    }
}
