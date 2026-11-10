// NONMATCHING: func_001D2960 -- retail 172 / ours 170 instructions, 15 in changed runs
// ghvu10: [L] DNAT CB3AICarPhysics::Update(float). 170/172, 15 changed, frame exact: (1) the float-bits test: retail takes &d->field_23CC (addiu a0) BEFORE the lw of the bits into d's own register (+nop); ours loads the bits first and forms the address in the bnez delay slot; (2) VU numbering of target = v + dir*(s*k): retail v=vf1, dir=vf2, scalar vf3 (result in v's register); ours dir=vf1, scalar=vf2, v=vf3. Float block solved with a literal 0.0f + adda/madd; safe-normalise via [L] N185 stand-ins.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_001D2960 -- hand-written (ghvu10, Ghidra draft). [L] DNAT: CB3AICarPhysics::Update(float)
// (research/proto/new_names.csv, low). Area not evidenced, so _unclassified/ (docs/conventions.md).
// Field names are placeholders and every type is [G].

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_001D2960_p { unsigned char pad_0[0x133C]; int field_133C; unsigned char pad_1340[0x66C]; signed char field_19AC; };
struct UnkStruct_001D2960_d { unsigned char pad_0[0x2178]; unsigned char field_2178; unsigned char pad_2179[7]; int field_2180; unsigned char pad_2184[0x248]; float field_23CC; };
struct UnkStruct_001D2960_m { unsigned char pad_0[0x20]; CGtV3d field_20; };
struct UnkStruct_001D2960 {
    unsigned char pad_0[0xB0];
    CGtV3d field_B0;
    unsigned char pad_C0[0xA0];
    CGtV3d field_160;
    CGtV3d field_170;
    unsigned char pad_180[0x10];
    short field_190;
    unsigned char pad_192[2];
    int field_194;
    int field_198;
    unsigned char pad_19C[0x68];
    UnkStruct_001D2960_m *field_204;
    unsigned char pad_208[8];
    unsigned char field_210;
    unsigned char pad_211;
    unsigned char field_212;
    unsigned char pad_213[0x1140];
    unsigned char field_1353;
    unsigned char pad_1354[0xA0];
    UnkStruct_001D2960_p *field_13F4;
    unsigned char pad_13F8[8];
    float field_1400;
    unsigned char pad_1404[0x10];
    float field_1414;
    unsigned char pad_1418[0x74];
    float field_148C;
    float field_1490;
    unsigned char pad_1494[8];
    float field_149C;
    unsigned char pad_14A0[0xB0];
    unsigned char field_1550;
    unsigned char field_1551;
    unsigned char pad_1552[0x16];
    UnkStruct_001D2960_d *field_1568;
};
struct UnkStruct_D_0055EFEC { void *field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0052267C { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0055EFEC D_0055EFEC[];
extern UnkStruct_D_00522680 D_00522680;
extern UnkStruct_D_0052267C D_0052267C;
extern "C" void func_001D1130(UnkStruct_001D2960 *);
extern "C" void func_001D0B50(UnkStruct_001D2960 *);
extern "C" void func_001BED00(void *, float);
extern "C" void func_001BEEE0(UnkStruct_001D2960 *, const CGtV3d *);
extern "C" void *memset(void *, int, unsigned);
extern "C" void UpdateStickySpeedMatch__15CB3AICarPhysicsFv(UnkStruct_001D2960 *);
extern "C" void Update__17CB3RaceCarPhysicsFf(UnkStruct_001D2960 *, float);

// [L] N185: XAxisType -> float without the address-taken read.
static inline float func_001D2960_inl1(XAxisType x) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x.lVector)); return f; }
// [L] N185: Normalise on a compiler-chosen register (no 1.0*Q tail), the result moved out with a kept qmfc2 (.i).
static inline CGtV3d func_001D2960_inl2(const CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    CGtV3d w = v;
    u_long128 r;
    asm(".set noreorder");
    asm("qmtc2.i %1, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(w.mData) : "r"(l.lVector));
    asm("qmfc2.i %0, %1" : "=r"(r) : "j"(w.mData));
    asm(".set reorder");
    return CGtV3d(r);
}
// [L] N185: CGtV3d + CGtV3d on compiler-chosen registers.
static inline CGtV3d func_001D2960_inl3(u_long128 a, const CGtV3d &b) { u_long128 r; asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b.mData)); return CGtV3d(r); }

// 0x001D2960
extern "C" void func_001D2960(UnkStruct_001D2960 *self, float dt)
{
    func_001D1130(self);
    func_001D0B50(self);
    if (self->field_1550 == 0) {
        self->field_1353 |= 8;
        self->field_1353 |= 0x10;
        self->field_1353 |= 1;
        self->field_1353 |= 2;
        self->field_1353 |= 4;
        self->field_212 = 0;
        memset(&self->field_160, 0, 0x60);
        self->field_160.Zero();
        self->field_170.Zero();
        self->field_190 = 0;
        self->field_194 = 0;
        self->field_198 = 0;
    }
    if (self->field_13F4->field_133C == 0) {
        func_001BED00(D_0055EFEC[self->field_13F4->field_19AC].field_0, 22.35199928f);
        self->field_149C = 0.75f + D_00522680.field_0 / 6.0f;
        self->field_149C = self->field_149C * (0.35f * (0.0f + self->field_1490 + 1.25f * self->field_148C));
        self->field_1400 = 1.0f;
        self->field_1414 = 1.0f;
    } else if (self->field_1550 && !self->field_210) {
        UnkStruct_001D2960_d *d = self->field_1568;
        const float &s = d->field_23CC;
        if (d->field_2180 == 5) {
            UpdateStickySpeedMatch__15CB3AICarPhysicsFv(self);
        } else if (d->field_2178) {
            if ((*(const unsigned int *)&d->field_23CC & 0x7F800000) > 0x37800000) {
                u_long128 vq = self->field_B0.mData;
                CGtV3d v(vq);
                CGtV3d t;
                CGtV3d dir;
                if (func_001D2960_inl1(v.GetSquaredLength()) < 2.3283064e-10f) {
                    dir = self->field_204->field_20;
                } else {
                    dir = func_001D2960_inl2(v);
                }
                t = func_001D2960_inl3(vq, dir * (s * D_0052267C.field_0));
                func_001BEEE0(self, &t);
            }
        }
    }
    if (self->field_1550) Update__17CB3RaceCarPhysicsFf(self, dt);
    self->field_1551 = self->field_1550;
}
