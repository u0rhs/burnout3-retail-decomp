// B3ReplayFrame.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3ReplayFrame.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4ReplayFrame.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3CrashReplayFrame.h"
#include "b3/classes/CB3ReplayFrame.h"
#include "b3/classes/CDrivingControls.h"

// CB3CrashReplayFrame::RetrieveDrivingControls(CDrivingControls*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ReplayFrame.cpp.
// 0x00154AC0
int CB3CrashReplayFrame::RetrieveDrivingControls(CDrivingControls* p0)
{
    p0->field_C = (((float)field_0) / 127.0f);
    p0->field_18 = (((float)(field_1 & 31)) / 31.0f);
    p0->field_8 = (((float)((field_1 >> 5) & 7)) / 7.0f);
    p0->field_0 = (field_2 & 31);
    p0->field_14 = field_4;
    p0->field_10 = (((float)field_3) / 127.0f);
    p0->field_C = (((float)field_0) / 127.0f);
    p0->field_18 = (((float)(field_1 & 31)) / 31.0f);
    p0->field_8 = (((float)((field_1 >> 5) & 7)) / 7.0f);
    p0->field_0 = (field_2 & 31);
    return ((field_2 >> 5) & 7);
}

// CB3ReplayFrame::RetrieveDrivingControls(CDrivingControls*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ReplayFrame.cpp.
// 0x00154C90
int CB3ReplayFrame::RetrieveDrivingControls(CDrivingControls* p0)
{
    p0->field_C = (((float)field_0) / 127.0f);
    p0->field_18 = (((float)(field_1 & 31)) / 31.0f);
    p0->field_8 = (((float)((field_1 >> 5) & 7)) / 7.0f);
    p0->field_0 = (field_2 & 31);
    return ((field_2 >> 5) & 7);
}
