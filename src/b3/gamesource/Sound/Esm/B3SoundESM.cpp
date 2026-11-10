// B3SoundESM.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3SoundESM.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Sound/Esm, [L] Revenge (SLUS_212.42) GameSource/Sound/Esm/B4SoundESM.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SoundESMHigh.h"
#include "b3/classes/CB3SoundESMLow.h"
#include "b3/classes/CGtSoundRealVoice.h"
#include "b3/classes/CGtSoundVirtualVoice.h"

struct UnkStruct_00287B80;
struct UnkStruct_00287B80_1;
struct UnkStruct_00287B80_e0;

struct UnkStruct_00287B80_1 {
    unsigned char pad_0[0x3C];
    UnkStruct_00287B80_e0 * field_3C;
    unsigned char field_40;
};

struct UnkStruct_00287B80_e0 {
    unsigned char pad_0[0xD];
    unsigned char field_D;
    unsigned char pad_E[0x2];
};

struct UnkStruct_00287B80 {
    unsigned char pad_0[0x2C];
    UnkStruct_00287B80_1 * field_2C;
    unsigned char pad_30[0x27];
    unsigned char field_57;
    unsigned char pad_58[0x8];
    int field_60[1];  // [G] element count unknown
    unsigned char pad_64[0x2C];
    int field_90;
};

extern "C" void func_00288C20(void *);
extern "C" void Stop__17CGtSoundRealVoiceFv(void *);  // CGtSoundRealVoice::Stop(), passed 1 more argument(s) [G]
extern "C" void Stop__20CGtSoundVirtualVoiceFv(void *);  // CGtSoundVirtualVoice::Stop(), passed 1 more argument(s) [G]

// CB3SoundESMLow::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESM.cpp.
// 0x00287940
void CB3SoundESMLow::Construct()
{
    func_00288C20(this);
    field_56 = 0;
}

// func_00287B80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00287B80
extern "C" void func_00287B80(UnkStruct_00287B80 * self)
{
    int m0 = 0;
    while ((unsigned int)m0 < (unsigned int)self->field_2C->field_40) {
        switch ((self->field_2C->field_3C[m0].field_D & 15)) {
        case 0:
            int t0 = self->field_60[m0];
            if (t0 != 0) {
                Stop__17CGtSoundRealVoiceFv((void *)t0);
            }
            break;
        case 1:
            break;
        case 2:
            int t1 = self->field_90;
            if (t1 != 0) {
                Stop__20CGtSoundVirtualVoiceFv((void *)t1);
            }
            break;
        default:
            break;
        }
        m0 = (m0 + 1);
    }
    self->field_57 = 0;
}

// CB3SoundESMHigh::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESM.cpp.
// 0x00288440
void CB3SoundESMHigh::Construct()
{
    func_00288C20(this);
    field_56 = 1;
    field_94.Construct();
    field_90 = 0;
}
