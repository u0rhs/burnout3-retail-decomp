// CB3VehicleDeform::FindPointNearestTo(float,float,float,CB3ConvexHull*,GtMathPs2::CGtV3d*,EMainBodyBoneIndex,GtMathPs2::CGtV3d*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleDeform.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): int n = hull->field_18;; unsigned char n = hull->field_18;).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
using GtMathPs2::XAxisType;

struct UnkStruct_003DA920_h { unsigned char pad_0[0x8]; unsigned char field_8; unsigned char field_9; unsigned char pad_A[2]; };
struct UnkStruct_003DA920_hull { unsigned char pad_0[0x10]; UnkStruct_003DA920_h *field_10; unsigned char pad_14[4]; unsigned char field_18; };
struct UnkStruct_003DA920_b { unsigned char pad_0[0xE80]; CGtV3d field_E80; CGtV3d field_E90; };
struct UnkStruct_003DA920_p { unsigned char pad_0[0x40]; UnkStruct_003DA920_b *field_40; };
struct UnkStruct_003DA920_self { unsigned char pad_0[0x10]; UnkStruct_003DA920_p *field_10; };

extern "C" void NearestPointOnHull__16CB3VehicleDeformFP13CB3ConvexHullPQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3d(UnkStruct_003DA920_hull *, CGtV3d *, const void *, CGtV3d *);

struct UnkStruct_003DA920_pad { unsigned char field_0[0x10]; UnkStruct_003DA920_pad() {} ~UnkStruct_003DA920_pad() {} };

static inline u_long128 func_003DA920_inl1(const CGtV3d *v, const UnkStruct_003DA920_b *b)
{
    u_long128 m;
    u_long128 d;
    asm("vsub.xyz %0, %2, %1" : "=j"(d) : "j"(b->field_E90.mData), "j"(b->field_E80.mData));
    asm("vmul.xyz %0, %1, %2" : "=j"(m) : "j"(v->mData), "j"(d));
    return m;
}
extern "C" void FindPointNearestTo__16CB3VehicleDeformFfffP13CB3ConvexHullPQ29GtMathPs26CGtV3d18EMainBodyBoneIndexPQ29GtMathPs26CGtV3d ( UnkStruct_003DA920_self * self , const CGtV3d * v , UnkStruct_003DA920_hull * hull , CGtV3d * pts , int bone , CGtV3d * out );










void FindPointNearestTo__16CB3VehicleDeformFfffP13CB3ConvexHullPQ29GtMathPs26CGtV3d18EMainBodyBoneIndexPQ29GtMathPs26CGtV3d(UnkStruct_003DA920_self *self, const CGtV3d *v, UnkStruct_003DA920_hull *hull, CGtV3d *pts, int bone, CGtV3d *out)
{
  UnkStruct_003DA920_b *b = self->field_10->field_40;
  u_long128 m = func_003DA920_inl1(v, b);
  u_long128 p;
asm ( "vadd.xyz %0, %1, %2" : "=j" ( p ) : "j" ( b -> field_E90 . mData ) , "j" ( m ) ) ;
  UnkStruct_003DA920_pad pad0;
CGtV3d pos ( p ) ;
  UnkStruct_003DA920_pad pad1;
  UnkStruct_003DA920_pad pad2;
  UnkStruct_003DA920_pad pad3;
  UnkStruct_003DA920_pad pad4;
  if (bone == 8)
  {
    NearestPointOnHull__16CB3VehicleDeformFP13CB3ConvexHullPQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3d(hull, pts, &pos, out);
  }
  else
  {
    float best = 3.402823466e+38f;
    int bi = -1;
    unsigned char n = hull->field_18;
    for (int i = 0; i < n; i++)
    {
      UnkStruct_003DA920_h *e = &hull->field_10[i];
      if ((bone == e->field_8) || (bone == e->field_9))
      {
        CGtV3d dv = pts[i];
        dv -= pos;
        float d = dv.GetLength();
        if (d < best)
        {
          best = d;
          bi = i;
        }
      }
    }

    if (bi >= 0)
    {
      *out = pts[bi];
    }
    else
    {
      NearestPointOnHull__16CB3VehicleDeformFP13CB3ConvexHullPQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3d(hull, pts, &pos, out);
    }
  }
}
