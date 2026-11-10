// func_003FDD00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (decomp-permuter (build/vt/permsetup.py)).

extern "C" {

typedef struct UnkStruct_003FDD00 UnkStruct_003FDD00;
typedef struct UnkStruct_003FDD00_a1 UnkStruct_003FDD00_a1;
struct UnkStruct_003FDD00;
struct UnkStruct_003FDD00_a1;
struct UnkStruct_003FDD00_a1
{
  unsigned char field_0;
  unsigned char pad_1[0x2B];
  int field_2C;
};
struct UnkStruct_003FDD00
{
  unsigned char field_0;
  unsigned char pad_1[0x2B];
  int field_2C;
};
int func_003FDD00(UnkStruct_003FDD00 *self, UnkStruct_003FDD00_a1 *p0)
{
  if (p0->field_0 == 0)
  {
    return -1;
  }
  if (self->field_0 == 0)
  {
    return 1;
  }
  if (self->field_2C < p0->field_2C)
  {
    return 1;
  }
  if (self || p0->field_2C)
  {
    return -(p0->field_2C < self->field_2C);
  }
  else
  {
    return -(p0->field_2C < self->field_2C);
  }
}

}
