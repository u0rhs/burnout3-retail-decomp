// Hand-written; the lifter refused it (dperm (decomp-permuter): field_EA = 1 (flag is 1 on every path into fin), flag local dropped).

struct UnkStruct_Soundtrack { int field_0; int field_4; int field_8; short field_C[32]; int field_4C; int field_50; unsigned char field_54; };
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
extern UnkStruct_Pad16 D_01E774E0;
struct UnkStruct_Shorts { short b[32]; };
struct UnkStruct_003FC060 {
    unsigned char pad_0[0x8];
    unsigned char field_8[0x60];
    int field_68;
    int field_6C;
    int field_70;
    UnkStruct_Shorts field_74;
    unsigned int field_B4;
    unsigned int field_B8;
    unsigned char field_BC;
    unsigned char pad_BD[3];
    void * field_C0;
    unsigned char pad_C4[4];
    int field_C8;
    int field_CC;
    int field_D0;
    unsigned char pad_D4[4];
    int field_D8;
    unsigned char pad_DC[0xC];
    unsigned char field_E8;
    unsigned char pad_E9;
    unsigned char field_EA;
};
extern "C" void Stop__14CGtSoundStreamFv(void *);
extern "C" int Release__14CGtSoundStreamFv(void *);
extern "C" void FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(void *, void *);
extern "C" int func_0042B510(void *, void *, int, int);
extern "C" void func_0042B580(void *);
extern "C" void func_003FC700(void *);
extern "C" void func_003FBC20(void *, int);
// N182: `#pragma opt_repositioncode off` ([G] scoped to this function; found by mwperm).
#pragma push
#pragma opt_repositioncode off
// 0x003FC060
extern "C" int func_003FC060(UnkStruct_003FC060 *self, UnkStruct_Soundtrack *p0, int p1, int p2)
{
  int v;
  int r2;
  self->field_68 = p0->field_0;
  self->field_6C = p0->field_4;
  self->field_70 = p0->field_8;
  self->field_74 = *((UnkStruct_Shorts *) p0->field_C);
  self->field_B4 = p0->field_4C;
  self->field_B8 = p0->field_50;
  self->field_BC = p0->field_54;
  self->field_CC = p2;
  if (p1 == (-1))
  {
    self->field_E8 = self->field_E8 & 0xFE;
    if (self->field_BC == 0)
    {
      goto nostream;
    }
    if (self->field_C0 != 0)
    {
      Stop__14CGtSoundStreamFv(self->field_C0);
      Release__14CGtSoundStreamFv(self->field_C0);
      FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, self->field_C0);
      self->field_C0 = 0;
    }
    if (self->field_D0 == 4)
    {
      goto five1;
    }
    v = 6;
    set6:
    self->field_C8 = v;
    fin:
    self->field_EA = 1;

    return 0;
  }
  self->field_EA = 0;
  if (p0->field_54 != 0)
  {
    goto soundtrack;
  }
  self->field_D8 = p1;
  if (self->field_D0 == 4)
  {
    goto five2;
  }
  r2 = p1;
  call:
  return func_0042B510(&self->field_8, &self->field_68, r2, p2);

  five1:
  self->field_D0 = 5;

  func_003FC700(self);
  v = 6;
  goto set6;
  nostream:
  func_0042B580(&self->field_8);
  goto fin;
  soundtrack:
  func_003FBC20(self, p1);

  return 1;
  five2:
  self->field_D0 = 5;

  func_003FC700(self);
  r2 = p1;
  goto call;
}
