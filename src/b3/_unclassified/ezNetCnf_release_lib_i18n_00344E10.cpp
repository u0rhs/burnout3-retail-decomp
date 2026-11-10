// cbFormatAuthMessage -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> ezNetCnf_release.lib i18n.o.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extern C snprintf auth).

extern "C" int snprintf(char *, int, const char *, ...);
struct UnkStruct_a166_s { unsigned char pad_0[0x28]; int field_28; };
struct UnkStruct_a166_t { unsigned char pad_0[8]; char field_8[1]; unsigned char pad_9[0x173]; char field_17C[1]; };
// 0x00344E10
extern "C" void cbFormatAuthMessage(char *buf, int n, const char *fmt, UnkStruct_a166_s *s, UnkStruct_a166_t *t) {
  if (s->field_28 == 3) snprintf(buf, n, fmt, t->field_17C);
  else if (s->field_28 == 4) snprintf(buf, n, fmt, t->field_8);
}
