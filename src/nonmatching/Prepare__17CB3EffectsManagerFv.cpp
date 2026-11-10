// NONMATCHING: Prepare__17CB3EffectsManagerFv -- retail 259 / ours 260 instructions, 8 in changed runs
// 8 instrs: retail keeps two lui 2 for the field_1F848/1F854 stores (ours shares one via move) and reads Y() lane as lwc1 0xA4(sp) (ours addiu v1,sp,164); 2 N140 pads for frame 0x110
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3EffectsManager::Prepare() -- hand-written (fresh6). [C] name: the mangled symbol.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using GtMathPs2::CGtV4d;

struct UnkStruct_00262770_pad { int x[4]; UnkStruct_00262770_pad() {} ~UnkStruct_00262770_pad() {} };
class CGtTexture;
class CB3CoronaDynamicArray { public: void Prepare(); unsigned char pad_0[0x34]; };
class CB3DebrisArray { public: void Prepare(); unsigned char pad_0[0x30]; };
class CB3ParticleArray { public: void Prepare(); unsigned char pad_0[0x150]; };
class CB3PopcornArray { public: void Prepare(); unsigned char pad_0[0x40]; };
class CB3SparkArray { public: void Prepare(); unsigned char pad_0[0xA8]; };
class CB3SparkRenderer { public: static void Prepare(); };
class CB3ScrapeSystem { public: void Prepare(); unsigned char pad_0[0x10]; };
struct UnkStruct_00262770_2600 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01EA4BB0 { unsigned char pad_0[0x10]; };
struct UnkStruct_00262770_cp { int field_0; const char *field_4; };
struct UnkStruct_00262770_e0 { unsigned char pad_0[0x8]; int field_8; unsigned char pad_C[0x4]; };
struct UnkStruct_00262770_4 { unsigned char pad_0[0x8]; int field_8; UnkStruct_00262770_e0 *field_C; };
struct UnkStruct_D_00518688 { UnkStruct_00262770_4 *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00262770_blk { unsigned char pad_0[0x18]; char field_18[8]; };
struct UnkStruct_D_01E85960 { CGtV4d field_0; };

extern int _gnPerfMonEffectsManagerUpdate;
extern int _gnPerfMonEffectsManagerSoundUpdate;
extern int _gnPerfMonEffectsManagerRender;
extern int D_004E199C;
extern int D_004E19A0;
extern int D_004E19A8;
extern int D_004E19A4;
extern int D_004E1988;
extern int _gnPerfMonSpawnPopcorn;
extern int _gnPerfMonSpawnDebris;
extern UnkStruct_D_01E85960 D_01E85960;
extern UnkStruct_00262770_cp _gaCoronaParams[];
extern UnkStruct_D_00518688 D_00518688;
extern UnkStruct_D_01EA4BB0 D_01EA4BB0;

extern "C" int strcasecmp(const char *, const void *);
extern "C" int func_002BD7F0(void *);
extern "C" int func_0039AD50(void *);

class CB3EffectsManager {
public:
    int Prepare();
    unsigned char pad_0[0xC];
    CB3CoronaDynamicArray field_C[3];
    unsigned char pad_A8[0x8];
    CB3DebrisArray field_B0[4];
    CB3ParticleArray field_170[24];
    CB3PopcornArray field_20F0[4];
    CB3SparkArray field_21F0[6];
    unsigned char pad_25E0[0x20];
    UnkStruct_00262770_2600 field_2600;
    unsigned char pad_2610[0x16C80 - 0x2610];
    CB3ScrapeSystem field_16C80;
    unsigned char pad_16C90[0x1F800 - 0x16C90];
    CGtV4d field_1F800;
    unsigned char pad_1F810[0x18];
    int field_1F828;
    int field_1F82C;
    CGtTexture *field_1F830[3];
    unsigned char pad_1F83C[0xC];
    int field_1F848;
    unsigned char pad_1F84C[0x8];
    int field_1F854;
};

// 0x00262770
int CB3EffectsManager::Prepare()
{
    if (_gnPerfMonEffectsManagerUpdate == -1) _gnPerfMonEffectsManagerUpdate = 0;
    if (_gnPerfMonEffectsManagerSoundUpdate == -1) _gnPerfMonEffectsManagerSoundUpdate = 0;
    if (_gnPerfMonEffectsManagerRender == -1) _gnPerfMonEffectsManagerRender = 0;
    if (D_004E199C == -1) D_004E199C = 0;
    if (D_004E19A0 == -1) D_004E19A0 = 0;
    if (D_004E19A8 == -1) D_004E19A8 = 0;
    if (D_004E19A4 == -1) D_004E19A4 = 0;
    if (D_004E1988 == -1) D_004E1988 = 0;
    if (_gnPerfMonSpawnPopcorn == -1) _gnPerfMonSpawnPopcorn = 0;
    if (_gnPerfMonSpawnDebris == -1) _gnPerfMonSpawnDebris = 0;
    field_1F848 = 0;
    field_1F854 = 0;
    {
        UnkStruct_00262770_pad p1, p2;
        float zr = 0.0f;
        CGtV4d c = D_01E85960.field_0;
        float x = c.X();
        float y = c.Y();
        float z = c.Z();
        float s = x + y + z;
        if (s <= 0.001000000047f) {
            field_1F800 = CGtV4d(zr, zr, zr, 1.0f);
        } else {
            float r = (x + s) * 0.25f;
            float g = (y + s) * 0.25f;
            float b = (z + s) * 0.25f;
            float m = GtMath::Max(GtMath::Max(r, g), b);
            field_1F800 = CGtV4d(r, g, b, 1.0f);
            {
                u_long128 t;
                asm("qmtc2.ni %1, %0" : "=j"(t) : "r"(1.0f / m));
                asm("vmulx.xyzw %0, %0, %1x" : "+j"(field_1F800.mData) : "j"(t));
            }
            field_1F800.SetA(1.0f);
        }
    }
    for (int i = 0; i < 3; i++) {
        field_C[i].Prepare();
        int t2;
        const char *name;
        int j;
        UnkStruct_00262770_4 *t0;
        name = _gaCoronaParams[i].field_4;
        t0 = D_00518688.field_0;
        for (j = 0; j < t0->field_8; j++) {
            t2 = t0->field_C[j].field_8;
            if (strcasecmp(((UnkStruct_00262770_blk *)(t2 + 0x90))->field_18, name) == 0) goto found;
        }
        t2 = 0;
    found:
        field_1F830[i] = (CGtTexture *)t2;
    }
    for (int i = 0; i < 4; i++) field_B0[i].Prepare();
    for (int i = 0; i < 24; i++) field_170[i].Prepare();
    for (int i = 0; i < 4; i++) field_20F0[i].Prepare();
    CB3SparkRenderer::Prepare();
    for (int i = 0; i < 6; i++) field_21F0[i].Prepare();
    func_002BD7F0(&field_2600);
    field_16C80.Prepare();
    field_1F82C = 0x2B9D6F8;
    field_1F828 = 0xFD462907;
    func_0039AD50(&D_01EA4BB0);
    return 1;
}
