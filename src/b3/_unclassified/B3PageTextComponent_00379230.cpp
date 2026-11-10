// CB3PageTextComponent::GetNumLines() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PageTextComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ceil of f/27).

extern "C" double ceil(double);
struct UnkStruct_a166_pt { unsigned char pad_0[0xC]; float field_C; };
struct UnkStruct_a166_pc { unsigned char pad_0[0x18]; UnkStruct_a166_pt *field_18; };
extern "C" int GetNumLines__20CB3PageTextComponentFv(UnkStruct_a166_pc *self) {
  return (int)ceil((double)(self->field_18->field_C / 27.0f));
}
