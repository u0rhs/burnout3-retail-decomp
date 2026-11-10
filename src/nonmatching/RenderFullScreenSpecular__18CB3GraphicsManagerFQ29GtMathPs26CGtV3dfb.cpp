// NONMATCHING: RenderFullScreenSpecular__18CB3GraphicsManagerFQ29GtMathPs26CGtV3dfb -- retail 131 / ours 125 instructions, 112 in changed runs
// ghvu7: logic complete (125/131, 112 changed, frame 0xF0 vs 0x180). Open: retail keeps y0=0/h=0x200/n=20 in s1/s2/s0 across _rwDMAOpenVIFPkt with unfolded dsll 4 / dsll 16 (opt_propagation off unfolds them but breaks the p++ chains); colour kept in s3 (qmfc2/qmtc2) not a stack spill; lane-add order Z,X,Y; 9 dead 16-byte slots; VU numbering colour vf2/scalar vf3/255 vf1. Header gap: operator+(X/Y/ZAxisType,float)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3GraphicsManager::RenderFullScreenSpecular(GtMathPs2::CGtV3d, float, bool) -- hand-written (ghvu7) from the Ghidra
// draft and the sibling RenderPalOrHdtvContrastFilter (B3GraphicsManagerPS2_00227210.cpp). [C] name: the mangled
// symbol in retail's tables. Field names are placeholders and every type is [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_farFogPlane { u_long128 * field_0; };
struct UnkStruct_skyXyoffset_1 { unsigned long field_0; };
extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_skyXyoffset_1 skyXyoffset_1;
extern "C" void _rwDMAOpenVIFPkt(int, int);

// [L] N185: stands in for the missing GtMathPs2 operator +(XAxisType/YAxisType/ZAxisType, float) (B3O0PCH map, 80 bytes each).
static inline XAxisType func_002274B0_inl1(XAxisType a, float f) { u_long128 s, r; asm("qmtc2 %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return XAxisType(r); }
static inline YAxisType func_002274B0_inl2(YAxisType a, float f) { u_long128 s, r; asm("qmtc2 %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return YAxisType(r); }
static inline ZAxisType func_002274B0_inl3(ZAxisType a, float f) { u_long128 s, r; asm("qmtc2 %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.z %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return ZAxisType(r); }

class CB3GraphicsManager {
public:
    void RenderFullScreenSpecular(CGtV3d, float, bool);
};

// 0x002274B0
void CB3GraphicsManager::RenderFullScreenSpecular(CGtV3d colour, float f, bool)
{
    unsigned long y0 = 0;
    unsigned long h = 512;
    unsigned int n = 20;
    CGtV3d c = Min(colour * (127.5f * f), CGtV3d(255.0f, 255.0f, 255.0f));
    _rwDMAOpenVIFPkt(0x80000000, 28);
    unsigned long t0 = ((y0 + h) << 4) << 16;
    unsigned long t1 = (y0 << 4) << 16;
    u_long128 *p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10A3400000000004UL), "r"(14));
    asm("pcpyld %0, %1, %2" : "=r"(*p++) : "r"(24), "r"(0UL));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x31001UL), "r"(71));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(88UL), "r"(66));
    unsigned long b = (unsigned long)(int)(float)func_002274B0_inl3(c.Z(), 0.5f) << 16;
    unsigned long r = (unsigned long)(int)(float)func_002274B0_inl1(c.X(), 0.5f);
    unsigned long g = (unsigned long)(int)(float)func_002274B0_inl2(c.Y(), 0.5f) << 8;
    unsigned long rgb = b | (r | g);
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(rgb), "r"(1));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)n | 0x2400000000000000UL), "r"(85));
    unsigned long lo;
    unsigned int i = 0;
    unsigned long m = 0;
    goto test;
body:
    {
        lo = m | t1;
        m += 512;
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(lo), "r"(m | t0));
    }
    i++;
test:
    if (i < n) goto body;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10A3400000008001UL), "r"(14));
    asm("pcpyld %0, %1, %2" : "=r"(*p++) : "r"(24), "r"(skyXyoffset_1.field_0));
    farFogPlane.field_0 = p;
}
