// B3MemoryManagerPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3MemoryManagerPS2.cpp.
// Area: src/b3/gamesource/Game/Ps2, [L] Revenge (SLUS_212.42) GameSource/Game/Ps2/B4MemoryManagerPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3MemoryManager.h"
#include "b3/classes/CB3MemoryManagerPS2.h"
#include "b3/classes/EB3MemoryBlock.h"
#include "b3/classes/EB3MemoryLayout.h"

extern "C" void ReleaseBlock__16CB3MemoryManagerF14EB3MemoryBlocki(void *, EB3MemoryBlock, int);  // CB3MemoryManager::ReleaseBlock(EB3MemoryBlock,int)

// CB3MemoryManagerPS2::ReleaseBlock(EB3MemoryBlock,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MemoryManagerPS2.cpp.
// 0x002223C0
void CB3MemoryManagerPS2::ReleaseBlock(EB3MemoryBlock p0, int p1)
{
    switch (p0) {
    case 23:
        field_99C.ReleaseMemoryBlock(field_984);
        break;
    case 24:
        field_9AC.ReleaseMemoryBlock(field_984);
        break;
    case 25:
        field_98C.ReleaseMemoryBlock(field_984);
        break;
    case 26:
        field_9BC.ReleaseMemoryBlock(field_984);
        break;
    case 4:
        int t0 = field_984;
        if (t0 != 0) {
            if (t0 == 2) {
                field_494.ReleaseMemoryBlock(t0);
            } else {
                field_174.ReleaseMemoryBlock(t0);
            }
        } else {
            field_934.ReleaseMemoryBlock(t0);
        }
        break;
    default:
        ReleaseBlock__16CB3MemoryManagerF14EB3MemoryBlocki(this, p0, p1);
        break;
    }
}
