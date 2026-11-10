// CB3TrailRenderer::Render(CB3TrailEmitter**,int,CB3TrailParams*,EB3TrailType) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrailRenderPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (texture find via the SOLVED int-record + blk(+0x90)->field_18 idiom (unfolded 0x90/0x18); emit-loop counter declared before the packet pointer (N183 declaration order) fixes the t4/t5 swap).

typedef unsigned int u_long128 __attribute__((mode(TI)));
enum EGtTextureCachePS2_FilterMode {};
class CGtTexture;
class CGtTextureCache {
public:
    unsigned char pad_0[0x10];
    void AccessTexture(CGtTexture *, float, EGtTextureCachePS2_FilterMode, bool, bool);
};
struct UnkStruct_farFogPlane { u_long128 *field_0; };
struct UnkStruct_TR_name { unsigned char pad_0[0x18]; char field_18[1]; };
struct UnkStruct_TR_tex { unsigned char pad_0[0x90]; UnkStruct_TR_name field_90; };
struct UnkStruct_TR_ent { int field_0; int field_4; UnkStruct_TR_tex *field_8; int field_C; };
struct UnkStruct_D_00518688_h;
struct UnkStruct_D_00518688 { unsigned char pad_0[8]; int field_8; UnkStruct_TR_ent *field_C; };
class CB3TrailEmitter { public: unsigned char pad_0[8]; int field_8; unsigned char pad_C[4]; signed char field_10; };
class CB3TrailParams { public: unsigned char pad_0[0x20]; unsigned int field_20; };
struct UnkStruct_D_01E865E0 { unsigned char pad_0[0x30]; };
enum EB3TrailType {};
extern UnkStruct_farFogPlane farFogPlane;
struct UnkStruct_D_00518688_h { UnkStruct_D_00518688 *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00518688_h D_00518688;
extern UnkStruct_D_01E865E0 D_01E865E0[];
extern CGtTextureCache gTextureCache;
extern "C" int strcasecmp(const char *, const char *);
extern "C" void _rwDMAOpenVIFPkt(int, int);
#define PCP(q, lo, hi) asm("pcpyld %0, %2, %1" : "=r"(q) : "r"(lo), "r"(hi))
class CB3TrailRenderer {
public:
    static void Render(CB3TrailEmitter **p0, int p1, CB3TrailParams *p2, EB3TrailType p3);
};
struct UnkStruct_002F3600_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};
static inline UnkStruct_TR_tex *func_002F3600_inl1(UnkStruct_D_00518688 *tb, const char *name)
{
    for (int i = 0; i < tb->field_8; i++) {
        int t2 = (int)tb->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_002F3600_blk *)(t2 + 0x90))->field_18, name) == 0)
            return (UnkStruct_TR_tex *)t2;
    }
    return 0;
}
// 0x002F3600
void CB3TrailRenderer::Render(CB3TrailEmitter **p0, int p1, CB3TrailParams *p2, EB3TrailType p3)
{
    UnkStruct_D_00518688 *tb = D_00518688.field_0;
    UnkStruct_TR_tex *tex = func_002F3600_inl1(tb, (const char *)p2);
    gTextureCache.AccessTexture((CGtTexture *)tex, 0.0f, (EGtTextureCachePS2_FilterMode)1, 0, 0);
    _rwDMAOpenVIFPkt(0, p1 * 3 + 5);
    int i;
    u_long128 *p = farFogPlane.field_0;
    unsigned long k2 = 0x10000000UL;
    unsigned long k3 = 0x30000000UL;
    unsigned long addr = (unsigned long)(unsigned int)&D_01E865E0[(int)p3];
    PCP(*p++, k2, k2);
    PCP(*p++, (addr << 32) | (k3 | 3UL), 0x6C0303F001000101UL);
    PCP(*p++, k2 | 2UL, 0x5000000200000000UL);
    PCP(*p++, 0x8001UL | (k2 << 32), 0xEUL);
    unsigned int col = p2->field_20;
    PCP(*p++, ((unsigned long)(col & 0xFF000000U) << 8) | (col & 0xFFU), 0x42UL);
    for (i = 0; i < p1; i++, p0++) {
        CB3TrailEmitter *e = *p0;
        int s0 = e->field_8 & ~0x30000000;
        signed char b = e->field_10;
        if (b >= 2) {
            PCP(*p++, ((unsigned long)(unsigned int)s0 << 32) | (k3 | 0x10UL), 0x6C10800001000102UL);
            PCP(*p++, ((unsigned long)(unsigned int)(s0 + 0x100) << 32) | (k3 | 3UL), 0x6A10800101000102UL);
            PCP(*p++, k2, ((unsigned long)(unsigned int)(b | 0x04000000) | (0x17000000UL << 32)));
        }
    }
    farFogPlane.field_0 = p;
}
