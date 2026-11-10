// B3ConvexHullMaker.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3ConvexHullMaker.cpp.
// Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/GtMathPs2.h"

#include "b3/classes/CB3ConvexHull.h"
#include "b3/classes/CB3ConvexHullMaker.h"
#include "b3/classes/CB3ConvexHullVertex.h"
#include "b3/classes/CB3VehicleDeform.h"

struct UnkStruct_003D8D60_1;

struct UnkStruct_003D8D60_1 {
    unsigned char pad_0[0xC0];
};

extern "C" void func_003D9360(CB3ConvexHullMaker *, UnkStruct_003D8D60_1 *);

// CB3ConvexHullMaker::MakeConvexHull(CB3ConvexHull*,float*,CB3ConvexHullVertex*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ConvexHullMaker.cpp.
// 0x003D8D60
void CB3ConvexHullMaker::MakeConvexHull(CB3ConvexHull* p0, float* p1, CB3ConvexHullVertex* p2)
{
    UnkStruct_003D8D60_1 local;  // [G] the frame's one local (size: up to the frame top)
    // Retail leaves `local` (sp+0x20, 12 CGtV3d) uninitialized [C 0x3D8D60..]; [L] GetBasePoints / func_003D9360 carry its w
    // lanes of points 0..7 through, so the hull's vertex w lanes are stale words of this frame ([C] native3 capture: the word
    // at local+0x3C at entry, 0x3E5A98A2, is vertex 3's w after the call; [L] vertex 7's is a copy). Retail's own read; on a
    // host an uninitialized local (native3: MakeConvexHull's and CB3VehicleDeform::Impact's 8 words).
    field_0 = (CB3ConvexHullVertex *)p2;
    field_4 = (CB3ConvexHull *)p0;
    GetBasePoints((GtMathPs2::CGtV3d*)&local, p1);
    func_003D9360(this, &local);
    MakeVerticesIntoHull((GtMathPs2::CGtV3d*)&local);
}
