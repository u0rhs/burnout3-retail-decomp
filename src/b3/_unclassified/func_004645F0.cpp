// func_004645F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (decomp-permuter (build/vt/permsetup.py)).

extern "C" {

typedef struct UnkStruct_004645F0_1 UnkStruct_004645F0_1;
typedef struct UnkStruct_004645F0_2 UnkStruct_004645F0_2;
typedef struct UnkStruct_004645F0_3 UnkStruct_004645F0_3;
typedef struct UnkStruct_004645F0_4 UnkStruct_004645F0_4;
typedef struct UnkStruct_D_004E2FBC UnkStruct_D_004E2FBC;
struct UnkStruct_004645F0_1;
struct UnkStruct_004645F0_2;
struct UnkStruct_004645F0_3;
struct UnkStruct_004645F0_4;
struct UnkStruct_D_004E2FBC;
struct UnkStruct_D_004E2FBC
{
  UnkStruct_004645F0_1 *field_0;
};
struct UnkStruct_004645F0_1
{
  unsigned char pad_0[0x70];
  UnkStruct_004645F0_2 *field_70;
  int field_74;
  int field_78;
  unsigned char pad_7C[0x18];
  int field_94;
  int field_98;
  int field_9C;
};
struct UnkStruct_004645F0_2
{
  unsigned char pad_0[0xC];
  int field_C;
  int field_10;
  int field_14;
};
struct UnkStruct_004645F0_3
{
  UnkStruct_004645F0_4 *field_0;
};
struct UnkStruct_004645F0_4
{
  unsigned char pad_0[0x4];
  int field_4;
};
extern UnkStruct_D_004E2FBC D_004E2FBC;
void *memset(void *, int, unsigned int);
void *memcpy(void *, const void *, unsigned int);
int func_00467580(void *);
int func_004645F0(void *n0_)
{
    int n0 = (int)n0_;
  UnkStruct_004645F0_3 local;
  UnkStruct_004645F0_1 *t0 = D_004E2FBC.field_0;
  int t1 = t0->field_94;
  if ((t1 << 4) == 0)
  {
    memset((void *) (n0 + 96), 0, 4);
  }
  else
  {
    int t3 = t0->field_9C;
    UnkStruct_004645F0_2 *t2 = t0->field_70;
    int r1 = ((int (*)(int)) t2->field_C)(n0);
    if (r1 == 0)
    {
      int r2 = ((int (*)(int, int)) t2->field_10)(t3, t1 << 4);
      if (r2 == 0)
      {
        ((void (*)(UnkStruct_004645F0_3 *)) t2->field_14)(&local);
      }
    }
    memcpy((void *) (n0 + 96), (const void *) local.field_0->field_4, 4);
  }
  memcpy((void *) (((char *) D_004E2FBC.field_0) + 96), (const void *) (n0 + 96), 4);
  D_004E2FBC.field_0->field_94 = 0;
  D_004E2FBC.field_0->field_98 = 0;
  D_004E2FBC.field_0->field_74 = 3;
  D_004E2FBC.field_0->field_78 = 3;
  int r6 = func_00467580((void *)(n0));
  int v5;
  if (r6 == 0)
  {
    v5 = 0;
  }
  else
  {
    v5 = r6 + 100;
  }
  return v5;
}

}
