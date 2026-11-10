// B3SoundTrafficVehicle.cpp -- translation unit regrouped by tools/tu_merge.py from 6 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 6 function(s) named in research/retail_names.csv -> B3SoundTrafficVehicle.cpp.
// Area: src/b3/gamesource/Sound/Traffic, [L] Revenge (SLUS_212.42) GameSource/Sound/Traffic/B4SoundTrafficVehicle.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SoundTrafficVehicle.h"
#include "b3/classes/CGtSoundVirtualVoice.h"
#include "b3/classes/UnkStruct__gnCarriageCount.h"

extern UnkStruct__gnCarriageCount _gnCarriageCount;
extern "C" int func_002F4F10(void *);

// CB3SoundTrafficVehicle::GetPlayerIndex() const -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTrafficVehicle.cpp.
// 0x00278810
signed char CB3SoundTrafficVehicle::GetPlayerIndex() const
{
    return field_12C;
}

// CB3SoundTrafficVehicle::IsHorning() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTrafficVehicle.cpp.
// 0x00278820
bool CB3SoundTrafficVehicle::IsHorning()
{
    return (field_C8 != 0);
}

// CB3SoundTrafficVehicle::Deactivate() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTrafficVehicle.cpp.
// 0x00278E70
void CB3SoundTrafficVehicle::Deactivate()
{
    CGtSoundVirtualVoice * t0 = field_C0;
    if (t0 != 0) {
        t0->Stop();
        field_C0 = 0;
    }
    CGtSoundVirtualVoice * t1 = field_C4;
    if (t1 != 0) {
        t1->Stop();
        field_C4 = 0;
    }
    CGtSoundVirtualVoice * t2 = field_C8;
    if (t2 != 0) {
        t2->Stop();
        field_C8 = 0;
    }
    if (field_120 == 7) {
        _gnCarriageCount.field_0 = (_gnCarriageCount.field_0 + -1);
    }
    field_12C = -1;
    field_110 = -1;
    field_124 = 0;
    field_0 = 0;
    field_10.Stop();
}

// CB3SoundTrafficVehicle::GetID() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTrafficVehicle.cpp.
// 0x00279550
int CB3SoundTrafficVehicle::GetID()
{
    return field_110;
}

// CB3SoundTrafficVehicle::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTrafficVehicle.cpp.
// 0x00279560
void CB3SoundTrafficVehicle::Release()
{
    CGtSoundVirtualVoice * t0 = field_C0;
    if (t0 != 0) {
        t0->Stop();
        field_C0 = 0;
    }
    CGtSoundVirtualVoice * t1 = field_C4;
    if (t1 != 0) {
        t1->Stop();
        field_C4 = 0;
    }
    CGtSoundVirtualVoice * t2 = field_C8;
    if (t2 != 0) {
        t2->Stop();
        field_C8 = 0;
    }
    field_110 = -1;
    field_124 = 0;
    field_0 = 0;
    field_124 = 0;
    field_10.Release();
}

// CB3SoundTrafficVehicle::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTrafficVehicle.cpp.
// 0x0027A550
int CB3SoundTrafficVehicle::Prepare()
{
    field_12C = -1;
    field_110 = -1;
    field_124 = 0;
    CGtSoundVirtualVoice * t0 = field_C8;
    if (t0 != 0) {
        t0->Stop();
        field_C8 = 0;
    }
    CGtSoundVirtualVoice * t1 = field_C0;
    if (t1 != 0) {
        t1->Stop();
        field_C0 = 0;
    }
    CGtSoundVirtualVoice * t2 = field_C4;
    if (t2 != 0) {
        t2->Stop();
        field_C4 = 0;
    }
    func_002F4F10(((char *)this + 0x50));
    func_002F4F10(((char *)this + 0x7C));
    field_100 = 1.0f;
    field_104 = 1.0f;
    field_108 = 1.0f;
    field_10C = 1.0f;
    return 1;
}
