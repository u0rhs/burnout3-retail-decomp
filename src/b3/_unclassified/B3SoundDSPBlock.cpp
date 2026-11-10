// B3SoundDSPBlock.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3SoundDSPBlock.cpp.
// Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SoundDSPDataBlock.h"
#include "b3/classes/UnkStruct__grCornerFrequency.h"
#include "b3/classes/UnkStruct__grSlope.h"
#include "b3/classes/UnkStruct__grdBGain.h"

extern UnkStruct__grCornerFrequency _grCornerFrequency;
extern UnkStruct__grdBGain _grdBGain;
extern UnkStruct__grSlope _grSlope;

// CB3SoundDSPDataBlock::Reset() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundDSPBlock.cpp.
// 0x002FC0E0
void CB3SoundDSPDataBlock::Reset()
{
    field_44 = 256;
    field_48 = 48000;
    field_34 = 0;
    field_3C = 0;
    field_40 = 0;
    field_38 = 0;
    if (field_70 == 2) {
        CalculateHighShelfCoefficients((1000.0f * _grCornerFrequency.field_0), _grdBGain.field_0, _grSlope.field_0);
    }
}

// CB3SoundDSPDataBlock::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundDSPBlock.cpp.
// 0x002FC160
void CB3SoundDSPDataBlock::Construct()
{
    field_44 = 256;
    field_48 = 48000;
    field_70 = 0;
    field_34 = 0x10000;
    field_3C = 0x10000;
    field_40 = 0x10000;
    field_38 = 0x10000;
    for (int i = 0; (i < 13); i++) {
        field_0[i] = 0x10000;
    }
    field_6E = 0;
    field_6C = 0;
    field_6A = 0;
    field_68 = 0;
}
