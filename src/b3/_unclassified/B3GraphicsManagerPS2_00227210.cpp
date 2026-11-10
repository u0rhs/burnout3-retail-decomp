// CB3GraphicsManager::RenderPalOrHdtvContrastFilter() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3GraphicsManagerPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (*p++ GIF asm, operand order = creation order, lo/i/m decl order).

// CB3GraphicsManager::RenderPalOrHdtvContrastFilter() -- hand-matched (gif3).
// [C] name: the mangled symbol in retail's tables (high). Area not evidenced, so _unclassified/ (docs/conventions.md).
// Field names are placeholders and every type is [G] (instruction widths).
// GIF quads (N175): pcpyld asm straight into *p++; operand order = input creation order (q1 and the loaded
// skyXyoffset_1 quad hi-first, retail materialises the register number first); the 20-quad loop is the N24
// entry-jump goto form with `lo, i, m` declared in that order (sets the a2/a3/t0 loop registers).
typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_farFogPlane { u_long128 * field_0; };
struct UnkStruct_skyXyoffset_1 { unsigned long field_0; };
class CB3GraphicsManager {
public:
    void RenderPalOrHdtvContrastFilter();
};
extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_skyXyoffset_1 skyXyoffset_1;
extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x00227210
void CB3GraphicsManager::RenderPalOrHdtvContrastFilter()
{
    _rwDMAOpenVIFPkt(0x80000000, 30);
    u_long128 *p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10A3400000000004UL), "r"(14));
    asm("pcpyld %0, %1, %2" : "=r"(*p++) : "r"(24), "r"(0UL));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x31001UL), "r"(71));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(129UL), "r"(66));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x8D030303UL), "r"(1));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x2400000000000014UL), "r"(85));
    unsigned long lo;
    unsigned int i = 0;
    unsigned long m = 0;
    goto test;
body:
    {
        lo = m;
        m += 512;
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(lo), "r"(m | 0x20000000UL));
    }
    i++;
test:
    if (i < 20) goto body;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10A3400000008003UL), "r"(14));
    asm("pcpyld %0, %1, %2" : "=r"(*p++) : "r"(24), "r"(skyXyoffset_1.field_0));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x3000DUL), "r"(71));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x8000000044UL), "r"(66));
    farFogPlane.field_0 = p;
}
