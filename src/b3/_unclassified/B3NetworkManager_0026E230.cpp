// CB3NetworkManager::NATDataMessageArrivedCallback(CGtNetworkMessage*,int,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extern C).

struct UnkStruct_026E_a164_M { int f0; int f4; };
extern "C" char *GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);
extern "C" int Retrieve__36CB3NetworkAllNATDataFinalisedMessageFPiP15EPlayerNATState(void *, void *, void *);
extern "C" void NATDataMessageArrivedCallback__17CB3NetworkManagerFP17CGtNetworkMessageiPv(UnkStruct_026E_a164_M *m, int a1, void *mgr)
{
    char *p = GetPlayerByID__23CGtNetworkPlayerManagerCFi(mgr, m->f4);
    if (p != 0) {
        Retrieve__36CB3NetworkAllNATDataFinalisedMessageFPiP15EPlayerNATState(m, p + 0x580, p + 0x5A0);
    }
}
