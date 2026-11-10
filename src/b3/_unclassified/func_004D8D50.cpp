// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): float *new_var4;; float *new_var3;; float new_var;; float *new_var2;; *((float *) D_004C7174) = 328.0f;; *((float *) D_004C7174) = (0, 328.0f);; *((float *) D_004C717C) = 0.5f;; *((float *) D_004C7180) = 64.0f;; *((float *) D_004C7188) = 0.0f;; new_var3 = (float *) D_004C7180;; new_var2 = new_var3;;).

extern unsigned char D_004C7170[];
extern unsigned char D_004C7174[];
extern unsigned char D_004C7178[];
extern unsigned char D_004C717C[];
extern unsigned char D_004C7180[];
extern unsigned char D_004C7184[];
extern unsigned char D_004C7188[];
extern unsigned char D_004C718C[];
extern unsigned char D_004C7190[];
extern unsigned char D_004C7194[];
extern "C" void func_004D8D50 ( );

// 0x004D8D50
void func_004D8D50()
{
  float *v4;
  float *v3;
  float v0;
  float *v2;
  *((float *) D_004C7170) = 320.0f;
  *((float *) D_004C7174) = (0, 328.0f);
  *((float *) D_004C7178) = 0.5f;
  v3 = (float *) D_004C7180;
  v2 = v3;
  v4 = (float *) D_004C717C;
  *v4 = 0.5f;
  *v2 = 64.0f;
  v0 = 0.0f;
  *((float *) D_004C7184) = 304.0f;
  *((float *) D_004C7188) = v0;
  D_004C7184 = D_004C7184;
  *((float *) D_004C7184) = 304.0f;
  *((float *) D_004C718C) = 0.0f;
  *((float *) D_004C7190) = (float) 513;
  *((float *) D_004C7194) = 49.0f;
}
