// func_00222260 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (three pass-through args forwarded to the D_004E2938 function pointer).

// lifter variant 0
// func_00222260 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtTextureCache;
struct UnkStruct_D_004E2938;

class CGtTextureCache {
public:
    void FlushCache();

    unsigned char pad_0[0x1F4];
    int field_1F4;
};

struct UnkStruct_D_004E2938 {
    int (*field_0)(void *, void *, void *);  // [G] function pointer (jalr through it)
};

extern CGtTextureCache gTextureCache;
extern UnkStruct_D_004E2938 D_004E2938;

extern "C" void RpSkyTexCacheFlush();

extern "C" bool func_00222260(void * p0, void * p1, void * p2)
{
    gTextureCache.FlushCache();
    RpSkyTexCacheFlush();
    gTextureCache.field_1F4 = 0;
    return D_004E2938.field_0(p0, p1, p2) != 0;
}
