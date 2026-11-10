// func_0019E760 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (two RwRect locals; CGtViewport field_310[1] member (recomputed address); float b,a declared in that order, per-arm assignment order brute-forced).

// func_0019E760 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtViewport;
struct RwRect {
    int x;
    int y;
    int w;
    int h;
};

class CGtViewport;
struct UnkStruct_0019E760;
struct UnkStruct_0019E760_1;

class CGtViewport {
public:
    void SetSubRaster(CGtViewport*, RwRect*);
    void SetAspectRatio(float);
};

struct UnkStruct_0019E760_1 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
};

struct UnkStruct_0019E760 {
    int field_0;
    int field_4;
    unsigned char pad_8[0x5];
    unsigned char field_D;
    unsigned char pad_E[0x1];
    unsigned char field_F;
    unsigned char pad_10[0x48];
    int field_58;
    unsigned char pad_5C[0x34];
    CGtViewport field_90;
    unsigned char pad_91[0x6F];
    float field_100;
    unsigned char pad_104[0x2C];
    CGtViewport field_130;
    unsigned char pad_131[0x6F];
    float field_1A0;
    unsigned char pad_1A4[0x16C];
    CGtViewport field_310[1];
};

// 0x0019E760
extern "C" void func_0019E760(UnkStruct_0019E760 * self)
{
    RwRect r0;
    RwRect r1;
    float b;
    float a;
    if (self->field_F == 0) {
        r0.x = 0;
        r0.y = 0;
        r0.w = self->field_0;
        r0.h = self->field_4 / 2;
        r1.y = r0.h;
        r1.x = 0;
        r1.w = self->field_0;
        r1.h = self->field_4 - r1.y;
        if (self->field_D != 0) {
            b = 3.5555556f;
            a = 1.62f;
        } else {
            b = 2.6666667f;
            a = 1.35f;
        }
    } else {
        r0.x = 0;
        r0.y = 0;
        r0.w = self->field_0 / 2;
        r0.h = self->field_4;
        r1.x = r0.w;
        r1.y = 0;
        r1.w = self->field_0 - r1.x;
        r1.h = self->field_4;
        if (self->field_D != 0) {
            a = 0.75f;
            b = 0.8888889f;
        } else {
            b = 0.6666667f;
            a = 0.55f;
        }
    }
    self->field_90.SetSubRaster(self->field_310, &r0);
    self->field_90.SetAspectRatio(b);
    self->field_100 = a;
    self->field_130.SetSubRaster(self->field_310, &r1);
    self->field_130.SetAspectRatio(b);
    self->field_1A0 = a;
    self->field_58 = 2;
}
