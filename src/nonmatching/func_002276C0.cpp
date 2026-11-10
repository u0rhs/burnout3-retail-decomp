// NONMATCHING: func_002276C0 -- retail 214 / ours 214 instructions, 90 in changed runs
// gif7: packet exact in shape (DMA open n+8, XYOFFSET/TEST/ALPHA table/RGBAQ/GIF tag, 512-wide sprite strip while (--n), A+D tail + cam->field_1E0); colour = Min(*p1 * CGtV4d(127.95,..,128.9), CGtV4d(255.9 x4)) held as u_long128, lanes via CGtV4d(col).X/Y/Z/W(); pos/end declared before the colour (frame order); int n. Left 90: frame 0x200 vs 0x1F0 (retail's operator+ temp 0x20 below end, lane copies at 0xD0-0xF0 vs ours 0xA0-0xC0). 15 pragmas inert
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_002276C0_cam {
    unsigned char pad_0[0x1E0];
    u_long128 field_1E0;
    unsigned char pad_1F0[0x28];
    CGtV2d field_218;
    CGtV2d field_220;
    unsigned char pad_228[0x8];
};
struct UnkStruct_002276C0 {
    unsigned char pad_0[0x470];
    UnkStruct_002276C0_cam field_470[6];
    int field_1190;
};
struct UnkStruct_farFogPlane { u_long128 * field_0; };
extern UnkStruct_farFogPlane farFogPlane;
extern unsigned long D_004B9DF0[];
extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x002276C0
extern "C" void func_002276C0(UnkStruct_002276C0 * p0, const CGtV4d * p1, int p2)
{
    UnkStruct_002276C0_cam * cam = &p0->field_470[p0->field_1190];
    CGtV2d pos = cam->field_220;
    CGtV2d end = pos + cam->field_218;
    u_long128 col = Min(*p1 * CGtV4d(127.95f, 127.95f, 127.95f, 128.9f), CGtV4d(255.9f, 255.9f, 255.9f, 255.9f)).mData;
    pos *= 16.0f;
    end *= 16.0f;
    long x0 = (int)(0.5f + pos.X());
    long y0 = (int)(0.5f + pos.Y());
    long x1 = (int)(0.5f + end.X());
    long y1 = (int)(0.5f + end.Y());
    long x = (x0 + 0x200) & ~0x1FFUL;
    int n = (((x1 + 0x1FF) & ~0x1FFUL) - (x0 & ~0x1FFUL)) >> 9;
    _rwDMAOpenVIFPkt(0x80000000, n + 8);
    u_long128 * p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10A3400000000004UL), "r"(0xE));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0), "r"(0x18));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x33001), "r"(0x47));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(D_004B9DF0[p2]), "r"(0x42));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((long)(int)(float)CGtV4d(col).W() << 24) | (((long)(int)(float)CGtV4d(col).Z() << 16) | ((long)(int)(float)CGtV4d(col).X() | ((long)(int)(float)CGtV4d(col).Y() << 8)))), "r"(1));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)(unsigned int)n | 0x2400000000000000UL), "r"(0x55));
    while (--n != 0) {
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(x0 | (y0 << 16)), "r"(x | (y1 << 16)));
        x0 = x;
        x += 0x200;
    }
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(x0 | (y0 << 16)), "r"(x1 | (y1 << 16)));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10A3400000008001UL), "r"(0xE));
    *p++ = cam->field_1E0;
    farFogPlane.field_0 = p;
}

