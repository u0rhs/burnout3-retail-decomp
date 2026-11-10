// CGtBuddiesPS2DirtySock::_RemoveBuddyCallback(DirtySock::HLBApiRefT*,int,int,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (buddy callback extern C).

struct UnkStruct_a166_bb { unsigned char pad_0[0xE8]; void (*field_E8)(int, int); int field_EC; };
extern "C" void _RemoveBuddyCallback__22CGtBuddiesPS2DirtySockFPQ29DirtySock10HLBApiRefTiiPv(void *ref, int msg, int err, UnkStruct_a166_bb *self) {
  if (msg == 3 && self->field_E8 != 0) { self->field_E8(err == 0, self->field_EC); self->field_E8 = 0; self->field_EC = 0; }
}
