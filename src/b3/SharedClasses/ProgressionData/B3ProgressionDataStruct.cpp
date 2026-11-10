// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// B3ProgressionDataStruct.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3ProgressionDataStruct.cpp.
// Area: src/b3/SharedClasses/ProgressionData, [L] Revenge (SLUS_212.42) SharedClasses/ProgressionData/B4ProgressionDataStruct.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

struct UnkStruct_00367E70_e2 {
    unsigned char pad_0[0x34];
    int field_34;  // [G] pointer relocated by a byte offset
    unsigned char pad_38[0x8];
};
struct UnkStruct_00367E70_e1 {
    unsigned char pad_0[0x10];
    UnkStruct_00367E70_e2 * field_10;
    int field_14;
};
struct UnkStruct_00367E70_e0 {
    UnkStruct_00367E70_e1 * field_0;
    int field_4;
};
struct UnkStruct_00367E70 {
    unsigned char pad_0[0x4];
    UnkStruct_00367E70_e0 * field_4;
    int field_8;
    int field_C;  // [G] pointer relocated by a byte offset
};

// Fixup__24CB3ProgressionDataStructFUi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00367E70
extern "C" void Fixup__24CB3ProgressionDataStructFUi(UnkStruct_00367E70 * self, int p0)
{
    self->field_4 = (UnkStruct_00367E70_e0 *)((char *)self->field_4 + p0);
    for (int i = 0; i < self->field_8; i++) {
        UnkStruct_00367E70_e0 * e = &self->field_4[i];
        e->field_0 = (UnkStruct_00367E70_e1 *)((char *)e->field_0 + p0);
        for (int j = 0; j < e->field_4; j++) {
            UnkStruct_00367E70_e1 * e2 = &e->field_0[j];
            e2->field_10 = (UnkStruct_00367E70_e2 *)((char *)e2->field_10 + p0);
            int k = 0;
            if (0 < e2->field_14) {
                for (; k < e2->field_14; k++) {
                    e2->field_10[k].field_34 += p0;
                }
            }
        }
    }
    self->field_C += p0;
}
