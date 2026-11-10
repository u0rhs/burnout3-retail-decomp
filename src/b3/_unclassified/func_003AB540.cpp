// func_003AB540 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (dperm (decomp-permuter, background run): float a = func_003AB540_inl1(832.0f, x, f0);; float a = func_003AB540_inl1(832.0f, x, f0);).

struct UnkStruct_003AB540;
struct UnkStruct_003AB540_2;
struct UnkStruct_003AB540_3;
struct UnkStruct_003AB540_e0;
struct UnkStruct_D_01E90240;

struct UnkStruct_003AB540_e0 {
    unsigned char pad_0[0x4];
    UnkStruct_003AB540_2 * field_4;
    unsigned char pad_8[0x8];
};

struct UnkStruct_003AB540_2 {
    float field_0;
    unsigned char pad_4[0x4];
    float field_8;
};

struct UnkStruct_003AB540_3 {
    float field_0;
    float field_4;
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  
};

struct UnkStruct_003AB540 {
    unsigned char pad_0[0xA0];
    UnkStruct_003AB540_e0 field_A0[1];  
    unsigned char pad_B0[0x198];
    int field_248;
    unsigned char pad_24C[0x4];
    unsigned short field_250;
};

extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void func_00372400(void *, void *, UnkStruct_003AB540_3 *, float, float, float, void *);

static inline float func_003AB540_inl1(float a, float b, float t) { float d = b - a; return a + t * d; }
extern "C" void func_003AB540 ( UnkStruct_003AB540 * self , float f0 );







// 0x003AB540
void func_003AB540(UnkStruct_003AB540 *self, float f0)
{
  UnkStruct_003AB540_3 pos;
  UnkStruct_003AB540_3 anchor;
  void *d = &D_01E90240;
  int t0 = self->field_250;
  float y = 144.0f + (33.5f * t0);
  UnkStruct_003AB540_2 *t1 = ((UnkStruct_003AB540_e0 *) ((((char *) self) + (t0 * 16)) + 0xA0))->field_4;
  float v1;
  if (t1 == 0)
  {
    v1 = 640.0f;
  }
  else
  {
    v1 = t1->field_0 + t1->field_8;
  }
  float x = 17.34f + (v1 - 21.0f);
  float a = func_003AB540_inl1(832.0f, x, f0);
  anchor.field_0 = 0.0f;
  anchor.field_4 = 0.5f;
  pos.field_4 = y;
  pos.field_0 = func_003AB540_inl1(-64.0f, 352.0f, f0);
  func_00372400((void *)(self->field_248), &pos, &anchor, 64.0f + (a + (256.0f - x)), 64.0f, a, ((char *) d) + 0x110);
}
