// NONMATCHING: Update__17CB3TrafficVehicleFP21CB3TrafficRaceCarInfoi -- retail 19357 / ours 19356 instructions, 1 in changed runs
// traffic1: Update-only diff (build/vt/traffic1/d.sh) 19357/19356, 1 changed: tree-1 exit lacks retail's 'b epilogue' (ours falls into the logic-exit stub). Source order if(field_46){ if(lane end && !field_118) Remove(); else {logic; if(full){...} else {matrix}} } else Remove(); (N151 trees 2x255 bodies identical). [G] stand-ins: local GetSquaredLength without .set noreorder (the region moves the loop-1 body out of line [C]), compiler-chosen vsub + written-out SetY(0) (loop-2 VU numbering), in-place operator+ on the by-value operand (matrix branch), GetLength one=result GPR, N140 pad (frame 0xD0). try.py's count is whole-object (Remove/RemoveFromLanes defined here). Negative for the last instr: return/goto end after tree 1, pad scoped in logic, inverted inner if, logic as inline helper.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed

// Update__17CB3TrafficVehicleFP21CB3TrafficRaceCarInfoi -- traffic1 draft. N151: func_00173D30 ([L] CB3TrafficVehicle::Remove())
// auto-inlined twice (2 x 255 bodies); the rest is Update's own logic (~500 instrs).
#pragma auto_inline on
#pragma defer_codegen on

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3TrafficVehicle;
class CB3TrafficParam {
public:
    void Remove();
    void RemoveFromTrafficLights();

    unsigned char pad_0[0x18];
    float field_18;
    unsigned char pad_1C[0x10];
    float field_2C;
    float field_30;
    unsigned char pad_34[0xD];
    unsigned char field_41;
    unsigned char pad_42[0x4];
    unsigned char field_46;
    unsigned char pad_47;
    unsigned char field_48;
    unsigned char field_49;
};
class CB3TrafficSystem {
public:
    void AddToDeadTrafficParamList(CB3TrafficParam *);
    unsigned char pad_0[0x40000];
};
class CB3TrafficRaceCarInfo {                    // [G] 0x70-byte records (as DoTrafficBehaviour)
public:
    unsigned char pad_0[0x30];
    CGtV3d field_30;
    unsigned char pad_40[0x10];
    CGtV3d field_50;
    unsigned char pad_60[0x8];
    unsigned char field_68;
    unsigned char pad_69[0x7];
};
struct UnkStruct_00186850_seg { unsigned char pad_0[0x10]; int field_10; };
struct UnkStruct_00186850_lane { UnkStruct_00186850_seg * field_0; unsigned char pad_4[0x48]; };
struct UnkStruct_00186850_rec { CGtMatrix3x4 field_0; unsigned char pad_40[0x10]; };
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x22C];
    UnkStruct_00186850_lane field_22C[1];        // [G] count unknown
    unsigned char pad_278[0x33F98];
    UnkStruct_00186850_rec field_34210[1];       // [G] count unknown
    unsigned char pad_34260[0x4FD4];
    float field_39234[6][0xFE];
    unsigned char field_3AA04[6][0xFE];
    unsigned char field_3AFF8[6][0x19];
    unsigned char field_3B08E[6][0x8];
    unsigned char pad_3B0BE[0x72];
    unsigned char field_3B130[6];
    unsigned char field_3B136[6];
    unsigned char field_3B13C[6];
};
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_D_0052267C { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0052267C D_0052267C;
extern float D_004B71B0[][5];

class CB3TrafficVehicle {
public:
    void Update(CB3TrafficRaceCarInfo *, int);
    void RemoveFromLanes();
    void CheckForChangeLane();
    void InitalisePosition();
    void DoTrafficBehaviour(CB3TrafficRaceCarInfo *, int);
    void UpdatePosition();

    unsigned char pad_0[0x5E];
    unsigned char field_5E;
    unsigned char pad_5F[0x11];
    CGtMatrix3x4 field_70;
    unsigned char pad_B0[0x14];
    float field_C4;
    unsigned char field_C8;
    unsigned char pad_C9[0x27];
    float field_F0[8];
    CB3TrafficVehicle * field_110;
    CB3TrafficParam * field_114;
    int field_118;
    float field_11C;
    float field_120;
    unsigned char pad_124[0x1C];
    float field_140;
    float field_144;
    float field_148;
    unsigned char pad_14C[0x24];
    signed char field_170;
    unsigned char pad_171;
    signed char field_172;
    unsigned char pad_173;
    unsigned char field_174;
    unsigned char field_175;
    unsigned char pad_176;
    unsigned char field_177;
    unsigned char field_178;
    unsigned char field_179;
    unsigned char field_17A;
    unsigned char field_17B;
};

extern CB3TrafficSystem D_00527440;
struct UnkStruct_D_0055D7F7 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
};
extern UnkStruct_D_0055D7F7 D_0055D7F7;
extern "C" void func_00163E90(CB3TrafficSystem *, CB3TrafficVehicle *, int);
extern "C" void func_00173D30(CB3TrafficVehicle * self);

void CB3TrafficVehicle::RemoveFromLanes()
{
    CB3TrafficParam * t0 = field_114;
    if (t0 != 0) {
        t0->RemoveFromTrafficLights();
        field_114->Remove();
        D_00527440.AddToDeadTrafficParamList((CB3TrafficParam*)field_114);
        field_114 = 0;
    }
    if (field_118 != 0) {
        field_118 = 0;
        field_11C = -1.0f;
    }
}

extern "C" void func_00173D30(CB3TrafficVehicle * self)
{
    self->field_17A |= 1;
    self->RemoveFromLanes();
    if (D_0055D7F7.field_0 != 0) {
        if (self->field_110 != 0) func_00173D30(self->field_110);
    } else {
        if (self->field_110 != 0 && (self->field_174 & 2) == 0) func_00173D30(self->field_110);
    }
    func_00163E90(&D_00527440, self, 1);
    self->field_174 = 0;
}

// [G] GetSquaredLength without the header's `.set noreorder` region: the region makes MWCC move the loop-1 body out of line
// (traffic1 probe u1/t1 [C]); retail keeps it in line.
static inline float func_00186850_inl1(const CGtV3d &v)
{
    u_long128 sq, one, t;
    asm("vmul.xyz %0, %1, %1" : "=j"(sq) : "j"(v.mData));
    asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one));
    asm("vadday.x $ACC, %1, %1y" "\n\t" "vmaddz.x %0, %2, %1z" : "=j"(t) : "j"(sq), "j"(one));
    float r; asm("qmfc2 %0, %1" : "=r"(r) : "j"(t));
    return r;
}
static inline CGtV3d func_00186850_inl3(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 t;
    asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(t);
}
// [G] operator+ stand-in: `vadd.xyz o, this, o` in place on the by-value operand (retail's matrix branch 0x190324..0x19033C:
// result in the product's register; header operator+ gives other numbering, traffic1 probe y1 [C]).
static inline CGtV3d func_00186850_inl4(const CGtV3d &a, CGtV3d o)
{
    asm("vadd.xyz %0, %1, %0" : "+j"(o.mData) : "j"(a.mData));
    return o;
}
// [G] GetLength with one GPR for 1.0 and the result (retail 0x186A50..0x186A60 t0/t0; the header's "=&r" one gives a1).
static inline XAxisType func_00186850_inl5(const CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 t;
    XAxisType r;
    asm(".set noreorder");
    asm("qmtc2.i %1, $vf1" "\n\t" "vsqrt $Q, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %0, $vf1" "\n\t"
        "vwaitq" "\n\t" "qmtc2.i %0, $vf1" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %0, $vf1"
        : "=&r"(t) : "r"(l.lVector));
    asm(".set reorder");
    r = XAxisType(t);
    return r;
}
struct UnkStruct_00186850_pad { int x[12]; UnkStruct_00186850_pad() {} ~UnkStruct_00186850_pad() {} };
void CB3TrafficVehicle::Update(CB3TrafficRaceCarInfo *info, int n)
{
    UnkStruct_00186850_pad pad;  // N140 [G]: three dead 16-byte slots (retail frame 0xD0)
    field_C8 = 0xD;
    bool full = false;
    int i;
    for (i = 0; i < n; i++) {
        if (info[i].field_68) {
            CGtV3d d = field_70.mPos - info[i].field_50;
            d.SetY(0.0f);
            float d2 = func_00186850_inl1(d);
            if ((d2 < 275 * 275 || (field_174 & 4)) && !(field_174 & 2)) {
                full = true;
                if (d2 < 250 * 250 || (field_174 & 4)) {
                    field_17B |= (unsigned char)(1 << i);
                } else {
                    field_17B &= (unsigned char)~(1 << i);
                }
                D_00522660.field_3AA04[i][D_00522660.field_3B130[i]] = field_177;
                D_00522660.field_3B130[i]++;
            } else {
                field_17B &= (unsigned char)~(1 << i);
            }
        }
    }
    for (i = 0; i < n; i++) {
        CGtV3d d = func_00186850_inl3(field_70.mPos, info[i].field_30);
        u_long128 zs;  // [G] SetY(0.0f) written out (header call numbers zero before mPos, probe k2 [C])
        asm("qmtc2.ni %1, %0" : "=j"(zs) : "r"(0.0f));
        asm("vaddx.y %0, $vf0, %1x" : "+j"(d.mData) : "j"(zs));
        float dist = func_00186850_inl5(d);
        D_00522660.field_39234[i][field_177] = dist;
        if (full && (dist < 100.0f || (field_174 & 4)) && !(field_174 & 2)) {
            if (dist < 16.0f && D_00522660.field_3B13C[i] < 8) {
                D_00522660.field_3B08E[i][D_00522660.field_3B13C[i]] = field_177;
                D_00522660.field_3B13C[i]++;
            }
            if (D_00522660.field_3B136[i] < 25) {
                D_00522660.field_3AFF8[i][D_00522660.field_3B136[i]] = field_177;
                D_00522660.field_3B136[i]++;
            }
        }
    }
    CB3TrafficParam *p = field_114;
    if (p == 0) return;
    int pos = (int)p->field_30;
    if (p->field_46 != 0) {
        UnkStruct_00186850_lane *lane;
        if (p->field_41 == 255) {
            lane = 0;
        } else {
            lane = &D_00522660.field_22C[p->field_41];
        }
        if (pos >= lane->field_0->field_10 - 1 && field_118 == 0) {
            func_00173D30(this);
        } else {
            field_C4 = p->field_2C;
            CheckForChangeLane();
            if (full && (field_17A & 1)) {
                field_17A &= ~1;
                InitalisePosition();
            }
            if (full) {
            if (!(field_174 & 4) && D_0055D7F7.field_0 == 0) DoTrafficBehaviour(info, n);
            UpdatePosition();
            if (field_114->field_18 <= 0.0f) {
                if (field_C4 < 0.5f) field_148 = 0.0f;
                p = field_114;
                if (p->field_46 == 1) {
                    if (p->field_18 < -0.06f) field_148 = 0.0f;
                } else {
                    if (p->field_18 < -0.03f) field_148 = 0.0f;
                }
            }
            if (field_148 >= 0.0f) {
                field_148 += D_0052267C.field_0;
                if (field_148 < 0.5f) field_C8 |= 0x10;
                else field_148 = -1.0f;
            }
            float t = field_140;
            if (t >= 0.0f) {
                field_140 = t + D_0052267C.field_0;
                if ((0.0f + t - 0.6f * (float)(int)(t / 0.6f)) / 0.6f < 0.5f) {
                    if (field_175 & 1) field_C8 |= 0x20;
                    if (field_175 & 4) field_C8 |= 0x40;
                } else if (field_110 == 0) {
                    if (field_114->field_48 == 0 && field_5E == field_114->field_41) {
                        field_175 = 0;
                        field_140 = -1.0f;
                    }
                } else {
                    if (field_114->field_48 == 0 && field_110->field_5E == field_114->field_41) {
                        field_175 = 0;
                        field_140 = -1.0f;
                    }
                }
            }
            if (field_172 == 2) {
                if (field_144 < 3.0f) {
                    field_144 += D_0052267C.field_0;
                    if (field_F0[field_170] > 0.0f) {
                        if (D_004B71B0[field_178][field_179] < field_144) field_179++;
                        if (field_179 % 2 == 0) field_C8 |= 2;
                    }
                } else {
                    field_172 = 1;
                    field_144 = -1.0f;
                }
            }
            } else {
                field_17A |= 1;
                field_70 = D_00522660.field_34210[field_114->field_49].field_0;
                field_70.mPos = func_00186850_inl4(field_70.mPos, field_70.mUp * field_120);
            }
        }
    } else {
        func_00173D30(this);
    }
}

