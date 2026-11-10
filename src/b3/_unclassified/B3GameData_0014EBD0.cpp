// CB3GameData::SetGameDataFileName(char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3GameData.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3GameData.h"

extern "C" char * strncpy(char *, const char *, unsigned int);

// 0x0014EBD0
void CB3GameData::SetGameDataFileName(char* p0)
{
    strncpy(((char *)this + 0x458), p0, 256);
    field_589 = 1;
}
