// NONMATCHING: func_001BED00 -- retail 118 / ours 120 instructions, 17 in changed runs
// ghvu5: [L] DNAT RollingStart(float); func_001BEEE0's body inlined on field_204->field_20 * speed. Left (17): the speed bit test (retail mfc1 v1,f12 straight from the register; the union/pun spills it -- the known a136 open problem, needs an approved mfc1 helper); W() lane copies addressed through a register (addiu v0,sp,124; lwc1 0(v0)) and slot order (retail W1 0x60, W2 0x90) -- one CSE of the two lane reads; loop counter a1 vs a0.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_001BED00 -- hand-written (ghvu5). Unnamed: placeholder with C linkage.
// [L] DNAT: CB3RaceCarPhysics::RollingStart(float) (research/proto/new_names.csv, low). The first part is func_001BEEE0's
// body inlined (its proven source, simfind 0.525) on the vector field_204->field_20 * speed.
#include "b3/GtMathPs2.h"


using namespace GtMathPs2;

struct UnkStruct_001BED00_2 {
    unsigned char pad_0[0x20];
    CGtV3d field_20;
};

struct UnkStruct_001BED00_e {
    float field_0;
    unsigned char pad_4[0x8];
    float field_C;
    unsigned char pad_10[0xB0];
};

struct UnkStruct_001BED00 {
    unsigned char pad_0[0xB0];
    CGtV3dPlus field_B0;
    CGtV3d field_C0;
    unsigned char pad_D0[0x134];
    UnkStruct_001BED00_2 * field_204;
    unsigned char pad_208[0x668];
    UnkStruct_001BED00_e field_870[1];  // [G] element count unknown (stride 0xC0)
    unsigned char pad_930[0xC0];
    float field_9F0;
    unsigned char pad_9F4[0x775];
    signed char field_1169;
    unsigned char pad_116A[0x2DE];
    unsigned char field_1448[0x44];
    float field_148C;
    float field_1490;
    unsigned char pad_1494[0x8];
    float field_149C;
    float field_14A0;
    float field_14A4;
    unsigned char pad_14A8[0x20];
    int field_14C8;
    unsigned char pad_14CC[0x4];
    float field_14D0;
    float field_14D4;
};

// [G] N140 pad: retail's frame (0x90) has three dead 16-byte slots below the W() lane copy; declared inside the
// NormaliseGetLength stand-in they land there (a function-level pad lands above it).
struct UnkStruct_001BED00_pad { int x[12]; UnkStruct_001BED00_pad() {} ~UnkStruct_001BED00_pad() {} };
// [L] N185: stands in for CGtV3d::NormaliseGetLength(): the header body, with `.set noreorder` also inside the asm string --
// with the region only as separate statements MWCC still puts hazard nops after the mtc1 and the mfc1 (retail 0x1BEF98-0x1BEFA4
// has none).
static inline XAxisType func_001BED00_inl1(CGtV3d &v)
{
    UnkStruct_001BED00_pad pad;
    XAxisType l = v.GetSquaredLength();
    u_long128 t, r;
    float f;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm(".set noreorder" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "qmfc2 %1, $vf1" "\n\t" "mtc1 %1, %2" "\n\t" "sqrt.s %2, %2" "\n\t" "mfc1 %1, %2" "\n\t"
        "qmtc2 %1, $vf1" "\n\t" "qmfc2 %1, $vf1" "\n\t" "vwaitq" "\n\t" "qmtc2 %3, $vf1" "\n\t" "vmulq.xyz $vf1, $vf1, $Q" "\n\t"
        "qmfc2 %0, $vf1" "\n\t" ".set reorder" : "=r"(t), "=&r"(r), "=&f"(f) : "r"(v.mData));
    asm(".set reorder");
    v.mData = t;
    return XAxisType(r);
}
extern "C" int func_001C6F30(void *, float, float);
// [G] func_001BEEE0's body (src/b3/_unclassified/func_001BEEE0.cpp) as an inline
static inline void func_001BED00_inl2(UnkStruct_001BED00 * self, const CGtV3d * p1)
{
    self->field_B0.SetGtV3d(*p1);
    if (p1->GetSquaredLength() < 2.3283064e-10f) {
        self->field_B0.SetPlus(0.0f);
        self->field_C0 = self->field_204->field_20;
    } else {
        self->field_C0 = *p1;
        self->field_B0.SetPlus(func_001BED00_inl1(self->field_C0));
    }
    float w = ((CGtV4d *)&self->field_B0)->W();
    for (int i = 0; i < self->field_1169; i++) {
        self->field_870[i].field_C = w / self->field_870[i].field_0;
    }
}
// 0x001BED00
extern "C" void func_001BED00(UnkStruct_001BED00 * self, float speed)
{
    union { float f; unsigned int i; } u;
    u.f = speed;
    if ((u.i & 0x7F800000) <= 0x37800000) speed = 0.0f;
    CGtV3d v = self->field_204->field_20 * speed;
    self->field_B0.SetGtV3d(v);
    if (v.GetSquaredLength() < 2.3283064e-10f) {
        self->field_B0.SetPlus(0.0f);
        self->field_C0 = self->field_204->field_20;
    } else {
        self->field_C0 = v;
        self->field_B0.SetPlus(func_001BED00_inl1(self->field_C0));
    }
    float w = ((CGtV4d *)&self->field_B0)->W();
    for (int i = 0; i < self->field_1169; i++) {
        self->field_870[i].field_C = w / self->field_870[i].field_0;
    }
    self->field_149C = 0.5f * (self->field_148C + self->field_1490);
    self->field_14C8 = func_001C6F30(self->field_1448, self->field_9F0, ((CGtV4d *)&self->field_B0)->W());
    self->field_14D0 = -1.0f;
    self->field_14D4 = 1.0f;
    self->field_14A0 = -1.0f;
    self->field_14A4 = 0.0f;
}

