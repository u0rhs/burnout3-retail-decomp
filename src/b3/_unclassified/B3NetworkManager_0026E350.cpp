// CB3NetworkManager::ReplayHeaderMessageDeliveredCallback(bool,CGtNetworkMessage*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a165 tiny).

struct UnkStruct_a165_nm { unsigned char pad_0[0x8]; void *field_8; };
struct UnkStruct_a165_pl { unsigned char pad_0[0x4F5]; unsigned char field_4F5; };
extern "C" UnkStruct_a165_pl *GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);
extern "C" void ReplayHeaderMessageDeliveredCallback__17CB3NetworkManagerFbP17CGtNetworkMessagePv(bool b, UnkStruct_a165_nm *msg, void *pv) {
 UnkStruct_a165_pl *p = GetPlayerByID__23CGtNetworkPlayerManagerCFi(pv, (int)msg->field_8);
 if (p != 0) p->field_4F5 = 1; }
