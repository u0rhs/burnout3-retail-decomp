// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): *((float *) D_004C6E50) = (float) 513;; *((float *) D_004C6E50) = (float) 513;).

extern unsigned char D_004C6E48[];
extern unsigned char D_004C6E4C[];
extern unsigned char D_004C6E50[];
extern unsigned char D_004C6E54[];
extern "C" void func_004D8980 ( );

// 0x004D8980
void func_004D8980()
{
  *((float *) D_004C6E48) = 64.0f;
  *((float *) D_004C6E4C) = 96.0f;
  *((float *) D_004C6E50) = (float) 513;
  *((float *) D_004C6E54) = 81.0f;
}
