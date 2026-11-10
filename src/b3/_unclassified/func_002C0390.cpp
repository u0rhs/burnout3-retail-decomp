// func_002C0390 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtNetworkHeadset.h"
#include "b3/classes/EHeadsetTalkControlStatus.h"

struct UnkStruct_002C0390;

struct UnkStruct_002C0390 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x816C];
    int field_8178;
    unsigned char pad_817C[0x4];
    float field_8180;
    int field_8184;
    unsigned char pad_8188[0x4C];
    int field_81D4;
};

extern "C" void SetStatusToSend__17CGtNetworkHeadsetF25EHeadsetTalkControlStatusi(void *, EHeadsetTalkControlStatus, int);  // CGtNetworkHeadset::SetStatusToSend(EHeadsetTalkControlStatus,int)

// 0x002C0390
extern "C" void func_002C0390(UnkStruct_002C0390 * self)
{
    int t0 = self->field_8;
    if (t0 != 2 && t0 != 1) {
        return;
    }
    self->field_81D4 = -1;
    self->field_8178 = 0;
    self->field_8 = 0;
    self->field_8184 = 0;
    self->field_8180 = 1.0f;
    SetStatusToSend__17CGtNetworkHeadsetF25EHeadsetTalkControlStatusi(self, (EHeadsetTalkControlStatus)4, -1);
}
