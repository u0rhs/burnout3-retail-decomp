// func_00469810 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (decomp-permuter (build/vt/permsetup.py)).

extern "C" {

typedef struct UnkStruct_00469810 UnkStruct_00469810;
typedef struct UnkStruct_D_004B13C0 UnkStruct_D_004B13C0;
typedef struct UnkStruct_D_004B13C4 UnkStruct_D_004B13C4;
typedef struct UnkStruct_D_004B13C8 UnkStruct_D_004B13C8;
typedef struct UnkStruct_D_004B13CC UnkStruct_D_004B13CC;
typedef struct UnkStruct_D_004E2FDC UnkStruct_D_004E2FDC;
struct UnkStruct_00469810;
struct UnkStruct_D_004B13C0;
struct UnkStruct_D_004B13C4;
struct UnkStruct_D_004B13C8;
struct UnkStruct_D_004B13CC;
struct UnkStruct_D_004E2FDC;
struct UnkStruct_D_004B13C0
{
  int field_0;
  unsigned char pad_4[0xC];
};
struct UnkStruct_D_004B13CC
{
  int field_0;
  unsigned char pad_4[0xC];
};
struct UnkStruct_D_004B13C8
{
  void *field_0;
  unsigned char pad_4[0xC];
};
struct UnkStruct_D_004B13C4
{
  int field_0;
  unsigned char pad_4[0xC];
};
struct UnkStruct_D_004E2FDC
{
  int field_0;
};
struct UnkStruct_00469810
{
  void *field_0;
};
extern UnkStruct_D_004B13C0 D_004B13C0;
extern UnkStruct_D_004B13CC D_004B13CC;
extern UnkStruct_D_004B13C8 D_004B13C8;
extern UnkStruct_D_004B13C4 D_004B13C4;
extern UnkStruct_D_004E2FDC D_004E2FDC;
int func_00469810(UnkStruct_00469810 *self)
{
  if (D_004B13C0.field_0 == 0)
  {
    return 6;
  }
  if (self == 0)
  {
    if (1)
    {
    }
    return 2;
  }
  int t0 = D_004B13CC.field_0;
  if (self || (&D_004B13CC))
  {
    D_004B13C8.field_0 = &D_004E2FDC;
    D_004B13C4.field_0 = 4;
    D_004E2FDC.field_0 = ~t0;
    self->field_0 = &D_004B13C4;
    return 0;
  }
  else
  {
    D_004B13C8.field_0 = &D_004E2FDC;
    D_004B13C4.field_0 = 4;
    D_004E2FDC.field_0 = ~t0;
    self->field_0 = &D_004B13C4;
    return 0;
  }
}

}
