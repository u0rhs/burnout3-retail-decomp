// GtSoundVoiceManager.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 5 function(s) named in research/retail_names.csv -> GtSoundVoiceManager.cpp.
// Area: src/b3/GameShared/GameClasses/Sound, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundVoiceManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtSoundManager.h"
#include "b3/classes/CGtSoundRealVoice.h"
#include "b3/classes/CGtSoundVirtualVoice.h"
#include "b3/classes/CGtSoundVoiceManager.h"

struct UnkStruct_00388B30_e1;

struct UnkStruct_00388B30_e1 {
    unsigned char pad_0[0x20];
};

extern "C" void Pause__20CGtSoundVirtualVoiceFv(void *, bool);  // CGtSoundVirtualVoice::Pause()
extern "C" void Pause__17CGtSoundRealVoiceFv(void *, bool);  // CGtSoundRealVoice::Pause()
extern "C" void Stop__20CGtSoundVirtualVoiceFv(void *);  // CGtSoundVirtualVoice::Stop()
extern "C" void Stop__17CGtSoundRealVoiceFv(void *);  // CGtSoundRealVoice::Stop()

// CGtSoundVoiceManager::PauseAll() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVoiceManager.cpp.
// 0x00388B30
extern "C" void PauseAll__20CGtSoundVoiceManagerFv(CGtSoundVoiceManager * self, bool p0)
{
    for (unsigned int i = 0; i < 128; i++) {
        Pause__20CGtSoundVirtualVoiceFv((char *)&self->field_0[i] + 0x4, p0);
    }
    for (unsigned int i1 = 0; i1 < 16; i1++) {
        Pause__17CGtSoundRealVoiceFv((char *)self + (i1 << 5) + 0x1A04, p0);
    }
}

// CGtSoundVoiceManager::FreeVirtualVoice(CGtSoundVirtualVoice*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVoiceManager.cpp.
// 0x00388EA0
void CGtSoundVoiceManager::FreeVirtualVoice(CGtSoundVirtualVoice* p0)
{
    Stop__20CGtSoundVirtualVoiceFv(p0);
    p0->field_2F = (p0->field_2F & 254);
}

// CGtSoundVoiceManager::FreeRealVoice(CGtSoundRealVoice*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVoiceManager.cpp.
// 0x00388EE0
void CGtSoundVoiceManager::FreeRealVoice(CGtSoundRealVoice* p0)
{
    Stop__17CGtSoundRealVoiceFv(p0);
    p0->field_1B = (p0->field_1B & 254);
}

// CGtSoundVoiceManager::AllocVirtualVoice() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVoiceManager.cpp.
// 0x00388F20
void * CGtSoundVoiceManager::AllocVirtualVoice()
{
    int t0 = field_1E38;
    if (t0 == 0) {
        return 0;
    }
    field_1E38 = (t0 + -1);
    UnkStruct_00388F20_e1 * e1 = &field_0[field_1D44[field_1E38]];
    e1->field_33 = (e1->field_33 | 1);
    return ((char *)&field_0[field_1D44[field_1E38]] + 0x4);
}

// CGtSoundVoiceManager::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVoiceManager.cpp.
// 0x00389070
void CGtSoundVoiceManager::Destruct()
{
}
