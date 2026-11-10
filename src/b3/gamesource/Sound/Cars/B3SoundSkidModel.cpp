// B3SoundSkidModel.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3SoundSkidModel.cpp, 1 by a medium-confidence name confirmed by a neighbour.
// Area: src/b3/gamesource/Sound/Cars, [L] Revenge (SLUS_212.42) GameSource/Sound/Cars/B4SoundSkidModel.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SoundSkidModel.h"
#include "b3/classes/CB3SoundSkidModelGraph.h"

// CB3SoundSkidModelGraph::CalcVolumeOutput(float,float&) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundSkidModel.cpp.
// 0x0028E120
void CB3SoundSkidModelGraph::CalcVolumeOutput(float p0, float & p1) const
{
    float lo = field_0[0].field_0;
    float hi = field_0[1].field_0;
    float t = p0 < lo ? lo : (p0 > hi ? hi : p0);
    unsigned int i;
    for (i = 0; i < 1; i++) {
        if (t >= field_0[i].field_0 && t < field_0[i + 1].field_0) {
            break;
        }
    }
    float d = field_0[i + 1].field_0 - field_0[i].field_0;
    float r;
    if (0.0f != d) {
        float v = (t - field_0[i].field_0) / d;
        float y0 = field_0[i].field_4;
        float y1 = field_0[i + 1].field_4;
        r = 0.0f + y0 + v * (y1 - y0);
    } else {
        r = field_0[i].field_4;
    }
    p1 = p1 * r;
}

// CB3SoundSkidModel::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3SoundSkidModel.cpp.
// 0x0028E200
void CB3SoundSkidModel::Destruct()
{
}
