// LobbyAlloc -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct__gMemoryAllocator.h"

extern UnkStruct__gMemoryAllocator _gMemoryAllocator;
extern "C" void *Malloc__9CGtMallocFUi(void *, unsigned);

// 0x0033C8C0
extern "C" void *LobbyAlloc(unsigned n) { return Malloc__9CGtMallocFUi(&_gMemoryAllocator, n); }
