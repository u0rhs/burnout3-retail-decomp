// GtMathPs2::CGtV3d::GetSquaredLength() const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BehaviourFlyAround.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (out-of-line copy: local minimal CGtV3d/XAxisType (no header) + header's GetSquaredLength asm body as non-inline member).

typedef unsigned int u_long128 __attribute__((mode(TI)));
namespace GtMathPs2 {
struct XAxisType {
    u_long128 lVector;
    XAxisType() {}
    XAxisType(u_long128 v) { lVector = v; }
};
struct CGtV3d {
    u_long128 mData;
    XAxisType GetSquaredLength() const;
};
#pragma push
#pragma peephole off
// 0x002ED2C0
XAxisType CGtV3d::GetSquaredLength() const {
    u_long128 one, sq, t;
    asm("lqc2 $vf2, 0(%2)" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "vmul.xyz $vf2, $vf2, $vf2" "\n\t"
        "qmfc2 %0, $vf2" "\n\t" "qmfc2 %1, $vf1" : "=r"(sq), "=r"(one) : "r"(this));
    asm volatile("qmtc2 %1, $vf2" "\n\t" "vadday.x $ACC, $vf2, $vf2y" "\n\t" "qmtc2 %2, $vf1" "\n\t"
                 "vmaddz.x $vf1, $vf1, $vf2z" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(sq), "r"(one));
    return XAxisType(t);
}
#pragma pop
}
