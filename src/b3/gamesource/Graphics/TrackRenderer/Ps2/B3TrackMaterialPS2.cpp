// B3TrackMaterialPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3TrackMaterialPS2.cpp.
// Area: src/b3/gamesource/Graphics/TrackRenderer/Ps2, [L] Revenge (SLUS_212.42) GameSource/Graphics/TrackRenderer/Ps2/B4TrackMaterialPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3TrackMaterial.h"

// CB3TrackMaterial::Prepare() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrackMaterialPS2.cpp.
// 0x0026A160
int CB3TrackMaterial::Prepare()
{
    field_10 = 0;
    field_1C = 0;
    return 1;
}

// CB3TrackMaterial::FixUp() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrackMaterialPS2.cpp.
// 0x0026A170
void CB3TrackMaterial::FixUp()
{
    void * * t0 = field_C;
    if (t0 == 0) return;
    field_C = (void * *)((char *)t0 + (int)this);
    for (int i = 0; (i < field_11); i++) {
        field_C[i] = &field_0[(int)field_C[i]];
    }
}
