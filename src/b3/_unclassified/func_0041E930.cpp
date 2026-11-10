// func_0041E930 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtNetworkHeadset.h"
#include "b3/classes/CGtNetworkPlayerManager.h"

struct UnkStruct_0041E930;
struct UnkStruct_0041E930_0;

struct UnkStruct_0041E930_0 {
    int field_0;
};

struct UnkStruct_0041E930 {
    unsigned char pad_0[0x81D8];
    CGtNetworkPlayerManager * field_81D8;
};

extern "C" int GetIDOfTalkingNetworkPlayer__17CGtNetworkHeadsetFPi(void *, int*);  // CGtNetworkHeadset::GetIDOfTalkingNetworkPlayer(int*)
extern "C" int IsTalking__17CGtNetworkHeadsetFv(void *);  // CGtNetworkHeadset::IsTalking()

// 0x0041E930
extern "C" int func_0041E930(UnkStruct_0041E930 * self)
{
    int id;
    if (GetIDOfTalkingNetworkPlayer__17CGtNetworkHeadsetFPi(self, &id) != 0) {
        return id;
    }
    if (IsTalking__17CGtNetworkHeadsetFv(self) != 0) {
        return self->field_81D8->GetMyPlayerID();
    }
    return -1;
}
