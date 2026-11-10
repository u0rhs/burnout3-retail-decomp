// CB3EffectsManager::RenderPostFogEffects(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EffectsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (fresh4: from scratch; byte-offset player base CSE, -v temp to const CGtV3d& param, u_long128 colour copy, padded globals).

// CB3EffectsManager::RenderPostFogEffects(int) -- hand-written from scratch (the lifter refused it).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3EffectsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G]
// (instruction widths); array strides from retail's index arithmetic.

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV3d;
using GtMathPs2::CGtV4d;

class CB3PopcornArray { public: unsigned char pad_0[0x40]; };
class CB3ParticleArray { public: unsigned char pad_0[0x150]; };
class CB3SparkArray { public: unsigned char pad_0[0xA8]; };
class CB3CoronaDynamicArray { public: unsigned char pad_0[0x34]; };
class CGtTexture;

struct UnkStruct_00261E00_e0 { unsigned char pad_0[0x1CBA]; unsigned char field_1CBA; unsigned char pad_1CBB[0xB15]; };
struct UnkStruct_00261E00_e1 { unsigned char pad_0[0x3534]; float field_3534; };
struct UnkStruct_00261E00_pl { unsigned char pad_0[0x12C63A]; unsigned char field_12C63A; unsigned char pad_12C63B[0xB45]; UnkStruct_00261E00_e1 *field_12D180; };
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12A980];
    UnkStruct_00261E00_e0 field_12A980[1];  // [G] element count unknown
};
struct UnkStruct_00261E00_e3 { unsigned long field_0; unsigned char pad_8[0xBA8]; };
struct UnkStruct_00261E00_e4 { CGtV3d field_0; unsigned char pad_10[0x30]; };
struct UnkStruct_D_01E85900 { unsigned char pad_0[0xB0]; UnkStruct_00261E00_e4 field_B0[1]; };
struct UnkStruct_D_00665F2C { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_00665EA1 { unsigned char field_0; unsigned char pad_1[0xF]; };

class CB3EffectsManager {
public:
    void RenderPostFogEffects(int p0);

    unsigned char pad_0[0xC];
    CB3CoronaDynamicArray field_C[3];
    unsigned char pad_A8[0xC8];
    CB3ParticleArray field_170[24];
    CB3PopcornArray field_20F0[4];
    CB3SparkArray field_21F0[6];
    unsigned char pad_25E0[0x1D220];
    CGtV4d field_1F800;
    unsigned char pad_1F810[0x20];
    CGtTexture *field_1F830[3];
    unsigned char pad_1F83C[0xC];
    float field_1F848;
};

extern UnkStruct_D_00665F2C D_00665F2C;
extern UnkStruct_D_00665EA1 D_00665EA1;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_00261E00_e3 D_005179C0[];
extern UnkStruct_D_01E85900 D_01E85900;
struct UnkStruct_D_01E85A30 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E85A30 D_01E85A30;
struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522680 D_00522680;
extern unsigned char D_01EA4BB0[];
extern unsigned char D_00665EC0[];

extern "C" void BeginRender__18CB3PopcornRendererFv();
extern "C" void RenderPopcornArray__18CB3PopcornRendererFP15CB3PopcornArray(CB3PopcornArray *);
extern "C" void EndRender__18CB3PopcornRendererFv();
extern "C" void BeginRender__19CB3ParticleRendererFb(unsigned char, bool);
extern "C" void SetLighting__16CB3ParticleArrayFQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV3d(CB3ParticleArray *, const void *, const CGtV3d &);
extern "C" void RenderParticleArray__19CB3ParticleRendererFP16CB3ParticleArray(CB3ParticleArray *);
extern "C" void EndRender__19CB3ParticleRendererFv();
extern "C" void Construct__17CB3CoronaRendererFv(int, float);
extern "C" void RenderDynamicArray__17CB3CoronaRendererFP21CB3CoronaDynamicArrayP10CGtTexture(CB3CoronaDynamicArray *, CGtTexture *);
extern "C" void EndRender__17CB3CoronaRendererFv();
extern "C" void BeginRender__16CB3SparkRendererFib(int, unsigned char);
extern "C" void RenderSparkArray__16CB3SparkRendererFP13CB3SparkArray(CB3SparkArray *);
extern "C" void EndRender__16CB3SparkRendererFv();
extern "C" void RenderFullScreenFlash__19CB3ExplosionManagerFf(void *, float);
extern "C" void func_002276C0(void *, void *, int);
extern "C" void func_00255C90(CB3EffectsManager *);

// 0x00261E00
void CB3EffectsManager::RenderPostFogEffects(int p0)
{
    if (D_00665F2C.field_0 == 0) {
        return;
    }
    unsigned char crash = ((UnkStruct_00261E00_pl *)((char *)&D_00522660 + p0 * 0x27D0))->field_12C63A;
    bool f10 = (D_005179C0[p0].field_0 & 0x10) != 0;
    int i;
    if (crash != 0) {
        BeginRender__18CB3PopcornRendererFv();
        for (i = 0; i < 4; i++) {
            RenderPopcornArray__18CB3PopcornRendererFP15CB3PopcornArray(&field_20F0[i]);
        }
        EndRender__18CB3PopcornRendererFv();
    }
    BeginRender__19CB3ParticleRendererFb(crash, f10);
    for (i = 0; i < 24; i++) {
        SetLighting__16CB3ParticleArrayFQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV3d(&field_170[i], &field_1F800, -D_01E85900.field_B0[D_01E85A30.field_0].field_0);
        RenderParticleArray__19CB3ParticleRendererFP16CB3ParticleArray(&field_170[i]);
    }
    EndRender__19CB3ParticleRendererFv();
    Construct__17CB3CoronaRendererFv(p0, field_1F848);
    for (i = 0; i < 3; i++) {
        RenderDynamicArray__17CB3CoronaRendererFP21CB3CoronaDynamicArrayP10CGtTexture(&field_C[i], field_1F830[i]);
    }
    EndRender__17CB3CoronaRendererFv();
    BeginRender__16CB3SparkRendererFib(p0, crash);
    for (i = 0; i < 6; i++) {
        RenderSparkArray__16CB3SparkRendererFP13CB3SparkArray(&field_21F0[i]);
    }
    EndRender__16CB3SparkRendererFv();
    if (crash != 0 && (D_005179C0[p0].field_0 & 0x2000) == 0) {
        UnkStruct_00261E00_e1 *c = ((UnkStruct_00261E00_pl *)((char *)&D_00522660 + p0 * 0x27D0))->field_12D180;
        float t = c->field_3534;
        if (t > 0.0f) {
            RenderFullScreenFlash__19CB3ExplosionManagerFf(D_01EA4BB0, D_00522680.field_0 - t);
        }
    }
    if (D_00665EA1.field_0 != 0) {
        CGtV4d c(0.0f, 0.0f, 1.0f, 0.1f);
        u_long128 copy = *(u_long128 *)&c;
        func_002276C0(D_00665EC0, &copy, 1);
    }
    func_00255C90(this);
}
