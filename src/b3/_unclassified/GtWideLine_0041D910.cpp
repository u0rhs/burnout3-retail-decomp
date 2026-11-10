// CGtWideLine::ConvertPointListToWideLine(CGtWideLinePoint*,int,float,GtMathPs2::CGtV2d*,GtMathPs2::CGtV2d*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtWideLine.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): float *py = &off.marValues[1];; float *py = &off.marValues[1];; *py = oy;).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
struct UnkStruct_CGtWideLinePoint { CGtV2d field_0; float field_8; float field_C; unsigned char pad_10[0x10]; float field_20; unsigned char pad_24[0xC]; };
extern "C" void ConvertPointListToWideLine__11CGtWideLineFP16CGtWideLinePointifPQ29GtMathPs26CGtV2dPQ29GtMathPs26CGtV2d ( UnkStruct_CGtWideLinePoint * pts , int n , float width , CGtV2d * p0 , CGtV2d * p1 );





void ConvertPointListToWideLine__11CGtWideLineFP16CGtWideLinePointifPQ29GtMathPs26CGtV2dPQ29GtMathPs26CGtV2d(UnkStruct_CGtWideLinePoint *pts, int n, float width, CGtV2d *p0, CGtV2d *p1)
{
  int i = 0;
  int j = 0;
  float half = 0.5f * width;
  CGtV2d off;
  if (0 < n)
  {
    goto t;
    l:
    {
      UnkStruct_CGtWideLinePoint *p = &pts[i];
      float *py = &off.marValues[1];
      i++;
      CGtV2d *o0 = &p0[j];
      CGtV2d *o1 = &p1[j];
      j += 2;
      float dx = p->field_8;
      float dy = -p->field_C;
      float inv;
      float one = 1.0f;
asm ( "rsqrt.s %0, %1, %2" : "=f" ( inv ) : "f" ( one ) , "f" ( dy * dy + dx * dx ) ) ;
      float ox = dy * inv;
      float oy = dx * inv;
      ox *= half;
      oy *= half;
      *py = oy;
      off.marValues[0] = ox;
      *py = oy;
      o0[0] = p->field_0 + off;
      o1[0].Set(p->field_20, 0.0f);
      o0[1] = p->field_0 - off;
      o1[1].Set(p->field_20, 1.0f);
    }

    t:
    if (i < n)
    {
      goto l;
    }

  }
}
