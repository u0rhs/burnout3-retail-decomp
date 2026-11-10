// Hand-written; the lifter refused it (CB3EnvironmentManager::Prepare [L]: StaticTrack Prepare shape, EnvData copy via u_long128[3] POD members, inline name-find, A4==0 arm before the find, goto entry-jump element loop).

// CB3EnvironmentManager::Prepare() [L] (research/nahelam_check.csv / config/symbol_addrs_b3names.txt: E map, high);
// kept under its asm label. Hand-written (fresh6) from the shape of Prepare__14CB3StaticTrackFv (func_00332E00.cpp).
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
using GtMathPs2::CGtV4d;

class CGtTexture;
class CAsyncLoadManager {
public:
    int QueueLoadRequest(const char*, bool*, void*, unsigned int);
    unsigned char pad_0[0x10];
};
class CB3TrackList {
public:
    void CreateTrackPathFromID(unsigned long, char*, int);
    int GetTrackIndexFromID(unsigned long);
    void CreateTrackPathFromIndex(int, char*, int);
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_0064D370 { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_theMemMgr { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C1CB8 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C1CC8 { unsigned char pad_0[0x10]; };
struct UnkStruct_002BCA20_e0 { unsigned char pad_0[0x8]; int field_8; unsigned char pad_C[0x4]; };
struct UnkStruct_002BCA20_4 { unsigned char pad_0[0x8]; int field_8; UnkStruct_002BCA20_e0 *field_C; };
struct UnkStruct_D_00518688 { UnkStruct_002BCA20_4 *field_0; unsigned char pad_4[0xC]; };
// [G] the block at +0x90 of each texture; its name at +0x18 (N113 idiom, B3SunRendererPS2_0024D390.cpp)
struct UnkStruct_002BCA20_blk { unsigned char pad_0[0x18]; char field_18[8]; };

struct UnkStruct_002BCA20_p { u_long128 field_0; float field_10[8]; };
class CB3EnvironmentData {
public:
    void FixUp();
    UnkStruct_002BCA20_p field_0;
    UnkStruct_002BCA20_p field_30;
    CGtV4d field_60;
    CGtV4d field_70;
    CGtV3d field_80;
    float field_90;
    int field_94;
    CGtTexture *field_98;
    CGtTexture *field_9C;
    CGtTexture *field_A0;
    CGtTexture *field_A4;
    int field_A8;
    int field_AC;
};

struct UnkStruct_002BCA20_e {
    CGtV3d field_0;
    CGtV4d field_10;
    float field_20, field_24, field_28, field_2C, field_30, field_34, field_38, field_3C;
};

extern UnkStruct_D_0064D370 D_0064D370;
extern UnkStruct_theMemMgr theMemMgr;
extern CB3TrackList D_005196A0;
extern CAsyncLoadManager D_004F6100;
extern UnkStruct_D_004C1CB8 D_004C1CB8;
extern UnkStruct_D_004C1CC8 D_004C1CC8;
extern UnkStruct_D_00518688 D_00518688;
struct UnkStruct_D_00665EC0 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00665EC0 D_00665EC0;

extern "C" char *strcat(char *, const char *);
extern "C" int strcasecmp(const char *, const void *);
extern "C" void *AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" int GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(void *, int);
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" int Prepare__18CB3SkyDomeRendererFP10CGtTextureP10CGtTextureP10CGtTexture(CGtTexture *, CGtTexture *, CGtTexture *);
extern "C" void Prepare__14CB3SunRendererFP10CGtTextureP10CGtTextureP10CGtTexture(CGtTexture *, CGtTexture *, CGtTexture *);

struct UnkStruct_002BCA20 {
    CB3EnvironmentData field_0;
    UnkStruct_002BCA20_e field_B0[2];
    unsigned char pad_130[0x4];
    int field_134;
    float field_138;
    unsigned char field_13C;
    unsigned char pad_13D[0x3];
    int field_140;
    int field_144;
    CB3EnvironmentData *field_148;
    unsigned char field_14C;
};

// [G] inlined texture find by name (no name known for it)
static inline CGtTexture *func_002BCA20_inl1()
{
    int i;
    UnkStruct_002BCA20_4 *t0 = D_00518688.field_0;
    for (i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_002BCA20_blk *)(t2 + 0x90))->field_18, &D_004C1CC8) == 0) return (CGtTexture *)t2;
    }
    return (CGtTexture *)0;
}

// 0x002BCA20
extern "C" int func_002BCA20(UnkStruct_002BCA20 *self)
{
    char path[0x100];
    switch (self->field_140) {
    case 1:
    case 24:
        if (self->field_144 != 0 || self->field_14C == 1) return 1;
        self->field_14C = 0;
        self->field_140 = 2;
        return 0;
    case 2:
        self->field_148 = (CB3EnvironmentData *)AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 4, 0);
        if (self->field_148 == 0) return 0;
        if (D_0064D370.field_0 != 0) {
            D_005196A0.CreateTrackPathFromIndex(D_005196A0.GetTrackIndexFromID(D_0064D370.field_0), path, 256);
        } else {
            D_005196A0.CreateTrackPathFromID(0xC4BD5916359D4000, path, 256);
        }
        strcat(path, (const char *)&D_004C1CB8);
        self->field_144 = D_004F6100.QueueLoadRequest(path, (bool *)&self->field_14C, self->field_148, GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(&theMemMgr, 4));
        self->field_140 = 3;
    case 3:
        if (self->field_14C == 0) return 0;
        self->field_144 = 0;
        self->field_148->FixUp();
        self->field_0 = *self->field_148;
        self->field_148 = 0;
        ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 4, 0);
        self->field_0.field_80 = -self->field_0.field_80;
        self->field_0.field_90 *= (float)D_00665EC0.field_0;
        self->field_140 = 22;
    case 22: {
        if (Prepare__18CB3SkyDomeRendererFP10CGtTextureP10CGtTextureP10CGtTexture(self->field_0.field_98, self->field_0.field_9C, self->field_0.field_A0) == 0) return 0;
        unsigned long id = D_0064D370.field_0;
        if (id == 0xC4BDA62031BD4000 || id == 0xC4BDA62031E45000 || id == 0x67E63A1B0EBD4000 || id == 0x67E63A1B0EE45000) {
            self->field_13C = 0;
        } else if (self->field_0.field_A4 == 0) {
            self->field_13C = 0;
        } else {
            Prepare__14CB3SunRendererFP10CGtTextureP10CGtTextureP10CGtTexture(func_002BCA20_inl1(), self->field_0.field_A4, self->field_0.field_9C);
            self->field_13C = 1;
        }
        self->field_0.field_98 = 0;
        self->field_0.field_9C = 0;
        self->field_0.field_A0 = 0;
        self->field_0.field_A4 = 0;
        self->field_134 = 0;
        self->field_138 = 0.002083333442f;
        int k = 0;
        goto t;
    l: {
            UnkStruct_002BCA20_e &e = self->field_B0[k];
            e.field_0 = self->field_0.field_80;
            e.field_10 = CGtV4d(self->field_0.field_0.field_0);
            e.field_20 = self->field_0.field_0.field_10[0]; e.field_24 = self->field_0.field_0.field_10[1];
            e.field_28 = self->field_0.field_0.field_10[2]; e.field_2C = self->field_0.field_0.field_10[3];
            e.field_30 = self->field_0.field_0.field_10[4]; e.field_34 = self->field_0.field_0.field_10[5];
            e.field_38 = self->field_0.field_0.field_10[6]; e.field_3C = self->field_0.field_0.field_10[7];
            k++;
        }
    t:
        if (k < 2) goto l;
        self->field_140 = 23;
        break;
    }
    }
    return 1;
}
