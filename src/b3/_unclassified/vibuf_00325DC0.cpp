// viBufCount -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> vibuf.c.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a165 tiny).

struct UnkStruct_a165_vb { unsigned char pad_0[0x10]; int field_10; int field_14; unsigned char pad_18[0x28]; int field_40; };
extern "C" void WaitSema(int);
extern "C" void SignalSema(int);
// 0x00325DC0
extern "C" int viBufCount(UnkStruct_a165_vb *b) { WaitSema(b->field_40); int n = b->field_14 + (b->field_10 << 16); SignalSema(b->field_40); return n; }
