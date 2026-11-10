// B3FogPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3FogPS2.cpp.
// Area: src/b3/gamesource/Graphics/Fog/Ps2, [L] Revenge (SLUS_212.42) GameSource/Graphics/Fog/Ps2/B4FogPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/GtMath.h"

#include "b3/classes/CB3Fog.h"
#include "b3/classes/UnkStruct_D_004E08B0.h"
#include "b3/classes/UnkStruct_D_004E0B5C.h"
#include "b3/classes/UnkStruct_D_004E0B60.h"

extern UnkStruct_D_004E0B5C D_004E0B5C;
extern UnkStruct_D_004E0B60 D_004E0B60;
extern UnkStruct_D_004E08B0 D_004E08B0;

// CB3Fog::CalculateClipPlanes(float*,float*,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3FogPS2.cpp.
// 0x00240EF0
void CB3Fog::CalculateClipPlanes(float* p0, float* p1, float p2)
{
    float mm0 = (p2 * D_004E0B5C.field_0);
    field_0 = GtMath::Min(GtMath::Max(mm0, D_004E0B60.field_0), D_004E08B0.field_0);
    *p0 = ((float)10000);
}
