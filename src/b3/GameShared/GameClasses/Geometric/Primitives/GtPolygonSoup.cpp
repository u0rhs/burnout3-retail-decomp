// GtPolygonSoup.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> GtPolygonSoup.cpp.
// Area: src/b3/GameShared/GameClasses/Geometric/Primitives, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Geometric/Primitives/GtPolygonSoup.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtPolygonSoup.h"
#include "b3/classes/CGtPolygonSoup16.h"

struct UnkStruct_002BF7B0_e0;
struct UnkStruct_002BF7D0_e0;

struct UnkStruct_002BF7B0_e0 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_002BF7D0_e0 {
    unsigned char pad_0[0x1];
};

// CGtPolygonSoup16::FixUp() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtPolygonSoup.cpp.
// 0x002BF7B0
void CGtPolygonSoup16::FixUp()
{
    field_0 = ((char *)this + (int)field_0);
    field_4 = ((char *)this + (int)field_4);
}

// CGtPolygonSoup::FixUp() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtPolygonSoup.cpp.
// 0x002BF7D0
void CGtPolygonSoup::FixUp()
{
    field_0 = ((char *)this + (int)field_0);
    field_4 = ((char *)this + (int)field_4);
}
