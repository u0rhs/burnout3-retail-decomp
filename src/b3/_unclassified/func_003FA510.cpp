// func_003FA510 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/CGtSoundBankManager.h"
#include "b3/classes/UnkStruct_D_004CE9C8.h"
#include "b3/classes/UnkStruct_D_004CE9D0.h"
#include "b3/classes/UnkStruct_D_004E1EC0.h"
#include "b3/classes/UnkStruct_D_004E1EC4.h"

struct UnkStruct_003FA510;

struct UnkStruct_003FA510 {
    unsigned char pad_0[0x164];
    void * field_164;
    int field_168;
    unsigned char pad_16C[0x28];
    signed char field_194;
    unsigned char pad_195[0x3];
    int field_198;
};

extern UnkStruct_D_004E1EC0 D_004E1EC0;
extern UnkStruct_D_004E1EC4 D_004E1EC4;
extern UnkStruct_D_004CE9D0 D_004CE9D0;
extern CGtSoundBankManager D_01E75648;
extern UnkStruct_D_004CE9C8 D_004CE9C8;
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const
extern "C" void sprintf(void *, void *, int, int, int, int, int, int, float, float, float, float, float, float, float, float);

// 0x003FA510
extern "C" int func_003FA510(UnkStruct_003FA510 * self, int p0, int p1, int p2, int p3, int p4, int p5, int p6, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7)
{
    if ((self->field_198 & 16) == 0) {
        sprintf(((char *)self + 0x110), &D_004CE9D0, D_004E1EC0.field_0, D_004E1EC4.field_0, self->field_194, p4, p5, p6, f0, f1, f2, f3, f4, f5, f6, f7);
        self->field_198 = (self->field_198 | 16);
    }
    int r1 = D_01E75648.LoadBank((const char*)((char *)self + 0x110), 1, 0, 2048);
    self->field_164 = (void *)r1;
    if (self->field_164 == 0) {
        return 0;
    }
    int r2 = FindWave__12CGtSoundBankCFRCUlb(self->field_164, &D_004CE9C8, 0);
    self->field_168 = r2;
    self->field_198 = (self->field_198 & -17);
    self->field_194 = (self->field_194 + 1);
    if (self->field_194 == 10) {
        self->field_194 = 0;
    }
    return 1;
}
