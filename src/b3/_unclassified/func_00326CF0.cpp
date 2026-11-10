// Hand-written; the lifter refused it (near34: clone of CGt2dObjectVideoImage::Prepare (sibling) + num/size into field_8 after field_14 = 1).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_vi_img { unsigned char pad_0[0xC]; int field_C; int field_10; };
struct UnkStruct_vi_blk { CGtV2d field_0; CGtV2d field_8; void *field_10; unsigned char field_14; };
struct UnkStruct_vi_obj { unsigned char pad_0[0x20]; UnkStruct_vi_blk field_20; };
extern "C" UnkStruct_vi_img *GetImage__15CGtVideoDecoderFv(void *);
extern "C" void _Render__21CGt2dObjectVideoImageFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const void *, const void *);
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, void (*)(const void *, const void *), unsigned int, unsigned int);
// 0x00326CF0
extern "C" void func_00326CF0(UnkStruct_vi_obj *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, const CGtV2d &num, const CGtV4d colour, void *dec)
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
  d->field_14 = 1;
  d->field_8 = num / size;
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(self, pos - (size * anchor), size, colour, _Render__21CGt2dObjectVideoImageFRCQ211CGt2dObject16CGt2dObjectSpacePCv, 0x40, 0x18);
}
