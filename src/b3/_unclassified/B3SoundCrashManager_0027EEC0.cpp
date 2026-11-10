// CB3SoundCrashManager::DeformBonnet(GtMathPs2::CGtV3d,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a79: sibling of DeformRoof shape).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
struct UnkStruct_0027EE40_pad {
    unsigned char field_0[4];
    UnkStruct_0027EE40_pad() {}
    ~UnkStruct_0027EE40_pad() {}
};
class CB3SoundCrashManager {
public:
    void DeformBonnet(CGtV3d, float);
    unsigned char pad_0[0x598];
    float field_598;
    float field_59C;
    float field_5A0;
    unsigned char pad_5A4[0x2DC];
    void * field_880;
};
extern "C" void func_00280580(CB3SoundCrashManager *, float, const void *, int);
extern "C" void func_0027EC10(CB3SoundCrashManager *, const void *, float);
// 0x0027EEC0
void CB3SoundCrashManager::DeformBonnet(CGtV3d p0, float p1)
{
    UnkStruct_0027EE40_pad pad;
    CGtV3d pos;
    pos = p0;
    const void *pp = &pos;
    float f = p1;
    if (field_880 != 0) {
        if (f > field_598) {
            func_00280580(this, f, pp, 0);
        }
        func_0027EC10(this, &pos, f);
    }
}
