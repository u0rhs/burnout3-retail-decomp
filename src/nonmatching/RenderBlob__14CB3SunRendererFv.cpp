// NONMATCHING: RenderBlob__14CB3SunRendererFv -- retail 199 / ours 199 instructions, 82 in changed runs
// gif7: packet part near-exact (q0 local before the farFogPlane load, cam->field_1C0 | FBMSK, D_01D9B950 copy, RGBAQ from CGtV4d X/Y/Z lanes); left 82, mostly frame-slot offsets: retail's CGtV2d temps sit 8 bytes lower (an extra 8-byte slot between the named result and the operator temps, and an 8-byte-smaller colour-temp region), the unfolded +0x470/+0x1C0 camera address, Q8 zero register. Inert/worse: single-expression position, named radius CGtV2d (frame grows), colour forms, z zero locals, 15 pragmas
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_0024D0E0_cam { unsigned char pad_0[0x1C0]; u_long128 field_1C0; unsigned char pad_1D0[0x60]; };
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x470]; UnkStruct_0024D0E0_cam field_470[1]; };
struct UnkStruct_D_00667050 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_farFogPlane { u_long128 * field_0; };
extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_00667050 D_00667050;
extern UnkStruct_farFogPlane farFogPlane;
extern u_long128 D_01D9B950;
extern CGtV4d D_01D9B960;
extern "C" void _rwDMAOpenVIFPkt(int, int);

class CB3SunRenderer {
public:
    static unsigned char mbBehind;
    static CGtV2d mSunPos;
    static CGtV2d mScreenSize;
    static int mnScreenSizeX;
    static int mnScreenSizeY;
    static int mnGSOffsetX;
    static int mnGSOffsetY;
    static float mrAspectRatio;
    static float mrBlobRadius;
    static void RenderBlob();
};

// 0x0024CDF0
void CB3SunRenderer::RenderBlob()
{
    const u_long128 * cp = &D_00665EC0.field_470[D_00667050.field_0].field_1C0;
    if (mbBehind) return;
    CGtV2d a = mSunPos * mScreenSize;
    CGtV2d b = a * 16.0f;
    float r = 16.0f * mrBlobRadius;
    int rx = (int)r;
    int ry = (int)(r * mrAspectRatio);
    int x = (int)b.X();
    int y = (int)b.Y();
    int x0 = x - rx;
    int x1 = x + rx;
    int y0 = y - ry;
    int y1 = y + ry;
    if (x1 <= 0 || x0 >= mnScreenSizeX << 4 || y1 <= 0 || y0 >= mnScreenSizeY << 4) return;
    CGtV4d col = D_01D9B960;
    int cr = (int)(float)col.X();
    int cg = (int)(float)col.Y();
    float cb = col.Z();
    _rwDMAOpenVIFPkt(0x80000000, 0xC);
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x10AB40000000800BUL), "r"(0xE));
    u_long128 * p = farFogPlane.field_0;
    *p++ = q0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x31001), "r"(0x47));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x44), "r"(0x42));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)*cp | 0xFF00000000000000UL), "r"(0x4C));
    *p++ = D_01D9B950;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x61), "r"(0x14));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(5), "r"(8));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((long)(int)cb << 16) | ((long)cg << 8 | (long)cr) | 0x3F80000080000000UL), "r"(1));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0), "r"(3));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((long)(x0 + mnGSOffsetX) | ((long)(y0 + mnGSOffsetY) << 16) | 0x00FFFFFF00000000UL), "r"(5));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x02000200), "r"(3));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((long)(x1 + mnGSOffsetX) | ((long)(y1 + mnGSOffsetY) << 16) | 0x00FFFFFF00000000UL), "r"(5));
    farFogPlane.field_0 = p;
}
