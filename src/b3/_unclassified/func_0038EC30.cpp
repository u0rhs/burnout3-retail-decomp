// AssignStartPositionIndex__26CB3OnlineRoadRageRaceLogicFi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OnlineRoadRageRaceLogic.h"
#include "b3/classes/EB3DamageType.h"
#include "b3/classes/UnkStruct_D_004A4FC0.h"
#include "b3/classes/UnkStruct_D_01E3D558.h"

struct UnkStruct_0038EC30;
struct UnkStruct_0038EC30_0;
struct UnkStruct_0038EC30_3;
struct UnkStruct_0038EC30_4;

struct UnkStruct_0038EC30_0 {
    UnkStruct_0038EC30_c0 field_0;
    unsigned char pad_18[0x8];
};

struct UnkStruct_0038EC30_3 {
    unsigned char pad_0[0x1914];
    int field_1914;
    unsigned char pad_1918[0x170];
    int field_1A88;
};

struct UnkStruct_0038EC30_4 {
    unsigned char pad_0[0x32];
    unsigned char field_32;
};

struct UnkStruct_0038EC30 {
    unsigned char pad_0[0x7C];
    int field_7C;
    int field_80;
};

extern UnkStruct_0038EC30_3 * D_0064D388[];  // [G] element count unknown
extern UnkStruct_0038EC30_c0 D_004A4FC0[];  // [G] unsized array: gives retail's 4-aligned 8-byte copy loop (known.md N132)
extern UnkStruct_D_01E3D558 D_01E3D558;

// [L] DNAT: CB3OnlineRoadRageRaceLogic::AssignStartPositionIndex(int) (research/proto/new_names.csv, high)
// 0x0038EC30
extern "C" int AssignStartPositionIndex__26CB3OnlineRoadRageRaceLogicFi(UnkStruct_0038EC30 * self, int p0)
{
    UnkStruct_0038EC30_c0 local;
    local = D_004A4FC0[0];
    UnkStruct_0038EC30_3 * t0 = D_0064D388[p0];
    UnkStruct_0038EC30_4 * v0;
    if (t0->field_1914 != 2) {
        v0 = (UnkStruct_0038EC30_4 *)&D_01E3D558;
    } else {
        v0 = (UnkStruct_0038EC30_4 *)(t0->field_1A88 + 1208);
    }
    int v2;
    if (v0->field_32 != 0) {
        int t1 = self->field_7C;
        v2 = local.field_0[5 - t1];
        self->field_7C = (t1 + 1);
    } else {
        int t2 = self->field_80;
        v2 = local.field_0[t2];
        self->field_80 = (t2 + 1);
    }
    return v2;
}
