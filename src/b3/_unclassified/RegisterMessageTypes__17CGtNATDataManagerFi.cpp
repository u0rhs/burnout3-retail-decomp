// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): if (player); {; }; else; {; goto found;; }; if (func_0022FC10(player, 6) == 0); if (func_0022FC10(player, 6) == (0 & 0xFF))).

class CGtNetworkPlayerManager;
struct UnkStruct_00231700_el {
    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0x48];
    unsigned char field_60[0x10];
    unsigned char field_70[0x10];
    unsigned char field_80[0x10];
};
struct UnkStruct_00231700 {
    UnkStruct_00231700_el field_0[8];
    unsigned char pad_480[0x528 - 0x480];
    CGtNetworkPlayerManager * field_528;
};

extern "C" void * GetPlayerByID__23CGtNetworkPlayerManagerCFi(CGtNetworkPlayerManager *, int);
extern "C" int func_0022FC10(void *, int);
extern "C" void func_0022FE10(void *, int, int, void *, void *, void *, void *, void *);
extern "C" void func_00231B20();
extern "C" void func_002319D0(void *, int, void *);
extern "C" void func_00231920(bool, void *, void *);
extern "C" void func_00231AD0(void *, int, void *);
extern "C" void func_00231A20(bool, void *, void *);
extern "C" void RegisterMessageTypes__17CGtNATDataManagerFi ( UnkStruct_00231700 * self , int id );





void RegisterMessageTypes__17CGtNATDataManagerFi(UnkStruct_00231700 *self, int id)
{
  void *player = GetPlayerByID__23CGtNetworkPlayerManagerCFi(self->field_528, id);
  UnkStruct_00231700_el *e;
  int i;
  for (i = 0; i < 8; i++)
  {
    e = &self->field_0[i];
    if (id == e->field_14)
    {
      if (player)
      {
        goto found;
      }
      else
      {
        goto found;
      }
    }
  }

  e = 0;
  found:
  if (func_0022FC10(player, 5) == 0)
  {
    func_0022FE10(player, 5, 0x10, e->field_60, (void *)(0), (void *) func_00231B20, 0, self);
  }

  if (func_0022FC10(player, 6) == (0 & 0xFF))
  {
    func_0022FE10(player, 6, 0x10, e->field_70, (void *)(0), (void *) func_002319D0, (void *) func_00231920, self);
  }
  if (func_0022FC10(player, 4) == 0)
  {
    func_0022FE10(player, 4, 0x10, e->field_80, (void *)(0), (void *) func_00231AD0, (void *) func_00231A20, self);
  }
}
