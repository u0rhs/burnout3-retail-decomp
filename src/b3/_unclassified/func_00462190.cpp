// func_00462190 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (decomp-permuter (build/vt/permsetup.py)).

extern "C" {

typedef struct UnkStruct_00462190 UnkStruct_00462190;
typedef struct UnkStruct_00462190_a1 UnkStruct_00462190_a1;
typedef struct UnkStruct_00462190_a2 UnkStruct_00462190_a2;
struct UnkStruct_00462190;
struct UnkStruct_00462190_a1;
struct UnkStruct_00462190_a2;
struct UnkStruct_00462190_a1
{
  int field_0;
};
struct UnkStruct_00462190_a2
{
  int field_0;
};
struct UnkStruct_00462190
{
  unsigned char pad_0[0x4];
  int field_4;
  unsigned char pad_8[0x3C4];
  int field_3CC;
};
void func_00462190(UnkStruct_00462190 *self, UnkStruct_00462190_a1 *p0, UnkStruct_00462190_a2 *p1)
{
  int t0 = self->field_3CC;
  int v0;
  if ((t0 & 1023) != 0)
  {
    v0 = (((unsigned int) t0) >> 10) + 1;
  }
  else
  {
    v0 = ((unsigned int) t0) >> 10;
  }
  int t1 = self->field_4;
  int v1;
  t0 = v0 << 10;
  if ((t1 & 1023) != 0)
  {
    v1 = (((unsigned int) t1) >> 10) + 1;
  }
  else
  {
    v1 = ((unsigned int) t1) >> 10;
  }
  p0->field_0 = (t0 + (v1 << 10)) + 5120;
  p1->field_0 = 3;
}

}
