// ChatMessageCallback__22CB3OnlineOpenLobbyPageFPcPcPv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3ChatDisplayComponent.h"
#include "b3/classes/EB3ChatDisplayOrientation.h"

struct UnkStruct_00396A40_0;

struct UnkStruct_00396A40_0 {
    unsigned char pad_0[0x100];
};

extern CB3ChatDisplayComponent D_01E8CBE0;
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(int, UnkStruct_00396A40_0 *, int);

// 0x00396A40
extern "C" int ChatMessageCallback__22CB3OnlineOpenLobbyPageFPcPcPv(int n0, int p0)
{
    UnkStruct_00396A40_0 local;  // [G] the frame's one local (size: up to the frame top)
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(p0, &local, 128);
    D_01E8CBE0.AddNewMessage((char*)n0, (const unsigned short*)&local);
    return 1;
}
