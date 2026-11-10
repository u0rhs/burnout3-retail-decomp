// NONMATCHING: RenderConnection__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv -- retail 94 / ours 91 instructions, 63 in changed runs
// a204: (void)*(volatile u_long128*)&colour keeps the (1,1,1,1) quad in a stack slot -> frame 0xC0 matches (was 0xA0); retail's dead 'lq v1,0x60' still absent (asm lq and volatile copy add sq / change sched)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: RenderConnection__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv -- retail 94 / ours 87 instructions, 92 in changed runs
// a113: 87 vs 94 instrs. Structure matches (A=size*scale, B=(18,12)*scale via by-value temps, C=pos; C+=A late stores, E=C-B, loop). Missing: retail's dead CGtV4d(1,1,1,1) quad (4x sw 1.0 + lq v1,0x60, no sq; shares the 1.0 const reg with the +1.0f/-1.0f) which b119 eliminates in every source form tried; register/schedule offsets follow from that
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
#include "b3/classes/CGt2dFrame.h"

using namespace GtMathPs2;

struct UnkStruct_Table_rc {
    unsigned char pad_0[0x10];
    float field_10;
    unsigned char pad_14[0x2C];
    CGtV2d field_40;
    int field_48;
};

extern "C" void RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, const CGt2dFrame &, const void *);

static inline void a204_nop(CGtV4d c) {}
static inline float a204_w(CGtV4d c) { return c.f[3]; }
extern "C" void RenderConnection__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(
    const CGtV2d &pos, const CGtV2d &size, unsigned short *p, const CGt2dFrame &frame, const void *data)
{
    const UnkStruct_Table_rc *d = (const UnkStruct_Table_rc *)data;
    CGtV4d colour(1.0f, 1.0f, 1.0f, 1.0f);
    (void)*(volatile u_long128 *)&colour;
    CGtV2d c(pos);
    c += size * d->field_40;
    CGtV2d at = c - CGtV2d(18.0f, 12.0f) * d->field_40;
    at.marValues[0] = at.marValues[0] + 18.0f - 1.0f - d->field_10;
    at.marValues[1] = 1.0f + at.marValues[1];
    for (int i = 0; i < d->field_48; i++) {
        RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(at, size, p, frame, data);
        at.marValues[0] = at.marValues[0] - d->field_10 - 2.0f;
    }
}
