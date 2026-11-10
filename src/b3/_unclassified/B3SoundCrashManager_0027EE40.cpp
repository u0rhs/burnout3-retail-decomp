// CB3SoundCrashManager::DeformRoof(GtMathPs2::CGtV3d,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (N140 pad local, pos declared then pp=&pos then pos=p0, f=p1;f*=40).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
struct UnkStruct_0027EE40_pad {
    unsigned char field_0[4];
    UnkStruct_0027EE40_pad() {}
    ~UnkStruct_0027EE40_pad() {}
};
class CB3SoundCrashManager {
public:
    void DeformRoof(CGtV3d, float);
    unsigned char pad_0[0x59C];
    float field_59C;
    unsigned char pad_5A0[0x2E0];
    void * field_880;
};
extern "C" void func_0027FFF0(CB3SoundCrashManager *, float, const void *, int);
extern "C" void func_0027EC10(CB3SoundCrashManager *, const void *, float);
// 0x0027EE40
// [G] pad = N140 frame slot; pp (the &pos for the first call only) computed before the null test; no DNAT row
void CB3SoundCrashManager::DeformRoof(CGtV3d p0, float p1)
{
    UnkStruct_0027EE40_pad pad;
    CGtV3d pos;
    const void *pp = &pos;
    pos = p0;
    float f = p1;
    f *= 40.0f;
    if (field_880 != 0) {
        if (f > field_59C) {
            func_0027FFF0(this, f, pp, 0);
        }
        func_0027EC10(this, &pos, f);
    }
}
