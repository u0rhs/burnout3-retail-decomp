// GtSoundRealVoice.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> GtSoundRealVoice.cpp.
// Area: src/b3/GameShared/GameClasses/Sound, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundRealVoice.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtSoundRealVoice.h"

extern "C" void _rwaSPU2VoiceSetWave(UnkStruct_00385680_1 *, int);

// CGtSoundRealVoice::IgnoreGlobalPitch() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundRealVoice.cpp.
// 0x00385240
void CGtSoundRealVoice::IgnoreGlobalPitch()
{
    field_1B = (field_1B | 16);
}

// CGtSoundRealVoice::MuteDryVoice(int,bool) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundRealVoice.cpp.
// 0x00385250
void CGtSoundRealVoice::MuteDryVoice(int p0, bool p1)
{
}

// CGtSoundRealVoice::Stop() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundRealVoice.cpp.
// 0x00385680
void CGtSoundRealVoice::Stop()
{
    field_14->field_30->field_0 = 1;
    _rwaSPU2VoiceSetWave(field_14, 0);
    field_18 = 0;
    field_1B = (field_1B & 1);
}
