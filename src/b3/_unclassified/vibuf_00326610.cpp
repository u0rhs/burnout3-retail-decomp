// viBufEndPut -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> vibuf.c.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a165 tiny).

struct UnkStruct_a165_vb { unsigned char pad_0[0x14]; int field_14; unsigned char pad_18[0x28]; int field_40; unsigned char pad_44[4]; long field_48; };
extern "C" void WaitSema(int);
extern "C" void SignalSema(int);
// 0x00326610
extern "C" void viBufEndPut(UnkStruct_a165_vb *b, int n) { WaitSema(b->field_40); b->field_14 += n; b->field_48 += n; SignalSema(b->field_40); }
