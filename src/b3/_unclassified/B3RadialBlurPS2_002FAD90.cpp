// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// CB3RadialBlur::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RadialBlurPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (entry field is an int record address; strcasecmp(((blk*)(t2+0x90))->field_18) per N113/SunRenderer; goto found exit).

#include "b3/GtMathPs2.h"

#include "b3/classes/CB3RadialBlur.h"
#include "b3/classes/UnkStruct_D_004C4540.h"
#include "b3/classes/UnkStruct_D_004E06B0.h"
#include "b3/classes/UnkStruct_D_00518688.h"

struct UnkStruct_002FAD90_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

extern UnkStruct_D_004E06B0 D_004E06B0;
extern UnkStruct_D_00518688 D_00518688;
extern UnkStruct_D_004C4540 D_004C4540;
extern "C" int strcasecmp(const char *, const void *);

// 0x002FAD90
int CB3RadialBlur::Prepare()
{
    field_0 = 0.5f;
    field_4 = 0.5f;
    field_8 = 0.5f;
    field_C = 0.5f;
    field_10 = 0.99f;
    field_14 = 0.99f;
    field_18 = 1.0f;
    field_1C = 0;
    field_20.SetX(0.0f);
    field_20.SetY(0.0f);
    field_20.SetZ(0.0f);
    field_30 = 0;
    UnkStruct_002FAD90_3 * t0 = D_00518688.field_0;
    int t2;
    int i;
    for (i = 0; i < t0->field_8; i++) {
        t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_002FAD90_blk *)(t2 + 0x90))->field_18, &D_004C4540) == 0) {
            goto found;
        }
    }
    t2 = 0;
found:
    field_40 = t2;
    return 1;
}
