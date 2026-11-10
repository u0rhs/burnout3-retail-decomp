// func_0042F8D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (dperm (decomp-permuter, background run): if (p1 == 0); if (!(p1 == 0)); {; self->field_68 = func_003CCFB0(&D_0064CE40, g->field_94, 0);; self->field_60 = g->field_84;; self->field_64 = g->field_90;; self->field_71 = self->field_D6;; }; else; else; {; self->field_68 = func_003CCFB0(&D_0064CE40, g->field_94, 0);; self->field_60 = g->field_84).

struct UnkStruct_D_0064EA70 {
    unsigned char pad_0[0x84];
    int field_84;
    unsigned char pad_88[8];
    int field_90;
    unsigned char field_94;
    unsigned char pad_95[0x17];
    int field_AC[4];
    int field_BC[3];
};
extern UnkStruct_D_0064EA70 D_0064EA70;
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
extern UnkStruct_Pad16 D_0064CE40;
extern "C" int func_003CCFB0(void *, unsigned char, unsigned char);
struct UnkStruct_0042F8D0 {
    unsigned char pad_0[0x28];
    int field_28[4];
    int field_38[3];
    int field_44[4];
    int field_54[3];
    int field_60;
    int field_64;
    int field_68;
    signed char field_6C;
    unsigned char pad_6D[3];
    unsigned char field_70;
    unsigned char field_71;
    unsigned char pad_72[0x64];
    unsigned char field_D6;
    unsigned char pad_D7[4];
    signed char field_DB;
};
extern "C" void func_0042F8D0 ( UnkStruct_0042F8D0 * self , int p1 );





// 0x0042F8D0
void func_0042F8D0(UnkStruct_0042F8D0 *self, int p1)
{
  UnkStruct_D_0064EA70 * const g = &D_0064EA70;
  if (!(p1 == 0))
  {
    self->field_68 = func_003CCFB0(&D_0064CE40, g->field_94, 0);
    self->field_60 = g->field_84;
    self->field_64 = g->field_90;
    self->field_71 = self->field_D6;
  }
  else
  {
    if (self->field_DB == 1)
    {
      for (int i = 0; i < 4; i++)
      {
        self->field_28[i] = 0;
      }

      for (int i = 0; i < 3; i++)
      {
        self->field_38[i] = 0;
      }

    }
    else
      if (self->field_6C == self->field_DB)
    {
      goto copy;
    }
    acc:
    for (int i = 0; i < 4; i++)
    {
      self->field_44[i] = self->field_28[i];
      self->field_28[i] = self->field_28[i] + g->field_AC[i];
    }


    for (int i = 0; i < 3; i++)
    {
      self->field_54[i] = self->field_38[i];
      self->field_38[i] = self->field_38[i] + g->field_BC[i];
    }

    self->field_6C = self->field_DB;
    self->field_70 = self->field_D6;
  }
  return;
  copy:
  for (int i = 0; i < 4; i++)
  {
    self->field_28[i] = self->field_44[i];
  }


  for (int i = 0; i < 3; i++)
  {
    self->field_38[i] = self->field_54[i];
  }

  goto acc;
}
