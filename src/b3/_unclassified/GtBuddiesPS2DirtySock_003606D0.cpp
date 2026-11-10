// CGtBuddiesPS2DirtySock::GetNumBuddies() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (tiny extern C).

struct UnkStruct_a166_bd { unsigned char pad_0[0x118]; int field_118; };
extern "C" int HLBListGetBuddyCount(int);
extern "C" int GetNumBuddies__22CGtBuddiesPS2DirtySockFv(UnkStruct_a166_bd *self) { return HLBListGetBuddyCount(self->field_118); }
