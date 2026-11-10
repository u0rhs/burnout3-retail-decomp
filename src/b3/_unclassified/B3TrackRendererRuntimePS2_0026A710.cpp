// CB3TrackRenderer::PushCameraForInstanceRendering(EB3RenderableCamera) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrackRendererRuntimePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): if ((v && v) && v); {; }).

#include "b3/GtMathPs2.h"

#pragma push
#pragma opt_propagation off
using namespace GtMathPs2;
struct UnkStruct_665EC0_ent {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    u_long128 field_30;
    u_long128 field_40;
    u_long128 field_50;
    unsigned char pad_60[0x120];
    CGtV4d field_180;
    unsigned char pad_190[0xA0];
};
struct UnkStruct_665EC0 {
    unsigned char pad_0[0x470];
    UnkStruct_665EC0_ent field_470[1];  
};
struct UnkStruct_0026A710_pad { int x[4]; UnkStruct_0026A710_pad() {} ~UnkStruct_0026A710_pad() {} };
extern UnkStruct_665EC0 D_00665EC0;
enum EB3RenderableCamera { UnkEnum_26A710_0 };
class CB3TrackRenderer {
public:
    int PushCameraForInstanceRendering(EB3RenderableCamera cam);
    unsigned char pad_0[0x84];
    signed char field_84;
    unsigned char pad_85[2];
    unsigned char field_87[1];
    unsigned char pad_88[8];
    float field_90;
};







// 0x0026A710
int CB3TrackRenderer::PushCameraForInstanceRendering(EB3RenderableCamera cam)
{
  field_87[field_84] = cam;
  UnkStruct_665EC0_ent *e = &D_00665EC0.field_470[cam];
  CGtV4d b;
  b.mData = e->field_0;
  CGtV4d a;
  a.mData = e->field_180.mData;
  CGtV4d *pa = &a;
  UnkStruct_0026A710_pad pad;
  if (!(pa->f[3] <= field_90))
  {
    float t = pa->f[3] - field_90;
    CGtV4d d;
    CGtV4d *pd = &d;
    *pd = b;
    float nw = d.f[3] - t;
asm ( "qmtc2.ni %1, $vf1\n\tvmulx.w %0, $vf0, $vf1x" : "+j" ( b . mData ) : "r" ( nw ) ) ;
  }
  int v;
asm ( "qmtc2.i %0, $vf1\n\tqmtc2.ni %1, $vf2\n\tqmtc2.ni %2, $vf3\n\tqmtc2.ni %3, $vf4\n\tqmtc2.ni %4, $vf5\n\tqmtc2.ni %5, $vf6" : : "r" ( e -> field_20 ) , "r" ( e -> field_30 ) , "r" ( e -> field_40 ) , "r" ( e -> field_50 ) , "r" ( b . mData ) , "r" ( e -> field_10 ) ) ;
asm ( "vcallms 0xC0" ) ;
asm ( "cfc2.i %0, $vi1" : "=r" ( v ) ) ;
  field_84 = v;
  if ((v && v) && v)
  {
  }
  return 1;
}



#pragma pop
