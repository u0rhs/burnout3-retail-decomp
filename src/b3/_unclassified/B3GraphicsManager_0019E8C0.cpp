// CB3GraphicsManagerBase::SetViewportsSinglePlayer() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3GraphicsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a71: mangled Fv but reads a1 (viewport index) -> extern C with extra int param; arm-1 assignment order b then a fixes delay slot).

class CGtViewport;
struct RwRect {
    int x;
    int y;
    int w;
    int h;
};

class CGtViewport {
public:
    void SetSubRaster(CGtViewport*, RwRect*);
    void SetAspectRatio(float);
};

struct UnkStruct_0019E8C0_vp {
    CGtViewport field_0;
    unsigned char pad_1[0x6F];
    float field_70;
    unsigned char pad_74[0x2C];
};

struct UnkStruct_0019E8C0 {
    int field_0;
    int field_4;
    unsigned char pad_8[0x5];
    unsigned char field_D;
    unsigned char pad_E[0x4A];
    int field_58;
    unsigned char pad_5C[0x34];
    UnkStruct_0019E8C0_vp field_90[2];
    unsigned char pad_1D0[0x140];
    CGtViewport field_310[1];
};

// 0x0019E8C0
extern "C" void SetViewportsSinglePlayer__22CB3GraphicsManagerBaseFv(UnkStruct_0019E8C0 * self, int p0)
{
    RwRect r0;
    r0.x = 0;
    r0.y = 0;
    r0.w = self->field_0;
    r0.h = self->field_4;
    float b;
    float a;
    if (self->field_D != 0) {
        b = 1.7777778f;
        a = 1.2f;
    } else {
        b = 1.3333334f;
        a = 1.0f;
    }
    self->field_90[p0].field_0.SetSubRaster(self->field_310, &r0);
    self->field_90[p0].field_0.SetAspectRatio(b);
    self->field_90[p0].field_70 = a;
    if (p0 == 0) {
        self->field_58 = 0;
    } else {
        self->field_58 = 1;
    }
}
