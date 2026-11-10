// CB3AILane::GetAvgLeftwardsVector(unsigned short,GtMathPs2::CGtV3d*) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (fold: cross result qmfc2 written .i (opaque to MWCC copy modelling, fixup -> .ni) keeps retail's sq).


#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
extern u_long128 kYAxis;
class CB3AILane {
public:
    void GetAvgForwardsVector(unsigned short, CGtV3d *) const;
    void GetAvgLeftwardsVector(unsigned short, CGtV3d *) const;
};
static inline void func_a187_cross(CGtV3d *o, u_long128 a, u_long128 b)
{
    u_long128 t;
    asm volatile("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b) : "j"(a));
    o->mData = t;
}
// 0x00147E90
void CB3AILane::GetAvgLeftwardsVector(unsigned short s, CGtV3d *out) const
{
    CGtV3d f;
    GetAvgForwardsVector(s, &f);
    func_a187_cross(out, kYAxis, f.mData);
}
