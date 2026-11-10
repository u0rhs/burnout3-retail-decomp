// CB3StreamedTrack::DoUnitFrustumTesting() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamedTrackPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): int i;; int j;; int new_var[2];; for (i = 0; i < 17; i++); for (new_var[1] = 0; new_var[1] < 17; new_var[1]++); field_58[i] = 0;; field_58[new_var[1]] = 0;; for (i = 0; i < 4; i++); for (new_var[1] = 0; new_var[1] < 4; new_var[1]++); cam = &((UnkStruct_0021D080_gm *) (&D_00665EC0))->field_470[i];; i).

#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

class CGtFrustum;
class CGtExtrudedBox;
class CGtOrientedBox;


struct UnkStruct_0021D080_cam {
    unsigned char pad_0[0xD0];
    CGtV3d field_D0;
    unsigned char pad_E0[0x150];
};
struct UnkStruct_0021D080_gm {
    unsigned char pad_0[0x470];
    UnkStruct_0021D080_cam field_470[4];
};

struct UnkStruct_0021D080_u {
    unsigned char pad_0[0x10];
    CGtV3d field_10[4];
};

struct UnkStruct_0021D080_sb {
    CGtV3d field_0[8];
};

struct UnkStruct_0021D080_ob {
    unsigned char pad_0[0xE0];
};

class GtIntersection {
public:
    static int IntersectFrustum(const CGtFrustum &f, const CGtExtrudedBox &b);
    static int IntersectSphere(CGtSphere s, const CGtOrientedBox &b);
};

class CB3StreamedTrack {
public:
    void DoUnitFrustumTesting();
    unsigned char pad_0[0x58];
    unsigned short field_58[17];
    unsigned char pad_7A[0x2];
    UnkStruct_0021D080_u *field_7C[17];
};


struct UnkStruct_0021D080_pad { int x[8]; UnkStruct_0021D080_pad() {} ~UnkStruct_0021D080_pad() {} };

class CB3GraphicsManager;
extern CB3GraphicsManager D_00665EC0;
extern "C" void ConvertTo__20CGtSimpleOrientedBoxCFP14CGtOrientedBox(const UnkStruct_0021D080_sb *, UnkStruct_0021D080_ob *);


static inline CGtV3d DoUnitFrustumTesting_inl1(const CGtV3d &a) {
    u_long128 t;
    asm("vadd.xyz %0, $vf0, $vf0" : "=j"(t));
    asm("vaddw.y %0, $vf0, %1w" : "+j"(t) : "j"(a.mData));
    return CGtV3d(t);
}

static inline CGtV3d DoUnitFrustumTesting_inl2(const CGtV3d &a, const CGtV3d &b) {
    u_long128 r;
    asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}














// 0x0021D080
void CB3StreamedTrack::DoUnitFrustumTesting()
{
  int v0[2];
  UnkStruct_0021D080_cam *cam;
  for (v0[1] = 0; v0[1] < 17; v0[1]++)
  {
    field_58[v0[1]] = 0;
  }

  for (v0[1] = 0; v0[1] < 4; v0[1]++)
  {
    cam = &((UnkStruct_0021D080_gm *) (&D_00665EC0))->field_470[v0[1]];
    int sh = v0[1] * 2;
    int mask;
    for (v0[0] = 0; v0[0] < 17; v0[0]++)
    {
      UnkStruct_0021D080_u **pu = &field_7C[v0[0]];
      mask = ~(3 << sh);
      if ((*pu) == 0)
      {
        goto none;
      }
      int v;
      int r = GtIntersection::IntersectFrustum(*((const CGtFrustum *) cam), *((const CGtExtrudedBox *) (*pu)->field_10));
      if (r == 0)
      {
        v = 0;
      }
      else
        if (r == 2)
      {
        v = 1;
      }
      else
      {
        CGtSphere s;
        CGtV3d c[8];
        UnkStruct_0021D080_sb sb;
        UnkStruct_0021D080_ob ob;
        UnkStruct_0021D080_pad pad;
        s.SetPosition(cam->field_D0);
        s.SetRadius(100.0f);
        UnkStruct_0021D080_u *u = *pu;
        CGtV3d h = DoUnitFrustumTesting_inl1(u->field_10[0]);
        c[0] = u->field_10[0];
        c[1] = u->field_10[1];
        c[2] = u->field_10[2];
        c[3] = u->field_10[3];
        c[4] = DoUnitFrustumTesting_inl2(c[0], h);
        c[5] = DoUnitFrustumTesting_inl2(c[1], h);
        c[6] = DoUnitFrustumTesting_inl2(c[2], h);
        c[7] = DoUnitFrustumTesting_inl2(c[3], h);
        sb.field_0[0] = c[0];
        sb.field_0[1] = c[3];
        sb.field_0[2] = c[2];
        sb.field_0[3] = c[1];
        sb.field_0[4] = c[4];
        sb.field_0[5] = c[7];
        sb.field_0[6] = c[6];
        sb.field_0[7] = c[5];
        ConvertTo__20CGtSimpleOrientedBoxCFP14CGtOrientedBox(&sb, &ob);
        if (GtIntersection::IntersectSphere(s, *((const CGtOrientedBox *) (&ob))))
        {
          v = 3;
        }
        else
        {
          v = 2;
        }
      }
      field_58[v0[0]] &= mask;
      field_58[v0[0]] |= ((unsigned short) v) << sh;
      continue;
      none:
      field_58[v0[0]] &= mask;

    }

  }

}
