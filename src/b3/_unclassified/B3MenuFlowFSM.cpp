// B3MenuFlowFSM.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3MenuFlowFSM.cpp.
// Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3MenuFlowFSM.h"
#include "b3/classes/CGtFSM.h"
#include "b3/classes/CGtStateOffset.h"
#include "b3/classes/CGtTimer.h"

// CB3MenuFlowFSM::ApplyEvent(unsigned int,void*) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MenuFlowFSM.cpp.
// 0x0030ED70
void CB3MenuFlowFSM::ApplyEvent(unsigned int p0, void* p1)
{
    CGtFSM::ApplyEvent(p0, p1);
}

// Construct__14CB3MenuFlowFSMFPvPC14CGtStateOffsetP8CGtTimer -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0030ED80
extern "C" void Construct__14CB3MenuFlowFSMFPvPC14CGtStateOffsetP8CGtTimer(CGtFSM *self, void* p0, const CGtStateOffset* p1, CGtTimer* p2)
{
    self->field_818 = 0;
    self->Construct(p0, p1, p2);
}
