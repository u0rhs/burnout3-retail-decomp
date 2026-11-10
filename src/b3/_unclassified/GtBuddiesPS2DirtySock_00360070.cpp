// CGtBuddiesPS2DirtySock::_BanBuddyCallback(DirtySock::HLBApiRefT*,int,int,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (buddy callback extern C).

struct UnkStruct_a166_bb { unsigned char pad_0[0xF0]; void (*field_F0)(int, int); int field_F4; };
extern "C" void _BanBuddyCallback__22CGtBuddiesPS2DirtySockFPQ29DirtySock10HLBApiRefTiiPv(void *ref, int msg, int err, UnkStruct_a166_bb *self) {
  if (msg != 2 && msg != 4) return;
  if (self->field_F0 != 0) { self->field_F0(err == 0, self->field_F4); self->field_F0 = 0; self->field_F4 = 0; }
}
