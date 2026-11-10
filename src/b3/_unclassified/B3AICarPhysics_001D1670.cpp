// CB3AICarPhysics::UpdateStickySpeedMatch() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AICarPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3AICarPhysics has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].
// Hand-finished from the lifted source (stabs1: Revenge locals (lrFinalSpeed, lDir from an inlined accessor's named copy) fix dir's slot).

// lifter variant 0
// CB3AICarPhysics::UpdateStickySpeedMatch() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AICarPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3AICarPhysics has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].

#include "b3/GtMathPs2.h"

class CB3AICarPhysics;
struct UnkStruct_001D1670_1;
struct UnkStruct_001D1670_2;

struct UnkStruct_001D1670_1 {
    unsigned char pad_0[0x23C8];
    float field_23C8;
};

struct UnkStruct_001D1670_2 {
    unsigned char pad_0[0x20];
    u_long128 field_20;
};


class CB3AICarPhysics {
public:
    void UpdateStickySpeedMatch();

    unsigned char pad_0[0xB0];
    GtMathPs2::CGtV3d field_B0;
    unsigned char pad_C0[0x144];
    UnkStruct_001D1670_2 * field_204;
    unsigned char pad_208[0x7E8];
    float field_9F0;
    unsigned char pad_9F4[0xA98];
    float field_148C;
    float field_1490;
    unsigned char pad_1494[0x8];
    float field_149C;
    float field_14A0;
    int field_14A4;
    unsigned char pad_14A8[0x20];
    int field_14C8;
    unsigned char pad_14CC[0x4];
    float field_14D0;
    float field_14D4;
    unsigned char pad_14D8[0x90];
    UnkStruct_001D1670_1 * field_1568;
};

extern "C" int IsVehicleTouchingHorizontalSurface__17CB3VehiclePhysicsFbf(void *, bool, float);  // CB3VehiclePhysics::IsVehicleTouchingHorizontalSurface(bool,float)
extern "C" void func_001BEEE0(CB3AICarPhysics *, void *);
extern "C" int func_001C6F30(void *, float, float);


// stabs1 (2026-10-30): local shape from Revenge's UpdateStickySpeedMatch__15CB4AICarPhysics (research/stabs, [L]):
// locals lrFinalSpeed, lDir in that order, lDir initialised from an inlined CB4CollidingBody accessor (here a [G]
// placeholder returning a named copy, which supplies retail's extra 16-byte slot); local names are Revenge's [L].
static inline GtMathPs2::CGtV3d func_001D1670_inl1(const CB3AICarPhysics *p) { GtMathPs2::CGtV3d r = p->field_B0; return r; }
// 0x001D1670
void CB3AICarPhysics::UpdateStickySpeedMatch()
{
    GtMathPs2::CGtV3d prod;
    if (IsVehicleTouchingHorizontalSurface__17CB3VehiclePhysicsFbf(this, 1, 30.0f) == 0) return;
    float lrFinalSpeed = field_1568->field_23C8;
    GtMathPs2::CGtV3d lDir = func_001D1670_inl1(this);
    if (lDir.GetSquaredLength() < 2.3283064e-10f) {
        lDir.mData = field_204->field_20;
    } else {
        u_long128 b = lDir.mData;
        GtMathPs2::XAxisType l = lDir.GetSquaredLength();
        asm("qmtc2.i %1, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(b) : "r"(l.lVector));
        asm("qmfc2.i %0, %1" : "=r"(lDir.mData) : "j"(b));
    }
    prod = lDir * lrFinalSpeed;
    func_001BEEE0(this, &prod);
    field_149C = (0.5f * (field_148C + field_1490));
    float t2 = field_9F0;
    field_14C8 = func_001C6F30(((char *)this + 0x1448), t2, ((const GtMathPs2::CGtV4d *)&field_B0)->W()  /* [G] the W() lane read: retail's 16-byte copy at sp+0x30 read at +0xC */);
    field_14D0 = -1.0f;
    field_14D4 = 1.0f;
    field_14A0 = -1.0f;
    field_14A4 = 0;
}
