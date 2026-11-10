// func_0022DA60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (decomp-permuter (build/vt/permsetup.py)).

extern "C" {

typedef struct UnkStruct_0022DA60 UnkStruct_0022DA60;
typedef struct UnkStruct_D_01D7B700 UnkStruct_D_01D7B700;
struct UnkStruct_0022DA60;
struct UnkStruct_D_01D7B700;
struct UnkStruct_D_01D7B700
{
  unsigned char pad_0[0x10];
};
struct UnkStruct_0022DA60
{
  unsigned char pad_0[0x94];
  int field_94;
  unsigned char pad_98[0x670];
  unsigned char field_708;
};
extern UnkStruct_D_01D7B700 D_01D7B700;
void *memset(void *, int, unsigned int);
int ezNetCtlInit();
int ezNetCtlDownInterface();
int ezNetCtlWaitEventTO(int);
int ezNetCtlExit(int);
void sceLibnetUnregisterHandler(void *, void *);
void sceLibnetTerminate(void *);
void sceInsockTerminate(int);
// 0x0022DA60
void func_0022DA60(UnkStruct_0022DA60 *self)
{
  char *t_n0;
  ezNetCtlInit();
  while (ezNetCtlDownInterface() == 0)
  {
    int r1 = ezNetCtlWaitEventTO(10000);
    if (r1 >= 0)
    {
      if (r1 != 11)
      {
        continue;
      }
    }
    break;
  }

  ezNetCtlExit(2);
  t_n0 = (char *) self;
  sceLibnetUnregisterHandler(t_n0 + 0x50, &D_01D7B700);
  sceLibnetTerminate(t_n0 + 0x50);
  sceInsockTerminate(self->field_94);
  sceInsockTerminate(0);
  memset(t_n0 + 0xA8, 0, 4);
  memset(t_n0 + 0x2C, 0, 16);
  memset(t_n0 + 0x1C, 0, 16);
  self->field_708 = 0;
}

}
