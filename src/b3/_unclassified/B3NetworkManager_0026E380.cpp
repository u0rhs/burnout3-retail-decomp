// CB3NetworkManager::ReplayBodyMessageArrivedCallback(CGtNetworkMessage*,int,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051B860.h"

struct UnkStruct_0026E380 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0xC];
    int field_14;
};

struct UnkStruct_0026E380_p {
    unsigned char pad_0[0x4FC];
    int field_4FC;
};

extern UnkStruct_D_0051B860 D_0051B860;
extern "C" UnkStruct_0026E380_p * GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);
extern "C" void Retrieve__27CB3NetworkReplayBodyMessageFPUc(void *, unsigned char *);

// 0x0026E380
extern "C" void ReplayBodyMessageArrivedCallback__17CB3NetworkManagerFP17CGtNetworkMessageiPv(UnkStruct_0026E380 *self, int p0, void *p1)
{
    UnkStruct_0026E380_p *r0 = GetPlayerByID__23CGtNetworkPlayerManagerCFi(p1, self->field_4);
    unsigned char *buf = D_0051B860.field_0;
    if (buf == 0 || r0 == 0) return;
    int t = self->field_14;
    if (t > r0->field_4FC) {
        Retrieve__27CB3NetworkReplayBodyMessageFPUc(self, buf + t);
        r0->field_4FC = t;
        return;
    }
}
