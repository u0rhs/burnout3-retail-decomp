// CGtTextureCache::Construct(unsigned int,int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtTextureCachePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (phantom args dropped from RpSkyTexCacheSetCallBack; pointer local to ourGlobals.field_98; D_004E2938 as void*).

// CGtTextureCache::Construct(unsigned int,int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtTextureCachePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtTextureCache;
struct UnkStruct_func_00222260;
struct UnkStruct_func_002222D0;
struct UnkStruct_func_002222E0;
struct UnkStruct_ourGlobals;


struct UnkStruct_ourGlobals {
    unsigned char pad_0[0x98];
    void * field_98;
};

struct UnkStruct_func_002222E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_002222D0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_00222260 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtTextureCache {
public:
    void Construct(unsigned int p0, int p1, int p2);

    int field_0;
    unsigned char pad_4[0xBC];
    int field_C0;
    int field_C4;
    int field_C8[1];  // [G] element count unknown
    unsigned char pad_CC[0x74];
    int field_140;
    int field_144;
    int field_148[1];  // [G] element count unknown
    unsigned char pad_14C[0x74];
    int field_1C0;
    unsigned char field_1C4;
    unsigned char field_1C5;
    unsigned char pad_1C6[0x2];
    int field_1C8;
    int field_1CC;
    int field_1D0;
    int field_1D4;
    int field_1D8;
    int field_1DC;
    int field_1E0;
    int field_1E4;
    int field_1E8;
    int field_1EC;
    int field_1F0;
    int field_1F4;
    int field_1F8;
    int field_1FC;
    int field_200;
    int field_204[1];  // [G] element count unknown
    unsigned char pad_208[0x1C];
    unsigned char field_224;
};

extern void *D_004E2938;
extern UnkStruct_ourGlobals ourGlobals;
extern UnkStruct_func_002222E0 func_002222E0;
extern UnkStruct_func_002222D0 func_002222D0;
extern UnkStruct_func_00222260 func_00222260;

extern "C" int RpSkyTexCacheSetCallBack(void *);
extern "C" int RpSkyTexCacheSetReleaseCallBack(void *);

// 0x00222120
void CGtTextureCache::Construct(unsigned int p0, int p1, int p2)
{
    field_1E4 = p1;
    field_1F0 = p2;
    field_1F4 = 0;
    field_1EC = p0;
    field_1FC = 0;
    field_200 = 0x100000;
    int t0 = field_1EC;
    field_1E8 = (0x100000 - (t0 + field_1FC));
    field_1D8 = (((unsigned int)field_1E8 >> 1) & -2048);
    field_1DC = field_1EC;
    field_1E0 = (field_1EC + field_1D8);
    for (int i = 0; (i < 30); i++) {
        field_C8[i] = 0;
        field_148[i] = 0;
    }
    field_C0 = 0;
    field_140 = 0;
    field_C4 = 0;
    field_144 = 0;
    field_1C0 = 0;
    field_1F8 = 0;
    for (int i1 = 0; (i1 < 8); i1++) {
        field_204[i1] = 0;
    }
    RpSkyTexCacheSetCallBack(&func_002222E0);
    RpSkyTexCacheSetReleaseCallBack(&func_002222D0);
    if (D_004E2938 == 0) {
        void **p = &ourGlobals.field_98;
        void * t1 = *p;
        *p = &func_00222260;
        D_004E2938 = t1;
    }
    field_1C8 = 0;
    field_1C5 = 0;
    field_1C4 = 1;
    field_1CC = 0;
    field_224 = 0;
    field_0 = 0;
    field_1D0 = 0;
    field_1D4 = 0;
}
