// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): UnkStruct_00288480 *new_var;; self->field_4C = self->field_48;; new_var = self;; new_var->field_4C = self->field_48;; _mRandom__13CGtSoundUtils.field_0 = x;; _mRandom__13CGtSoundUtils.field_0 = (((((unsigned int) (x & 0xFFFFFFFF)) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF;).

#include "b3/GtMathPs2.h"
#include "b3/classes/CGtTimer.h"
#include "b3/GtMath.h"

using GtMathPs2::CGtV4d;

struct UnkStruct_00288480_rnd { int field_0; int field_4; };
extern "C" UnkStruct_00288480_rnd _mRandom__13CGtSoundUtils;

struct UnkStruct_00288480_c8d0 {
    unsigned char pad_0[0xC0];
};
struct UnkStruct_00288480_car {
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;
    unsigned char pad_C0[0x810];
    UnkStruct_00288480_c8d0 field_8D0[1];  
    unsigned char pad_990[0x7D9];
    signed char field_1169;
    unsigned char pad_116A[0x26A];
    float field_13D4;
};
struct UnkStruct_00288480_slot {
    UnkStruct_00288480_car *field_0;
    unsigned char pad_4[0x2C];
};
extern UnkStruct_00288480_slot D_0055EFEC[];
struct UnkStruct_00288480_p2 {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};
struct UnkStruct_00288480 {
    unsigned char pad_0[0x44];
    float field_44;
    float field_48;
    float field_4C;
    float field_50;
};
struct UnkStruct_D_0052267C { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0052267C D_0052267C;
extern float D_004E0798;
extern float D_004E1B34;
extern float D_004E1B3C;
extern float D_004E1B40;
extern float D_004E1B44;
extern float D_004E1B48;
extern float D_004E1B4C;
extern float D_004E1B50;
extern "C" float func_0028DFC0(UnkStruct_00288480_c8d0 *);

static inline float func_00288480_inl2() { return D_0052267C.field_0; }
extern "C" void func_00288480 ( UnkStruct_00288480 * self , float * out , const UnkStruct_00288480_p2 * p2 );






// 0x00288480
void func_00288480(UnkStruct_00288480 *self, float *out, const UnkStruct_00288480_p2 *p2)
{
  UnkStruct_00288480_car *c = D_0055EFEC[p2->field_19AC].field_0;
  float amp;
  float t = (float) ((unsigned int) CGtTimer::mguFrames);
  UnkStruct_00288480 *v0;
  int i;
  int cnt = 0;
  for (i = 0; i < c->field_1169; i++)
  {
    if (func_0028DFC0(&c->field_8D0[i]) < 0.5f)
    {
      cnt++;
    }
  }

  if (cnt >= 2)
  {
    self->field_50 -= func_00288480_inl2();
    self->field_44 += func_00288480_inl2();
  }
  else
  {
    self->field_50 = D_004E1B48;
    self->field_44 = 0.0f;
  }
  float k = c->field_13D4;
  float lo = D_004E1B40 * k;
  float hi = D_004E1B44 * k;
  float v = D_004E0798 * ((float) c->field_B0.W());
  v = GtMath::Max(v, lo);
  v = GtMath::Min(v, hi);
  float range = hi - lo;
  float frac = 0.0f;
  unsigned int rbits;
asm ( "mfc1 %0, %1" : "=r" ( rbits ) : "f" ( range ) ) ;
  if ((rbits & 0x7F800000) > 0x37800000)
  {
    frac = v / range;
  }
  self->field_44 = GtMath::Min(D_004E1B34, self->field_44);
  float r = self->field_44 / D_004E1B34;
  amp = r * frac;
  float s1 = sinf(t / self->field_4C);
  float s2 = sinf(t / self->field_48);
  float w;
  if (self->field_50 > 0.0f)
  {
    w = s1 + ((1.0f - (self->field_50 / D_004E1B48)) * (s2 - s1));
  }
  else
  {
    v0 = self;
    v0->field_4C = self->field_48;
    self->field_50 = D_004E1B48;
    int a = _mRandom__13CGtSoundUtils.field_0;
    int x = (a << 16) + (a >> 16);
    x += _mRandom__13CGtSoundUtils.field_4;
    _mRandom__13CGtSoundUtils.field_4 += x;
    _mRandom__13CGtSoundUtils.field_0 = (((((unsigned int) (x & 0xFFFFFFFF)) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF;
    self->field_48 = D_004E1B4C + ((2.3283064e-10f * ((float) ((unsigned int) x))) * (D_004E1B50 - D_004E1B4C));
    w = s2;
  }
  w *= D_004E1B3C * amp;
  *out += w;
}
