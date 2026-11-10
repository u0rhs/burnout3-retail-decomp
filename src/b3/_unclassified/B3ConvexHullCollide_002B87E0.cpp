// CB3ConvexHullCollide::BuildClippedEdgeList(GtMathPs2::CGtV3d*,unsigned int*,GtMathPs2::CGtV3d,const CB3ConvexHull*,GtMathPs2::CGtV3d*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ConvexHullCollide.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (fold: .set noreorder region around the result qmfc2.ni keeps it unforwarded and in asm order; plane copied to a u_long128 local before the loop gives retail's zero-trip guard (lq and qmtc2.ni in different blocks); vertex via qmtc2 $vf1 folds to lqc2 $vf1 as in retail).


#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
namespace GtMathPs2 {
}
struct CB3ConvexHull {
    unsigned char pad_0[8];
    CGtV3d *field_8;
    unsigned char (*field_C)[2];
    unsigned char pad_10[8];
    unsigned char field_18;
    unsigned char pad_19;
    unsigned char field_1A;
};
class CB3ConvexHullCollide { public:
static void BuildClippedEdgeList(CGtV3d *out, unsigned *n, CGtV3d pl, const CB3ConvexHull *h, CGtV3d *vtx);
};
// 0x002B87E0
void CB3ConvexHullCollide::BuildClippedEdgeList(CGtV3d *out, unsigned *n, CGtV3d pl, const CB3ConvexHull *h, CGtV3d *vtx)
{
    float d[28];
    unsigned char i;
    u_long128 pv = pl.mData;
    for (i = 0; i < h->field_18; i++) {
        d[i] = DotProduct(CGtV3d(pv), h->field_8[i]);
    }
    *n = 0;
    for (i = 0; i < h->field_1A; i++) {
        unsigned char a = h->field_C[i][0];
        unsigned char b = h->field_C[i][1];
        if (d[a] < 0.0f) continue;
        if (d[b] < 0.0f) continue;
        out[(*n)++] = vtx[a];
        out[(*n)++] = vtx[b];
    }
}
