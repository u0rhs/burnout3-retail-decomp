// SFIOGetFileCallback__16CB3SFIOCallbacksFPc -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3SFIOCallbacks.h"

// 0x00360B10
extern "C" void SFIOGetFileCallback__16CB3SFIOCallbacksFPc()
{
    CB3SFIOCallbacks::gmeLastOperation = 0;
    CB3SFIOCallbacks::gmeError = 0;
    CB3SFIOCallbacks::gmeProcess = 2;
}
