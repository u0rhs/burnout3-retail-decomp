// CB3AIAvoidanceMap::GetSafestChannel() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAvoidance.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3AIAvoidanceMap.h"

// 0x0013E790
int CB3AIAvoidanceMap::GetSafestChannel()
{
    int lo = (int)(5.0f * -field_44C) + 128;
    if (lo < 0) {
        lo = 0;
    }
    if (lo >= 256) {
        lo = 255;
    }
    int hi = (int)(5.0f * (field_444 - field_44C)) + 128;
    if (hi < 0) {
        hi = 0;
    }
    if (hi >= 256) {
        hi = 255;
    }
    int best = 128;
    float bestv = -0.1f;
    for (int i = lo + 3; i < hi - 3; i++) {
        float v = 0.2f * (float)(field_143[i] + (field_141[i] + (field_140[i] + (field_13D[i] + field_13F[i]))));
        v *= 0.03137255f;
        float a = (float)i / 128.0f;
        float b = (float)((i - lo) << 1) / (float)(hi - lo);
        if (!(a <= 1.0f)) {
            a = 2.0f - a;
        }
        if (!(b <= 1.0f)) {
            b = 2.0f - b;
        }
        float s = v * (a * b);
        if (!(s < bestv)) {
            bestv = s;
            best = i;
        }
    }
    return best;
}
