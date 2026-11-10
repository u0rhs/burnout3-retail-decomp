// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): if (1); {; *((float *) D_004D39A8) = 0.3125f;; *((float *) D_004D39A8) = 0.3125f;; }; *((float *) D_004D39BC) = 0.65625f;; *((float *) D_004D39BC) = 0.65625f;).

extern unsigned char D_004D39A0[];
extern unsigned char D_004D39A4[];
extern unsigned char D_004D39A8[];
extern unsigned char D_004D39AC[];
extern unsigned char D_004D39B0[];
extern unsigned char D_004D39B4[];
extern unsigned char D_004D39B8[];
extern unsigned char D_004D39BC[];
extern unsigned char D_004D39C0[];
extern unsigned char D_004D39C4[];
extern "C" void func_004DD670 ( );

// 0x004DD670
void func_004DD670()
{
  if (1)
  {
    *((float *) D_004D39A0) = 12.0f;
    *((float *) D_004D39A4) = 24.0f;
    *((float *) D_004D39A8) = 0.3125f;
    *((float *) D_004D39AC) = 0.0f;
    *((float *) D_004D39B0) = 0.5f;
  }
  *((float *) D_004D39B4) = 0.0f;
  *((float *) D_004D39B8) = 0.3125f;
  *((float *) D_004D39BC) = 0.65625f;
  *((float *) D_004D39C0) = 0.5f;
  *((float *) D_004D39C4) = 0.65625f;
}
