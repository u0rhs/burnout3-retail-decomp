// func_0041E8F0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtNetworkHeadset.h"

// 0x0041E8F0
// [C] returns GetIDOfTalkingNetworkPlayer's result: retail 0x41E8F0 is `j GetIDOfTalkingNetworkPlayer__17CGtNetworkHeadsetFPi`
// (a tail call, so v0 is the callee's), and func_00312A60 tests it at 0x312B4C (`beqz $v0`).
extern "C" int func_0041E8F0(CGtNetworkHeadset *self, int* p0)
{
    return self->GetIDOfTalkingNetworkPlayer(p0);
}
