// CDrawnTrafficCache::TestPosition(GtMathPs2::CGtV3d) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficSystemLoadAndRender.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a213: CGtV3d pc=p copy + *(u_long128*)&pc as vf2 operand; separate asm lqc2 $vf1 row0 before r1/r2 loads (frees s reg); element-pointer return).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_00309300_pl {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
};
class CDrawnTrafficCache {
public:
    int TestPosition(CGtV3d p);
    unsigned char pad_0[0x7D0];
    UnkStruct_00309300_pl field_7D0[1];
};
class CDrawnTrafficCacheX;
// 0x00309300
int CDrawnTrafficCache::TestPosition(CGtV3d p)
{
    int n = *(int *)((char *)this + 0x9B0);
    CGtV3d pc = p;
    int i;
    for (i = 0; i < n; i++) {
        UnkStruct_00309300_pl *s = &field_7D0[i];
        u_long128 v, m;
        unsigned long any;
        asm volatile("lqc2 $vf1, 0(%0)" :: "r"(s));
        u_long128 r1 = s->field_10;
        u_long128 r2 = s->field_20;
        asm("vmulax.xyzw $ACC, $vf1, %4x\n\tqmtc2.ni %2, $vf1\n\tvmaddaz.xyzw $ACC, $vf1, %4z\n\tqmtc2.ni %3, $vf1\n\tvmsubw.xyzw $vf1, $vf1, $vf0w\n\tqmfc2.ni %0, $vf1"
            : "=r"(v) : "r"(0), "r"(r1), "r"(r2), "j"(*(u_long128 *)&pc), "r"(s));
        asm("psraw %0, %1, 31" : "=r"(m) : "r"(v));
        asm("pcpyud %0, %1, $0\n\tor %0, %1, %0" : "=r"(any) : "r"(m));
        if (any == 0) goto found;
    }
    return -1;
found:
    return ((int *)((char *)this + 0x980))[i];
}
