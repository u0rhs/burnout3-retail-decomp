// B3Im3d::SetAlphaTestThreshold(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Im3DPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (GIF quads (sibling of SetLineAntialiasing): *p++ lo-first pcpyld asm, plain 64-bit literals, (long)(int)(f*128.0f)<<4 | K).

// B3Im3d::SetAlphaTestThreshold(float) -- hand-written (gifq): the lifter refused (dsll).
// [C] name: the mangled symbol in retail's tables (high). Field and struct names are placeholders, types [G].

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_farFogPlane {
    u_long128 * field_0;
};

class B3Im3d {
public:
    static void SetAlphaTestThreshold(float p0);
    static float _grATestThreshold;
};

extern UnkStruct_farFogPlane farFogPlane;

extern "C" void _rwDMAOpenVIFPkt(int, int);





// 0x00365230
void B3Im3d::SetAlphaTestThreshold(float p0)
{
    _grATestThreshold = p0;
    _rwDMAOpenVIFPkt(0, 3);
    u_long128 * p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10000002), "r"(0x5000000211000000));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000000008001), "r"(14));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((long)(int)(_grATestThreshold * 128.0f) << 4) | 0x5000B), "r"(71));
    farFogPlane.field_0 = p;
}
