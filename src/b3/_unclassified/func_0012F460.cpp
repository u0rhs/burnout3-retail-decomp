// func_0012F460 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (decomp-permuter (build/vt/permsetup.py)).

extern "C" {

typedef struct UnkStruct_0012F460 UnkStruct_0012F460;
typedef struct UnkStruct_0012F460_1 UnkStruct_0012F460_1;
struct UnkStruct_0012F460;
struct UnkStruct_0012F460_1;
struct UnkStruct_0012F460_1
{
  unsigned char pad_0[0x8];
  unsigned char field_8;
  unsigned char field_9;
};
struct UnkStruct_0012F460
{
  unsigned char pad_0[0x4];
  int field_4;
  UnkStruct_0012F460_1 *field_8;
};
int func_004437F0(UnkStruct_0012F460_1 *, int);
int IsControlJustPressed__26CGtInputDevicePS2DualShockFi(void *, int);
int func_0012F460(UnkStruct_0012F460 *self)
{
  UnkStruct_0012F460_1 *t0 = self->field_8;
  unsigned int v0;
  if (t0 == 0)
  {
    v0 = 0;
  }
  else
  {
    v0 = t0->field_8;
  }
  int v4;
  if (v0 != 0)
  {
    int v2;
    if (t0->field_9 != 0)
    {
      int r2 = func_004437F0(t0, 2);
      v2 = r2 & 255;
    }
    else
    {
      int r1 = func_004437F0(t0, 24);
      v2 = r1 & 255;
    }
    v4 = v2;
  }
  else
  {
    int r0 = IsControlJustPressed__26CGtInputDevicePS2DualShockFi((void *)(self->field_4), 11);
    v4 = r0 & 255;
  }
  return v4;
}

}
