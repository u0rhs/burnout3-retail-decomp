// func_001D0E00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

#include "b3/classes/CB3CrashActionDirector.h"
#include "b3/classes/CB3PhysicsManager.h"
#include "b3/classes/UnkStruct_D_0051BA88.h"

struct UnkStruct_001D0E00;
struct UnkStruct_001D0E00_4;
struct UnkStruct_001D0E00_e0;

struct UnkStruct_001D0E00_4 {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

struct UnkStruct_001D0E00_e0 {
    unsigned char pad_0[0x58];
    int field_58;
    unsigned char pad_5C[0x34];
    short field_90;
    unsigned char pad_92[0x1];
    unsigned char field_93;
    unsigned char pad_94[0x2C];
};

struct UnkStruct_001D0E00 {
    unsigned char pad_0[0x160];
    GtMathPs2::CGtV3d field_160;
    GtMathPs2::CGtV3d field_170;
    unsigned char pad_180[0x10];
    short field_190;
    unsigned char pad_192[0x2];
    int field_194;
    int field_198;
    unsigned char pad_19C[0x74];
    unsigned char field_210;
    unsigned char field_211;
    unsigned char field_212;
    unsigned char pad_213[0x5];
    signed char field_218;
    unsigned char pad_219[0x627];
    UnkStruct_001D0E00_e0 field_840[1];  // [G] element count unknown
    unsigned char pad_900[0x860];
    short field_1160;
    unsigned char pad_1162[0x7];
    signed char field_1169;
    unsigned char pad_116A[0x1E9];
    unsigned char field_1353;
    unsigned char pad_1354[0x1D0];
    int field_1524;
    unsigned char pad_1528[0x28];
    unsigned char field_1550;
    unsigned char pad_1551[0x17];
    UnkStruct_001D0E00_4 * field_1568;
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern CB3PhysicsManager D_0055EF70;
extern CB3CrashActionDirector D_0055E948;
extern "C" void * memset(void *, int, unsigned int);
extern "C" void func_001AB010(UnkStruct_001D0E00 *);
extern "C" void SetAIOutOfRange__8CB3AICarFv(UnkStruct_001D0E00_4 *);

// 0x001D0E00
extern "C" void func_001D0E00(UnkStruct_001D0E00 * self)
{
    self->field_1550 = 0;
    if (self->field_210 == 0) {
        int r0 = D_0051BA88.field_0->field_1B4->vfunc_B8();
        if (r0 != 0) {
            D_0055EF70.StopRaceCarBodyPartsCrashing(self->field_1568->field_19AC);
        }
    } else {
        D_0055E948.StopRaceCarCrashing(self->field_218);
    }
    func_001AB010(self);
    self->field_1160 = 0;
    self->field_198 = 0;
    self->field_212 = 0;
    self->field_211 = 0;
    for (int i = 0; (i < self->field_1169); i++) {
        self->field_840[i].field_93 = 0;
        self->field_840[i].field_90 = 0;
        self->field_840[i].field_58 = 0;
    }
    self->field_1353 = (self->field_1353 | 8);
    self->field_1353 = (self->field_1353 | 16);
    self->field_1353 = (self->field_1353 | 1);
    self->field_1353 = (self->field_1353 | 2);
    self->field_1353 = (self->field_1353 | 4);
    self->field_212 = 0;
    memset(((char *)self + 0x160), 0, 96);
    self->field_160.Zero();
    self->field_170.Zero();
    self->field_190 = 0;
    self->field_194 = 0;
    self->field_198 = 0;
    self->field_1524 = 0;
    SetAIOutOfRange__8CB3AICarFv(self->field_1568);
}
