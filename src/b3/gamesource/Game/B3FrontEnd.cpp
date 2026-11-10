// B3FrontEnd.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 5 function(s) named in research/retail_names.csv -> B3FrontEnd.cpp.
// Area: src/b3/gamesource/Game, [L] Revenge (SLUS_212.42) GameSource/Game/B4FrontEnd.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

struct UnkStruct_00130C40;
struct UnkStruct_00131AA0;
struct UnkStruct_00131AA0_e0;

struct UnkStruct_00130C20 {
    unsigned char pad_0[0x300];
    unsigned long field_300;
};
struct UnkStruct_00130C30 {
    unsigned char pad_0[0x2FC];
    int field_2FC;
};
struct UnkStruct_00130C40 {
    unsigned char pad_0[0x2F4];
    int field_2F4;
};
struct UnkStruct_00131AA0_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};
struct UnkStruct_00131AA0 {
    unsigned char pad_0[0xC];
    UnkStruct_00131AA0_e0 * field_C;
};
struct UnkStruct_00130C70 {
    unsigned char pad_0[0x1C8];
    unsigned char field_1C8[0x130];           
    int field_2F8;
    unsigned char pad_2FC[0x1C];
    unsigned char field_318[0x10];            
};

extern "C" void func_001345F0();
extern "C" void func_00324ED0(void *);
extern "C" int func_00324EE0(void *);
extern "C" void Update__15CGtVideoDecoderFv(void *);
extern "C" void Release__15CGtVideoDecoderFv(void *);
extern "C" void Destroy__15CGtLinearMallocFv(void *);
extern "C" void func_00130C70 ( UnkStruct_00130C70 * self );

// func_00130C20 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00130C20
extern "C" void func_00130C20(UnkStruct_00130C20 *self, unsigned long p0)
{
    self->field_300 = p0;
}

// func_00130C30 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00130C30
extern "C" void func_00130C30(UnkStruct_00130C30 *self, int p0)
{
    self->field_2FC = p0;
}

// func_00130C40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00130C40
extern "C" void func_00130C40(UnkStruct_00130C40 * self)
{
    func_001345F0();
    self->field_2F4 = 25;
}

// func_00130C70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00130C70
void func_00130C70(UnkStruct_00130C70 *self)
{
  if (self->field_2F8 != 0x18)
  {
    func_00324ED0(self->field_1C8);
    while (!func_00324EE0(self->field_1C8))
    {
      Update__15CGtVideoDecoderFv(self->field_1C8);
    }

    Release__15CGtVideoDecoderFv(self->field_1C8);
    Destroy__15CGtLinearMallocFv(self->field_318);
  }
  self->field_2F8 = 0x18;
}

// func_00131AA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00131AA0
extern "C" int func_00131AA0(UnkStruct_00131AA0 * self, int p0)
{
    return self->field_C[p0].field_8;
}
