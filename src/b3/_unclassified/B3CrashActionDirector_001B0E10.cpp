// CB3CrashActionDirector::DebugCrashEffect(CB3RaceCarPhysics*,CGtAxisAlignedBox*,GtMathPs2::CGtMatrix3x4*,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashActionDirector.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ghvu12: Ghidra draft; jtbl switch; N129 address-read lane stand-ins (6 dead slots), subtrahend-first params, point built in a copy of p then TransformPoint).

// CB3CrashActionDirector::DebugCrashEffect(CB3RaceCarPhysics*,CGtAxisAlignedBox*,CGtMatrix3x4*,unsigned int) -- hand-written
// (ghvu12) from the Ghidra draft. [C] name: the mangled symbol in retail's tables. Field names are placeholders, every type
// is [G]. [G] meaning: a debug switch on the director's mode (field_8): modes 1-5 apply a crash impulse pair through
// func_001CC520 with a per-mode strength, mode 6 applies a ramp at the box's transformed base with the box size.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3RaceCarPhysics;
struct CGtAxisAlignedBox { CGtV3d field_0; CGtV3d field_10; };
extern "C" void func_001CC520(void *, int, int, float);
extern "C" void ApplyRamp__17CB3VehiclePhysicsFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(void *, const CGtV3d *, const CGtV3d *, const CGtV3d *);

// [L] N185: XAxisType/YAxisType lane subtracts and a z-from-x lane setter on compiler-chosen registers stand-ins, their
// by-value arguments read through their addresses (N129: retail's six dead frame slots); the subtracts take the
// subtrahend first so the minuend is evaluated (loaded) first
static inline XAxisType func_001B0E10_inl1(XAxisType b, XAxisType a) { u_long128 r; asm("vsubx.x %0, %1, %2x" : "=j"(r) : "j"(*(const u_long128 *)&a.lVector), "j"(*(const u_long128 *)&b.lVector)); return XAxisType(r); }
static inline YAxisType func_001B0E10_inl2(YAxisType b, YAxisType a) { u_long128 r; asm("vsuby.y %0, %1, %2y" : "=j"(r) : "j"(*(const u_long128 *)&a.lVector), "j"(*(const u_long128 *)&b.lVector)); return YAxisType(r); }
static inline void func_001B0E10_inl3(CGtV3d &v, XAxisType a) { asm("vaddx.z %0, $vf0, %1x" : "+j"(v.mData) : "j"(*(const u_long128 *)&a.lVector)); }

class CB3CrashActionDirector {
public:
    bool DebugCrashEffect(CB3RaceCarPhysics *phys, CGtAxisAlignedBox *box, CGtMatrix3x4 *m, unsigned int flags);
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x570];
    float field_57C;
    float field_580;
    float field_584;
    float field_588;
    float field_58C;
};

// 0x001B0E10
bool CB3CrashActionDirector::DebugCrashEffect(CB3RaceCarPhysics *phys, CGtAxisAlignedBox *box, CGtMatrix3x4 *m, unsigned int flags)
{
    switch (field_8) {
    case 1: {
        float f = field_57C;
        func_001CC520(phys, flags | 1, 0, f);
        func_001CC520(phys, 0x10, 0, f);
        break;
    }
    case 2: {
        float f = field_580;
        func_001CC520(phys, flags | 2, 0, f);
        func_001CC520(phys, 0x10, 0, f);
        break;
    }
    case 3: {
        float f = field_584;
        func_001CC520(phys, flags, 0, f);
        func_001CC520(phys, 0x10, 0, f);
        break;
    }
    case 4: {
        float f = field_588;
        func_001CC520(phys, 1, 0, f);
        func_001CC520(phys, 0x10, 0, f);
        break;
    }
    case 5: {
        float f = field_58C;
        func_001CC520(phys, 2, 0, f);
        func_001CC520(phys, 0x10, 0, f);
        break;
    }
    case 6: {
        CGtV3d s;
        CGtV3d p;
        s.SetX(func_001B0E10_inl1(box->field_10.X(), box->field_0.X()));
        s.SetY(func_001B0E10_inl2(box->field_10.Y(), box->field_0.Y()));
        func_001B0E10_inl3(s, s.X());
        XAxisType z = box->field_0.X();
        // [G] the point is built in a copy of p (retail loads p's slot first), stored to p, then transformed from the copy:
        // only this shape keeps retail's store of p and the transform reading the register value
        CGtV3d q = p;
        q.SetX(0.0f);
        q.SetY(0.0f);
        func_001B0E10_inl3(q, z);
        p = q;
        p = TransformPoint(*m, q);
        ApplyRamp__17CB3VehiclePhysicsFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(phys, &p, &m->mAt, &s);
        break;
    }
    default:
        return false;
    }
    return true;
}
