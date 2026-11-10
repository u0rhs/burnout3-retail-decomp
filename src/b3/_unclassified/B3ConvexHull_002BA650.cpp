// CB3ConvexHull::MakeConeFromBoundingBox(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ConvexHull.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (dperm (decomp-permuter, background run): const void *pa = &a;; const void *pa = &a;).

#include "b3/GtMathPs2.h"

#pragma push
#pragma opt_propagation off

class CB3ConvexHull;
struct UnkStruct_002BA650_3;
struct UnkStruct_002BA650_4;

struct UnkStruct_002BA650_3 {
    GtMathPs2::CGtV3d field_0;
    GtMathPs2::CGtV3d field_10;
    GtMathPs2::CGtV3d field_20;
    GtMathPs2::CGtV3d field_30;
    GtMathPs2::CGtV3d field_40;
};

struct UnkStruct_002BA650_4 {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
    unsigned char field_4;
    unsigned char field_5;
    unsigned char field_6;
    unsigned char field_7;
    unsigned char field_8;
    unsigned char field_9;
    unsigned char field_A;
    unsigned char field_B;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char field_E;
    unsigned char field_F;
    unsigned char field_10;
    unsigned char field_11;
};

class CB3ConvexHull;
extern "C" void ScaleAndFillInHullDetails__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(CB3ConvexHull *, const void *, const void *);
class CB3ConvexHull {
public:
    void MakeConeFromBoundingBox(GtMathPs2::CGtV3d p0, GtMathPs2::CGtV3d p1);
    void ScaleAndFillInHullDetails(GtMathPs2::CGtV3d, GtMathPs2::CGtV3d);

    UnkStruct_002BA650_4 * field_0;
    unsigned char pad_4[0x4];
    UnkStruct_002BA650_3 * field_8;
    unsigned char pad_C[0xC];
    unsigned char field_18;
    unsigned char field_19;
};





// 0x002BA650
void CB3ConvexHull::MakeConeFromBoundingBox(GtMathPs2::CGtV3d p0, GtMathPs2::CGtV3d p1)
{
  GtMathPs2::CGtV3d a;
  const void *pa = &a;
  GtMathPs2::CGtV3d b;
  const void *pb = &b;
  b = p1;
  a = p0;
  field_8->field_0.Set(0.5f, 1.0f, 0.5f);
  field_8->field_10.Set(0.0f, 0.0f, 0.0f);
  field_8->field_20.Set(1.0f, 0.0f, 0.0f);
  field_8->field_30.Set(1.0f, 0.0f, 1.0f);
  field_8->field_40.Set(0.0f, 0.0f, 1.0f);
  field_18 = 5;
  UnkStruct_002BA650_4 *t0 = field_0;
  t0->field_0 = 1;
  t0->field_1 = 2;
  t0->field_2 = 3;
  UnkStruct_002BA650_4 *t1 = field_0;
  t1->field_3 = 1;
  t1->field_4 = 3;
  t1->field_5 = 4;
  UnkStruct_002BA650_4 *t2 = field_0;
  t2->field_6 = 0;
  t2->field_7 = 2;
  t2->field_8 = 1;
  UnkStruct_002BA650_4 *t3 = field_0;
  t3->field_9 = 0;
  t3->field_A = 3;
  t3->field_B = 2;
  UnkStruct_002BA650_4 *t4 = field_0;
  t4->field_C = 0;
  t4->field_D = 4;
  t4->field_E = 3;
  UnkStruct_002BA650_4 *t5 = field_0;
  t5->field_F = 0;
  t5->field_10 = 1;
  t5->field_11 = 4;
  field_19 = 6;
  ScaleAndFillInHullDetails__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(this, pa, pb);
}





#pragma pop
