// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// func_0024B2A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (early return; find-by-name as a static inline helper (strcasecmp(((blk*)(int+0x90))->field_18), N113); CopyTextureAs32Bit returns u_long128).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGtTexture;

class CB3GraphicsManager;
class CB3SunRenderer;
struct UnkStruct_0024B2A0_2;
struct UnkStruct_0024B2A0_e0;
struct UnkStruct_D_004BB730;
struct UnkStruct_D_00518688;
struct UnkStruct_D_006662D0;
struct UnkStruct_D_01D9B950;

class CB3GraphicsManager {
public:
    u_long128 CopyTextureAs32Bit(CGtTexture*, unsigned int, unsigned int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00518688 {
    UnkStruct_0024B2A0_2 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0024B2A0_2 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_0024B2A0_e0 * field_C;
};

struct UnkStruct_0024B2A0_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_D_006662D0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01D9B950 {
    u_long128 field_0;
};

struct UnkStruct_D_004BB730 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SunRenderer {
public:
    static int mpCoronaTexture;
};

extern UnkStruct_D_00518688 D_00518688;
extern UnkStruct_D_006662D0 D_006662D0;
extern UnkStruct_D_01D9B950 D_01D9B950;
extern UnkStruct_D_004BB730 D_004BB730;
extern CB3GraphicsManager D_00665EC0;

extern "C" int strcasecmp(const char *, const void *);

// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113).
struct UnkStruct_0024B2A0_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

static inline CGtTexture * func_0024B2A0_inl1(const void * name)
{
    UnkStruct_0024B2A0_2 * t0 = D_00518688.field_0;
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_0024B2A0_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return (CGtTexture *)t2;
        }
    }
    return 0;
}

// 0x0024B2A0
extern "C" void func_0024B2A0()
{
    if (CB3SunRenderer::mpCoronaTexture == 0) return;
    D_01D9B950.field_0 = D_00665EC0.CopyTextureAs32Bit(func_0024B2A0_inl1(&D_004BB730), D_006662D0.field_0 + 176, 0);
}
