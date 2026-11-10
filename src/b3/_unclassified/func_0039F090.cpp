// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): *p = (*p) - 1;; *p = (*p) + -1;; int id = (((unsigned) (*p)) < 2) ? (0x2E5) : (0x2E4);; lo = *p;; int id = (((unsigned) lo) < 2) ? (0x2E5) : (0x2E4);).

class CB3InputManager {
public:
    int GetMenuLeft(signed char);
    int GetMenuRight(signed char);
    unsigned char pad_0[0x10];
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E8D4B0 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E89810 { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_0039F090 {
    unsigned char pad_0[0x4];
    unsigned short field_4;
    unsigned char pad_6[0x8];
    unsigned char field_E;
    unsigned char pad_F[0x5];
    unsigned char field_14;
    unsigned char pad_15[3];
    unsigned char * field_18;
    unsigned char pad_1C[0x78];
    unsigned short field_94;
    unsigned short field_96;
    unsigned char pad_98[0x50];
    int field_E8;
    unsigned char pad_EC[0x8];
    unsigned char field_F4;
    unsigned char pad_F5[0x2B];
    unsigned long field_120[1];
    unsigned char pad_128[0xE8];
    int field_210;
    unsigned char pad_214[0x4];
    unsigned long field_218[1];
    unsigned char pad_220[0x4C0];
    int field_6E0;
    int field_6E4;
    int field_6E8;
    int field_6EC;
    int field_6F0;
    int field_6F4;
    unsigned char pad_6F8[0x8];
    signed char field_700;
};
extern CB3InputManager D_004F50C0;
extern UnkStruct_P D_01E7A800, D_01E8961C, D_01E89800;
extern UnkStruct_D_01E8D4B0 D_01E8D4B0;
extern UnkStruct_B D_01E8D4BA;
extern UnkStruct_D_01E89810 D_01E89810;
extern UnkStruct_P D_004C9B78, D_004C9B80, D_004C9B88, D_004C9B90;
extern UnkStruct_F D_004C9B98;
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" unsigned long func_0039EC90(void *);
extern "C" unsigned long func_0039EF40(void *);
extern "C" void func_0039E5F0(void *);
extern "C" void func_0039DE20(void *);
extern "C" void func_0039D900(void *);
extern "C" bool func_00351F00(void *, void *, void *, void *, void *, void *, int, int, int, int, int, float, float);

static inline int func_0039D900_inl1(UnkStruct_0039F090 * self, int i)
{
    unsigned char *p = self->field_18;
    if (p == 0 || i < 0 || i > self->field_14) return 0;
    return *(unsigned char *)((char *)p + i);
}
extern "C" void func_0039F090 ( UnkStruct_0039F090 * self );





// 0x0039F090
void func_0039F090(UnkStruct_0039F090 *self)
{
  int *p;
  int lo;
  int hi;
  switch (self->field_4)
  {
    case 0:
      p = &self->field_6E4;
      lo = 0;
      hi = 5;
      break;

    case 1:
      hi = self->field_6E0;
      p = &self->field_6EC;
      lo = 0;
      break;

    case 2:
      lo = self->field_94;
      p = &self->field_6F0;
      hi = self->field_96 + 1;
      break;

    case 3:
      hi = self->field_E8;
      p = &self->field_6F4;
      lo = 0;
      break;

    default:
      return;

  }

  int old = *p;
  if (D_004F50C0.GetMenuLeft(0))
  {
    *p = (*p) + -1;
    if ((*p) < lo)
    {
      *p = hi - 1;
    }
  }
  else
    if (D_004F50C0.GetMenuRight(0))
  {
    *p = (*p) + 1;
    if ((*p) >= hi)
    {
      *p = lo;
    }
  }
  if ((*p) != old)
  {
    if (self->field_4 != 0)
    {
      self->field_F4 = 0;
      FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
      SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, self->field_4, *p);
    }
    if (self->field_4 == 0)
    {
      self->field_F4 = 0;
      if (!(((unsigned) self->field_700) > 1))
      {
        self->field_6E8 = 0;
        self->field_6EC = 0;
        self->field_120[0] = func_0039EF40(self);
        self->field_210 = 1;
      }
      FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
      SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, self->field_4, *p);
      if (D_01E8D4BA.field_0 != 0)
      {
        ((UnkStruct_D_01E8D4B0 *) (&D_01E8D4B0))->vfunc_C();
      }
      switch (*p)
      {
        case 0:
          func_0039E5F0(self);
          break;

        case 1:
          func_0039DE20(self);
          break;

        case 2:

        case 3:

        case 4:
          func_0039D900(self);
          break;

      }

    }
    else
      if (self->field_4 == 1)
    {
      if ((*p) == 0)
      {
        self->field_218[0] = func_0039EC90(self);
      }
    }
    if (self->field_4 == 0)
    {
      if (D_01E8D4BA.field_0 != 0)
      {
        ((UnkStruct_D_01E8D4B0 *) (&D_01E8D4B0))->vfunc_C();
      }
      if (func_0039D900_inl1(self, *p))
      {
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 & (~0x10UL), 3);
        lo = *p;
        int id = (((unsigned) lo) < 2) ? (0x2E5) : (0x2E4);
        func_00351F00(&D_01E8D4B0, &D_004C9B78, &D_004C9B80, &D_004C9B88, &D_004C9B90, &D_004C9B98, id, 0x103, 1, 3, 0, 26.0f, D_004C9B98.field_0 - 16.0f);
      }
      else
      {
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 | 0x10, 3);
      }
    }
  }
}
