// GtArray.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> GtArray.cpp.
// Area: src/b3/GameShared/GameClasses/Containers, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Containers/GtArray.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtArrayBase.h"

// CGtArrayBase::FixUp() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtArray.cpp.
// 0x002719B0
void CGtArrayBase::FixUp()
{
    field_C = (char **)((int)field_C + (int)this);
    for (int i = 0; i < field_8; i++) {
        char **p = field_C;
        if (p[i] != 0) {
            p[i] = p[i] + (int)this;
        }
    }
}
