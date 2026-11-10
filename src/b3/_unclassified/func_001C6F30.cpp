// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): inline float inline_fn(float arg0, float arg1); {; return arg0 / arg1;; }; float s = p1 / p0;; float s = inline_fn(p1, p0);).

struct UnkStruct_001C6F30 {
    unsigned char pad_0[0x4];
    float field_4[7];                         
    float field_20;
    unsigned char pad_24[0x4];
    float field_28;
    unsigned char pad_2C[0x28];
    float field_54;
    unsigned char pad_58[0x2C];
    int field_84;
};

extern float D_004E0D80;
extern "C" int func_001C6F30 ( UnkStruct_001C6F30 * t , float p0 , float p1 );




inline float func_001C6F30_inl1(float arg0, float arg1)
{
  return arg0 / arg1;
}

// 0x001C6F30
int func_001C6F30(UnkStruct_001C6F30 *t, float p0, float p1)
{
  float s = func_001C6F30_inl1(p1, p0);
  float up = D_004E0D80 * t->field_28;
  float r;
  int g;
  for (g = 1; g < t->field_84; g++)
  {
    r = t->field_20 * (s * t->field_4[g]);
    if (r <= up)
    {
      break;
    }
  }

  t->field_54 = r;
  return g;
}
