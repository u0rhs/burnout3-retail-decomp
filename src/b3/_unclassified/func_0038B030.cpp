// func_0038B030 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (decomp-permuter (build/vt/permsetup.py)).

extern "C" {

typedef struct UnkStruct_D_004EE040 UnkStruct_D_004EE040;
typedef struct UnkStruct_D_0064D3B0 UnkStruct_D_0064D3B0;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_0064D3B0;
struct UnkStruct_D_0064D3B0
{
  unsigned char pad_0[0x10D4];
  int field_10D4;
};
struct UnkStruct_D_004EE040
{
  unsigned char pad_0[0x10];
};
extern UnkStruct_D_0064D3B0 D_0064D3B0;
extern UnkStruct_D_004EE040 D_004EE040;
int func_00131CE0(void *);
bool func_0038B030()
{
  int r0 = func_00131CE0(&D_004EE040);
  UnkStruct_D_0064D3B0 *t_n0;
  if (r0 != 0)
  {
    return 0;
  }
  t_n0 = &D_0064D3B0;
  if (t_n0 == 0)
  {
    return 0;
  }
  r0 = t_n0->field_10D4;
  return 0 < r0;
}

}
