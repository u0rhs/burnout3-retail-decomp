// CGtTimer::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtTimer.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (return true; header statics).

#include "b3/classes/CGtTimer.h"
struct UnkStruct_1D3C_a164 { int f0, f4, f8, fC, f10, f14, f18; float f1C; int f20, f24; unsigned char f28; };
extern "C" bool Prepare__8CGtTimerFv(UnkStruct_1D3C_a164 *s)
{
    s->f14 = CGtTimer::mguFrames;
    s->f0 = 0;
    s->f4 = 0;
    s->f8 = 0;
    s->fC = 0;
    s->f10 = 0;
    s->f18 = 1;
    s->f24 = 1;
    s->f28 = 0;
    s->f1C = CGtTimer::mgrBaseTimestepSeconds / (float)s->f18;
    s->f20 = 0;
    return true;
}
