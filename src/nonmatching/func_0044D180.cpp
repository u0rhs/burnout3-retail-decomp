// NONMATCHING: func_0044D180 -- retail 159 / ours 156 instructions, 124 in changed runs
// structure/blocks/calls right (159 vs 156 instrs, ~120 changed): retail keeps row byte offset in s1 and recomputes self+off at each use (no CSE'd row pointer), t0/t1 text ptrs in s3/s2, self in s4; our CSE hoists the row ptr into s0; text via D_0064ED24/D_0065F2A4/D_006514F4 or func_00271A00(D_0051BA44, D_01ECDACD+0x309/0x30A)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using namespace GtMathPs2;

struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;
struct UnkStruct_D_16b { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_16b D_01E65499;
extern UnkStruct_D_16b D_01ECDAC5;
extern UnkStruct_D_16b D_01ECDAC7;
struct UnkStruct_D_16c { signed char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_16c D_01ECDACD;
struct UnkStruct_D_16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_16 D_01E903E0;
extern UnkStruct_D_16 D_0051BA44;
extern UnkStruct_D_16 D_01E90250;
extern UnkStruct_D_16 D_004D3130;
extern UnkStruct_D_16 D_004D3140;
extern unsigned short D_0064ED24[];
extern unsigned short D_0065F2A4[];
extern unsigned short D_006514F4[];
extern "C" void func_00453680(void *, int, int, int);
extern "C" const unsigned short *func_00271A00(void *, int);
extern "C" CGt2dObject *ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void func_0033D4E0(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, const void *, const CGt2dFont *, const unsigned short *, const void *, int);
struct UnkStruct_0044D180_row {
    CGt2dObject *field_0;
    unsigned char pad_4[4];
    void *field_8;
    unsigned char pad_C[4];
    CGt2dObject *field_10[2];
};
struct UnkStruct_0044D180 {
    unsigned char pad_0[8];
    short field_8;
};

// 0x0044D180
extern "C" void func_0044D180(UnkStruct_0044D180 *self, int row, int a2)
{
    const unsigned short *t0 = 0;
    const unsigned short *t1;
    CGtV2d pos1;
    CGtV2d anc1;
    CGtV2d pos2;
    CGtV2d anc2;
    float zf = 0.0f;
    float kf = 1.0f;
    func_00453680(self, row, 2, a2);
    int off = row * 0x24;
    ((UnkStruct_0044D180_row *)((char *)self + off + 0xC))->field_0->mObjectSpace.mColour = *(const CGtV4d *)&D_004D3140;
    if (D_01E65499.field_0 != 0) {
        t1 = D_0064ED24;
        if (D_01ECDAC5.field_0 != 0) {
            t0 = t1;
            t1 = D_0065F2A4;
        }
    } else {
        if (D_01ECDAC7.field_0 != 0) {
            t1 = func_00271A00(&D_0051BA44, D_01ECDACD.field_0 + 0x309);
            if (D_01ECDAC5.field_0 != 0) {
                t0 = t1;
                t1 = func_00271A00(&D_0051BA44, D_01ECDACD.field_0 + 0x30A);
            }
        } else {
            t1 = D_0064ED24;
            if (D_01ECDAC5.field_0 != 0) {
                t0 = t1;
                t1 = D_006514F4;
            }
        }
    }
    if (t0 != 0) {
        UnkStruct_0044D180_row *q = (UnkStruct_0044D180_row *)((char *)self + off + 0xC);
        float x = -190.0f + (zf + q->field_0->mObjectSpace.mTopLeftPos.marValues[0] + kf * q->field_0->mObjectSpace.mSize.marValues[0]);
        q->field_10[0] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, q->field_8);
        pos1.marValues[0] = x;
        pos1.marValues[1] = 0.0f;
        anc1.marValues[0] = 1.0f;
        anc1.marValues[1] = 0.5f;
        func_0033D4E0(q->field_10[0], pos1, anc1, 22.0f, &D_01E90250, D_00665ED0.pFont, t0, &D_004D3130, 2);
    }
    UnkStruct_0044D180_row *q2 = (UnkStruct_0044D180_row *)((char *)self + off + 0xC);
    float x2 = -30.0f + (zf + q2->field_0->mObjectSpace.mTopLeftPos.marValues[0] + kf * q2->field_0->mObjectSpace.mSize.marValues[0]);
    q2->field_10[1] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, q2->field_8);
    pos2.marValues[0] = x2;
    pos2.marValues[1] = 0.0f;
    anc2.marValues[0] = 1.0f;
    anc2.marValues[1] = 0.5f;
    func_0033D4E0(q2->field_10[1], pos2, anc2, 22.0f, &D_01E90250, D_00665ED0.pFont, t1, &D_004D3130, 2);
}
