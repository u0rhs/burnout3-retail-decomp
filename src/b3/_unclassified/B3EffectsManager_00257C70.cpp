// CB3EffectsManager::UpdateVehicleFireTrail(CB3VehiclePhysics*,const CB3EffectsManager::CLighting&) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EffectsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ghvu4: goto into the scope of constructed locals (ill-formed C++ that MWCC accepts; [G] N233)).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00257C70_inst { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_00257C70_st { unsigned char pad_0[0x1000]; CGtV4d field_1000; };
class CB3VehiclePhysics {
public:
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;
    unsigned char pad_C0[0xC00];
    UnkStruct_00257C70_inst * field_CC0;
    UnkStruct_00257C70_st * field_CC4;
};
extern int D_0049BB30[];
extern unsigned char D_004E29FC[3];
extern float D_004E0C50;
extern float D_004E1270;
class CB3EffectsManager;
extern "C" void func_0025F0C0(CB3EffectsManager *, const void *, const void *, const void *, int, const void *, unsigned char *, int, float, float, float, int);  // signature as UpdateExplosionTrails' archive; retail stores the 9th int (sd 1 at sp+0)
class CB3EffectsManager {
public:
    class CLighting;
    void UpdateVehicleFireTrail(CB3VehiclePhysics *, const CLighting &);
    unsigned char pad_0[0x1F848];
    float field_1F848;
    float field_1F84C;
};
// [L] N185: stands in for a missing GtMathPs2 operator-(float, WAxisType) (retail `qmtc2.ni f,$vf2; vsubw.x $vf1,$vf2,$vf1w`)
static inline XAxisType func_00257C70_inl1(float f, WAxisType w)
{
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vsubw.x %0, %1, %2w" : "=j"(r) : "j"(s), "j"(w.lVector));
    return XAxisType(r);
}

// [G] N140 frame pads: retail's frame keeps three unused 16-byte slots below the vectors.
struct UnkStruct_00257C70_pad { int x[4]; UnkStruct_00257C70_pad() {} ~UnkStruct_00257C70_pad() {} };
// [L] N185: compiler-chosen vsub.xyz (the header operator- hard-codes $vf1/$vf2; retail `vsub.xyz $vf1,$vf3,$vf1`)
static inline CGtV3d func_00257C70_inl2(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }

// 0x00257C70
void CB3EffectsManager::UpdateVehicleFireTrail(CB3VehiclePhysics * veh, const CLighting & light)
{
    float t = func_00257C70_inl1(field_1F848, veh->field_CC4->field_1000.W());
    if (t < 5.0f) {
        float len;
        float a;
        // [G] goto form: retail keeps the a = 1.0f arm out of line after the epilogue path (a67/a71 shape).
        // NOTE: `goto one` lands inside the scope of p/pos/vel/q0-q2 (ill-formed C++: they have constructors); MWCC b119p
        // accepts it silently. Valid rewrites (declarations hoisted, the tail in a block or an inline) put the arm back inline.
        if (t < 2.5f) goto one;
        a = 1.0f - D_004E1270 * ((t - 2.5f) * D_004E0C50);
join:
        CGtV3d p;
        CGtV3d pos = veh->field_CC0->field_30;
        CGtV3d vel = *(const CGtV3d *)&veh->field_B0;
        UnkStruct_00257C70_pad q0;
        UnkStruct_00257C70_pad q1;
        UnkStruct_00257C70_pad q2;
        p = func_00257C70_inl2(pos, vel * field_1F84C);
        len = field_1F84C * veh->field_B0.W();
        for (int i = 0; i < 3; i++) {
            func_0025F0C0(this, &p, &pos, &vel, D_0049BB30[i], &light, &D_004E29FC[i], 1, len, a, a, 1);
        }
        return;
    one:
        a = 1.0f;
        goto join;
    }
}
