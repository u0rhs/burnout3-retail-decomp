// CB3DebrisArray::ConstructGeometryData(EDebrisGeometry) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DebrisRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near32: locals declared at the top with the loop counter first (sreg + hand), geometry table extern declared const ([G], lets the field_4 load hoist)).

// near32: [G] the geometry table is read-only (const lets the field_4 load schedule above the saved-register stores); locals declared at the top, the loop counter first, fix the saved-register order.

#include "b3/GtMath.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
enum EDebrisGeometry {};
struct UnkStruct_002F4A20_geom { int field_0; unsigned int field_4; float *field_8; unsigned char *field_C; };
extern "C" const UnkStruct_002F4A20_geom maGeometries__18CB3DebrisArrayBase[];
extern "C" float RwV3dLength(const float *);
extern "C" void SyncDCache(void *, void *);
class CB3EffectsManager { public: static int Alloc(unsigned int, unsigned int); };
class CB3DebrisArray {
public:
    void ConstructGeometryData(EDebrisGeometry);
    unsigned char pad_0[0x10];
    u_long128 *field_10;
    unsigned char pad_14[0xC];
    float field_20;
};
// 0x002F4A20
void CB3DebrisArray::ConstructGeometryData(EDebrisGeometry g)
{
    float l;
    unsigned int i;
    int *src;
    int *dst;
    u_long128 *buf;
    unsigned int size;
    unsigned int n;
    const UnkStruct_002F4A20_geom *e;
    e = &maGeometries__18CB3DebrisArrayBase[g];
    n = e->field_4;
    size = n * 16 + 16;
    buf = (u_long128 *)CB3EffectsManager::Alloc(size, 16);
    u_long128 q;
    asm("pcpyld %0, %2, %1" : "=r"(q) : "r"((((0x30024000UL << 32) | 0x8000UL) | (unsigned long)n)), "r"(0x412UL));
    buf[0] = q;
    dst = (int *)(buf + 1);
    for (i = 0; i < n; i++) {
        src = (int *)((char *)e->field_8 + e->field_C[i] * 12);
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = 0;
        dst += 4;
    }
    field_20 = 0.0f;
    for (int j = 0; j < e->field_0; j++) {
        l = RwV3dLength((float *)((char *)e->field_8 + j * 12));
        field_20 = GtMath::Max(field_20, l);
    }
    SyncDCache(buf, (char *)buf + size - 1);
    field_10 = buf;
}
