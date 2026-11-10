// CGtLobbyPS2DirtySock::ReceiveArbitaryMessage(void**,int*,char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (arb packet pop).

class CGtLobbyPS2DirtySock { public: static int mnNumArbPacketsBuffered; };
struct UnkStruct_D_01EA37C0 { unsigned char pad_0[0x40]; };
extern UnkStruct_D_01EA37C0 D_01EA37C0[];
extern "C" int ReceiveArbitaryMessage__20CGtLobbyPS2DirtySockFPPvPiPc(void *self, void **msg, int *len) {
  if (CGtLobbyPS2DirtySock::mnNumArbPacketsBuffered == 0) return 0;
  *msg = &D_01EA37C0[CGtLobbyPS2DirtySock::mnNumArbPacketsBuffered - 1];
  *len = 0x40;
  CGtLobbyPS2DirtySock::mnNumArbPacketsBuffered = CGtLobbyPS2DirtySock::mnNumArbPacketsBuffered - 1;
  return 1;
}
