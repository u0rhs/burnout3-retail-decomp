// CB3AIAvoidanceMap::CheckTraffic() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAvoidance.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ghvu3: Ghidra draft; top-tested goto loop, &D_00527440 const base, per-path ext, int flag inline, CheckVehicle via mangled extern with the CGtV3d as a pointer [G]).

// Hand-written (ghvu3, Ghidra draft); the lifter refused it. Every traffic vehicle in the owner's zone list: its
// parameter block (or its trailer's), the model's half extents scaled by the parameter's scale, then CheckVehicle
// unless flag 2 of field_174 is set.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_0013ED50_prm { unsigned char pad_0[0x2C]; float field_2C; unsigned char pad_30[0x19]; unsigned char field_49; };
struct UnkStruct_0013ED50_tv;
struct UnkStruct_0013ED50_mdl { unsigned char pad_0[0xE80]; unsigned char field_E80[0x10]; };
struct UnkStruct_0013ED50_tv {
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;
    UnkStruct_0013ED50_mdl *field_B0;
    unsigned char pad_B4[0x58];
    UnkStruct_0013ED50_tv *field_10C;
    unsigned char pad_110[4];
    UnkStruct_0013ED50_prm *field_114;
    unsigned char pad_118[0x5C];
    unsigned char field_174;
    unsigned char pad_175[0xB];
};
struct UnkStruct_D_00527440 {
    unsigned char pad_0[0x127D0];
    UnkStruct_0013ED50_tv field_127D0[1];
    unsigned char pad_12950[0x36218 - 0x12950];
    unsigned char field_36218[10][25];
    unsigned char pad_36312[0x36356 - 0x36312];
    unsigned char field_36356[10];
};
struct UnkStruct_0013ED50_ext { CGtV3d field_0; unsigned char pad_10[0x40]; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x34230]; UnkStruct_0013ED50_ext field_34230[1]; };
extern UnkStruct_D_00527440 D_00527440;
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_0013ED50_own { unsigned char pad_0[0x19AC]; signed char field_19AC; };
class CGtAxisAlignedBox;
enum EAIAvoidanceRisk {};
class CB3AIAvoidanceMap {
public:
    void CheckTraffic();
    void CheckVehicle(const CGtMatrix3x4 &, CGtV3d, bool, bool, EAIAvoidanceRisk, const CGtAxisAlignedBox &);
    unsigned char pad_0[0x454];
    UnkStruct_0013ED50_own *field_454;
};
// [G] a flag test written as an int-returning inline (retail materialises it: andi 2; sltu; bnez)
static inline int func_0013ED50_inl1(const UnkStruct_0013ED50_tv *t) { return (t->field_174 & 2) != 0; }
// [G] CheckVehicle called through its mangled symbol with the CGtV3d argument as a pointer: retail passes ext's own stack slot
// (no by-value copy; the EABI passes a by-value CGtV3d as a pointer to the caller's object), which the member call cannot give
extern "C" void CheckVehicle__17CB3AIAvoidanceMapFRCQ29GtMathPs212CGtMatrix3x4Q29GtMathPs26CGtV3dbb16EAIAvoidanceRiskRC17CGtAxisAlignedBox(CB3AIAvoidanceMap *, const CGtMatrix3x4 &, const CGtV3d *, bool, bool, EAIAvoidanceRisk, const CGtAxisAlignedBox &);
// 0x0013ED50
void CB3AIAvoidanceMap::CheckTraffic()
{
    UnkStruct_D_00527440 * const ts = &D_00527440;
    int i = 0;
top:
    if (!(i < ts->field_36356[field_454->field_19AC]))
        return;
    {
        UnkStruct_0013ED50_tv *t = &ts->field_127D0[ts->field_36218[field_454->field_19AC][i]];
        CGtV3d ext;
        if (t->field_114 != 0) {
            ext = D_00522660.field_34230[t->field_114->field_49].field_0 * t->field_114->field_2C;
        } else {
            if (t->field_10C == 0 || t->field_10C->field_114 == 0)
                goto next;
            UnkStruct_0013ED50_prm *p = t->field_10C->field_114;
            ext = D_00522660.field_34230[p->field_49].field_0 * p->field_2C;
        }
        if (!func_0013ED50_inl1(t))
            CheckVehicle__17CB3AIAvoidanceMapFRCQ29GtMathPs212CGtMatrix3x4Q29GtMathPs26CGtV3dbb16EAIAvoidanceRiskRC17CGtAxisAlignedBox(this, t->field_70, &ext, false, false, (EAIAvoidanceRisk)4, *(const CGtAxisAlignedBox *)t->field_B0->field_E80);
    }
next:
    i++;
    goto top;
}
