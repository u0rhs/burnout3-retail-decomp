// GtSoundListener.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> GtSoundListener.cpp.
// Area: src/b3/GameShared/GameClasses/Sound, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundListener.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtSoundListener.h"

extern "C" void RwaObjDestroy(int, int, int);
extern "C" int RwaVirtualListenerCreate(int, int, int, int);

// CGtSoundListener::GetRWAListener() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundListener.cpp.
// 0x00384920
int CGtSoundListener::GetRWAListener()
{
    return field_8;
}

// CGtSoundListener::Destruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundListener.cpp.
// 0x00384930
void CGtSoundListener::Destruct()
{
    int t0 = field_8;
    if (t0 == 0) return;
    RwaObjDestroy(t0, 0, 0);
    field_8 = 0;
}

// CGtSoundListener::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundListener.cpp.
// 0x00384970
void CGtSoundListener::Release()
{
}

// CGtSoundListener::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundListener.cpp.
// 0x003849F0
void CGtSoundListener::Construct()
{
    int r0 = RwaVirtualListenerCreate(0, 4, 0, 0);
    field_8 = r0;
    field_4 = 0;
}
