// CB3Score::WasSlammedWithinTime(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (WithinTime shape).

struct UnkStruct_0015_a164_A { unsigned char pad_0[0x10CC]; float lim; unsigned char pad_1[0x1588-0x10CC-4]; float f; };
struct UnkStruct_0015_a164_B { unsigned char pad_0[0xC8]; UnkStruct_0015_a164_A *p; };
extern "C" bool WasSlammedWithinTime__8CB3ScoreFf(UnkStruct_0015_a164_B *self, float t)
{
    UnkStruct_0015_a164_A *q = self->p;
    if (q->f >= 0.0f) {
        return !(q->lim > q->f + t);
    }
    return false;
}
