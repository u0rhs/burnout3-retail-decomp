// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): *((float *) D_004C6EA8) = (float) 545;; *((float *) D_004C6EA8) = (float) 545;).

extern unsigned char D_004C6EA0[];
extern unsigned char D_004C6EA4[];
extern unsigned char D_004C6EA8[];
extern unsigned char D_004C6EAC[];
extern "C" void func_004D8A40 ( );

// 0x004D8A40
void func_004D8A40()
{
  *((float *) D_004C6EA0) = 64.0f;
  *((float *) D_004C6EA4) = 96.0f;
  *((float *) D_004C6EA8) = (float) 545;
  *((float *) D_004C6EAC) = 81.0f;
}
