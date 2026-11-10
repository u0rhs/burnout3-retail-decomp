// CB3AITarget::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AITarget.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a163 tiny).

extern "C" void func_00330360(void *);
class CB3AITarget { public: void Release(); unsigned char pad_0[0x170]; int field_170; };
// 0x0014D410
void CB3AITarget::Release() { func_00330360(&field_170); }
