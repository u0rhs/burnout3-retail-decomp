// GtNetworkHeadset.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> GtNetworkHeadset.cpp, 2 placed between two of them by address contiguity (N2).
// Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtNetworkHeadset.h"
#include "b3/classes/EHeadsetTalkControlStatus.h"

struct UnkStruct_002BFB00;
struct UnkStruct_002C02D0;

struct UnkStruct_002BFB00 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x8114];
    int field_8120;
    unsigned char pad_8124[0x40];
    int field_8164;
    unsigned char pad_8168[0x10];
    int field_8178;
    unsigned char pad_817C[0x4];
    float field_8180;
    float field_8184;
    int field_8188;
    unsigned char pad_818C[0x48];
    int field_81D4;
};

struct UnkStruct_002C02D0 {
    unsigned char pad_0[0x817C];
    float field_817C;
};

extern "C" void SetStatusToSend__17CGtNetworkHeadsetF25EHeadsetTalkControlStatusi(void *, EHeadsetTalkControlStatus, int);  // CGtNetworkHeadset::SetStatusToSend(EHeadsetTalkControlStatus,int)

// func_002BFB00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002BFB00
extern "C" void func_002BFB00(UnkStruct_002BFB00 * self)
{
    switch (self->field_8) {
    case 0:
        break;
    case 1:
        if (!(self->field_8184 <= 3.0f)) {
            SetStatusToSend__17CGtNetworkHeadsetF25EHeadsetTalkControlStatusi(self, (EHeadsetTalkControlStatus)5, -1);
            self->field_8 = 0;
            self->field_8184 = 0.0f;
            return;
        }
        break;
    case 2:
        if (!(self->field_8184 <= 25.0f)) {
            self->field_81D4 = -1;
            self->field_8178 = 0;
            self->field_8180 = 1.0f;
            SetStatusToSend__17CGtNetworkHeadsetF25EHeadsetTalkControlStatusi(self, (EHeadsetTalkControlStatus)4, -1);
            self->field_8 = 0;
            self->field_8184 = 0.0f;
            return;
        }
        break;
    case 3:
        if (!(self->field_8184 <= 3.0f)) {
            self->field_8188 = -1;
            self->field_8 = 0;
            self->field_8184 = 0.0f;
            return;
        }
        break;
    case 4:
        if (!(self->field_8184 <= 30.0f)) {
            self->field_81D4 = -1;
            self->field_8188 = -1;
            self->field_8120 = 0;
            self->field_8164 = -1;
            self->field_8 = 0;
            self->field_8184 = 0.0f;
            return;
        }
        break;
    default:
        break;
    }
}

// func_002C02D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002C02D0
extern "C" float func_002C02D0(UnkStruct_002C02D0 * self)
{
    return self->field_817C;
}

// CGtNetworkHeadset::GetMaximumTalkTime() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkHeadset.cpp.
// 0x002C02E0
float CGtNetworkHeadset::GetMaximumTalkTime()
{
    return field_8178;
}

// CGtNetworkHeadset::IsRequestingTalk() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkHeadset.cpp.
// 0x002C0370
bool CGtNetworkHeadset::IsRequestingTalk()
{
    return (field_8 == 1);
}

// CGtNetworkHeadset::IsTalking() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkHeadset.cpp.
// 0x002C0380
bool CGtNetworkHeadset::IsTalking()
{
    return (field_8 == 2);
}
