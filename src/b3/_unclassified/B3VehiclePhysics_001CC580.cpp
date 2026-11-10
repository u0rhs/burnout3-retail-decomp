// CB3VehiclePhysics::FireAirRamWithDirection(unsigned int,float,GtMathPs2::CGtV3d,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehiclePhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ghvu13: Ghidra draft; N185 lane-op stand-ins, p=pos copy, 20 N140 16-byte pads for the 0x360 frame).

// CB3VehiclePhysics::FireAirRamWithDirection(unsigned int, float, CGtV3d, bool) -- hand-written by ghvu13 from the Ghidra draft.
// [C] name: the mangled symbol in retail's tables. Field names are placeholders and every type is [G].
// ghvu13: straight-line lane code; [L] N185 stand-ins for the missing lane operators (unary - on X with retail's $vf1 -> $vf2,
// CGtV3d * X/Y/Z lane, CrossProduct in place, Set(f,f,f) with the scalar on $vf2); `CGtV3d p = pos;` before the field_110
// update gives retail's early pos load; 20 N140 16-byte pads (one between imp and spin, seven below spin, twelve in the cross
// inline) stand in for retail's dead frame slots (frame 0x360).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_001CC580_m { CGtV3d field_0; CGtV3d field_10; CGtV3d field_20; CGtV3d field_30; };
struct UnkStruct_001CC580_cc4 {
    unsigned char pad_0[0xFF0];
    CGtV3dPlus field_FF0;
    unsigned char pad_1000[0x15];
    unsigned char field_1015;
};
struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522680 D_00522680;
extern float D_004E1704;
extern float D_004E1708;
extern unsigned char D_01E78510[];
extern "C" void AirRam__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3dfb(void *, const void *, float, bool);

class CB3VehiclePhysics {
public:
    void FireAirRamWithDirection(unsigned int flags, float f, CGtV3d dir, bool b);

    unsigned char pad_0[0x110];
    CGtV3d field_110;
    CGtV3d field_120;
    unsigned char pad_130[0xA0];
    CGtV3d field_1D0;
    CGtV3d field_1E0;
    float field_1F0;
    unsigned char pad_1F4[0x10];
    UnkStruct_001CC580_m *field_204;
    unsigned char pad_208[6];
    unsigned char field_20E;
    unsigned char pad_20F[6];
    signed char field_215;
    unsigned char pad_216[0xCC4 - 0x216];
    UnkStruct_001CC580_cc4 *field_CC4;
};

// [L] N185: stand-ins for missing GtMathPs2 lane operators (XAxisType unary - hard-coded $vf1 -> $vf2 as retail; the products compiler-chosen).
static inline XAxisType func_001CC580_inl1(XAxisType a) { u_long128 r; asm("qmtc2 %1, $vf1" "\n\t" "vsub.x $vf2, $vf0, $vf1" "\n\t" "qmfc2 %0, $vf2" : "=r"(r) : "r"(a.lVector)); return XAxisType(r); }
static inline CGtV3d func_001CC580_inl2(CGtV3d v, XAxisType a) { u_long128 r; asm("vmulx.xyz %0, %1, %2x" : "=j"(r) : "j"(v.mData), "j"(a.lVector)); return CGtV3d(r); }
static inline CGtV3d func_001CC580_inl3(CGtV3d v, YAxisType a) { asm("vmuly.xyz %0, %0, %1y" : "+j"(v.mData) : "j"(a.lVector)); return v; }
static inline CGtV3d func_001CC580_inl4(CGtV3d v, ZAxisType a) { u_long128 r; asm("vmulz.xyz %0, %1, %2z" : "=j"(r) : "j"(v.mData), "j"(a.lVector)); return CGtV3d(r); }
// N140 [G]: 16-byte frame pads standing in for retail's 20 dead slots (inline temporaries b119 drops).
struct UnkStruct_001CC580_pad { int x[4]; UnkStruct_001CC580_pad() {} ~UnkStruct_001CC580_pad() {} };

// [L] N185: CrossProduct on compiler-chosen registers, the result in place on the first operand, moved out .i (N190).
static inline CGtV3d func_001CC580_inl5(CGtV3d a, CGtV3d b)
{
    UnkStruct_001CC580_pad c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11;  // N140 [G]
    u_long128 t;
    asm("vopmula.xyz $ACC, %1, %2" "\n\t" "vopmsub.xyz %1, %2, %1" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(a.mData) : "j"(b.mData));
    return CGtV3d(t);
}

// [L] N185: Set(f, f, f) with the scalar moved into a hard-coded $vf2 (the header's three "=j" scalars land on $vf3 here).
static inline void func_001CC580_inl6(CGtV3d &v, float f)
{
    asm("qmtc2.ni %1, $vf2" "\n\t" "vaddx.x %0, $vf0, $vf2x" "\n\t" "vaddx.y %0, $vf0, $vf2x" "\n\t" "vaddx.z %0, $vf0, $vf2x" : "+j"(v.mData) : "r"(f));
}

// 0x001CC580
void CB3VehiclePhysics::FireAirRamWithDirection(unsigned int flags, float f, CGtV3d dir, bool b)
{
    CGtV3d d = dir;
    CGtV3d pos = field_204->field_30;
    CGtV3d imp;
    UnkStruct_001CC580_pad a0;  // N140 [G]
    CGtV3d spin;
    UnkStruct_001CC580_pad b0, b1, b2, b3, b4, b5, b6;  // N140 [G]
    func_001CC580_inl6(spin, 0.0f);
    if (flags & 8) {
        pos += func_001CC580_inl2(field_204->field_0, func_001CC580_inl1(field_1D0.X()));
        spin.SetX(func_001CC580_inl1(field_1D0.X()) * 0.9f);
    } else if (flags & 4) {
        pos += func_001CC580_inl2(field_204->field_0, func_001CC580_inl1(field_1E0.X()));
        spin.SetX(func_001CC580_inl1(field_1E0.X()) * 0.9f);
    }
    if ((flags & 1) || (flags & 0x20)) {
        f *= D_004E1708;
        pos += func_001CC580_inl4(field_204->field_20, field_1D0.Z());
        spin.SetZ(field_1D0.Z() * 0.9f);
    } else if ((flags & 2) || (flags & 0x40)) {
        f *= D_004E1708;
        pos += func_001CC580_inl4(field_204->field_20, field_1E0.Z());
        spin.SetZ(field_1E0.Z() * 0.9f);
    }
    if (field_204->field_10.Y() < 0.0f) {
        pos += func_001CC580_inl3(field_204->field_10, field_1D0.Y()) * 0.8f;
    }
    imp = d * D_004E1704 * field_1F0 * f;
    if (!(flags & 0x40) && !(flags & 0x20) && !(flags & 0x80)) {
        spin.Set(0.0f, 1.0f, 0.0f);
        field_CC4->field_1015 |= 6;
    } else {
        spin.Set(1.0f, 0.0f, 0.0f);
    }
    if (!(flags & 0x10) && !(flags & 0x80)) {
        CGtV3d old = field_110;
        CGtV3d p = pos;
        field_110 += imp;
        field_120 += func_001CC580_inl5(p - field_204->field_30, imp);
        field_110 = old;
    } else {
        field_110 += imp;
    }
    field_CC4->field_FF0.SetGtV3d(spin);
    field_CC4->field_FF0.SetPlus(D_00522680.field_0);
    field_20E = 0;
    AirRam__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3dfb(D_01E78510, &pos, f, field_215 == 1);
}
