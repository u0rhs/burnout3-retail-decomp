// func_00302C10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3StreamManager.h"
#include "b3/classes/CB3StreamedTrackHighData.h"
#include "b3/classes/CB3StreamedTrackLODAndCollisionData.h"
#include "b3/classes/UnkStruct_D_004E2D48.h"

struct UnkStruct_00302C10;

struct UnkStruct_00302C10 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    unsigned char pad_14[0xC];
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    unsigned char pad_38[0xC];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char field_46;
    unsigned char pad_47[0x1];
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    unsigned char pad_58[0xFC];
    CB3StreamedTrackHighData * field_154[1];  // [G] element count unknown
    unsigned char pad_158[0x24];
    CB3StreamedTrackLODAndCollisionData * field_17C[1];  // [G] element count unknown
};

extern UnkStruct_D_004E2D48 D_004E2D48;
extern CB3StreamManager D_0064CD40;

// 0x00302C10
extern "C" void func_00302C10(UnkStruct_00302C10 * self)
{
    for (int i = 0; (i < self->field_8); i++) {
        CB3StreamedTrackHighData ** pp = &self->field_154[i];
        if (*pp != 0) {
            D_0064CD40.ReleaseHighDetailUnit(*pp);
            *pp = 0;
        }
    }
    for (int i1 = 0; (i1 < self->field_C); i1++) {
        CB3StreamedTrackLODAndCollisionData ** pq = &self->field_17C[i1];
        if (*pq != 0) {
            D_0064CD40.ReleaseLODUnit(*pq);
            *pq = 0;
        }
    }
    D_004E2D48.field_0 = -1;
    self->field_44 = 0;
    self->field_45 = 0;
    self->field_46 = 0;
    self->field_34 = -1;
    self->field_30 = -1;
    self->field_54 = -1;
    self->field_50 = -1;
    self->field_4 = -1;
    self->field_0 = -1;
    self->field_24 = -1;
    self->field_20 = -1;
    self->field_C = -1;
    self->field_8 = -1;
    self->field_2C = -1;
    self->field_28 = -1;
    self->field_4C = -1;
    self->field_48 = -1;
    self->field_10 = 24;
}
