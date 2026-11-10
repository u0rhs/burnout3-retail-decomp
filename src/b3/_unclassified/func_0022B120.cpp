// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): UnkStruct_0022B120_v *p = &base[idx];; p->field_0.SetX(v.X() * r);; float c = 2.0f * (3.1415927f * ((0.25f / ((float) cols)) * ((float) j)));; p->field_0.SetY(v.Y());; p->field_0.SetZ(v.Z() * r);; p->field_10.SetX(t * sinf(c));; CGtV3d *q = &p->field_10;; q->SetY(t * cosf(c));; UnkStruct_0022B120_v ).

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV3d;

extern "C" float sqrtf(float);
extern "C" float floorf(float);

struct UnkStruct_0022B120_pad { int x[4]; UnkStruct_0022B120_pad() {} ~UnkStruct_0022B120_pad() {} };
struct UnkStruct_0022B120_v {
    CGtV3d field_0;
    CGtV3d field_10;
};
extern "C" int func_0022B120 ( int n , float radius , float angle );






// 0x0022B120
int func_0022B120(int n, float radius, float angle)
{
  float s = sqrtf((float) n);
  int rows = (int) floorf(s);
  float frac = s - ((float) rows);
  int cols = rows;
  if (frac <= 0.75f)
  {
    if (!(frac <= 0.25f))
    {
      cols = rows + 1;
    }
  }
  else
  {
    cols = rows + 1;
    rows = cols;
  }
  int out = 0;
  UnkStruct_0022B120_v *base = ((UnkStruct_0022B120_v *) 0x70004000) - ((cols + 1) * (rows + 1));
  int idx = 0;
  CGtV3d v;
  UnkStruct_0022B120_pad p0;
  UnkStruct_0022B120_pad p1;
  UnkStruct_0022B120_pad p2;
  UnkStruct_0022B120_pad p3;
  UnkStruct_0022B120_pad p4;
  UnkStruct_0022B120_pad p5;
  int j;
  int i;
  for (i = 0; i <= rows; i++)
  {
    float a = 0.017453292f * (((float) i) * (180.0f / ((float) (rows * 2))));
    v.SetY(radius * cosf(a));
    float r = radius * sinf(a);
    float t = (1.0f / ((float) rows)) * ((float) i);
    for (j = 0; j <= cols; j++)
    {
      float b = 0.017453292f * (((float) j) * (angle / ((float) cols)));
      v.SetX(sinf(b));
      v.SetZ(cosf(b));
      UnkStruct_0022B120_v *p;
      (&base[idx])->field_0.SetX(v.X() * r);
      float c;
      (&base[idx])->field_0.SetY(v.Y());
      (&base[idx])->field_0.SetZ(v.Z() * r);
      (&base[idx])->field_10.SetX(t * sinf(2.0f * (3.1415927f * ((0.25f / ((float) cols)) * ((float) j)))));
      CGtV3d *q = &(&base[idx])->field_10;
      q->SetY(t * cosf(2.0f * (3.1415927f * ((0.25f / ((float) cols)) * ((float) j)))));
      idx++;
    }

  }

  UnkStruct_0022B120_v *dst = (UnkStruct_0022B120_v *) 0x70000000;
  for (i = 0; i < rows; i++)
  {
    int a = i * (cols + 1);
    int b = (i + 1) * (cols + 1);
    if (i > 0)
    {
      UnkStruct_0022B120_v *sp = &base[a];
      dst[out++] = *sp;
    }
    dst[out] = base[a];
    dst[out + 1] = base[b];
    out += 2;
    for (j = 0; j < cols; j++)
    {
      a++;
      b++;
      dst[out] = base[a];
      dst[out + 1] = base[b];
      out += 2;
    }

    if (i < (rows - 1))
    {
      dst[out++] = base[b];
    }
  }

  return out;
}
