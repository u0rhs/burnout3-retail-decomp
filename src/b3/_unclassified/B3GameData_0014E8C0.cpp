// CB3GameData::Draw(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3GameData.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): do { } while (0);; j = 0;; if (pl->field_1384 > j); {; if (!(pl->field_10D4 < (pl->field_1384 - 1))); {; s4 = true;; }; }; }; }; if (s1 & 1); {; if ((pl->field_10D4 < 0) || ((func_00131E40(&D_004EE040) != 0) && (pl->field_18EA == 0))); {; for (j = 0; j < func_0014E8C0_inl1(this); j++); {; func_0015E).

struct UnkStruct_E8C0_2;
struct UnkStruct_E8C0_3;
struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_0051BA88 {
    UnkStruct_E8C0_2 * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_E8C0_3 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual int vfunc_44();
};
struct UnkStruct_E8C0_2 {
    unsigned char pad_0[0x1B4];
    UnkStruct_E8C0_3 * field_1B4;
};
struct UnkStruct_E8C0_pl {
    unsigned char pad_0[0x10D4];
    int field_10D4;
    unsigned char pad_10D8[0x2AC];
    int field_1384;
    unsigned char pad_1388[0x14];
    int field_139C;
    unsigned char pad_13A0[0x54A];
    unsigned char field_18EA;
};
struct UnkStruct_E8C0_shared {
    unsigned char pad_0[0x3EC];
    int field_3EC;
    int field_3F0;
    int field_3F4;
    int field_3F8;
    int field_3FC;
};
struct UnkStruct_E8C0_e388 { unsigned char pad_0[0x10]; };
struct UnkStruct_E8C0_e3C8 { unsigned char pad_0[0x8]; };
struct UnkStruct_E8C0_e140 { unsigned char pad_0[0x70]; };
class CB3GameData {
public:
    void Draw(int p0);
    unsigned char pad_0[0x140];
    UnkStruct_E8C0_e140 field_140[1];
    unsigned char pad_1B0[0x1D8];
    UnkStruct_E8C0_e388 field_388[2];
    UnkStruct_E8C0_e388 field_3A8[2];
    UnkStruct_E8C0_e3C8 field_3C8[1];
    unsigned char pad_3D0[0x84];
    void * field_454;
    unsigned char pad_458[0x108];
    int field_560;
    unsigned char pad_564[0x8];
    UnkStruct_E8C0_shared * field_56C;
};
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_004EE040 D_004EE040;
extern char D_00522660[];
extern "C" int func_00131E40(void *);
extern "C" void func_0015E720(void *, int);
extern "C" void Draw__22CB3SplitTimeCheckpointFv(void *);
extern "C" void Draw__14CB3CrashPickupFv(void *, int);
extern "C" void Draw__12CB3CrashRampFP10CGtTexture(void *, void *);


static inline int func_0014E8C0_inl1(CB3GameData * g)
{
    int c = 0;
    if (((g->field_560 != 0) ^ 1) == 0) {
        c = g->field_56C->field_3EC;
    }
    return c;
}

static inline int func_0014E8C0_inl2(CB3GameData * g)
{
    int c = 0;
    if (((g->field_560 != 0) ^ 1) == 0) {
        c = g->field_56C->field_3F4;
    }
    return c;
}






// 0x0014E8C0
void CB3GameData::Draw(int p0)
{
  bool s4;
  int j;
  int cnt;
  UnkStruct_E8C0_pl *pl;
  int s1;
  unsigned char b;
  b = func_00131E40(&D_004EE040);
  pl = (UnkStruct_E8C0_pl *) ((D_00522660 + (p0 * 0x27D0)) + 0x12AD50);
  UnkStruct_E8C0_3 *o = D_0051BA88.field_0->field_1B4;
  if (o != 0)
  {
    s1 = o->vfunc_44();
 do { } while (0);
  }
  else
  {
    s1 = 0;
  }
  s4 = false;
  cnt = 0;
  if (field_560 != 0)
  {
    cnt = field_56C->field_3F0;
  }
  if (b)
  {
    s4 = false;
    cnt = 0;
  }
  if (s1 & 2)
  {
    if (pl->field_139C > 0)
    {
      j = 0;
      if (pl->field_1384 > j)
      {
        if (!(pl->field_10D4 < (pl->field_1384 - 1)))
        {
          s4 = true;
        }
      }
    }
  }
  if (s1 & 1)
  {
    if ((pl->field_10D4 < 0) || ((func_00131E40(&D_004EE040) != 0) && (pl->field_18EA == 0)))
    {
      for (j = 0; j < func_0014E8C0_inl1(this); j++)
      {
        func_0015E720(&field_388[j], 0);
      }

    }
  }
  if (s1 & 0x18)
  {
    if (pl->field_139C > 0)
    {
      if (pl->field_10D4 >= 0)
      {
        if (pl->field_1384 > 0)
        {
          if (!(pl->field_10D4 < (pl->field_1384 - 1)))
          {
            s1 = s1 & (~0x18);
            s1 = s1 | 2;
          }
        }
        s4 = true;
      }
    }
  }
  if (s4)
  {
    for (j = 0; j < cnt; j++)
    {
      func_0015E720(&field_3A8[j], s1);
    }

  }
  if (s1 & 4)
  {
    for (j = 0; j < func_0014E8C0_inl2(this); j++)
    {
      Draw__22CB3SplitTimeCheckpointFv(&field_3C8[j]);
    }

  }
  if (D_0051BA88.field_0->field_1B4 == 0)
  {
    return;
  }
  for (j = 0; j < field_56C->field_3F8; j++)
  {
    Draw__14CB3CrashPickupFv(((char *) this) + (j * 16), p0 & 0xFFFFFFFFu);
  }

  for (j = 0; j < field_56C->field_3FC; j++)
  {
    Draw__12CB3CrashRampFP10CGtTexture(&field_140[j], field_454);
  }

}
