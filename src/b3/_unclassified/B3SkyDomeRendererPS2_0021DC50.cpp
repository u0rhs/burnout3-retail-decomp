// CB3SkyDomeRenderer::RenderComponent(CB3SkyDomeRendererBase::ESkyComponent) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SkyDomeRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a228: pcpyld packet via *q++ asm outputs, tab loaded late, c1 lo half is 0x10000000 (archive had 0x1000000D)).


typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_D_00665EC0 {
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_00667050 {
    int field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_farFogPlane {
    u_long128 *field_0;
};
struct UnkStruct_maParams {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    u_long128 field_30;
    u_long128 field_40;
    u_long128 field_50;
    u_long128 field_60;
    u_long128 field_70;
    unsigned long field_80;
    unsigned long field_88;
};
class CB3SkyDomeRendererBase {
public:
    enum ESkyComponent { UnkEnum_0 };
};
class CB3SkyDomeRenderer {
public:
    static void RenderComponent(CB3SkyDomeRendererBase::ESkyComponent c);
    static UnkStruct_maParams maParams[7];
};

extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_00667050 D_00667050;
extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x0021DC50
void CB3SkyDomeRenderer::RenderComponent(CB3SkyDomeRendererBase::ESkyComponent c)
{
    UnkStruct_maParams *p = &maParams[c];
    if (*(unsigned long *)((char *)p + 0x78) == 0) {
        return;
    }
    _rwDMAOpenVIFPkt(0, 15);
    u_long128 *q = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(0x1000000DUL), "r"(0x6C0C03EB01000101UL));
    *q++ = p->field_0;
    *q++ = p->field_10;
    *q++ = p->field_20;
    *q++ = p->field_30;
    *q++ = p->field_40;
    *q++ = p->field_50;
    *q++ = p->field_60;
    *q++ = p->field_70;
    char *tab = (char *)&D_00665EC0 + D_00667050.field_0 * 0x230;
    unsigned long lo0 = ((unsigned long)*(u_long128 *)(tab + 0x630) & 0xFFFFFFFFUL) | p->field_80;
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(lo0), "r"(0x4CUL));
    unsigned long lo1 = ((unsigned long)*(u_long128 *)(tab + 0x640) & 0xFFFFFFFEFFFFFFFFUL) | p->field_88;
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(lo1), "r"(0x4EUL));
    *q++ = *(u_long128 *)(tab + 0x650);
    *q++ = *(u_long128 *)(tab + 0x660);
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(0x1500000004000000UL), "r"(0UL));
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(0x10000000UL), "r"(0x1100000011000000UL));
    farFogPlane.field_0 = q;
}
