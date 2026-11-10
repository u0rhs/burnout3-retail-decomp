// CB3SoundCrashManager::BodyPartImpact(bool,EVehicleFlyingBit,GtMathPs2::CGtV3d,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (pp=&pos local before first call hoists addiu a2 into prologue).

// 2 instrs off: retail sets a2=&pos in prologue (before case-0 call), ours puts addiu a2 in jal delay slot

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
enum EVehicleFlyingBit {};
class CB3SoundCrashManager {
public:
    void BodyPartImpact(bool, EVehicleFlyingBit, CGtV3d, float);
};
extern "C" void func_0027C8E0(CB3SoundCrashManager *, bool, const void *, float);
extern "C" void func_0027C5A0(CB3SoundCrashManager *, bool, const void *, float);
// 0x0027F480
void CB3SoundCrashManager::BodyPartImpact(bool b, EVehicleFlyingBit t, CGtV3d p, float f)
{
    CGtV3d pos;
    pos = p;
    const void *pp = &pos;
    if (t == 0) func_0027C8E0(this, b, pp, f);
    if (t == 1) func_0027C8E0(this, b, &pos, f);
    if (t == 2) func_0027C5A0(this, b, &pos, f);
    if (t == 3) func_0027C5A0(this, b, &pos, f);
    if (t == 4) func_0027C8E0(this, b, &pos, f);
    if (t == 5) func_0027C8E0(this, b, &pos, f);
    if (t == 6) func_0027C5A0(this, b, &pos, f);
}
