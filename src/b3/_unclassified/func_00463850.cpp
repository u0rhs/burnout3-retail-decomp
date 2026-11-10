// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): inline unsigned int inline_fn(int arg0); {; return (unsigned int) arg0;; }; sz = 12 + ((k8C - (12 % ((unsigned int) k8C))) % ((unsigned int) k8C));; sz = 12 + ((k8C - (12 % inline_fn(k8C))) % inline_fn(k8C));; sz = 12 + ((k84 - (12 % ((unsigned int) k84))) % ((unsigned int) k84));; sz = 12 + ((k84 -).

struct UnkStruct_00463850_v {
    unsigned char pad_0[0xC];
    int (*vfunc_C)(int, int);
    int (*vfunc_10)(unsigned int, int);
    int (*vfunc_14)(int, int);
    int (*vfunc_18)();
};
struct UnkStruct_00463850_w {
    unsigned char pad_0[0xC];
    int (*vfunc_C)();
    int (*vfunc_10)(int, int);
    int (*vfunc_14)(void *);
};
struct UnkStruct_00463850_r { int field_0; int field_4; };
struct UnkStruct_00463850_g {
    unsigned char pad_0[0x60];
    unsigned char field_60[4];
    int field_64;
    int field_68;
    UnkStruct_00463850_v * field_6C;
    UnkStruct_00463850_w * field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    unsigned char field_88[4];
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    unsigned char pad_A0[0x8];
    unsigned char field_A8;
};
struct UnkStruct_D_004E2FBC_a { UnkStruct_00463850_g * field_0; };
struct UnkStruct_D_004D3B70 { unsigned char pad_0[0x10]; };  
extern UnkStruct_D_004E2FBC_a D_004E2FBC;
extern UnkStruct_D_004D3B70 D_004D3B70;
extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" void * memset(void *, int, unsigned int);
extern "C" int memcmp(const void *, const void *, unsigned int);
extern "C" int func_004670A0(int *, int *);
extern "C" void func_004652B0(int, int *, int *);
extern "C" int func_004651E0(int, int, void *);
extern "C" int func_00464F70();
extern "C" int func_00464CD0();
extern "C" int func_00467350(UnkStruct_00463850_g *, int, int);
extern "C" int func_00467440(UnkStruct_00463850_g *, int, int);
extern "C" int func_00467E80(UnkStruct_00463850_g *);


static inline int func_00463850_inl1(int a, int b)
{
    UnkStruct_00463850_g * g = D_004E2FBC.field_0;
    if (g->field_6C == 0) return 0;
    int r = g->field_6C->vfunc_C(g->field_64, g->field_68);
    if (r == 0) {
        r = D_004E2FBC.field_0->field_6C->vfunc_14(a, b);
        if (r == 0) {
            r = D_004E2FBC.field_0->field_6C->vfunc_18();
            if (r == 0) return 0;
        }
    }
    return r == 0 ? 0 : r + 200;
}
static inline void func_00463850_inl2(void * d, const void * s)
{
    if (d == 0) return;
    memcpy(d, s, 4);
}
static inline int func_00463850_inl3(int r)
{
    if (r == 0) return 0;
    return r + 0x64;
}
static inline void func_00463850_inl4(void * dst, UnkStruct_00463850_r ** po)
{
    int n = D_004E2FBC.field_0->field_94 * 16;
    if (n == 0) {
        memset(dst, 0, 4);
    } else {
        int s6 = D_004E2FBC.field_0->field_9C;
        UnkStruct_00463850_w * w = D_004E2FBC.field_0->field_70;
        if (w->vfunc_C() == 0) {
            if (w->vfunc_10(s6, n) == 0) w->vfunc_14(po);
        }
        memcpy(dst, (void *)(*po)->field_4, 4);
    }
}
static inline unsigned int func_00463850_inl5(unsigned int n, unsigned int a)
{
    if (n < a) {
        n = a;
    } else {
        n = n + (a - n % a) % a;
    }
    return n;
}
static inline int func_00463850_inl0()
{
    return D_004E2FBC.field_0 != 0;
}
extern "C" int func_00463850 ( int * p0 , int * p1 );




inline unsigned int func_00463850_inl1(int arg0)
{
  return (unsigned int) arg0;
}

// 0x00463850
int func_00463850(int *p0, int *p1)
{
  unsigned char buf[4];
  int kB8;
  int kB4;
  UnkStruct_00463850_r *oB0;
  int kAC;
  int kA8;
  UnkStruct_00463850_r *oA4;
  int xA0;
  int x9C;
  int k98;
  int k94;
  int k90;
  int k8C;
  int k88;
  int k84;
  if (func_00463850_inl0() == 0)
  {
    return 2;
  }
  if (p0 == 0)
  {
    return 4;
  }
  if (p1 == 0)
  {
    return 4;
  }
  int err = func_004670A0(p0, p1);
  if (((*p0) == 0) && (D_004E2FBC.field_0->field_74 != 0))
  {
    return 8;
  }
  if ((*p0) != 2)
  {
    goto out;
  }
  if (((err != 0) && (D_004E2FBC.field_0->field_74 != 4)) && (D_004E2FBC.field_0->field_74 != 5))
  {
    return func_00463850_inl3(err);
  }
  if ((D_004E2FBC.field_0->field_74 == 1) && (err == 0))
  {
    D_004E2FBC.field_0->field_A8 = 1;
  }
  if ((D_004E2FBC.field_0->field_74 != 1) && (D_004E2FBC.field_0->field_74 != 4))
  {
    D_004E2FBC.field_0->field_A8 = 0;
  }
  if (D_004E2FBC.field_0->field_74 == 6)
  {
    if (D_004E2FBC.field_0->field_78 == 5)
    {
      *p0 = 1;
      return func_00464F70();
    }
    if (D_004E2FBC.field_0->field_78 == 6)
    {
      memcpy(((char *) D_004E2FBC.field_0->field_7C) - 12, &D_004D3B70, 12);
      int n = D_004E2FBC.field_0->field_84;
      kB8 = 4;
      kB4 = 1;
      func_004652B0(2, &kB8, &kB4);
      if ((*p1) != func_00463850_inl5(n + 12, kB4))
      {
        return 0x6E;
      }
      *p1 = D_004E2FBC.field_0->field_84;
      int v = func_00463850_inl1(D_004E2FBC.field_0->field_7C, D_004E2FBC.field_0->field_84);
      if (v != 0)
      {
        return v;
      }
      if (err == 0)
      {
        func_00463850_inl4(D_004E2FBC.field_0->field_60, &oB0);
      }
    }
  }
  int st = D_004E2FBC.field_0->field_74;
  if (st == 8)
  {
    if (D_004E2FBC.field_0->field_78 == 5)
    {
      *p0 = 1;
      D_004E2FBC.field_0->field_78 = 10;
      char *b = ((char *) D_004E2FBC.field_0->field_7C) - 12;
      int n = D_004E2FBC.field_0->field_84;
      k98 = 4;
      k94 = 1;
      func_004652B0(1, &k98, &k94);
      return func_00463850_inl3(func_00467350(D_004E2FBC.field_0, (int) b, func_00463850_inl5(n + 12, k94)));
    }
    if (D_004E2FBC.field_0->field_78 == 10)
    {
      char *b = ((char *) D_004E2FBC.field_0->field_7C) - 12;
      int n = D_004E2FBC.field_0->field_84;
      kAC = 4;
      kA8 = 1;
      func_004652B0(1, &kAC, &kA8);
      int r;
      if ((*p1) == func_00463850_inl5(n + 12, kA8))
      {
        *p1 = D_004E2FBC.field_0->field_84;
        r = func_00464CD0();
      }
      else
      {
        r = 0x6E;
      }
      memcpy(b, &D_004D3B70, 12);
      return r;
    }
  }
  if ((st == 4) || (st == 5))
  {
    int s = D_004E2FBC.field_0->field_78;
    if (s == 4)
    {
      if (err != 0)
      {
        D_004E2FBC.field_0->field_A8 = 0;
        return func_00463850_inl3(err);
      }
      func_00467E80(D_004E2FBC.field_0);
      *p0 = 1;
      D_004E2FBC.field_0->field_78 = 9;
      return func_00463850_inl3(func_00467440(D_004E2FBC.field_0, 0, 0));
    }
    else
      if (s == 9)
    {
      if (err != 0)
      {
        D_004E2FBC.field_0->field_A8 = 0;
        return func_00463850_inl3(err);
      }
      if (D_004E2FBC.field_0->field_A8 != 0)
      {
        D_004E2FBC.field_0->field_A8 = 0;
        *p0 = 2;
        return 0;
      }
      D_004E2FBC.field_0->field_A8 = 0;
      *p0 = 1;
      D_004E2FBC.field_0->field_78 = 7;
      k90 = 4;
      k8C = 1;
      func_004652B0(1, &k90, &k8C);
      {
        unsigned int sz;
        if (12 < ((unsigned int) k8C))
        {
          sz = k8C;
        }
        else
        {
          sz = 12 + ((k8C - (12 % func_00463850_inl1(k8C))) % func_00463850_inl1(k8C));
        }
        return func_00463850_inl3(func_00467350(D_004E2FBC.field_0, D_004E2FBC.field_0->field_80, sz));
      }
    }
    else
      if (s == 7)
    {
      if ((err != 0) && (err != 10))
      {
        D_004E2FBC.field_0->field_A8 = 0;
        return func_00463850_inl3(err);
      }
      if ((err == 10) || (D_004E2FBC.field_0->field_94 == D_004E2FBC.field_0->field_90))
      {
        *p0 = 2;
        memcpy((void *) D_004E2FBC.field_0->field_80, &D_004D3B70, 12);
        func_00463850_inl4(buf, &oA4);
        if (D_004E2FBC.field_0->field_74 == 5)
        {
          return (memcmp(buf, D_004E2FBC.field_0->field_60, 4) == 0) ? (0) : (9);
        }
        memcpy(D_004E2FBC.field_0->field_60, buf, 4);
        return 0;
      }
      *p0 = 1;
      x9C = 0;
      D_004E2FBC.field_0->field_78 = 11;
      int v = func_00463850_inl1(D_004E2FBC.field_0->field_80, 12);
      if (v != 0)
      {
        return v;
      }
      char *s0 = (char *) D_004E2FBC.field_0->field_80;
      unsigned char *s1 = D_004E2FBC.field_0->field_88;
      func_00463850_inl2(&xA0, s0);
      func_00463850_inl2(&x9C, s0 + 4);
      func_00463850_inl2(s1, s0 + 8);
      int r = func_004651E0(xA0, x9C, D_004E2FBC.field_0->field_88);
      int r2;
      if (D_004E2FBC.field_0->field_98 != r)
      {
        r2 = func_00463850_inl3(func_00467440(D_004E2FBC.field_0, D_004E2FBC.field_0->field_98, 0));
      }
      else
      {
        r2 = 5;
      }
      return r2;
    }
    else
    {
      if (err == 0)
      {
        *p0 = 1;
        D_004E2FBC.field_0->field_78 = 7;
        k88 = 4;
        k84 = 1;
        func_004652B0(1, &k88, &k84);
        {
          unsigned int sz;
          if (12 < ((unsigned int) k84))
          {
            sz = k84;
          }
          else
          {
            sz = 12 + ((k84 - (12 % func_00463850_inl1(k84))) % func_00463850_inl1(k84));
          }
          return func_00463850_inl3(func_00467350(D_004E2FBC.field_0, D_004E2FBC.field_0->field_80, sz));
        }
      }
      return func_00463850_inl3(err);
    }
  }
  if ((*p0) == 2)
  {
    D_004E2FBC.field_0->field_74 = 0;
    D_004E2FBC.field_0->field_78 = 0;
  }
  out:
  return func_00463850_inl3(err);

}
