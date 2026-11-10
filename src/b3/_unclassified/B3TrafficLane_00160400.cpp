// CB3TrafficLane::GetParamFromDist(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficLane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (dperm (decomp-permuter, background run): float new_var;; new_var = p0;; if (cur > p0); if (cur > new_var); if (1) { } if (1) { } if (1) { } if (1 != 0) { } if (1) { }; if (cur < p0); if (cur < new_var); if (!(cur < p0)); if (!(cur < new_var)); new_var = (float) idx;; return ((float) idx) + ((d - (cur - p0)) / d);; return new_var + ((d - (c).

class CB3TrafficLane;
struct UnkStruct_001602F0_1;
struct UnkStruct_001602F0_e0;

struct UnkStruct_001602F0_1 {
    unsigned char pad_0[0x4];
    UnkStruct_001602F0_e0 * field_4;
    unsigned char pad_8[0x8];
    int field_10;
};

struct UnkStruct_001602F0_e0 {
    float field_0;
    unsigned char pad_4[0x4];
};

class CB3TrafficLane {
public:
    float GetParamFromDist(float p0);

    UnkStruct_001602F0_1 * field_0;
};





// 0x00160400
float CB3TrafficLane::GetParamFromDist(float p0)
{
  float v0;
  UnkStruct_001602F0_1 *t0 = field_0;
  int n = t0->field_10;
  UnkStruct_001602F0_e0 *a = t0->field_4;
  UnkStruct_001602F0_e0 *am = a - 1;
  int idx = (int) (((float) n) * (p0 / am[n].field_0));
  float cur;
  v0 = p0;
  if (idx > 0)
  {
    cur = am[idx].field_0;
  }
  else
  {
    cur = a[idx].field_0;
  }
  if (cur > v0)
  {
 if (1) { } if (1) { } if (1) { } if (1 != 0) { } if (1) { }
    while (idx > 0)
    {
      if (cur < v0)
      {
        break;
      }
      idx--;
      cur = a[idx - 1].field_0;
    }

  }
  else
  {
    while (idx < n)
    {
      if (!(cur < v0))
      {
        break;
      }
      idx++;
      cur = a[idx - 1].field_0;
    }

  }
  if (idx > 0)
  {
    idx--;
    v0 = (float) idx;
    float lo = am[idx].field_0;
    float hi = ((UnkStruct_001602F0_1 *) field_0)->field_4[idx].field_0;
    float d = hi - lo;
    return v0 + ((d - (cur - p0)) / d);
  }
  return 0.0f;
}
