// B3SoundCrashedTraffic.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> B3SoundCrashedTraffic.cpp.
// Area: src/b3/gamesource/Sound/Traffic, [L] Revenge (SLUS_212.42) GameSource/Sound/Traffic/B4SoundCrashedTraffic.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SoundCrashedTraffic.h"
#include "b3/classes/CB3VehiclePhysics.h"
#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/CGtSoundBankManager.h"
#include "b3/classes/CGtSoundVirtualVoice.h"
#include "b3/classes/UnkStruct_D_004C0930.h"
#include "b3/classes/UnkStruct_D_004C0948.h"
#include "b3/classes/UnkStruct_D_004C0958.h"
#include "b3/classes/UnkStruct_D_004C0968.h"
#include "b3/classes/UnkStruct_D_004C0978.h"
#include "b3/classes/UnkStruct_D_004E1C08.h"

struct UnkStruct_00290900_2;

struct UnkStruct_00290900_2 {
    unsigned long field_0;
    unsigned long field_8;
    unsigned long field_10;
    unsigned long field_18;
};

extern UnkStruct_D_004E1C08 D_004E1C08;
extern CGtSoundBankManager D_01E75648;
extern UnkStruct_D_004C0930 D_004C0930;
extern UnkStruct_D_004C0948 D_004C0948;
extern UnkStruct_D_004C0958 D_004C0958;
extern UnkStruct_D_004C0968 D_004C0968;
extern UnkStruct_D_004C0978 D_004C0978;
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const
extern "C" unsigned long GtIDCompress__FPCc(void *);

// CB3SoundCrashedTraffic::SetActive() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashedTraffic.cpp.
// 0x00290430
void CB3SoundCrashedTraffic::SetActive()
{
    field_4 = 5;
}

// CB3SoundCrashedTraffic::SetOwner(CB3VehiclePhysics*) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashedTraffic.cpp.
// 0x00290440
void CB3SoundCrashedTraffic::SetOwner(CB3VehiclePhysics* p0)
{
    field_0 = p0;
}

// CB3SoundCrashedTraffic::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashedTraffic.cpp.
// 0x00290900
bool CB3SoundCrashedTraffic::Prepare()
{
    UnkStruct_00290900_2 local;  // [G] the frame's one local (size: up to the frame top)
    field_4 = 0;
    field_0 = 0;
    field_20 = 1.0f;
    field_24 = 0;
    field_30 = 1.0f;
    field_34 = 1.0f;
    if (field_8 == 0) {
        int r0 = D_01E75648.LoadBank((const char*)D_004E1C08.field_0, 1, 1, 6144);
        field_8 = r0;
    }
    if (field_8 == 0) {
        return 0;
    }
    if (field_44 == 0) {
        int r1 = D_01E75648.LoadBank((const char*)&D_004C0930, 1, 1, 6144);
        field_44 = r1;
    }
    if (field_44 != 0) {
        unsigned long r2 = GtIDCompress__FPCc(&D_004C0948);
        local.field_18 = r2;
        int r3 = FindWave__12CGtSoundBankCFRCUlb((void *)field_44, ((char *)&local + 0x18), 0);
        field_48 = r3;
        if (field_8 != 0) {
            unsigned long r4 = GtIDCompress__FPCc(&D_004C0958);
            local.field_10 = r4;
            int r5 = FindWave__12CGtSoundBankCFRCUlb((void *)field_8, ((char *)&local + 0x10), 0);
            field_C = r5;
            unsigned long r6 = GtIDCompress__FPCc(&D_004C0968);
            local.field_8 = r6;
            int r7 = FindWave__12CGtSoundBankCFRCUlb((void *)field_8, ((char *)&local + 0x8), 0);
            field_10 = r7;
            unsigned long r8 = GtIDCompress__FPCc(&D_004C0978);
            local.field_0 = r8;
            int r9 = FindWave__12CGtSoundBankCFRCUlb((void *)field_8, &local, 0);
            field_14 = r9;
        }
        CGtSoundVirtualVoice * t0 = field_18;
        if (t0 != 0) {
            t0->Stop();
            field_18 = 0;
            field_1C = 0;
        }
        field_4 = 0;
        CGtSoundVirtualVoice * t1 = field_4C;
        if (t1 != 0) {
            t1->Stop();
            field_4C = 0;
            field_54 = 0;
        }
        CGtSoundVirtualVoice * t2 = field_50;
        if (t2 != 0) {
            t2->Stop();
            field_50 = 0;
            field_58 = 0;
        }
        field_38 = 0;
        return (field_8 == 0);
    }
    return 0;
}

// CB3SoundCrashedTraffic::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashedTraffic.cpp.
// 0x00290AD0
void CB3SoundCrashedTraffic::Construct()
{
    field_4 = 0;
    field_0 = 0;
    field_8 = 0;
    field_C = 0;
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
    field_44 = 0;
    field_1C = 0;
    field_20 = 1.0f;
    field_24 = 0;
    field_30 = 1.0f;
    field_34 = 1.0f;
}
