// B3Im3d::SetLineAntialiasing(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Im3DPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (GIF quads: *p++ = lo-first pcpyld asm with plain 64-bit literals (the shared 0x10000002/0x1000.. lui is MWCC constant CSE, not source sharing); end pointer stored once after the if/else).

// B3Im3d::SetLineAntialiasing(bool) -- hand-written (gifq): the lifter refused (dsll).
// [C] name: the mangled symbol in retail's tables (high). Field and struct names are placeholders, types [G].

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_farFogPlane {
    u_long128 * field_0;
};

class B3Im3d {
public:
    static void SetLineAntialiasing(bool p0);
    static bool _gbLineAA;
    static float _grATestThreshold;
};

extern UnkStruct_farFogPlane farFogPlane;

extern "C" void _rwDMAOpenVIFPkt(int, int);



// 0x00365370
void B3Im3d::SetLineAntialiasing(bool p0)
{
    _gbLineAA = p0;
    _rwDMAOpenVIFPkt(0, 3);
    u_long128 * p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10000002), "r"(0x5000000211000000));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000000008001), "r"(14));
    if (p0) {
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x5100A), "r"(71));
    } else {
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((long)(int)(_grATestThreshold * 128.0f) << 4) | 0x5000B), "r"(71));
    }
    farFogPlane.field_0 = p;
}
