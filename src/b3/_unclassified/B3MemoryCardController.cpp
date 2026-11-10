// B3MemoryCardController.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3MemoryCardController.cpp.
// Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CMemoryCardFileBase.h"
#include "b3/classes/UnkStruct_D_004D13A8.h"
#include "b3/classes/UnkStruct_D_01EBE390.h"

extern UnkStruct_D_01EBE390 D_01EBE390;
extern UnkStruct_D_004D13A8 D_004D13A8;
extern "C" char * strcpy(char *, const char *);
extern "C" void sprintf(void *, void *, int, UnkStruct_004216A0_1 *);

// CMemoryCardFileBase::GetFullFilename() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MemoryCardController.cpp.
// 0x004216A0
void * CMemoryCardFileBase::GetFullFilename()
{
    UnkStruct_004216A0_1 * t0 = field_0;
    if (t0->field_0 == 0) {
        strcpy((char *)&D_01EBE390, (const char *)CMemoryCardFileBase::mgpacDirName);
    } else {
        sprintf(&D_01EBE390, &D_004D13A8, CMemoryCardFileBase::mgpacDirName, t0);
    }
    return &D_01EBE390;
}
