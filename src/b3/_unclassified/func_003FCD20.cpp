// Hand-written; the lifter refused it (dperm (decomp-permuter): field_EA = 1 (flag is 1 on every path into fin), flag local dropped).

struct UnkStruct_Soundtrack { int field_0; int field_4; int field_8; short field_C[32]; int field_4C; int field_50; unsigned char field_54; unsigned char pad_55[3]; };
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
extern UnkStruct_Pad16 D_01E774E0;
extern UnkStruct_Soundtrack D_004A5A20;
extern char D_004CEAC0[];
struct UnkStruct_Shorts { short b[32]; };
struct UnkStruct_003FCD20 {
    float field_0;
    float field_4;
    int field_8;
    unsigned char field_C;
    unsigned char pad_D[0x33];
    int field_40;
    int field_44;
    unsigned char pad_48[0x20];
    int field_68;
    int field_6C;
    int field_70;
    UnkStruct_Shorts field_74;
    unsigned int field_B4;
    unsigned int field_B8;
    unsigned char field_BC;
    unsigned char pad_BD[3];
    void * field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4;
    int field_D8;
    int field_DC;
    int field_E0;
    unsigned char pad_E4[4];
    unsigned char field_E8;
    unsigned char field_E9;
    unsigned char field_EA;
};
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, unsigned short *, int);
extern "C" void Stop__14CGtSoundStreamFv(void *);
extern "C" int Release__14CGtSoundStreamFv(void *);
extern "C" void FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(void *, void *);
extern "C" void func_0042B5E0(void *);
extern "C" void func_0042B580(void *);
extern "C" void func_003FC700(void *);
// 0x003FCD20
extern "C" void func_003FCD20(UnkStruct_003FCD20 *self)
{
  int v;
  self->field_D8 = 0;
  self->field_0 = 1.0f;
  self->field_4 = 1.0f;
  self->field_C4 = 0;
  self->field_D4 = 0;
  self->field_C0 = 0;
  self->field_C8 = 6;
  ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(D_004CEAC0, (unsigned short *) D_004A5A20.field_C, 0x20);
  self->field_CC = 2;
  self->field_68 = D_004A5A20.field_0;
  self->field_6C = D_004A5A20.field_4;
  self->field_70 = D_004A5A20.field_8;
  self->field_74 = *((UnkStruct_Shorts *) D_004A5A20.field_C);
  self->field_B4 = D_004A5A20.field_4C;
  self->field_B8 = D_004A5A20.field_50;
  self->field_BC = D_004A5A20.field_54;
  self->field_CC = 2;
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

  func_0042B5E0(&self->field_8);
  self->field_DC = self->field_8 + 1;
  self->field_E8 = 0;
  self->field_E0 = 0;
  self->field_D0 = 0;
  self->field_C = 0;
  self->field_E9 = 0;
  self->field_D0 = 1;
  self->field_40 = 0;
  self->field_44 = 0;
  return;
  five1:
  self->field_D0 = 5;

  func_003FC700(self);
  v = 6;
  goto set6;
  nostream:
  func_0042B580(&self->field_8);
  goto fin;
}
