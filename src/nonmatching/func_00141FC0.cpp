// NONMATCHING: func_00141FC0 -- retail 141 / ours 144 instructions, 62 in changed runs
// fresh2: 144 vs 141, 62 in changed runs, frame 0x120 vs 0x130. Logic believed right (lerp of 4 lane-Y reads, D_0064D354 == D_00522660+0x12ACF4 read both ways, YAxisType - float). Lerp as static inline a + t*(b-a) + named z = 0.0f after the call gives all three adda.s/madd.s. Left: one 16-byte dead slot, Y() lane reads go through addiu'd pointers (retail lwc1 off(sp)), A's lq in s0, field_18B8/0xFFFF register swap
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00141FC0 -- hand-written (fresh2); the lifter refused it (label in an if body; vsubx.y).
// [C] caller: CB3AICar::Update (0x143B10) passes this. Area not evidenced, so _unclassified/ (docs/conventions.md).
// Field names are placeholders and every type is [G]. [L] D_0064D354 is the same word as D_00522660 + 0x12ACF4
// (0x522660 + 0x12ACF4 = 0x64D354); retail reaches it both ways.

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"

using namespace GtMathPs2;

struct UnkStruct_00141FC0_seg {
    unsigned short field_0;
    unsigned short field_2;
};

struct UnkStruct_00141FC0_segs {
    UnkStruct_00141FC0_seg * field_0;
};

struct UnkStruct_00141FC0_lane {
    unsigned char pad_0[0x4];
    UnkStruct_00141FC0_segs * field_4;
};

struct UnkStruct_00141FC0_pt {
    CGtV4d field_0;
};

struct UnkStruct_D_0064D354 {
    UnkStruct_00141FC0_pt * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12ACF4];
    UnkStruct_00141FC0_pt * field_12ACF4;
};

struct UnkStruct_00141FC0_phys {
    unsigned char pad_0[0x870];
    float field_870;
};

class CB3AITarget {
public:
    float GetCurrentFwdFrac() const;
};

class CB3AICar {
public:
    unsigned char pad_0[0x30];
    CGtV4d field_30;
    unsigned char pad_40[0x1874];
    UnkStruct_00141FC0_lane * field_18B4;
    unsigned short field_18B8;
    unsigned char pad_18BA[0x6];
    int field_18C0;
    unsigned char pad_18C4[0x12C];
    CB3AITarget field_19F0;
    unsigned char pad_19F1[0x1D7];
    unsigned short field_1BC8;
    unsigned char pad_1BCA[0x6];
    float field_1BD0;
    unsigned char pad_1BD4[0x85C];
    UnkStruct_00141FC0_phys * field_2430;
    unsigned char pad_2434[0x8];
    float field_243C;
    unsigned char pad_2440[0xA];
    unsigned short field_244A;
    unsigned char pad_244C[0x4];
    int field_2450;
};

extern UnkStruct_D_0064D354 D_0064D354;
extern UnkStruct_D_00522660 D_00522660;

extern "C" void func_00141D60(CB3AICar *, int, int);

static inline float func_00141FC0_inl1(float a, float b, float t)
{
    return a + t * (b - a);
}

// 0x00141FC0
extern "C" void func_00141FC0(CB3AICar * self)
{
    UnkStruct_00141FC0_lane * lane = self->field_18B4;
    if (lane == 0 || self->field_18B8 == 0xFFFF || self->field_1BC8 == 0xFFFF) {
        self->field_243C = 0.0f;
        self->field_244A = self->field_18C0;
        self->field_2450 = 0;
        return;
    }
    {
        UnkStruct_00141FC0_seg * s = &lane->field_4->field_0[self->field_18B8];
        int a0 = s[0].field_0;
        int b1 = s[1].field_0;
        int a1 = s[0].field_2;
        int b2 = s[1].field_2;
        float t = GtMath::Min(GtMath::Max(self->field_1BD0, 0.0f), 1.0f);
        float fr = self->field_19F0.GetCurrentFwdFrac();
        float z = 0.0f;
        float f = GtMath::Min(GtMath::Max(fr, z), 1.0f);
        float ya = D_0064D354.field_0[b1].field_0.Y();
        UnkStruct_00141FC0_pt * pts = *(UnkStruct_00141FC0_pt **)((int)&D_00522660 + 0x12ACF4);
        float yb = pts[a0].field_0.Y();
        float yc = pts[b2].field_0.Y();
        float yd = pts[a1].field_0.Y();
        float l1 = func_00141FC0_inl1(yb, ya, t);
        float l2 = func_00141FC0_inl1(yd, yc, t);
        float h = func_00141FC0_inl1(l2, l1, f);
        self->field_243C = self->field_30.Y() - h;
        float d = self->field_243C - self->field_2430->field_870;
        if (d <= -1.0f) {
            if (d < -5.0f) {
                self->field_2450++;
                if (self->field_2450 > 60) {
                    func_00141D60(self, self->field_244A - 8, 0);
                    self->field_2450 = 0;
                }
            } else {
                self->field_2450 = 0;
            }
        } else {
            self->field_244A = self->field_18C0;
            self->field_2450 = 0;
        }
    }
}
