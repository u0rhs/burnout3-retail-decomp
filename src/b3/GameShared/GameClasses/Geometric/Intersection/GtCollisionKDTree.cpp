// GtCollisionKDTree.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> GtCollisionKDTree.cpp.
// Area: src/b3/GameShared/GameClasses/Geometric/Intersection, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Geometric/Intersection/GtCollisionKDTree.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtCollisionKDTree.h"
#include "b3/classes/CGtPolygonSoup.h"
#include "b3/classes/CGtPolygonSoup16.h"

extern "C" void FixUp__14CGtPolygonSoupFv(void *);  // CGtPolygonSoup::FixUp()
extern "C" void FixUp__16CGtPolygonSoup16Fv(void *);  // CGtPolygonSoup16::FixUp()

// CGtCollisionKDTree::FixUp() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtCollisionKDTree.cpp.
// 0x003BE8D0
void CGtCollisionKDTree::FixUp()
{
    if (field_20 != 0) {
        field_20 = &field_0[(int)field_20];
    }
    if (field_24 != 0) {
        field_24 = (UnkStruct_003BE8D0_e1 *)&field_0[(int)field_24];
    }
    if (field_2C != 0) {
        for (unsigned short i = 0; i < field_28; i++) {
            FixUp__16CGtPolygonSoup16Fv(&field_24[i]);
        }
    } else {
        for (unsigned short i = 0; i < field_28; i++) {
            FixUp__14CGtPolygonSoupFv(&field_24[i]);
        }
    }
}
