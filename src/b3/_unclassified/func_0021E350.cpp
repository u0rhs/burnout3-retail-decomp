// Hand-written; the lifter refused it (a79: pcpyld asm halves, 4 maParams[].field_70 stores + backdrop frame).

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_0021E100_hp {
    unsigned char pad_0[0x70];
    u_long128 field_70;
    unsigned char pad_80[0x10];
};
struct UnkStruct_D_006662D4 {
    unsigned int field_0;
    unsigned char pad_4[0xC];
};
class CB3SkyDomeRenderer {
public:
    static UnkStruct_0021E100_hp maParams[6];
    static u_long128 mu128BackdropFrame_1;
};
extern UnkStruct_D_006662D4 D_006662D4;
// 0x0021E350
extern "C" void func_0021E350()
{
    unsigned long t3 = D_006662D4.field_0;
    unsigned long lo = t3 | 0x558004000UL;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(lo), "r"(6));
    CB3SkyDomeRenderer::maParams[0].field_70 = q0;
    CB3SkyDomeRenderer::maParams[1].field_70 = q0;
    CB3SkyDomeRenderer::maParams[3].field_70 = q0;
    CB3SkyDomeRenderer::maParams[4].field_70 = q0;
    unsigned long lo2 = (t3 >> 5) | 0x10000UL;
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(lo2), "r"(0x4C));
    CB3SkyDomeRenderer::mu128BackdropFrame_1 = q1;
}
