// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// CB3SunRenderer::Prepare(CGtTexture*,CGtTexture*,CGtTexture*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SunRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (static method; AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki returns void* (if/else, return-0 block last); CopyTextureAs32Bit returns u_long128; entry+0x90 cast to a block struct (N113); goto for the found exit).

// CB3SunRenderer::Prepare(CGtTexture*,CGtTexture*,CGtTexture*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SunRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGtTexture;

class CB3GraphicsManager;
class CB3SunRenderer;
struct UnkStruct_0024D390_4;
struct UnkStruct_0024D390_e0;
struct UnkStruct_D_004BB738;
struct UnkStruct_D_00518688;
struct UnkStruct_D_006662D0;
struct UnkStruct_D_01D9B950;
struct UnkStruct_theMemMgr;

class CB3GraphicsManager {
public:
    u_long128 CopyTextureAs32Bit(CGtTexture*, unsigned int, unsigned int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_006662D0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01D9B950 {
    u_long128 field_0;
};

struct UnkStruct_D_00518688 {
    UnkStruct_0024D390_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0024D390_4 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_0024D390_e0 * field_C;
};

struct UnkStruct_0024D390_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_theMemMgr {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BB738 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SunRenderer {
public:
    static int Prepare(CGtTexture* p0, CGtTexture* p1, CGtTexture* p2);
    static int mpCoronaTexture;
    static int mpEnvmapCoronaTexture;
};

extern UnkStruct_D_006662D0 D_006662D0;
extern UnkStruct_D_01D9B950 D_01D9B950;
extern UnkStruct_D_00518688 D_00518688;
extern UnkStruct_theMemMgr theMemMgr;
extern CB3GraphicsManager D_00665EC0;
extern UnkStruct_D_004BB738 D_004BB738;

extern "C" void *AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" int GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(void *, int);
extern "C" int CreateCopy__10CGtTextureFUi(CGtTexture*, void *, int);
extern "C" int strcasecmp(const char *, const void *);

// [G] the block at +0x90 of each entry's object; a name at +0x18. Retail adds 0x90 and 0x18 separately (cf. N113).
struct UnkStruct_0024D390_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

// 0x0024D390
int CB3SunRenderer::Prepare(CGtTexture* p0, CGtTexture* p1, CGtTexture* p2)
{
    void *r0 = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 3, 0);
    if (r0 != 0) {
        int r2 = CreateCopy__10CGtTextureFUi(p1, r0, GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(&theMemMgr, 3));
        u_long128 r3 = D_00665EC0.CopyTextureAs32Bit(p0, (D_006662D0.field_0 + 176), 0);
        CB3SunRenderer::mpCoronaTexture = r2;
        D_01D9B950.field_0 = r3;
        UnkStruct_0024D390_4 * t0 = D_00518688.field_0;
        int t2;
        int i;
        for (i = 0; i < t0->field_8; i++) {
            t2 = t0->field_C[i].field_8;
            if (strcasecmp(((UnkStruct_0024D390_blk *)(t2 + 0x90))->field_18, &D_004BB738) == 0) {
                goto found;
            }
        }
        t2 = 0;
    found:
        CB3SunRenderer::mpEnvmapCoronaTexture = t2;
        return 1;
    } else {
        return 0;
    }
}
