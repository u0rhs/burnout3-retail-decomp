// CB3PropManager::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PropManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): int k;; for (k = 0; k < t->field_54; k++); for (i = 0; i < t->field_54; i++); self->field_18[k] = (UnkStruct_Prop_ent **) lm.Malloc(cnt4);; if (self->field_18[k] == 0); self->field_18[i] = (UnkStruct_Prop_ent **) lm.Malloc(cnt4);; if (self->field_18[i] == 0); self->field_18[k][l] = (UnkStruct_Prop_e).

typedef unsigned int u_long128 __attribute__((mode(TI)));
class CGtLinearMalloc {
public:
    CGtLinearMalloc();
    ~CGtLinearMalloc();
    void Create(void *, unsigned int);
    void * Malloc(unsigned int);
    void Destroy();
    unsigned char field_0[0x1C];
};
struct UnkStruct_Prop_ent { unsigned short field_0; unsigned char field_2; unsigned char field_3; };
struct UnkStruct_Prop_64 { u_long128 field_0; u_long128 field_10; u_long128 field_20; u_long128 field_30; };
struct UnkStruct_Prop_tpl {
    unsigned char pad_0[0x36];
    unsigned char field_36;
    unsigned char pad_37[9];
    unsigned short field_40;
    unsigned char pad_42[2];
    unsigned char * field_44;
    UnkStruct_Prop_64 * field_48;
    unsigned char ** field_4C;
    UnkStruct_Prop_ent *** field_50;
    short field_54;
};
struct UnkStruct_Prop_mgr {
    void * field_0;
    UnkStruct_Prop_64 * field_4;
    unsigned char * field_8;
    int field_C;
    unsigned short field_10;
    unsigned char field_12;
    unsigned char pad_13[1];
    unsigned char ** field_14;
    UnkStruct_Prop_ent *** field_18;
    unsigned char field_1C[0x80];
};
struct UnkStruct_D_0064C994 { UnkStruct_Prop_tpl * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_theMemMgr { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0064C994 D_0064C994;
extern UnkStruct_theMemMgr theMemMgr;
extern "C" void * AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" int GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(void *, int);
extern "C" void func_002F9CF0(void *, int);
extern "C" void * memset(void *, int, unsigned int);
extern "C" bool Prepare__14CB3PropManagerFv ( UnkStruct_Prop_mgr * self );









bool Prepare__14CB3PropManagerFv(UnkStruct_Prop_mgr *self)
{
  int b;
  CGtLinearMalloc lm;
  if (self->field_0 == 0)
  {
    self->field_0 = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 0xD, 0);
  }
  if (self->field_0 == 0)
  {
    return false;
  }
  lm.Create(self->field_0, GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(&theMemMgr, 0xD));
  UnkStruct_Prop_tpl *t = D_0064C994.field_0;
  unsigned short n = t->field_40;
  unsigned char m = t->field_36;
  func_002F9CF0(&lm, 0x10);
  int i;
  self->field_4 = (UnkStruct_Prop_64 *) lm.Malloc(n << 6);
  if (self->field_4 == 0)
  {
    lm.Destroy();
    return true;
  }
  for (i = 0; i < n; i++)
  {
    self->field_4[i] = t->field_48[i];
  }

  func_002F9CF0(&lm, 1);
  int cnt = m;
  self->field_8 = (unsigned char *) lm.Malloc(cnt);
  if (self->field_8 == 0)
  {
    lm.Destroy();
    return true;
  }
  for (i = 0; i < cnt; i++)
  {
    self->field_8[i] = t->field_44[i];
  }

  func_002F9CF0(&lm, 4);
  self->field_14 = (unsigned char **) lm.Malloc(t->field_54 << 2);
  if (self->field_14 == 0)
  {
    lm.Destroy();
    return true;
  }
  int j;
  for (j = 0; j < t->field_54; j++)
  {
    func_002F9CF0(&lm, 1);
    self->field_14[j] = (unsigned char *) lm.Malloc(cnt);
    if (self->field_14[j] == 0)
    {
      lm.Destroy();
      return true;
    }
  }

  int a;
  for (a = 0; a < t->field_54; a++)
  {
    for (b = 0; b < cnt; b++)
    {
      self->field_14[a][b] = t->field_4C[a][b];
    }

  }

  func_002F9CF0(&lm, 4);
  self->field_18 = (UnkStruct_Prop_ent ***) lm.Malloc(t->field_54 << 2);
  if (self->field_18 == 0)
  {
    lm.Destroy();
    return true;
  }
  int cnt4 = cnt << 2;
  for (i = 0; i < t->field_54; i++)
  {
    func_002F9CF0(&lm, 0x10);
    self->field_18[i] = (UnkStruct_Prop_ent **) lm.Malloc(cnt4);
    if (self->field_18[i] == 0)
    {
      lm.Destroy();
      return true;
    }
    int l;
    for (l = 0; l < cnt; l++)
    {
      func_002F9CF0(&lm, 2);
      self->field_18[i][l] = (UnkStruct_Prop_ent *) lm.Malloc(self->field_14[i][l] << 2);
      if (self->field_18[i][l] == 0)
      {
        lm.Destroy();
        return true;
      }
    }

  }

  int q;
  int r;
  int p;
  for (p = 0; p < t->field_54; p++)
  {
    for (q = 0; q < cnt; q++)
    {
      for (r = 0; r < self->field_14[p][q]; r++)
      {
        self->field_18[p][q][r].field_0 = t->field_50[p][q][r].field_0;
        self->field_18[p][q][r].field_2 = q;
        self->field_18[p][q][r].field_3 = 0;
      }

    }

  }

  self->field_10 = n;
  self->field_12 = m;
  self->field_C = 0;
  memset(self->field_1C, 0, 0x80);
  lm.Destroy();
  return true;
}
