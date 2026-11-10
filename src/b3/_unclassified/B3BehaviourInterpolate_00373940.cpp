// CB3BehaviourInterpolate::GetTimeElapsed() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BehaviourInterpolate.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (switch, uninit t in default).

struct UnkStruct_a166_ci { unsigned char pad_0[0xB88]; float field_B88; float field_B8C; };
struct UnkStruct_a166_bi { unsigned char pad_0[0x120]; UnkStruct_a166_ci *field_120; float field_124; unsigned char pad_128[4]; float field_12C; unsigned char pad_130[0x14]; int field_144; };
extern "C" float GetTimeElapsed__23CB3BehaviourInterpolateFv(UnkStruct_a166_bi *self) {
  float t;
  switch (self->field_144) {
    case 0: t = self->field_120->field_B88; break;
    case 1: t = self->field_120->field_B8C; break;
    case 2: t = self->field_12C; break;
  }
  return t - self->field_124;
}
