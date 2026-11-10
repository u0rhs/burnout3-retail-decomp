// CB3NetworkManager::PlayerBootedCallback(ELobbyKickReason,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a80: D_0051BA88 padded to 0x10 (non-gp) struct with field_0 ptr).

#include "b3/classes/CB3MenuFlowFSM.h"
struct UnkStruct_0026F0F0_g { unsigned char pad_0[0x10]; };
struct UnkStruct_0026F0F0_h { UnkStruct_0026F0F0_g *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_0026F0F0_g D_0051A6A8;
extern UnkStruct_0026F0F0_h D_0051BA88;
extern CB3MenuFlowFSM D_01EA2970;
extern "C" void ClearAllPlayers__23CGtNetworkPlayerManagerFv(void *);
extern "C" int PlayerBootedCallback__17CB3NetworkManagerF16ELobbyKickReasonPv(int reason, void *p1)
{
    if (D_0051BA88.field_0 == &D_0051A6A8) {
        ClearAllPlayers__23CGtNetworkPlayerManagerFv(p1);
        D_01EA2970.ApplyEvent(0x28, (void *)reason);
    }
    return 1;
}
