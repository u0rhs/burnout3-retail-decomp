// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): const int t7 = (crc ^ data[i]) & 0xFF;; t6 = (crc ^ data[i]) & 0xFF;; const int t7 = t6;; t3 = (unsigned long) t0;; t3 = (unsigned long) (t0 & 0xFFFFFFFFu);; if (t2); {; }).

struct UnkStruct_D_004B13CC { int v; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004B13C0 { unsigned int * v; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004B13CC D_004B13CC;
extern UnkStruct_D_004B13C0 D_004B13C0;
extern "C" int func_00469880 ( const unsigned char * data , unsigned int len );




// 0x00469880
int func_00469880(const unsigned char *data, unsigned int len)
{
  unsigned int i;
  unsigned int crc = D_004B13CC.v;
  unsigned long t6;
  unsigned int *tbl = D_004B13C0.v;
  if (tbl == 0)
  {
    return 6;
  }
  const bool t5 = data == 0;
  const bool t2 = t5;
  if (!t2)
  {
  }
  else
  {
    goto ret0;
  }
  i = 0;
  goto test;
  body:
  ;

  t6 = (crc ^ data[i]) & 0xFF;
  const int t7 = t6;
  int t8 = crc >> 8;
  int t0 = t8;
  const int t1 = t7;
  long t3;
  t3 = (unsigned long) (t0 & 0xFFFFFFFFu);
  unsigned long t4 = t3 & 0xFFFFFF;
  t6 = t4 ^ ((unsigned long) tbl[t1]);
  crc = t6;
  ++i;
  test:
  if (i < len)
  {
    goto body;
  }

  if (t2)
  {
  }
  D_004B13CC.v = crc;
  return 0;
  ret0:
  return 2;

}
