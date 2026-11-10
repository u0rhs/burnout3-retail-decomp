// GtDictionary.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> GtDictionary.cpp.
// Area: src/b3/GameShared/GameClasses/Containers, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Containers/GtDictionary.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

struct UnkStruct_0021AAF0;
struct UnkStruct_0021AAF0_e0;

struct UnkStruct_0021AAF0_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};
struct UnkStruct_0021AAF0 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_0021AAF0_e0 * field_C;
};

// FixUp__17CGtDictionaryBaseFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0021AAF0
extern "C" void FixUp__17CGtDictionaryBaseFv(UnkStruct_0021AAF0 * self)
{
    self->field_C = (UnkStruct_0021AAF0_e0 *)((char *)self->field_C + (int)self);
    for (int i = 0; (i < self->field_8); i++) {
        UnkStruct_0021AAF0_e0 * e1 = &self->field_C[i];
        e1->field_8 = (int)(e1->field_8 + (int)self);
    }
}
