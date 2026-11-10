// NONMATCHING: func_003A8EB0 -- retail 99 / ours 99 instructions, 2 in changed runs
// audit1 (2026-11-01): called a GetStageGtID(int) member that does not exist; retail calls the static GetStageGtID(int, int) with (field_300, 0) [C] retail 0x3A8F1C/0x3A8F80 (same registers, but the port would link a missing symbol) (behaviour_audit) | Before: near32: 2 off -- only the two lwc1 loads of o->field_8 / field_228->field_8 swapped (retail numerator first); layout via goto done + store before the nt<lim test, p assigned (not copy-init) for the dead p stores, CGtV2d(CGtV2d(x,y)) temp pair, b declared at top (sreg). Tried const fields/pointers, locals for n/l, static inline divide, a->field_0 forms
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.


// lit4fix: .lit4 externs rewritten as literals; was: a131: 45 instrs off; s0/s1 swap (self in s0 retail), D_004E0824 hoisted load at entry, p copy stores before q; logic right

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using GtMathPs2::CGtV2d;

class CGt2dObject;
class CB3HardCodedRaceStageList {
public:
    static unsigned long GetStageGtID(int, int);   // audit1: retail calls the static (int, int) overload 0x3EA090
    static unsigned long GetStageTrackID(unsigned long);
};
struct UnkStruct_003A8EB0_o { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_003A8EB0_s40 { UnkStruct_003A8EB0_o * field_0; unsigned char pad_4[0x3C]; };
struct UnkStruct_003A8EB0_s80 { unsigned char pad_0[0x4]; int field_4; unsigned char pad_8[0x38]; };
struct UnkStruct_003A8EB0_l { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_003A8EB0 {
    unsigned char pad_0[0x40];
    UnkStruct_003A8EB0_s40 field_40;
    UnkStruct_003A8EB0_s80 field_80;
    unsigned char pad_C0[0x168];
    UnkStruct_003A8EB0_l * field_228;
    unsigned char pad_22C[0xD4];
    int field_300;   // audit1: an int (GetStageGtID's first argument), not a list pointer [C] retail 0x3A8F18
    unsigned char pad_304[0x404];
    float field_708;
};
extern "C" CGtV2d * func_003EA7F0(unsigned long);
extern "C" void Update__Q218CB3SatNavComponent9CPopupBoxFfRCQ29GtMathPs26CGtV2d(void *, const CGtV2d &, float);
extern "C" void func_003B10A0(void *, const CGtV2d &, int, UnkStruct_003A8EB0_o *, float);
extern "C" void func_003A8A90(void *);
extern "C" void func_003A8BF0(void *);

extern "C" void func_003A8EB0(UnkStruct_003A8EB0 * self, float p0)
{
    UnkStruct_003A8EB0_s80 * b;
    float lim = 0.4f;
    float nt = self->field_708 + p0;
    self->field_708 = nt;
    if (nt < lim) {
        func_003A8A90(self);
        goto done;
    }
    float t = nt - 0.4f;
    if (self->field_40.field_0 == 0) {
        func_003A8BF0(self);
    }
    UnkStruct_003A8EB0_s40 * a = &self->field_40;
    if (a->field_0 != 0) {
        float f = GtMath::Min(GtMath::Max(t, 0.0f), 0.8f);
        CGtV2d pos = *func_003EA7F0(CB3HardCodedRaceStageList::GetStageTrackID(CB3HardCodedRaceStageList::GetStageGtID(self->field_300, 0)));
        Update__Q218CB3SatNavComponent9CPopupBoxFfRCQ29GtMathPs26CGtV2d(a, pos, 1.25f * f);
    }
    b = &self->field_80;
    if (b->field_4 != 0) {
        float f = GtMath::Min(GtMath::Max(t, 0.0f), 0.8f);
        float z = 0.0f;
        CGtV2d * pp = func_003EA7F0(CB3HardCodedRaceStageList::GetStageTrackID(CB3HardCodedRaceStageList::GetStageGtID(self->field_300, 0)));
        CGtV2d p;
        p = *pp;
        UnkStruct_003A8EB0_o * o = a->field_0;
        func_003B10A0(b, CGtV2d(CGtV2d(p.marValues[0] + o->field_8 / self->field_228->field_8, p.marValues[1] + z)), 1, o, 1.25f * f);
    }
done:
    return;
}

