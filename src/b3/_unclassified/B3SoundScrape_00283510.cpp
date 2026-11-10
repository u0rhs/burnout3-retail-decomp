// CB3SoundScrape::SetInfo(ESoundWorldCrashSurfaceType,float,float,GtMathPs2::CGtV3d*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundScrape.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (a165 tiny).

#include "b3/GtMathPs2.h"
struct UnkStruct_a165_sc { u_long128 field_0; unsigned char pad_10[0x1C]; float field_2C; float field_30; int field_34; int field_38; unsigned char field_3C; };
struct UnkStruct_a165_v { u_long128 field_0; };
extern "C" void SetInfo__14CB3SoundScrapeF27ESoundWorldCrashSurfaceTypeffPQ29GtMathPs26CGtV3d(UnkStruct_a165_sc *s, int p0, float p1, float p2, UnkStruct_a165_v *p3) {
 s->field_34 = p0; s->field_2C = p2; s->field_30 = p1; s->field_0 = p3->field_0;
 int t0 = s->field_38;
 if (t0 < 25) { s->field_38 = t0 + 2; }
 s->field_3C = 1; }
