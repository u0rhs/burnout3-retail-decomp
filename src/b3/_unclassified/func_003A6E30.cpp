// func_003A6E30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtTexture;

class Gt2dRenderer;
struct UnkStruct_D_01EA46B4;

class Gt2dRenderer {
public:
    void SetTexture(CGtTexture*);
};

struct UnkStruct_D_01EA46B4 {
    Gt2dRenderer * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01EA46B4 D_01EA46B4;

extern "C" void func_003A6CC0(void *, void *);

// 0x003A6E30
extern "C" void func_003A6E30(int n0, int p0)
{
    D_01EA46B4.field_0->SetTexture((CGtTexture*)p0);
    func_003A6CC0((void *)(n0), (void *)(p0));
}
