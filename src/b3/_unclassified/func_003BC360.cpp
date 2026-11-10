// func_003BC360 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (dperm (decomp-permuter, background run): if ((!self) && (!self)); {; }).

typedef unsigned int u_long128 __attribute__((mode(TI)));

enum UnkEnum_003BC360 { UnkEnum_0 = 0, UnkEnum_1 = 1, UnkEnum_2 = 2, UnkEnum_17 = 17 };
struct UnkStruct_003BC360;
struct UnkStruct_003BC360_10;
struct UnkStruct_003BC360_3;
struct UnkStruct_003BC360_7;
struct UnkStruct_003BC360_e0;

struct UnkStruct_003BC360_e0 {
    unsigned char pad_0[0xD];
    unsigned char field_D;
    unsigned char field_E;
    unsigned char pad_F[0x5];
};

struct UnkStruct_003BC360_3 {
    float field_0;
};

struct UnkStruct_003BC360_7 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_003BC360_10 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

struct UnkStruct_003BC360 {
    unsigned char pad_0[0x10];
    UnkStruct_003BC360_e0 * field_10;
    UnkStruct_003BC360_3 * field_14[1];  
    unsigned char pad_18[0x44];
    UnkStruct_003BC360_7 * field_5C[1];  
    unsigned char pad_60[0x20];
    UnkStruct_003BC360_10 * field_80[1];  
    unsigned char pad_84[0x58];
    int field_DC;
};

extern u_long128 D_01E90240[];

extern "C" void func_003BE040(UnkStruct_003BC360 *, int, bool, float);

struct UnkStruct_003BC360_pad { int x[8]; UnkStruct_003BC360_pad() {} ~UnkStruct_003BC360_pad() {} };
extern "C" void func_003BC360 ( UnkStruct_003BC360 * self , int p0 , int p1 );










// 0x003BC360
void func_003BC360(UnkStruct_003BC360 *self, int p0, int p1)
{
  UnkStruct_003BC360_pad pad;
  u_long128 * const tab = D_01E90240;
  self->field_10[p0].field_E = (p1 != 0) ^ 1;
  float fl = self->field_14[p0]->field_0;
  if ((!self) && (!self))
  {
  }
  func_003BE040(self, p0, self->field_DC == p0, fl);
  UnkStruct_003BC360_7 *t0 = self->field_5C[p0];
  if (t0 != 0)
  {
    UnkStruct_003BC360_e0 *t1 = self->field_10;
    unsigned char t2 = t1[p0].field_D;
    if (t2 != 7)
    {
      if (t2 != 8)
      {
        UnkEnum_003BC360 v1;
        if (t1[p0].field_E != 0)
        {
          v1 = UnkEnum_2;
        }
        else
        {
          UnkEnum_003BC360 v0;
          if (self->field_DC == p0)
          {
            v0 = UnkEnum_1;
          }
          else
          {
            v0 = UnkEnum_0;
          }
          v1 = v0;
        }
        t0->field_10 = tab[v1];
      }
    }
  }
  UnkStruct_003BC360_10 *t3 = self->field_80[p0];
  if (t3 != 0)
  {
    UnkEnum_003BC360 v6;
    if (self->field_10[p0].field_E != 0)
    {
      v6 = UnkEnum_2;
    }
    else
    {
      UnkEnum_003BC360 v5;
      if (self->field_DC == p0)
      {
        v5 = UnkEnum_17;
      }
      else
      {
        v5 = UnkEnum_0;
      }
      v6 = v5;
    }
    t3->field_10 = tab[v6];
  }
}
