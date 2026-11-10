// CB3OnlineLoginToLobbyPage::ForAllPersonas(char*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLoginToLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extern C strcpy persona).

extern "C" char *strcpy(char *, const char *);
struct UnkStruct_a166_pn { unsigned char pad_0[4]; char field_4[0x10][1]; unsigned char pad_14[0x3E]; signed char field_52; };
extern "C" int ForAllPersonas__25CB3OnlineLoginToLobbyPageFPcPv(char *name, UnkStruct_a166_pn *self) {
  strcpy(self->field_4[self->field_52 * 16], name);
  self->field_52 = self->field_52 + 1;
  return 1;
}
