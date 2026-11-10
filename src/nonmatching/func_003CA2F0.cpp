// NONMATCHING: func_003CA2F0 -- retail 184 / ours 173 instructions, 127 in changed runs
// fresh4: first draft, logic decoded (paragraph func_002F9690 + box Prepare, settings block at +0x20, text at +0x50+idx*0x100); 127 off: retail keeps the size/pos constant arithmetic unfolded (sub.s 580-40, 310-40, add.s 30+20, K+20 into named CGtV2d locals at 0x118/0x120), b119 folds it; frame 0x130 slot order not attempted
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003CA2F0 -- hand-written from scratch (the lifter refused it). Unnamed, so a placeholder with C linkage.
// Layout and types are [G] (instruction widths). [L] builds one of two (idx 0/1) paragraph + box object pairs in
// CGt2dScene D_01E903E0: func_002F9690 is CGt2dObjectParagraph::Prepare (DNAT, see func_0033E220.cpp).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
using namespace GtMathPs2;

struct UnkStruct_003CA2F0_set {
    float field_0;
    float field_4;
    float field_8;
    int field_C;
    int field_10;
    short field_14;
    short field_16;
};
struct UnkStruct_003CA2F0 {
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[6];
    CGt2dObject *field_10[2];
    CGt2dObject *field_18[2];
    UnkStruct_003CA2F0_set field_20[2];
    unsigned short field_50[2][0x80];
};
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x14]; void *field_14; };
struct UnkStruct_D_00665ED0 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern unsigned char D_0051BA44[];
extern float D_004E1E98;
extern const CGtV2d D_004CA460;

extern "C" CGt2dObject *ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" unsigned short *func_00271A00(void *, int);
extern "C" void *func_001A3AA0(unsigned short *, const unsigned short *, int *);
extern "C" void func_002F9690(CGt2dObject *obj, const CGtV2d &pos, float width, const CGtV2d &anchor, CGtV4d colour,
                              const unsigned short *text, const UnkStruct_003CA2F0_set *settings, unsigned int a, int type);
extern "C" void Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(
    CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d);

extern "C" void func_003CA2F0(UnkStruct_003CA2F0 *self, unsigned char idx, signed char n);

// 0x003CA2F0
void func_003CA2F0(UnkStruct_003CA2F0 *self, unsigned char idx, signed char n)
{
    CGtV2d size = CGtV2d(580.0f, 310.0f) - CGtV2d(40.0f, 40.0f);
    CGtV2d pos = CGtV2d(30.0f, D_004E1E98) + CGtV2d(20.0f, 20.0f);
    int v;
    int id = self->field_8 + 1;
    void *frame = D_01E903E0.field_14;
    pos.marValues[1] = pos.marValues[1] - (float)idx * (0.4f * size.marValues[1]);
    self->field_18[idx] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, id, frame);
    self->field_10[idx] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, id, frame);
    UnkStruct_003CA2F0_set *s = &self->field_20[idx];
    s->field_0 = 1.1f;
    s->field_4 = 1.1f;
    s->field_8 = 28.8f;
    s->field_C = 0;
    s->field_10 = D_00665ED0.field_0;
    s->field_14 = -1;
    s->field_16 = -1;
    v = n + 1;
    func_001A3AA0(self->field_50[idx], func_00271A00(D_0051BA44, 1), &v);
    func_002F9690(self->field_18[idx], pos, size.marValues[0], CGtV2d(0.0f, 0.0f), CGtV4d(1.0f, 1.0f, 1.0f, 1.0f),
                  self->field_50[idx], s, 0x67, 2);
    CGt2dObject *o = self->field_18[idx];
    Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(
        self->field_10[idx], o->Pos() - D_004CA460, CGtV2d(0.0f, 0.0f), o->Size() + D_004CA460 * 2.0f,
        CGtV4d(0.0f, 0.0f, 0.0f, 1.0f));
}
