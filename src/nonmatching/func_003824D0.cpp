// NONMATCHING: func_003824D0 -- retail 182 / ours 185 instructions, 105 in changed runs
// v275: logic complete (BoostBar message Prepare: width via func_003827B0, Min(maxw), callback select, colour W kept, Min(c,1)*255.99 -> bytes); left: our Y()/Z() lane reads go through CSE'd lane-address registers (retail reads lwc1 off sp), frame 0x260 vs 0x280
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_003824D0_data {
    const unsigned short *field_0;
    float field_4;
    float field_8;
    float field_C;
    unsigned char field_10;
    unsigned char field_11;
    unsigned char field_12;
    unsigned char field_13;
    unsigned char field_14;
    unsigned char field_15;
    unsigned char field_16;
    unsigned char field_17;
};
struct UnkStruct_003824D0 {
    unsigned char pad_0[0x20];
    UnkStruct_003824D0_data field_20;
};

extern "C" float func_003827B0(const unsigned short *s, unsigned char flags);
extern "C" void func_00381020(void);
extern "C" void func_00381030(void *, void *);
extern "C" void func_00381AB0(void *, void *);
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, const void *, unsigned int, unsigned int);

static inline CGtV2d func_003824D0_inl1(const CGtV2d &a, const CGtV2d &b) { return a - b; }

// 0x003824D0
extern "C" void func_003824D0(UnkStruct_003824D0 *self, const CGtV2d &p0, const CGtV2d &p1, CGtV4d c1, CGtV4d c2,
                              const unsigned short *str, unsigned char flags, float h, float k, float maxw)
{
    CGtV4d one(1.0f, 1.0f, 1.0f, 1.0f);
    UnkStruct_003824D0_data *d = &self->field_20;
    float w = func_003827B0(str, flags);
    float inv = 0.0f;
    float sx;
    const void *cb;
    if (w > 0.0f) {
        float t = k * (w * h);
        sx = GtMath::Min(t, maxw);
        inv = 1.0f / w;
        if (flags & 0x10)
            cb = (const void *)&func_00381030;
        else
            cb = (const void *)&func_00381AB0;
    } else {
        sx = h;
        cb = (const void *)&func_00381020;
    }
    CGtV4d col;
    if (flags & 8)
        col = c1;
    else
        col = CGtV4d(1.0f, 1.0f, 1.0f, c1.W());
    CGtV2d size(sx, h);
    CGtV2d pos = func_003824D0_inl1(p0, size * p1);
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(self, pos, size, col, cb, 64, 24);
    d->field_0 = str;
    d->field_8 = 1.0f / size.X();
    d->field_C = 1.0f / size.Y();
    d->field_4 = inv;
    CGtV4d a = Min(c1, one) * 255.99f;
    CGtV4d b = Min(c2, one) * 255.99f;
    float ax = a.X();
    float ay = a.Y();
    float az = a.Z();
    float bx = b.X();
    float by = b.Y();
    float bz = b.Z();
    d->field_10 = (int)ax;
    d->field_11 = (int)ay;
    d->field_12 = (int)az;
    d->field_14 = (int)bx;
    d->field_15 = (int)by;
    d->field_16 = (int)bz;
    d->field_13 = flags;
    d->field_17 = 0;
}
