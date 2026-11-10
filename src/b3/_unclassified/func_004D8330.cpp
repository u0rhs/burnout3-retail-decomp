// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): float *new_var;; new_var = (float *) D_004C551C;; *new_var = 112.0f;; *((float *) D_004C5524) = 0.0f;; new_var = (float *) D_004C5524;; *new_var = 0.0f;; *((float *) D_004C5528) = (float) 513;; *((float *) D_004C5528) = (float) 513;).

extern unsigned char D_004C5508[];
extern unsigned char D_004C550C[];
extern unsigned char D_004C5510[];
extern unsigned char D_004C5514[];
extern unsigned char D_004C5518[];
extern unsigned char D_004C551C[];
extern unsigned char D_004C5520[];
extern unsigned char D_004C5524[];
extern unsigned char D_004C5528[];
extern unsigned char D_004C552C[];
extern "C" void func_004D8330 ( );

// 0x004D8330
void func_004D8330()
{
  float *v0;
  *((float *) D_004C5508) = 72.0f;
  v0 = (float *) D_004C551C;
  *((float *) D_004C550C) = 168.0f;
  *((float *) D_004C5510) = 0.0f;
  *((float *) D_004C5514) = 0.5f;
  *((float *) D_004C5518) = 64.0f;
  *v0 = 112.0f;
  *((float *) D_004C5520) = 0.0f;
  *((float *) D_004C551C) = 112.0f;
  v0 = (float *) D_004C5524;
  *v0 = 0.0f;
  *((float *) D_004C5528) = (float) 513;
  *((float *) D_004C552C) = 113.0f;
}
