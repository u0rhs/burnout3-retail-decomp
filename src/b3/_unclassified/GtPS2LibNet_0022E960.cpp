// CGtPS2LibNet::Send(void*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtPS2LibNet.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (tiny extern C).

extern "C" int sceInsockSend(int, void*, int, int);
extern "C" int Send__12CGtPS2LibNetFPvi(int *self, void *b, int n) { return sceInsockSend(self[0xB0/4], b, n, 0); }
