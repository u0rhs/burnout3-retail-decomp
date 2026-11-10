// NONMATCHING: RotateAndScaleCornerBonesToPointToRestOfCar__16CB3VehicleDeformFb -- retail 300 / ours 299 instructions, 101 in changed runs
// ghvu17 (Ghidra draft): logic, loop and block layout right (two windscreen arms, zero-length early return, 0.2f scale test with the store out of line, Cross/Normalise of rows 1-2, matrix product to field_500). UnkEnum_003E0B10 idx keeps retail's beqz/b diamond (movz otherwise); D_004E0D40 is lit4 -> 0.2f (hoisted to f20 as retail); ws assigned (not initialised) gives retail's copy. Left 101: in-place Normalise of a field puts the vmul product on the input's vf1 and parks it through a GPR (retail: product on vf2, no park; same gap in UpdateBodyPartWorldCollisionEffects' GetLength); d loaded twice in retail (ours vmove); matrix-product stand-in (no header API) row registers (retail A0 vf4, A1/A2 via lq+qmtc2 vf3/vf2, B rows on vf1); frame 0x210 vs 0x220; result-copy slot order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3VehicleDeform::RotateAndScaleCornerBonesToPointToRestOfCar(bool) -- hand-written (ghvu17).
// [C] name: the mangled symbol in retail's tables. Classes and structs declared here with only what this function
// touches; field names are placeholders and every type is [G] (instruction widths).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_003E0B10_14 {
    unsigned char pad_0[0x500];
    CGtMatrix3x4 field_500[8];
    CGtMatrix3x4 field_700[8];
};
struct UnkStruct_003E0B10_18 {
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70[20];
    CGtMatrix3x4 field_570[8];
};
extern int kaeOtherMainBone[];

enum UnkEnum_003E0B10 { };
class CB3VehicleDeform {
public:
    CGtV3d GetWindscreenPos(bool, bool);
    void RotateAndScaleCornerBonesToPointToRestOfCar(bool);
    unsigned char pad_0[0x14];
    UnkStruct_003E0B10_14 * field_14;
    UnkStruct_003E0B10_18 * field_18;
};

// [L] N185: operator+(YAxisType, float) (as the header's operator-(YAxisType, float), `vaddx.y`)
static inline YAxisType func_003E0B10_inl1(const YAxisType &a, float f)
{
    u_long128 s;
    u_long128 r = a.lVector;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vaddx.y %0, %0, %1x" : "+j"(r) : "j"(s));
    return YAxisType(r);
}
// [L] N185: CGtV3d subtract on compiler-chosen registers
static inline CGtV3d func_003E0B10_inl2(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
// [L] N185: CGtMatrix3x4 product (no header API): each row of b through a's 3x3 (vmulax/vmadday/vmaddz), the position row
// with vmaddaz + vmaddw of a.mPos; rows out through GPRs
static inline CGtMatrix3x4 func_003E0B10_inl3(const CGtMatrix3x4 &a, const CGtMatrix3x4 &b)
{
    CGtMatrix3x4 r;
    u_long128 t, a1, a2;
    asm("qmtc2.ni %1, %0" : "=j"(a1) : "r"(a.mUp.mData));
    asm("qmtc2.ni %1, %0" : "=j"(a2) : "r"(a.mAt.mData));
    asm("vmulax.xyz $ACC, %1, %4x" "\n\t" "vmadday.xyz $ACC, %2, %4y" "\n\t" "vmaddz.xyz $vf1, %3, %4z" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(t) : "j"(a.mRight.mData), "j"(a1), "j"(a2), "j"(b.mRight.mData));
    r.mRight.mData = t;
    asm("vmulax.xyz $ACC, %1, %4x" "\n\t" "vmadday.xyz $ACC, %2, %4y" "\n\t" "vmaddz.xyz $vf1, %3, %4z" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(t) : "j"(a.mRight.mData), "j"(a1), "j"(a2), "j"(b.mUp.mData));
    r.mUp.mData = t;
    asm("vmulax.xyz $ACC, %1, %4x" "\n\t" "vmadday.xyz $ACC, %2, %4y" "\n\t" "vmaddz.xyz $vf1, %3, %4z" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(t) : "j"(a.mRight.mData), "j"(a1), "j"(a2), "j"(b.mAt.mData));
    r.mAt.mData = t;
    asm("vmulax.xyz $ACC, %1, %4x" "\n\t" "vmadday.xyz $ACC, %2, %4y" "\n\t" "vmaddaz.xyz $ACC, %3, %4z" "\n\t" "qmtc2.i %5, $vf1" "\n\t"
        "vmaddw.xyz $vf1, $vf1, $vf0w" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(t) : "j"(a.mRight.mData), "j"(a1), "j"(a2), "j"(b.mPos.mData), "r"(a.mPos.mData));
    r.mPos.mData = t;
    return r;
}
// [L] N185: CrossProduct with the result moved out .i (retail keeps qmfc2.ni + sq for the stored rows)
static inline CGtV3d func_003E0B10_inl4(CGtV3d a, CGtV3d b) {
    u_long128 t;
    asm("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b.mData) : "j"(a.mData));
    return CGtV3d(t);
}

// 0x003E0B10
void CB3VehicleDeform::RotateAndScaleCornerBonesToPointToRestOfCar(bool flag)
{
    UnkEnum_003E0B10 e;
    if (flag)
        e = (UnkEnum_003E0B10)4;
    else
        e = (UnkEnum_003E0B10)1;
    int idx = e;
    CGtV3d ws;
    ws = GetWindscreenPos(flag, false);
    for (int i = 0; i < 2; i++) {
        CGtV3d d;
        float y;
        if ((flag && i == 0) || (!flag && i == 1)) {
            d = func_003E0B10_inl2(field_14->field_700[idx].mPos, ws);
            y = GetWindscreenPos(flag, true).Y() - field_18->field_70[idx].mPos.Y();
        } else {
            d = func_003E0B10_inl2(ws, field_14->field_700[idx].mPos);
            y = field_18->field_70[idx].mPos.Y() - GetWindscreenPos(flag, true).Y();
        }
        CGtV3d u = d;
        u.SetY(func_003E0B10_inl1(d.Y(), y));
        u.SetX(0.0f);
        XAxisType l = u.GetLength();
        if (((unsigned long)l.lVector & 0x7F800000) <= 0x37800000)
            return;
        float len = l;
        float s = len / (float)func_003E0B10_inl2(field_18->field_70[idx].mPos, GetWindscreenPos(flag, true)).GetLength();  // [C] retail FPU form, not a VU lane op: 0x3E0CE4 div.s (the cast keeps the port's PS2 float model)
        u.Normalise();
        CGtV3d n = u * s;
        if (s > 0.2f)
            field_14->field_700[idx].mRight = n;
        field_14->field_700[idx].mUp = func_003E0B10_inl4(field_14->field_700[idx].mAt, field_14->field_700[idx].mRight);
        field_14->field_700[idx].mUp.Normalise();
        field_14->field_700[idx].mAt = func_003E0B10_inl4(field_14->field_700[idx].mRight, field_14->field_700[idx].mUp);
        field_14->field_700[idx].mAt.Normalise();
        field_14->field_500[idx] = func_003E0B10_inl3(field_14->field_700[idx], field_18->field_570[idx]);
        idx = kaeOtherMainBone[idx];
    }
}



