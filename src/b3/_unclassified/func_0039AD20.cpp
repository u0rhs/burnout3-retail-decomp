// func_0039AD20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3ExplosionManager;

class CB3ExplosionManager {
public:
    void UpdateExplosionTrails(float);
};

struct UnkStruct_0039AD20_pad {
    unsigned char field_0[0x4];
    UnkStruct_0039AD20_pad() {}
    ~UnkStruct_0039AD20_pad() {}
};

// 0x0039AD20
extern "C" void func_0039AD20(CB3ExplosionManager * self, float f0)
{
    UnkStruct_0039AD20_pad pad;  // [G] an unused local object: retail's frame keeps 0x10 unused bytes at its top (a scoped object with a constructor/destructor reserves its slot, known.md N140)
    self->UpdateExplosionTrails(f0);
}
