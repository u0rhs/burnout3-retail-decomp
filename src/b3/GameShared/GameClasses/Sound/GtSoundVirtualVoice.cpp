// GtSoundVirtualVoice.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> GtSoundVirtualVoice.cpp.
// Area: src/b3/GameShared/GameClasses/Sound, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundVirtualVoice.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtSoundVirtualVoice.h"

// CGtSoundVirtualVoice::IgnoreGlobalPitch() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVirtualVoice.cpp.
// 0x003872D0
void CGtSoundVirtualVoice::IgnoreGlobalPitch()
{
    field_2F = (field_2F | 16);
}

// CGtSoundVirtualVoice::ForgetMe(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVirtualVoice.cpp.
// 0x003872E0
void CGtSoundVirtualVoice::ForgetMe(float p0)
{
    field_2F = (field_2F | 4);
    field_20 = p0;
    field_1C = p0;
}

// CGtSoundVirtualVoice::IsPlaying() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVirtualVoice.cpp.
// 0x00387980
bool CGtSoundVirtualVoice::IsPlaying()
{
    unsigned char t0 = field_2C;
    switch (t0) {
    case 0:
    case 1:
    case 3:
        if ((field_2F & 64) == 0) {
            return (((field_4->field_8A & 2) != 0) != false);
        }
        if ((field_2F & 128) != 0) {
            if (((field_4->field_8A & 2) != 0) == false) {
                if (t0 == 0) {
                    field_0 = 1;
                }
            }
        }
        return (0 < (field_2F & 128));
    case 2:
        return (0 < (field_2F & 8));
    default:
        return 0;
    }
}
