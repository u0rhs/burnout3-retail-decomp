// CB3Strings::Prepare(void*,const char*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Strings.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a165 tiny).

extern "C" void FixUp__12CGtArrayBaseFv(void *);
struct UnkStruct_a165_s { void *field_0; };
extern "C" int Prepare__10CB3StringsFPvPCci(UnkStruct_a165_s *self, void *p, const char *c, int i) { self->field_0 = p; FixUp__12CGtArrayBaseFv(self->field_0); return 1; }
