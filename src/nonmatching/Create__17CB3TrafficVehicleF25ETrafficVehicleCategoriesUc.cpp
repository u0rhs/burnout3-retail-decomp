// NONMATCHING: Create__17CB3TrafficVehicleF25ETrafficVehicleCategoriesUc -- retail 199 / ours 198 instructions, 1 in changed runs
// pass2e: negated Z through static inline func_001864F0_inl3 returning -v->Z() (ZAxisType by value) gives retail's dead 0x70 slot; lane slots now match. Left (1): retail reloads the 0.1f literal (lwc1 gp) in the out-of-line field_120 clamp block, ours reuses f0 (tried literal at each use, field re-read, T& r, clamp inline, fresh temp)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// repair1: compiles again (local ZAxisType operator- dropped: the header's ZAxisType::operator-() is this function's body); 0.2f written at each use, field_173 > 5 && < 11 (slti at), &D_01D9BB10[i] element pointer (lwc1 0x88(v1)), 5 N140 pads for retail's 0x150 frame. Left (5): one dead slot sits above the 169C/16A0 lane copies instead of at sp+0x70 between them and the negated copy (lane slots 0x10 low), and retail reloads the 0.1f literal in the out-of-line field_120 clamp block

// lit4fix: .lit4 externs rewritten as literals; was: a189: 35 instrs differ, logic complete. Left: (1) frame 0x110 vs retail 0x150 (retail has ~4 more 16B slots incl. one at sp+0x70 between the Z-lane copies; N140 pad objects did not change ours), lane slot offsets follow; (2) retail loads the 8 gp D_004E* floats before the swc1 run, ours load/store p

// CB3TrafficVehicle::Create(ETrafficVehicleCategories,unsigned char) -- hand-written (a189); the lifter refused it.
// [C] name: the mangled symbol in retail's tables. Layout [G] from instruction widths; field names are placeholders.
#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

enum ETrafficVehicleCategories {};

class CB3TrafficAxle {
public:
    void Prepare();
    unsigned char pad_0[0x30];
};

struct UnkStruct_001864F0_b0 {
    unsigned char pad_0[0x18];
    float field_18;
    unsigned char pad_1C[0xE80 - 0x1C];
    CGtV4d field_E80;
    unsigned char pad_E90[0x169C - 0xE90];
    CGtV4d * field_169C;
    CGtV4d * field_16A0;
    CGtV4d * field_16A4;
    CGtV4d * field_16A8;
    unsigned char pad_16AC[0x16BA - 0x16AC];
    unsigned char field_16BA;
    unsigned char field_16BB;
    unsigned char field_16BC;
    unsigned char field_16BD;
};

struct UnkStruct_D_01D9BB10_e {
    unsigned char pad_0[0x88];
    float field_88;
    unsigned char pad_8C[0x4];
    unsigned char pad_90[0x20];
};

class CB3TrafficVehicle {
public:
    int Create(ETrafficVehicleCategories p0, unsigned char p1);

    CB3TrafficAxle field_0;
    CB3TrafficAxle field_30;
    unsigned char pad_60[0x50];
    UnkStruct_001864F0_b0 * field_B0;
    float field_B4;
    float field_B8;
    float field_BC;
    float field_C0;
    unsigned char pad_C4[0x8];
    float field_CC;
    float field_D0;
    float field_D4;
    float field_D8;
    float field_DC;
    float field_E0;
    float field_E4;
    float field_E8;
    float field_EC;
    int field_F0[6];
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    float field_11C;
    float field_120;
    float field_124;
    unsigned char pad_128[0x8];
    int field_130;
    float field_134;
    float field_138;
    unsigned char pad_13C[0x10];
    float field_14C;
    float field_150;
    float field_154;
    float field_158;
    float field_15C;
    int field_160;
    int field_164;
    float field_168;
    unsigned char pad_16C[0x4];
    signed char field_170;
    unsigned char pad_171[1];
    signed char field_172;
    signed char field_173;
    unsigned char field_174;
    unsigned char pad_175[1];
    unsigned char field_176;
};

struct UnkStruct_D_0055D7F9 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
};
struct UnkStruct_D_0064CE44 {
    CB3TrafficVehicle * field_0;
    unsigned char pad_4[0xC];
};

extern UnkStruct_D_0055D7F9 D_0055D7F9;
extern UnkStruct_D_0064CE44 D_0064CE44;
extern UnkStruct_D_01D9BB10_e D_01D9BB10[];
extern float karTrafficSuspensionTravels[];

struct UnkStruct_001864F0_pad { int x[4]; UnkStruct_001864F0_pad() {} ~UnkStruct_001864F0_pad() {} };  // [G] N140 frame pad (retail frame 0x150)
// gapN: the -1.0 multiply here (retail 0x1865D0 `lui 0xBF80; qmtc2.ni; vmulx.z D,D,$vf2x`) is not ZAxisType::operator- (the header's is
// now vsub.z, 28 retail sites); [G] operator *(ZAxisType, float) by -1.0f in the old header body's register form, kept as a local stand-in
static inline ZAxisType func_001864F0_inl4(const ZAxisType &z) { u_long128 t = z.lVector; asm("qmtc2.ni %1, $vf2" "\n\t" "vmulx.z %0, %0, $vf2x" : "+j"(t) : "r"(0xBF800000)); return ZAxisType(t); }
static inline ZAxisType func_001864F0_inl3(const CGtV4d *v) { return func_001864F0_inl4(v->Z()); }
// 0x001864F0
int CB3TrafficVehicle::Create(ETrafficVehicleCategories p0, unsigned char p1)
{
    UnkStruct_001864F0_pad k0, k1, k2, k3, k4;
    field_114 = 0;
    field_118 = 0;
    field_11C = -1.0f;
    field_0.Prepare();
    field_30.Prepare();
    field_10C = 0;
    field_110 = 0;
    field_14C = 0.0f;
    field_150 = 0.0f;
    if (field_B0 != 0) {
        float t0 = field_B0->field_18;
        float t1 = 0.1f;
        field_120 = t0;
        if (t0 < t1) {
            field_120 = 0.1f;
        }
        if (field_B0->field_16BA > 0) {
            float z0 = ZAxisType(field_B0->field_169C->mData);
            field_150 = z0;
        }
        if (field_B0->field_16BB > 0) {
            float z1 = ZAxisType(field_B0->field_16A0->mData);
            field_14C = z1;
        }
        if (field_B0->field_16BC > 0) {
            float z2 = func_001864F0_inl3(field_B0->field_16A4);
            field_138 = z2;
        }
        if (field_B0->field_16BD > 0) {
            float z3 = ZAxisType(field_B0->field_16A8->mData);
            field_134 = z3;
        }
    }
    if (field_14C == 0.0f) {
        if (field_150 == 0.0f) {
            field_14C = -0.5f;
        }
    }
    field_172 = 0;
    field_170 = -1;
    field_130 = 0;
    field_B4 = 0.0f;
    field_B8 = 1.0f;
    field_BC = 0.0f;
    field_C0 = 1.0f;
    if (field_B0 != 0) {
        field_158 = 0.2f / (float)field_B0->field_E80.X();  // [C] retail FPU form, not a VU lane op: 0x18666C div.s (the cast keeps the port's PS2 float model)
        float z4 = ZAxisType(field_B0->field_E80.mData);
        field_154 = 0.2f / z4;
    } else {
        field_158 = 0.2f;
        field_154 = 0.2f;
    }
    field_173 = p0;
    field_15C = karTrafficSuspensionTravels[field_173];
    field_164 = 0;
    field_124 = 1.0f;
    for (int i = 0; i < 6; i++) {
        field_F0[i] = 0;
    }
    field_174 = 0;
    field_174 |= 1;
    if (field_173 > 5 && field_173 < 11) {
        field_174 |= 4;
    }
    field_CC = 0.625f;
    field_D0 = 0.4956515f;
    field_D4 = -0.1862765f;
    field_D8 = 0.3f;
    field_DC = 0.29375f;
    field_E0 = -0.1703813f;
    field_E4 = -0.1570656f;
    field_E8 = -0.2375f;
    field_EC = 0.13125f;
    UnkStruct_D_01D9BB10_e *e = &D_01D9BB10[field_176];
    field_168 = e->field_88;
    if (p1 & 1) {
        if (D_0055D7F9.field_0 != 0) {
            return 0;
        }
        field_174 |= 8;
        D_0064CE44.field_0 = this;
    }
    return 1;
}

