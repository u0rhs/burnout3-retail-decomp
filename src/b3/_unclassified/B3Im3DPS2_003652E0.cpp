// B3Im3d::SetBlendMode(B3Im3d::EBlendMode) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Im3DPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (gif4: N218 *p++ form, corrected q1 lo constant, third quad in its own block (switch case+default) [G]).

// B3Im3d::SetBlendMode(EBlendMode) -- [C] name: the mangled symbol in retail's tables. GIF packet in the N218 form
// (gif4): every constant half read off retail's lui/ori/dsll32 chain (q1 lo is 0x1000000000008001: dsll32 of the
// raw lui, as in SetLineAntialiasing). Area not evidenced; types [G].

typedef unsigned int u_long128 __attribute__((mode(TI)));
class B3Im3d;
struct UnkStruct_farFogPlane {
    u_long128 * field_0;
};
class B3Im3d {
public:
    enum EBlendMode { BM_0, BM_1, BM_2, BM_3 };
    static void SetAlphaTestThreshold(float p0);
    static void SetBlendMode(EBlendMode p0);
    static void SetLineAntialiasing(bool p0);
    static EBlendMode _geBlendMode;
    static float _grATestThreshold;
    static unsigned char _gbLineAA;
};
extern UnkStruct_farFogPlane farFogPlane;
extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x003652E0
void B3Im3d::SetBlendMode(B3Im3d::EBlendMode p0)
{
    B3Im3d::_geBlendMode = p0;
    _rwDMAOpenVIFPkt(0, 3);
    u_long128 *p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10000002UL), "r"(0x5000000211000000UL));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000000008001UL), "r"(14UL));
    // [G] retail schedules the third quad's constants after the first two stores: the quad sits in its own block
    // (gif4). SetLineAntialiasing's identical head is followed by an if/else; here a switch on the mode whose case
    // labels all share one body leaves the same block boundary and no compare (a bare `default:` does not).
    switch (p0) {
    case 0:
    default:
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x8000000044UL), "r"(0x42UL));
        break;
    }
    farFogPlane.field_0 = p;
}
