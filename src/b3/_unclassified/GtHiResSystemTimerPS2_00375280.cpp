// CGtHiResSystemTimer::GetTime() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtHiResSystemTimerPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a166 match (COP0 count read: one-instruction asm, N176); lead: diff normalises c0_ names).

#include "b3/classes/CGtHiResSystemTimer.h"
extern "C" void GetTime__19CGtHiResSystemTimerFv(unsigned long *out) {
  long l;
  asm volatile ("mfc0 %0,$9" : "=r"(l));
  int c = (int)l;
  if ((unsigned)c < (unsigned)CGtHiResSystemTimer::gmuTimeLSP) CGtHiResSystemTimer::gmnTimeMSP = CGtHiResSystemTimer::gmnTimeMSP + 1;
  CGtHiResSystemTimer::gmuTimeLSP = c;
  *out = ((unsigned long)CGtHiResSystemTimer::gmnTimeMSP << 32) + (unsigned)c;
}
