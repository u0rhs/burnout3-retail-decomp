// CB3EffectsManager::DoVehicleSteam(CB3VehiclePhysics*,float,const CB3EffectsManager::CLighting&) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EffectsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (stabs2: Revenge locals + SpawnParticlesFromPoint parameter order + point-first TransformPoint stand-in).

// stabs2: Revenge locals in order (lCarMatrix, lpEffectsPoint, lrNumParticles, count, mask, bit), callee declared in
// Revenge SpawnParticlesFromPoint's parameter order, TransformPoint stand-in with the point first; psweep pragma dropped.
// Hand-written (ghvu3, Ghidra draft); the lifter refused it. One steam emitter per enabled bit of the vehicle's damage
// mask: each emitter point (stride 0x30) moved to world space with a copy of the body matrix, then func_0025EA70.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_0025FCF0_pt { CGtV3d field_0; unsigned char pad_10[0x20]; };
struct UnkStruct_0025FCF0_m { unsigned char pad_0[0x168C]; UnkStruct_0025FCF0_pt *field_168C; unsigned char pad_1690[0x26]; unsigned char field_16B6; };
struct UnkStruct_0025FCF0_b { CGtMatrix3x4 field_0; UnkStruct_0025FCF0_m *field_40; };
struct UnkStruct_0025FCF0_p { unsigned char pad_0[0x1016]; unsigned char field_1016; };
class CB3VehiclePhysics {
public:
    unsigned char pad_0[0xCC0];
    UnkStruct_0025FCF0_b *field_CC0;
    UnkStruct_0025FCF0_p *field_CC4;
};
struct UnkStruct_D_004C9CD0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004C9CD0 D_004C9CD0;
extern unsigned char D_004E29F0;   // [L] lu8SteamAccumulator$36330 (symbol_addrs, medium; Revenge: function-local static RwUInt8) -- extern until a C-side .sbss static can be wired in
class CB3EffectsManager {
public:
    class CLighting;
    void DoVehicleSteam(CB3VehiclePhysics *v, float f, const CLighting &l);
    unsigned char pad_0[0x1F84C];
    float field_1F84C;
};
// [L] parameter order from Revenge CB4EffectsManager::SpawnParticlesFromPoint (pos, velocity A/B, spawn type, number,
// lighting, alpha, accumulator, destroy-old, crash-related; research/stabs): matches retail a1..t3, stack, f12/f13 here
extern "C" void func_0025EA70(CB3EffectsManager *, const CGtV3d *, const void *, const void *, int, float, const CB3EffectsManager::CLighting &, float, void *, bool, bool);
// [G] N140 pad: retail's frame has two dead 16-byte slots below pos
struct UnkStruct_0025FCF0_pad { int x[8]; UnkStruct_0025FCF0_pad() {} ~UnkStruct_0025FCF0_pad() {} };
// [L] N185: stands in for GtMathPs2::TransformPoint(const CGtMatrix3x4&, CGtV3d) with the point as the first "j" operand
// (retail loads the point before the matrix row here; the header lists the row first -- header lead, stabs2)
static inline CGtV3d func_0025FCF0_inl1(const CGtMatrix3x4& m, CGtV3d v) {
    u_long128 t;
    asm(".set noreorder" "\n\t" "vmulax.xyz $ACC, %2, %1x" "\n\t" "qmtc2.i %3, $vf1" "\n\t" "vmadday.xyz $ACC, $vf1, %1y" "\n\t" "qmtc2.i %4, $vf1" "\n\t"
        "vmaddaz.xyz $ACC, $vf1, %1z" "\n\t" "qmtc2.i %5, $vf1" "\n\t" "vmaddw.xyz $vf1, $vf1, $vf0w" "\n\t" "qmfc2.i %0, $vf1" "\n\t" ".set reorder"
        : "=r"(t) : "j"(v.mData), "j"(m.mRight.mData), "r"(m.mUp.mData), "r"(m.mAt.mData), "r"(m.mPos.mData));
    return CGtV3d(t);
}
// 0x0025FCF0
void CB3EffectsManager::DoVehicleSteam(CB3VehiclePhysics *v, float f, const CLighting &l)
{
    CGtMatrix3x4 m = v->field_CC0->field_0;
    UnkStruct_0025FCF0_pt *p = v->field_CC0->field_40->field_168C;
    float scale = 9.869999886f * field_1F84C;
    unsigned char n = v->field_CC0->field_40->field_16B6;
    unsigned char mask = v->field_CC4->field_1016;
    unsigned char bit = 1;
    while (n--) {
        if (mask & bit) {
            CGtV3d pos = func_0025FCF0_inl1(m, p->field_0);
            UnkStruct_0025FCF0_pad pad;
            func_0025EA70(this, &pos, &D_004C9CD0, &D_004C9CD0, 11, scale, l, f, &D_004E29F0, false, true);
        }
        bit += bit;
        p++;
    }
}
