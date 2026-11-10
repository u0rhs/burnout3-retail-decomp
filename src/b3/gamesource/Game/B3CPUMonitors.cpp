// B3CPUMonitors.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3CPUMonitors.cpp.
// Area: src/b3/gamesource/Game, [L] Revenge (SLUS_212.42) GameSource/Game/B4CPUMonitors.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

struct UnkStruct_002F03A0;

struct UnkStruct_002F03A0 {
    int field_0;
    int field_4;
    unsigned char pad_8[0x4];
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
};

extern "C" void Construct__21CB3NetworkCPUMonitorsFv(void *);

// Construct__14CB3CPUMonitorsFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002F03A0
extern "C" void Construct__14CB3CPUMonitorsFv(UnkStruct_002F03A0 * self)
{
    self->field_0 = -1;
    self->field_4 = -1;
    self->field_C = -1;
    self->field_10 = -1;
    self->field_14 = -1;
    self->field_18 = -1;
    self->field_1C = -1;
    self->field_20 = -1;
    self->field_24 = -1;
    self->field_28 = -1;
    Construct__21CB3NetworkCPUMonitorsFv(((char *)self + 0x2C));
}
