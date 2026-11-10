// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): if (p1); {; }; else; {; goto after1;; }).

class CGtSoundBank;

class CB3SoundGameModeManager {
public:
    void TriggerSpotDucker(float);

    unsigned char pad_0[0x10];  
};

struct UnkStruct_00285C00 {
    unsigned char pad_0[0x38];
    float field_38;
    unsigned char pad_3C[0x3C];
    int field_78;
};

struct UnkStruct_00285C00_m { unsigned char pad_0[0x1B4]; void * field_1B4; };
struct UnkStruct_00285C00_g { UnkStruct_00285C00_m * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00285C00_p { unsigned char pad_0[0x10]; };
struct UnkStruct_00285C00_i { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00285C00_ip { int * field_0; unsigned char pad_4[0xC]; };

extern CB3SoundGameModeManager D_01E77540;
extern UnkStruct_00285C00_g D_0051BA88;
extern UnkStruct_00285C00_p D_0051B340;
extern UnkStruct_00285C00_p D_004EE040;
extern UnkStruct_00285C00_i D_0064E4D8;
extern UnkStruct_00285C00_ip D_0064E4F0;

extern "C" int func_00131CE0(void *);
extern "C" void func_00285560(UnkStruct_00285C00 * self, int p0, int p1);
extern "C" void func_00285770(UnkStruct_00285C00 * self, int p0);
extern "C" void PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(void *, unsigned long, const void *, float, float, bool, float);  

#define PLAY(id, a, b, f, c) PlayHudSound__18CB3HUDSoundManagerFUlPC12CGtSoundBankffb(self, id, (const CGtSoundBank*)self->field_78, a, b, f, c)


static inline void func_00285C00_inl1(UnkStruct_00285C00 * self, int n)
{
    float v;
    switch (n) {
    case 0:
        v = 1.0f;
        break;
    case 1:
        v = 1.12246f;
        break;
    case 2:
        v = 1.18921f;
        break;
    case 3:
        v = 1.25992f;
        break;
    case 4:
        v = 1.41421f;
        break;
    }
    PLAY(0xBCB1BCEECD400000, self->field_38, v, 0, 0.0f);
    PLAY(0xBCB1BCEECD400000, self->field_38 / 2.0f, v, 0, 0.0f);
    D_01E77540.TriggerSpotDucker(0.5f);
}


#pragma push
#pragma opt_repositioncode off
extern "C" void func_00285C00 ( UnkStruct_00285C00 * self , int p0 , int p1 , int p2 );




// 0x00285C00
void func_00285C00(UnkStruct_00285C00 *self, int p0, int p1, int p2)
{
  int n;
  switch (p0)
  {
    case 9:
      PLAY(0x5370D087C0000000, 1.0f, 1.0f, 0, 0.0f);
      return;

    case 14:
      PLAY(0xBEBB1CDB8DB40000, 0.9f, 1.0f, 0, 0.75f);
      return;

    case 4:
      if ((p1 >= 0xAA) && (p1 < 0xAF))
    {
      func_00285770(self, p1 - 0xAA);
      return;
    }
      if ((p1 >= 0xAF) && (p1 < 0xC3))
    {
      func_00285770(self, 99);
      return;
    }
      n = 0;
      if (p1 == 0x93)
    {
      goto nj;
    }
    else
      if ((p1 == 0xA3) || (p1 == 0x9F))
    {
      goto n1;
    }
    else
      if ((p1 == 0xA4) || (p1 == 0xA0))
    {
      goto n2;
    }
    else
      if ((p1 == 0xA5) || (p1 == 0xA1))
    {
      goto n3;
    }
    else
      if ((p1 == 0xA6) || (p1 == 0xA2))
    {
      goto n4;
    }
      nj:
    if (D_0051BA88.field_0 != 0)
    {
      goto big;
    }

      fallback:
    func_00285C00_inl1(self, n);

      return;

    case 10:
      func_00285560(self, 2, 1);
      break;

    case 11:
      func_00285560(self, 1, 1);
      break;

    case 12:
      func_00285560(self, 0, 1);
      break;

    case 0:

    case 1:

    case 2:

    case 3:
      break;

  }

  after1:
  switch (p1)
  {
    case 0x76:

    case 0x55:

    case 0x45:

    case 0x37:

    case 0x3A:

    case 0x3D:

    case 0x40:

    case 0x4D:

    case 0x5D:

    case 0x7B:

    case 0x7A:
      PLAY(0xB9A33E7654300000, 0.75f, 1.0f, 1, 0.0f);
      PLAY(0x6048D35D03000000, 0.5f, 1.0f, 1, 0.25f);
      return;

    case 0x77:

    case 0x46:

    case 0x38:

    case 0x3B:

    case 0x3E:

    case 0x41:

    case 0x4E:

    case 0x56:

    case 0x5E:

    case 0x7C:
      PLAY(0xB9A33E7654300000, 0.75f, 1.0f, 1, 0.0f);
      PLAY(0x6048D35D03000000, 0.6f, 1.12246f, 1, 0.25f);
      return;

    case 0x78:

    case 0x47:

    case 0x39:

    case 0x3C:

    case 0x3F:

    case 0x4F:

    case 0x57:

    case 0x5F:

    case 0x7D:
      PLAY(0xB9A33E7654300000, 0.75f, 1.0f, 1, 0.0f);
      PLAY(0x6048D35D03000000, 0.7f, 1.18921f, 1, 0.25f);
      return;

    case 0x48:

    case 0x50:

    case 0x58:

    case 0x60:

    case 0x7E:
      PLAY(0xB9A33E7654300000, 0.75f, 1.0f, 1, 0.0f);
      PLAY(0x6048D35D03000000, 0.8f, 1.25992f, 1, 0.25f);
      return;

    case 0x83:
      PLAY(0xB894EB49168A0000, 1.0f, 1.0f, 0, 0.0f);
      return;

    case 0x88:
      func_00285770(self, 0);
      return;

    case 0xC5:
      func_00285560(self, 2, 0);
      return;

    case 0xC6:
      func_00285560(self, 1, 0);
      return;

    case 0xC7:
      func_00285560(self, 0, 0);
      return;

    case 0x71:

    case 0x72:

    case 0x73:

    case 0x74:

    case 0x75:
      PLAY(0xB9A33E7654300000, 0.3f, 1.0f, 1, 0.0f);
      PLAY(0xB9267F8F66000000, 0.4f, 1.0f, 1, 0.25f);
      if (p2 > 1)
    {
      goto p2a;
    }
      p2t:
    if (p2 == 3)
    {
      goto p2b;
    }

      p2j:
    return;


    default:
      if (((p0 == 1) || (p0 == 2)) || (((unsigned int) (p0 - 5)) <= 3))
    {
      goto dfl;
    }
      dj:
    return;


  }


  n1:
  n = 1;

  goto nj;
  n2:
  n = 2;

  goto nj;
  n3:
  n = 3;

  goto nj;
  n4:
  n = 4;

  goto nj;
  big:
  if ((func_00131CE0(&D_004EE040) == 0) || (D_0051BA88.field_0->field_1B4 != (&D_0051B340)))
  {
    goto fallback;
  }

  {
    int d = D_0064E4D8.field_0 - D_0064E4F0.field_0[2];
    if (d > 0)
    {
      if (d < 5)
      {
        if (n < d)
        {
          func_00285C00_inl1(self, d);
        }
        else
        {
          func_00285C00_inl1(self, n);
        }
        return;
      }
      else
        if (d > 4)
      {
        int k = d - 5;
        if (k > 4)
        {
          k = 4;
        }
        func_00285770(self, k);
        return;
      }
    }
    else
    {
      func_00285C00_inl1(self, n);
      return;
    }
    if (p1)
    {
      goto after1;
    }
    else
    {
      goto after1;
    }
  }
  p2a:
  PLAY(0xB9267F8F66000000, 0.5f, 1.0f, 1, 0.5f);

  goto p2t;
  p2b:
  PLAY(0xB9267F8F66000000, 1.0f, 1.0f, 1, 0.75f);

  goto p2j;
  dfl:
  PLAY(0xB9A33E7654300000, 0.75f, 1.0f, 1, 0.0f);

  PLAY(0x6048D35D03000000, 0.5f, 1.0f, 1, 0.25f);
  goto dj;
}


#pragma pop
