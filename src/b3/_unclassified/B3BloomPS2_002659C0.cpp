// CB3Bloom::Render(bool,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BloomPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): int new_var;; int fp = (int) ((skyFrame_1.field_0 >> 16) & 0x3F);; new_var = 0x3F;; int fp = (int) ((skyFrame_1.field_0 >> 16) & new_var);; unsigned int s5 = ((w >> 1) + 0x3F) >> 6;; unsigned int s5 = ((w >> 1) + new_var) >> 6;; t += (q * 8) + 1;; new_var = q;; t += (new_var * 8) + 1;; t += (q * 2) ).

typedef unsigned int u_long128 __attribute__((mode(TI)));
class CB3Bloom;
struct UnkStruct_skyFrame_1 { long field_0; };
struct UnkStruct_skyZbuf_1 { long field_0; };
struct UnkStruct_Bloom_cfg { char pad_0[0xC]; unsigned int field_C; unsigned int field_10; char pad_14[8]; short field_1C; short field_1E; };
struct UnkStruct_ourGlobals { char pad_0[0x60]; UnkStruct_Bloom_cfg *field_60; };
struct UnkStruct_ourGlobalsP { UnkStruct_ourGlobals *field_0; char pad_4[0xC]; };
struct UnkStruct_D_00665F28 { unsigned char field_0; char pad_1[0xF]; };
extern UnkStruct_skyFrame_1 skyFrame_1;
extern UnkStruct_skyZbuf_1 skyZbuf_1;
extern UnkStruct_ourGlobalsP ourGlobals;
extern UnkStruct_D_00665F28 D_00665F28;
extern "C" void _rwDMAOpenVIFPkt(int, int);
class CB3Bloom {
public:
    void Render(bool p0, bool p1);
    void SetRenderstates();
    void FirstDownsample(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    void SecondDownsample(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    void Blur(unsigned int, unsigned int, unsigned int, unsigned int);
    void Blend(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, bool, bool);
    void CopyToScreen(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    void RestoreRenderstates(unsigned long);
};





// 0x002659C0
void CB3Bloom::Render(bool p0, bool p1)
{
  int v0;
  if (D_00665F28.field_0 == 0)
  {
    return;
  }
  UnkStruct_Bloom_cfg *c = ourGlobals.field_0->field_60;
  int s7 = (int) (skyFrame_1.field_0 & 0x1FF);
  v0 = 0x3F;
  int fp = (int) ((skyFrame_1.field_0 >> 16) & v0);
  int zb = (int) (skyZbuf_1.field_0 & 0x1FF);
  unsigned int w = c->field_C;
  unsigned int h = c->field_10;
  int x = c->field_1C;
  int y = c->field_1E;
  unsigned int s6 = zb + (((h + 0x1F) >> 5) << 1);
  unsigned int s5 = ((w >> 1) + v0) >> 6;
  unsigned int q = ((w >> 2) + 0x1F) >> 5;
  int t = 5;
  t += 0x12;
  t += 11 * (w >> 6);
  t += 8;
  t += (s5 * 2) + 1;
  t += 5;
  v0 = q;
  t += (v0 * 8) + 1;
  t += 7;
  t += (v0 * 2) + 1;
  t += 8;
  t += ((w >> 5) * 2) + 1;
  _rwDMAOpenVIFPkt(0x80000000, t + 9);
  SetRenderstates();
  FirstDownsample(w, h, x, y, s7, fp, zb, s6, s5);
  SecondDownsample(w, h, s6, s5, s6, s5);
  Blur(w, h, s6, s5);
  Blend(w, h, x, y, s6, s5, p0, p1);
  CopyToScreen(w, h, x, y, s6, s5, s7, fp);
  RestoreRenderstates(((((unsigned long) ((unsigned int) x)) | (((unsigned long) ((unsigned int) ((x + w) - 1))) << 16)) | (((unsigned long) ((unsigned int) y)) << 32)) | (((unsigned long) ((unsigned int) ((y + h) - 1))) << 48));
}
