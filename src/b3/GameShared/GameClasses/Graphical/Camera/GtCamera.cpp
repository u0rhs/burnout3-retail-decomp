// GtCamera.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> GtCamera.cpp, 2 by a medium-confidence name confirmed by a neighbour.
// Area: src/b3/GameShared/GameClasses/Graphical/Camera, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Graphical/Camera/GtCamera.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtCamera.h"
#include "b3/classes/CGtCameraBehaviourDef.h"

// CGtCamera::SetBehaviours(CGtCameraBehaviourDef*,int) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtCamera.cpp.
// 0x0021B000
void CGtCamera::SetBehaviours(CGtCameraBehaviourDef* p0, int p1)
{
    field_34 = p0;
    field_38 = p1;
}

// CGtCamera::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtCamera.cpp.
// 0x0021B4C0
void CGtCamera::Destruct()
{
    field_3C = 0;
}

// CGtCamera::Construct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtCamera.cpp.
// 0x0021B4D0
void CGtCamera::Construct()
{
    field_38 = 0;
    field_3C = 0;
    field_30 = 0;
}
