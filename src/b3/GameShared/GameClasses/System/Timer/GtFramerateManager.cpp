// GtFramerateManager.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> GtFramerateManager.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/GameShared/GameClasses/System/Timer, [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Timer/GtFramerateManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

struct UnkStruct_003767B0 {
    int field_0;
    unsigned char pad_4[0x30];
    unsigned char field_34;
};
struct UnkStruct_003767C0 {
    int field_0;
    unsigned char pad_4[0x4];
    unsigned long field_8;
    unsigned long field_10;
    unsigned char pad_18[0x10];
    int field_28;
    int field_2C;
    int field_30;
};
struct UnkStruct_003767E0 {
    unsigned char pad_0[0x18];
    long field_18;
    long field_20;
    unsigned char pad_28[0x4];
    int field_2C;
    int field_30;
};

// func_003767B0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003767B0
extern "C" void func_003767B0(UnkStruct_003767B0 *self, int p0, int p1)
{
    self->field_0 = p0;
    self->field_34 = (unsigned char)p1;
}

// Prepare__19CGtFramerateManagerFv -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003767C0
extern "C" void Prepare__19CGtFramerateManagerFv(UnkStruct_003767C0 *self)
{
    self->field_0 = 0;
    self->field_10 = 0;
    self->field_8 = 0;
    self->field_2C = 0;
    self->field_28 = 0;
    self->field_30 = 0;
}

// Hand-written; the lifter refused it (bus-clock int local 0x11940000 (294.912MHz); FramerateManager::Construct(float,float) DNAT high, comment only).
// 0x003767E0
extern "C" void Construct__19CGtFramerateManagerFff(UnkStruct_003767E0 *self, float p0, float p1)
{
    int clk = 0x11940000;
    self->field_20 = (long)(p0 * (float)clk / 1000.0f);
    self->field_18 = (long)(p1 * (float)clk / 1000.0f);
    self->field_2C = -1;
    self->field_30 = 0;
}
