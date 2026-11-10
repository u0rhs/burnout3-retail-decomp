// CGt2dObjectVideoImage::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d,CGtVideoDecoder*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dObjectVideoImage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): UnkStruct_vi_img *new_var;; float new_var2;; uv = dpc_CGtV2d((float) (img->field_C * 16), (float) (img->field_10 * 16)) / dpc_CGtV2d(64.0f, 64.0f);; new_var2 = (float) ((new_var = img)->field_C * 16);; uv = dpc_CGtV2d(new_var2, (float) (img->field_10 * 16)) / dpc_CGtV2d(64.0f, 64.0f);).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_vi_img { unsigned char pad_0[0xC]; int field_C; int field_10; };
struct UnkStruct_vi_blk { CGtV2d field_0; CGtV2d field_8; void *field_10; unsigned char field_14; };
struct UnkStruct_vi_obj { unsigned char pad_0[0x20]; UnkStruct_vi_blk field_20; };
extern "C" UnkStruct_vi_img *GetImage__15CGtVideoDecoderFv(void *);
extern "C" void _Render__21CGt2dObjectVideoImageFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const void *, const void *);
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, void (*)(const void *, const void *), unsigned int, unsigned int);

static inline void func_00326E70_inl1(UnkStruct_vi_blk *d, CGtV2d uv) { d->field_0 = uv; }
static inline void func_00326E70_inl2(UnkStruct_vi_blk *d, const CGtV2d uv) { d->field_0 = uv; }
extern "C" void Prepare__21CGt2dObjectVideoImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP15CGtVideoDecoder ( UnkStruct_vi_obj * self , const CGtV2d & pos , const CGtV2d & anchor , const CGtV2d & size , const CGtV4d colour , void * dec );









void Prepare__21CGt2dObjectVideoImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP15CGtVideoDecoder(UnkStruct_vi_obj *self, const CGtV2d & pos, const CGtV2d & anchor, const CGtV2d & size, const CGtV4d colour, void *dec)
{
  UnkStruct_vi_img *v0;
  UnkStruct_vi_blk *d = &self->field_20;
  float v2;
  UnkStruct_vi_img *img = GetImage__15CGtVideoDecoderFv(dec);
  CGtV2d uv;
  v2 = (float) ((v0 = img)->field_C * 16);
  uv = CGtV2d(v2, (float) (img->field_10 * 16)) / CGtV2d(64.0f, 64.0f);
  d->field_10 = dec;
  d->field_0 = uv;
  d->field_14 = 0;
  Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(self, pos - (size * anchor), size, colour, _Render__21CGt2dObjectVideoImageFRCQ211CGt2dObject16CGt2dObjectSpacePCv, 0x40, 0x18);
}
