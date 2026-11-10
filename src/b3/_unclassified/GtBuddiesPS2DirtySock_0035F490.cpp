// CGtBuddiesPS2DirtySock::_InviteBuddyCallback(DirtySock::HLBApiRefT*,int,int,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (buddy callback extern C).

struct UnkStruct_a166_bb { unsigned char pad_0[0xD8]; void (*field_D8)(int, int); int field_DC; };
extern "C" void _InviteBuddyCallback__22CGtBuddiesPS2DirtySockFPQ29DirtySock10HLBApiRefTiiPv(void *ref, int msg, int err, UnkStruct_a166_bb *self) {
  if (self->field_D8 != 0) { self->field_D8(err == 0, self->field_DC); self->field_D8 = 0; self->field_DC = 0; }
}
