// B3ConvexHullCollide.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3ConvexHullCollide.cpp.
// Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/GtMathPs2.h"

#include "b3/classes/CB3CollidingBody.h"
#include "b3/classes/CB3ConvexHullCollide.h"
#include "b3/classes/CB3HullWorldTriCollideParams.h"
#include "b3/classes/UnkStruct_D_01E83670.h"

extern UnkStruct_D_01E83670 D_01E83670;
extern "C" int func_002B7F70(CB3ConvexHullCollide *, void *);

// CB3ConvexHullCollide::CollideBodyHullWithWorld(CB3HullWorldTriCollideParams*,CB3CollidingBody*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ConvexHullCollide.cpp.
// 0x002B9470
int CB3ConvexHullCollide::CollideBodyHullWithWorld(CB3HullWorldTriCollideParams* p0, CB3CollidingBody* p1)
{
    field_0 = p0->field_208;
    UnkStruct_002B9470_2 * t0 = p0->field_204;
    field_30 = t0->field_0;
    field_40 = t0->field_10;
    field_50 = t0->field_20.mData;
    field_60 = t0->field_30;
    field_70 = p0->field_70;
    field_80 = p0->field_80;
    field_90 = p0->field_90;
    field_A0 = p0->field_A0;
    field_F4 = ((char *)p0 + 0x1D0);
    field_F0 = p0->field_200;
    if (p0->field_214 == 0) {
        field_100 = -p0->field_204->field_20;
    } else {
        field_100.mData = p0->field_140;
    }
    field_111 = p0->field_214;
    int r0 = func_002B7F70(this, &D_01E83670);
    return (r0 & 255);
}
