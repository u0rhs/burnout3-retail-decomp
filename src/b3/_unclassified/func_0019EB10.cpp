// Destruct__22CB3GraphicsManagerBaseFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3VehicleRenderer;
class CGtViewport;
struct UnkStruct_0019EB10;
struct UnkStruct_D_01E32A10;

class CB3VehicleRenderer {
public:
    void Destruct();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtViewport {
public:
    void Destruct();
};

struct UnkStruct_D_01E32A10 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0019EB10 {
    unsigned char pad_0[0x90];
    CGtViewport field_90;
    unsigned char pad_91[0x9F];
    CGtViewport field_130;
    unsigned char pad_131[0x1DF];
    CGtViewport field_310;
};

extern CB3VehicleRenderer gVehicleRenderer;
extern UnkStruct_D_01E32A10 D_01E32A10;

extern "C" void Destruct__16CB3TrackRendererFv(void *);  // CB3TrackRenderer::Destruct()

// 0x0019EB10
extern "C" void Destruct__22CB3GraphicsManagerBaseFv(UnkStruct_0019EB10 * self)
{
    gVehicleRenderer.Destruct();
    Destruct__16CB3TrackRendererFv(&D_01E32A10);
    self->field_90.Destruct();
    self->field_130.Destruct();
    self->field_310.Destruct();
}
