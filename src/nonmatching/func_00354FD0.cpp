// NONMATCHING: func_00354FD0 -- retail 72 / ours 72 instructions, 3 in changed runs
// near14: CGtV2d a with SetX/SetY/SetY(0.75f*a.Y()) (gives retail's addiu v1 pointer store) + .lit4 deg->rad literal: 9 -> 3. Left: else-arm div.s operand registers (a.x reload f1 vs f2, field_74 f2 vs f1). draftAL (2026-11-01): LOGIC FIX -- returns the float of its tail call (func_00353C00 / func_00353E10 both return f0; func_003550F0 uses it as the rig score); the older draft returned void; same 72 instrs, 3 changed
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] reviewed by draftAL against the retail asm: both arms' argument lists (a2 = p0+0x70 also to func_00353C00, which overwrites it: kept for call identity), the float return through f0

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// func_00354FD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
class CGtFrustum;
struct UnkStruct_00354FD0;
struct UnkStruct_00354FD0_0;
struct UnkStruct_00354FD0_4;
struct UnkStruct_00354FD0_5;
struct UnkStruct_00354FD0_6;
struct UnkStruct_00354FD0_a1;
struct UnkStruct_D_004E0D60;
struct UnkStruct_00354FD0_0 {
    unsigned char pad_0[0x60];
    float field_60;
    float field_64;
    int field_68;
    int field_6C;
};
struct UnkStruct_00354FD0_a1 {
    unsigned char pad_0[0xB8];
    float field_B8;
};
struct UnkStruct_D_004E0D60 {
    float field_0;
};
struct UnkStruct_00354FD0_4 {
    unsigned char pad_0[0x30];
    UnkStruct_00354FD0_5 * field_30;
};
struct UnkStruct_00354FD0_5 {
    unsigned char pad_0[0x58];
    UnkStruct_00354FD0_6 * field_58;
    unsigned char pad_5C[0x18];
    float field_74;
    unsigned char pad_78[0xC];
    float field_84;
    float field_88;
};
struct UnkStruct_00354FD0_6 {
    unsigned char pad_0[0x68];
    float field_68;
    float field_6C;
};
struct UnkStruct_00354FD0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x8];
    UnkStruct_00354FD0_4 * field_14;
};
extern UnkStruct_D_004E0D60 D_004E0D60;
struct UnkStruct_00354FD0_v2 { float x; float y; };
struct UnkStruct_00354FD0_fr { unsigned char pad_0[0x60]; };
extern "C" void ConstructPerspective__17CGtFrustumBuilderFP10CGtFrustumRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dff(void *, void *, void *, void *, float, float);  // CGtFrustumBuilder::ConstructPerspective(CGtFrustum*,const GtMathPs2::CGtMatrix3x4&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,float,float)
extern "C" float tanf(float);
extern "C" float func_00353C00(int, void *, void *);   // [C] returns f0 (proven B3CrashAnalyser.cpp); a2 unread by the callee, kept for call identity
extern "C" float func_00353E10(int, void *, void *, float);   // [C] returns f0 (proven func_00353E10.cpp)
// draftAL: [C] returns the callee's float (its caller func_003550F0 reads f0 as the rig score); the older draft returned void
extern "C" float func_00354FD0(UnkStruct_00354FD0 * self, UnkStruct_00354FD0_a1 * p0, int p1, int p2)
{
    CGtV2d b;
    CGtV2d a;
    UnkStruct_00354FD0_fr fr;
    b.marValues[0] = 0;
    b.marValues[1] = 0;
    if (p1 == 0) {
        UnkStruct_00354FD0_6 * t2 = self->field_14->field_30->field_58;
        a.SetX(t2->field_68);
        a.SetY(t2->field_6C);
        a.SetY(0.75f * a.Y());
    } else {
        a.marValues[0] = tanf(0.017453292f * (0.5f * p0->field_B8));
        a.marValues[1] = 0.75f * (a.marValues[0] / self->field_14->field_30->field_74);
    }
    ConstructPerspective__17CGtFrustumBuilderFP10CGtFrustumRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dff((CGtFrustum*)&fr, ((char *)p0 + 0x40), &a, &b, self->field_14->field_30->field_84, self->field_14->field_30->field_88);
    float r;
    if (p2 != 0) {
        r = func_00353C00(self->field_8, &fr, ((char *)p0 + 0x70));
    } else {
        r = func_00353E10(self->field_8, &fr, ((char *)p0 + 0x70), a.X());
    }
    return r;
}

