// CB3OnScreenKeyboardComponent::GetTableCellSize(GtMathPs2::CGtV2d*,const CGt2dFrame&,const void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (volatile dead-store temp [G]).

// [G] volatile local t reproduces retail dead stack stores (sp+8/+12) of an inlined CGtV2d temp; "const void *a1" unused.
struct UnkStruct_a166_v2 { float field_0; float field_4; };
struct UnkStruct_a166_fr { unsigned char pad_0[0x68]; float field_68; float field_6C; unsigned char pad_70[0x10]; unsigned char field_80; };
extern "C" void GetTableCellSize__28CB3OnScreenKeyboardComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(UnkStruct_a166_v2 *out, const void *a1, const UnkStruct_a166_fr *fr) {
  volatile UnkStruct_a166_v2 t;
  if (fr->field_80 != 0) { t.field_0 = 0.0f; t.field_4 = fr->field_6C; out->field_0 = 0.0f; out->field_4 = fr->field_6C; }
  else { out->field_0 = fr->field_68; out->field_4 = fr->field_6C; }
}
