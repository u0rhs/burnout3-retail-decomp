// Hand-written; the lifter refused it (a71: clamp via inline asm pmaxw/pminw/pextlw (b119 has no int min/max intrinsic); found-arm break not return).

// [L] DNAT: no row. Name unknown (B3Profile region).
#include "b3/classes/CB3HardCodedTrackList.h"

extern "C" signed char func_003F5DE0(int n0);
extern "C" int GetHeadlineCrashDamage__24CB3HardCodedHeadlineListFi(int n0);

struct UnkStruct_0013B580 {
    unsigned char pad_0[0x44];
    unsigned int field_44;
    unsigned char pad_48[0x3FF];
    unsigned char field_447[10];  // [G] element count
};

static inline int func_0013B580_max(int a, int b)
{
    int r;
    asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}

static inline int func_0013B580_min(int a, int b)
{
    int r;
    asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}

static inline unsigned int func_0013B580_zx(int a)
{
    unsigned int r;
    asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a));
    return r;
}

// 0x0013B580
extern "C" void func_0013B580(UnkStruct_0013B580 * self, unsigned int p0, unsigned long p1)
{
    self->field_44 += p0;
    int v = self->field_44;
    int t = func_0013B580_max(v, 0);
    t = func_0013B580_min(t, 1999999999);
    self->field_44 = func_0013B580_zx(t);
    int r0 = CB3HardCodedTrackList::FindTrack(p1);
    int i;
    for (i = 0; i < 10; i++) {
        int r = func_003F5DE0(i);
        if (r0 == r || r0 == r + 1) {
            if (p0 >= (unsigned int)GetHeadlineCrashDamage__24CB3HardCodedHeadlineListFi(i)) {
                self->field_447[i] = 1;
                break;
            }
        }
    }
}
