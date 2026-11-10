// Prepare__14CB3SoundScrapeFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/CGtSoundVirtualVoice.h"
#include "b3/classes/UnkStruct_D_01E78D90.h"
#include "b3/classes/UnkStruct_kB3CarScrapeHiWaveId.h"
#include "b3/classes/UnkStruct_kB3CarScrapeLoWaveId.h"

struct UnkStruct_00283A50;

struct UnkStruct_00283A50 {
    unsigned char pad_0[0x10];
    CGtSoundVirtualVoice * field_10;
    CGtSoundVirtualVoice * field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
};

extern UnkStruct_D_01E78D90 D_01E78D90;
extern UnkStruct_kB3CarScrapeLoWaveId kB3CarScrapeLoWaveId;
extern UnkStruct_kB3CarScrapeHiWaveId kB3CarScrapeHiWaveId;
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const

// 0x00283A50
extern "C" int Prepare__14CB3SoundScrapeFv(UnkStruct_00283A50 * self)
{
    CGtSoundVirtualVoice * t0 = self->field_10;
    if (t0 != 0) {
        t0->Stop();
        self->field_10 = 0;
    }
    CGtSoundVirtualVoice * t1 = self->field_14;
    if (t1 != 0) {
        t1->Stop();
        self->field_14 = 0;
    }
    self->field_18 = -1;
    self->field_1C = -1;
    self->field_2C = 0;
    self->field_30 = 0;
    if (self->field_20 == 0) {
        int r2 = FindWave__12CGtSoundBankCFRCUlb((void *)D_01E78D90.field_0, &kB3CarScrapeLoWaveId, 0);
        self->field_20 = r2;
    }
    if (self->field_24 == 0) {
        int r3 = FindWave__12CGtSoundBankCFRCUlb((void *)D_01E78D90.field_0, &kB3CarScrapeHiWaveId, 0);
        self->field_24 = r3;
    }
    self->field_28 = 0;
    return 1;
}
