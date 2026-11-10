// CB3Score::OnTakeDown(CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): unsigned char *pf = &field_5B9[p0->field_19AC];; if ((*pf) != 0); unsigned char *pf;; if ((*(&field_5B9[p0->field_19AC])) != 0); *pf = 0;; *(&field_5B9[p0->field_19AC]) = 0;).

class CB3RaceCar;
class CB3CrashStartInfo { public: unsigned char pad_0[0x1]; };
class CB3ScoreBonus {
public:
    void OnTakedown(CB3RaceCar *, const CB3CrashStartInfo *, bool, bool);
    unsigned char pad_0[0x1];
};
struct UnkStruct_D_0051BA88_ls {
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
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64(CB3RaceCar *, CB3RaceCar *);
};
struct UnkStruct_D_0051BA88_2 {
    unsigned char pad_0[0x1B4];
    UnkStruct_D_0051BA88_ls * field_1B4;
};
struct UnkStruct_D_0051BA88 {
    UnkStruct_D_0051BA88_2 * field_0;
    unsigned char pad_4[0xC];
};
class CB3RaceCar {
public:
    unsigned char pad_0[0x10CC];
    float field_10CC;
    unsigned char pad_10D0[0x2F8];
    CB3CrashStartInfo field_13C8;
    unsigned char pad_13C9[0x1FD];
    unsigned char field_15C6;
    unsigned char field_15C7;
    unsigned char pad_15C8[0x4];
    CB3RaceCar * field_15CC;
    unsigned char pad_15D0[0xA9];
    unsigned char field_1679[6];
    unsigned char field_167F;
    unsigned char pad_1680[0x26A];
    unsigned char field_18EA;
    unsigned char pad_18EB[0x29];
    int field_1914;
    unsigned char pad_1918[0x94];
    signed char field_19AC;
    unsigned char pad_19AD[0xA4F];
    float field_23FC;
};
class CB3Score {
public:
    int OnTakeDown(CB3RaceCar * p0);
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0x58];
    int field_68;
    unsigned char pad_6C[0x8];
    int field_74;
    unsigned char pad_78[0x8];
    int * field_80;
    unsigned char pad_84[0x44];
    CB3RaceCar * field_C8;
    unsigned char pad_CC[0x58];
    CB3ScoreBonus field_124;
    unsigned char pad_125[0x3AF];
    CB3RaceCar * field_4D4;
    unsigned char pad_4D8[0x18];
    bool field_4F0[6];
    bool field_4F6[6];
    unsigned char pad_4FC[0x4];
    float field_500;
    unsigned char pad_504[0xB5];
    unsigned char field_5B9[6];
};
extern UnkStruct_D_0051BA88 D_0051BA88;





// 0x001553F0
int CB3Score::OnTakeDown(CB3RaceCar *p0)
{
  const CB3CrashStartInfo *info = 0;
  if (p0->field_18EA != 0)
  {
    info = &p0->field_13C8;
  }
  if (p0->field_15C6 == 0)
  {
    p0->field_15CC = field_C8;
    p0->field_15C6 = 1;
    p0->field_15C7 = 1;
    field_68 = field_68 + 1;
    field_500 = field_C;
    field_4D4 = p0;
    int *thr = field_80;
    if (thr != 0)
    {
      int idx = 3;
      int i = idx;
      while (i--)
      {
        if (!(field_68 < thr[i]))
        {
          if ((i > field_74) || (field_74 == 4))
          {
            field_74 = i;
            break;
          }
        }
      }

    }
    int car = p0->field_19AC;
    field_124.OnTakedown(p0, info, field_4F6[car], field_4F0[car]);
    D_0051BA88.field_0->field_1B4->vfunc_64(p0, field_C8);
    unsigned char *pf;
    if ((*(&field_5B9[p0->field_19AC])) != 0)
    {
      *(&field_5B9[p0->field_19AC]) = 0;
      p0->field_167F = 1;
    }
    else
    {
      p0->field_1679[field_C8->field_19AC] = 1;
    }
    if (p0->field_1914 == 1)
    {
      p0->field_23FC = 5.0f + p0->field_10CC;
    }
    return 1;
  }
  return 0;
}
