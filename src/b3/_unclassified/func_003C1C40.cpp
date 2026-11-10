// func_003C1C40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (dperm (decomp-permuter perm_inline): field_34 reads through an inline accessor func_003C1C40_inl1, v1/v0 copies of p0; source = compile.sh's generated C++).

extern "C" {

typedef struct UnkStruct_003C1C40_rec UnkStruct_003C1C40_rec;
struct UnkStruct_003C1C40_rec
{
  unsigned char field_0;
  unsigned char field_1;
  unsigned char field_2;
  unsigned char field_3;
  int field_4;
  float field_8;
  float field_C;
  int field_10;
  int field_14;
  int field_18;
  int field_1C;
  int field_20;
  int field_24;
  unsigned char field_28;
  unsigned char field_29;
  unsigned char pad_2A[0x2];
  int field_2C;
  int field_30;
  int field_34;
};
extern UnkStruct_003C1C40_rec D_01EA5470[8];
inline int func_003C1C40_inl1(const UnkStruct_003C1C40_rec *arg0)
{
  return arg0->field_34;
}

// 0x003C1C40
void func_003C1C40(int n0, const UnkStruct_003C1C40_rec *p0)
{
  const UnkStruct_003C1C40_rec *v1 = p0;
  const UnkStruct_003C1C40_rec *v0 = v1;
  int i = 0;
  while (8 > i)
  {
    if ((D_01EA5470[i].field_0 != 0) && (D_01EA5470[i].field_34 == func_003C1C40_inl1(v0)))
    {
      D_01EA5470[i].field_0 = p0->field_0;
      D_01EA5470[i].field_1 = p0->field_1;
      D_01EA5470[i].field_2 = p0->field_2;
      D_01EA5470[i].field_3 = p0->field_3;
      D_01EA5470[i].field_4 = p0->field_4;
      D_01EA5470[i].field_8 = p0->field_8;
      D_01EA5470[i].field_C = p0->field_C;
      D_01EA5470[i].field_10 = p0->field_10;
      D_01EA5470[i].field_14 = p0->field_14;
      D_01EA5470[i].field_18 = p0->field_18;
      D_01EA5470[i].field_1C = p0->field_1C;
      D_01EA5470[i].field_20 = p0->field_20;
      D_01EA5470[i].field_24 = p0->field_24;
      D_01EA5470[i].field_28 = p0->field_28;
      D_01EA5470[i].field_29 = p0->field_29;
      D_01EA5470[i].field_2C = p0->field_2C;
      D_01EA5470[i].field_30 = p0->field_30;
      D_01EA5470[i].field_34 = func_003C1C40_inl1(p0);
      D_01EA5470[i].field_0 = 1;
      break;
    }
    i++;
  }

}
}
