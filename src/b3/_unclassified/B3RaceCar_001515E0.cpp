// CB3RaceCar::CalcRaceDistFromRaceCars() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (dperm (decomp-permuter): second divide by d0 reassigned 200.0f (d0 dead), (short) cast on field_0 compare).

class CB3Score {
public:
    short field_0;
    float GetTotalRaceDistFromAILaneStart();
};
struct UnkStruct_D_0064D37C {
    int field_0;
    unsigned char pad_4[0xC];
};
class CB3RaceCar {
public:
    void CalcRaceDistFromRaceCars();
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
    unsigned char pad_10C2[0x116];
    float field_11D8;
    unsigned char pad_11DC[0x6B8];
    float field_1894[32];
    int field_1914;
    unsigned char pad_1918[0x94];
    signed char field_19AC;
};
extern unsigned char D_00522660[];
extern UnkStruct_D_0064D37C D_0064D37C;

// 0x001515E0
void CB3RaceCar::CalcRaceDistFromRaceCars()
{
  int i = 0;
  float mn = 0.0f;
  int last = D_0064D37C.field_0 - 1;
  for (; i < D_0064D37C.field_0; i++)
  {
    if (i == this->field_19AC)
    {
      continue;
    }
    CB3RaceCar *o = *((CB3RaceCar **) ((D_00522660 + (((unsigned) i) * 4)) + 0x12AD28));
    float d0 = this->field_10C0.GetTotalRaceDistFromAILaneStart();
    float d1 = o->field_10C0.GetTotalRaceDistFromAILaneStart();
    float *p = &this->field_1894[i];
    *p = d1 - d0;
    int t = o->field_1914;
    if (t == 2)
    {
      if ((*p) > 0.0f)
      {
        float r = (*p) / 200.0f;
        if (r > mn)
        {
          mn = r;
        }
      }
    }
    d0 = 200.0f;
    if ((((short) o->field_10C0.field_0) == last) && (t == 1))
    {
      float r = (*p) / d0;
      if (r > mn)
      {
        mn = r;
      }
    }
  }

  if (mn > 8.0f)
  {
    mn = 8.0f;
  }
  this->field_11D8 = mn;
}
