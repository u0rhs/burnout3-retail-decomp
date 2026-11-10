// CB3NetworkManager::GetLobbyStatus() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a165 tiny).

struct UnkStruct_a165_vt { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual int vfunc_14(); };
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(char *self) { return ((UnkStruct_a165_vt *)(self + 0xA264))->vfunc_14(); }
