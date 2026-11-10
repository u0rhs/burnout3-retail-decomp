// CB3NetworkCarPhysics::WeWantToDoPhysics() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkCarPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ghvu1: header GetSquaredLength + operator-; vfunc_1C via cast of D_0064D3B0 (vptr at 0x1910); bool b = !(x != 0) for sltu/xori).

// CB3NetworkCarPhysics::WeWantToDoPhysics() -- hand-written (ghvu1, Ghidra-draft trial). [C] name: the mangled symbol in
// retail's tables. Classes and structs are declared here with only what this function touches; field names are
// placeholders and every type is [G] (instruction widths).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_00269B70_body { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_00269B70_n { unsigned char pad_0[0x4EFC]; unsigned char field_4EFC; };
struct UnkStruct_00269B70_o {
    unsigned char pad_0[0x1A85];
    bool field_1A85;
    unsigned char pad_1A86[2];
    UnkStruct_00269B70_n *field_1A88;
    unsigned char pad_1A8C[4];
    unsigned char field_1A90;
};
// [G] the object at D_0064D3B0: its vtable pointer sits after 0x1910 bytes of data; slot 0x1C returns a CGtV3d
struct UnkStruct_D_0064D3B0 {
    unsigned char pad_0[0x1910];
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual CGtV3d vfunc_1C();
};
extern unsigned char D_0064D3B0[];
extern unsigned char D_0064C9A8[];
extern "C" int TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(void *, const CGtV3d &);
class CB3NetworkCarPhysics {
public:
    bool WeWantToDoPhysics();
    unsigned char pad_0[0x204];
    UnkStruct_00269B70_body *field_204;
    unsigned char pad_208[0x1348];
    UnkStruct_00269B70_o *field_1550;
    unsigned char field_1554;
};
// 0x00269B70
bool CB3NetworkCarPhysics::WeWantToDoPhysics()
{
    if (TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(D_0064C9A8, field_204->field_30) < 0) return false;
    if (field_1554 != 0) return false;
    const CGtV3d &p = field_204->field_30;
    CGtV3d d = ((UnkStruct_D_0064D3B0 *)D_0064D3B0)->vfunc_1C() - p;
    float d2 = d.GetSquaredLength();
    UnkStruct_00269B70_o *o = field_1550;
    if ((o->field_1A90 != 0 && d2 > 19600) || (o->field_1A90 == 0 && d2 > 15625)) return false;
    bool b = !(o->field_1A88->field_4EFC != 0);
    if (b) return o->field_1A85;
    return false;
}
