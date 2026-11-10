// func_002F9970 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3NetworkMessage.h"
#include "b3/classes/CGtNetworkPlayerManager.h"

struct UnkStruct_002F9970;

struct UnkStruct_002F9970 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
    int field_10;
};

extern CGtNetworkPlayerManager D_01E32AE0;
extern "C" void Prepare__17CB3NetworkMessageFib(void *, int, bool);  // CB3NetworkMessage::Prepare(int,bool)

// 0x002F9970
extern "C" void func_002F9970(UnkStruct_002F9970 * self)
{
    if ((self->field_0 & 1) == 1) return;
    int r0 = D_01E32AE0.GetMyPlayerID();
    self->field_10 = r0;
    Prepare__17CB3NetworkMessageFib(self, 15, 0);
}
