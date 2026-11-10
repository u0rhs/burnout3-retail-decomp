// CB3Fog::Render(GtMathPs2::CGtV3d,float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3FogPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (pass2e: h's int conversion reuses variable a after a's last use (a = (int)hf), the four camera floats held as float locals and converted after the &0x1FF masks in order s2, a, s0, s6).

// near33: 51->10. s-regs exact via decl order s7..s0 then h,a,b,q,cd; b & 0x1FF computed before the /32 branch (s5 = a&0x1FF; s5 += s4*q). Left: temp regs only -- retail h in a0 (ours a2), a&0x1FF in a2 (ours a1), b&0x1FF in a1 (ours a0), andi a2 scheduled before sra s4

// a120: 127=127 instrs, logic/layout right (early return, RenderIndexedFog via const void* mangled extern so one stack copy, cam+0x470 hoisted); only s-register assignment and lq/narrowing schedule differ (retail loads both quads first, keeps cam in a1, s5/s4/s3/s2/s1/s0 follow ZGreen arg order); 60 decl-order shuffles failed

#include "b3/GtMathPs2.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
class CB3CameraData;
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_00665F29 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_00667050 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_00665F29 D_00665F29;
extern UnkStruct_D_00667050 D_00667050;
extern "C" void RenderIndexedFog__6CB3FogFQ29GtMathPs26CGtV3dUiUiUiUiUiUiUi(const void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
class CB3Fog {
public:
    static void SetRenderstates();
    static void ZGreen2FBAlpha(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    static void GenerateClut(float, float);
    static void RestoreRenderstates(const CB3CameraData *);
    static void Render(GtMathPs2::CGtV3d p0, float p1, float p2);
};
// 0x002419C0
void CB3Fog::Render(GtMathPs2::CGtV3d p0, float p1, float p2)
{
    GtMathPs2::CGtV3d v = p0;
    if (D_00665F29.field_0 == 0) return;
    {
        char * cam = (char *)&D_00665EC0 + D_00667050.field_0 * 0x230;
        int s7;
        int s6;
        int s5;
        int s4;
        int s3;
        int s2;
        int s1;
        int s0;
        int a;
        int b;
        int q;
        const CB3CameraData * cd;
        float s2f = *(float *)(cam + 0x690);
        b = (int)*(u_long128 *)(cam + 0x640);
        float hf = *(float *)(cam + 0x694);
        float s0f = *(float *)(cam + 0x688);
        cd = (const CB3CameraData *)(cam + 0x470);
        float s6f = *(float *)(cam + 0x68C);
        a = (int)*(u_long128 *)(cam + 0x630);
        s4 = (a & 0x3F0000) >> 16;
        s5 = a & 0x1FF;
        s3 = b & 0x1FF;
        s2 = (int)s2f;
        a = (int)hf;
        s0 = (int)s0f;
        s6 = (int)s6f;
        q = a / 32;
        s5 += s4 * q;
        s3 += s4 * q;
        s1 = a - q * 32;
        SetRenderstates();
        s7 = s1 + s6;
        if (s7 >= 0x200) {
            ZGreen2FBAlpha(s5, s4, s3, s2, s1, s0, 0x1E0 - s1);
            ZGreen2FBAlpha(s5 + s4 * 15, s4, s3 + s4 * 15, s2, 0, s0, s7 - 0x1E0);
        } else {
            ZGreen2FBAlpha(s5, s4, s3, s2, s1, s0, s6);
        }
        GenerateClut(p1, p2);
        RenderIndexedFog__6CB3FogFQ29GtMathPs26CGtV3dUiUiUiUiUiUiUi(&v, s2, s1, s0, s6, s5, s4, s3);
        RestoreRenderstates(cd);
    }
}
